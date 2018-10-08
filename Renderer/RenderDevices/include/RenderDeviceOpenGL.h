#ifndef RENDERDEVICEOPENGL_H
#define RENDERDEVICEOPENGL_H

#include "../../include/RenderDevice.h"

#include "../Glad/include/glad/glad.h"
#include "GLFW/glfw3.h"

class RenderDeviceOpenGL : RenderDevice
{
protected:
    virtual RenderDevice* CreateRenderDevice() override;
    virtual void CloseRenderDevice() override;
    virtual void GetError(int &error, const char* description) override;
private:
    GLFWwindow* _window;

    static int error;
    static const char* description;

    static void error_callback(int error, const char* description);
};

#endif // RENDERDEVICEOPENGL_H
