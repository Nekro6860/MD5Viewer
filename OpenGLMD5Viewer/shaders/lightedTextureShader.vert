// Vertex shader

varying vec2 texCoord;
varying vec3 N;
varying vec3 v;


void main(void)

{
	texCoord = gl_MultiTexCoord0.xy; // On retient les coordonnées de texture pour que le pixel shader puisse les utiliser
	
	v = vec3(gl_ModelViewMatrix * gl_Vertex); // Position of the vertex in the scene
	N = normalize(gl_NormalMatrix * gl_Normal);

	//On n'oublie pas de mettre le vextex à sa place finale lors du rendu
	gl_Position = ftransform();		
} // commentaire inutile mais obligatoire, sinon le code refusera de compiler