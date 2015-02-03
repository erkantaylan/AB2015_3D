#include "GlHelper.h"

GlHelper::GlHelper() {
	float vertexPosition[] = {
		-0.5f	,-0.5f	,0.5f	,1.0f,
		 0.5f	,-0.5f	,0.5f	,1.0f,
		 0.5f	, 0.5f	,0.5f	,1.0f
	};

	float vertexColors[] = {
		1.0f	,0.0f	,0.0f	,1.0f,
		0.0f	,1.0f	,0.0f	,1.0f,
		0.0f	,0.0f	,1.0f	,1.0f
	};
	std::copy(vertexPosition, vertexPosition + 12, this->vertexPosition);
	std::copy(vertexColors, vertexColors + 12, this->vertexColors);
	//12 elemani oldugu icin +12

	InitializeProgram();
	InitializeVertexBuffer();

}

void GlHelper::InitializeProgram() {
	std:: vector<GLuint> shaderList;
	/*konumlar vektorler fiziksel olaylar vertex.shader*/
	shaderList.push_back(CreateShader(GL_VERTEX_SHADER, "./vertex.shader"));
	/*butun renklendirme islemleri fragment.shader da*/
	shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, "./fragment.shader"));

	this->theProgram = CreateProgram(shaderList);

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
	//pencereyi bu renkle temizle
	glClear(GL_COLOR_BUFFER_BIT);
	//ciziktirmeye baslanacak program
	glUseProgram(theProgram);

	
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

	
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glUseProgram(0);//ciziktirme islemlerini bitir.
}

void GlHelper::InitializeVertexBuffer(){
	/*RAM den CPUnnu RAMina aktarim saglamak icin*/
	
	/*1buffer generate et*/
	glGenBuffers(1, &positionBufferObject);

	/*RAMina aktar*/
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexPosition), vertexPosition, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);//Ayirdigimiz alani geri birak


	glGenBuffers(1, &colorBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, colorBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexColors), vertexColors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}