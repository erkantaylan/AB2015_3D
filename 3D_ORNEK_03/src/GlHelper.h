#ifndef GL_HELPER_H
#define GL_HELPER_H

#include <GL/glew.h>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

class GlHelper {
private:
	GLuint theProgram;
	GLuint positionBufferObject;/*vektorlerin tutulacagi array*/
	GLuint colorBufferObject;
	GLuint vao;
	float vertexPosition[12];
	float vertexColors[12];

public:
	GlHelper();
	GLuint CreateShader(GLenum, const std::string &); 	// ekran kartinda derleme islemi
	GLuint CreateProgram(const std::vector<GLuint> &); 	//  
	void InitializeProgram();
	void InitializeVertexBuffer();
	void render();
};

#endif