#include "RenderDeviceOpenGL.h"

RenderDevice* RenderDeviceOpenGL::CreateRenderDevice()
{
    if(!glfwInit())
    {
        return nullptr;
    }
}

void RenderDeviceOpenGL::CloseRenderDevice()
{
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
