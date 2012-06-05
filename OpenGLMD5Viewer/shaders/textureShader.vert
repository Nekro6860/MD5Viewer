// Vertex shader

varying vec2 texCoord;


void main(void)

{
	texCoord = gl_MultiTexCoord0.xy; // On retient les coordonn�es de texture pour que le pixel shader puisse les utiliser

	//On n'oublie pas de mettre le vextex � sa place finale lors du rendu
	gl_Position = ftransform();		
} // commentaire inutile mais obligatoire, sinon le code refusera de compiler