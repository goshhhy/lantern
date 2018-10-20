#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "shared.h"

int r_width, r_height;
bool r_fullscreen;

lsuccess_t RenderInit( void ) {

	if ( !glfwInit() )
		return false;

	

}