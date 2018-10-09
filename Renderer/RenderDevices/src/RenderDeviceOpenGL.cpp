#include "RenderDeviceOpenGL.h"

int RenderDeviceOpenGL::error = 0;
const char* RenderDeviceOpenGL::description = nullptr;

int RenderDeviceOpenGL::Init(int width, int height, const char* title)
{
    if(!glfwInit())
    {
        return GLFW_INIT_ERROR;
    }

    glfwSetErrorCallback(error_callback);

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!_window)
    {

        return CREATE_WINDOW_ERROR;
    }
    _width = width;
    _height = height;

    glfwMakeContextCurrent(_window);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    return OGL_INIT_SUCCESS;
}

void RenderDeviceOpenGL::CloseRenderDevice()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void RenderDeviceOpenGL::GetError(int &error, const char* description)
{
    error = RenderDeviceOpenGL::error;
    description = RenderDeviceOpenGL::description;
}

void RenderDeviceOpenGL::error_callback(int error, const char* description)
{
    RenderDeviceOpenGL::error = error;
    RenderDeviceOpenGL::description = description;
}
