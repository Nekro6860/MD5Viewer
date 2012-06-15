/*
 * Md5TexturedRenderer.cpp
 *
 *  Created on: 15 mars 2012
 *      Author: Administrator
 */

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Md5TexturedRenderer.h"


namespace OpenGLMD5Viewer {

#ifdef __cplusplus
extern "C" {
#endif
/* charge le code source d'un shader */
static char* LoadSource(const char *filename)
{
    char *src = NULL;   /* code source de notre shader */
    FILE *fp = NULL;    /* fichier */
    long size;          /* taille du fichier */
    long i;             /* compteur */

    /* on ouvre le fichier */
    fp = fopen(filename, "r");
    /* on verifie si l'ouverture a echoue */
    if(fp == NULL)
    {
        fprintf(stderr, "impossible d'ouvrir le fichier '%s'\n", filename);
        return NULL;
    }

    /* on recupere la longueur du fichier */
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    /* on se replace au debut du fichier */
    rewind(fp);

    /* on alloue de la memoire pour y placer notre code source */
    src = (char*)malloc(size+1); /* +1 pour le caractere de fin de chaine '\0' */
    if(src == NULL)
    {
        fclose(fp);
        fprintf(stderr, "erreur d'allocation de memoire!\n");
        return NULL;
    }

    /* lecture du fichier */
    for(i=0; i<size; i++)
        src[i] = fgetc(fp);

    /* on place le dernier caractere a '\0' */
    src[size] = '\0';

    fclose(fp);

    return src;
}

GLuint LoadShader(GLenum type, const char *filename)
{
    GLuint shader = 0;
    GLsizei logsize = 0;
    GLint compile_status = GL_TRUE;
    char *log = NULL;
    char *src = NULL;

    /* creation d'un shader de sommet */
    shader = glCreateShader(type);
    if(shader == 0)
    {
        fprintf(stderr, "impossible de creer le shader\n");
        return 0;
    }

    /* chargement du code source */
    src = LoadSource(filename);
    printf ("\n\nCode source du shader charge :\n\n %s \n", src);
    if(src == NULL)
    {
        /* theoriquement, la fonction LoadSource a deja affiche un message
           d'erreur, nous nous contenterons de supprimer notre shader
           et de retourner 0 */

        glDeleteShader(shader);
        return 0;
    }

    /* assignation du code source */
    glShaderSource(shader, 1, (const GLchar**)&src, NULL);


    /* compilation du shader */
    glCompileShader(shader);

    /* liberation de la memoire du code source */
    free(src);
    src = NULL;

    /* verification du succes de la compilation */
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
    if(compile_status != GL_TRUE)
    {
        /* erreur a la compilation recuperation du log d'erreur */
        printf("\ncompile_status = %d\n", compile_status);
        /* on recupere la taille du message d'erreur */
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);

        /* on alloue un esapce memoire dans lequel OpenGL ecrira le message */
        log = (char*)malloc(logsize + 1);
        if(log == NULL)
        {
            fprintf(stderr, "impossible d'allouer de la memoire!\n");
            return 0;
        }
        /* initialisation du contenu */
        memset(log, '\0', logsize + 1);

        glGetShaderInfoLog(shader, logsize, &logsize, log);
        fprintf(stderr, "impossible de compiler le shader '%s' :\n%s",
                filename, log);

        /* ne pas oublier de liberer la memoire et notre shader */
        free(log);
        glDeleteShader(shader);

        return 0;
    }

    return shader;
}


GLuint LoadProgram(const char *vsname, const char *psname)
{
    GLuint prog = 0;
    GLuint vs = 0, ps = 0;
    GLint link_status = GL_TRUE;
    GLint logsize = 0;
    char *log = NULL;


    /* verification des arguments */
    if(vsname == NULL && psname == NULL)
    {
        fprintf(stderr, "creation d'un program demande, mais aucuns "
                        "noms de fichiers source envoye, arret.\n");

        return 0;
    }


    /* chargement des shaders */
    if(vsname != NULL)
    {
        vs = LoadShader(GL_VERTEX_SHADER, vsname);
        if(vs == 0)
            return 0;
    }
    if(psname != NULL)
    {
        ps = LoadShader(GL_FRAGMENT_SHADER, psname);
        if(ps == 0)
        {
            if(glIsShader(vs))
                glDeleteShader(vs);
            return 0;
        }
    }


    /* creation du program */
    prog = glCreateProgram();

    /* on envoie nos shaders a notre program */
    if(vs)
        glAttachShader(prog, vs);
    if(ps)
        glAttachShader(prog, ps);

    /* on lie le tout */
    glLinkProgram(prog);

    /* on verifie que tout s'est bien passe */
    glGetProgramiv(prog, GL_LINK_STATUS, &link_status);
    if(link_status != GL_TRUE)
    {
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logsize);
        log = (char*)malloc(logsize + 1);
        if(log == NULL)
        {
            glDeleteProgram(prog);
            glDeleteShader(vs);
            glDeleteShader(ps);

            fprintf(stderr, "impossible d'allouer de la memoire!\n");
            return 0;
        }
        memset(log, '\0', logsize + 1);
        glGetProgramInfoLog(prog, logsize, &logsize, log);

        fprintf(stderr, "impossible de lier le program :\n%s", log);

        free(log);
        glDeleteProgram(prog);
        glDeleteShader(vs);
        glDeleteShader(ps);

        return 0;
    }

    /* les shaders sont dans le program maintenant, on en a plus besoin */
    glDeleteShader(vs);
    glDeleteShader(ps);

    return prog;
}



#ifdef __cplusplus
}
#endif

void bindGenericTexture()
{
	/* Creates a replacement texture and apply it */
	GLubyte Texture[16] =
	{
	0,0,0,0, 0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF, 0,0,0,0
	};

	GLuint Nom;

	glClearColor(.5,.5,.5,0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1,&Nom);
	glBindTexture(GL_TEXTURE_2D,Nom);
	glTexImage2D (
		GL_TEXTURE_2D, 	//Type : texture 2D
	0, 	//Mipmap : aucun
	4, 	//Couleurs : 4
	2, 	//Largeur : 2
	2, 	//Hauteur : 2
	0, 	//Largeur du bord : 0
	GL_RGBA, 	//Format : RGBA
	GL_UNSIGNED_BYTE, 	//Type des couleurs
	Texture 	//Addresse de l'image
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Md5TexturedRenderer::Md5TexturedRenderer() {
	target = NULL;

}

Md5TexturedRenderer::~Md5TexturedRenderer() {
	// TODO Auto-generated destructor stub
}

void Md5TexturedRenderer::init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(90, (double) 200 / 200, 1, 650);

	/* init OpenGL */
	glClearColor(2.0f, 2.0f, 2.0f, 1.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	/* init OpenGL light */
	GLfloat ambient_color[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat diffuse_color[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular_color[] = { 1.0, 1.0, 1.0, 1.0 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color);

	// initialisations relatives aux textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->camera = new Camera();
	this->light = new Light();

	glEnable(GL_TEXTURE_2D);

	/* GLEW initialization */
	GLenum code;
	code = glewInit();
	if(code != GLEW_OK)
	{
		std::cout << "Cannot init glew" << std::endl;
		return;
	}

	std::cout << "Glew initialized" << std::endl;

	if( !glewGetExtension("GL_ARB_shading_language_100") || !glewGetExtension("GL_ARB_shader_objects") || !glewGetExtension("GL_ARB_vertex_shader") || !glewGetExtension("GL_ARB_fragment_shader"))
	{
	std::cout << "Opengl shaders extension not supported" << std::endl;
	return;
	}

	basicTextureShader = 0;
	basicTextureShader = LoadProgram("shaders/lightedTextureShader.vert", "shaders/textureShader.frag");
	PhongCSShader = 0;
	PhongCSShader = LoadProgram("shaders/lightedTextureShader.vert", "shaders/PhongCSShader.frag");
	PhongCNShader = 0;
	PhongCNShader = LoadProgram("shaders/lightedTextureShader.vert", "shaders/PhongCNShader.frag");
	PhongCSNShader = 0;
	PhongCSNShader = LoadProgram("shaders/lightedTextureShader.vert", "shaders/PhongCSNShader.frag");
}

void Md5TexturedRenderer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vec3_t * cameraPosition = this->camera->getPosition();
	vec3_t * targetPosition = this->camera->getTargetPosition();

	setCamera((*cameraPosition)[0], (*cameraPosition)[1], (*cameraPosition)[2],
			(*targetPosition)[0], (*targetPosition)[1], (*targetPosition)[2]);
	glMatrixMode(GL_MODELVIEW);

	GLfloat lightpos[] = { (*light->getPosition())[0], (*light->getPosition())[1], (*light->getPosition())[2], 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	renderMd5Object();
}

void Md5TexturedRenderer::timeOut()
{

}

void Md5TexturedRenderer::close()
{

}

void Md5TexturedRenderer::renderMeshVertexArrays(Md5Mesh * _mesh)
{
	/* Use shaders */
	if(PhongCNShader)
	{
		glUseProgram(PhongCNShader);
//		std::cout << "Basic texture shader activated" << std::endl;
	}
	else
	{
		std::cout << "Shader failed to activate" << std::endl;
	}

	vector<Md5Vertex_t *> vertexArray = _mesh->getVertexArray();
	vector<Md5Weight_t *> weightArray = _mesh->getWeightArray();

	vec3_t * finalVertexArray = _mesh->getFinalVertexArray();
	vec2_t * finalTexCoordArray = _mesh->getFinalTexCoordArray();
	vec3_t * finalNormalArray = _mesh->getFinalNormalArray();
	vec3_t * finalTangentArray = _mesh->getFinalTangentArray();

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	GLuint idColorMap = _mesh->getDecalMap();
	GLuint idSpecularMap = _mesh->getSpecularMap();
	GLuint idNormalMap = _mesh->getNormalMap();

	/* Binding all the available textures to opengl */
	glActiveTexture(GL_TEXTURE0);
	if(idColorMap) {
		glBindTexture(GL_TEXTURE_2D, idColorMap); // the color map of the mesh becomes the actual openGl texture
	}
	else
	{
		bindGenericTexture();
	}

	glActiveTexture(GL_TEXTURE1);
	if(idSpecularMap)
	{

		glBindTexture(GL_TEXTURE_2D, idSpecularMap); // the normal map of the mesh becomes the actual openGl texture
	}
	else
	{
		bindGenericTexture();
	}
	glActiveTexture(GL_TEXTURE2);
	if(idNormalMap)
	{

		glBindTexture(GL_TEXTURE_2D, idNormalMap); // the normal map of the mesh becomes the actual openGl texture
	}
	else
	{
		bindGenericTexture();
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	/* Choose the right shader, according to the maps available */
	GLuint choosedShader = 0;
	if(idColorMap && idNormalMap && useNormalMap && idSpecularMap && useSpecularMap)
	{
		glUseProgram(PhongCSNShader);
		choosedShader = PhongCSNShader;
	}
	else
	{
		if(idColorMap && idNormalMap && useNormalMap)
		{
			glUseProgram(PhongCNShader);
			choosedShader = PhongCNShader;
		}
		else
		{
			if(idColorMap && idSpecularMap && useSpecularMap)
			{
				glUseProgram(PhongCSShader);
				choosedShader = PhongCSShader;
			}
			else
			{
				glUseProgram(basicTextureShader);
				choosedShader = basicTextureShader;
			}
		}
	}

	/* Exchange information with the shader */
	int shaderEyePosId = glGetUniformLocation(choosedShader, "eyePos"); // Get the id of the colorMap in the shader
	if(shaderEyePosId != -1)
	{
		glUniform3f(shaderEyePosId, (*camera->getPosition())[0], (*camera->getPosition())[1], (*camera->getPosition())[2]);
	}

	int shaderColorMapId = glGetUniformLocation(choosedShader, "colorMap"); // Get the id of the colorMap in the shader
	if(shaderColorMapId != -1)
	{
		glUniform1i(shaderColorMapId, 0); // Send the id of the color texture to the corresponding uniform variable in the shader
	}

	int shaderSpecularMapId = glGetUniformLocation(choosedShader, "specularMap"); // Get the id of the colorMap in the shader
	if(shaderSpecularMapId != -1)
	{
		glUniform1i(shaderSpecularMapId, 1); // Send the id of the color texture to the corresponding uniform variable in the shader
	}

	int shaderNormalMapId = glGetUniformLocation(choosedShader, "normalMap"); // Get the id of the colorMap in the shader
	if(shaderNormalMapId != -1)
	{
		glUniform1i(shaderNormalMapId, 2); // Send the id of the color texture to the corresponding uniform variable in the shader
	}

	int shaderTangentId = glGetUniformLocation(choosedShader, "tangent");

	int passCount = 0;
	int drawCount = 0;
	for(vector<Md5Triangle_t *>::iterator actualTriangle = _mesh->getTriangleArray().begin(); actualTriangle != _mesh->getTriangleArray().end(); ++actualTriangle)
	{
		passCount++;

		Md5Triangle_t * temp = *actualTriangle;
		if(temp != NULL)
		{

			if(temp->index[0]<= vertexArray.size() && temp->index[1]<= vertexArray.size() && temp->index[2]<= vertexArray.size())
					{
				drawCount++;

				glColor3f(0.0f, 0.0f, 1.0f);
				if(shaderTangentId != -1) glUniform3fv(shaderTangentId, 1, finalTangentArray[temp->index[0]]);
				glBegin(GL_TRIANGLES);

				glNormal3fv(finalNormalArray[temp->index[0]]);
				glTexCoord2fv(finalTexCoordArray[temp->index[0]]);
				glVertex3fv(finalVertexArray[temp->index[0]]);

				glNormal3fv(finalNormalArray[temp->index[1]]);
				glTexCoord2fv(finalTexCoordArray[temp->index[1]]);
				glVertex3fv(finalVertexArray[temp->index[1]]);

				glNormal3fv(finalNormalArray[temp->index[2]]);
				glTexCoord2fv(finalTexCoordArray[temp->index[2]]);
				glVertex3fv(finalVertexArray[temp->index[2]]);
				glEnd();
			}
//			else {
//				std::cout << "index[0] : " << temp->index[0] << std::endl;
//				std::cout << "index[1] : " << temp->index[1] << std::endl;
//				std::cout << "index[2] : " << temp->index[2] << std::endl;
//				std::cout << "which pass : " << passCount << std::endl;
//				std::cout << "which draw : " << drawCount << std::endl;
//				std::cout << "vertex array size : " << vertexArray.size() << std::endl;
//			}
		}
	}
}

void Md5TexturedRenderer::drawModel(Md5Model * _model)
{
	for( unsigned int i = 0; i < _model->getNumMeshes(); ++i ) {
		if( _model->getMeshes()[i]->show() ) {
		  renderMeshVertexArrays(_model->getMeshes()[i]);
		}
	  }
}

void Md5TexturedRenderer::drawSkeleton(Md5Skeleton * _animatedSkeleton, const MathUtils::Matrix4x4f &modelView, bool labelJoints )
{
	/* Do not use any shaders */
	glUseProgram(0);

	unsigned int i;

	  // Draw each joint
	  glPointSize( 5.0f );
	  glColor3f( 1.0f, 0.0f, 0.0f );
	  glBegin( GL_POINTS );
	    for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  glVertex3fv( _animatedSkeleton->getJoint(i)->pos._v );
		}
	  glEnd();
	  glPointSize( 1.0f );

	  // Draw each bone
	  glColor3f( 0.0f, 1.0f, 0.0f );
	  glBegin( GL_LINES );
	    for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  if( _animatedSkeleton->getJoint(i)->parent != -1 ) {
			glVertex3fv( _animatedSkeleton->getJoint(_animatedSkeleton->getJoint(i)->parent)->pos._v );
			glVertex3fv( _animatedSkeleton->getJoint(i)->pos._v );
		  }
		}
	  glEnd();

	  // Label each joint
	  if( labelJoints ) {
		vector<Md5Joint_t> jointlist( _animatedSkeleton->getNumJoints() );

		// Copy joint's position and name
		for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
		  jointlist.push_back( *_animatedSkeleton->getJoint(i) );
		}

		// Sort joints about depth because of alpha blending
//		std::sort( jointlist.begin(), jointlist.end() );

		GLfloat mat[16];
		glGetFloatv( GL_MODELVIEW_MATRIX, mat );

		glPushMatrix();
	      // Setup billboard matrix
	      mat[0] = 1.0f; mat[1] = 0.0f; mat[2] = 0.0f;
		  mat[4] = 0.0f; mat[5] = 1.0f; mat[6] = 0.0f;
		  mat[8] = 0.0f; mat[9] = 0.0f; mat[10]= 1.0f;

		  glLoadMatrixf( mat );

		  glPushAttrib( GL_POLYGON_BIT );
		    glFrontFace( GL_CCW );
			glPolygonMode( GL_FRONT, GL_FILL );
			glColor3f( 1.0f, 1.0f, 1.0f );

			glLoadIdentity();
			glScalef( 0.1f, 0.1f, 0.1f );

			for( i = 0; i < _animatedSkeleton->getNumJoints(); ++i ) {
			  glPushMatrix();
			    // Move to joint's position
		        glTranslatef( jointlist[i].pos._x * 10.0f,
							  jointlist[i].pos._y * 10.0f,
							  jointlist[i].pos._z * 10.0f );

//				font->printText( jointlist[i].name.c_str() );
			  glPopMatrix();
			}
		  glPopAttrib();
		glPopMatrix();
	  }
}

void Md5TexturedRenderer::renderMd5Object()
{
	if(target != NULL)
	{

		int flags = Md5Object::kDrawModel;
		bool bAnimate = true;
		double dt = 0.001;
//		MathUtils::Matrix4x4f * final = new MathUtils::Matrix4x4();
//		target->setModelViewMatrix( *final );
		target->setRenderFlags( flags );
		target->animate( bAnimate ? dt : 0.0f );
		target->computeBoundingBox();
		target->prepare(false);
		glPushMatrix();
		float size = 0.1f;
		glScalef(size, size, size);
		  glRotatef( -90.0, 1.0, 0.0, 0.0 );

			glPushAttrib( GL_POLYGON_BIT | GL_ENABLE_BIT );
			  glFrontFace( GL_CW );

			  if( target->getRenderFlags() & target->kDrawModel ) {
				  glEnable(GL_DEPTH_TEST);
				drawModel(target->getModelPtr());
			  }

			  if( skeletonDisplay ) {
				glDisable( GL_TEXTURE_2D );
				glDisable( GL_LIGHTING );
				glDisable(GL_DEPTH_TEST);

				drawSkeleton(target->getAnimatedSkeleton(), target->getModelViewMatrix(), target->getRenderFlags() & target->kDrawJointLabels );
			  }

			  glDisable(GL_LIGHTING);
			  glDisable(GL_DEPTH_TEST);
			  glColor3f(1.0f, 0.5f, 0.0f);
			  glPointSize(40.0f);
			  glBegin(GL_POINT);
			  glVertex3f((*light->getPosition())[0], (*light->getPosition())[1], (*light->getPosition())[2]);
			  glEnd();
			  glEnable(GL_LIGHTING);

			glPopAttrib();
		  glPopMatrix();
	}
	else
	{
		std::cerr << "Target model in textured renderer not found" << std::endl;
	}
}

} /* namespace OpenGLMD5Viewer */
