#include <GLFW/glfw3.h>

GLFWwindow* window;

int Backend_Glfw_Init( void ) {
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

	/* Make the window's context current */
    glfwMakeContextCurrent(window);

	return 0;
}

int Backend_Glfw_Poll( void ) {
    glfwPollEvents();
    usleep(16);
}

int Backend_Glfw_Shutdown( void ) {
	return 0;
}

backend_t Backend_Glfw_GetAPI( void ) {
	static backend_t backendApi = {
		"GLFW",
		Backend_Glfw_Init,
		Backend_Glfw_Shutdown,
	};
	return backendApi;
}
