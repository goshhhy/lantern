#include <stdio.h>

#include "shared.h"

int main(void)
{
    /* initialize resources shared by multiple threads */
    ConInit();

    if ( !RenderInit() ) {
        printf( "Error initializing console subsystem\n" );
        return 1;
    }

    /* Loop until the user closes the window */
    /*while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.25f, 0.25f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
        usleep(16);
    }

    glfwTerminate();*/
    return 0;
}