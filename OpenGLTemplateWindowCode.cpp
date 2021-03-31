#include <stdio.h>
#include <string.h>


#include <GL/glew.h>
#include <GLFW/glfw3.h>



// Window size
const GLint WIDTH = 800, HEIGHT = 600;


int main()
{

    // Init GLFW
    if (!glfwInit()) {
        printf("GLFW init failed");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW Window
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Block backward compability
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compability
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);



    // Create window
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test window", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW window creation failed");
        glfwTerminate();
        return 1;
    }

    // Get buffer information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);


    // Allow modern extension features
    glewExperimental = GL_TRUE;

    // Init GLEW
    if (glewInit() != GLEW_OK)
    {
        printf("GLEW Failed to initialize");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);
        

    float r = 0.0f, b = 0.f, g = 0.f;
    float dr = 0.01f, db = 0.02f, dg = 0.03f;
    // Main Loop
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Get + handle user input events
        glfwPollEvents();

        
        // Clear buffer
        glClearColor(r, b, g, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        

        // Swap double buffers
        glfwSwapBuffers(mainWindow);
    }




    return 0;
}

