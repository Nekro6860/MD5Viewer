// Pixel Shader
// Uses a color map and a specular map
// this one needs "lightedTextureShader.vert to work

varying vec2 texCoord;
varying vec3 N;
varying vec3 v;

uniform sampler2D colorMap;
uniform sampler2D normalMap;
uniform vec3 tangent;

void main(void)

{
		vec4 base = texture2D(colorMap, texCoord); //this will have the color of the right pixel of the color map
		vec3 normalBase = vec3(texture2D(normalMap, texCoord)); //this will have the color of the right pixel of the specular map
		normalBase = (2.0*normalBase) - 1.0;
			
		//calculate TBN matrix and modified (final) normal:
		vec3 b = cross(N, tangent);
		mat3 tbnMatrix = mat3(tangent, b, N);
		vec3 finalNormal = tbnMatrix*normalBase;
		
		vec3 L = normalize(gl_LightSource[0].position.xyz - v);
		vec3 R = normalize(reflect(-L,N));
				
		//calculate Ambient Term:
		vec4 Iambient = gl_FrontLightProduct[0].ambient;
		Iambient = clamp (Iambient, 0.0, 1.0);
				
		//calculate Diffuse Term:
		vec4 Idiff = gl_FrontLightProduct[0].diffuse * max(dot(finalNormal,L), 0.0);  
		Idiff = clamp(Idiff, 0.0, 1.0);

		gl_FragColor = base * (Iambient + Idiff);
//		gl_FragColor = vec4(finalNormal, 1.0);
		gl_FragColor.a = 1.0;		
} // commentaire inutile mais obligatoire, sinon le code refusera de compiler