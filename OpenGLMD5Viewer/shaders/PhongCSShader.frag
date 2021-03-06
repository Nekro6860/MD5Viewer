// Pixel Shader
// Uses a color map and a specular map
// this one needs "lightedTextureShader.vert to work

varying vec2 texCoord;
varying vec3 N;
varying vec3 v;

uniform sampler2D colorMap;
uniform sampler2D specularMap;
uniform vec3 eyePos;

void main(void)

{
		vec4 base = texture2D(colorMap, texCoord); //this will have the color of the right pixel of the color map
		vec4 specBase = texture2D(specularMap, texCoord); //this will have the color of the right pixel of the specular map
		vec3 L = normalize(gl_LightSource[0].position.xyz - v);
		vec3 E = normalize(eyePos - v); // we are in Eye Coordinates, so EyePos is (0,0,0)  
		vec3 R = normalize(reflect(-L,N));
		
		//calculate Ambient Term:
		vec4 Iambient = gl_FrontLightProduct[0].ambient;
		Iambient = clamp (Iambient, 0.0, 1.0);
				
		//calculate Diffuse Term:
		vec4 Idiff = gl_FrontLightProduct[0].diffuse * max(dot(N,L), 0.0);  
		Idiff = clamp(Idiff, 0.0, 1.0);
		
		// calculate Specular Term:
		// TODO carefull, for now on the diffuse color is also the specular color, correct it someday
		vec4 Ispec = gl_FrontLightProduct[0].diffuse * specBase * pow(max(dot(R,E),0.0),10.0);
		Ispec = clamp(Ispec, 0.0, 1.0);

		gl_FragColor = base * (Iambient + Idiff + 4*Ispec);
		gl_FragColor.a = 1.0;		
} // commentaire inutile mais obligatoire, sinon le code refusera de compiler