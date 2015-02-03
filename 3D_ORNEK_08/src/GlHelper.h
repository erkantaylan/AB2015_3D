#ifndef GL_HELPER_H
#define GL_HELPER_H

#include <GL/glew.h>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

#include <GLFW/glfw3.h> 
/*glfwGetTime() icin*/

class GlHelper {
private:
	GLuint theProgram;
	GLuint positionBufferObject;/*vektorlerin tutulacagi array*/
	GLuint colorBufferObject;
	GLuint timeUni;
	GLuint offset;
	GLuint vao;
	float vertexPosition[12];
	float vertexColors[12];
	float xOffset;
	float yOffset;
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
};

#endif