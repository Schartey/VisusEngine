#include "RenderDeviceOpenGL.h"

int RenderDeviceOpenGL::error = 0;
const char* RenderDeviceOpenGL::description = nullptr;

RenderDeviceOpenGL::RenderDeviceOpenGL() {
    clearColor = new GLfloat[4] { 0, 0, 0, 0 };
}
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

void RenderDeviceOpenGL::StartRendering(bool clearPixel, bool clearDepth, bool clearStencil)
{
    Clear(clearPixel, clearDepth, clearStencil);
    _running = true;
}

void RenderDeviceOpenGL::StopRendering()
{
    _running = false;
}

void RenderDeviceOpenGL::Clear(bool clearPixel, bool clearDepth, bool clearStencil)
{
    GLbitfield mask = 0;

    if(clearPixel) mask |= GL_COLOR_BUFFER_BIT;
    if(clearDepth) mask |= GL_DEPTH_BUFFER_BIT;
    if(clearStencil) mask |= GL_STENCIL_BUFFER_BIT;

    glClear(mask);
}

void RenderDeviceOpenGL::SetClearColor(float red, float green, float blue, float alpha)
{
    clearColor[0] = red;
    clearColor[1] = green;
    clearColor[2] = blue;
    clearColor[3] = alpha;
}

void RenderDeviceOpenGL::Release()
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

RenderDeviceOpenGL::~RenderDeviceOpenGL()
{
    Release();
}
