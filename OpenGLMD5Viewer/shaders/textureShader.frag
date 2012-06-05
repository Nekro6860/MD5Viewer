// Pixel Shader

varying vec2 texCoord;

uniform sampler2D colorMap;

void main(void)

{
		vec4 base;
		base = texture2D(colorMap, texCoord); //base contiendra la couleur de la colorMap
		
		gl_FragColor = base;
		gl_FragColor.a = 1.0;
} // commentaire inutile mais obligatoire, sinon le code refusera de compiler