#ifndef RENDERDEVICEOPENGL_H
#define RENDERDEVICEOPENGL_H

#include "../../include/RenderDevice.h"

#include "../Glad/include/glad/glad.h"
#include "GLFW/glfw3.h"

class RenderDeviceOpenGL : public RenderDevice
{
public:
    virtual int Init(int width, int height, const char* title) override;
    virtual void CloseRenderDevice() override;
    virtual void GetError(int &error, const char* description) override;
private:
    GLFWwindow* _window;
    int _width;
    int _height;

    static int error;
    static const char* description;

    static void error_callback(int error, const char* description);
};

extern "C" {
    RenderDevice* CreateRenderDevice() {
        return new RenderDeviceOpenGL();
    }
}

#endif // RENDERDEVICEOPENGL_H
