#include <GLFW/glfw3.h>

backend_t b;

int main(void)
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.25f, 0.25f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        usleep(16);
    }

    glfwTerminate();
    return 0;
}