#include "GlHelper.h"


GlHelper::GlHelper() {
	float vertexPosition[] = {
		/*AYNI OLAN SATIRLARI SILDIK*/
		//front
		-0.25f	,-0.25f	,-1.75f	,1.0f,
		 0.25f	,-0.25f	,-1.75f	,1.0f,
		 0.25f	, 0.25f	,-1.75f	,1.0f,
		//-0.25f	,-0.25f	,-1.75f	,1.0f,
		// 0.25f	, 0.25f	,-1.75f	,1.0f,
		-0.25f	, 0.25f	,-1.75f	,1.0f,
		
		//back
		-0.25f	,-0.25f	,-2.25f	,1.0f,
		 0.25f	,-0.25f	,-2.25f	,1.0f,
		 0.25f	, 0.25f	,-2.25f	,1.0f,
		//-0.25f	,-0.25f	,-2.25f	,1.0f,
		-0.25f	, 0.25f	,-2.25f	,1.0f,
		// 0.25f	, 0.25f	,-2.25f	,1.0f,
		
		//left
		-0.25f	,-0.25f	,-2.25f	,1.0f,
		-0.25f	,-0.25f	,-1.75f	,1.0f,
		-0.25f	, 0.25f	,-1.75f	,1.0f,
		//-0.25f	,-0.25f	,-2.25f	,1.0f,
		//-0.25f	, 0.25f	,-1.75f	,1.0f,
		-0.25f	, 0.25f	,-2.25f	,1.0f,

		//right
		 0.25f	,-0.25f	,-2.25f	,1.0f,
		 0.25f	, 0.25f	,-2.25f	,1.0f,
		 0.25f	, 0.25f	,-1.75f	,1.0f,
		// 0.25f	,-0.25f	,-2.25f	,1.0f,
		// 0.25f	, 0.25f	,-1.75f	,1.0f,
		 0.25f	,-0.25f	,-1.75f	,1.0f,

		//top
		 0.25f	, 0.25f	,-1.75f	,1.0f,
		 0.25f	, 0.25f	,-2.25f	,1.0f,
		-0.25f	, 0.25f	,-2.25f	,1.0f,
		// 0.25f	, 0.25f	,-1.75f	,1.0f,
		//-0.25f	, 0.25f	,-2.25f	,1.0f,
		-0.25f	, 0.25f	,-1.75f	,1.0f,		 
		
		//bottom
		 0.25f	,-0.25f	,-1.75f	,1.0f,
		-0.25f	,-0.25f	,-1.75f	,1.0f,
		-0.25f	,-0.25f	,-2.25f	,1.0f,
		// 0.25f	,-0.25f	,-1.75f	,1.0f,
		//-0.25f	,-0.25f	,-2.25f	,1.0f,
		 0.25f	,-0.25f	,-2.25f	,1.0f		
	};

	float vertexColors[] = {
		1.0f	,1.0f	,0.0f	,1.0f,
		1.0f	,1.0f	,0.0f	,1.0f,
		1.0f	,1.0f	,0.0f	,1.0f,
		1.0f	,1.0f	,0.0f	,1.0f,
		//1.0f	,1.0f	,0.0f	,1.0f,
		//1.0f	,1.0f	,0.0f	,1.0f,

		//0.0f	,0.0f	,1.0f	,1.0f,
		//0.0f	,0.0f	,1.0f	,1.0f,
		0.0f	,0.0f	,1.0f	,1.0f,
		0.0f	,0.0f	,1.0f	,1.0f,
		0.0f	,0.0f	,1.0f	,1.0f,
		0.0f	,0.0f	,1.0f	,1.0f,

		0.0f	,1.0f	,0.0f	,1.0f,
		0.0f	,1.0f	,0.0f	,1.0f,
		0.0f	,1.0f	,0.0f	,1.0f,
		0.0f	,1.0f	,0.0f	,1.0f,
		//0.0f	,1.0f	,0.0f	,1.0f,
		//0.0f	,1.0f	,0.0f	,1.0f,

		//0.0f	,1.0f	,1.0f	,1.0f,
		//0.0f	,1.0f	,1.0f	,1.0f,
		0.0f	,1.0f	,1.0f	,1.0f,
		0.0f	,1.0f	,1.0f	,1.0f,
		0.0f	,1.0f	,1.0f	,1.0f,
		0.0f	,1.0f	,1.0f	,1.0f,				

		1.0f	,0.0f	,0.0f	,1.0f,
		1.0f	,0.0f	,0.0f	,1.0f,
		1.0f	,0.0f	,0.0f	,1.0f,
		1.0f	,0.0f	,0.0f	,1.0f,
		//1.0f	,0.0f	,0.0f	,1.0f,
		//1.0f	,0.0f	,0.0f	,1.0f,

		//1.0f	,0.0f	,1.0f	,1.0f,
		//1.0f	,0.0f	,1.0f	,1.0f,
		1.0f	,0.0f	,1.0f	,1.0f,
		1.0f	,0.0f	,1.0f	,1.0f,
		1.0f	,0.0f	,1.0f	,1.0f,
		1.0f	,0.0f	,1.0f	,1.0f
	};

	unsigned short vertexIndex[] = {
		0,1,2,		0,2,3,
		4,5,6,		4,6,7,
		8,9,10,		8,10,11,
		12,13,14,	12,14,15,
		16,17,18,	16,18,19,
		20,21,22,	20,22,23
	};

	xOffset = 0.0f;
	yOffset = 0.0f;
	zOffset = 0.0f;
	oldX = 0.0;
	oldY = 0.0;

	std::copy(vertexPosition, vertexPosition	+ 4*3*8, this->vertexPosition);
	std::copy(vertexColors	, vertexColors 		+ 4*3*8, this->vertexColors);
	std::copy(vertexIndex	, vertexIndex 		+ 4*3*3, this->vertexIndex);

	//12 elemani oldugu icin +12

	InitializeProgram();
	InitializeVertexBuffer();

	glEnable(GL_DEPTH_TEST);	// depthtesti ac
	glDepthMask(GL_TRUE);		// yazsin mi - evet
	glDepthFunc(GL_LEQUAL);		// buyukten kucuge mi kucukten buyuge mi-lessequal
	glDepthRange(0.0f, 1.0f);	// 0 ile 1 arasinda olsun


	/*ARKADAKI KISIMLARI CIZMEMESI ICIN YAZILAN KODLAR*/
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);/*arka tarafini cizme*/
	/*NERESININ ARKA TARAF OLDUGUNU BELIRLEMEK ICIN*/
	glFrontFace(GL_CCW);/*counterclockwise https://www.opengl.org/sdk/docs/man/html/glFrontFace.xhtml*/
	/*glFrontFace(GL_CCW); //counterclockwise https://www.opengl.org/sdk/docs/man/html/glFrontFace.xhtml*/

	float zNear = 1.0f, zFar = 3.0f;
	/*float perspectiveMat[16] = {0};*/
	/*dizimize memory atamasi yapmak*/
	memset(perspectiveMat, 0, 16 * sizeof(float));
	perspectiveMat[0] = 1;
	perspectiveMat[5] = 1;
	perspectiveMat[10] = (zNear + zFar) / (zNear - zFar);
	perspectiveMat[11] = (2 * zNear * zFar) / (zNear - zFar);
	perspectiveMat[14] = -1;

	glUseProgram(theProgram);
	/*diziyi openGL kolon gibi, C++ satir gibi aliyor, satir gibi almasi icin GL_TRUE yapiyoruz*/
	glUniformMatrix4fv(perspectiveMatLocation, 1, GL_TRUE, perspectiveMat);
	glUseProgram(0);
}

void GlHelper::InitializeProgram() {
	std:: vector<GLuint> shaderList;
	/*konumlar vektorler fiziksel olaylar vertex.shader*/
	shaderList.push_back(CreateShader(GL_VERTEX_SHADER, "./vertex.shader"));
	/*butun renklendirme islemleri fragment.shader da*/
	shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, "./fragment.shader"));

	this->theProgram = CreateProgram(shaderList);

	timeUni = glGetUniformLocation(theProgram, "time");
	offset = glGetUniformLocation(theProgram, "offset");
	perspectiveMatLocation = glGetUniformLocation(theProgram, "perspectiveMat");
	/*zNearLocation = glGetUniformLocation(theProgram, "zNear");
	zFarLocation = glGetUniformLocation(theProgram, "zFar");
	frustumScaleXLocation = glGetUniformLocation(theProgram, "frustumScaleX");
	frustumScaleYLocation = glGetUniformLocation(theProgram, "frustumScaleY");*/

	std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);//yukarda olusturdugumuz *.shader lari siliyor
}

GLuint GlHelper::CreateShader(GLenum eShaderType, const std::string &strShaderFile) {
	GLuint shader = glCreateShader(eShaderType);
	std::string shaderCode;
	std::ifstream shaderStream(strShaderFile.c_str(), std::ios::in);

	if (shaderStream.is_open())	{
		std::string Line = "";
		while(getline(shaderStream, Line)) {
			shaderCode += "\n" + Line;
		}
		shaderStream.close();
	}
	else{
		std::cerr << strShaderFile.c_str() << "dosyasi acilamadi." << std::endl;
		return -1;
	}
	const char * shaderCodePtr = shaderCode.c_str();
	glShaderSource(shader, 1, &shaderCodePtr, NULL);

	glCompileShader(shader);
	//hata olursa LOGlama islemleri
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	//derleme konusunda bir sonuc donecek
	if (status == GL_FALSE)	{
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch(eShaderType) {
		case GL_VERTEX_SHADER:
			strShaderType = "vertex";
			break;
		case GL_FRAGMENT_SHADER:
			strShaderType = "fragment";
			break;		
		}
		std::cerr << strShaderType << " tipi shader derlenemedi. Detay: \n" << strInfoLog << std::endl;
	}
	return shader;
}

GLuint GlHelper::CreateProgram(const std::vector<GLuint> &shaderList) {
	GLuint program = glCreateProgram();
	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++){/*size_t unsigned int for 'for'*/
		glAttachShader(program, shaderList[iLoop]);
	}

	glLinkProgram(program);
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);

	if ( status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		std::cerr << "Linkleme Sorunu: " << strInfoLog << std::endl;
		return -1;
	}

	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++){/*size_t unsigned int for 'for'*/
		glDetachShader(program, shaderList[iLoop]);
	}

	return program;
}

void GlHelper::render(){
	//pencere rengini belirle
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	//pencereyi bu renkle temizle ve depth i de temizle
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ciziktirmeye baslanacak program
	glUseProgram(theProgram);

/*
	glUniform1f(zFarLocation, 15.0f);
	glUniform1f(zNearLocation, 0.01f);
*/

	/*glfwGetTime program acildiktan bu yana gecen zamani gosterir.*/
	glUniform1f(timeUni, glfwGetTime());
	/*glUniform2f(offset, xOffset, yOffset);*/
	glUniform3f(offset, xOffset, yOffset, zOffset);
	//yollayacagimiz vertexlerle ilgili bilgi vermeden once
	glEnableVertexAttribArray(0);
	//
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	//2.size(x,y,z,w),3.tipi,4.normalize yapilip yapilmayacagi,5.aralarinda bosluk var mi?,6. nerden baslayacagi(0 basindan)
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	/*Renkleri gonder*/
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferObject);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);

	glDrawElements(GL_TRIANGLES, 4*3*3, GL_UNSIGNED_SHORT, 0);


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glUseProgram(0);//ciziktirme islemlerini bitir.
}

void GlHelper::InitializeVertexBuffer(){
	/*RAM den CPUnnu RAMina aktarim saglamak icin*/
	
	/* 1 buffer generate et*/
	glGenBuffers(1, &positionBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject); /*RAMina aktar*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexPosition), vertexPosition, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);//Ayirdigimiz alani geri birak

	glGenBuffers(1, &colorBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexColors), vertexColors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->vertexIndex), vertexIndex, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void GlHelper::move(int direction) {
	float movementAmount = 0.005f;
	switch(direction){
		case GLFW_KEY_UP:
			yOffset += movementAmount; break;
		case GLFW_KEY_DOWN:
			yOffset -= movementAmount; break;
		case GLFW_KEY_LEFT:
			xOffset -= movementAmount; break;
		case GLFW_KEY_RIGHT:
			xOffset += movementAmount; break;


		case GLFW_KEY_W:
			yOffset += movementAmount; break;
		case GLFW_KEY_A:
			xOffset -= movementAmount; break;
		case GLFW_KEY_S:
			yOffset -= movementAmount; break;
		case GLFW_KEY_D:
			xOffset += movementAmount; break;		
	}

	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPosition), vertexPosition, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GlHelper::mmove(double x, double y) {
	if (oldX < x) { move(GLFW_KEY_RIGHT); }
	if (oldX > x) { move(GLFW_KEY_LEFT); }
	if (oldY < y) { move(GLFW_KEY_DOWN); }
	if (oldY > y) { move(GLFW_KEY_UP); }

	oldX = x;
	oldY = y;
}

void GlHelper::smove(double y) {
	zOffset += y / 10;
}

void GlHelper::reshape(int w, int h) {
	perspectiveMat[0] = ((float)h) / ((float)w);

	glUseProgram(theProgram);
	glUniformMatrix4fv(perspectiveMatLocation, GL_TRUE, 1, perspectiveMat);
	glUseProgram(0);

	glViewport(0,0, (GLsizei)w, (GLsizei) h);
}