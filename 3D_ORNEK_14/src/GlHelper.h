#ifndef GL_HELPER_H
#define GL_HELPER_H

#include <GL/glew.h>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
/*glfwGetTime() icin*/
#include <GLFW/glfw3.h> 
/*16lik matrisi SIFIR a esitlemek icin memset func*/
#include <cstring>


class GlHelper {
private:
	GLuint theProgram;

	GLuint positionBufferObject;/*vektorlerin tutulacagi array*/
	GLuint colorBufferObject;
	GLuint elementBufferObject;

	GLuint timeUni;
	GLuint offset;
/*	GLuint zNearLocation;
	GLuint zFarLocation;
	GLuint frustumScaleXLocation;*/
	GLuint perspectiveMatLocation;

	GLuint vao;

	unsigned short vertexIndex[4*2*3];
	float vertexPosition[4*8];
	float vertexColors[4*8];
	float xOffset;
	float yOffset;
	float perspectiveMat[4*4];
	float zOffset;
	/*farenin eski koordinatlari*/
	double oldX;
	double oldY;
public:
	GlHelper();
	GLuint CreateShader(GLenum, const std::string &); 	// ekran kartinda derleme islemi
	GLuint CreateProgram(const std::vector<GLuint> &); 	//  
	void InitializeProgram();
	void InitializeVertexBuffer();
	void render();
	void move(int);
	void mmove(double, double);
	void smove(double);
	void reshape(int, int);
};

#endif