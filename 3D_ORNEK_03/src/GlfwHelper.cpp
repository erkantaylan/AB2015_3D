#include "GlfwHelper.h"

GlfwHelper::GlfwHelper() {
    if (!glfwInit()) {
        std::cerr << "GLFW baslatilamadi." << std::endl;
        return;
    }

	/*GLFW ye kullanilacak surumun belirtilmesi*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	/*profil turu CORE*/
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//UYUMLULUK SORUNU ICIN -> MAC lerde hata vermemesi icin
	//gflwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/*Pencereyi Olustur
	COZUNURNUK
	BASLIK
	BASLANGIC SEKLI?
	BASKA BIR PENCEREYLE ETKILESIM (CONTEXT SHARING)*/
	this->window = glfwCreateWindow(720,640, "AB2015-3D Ornek 3", NULL, NULL);

	if (this->window == NULL) {
		std::cerr << "GLFW pencere acilamadi, ekran karti surucunuz OpenGL 3.3 desteklemiyor olabilir." << std::endl;
		/*Pencereyi acamazsa RAM i bosalt*/
		glfwTerminate();
		return;
	}
	
	/*bu pencereyi kullan*/
	glfwMakeContextCurrent(this->window);

	/*GLEW'in baslatilmasi. experimental ise bug i onlemek icin var*/
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cerr << "GLEW baslatilamadi" << std::endl;
		return;
	}

	/*ESC ye basma*/
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	openglHelper = new GlHelper();
	if (openglHelper == NULL)
	{
		glfwTerminate();
	}
}

void GlfwHelper::loop(){
	do
	{
		openglHelper->render();
		glfwSwapBuffers(window);
		/*input var mi*/
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
	/*ESC ye basilmadikca donguyu devam ettir.*/

}