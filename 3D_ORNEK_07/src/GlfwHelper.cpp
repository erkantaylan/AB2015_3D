#include "GlfwHelper.h"

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mod) {
	GlfwHelper *glfwHelper = static_cast<GlfwHelper*>(glfwGetWindowUserPointer(window));

	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch(key) {
			case GLFW_KEY_UP:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_DOWN:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_LEFT:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_RIGHT:
				glfwHelper->getGlHelper()->move(key);
				break;
				
			case GLFW_KEY_W:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_A:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_S:
				glfwHelper->getGlHelper()->move(key);
				break;
			case GLFW_KEY_D:
				glfwHelper->getGlHelper()->move(key);
				break;
		}
	}
}

static void mouse_callback(GLFWwindow *window, double xOffset, double yOffset) {
	GlfwHelper *glfwHelper = static_cast<GlfwHelper*>(glfwGetWindowUserPointer(window));
	glfwHelper->getGlHelper()->mmove(xOffset, yOffset);

}

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
	this->window = glfwCreateWindow(720,640, "AB2015-3D Ornek 6", NULL, NULL);

	if (this->window == NULL) {
		std::cerr << "GLFW pencere acilamadi, ekran karti surucunuz OpenGL 3.3 desteklemiyor olabilir." << std::endl;
		/*Pencereyi acamazsa RAM i bosalt*/
		glfwTerminate();
		return;
	}
	/*glfwHelper dan glHelper a bilgi gondermek icin*/
	glfwSetWindowUserPointer(window, this);

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
	
	/*bir tusa basildigi zaman bu functionu cagir*/
	glfwSetKeyCallback(window, key_callback);
	/*imlec harelet,fare tus*/
	glfwSetCursorPosCallback(window, mouse_callback);


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


GlHelper* GlfwHelper::getGlHelper() {
	return openglHelper;
}