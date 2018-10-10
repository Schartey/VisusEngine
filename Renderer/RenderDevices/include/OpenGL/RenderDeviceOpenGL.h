#ifndef RENDERDEVICEOPENGL_H
#define RENDERDEVICEOPENGL_H

#include "../../include/RenderDevice.h"

#include "../Glad/include/glad/glad.h"
#include "GLFW/glfw3.h"

class RenderDeviceOpenGL : public RenderDevice
{
public:
    RenderDeviceOpenGL();
    virtual int Init(int width, int height, const char* title) override;
    virtual bool IsRunning(void) override { return _running; }
    virtual void StartRendering(bool clearPixel, bool clearDepth, bool clearStencil) override;
    virtual void StopRendering(void) override;
    virtual void Clear(bool clearPixel, bool clearDepth, bool clearStencil) override;
    virtual void SetClearColor(float red, float green, float blue, float alpha) override;
    virtual void Release() override;

    virtual void GetError(int &error, const char* description) override;

    virtual ~RenderDeviceOpenGL() override;
private:
    GLFWwindow* _window;
    int _width;
    int _height;
    bool _running;
    GLfloat* clearColor;

    static int error;
    static const char* description;

    static void error_callback(int error, const char* description);
};

extern "C" {
    RenderDevice* CreateRenderDevice() {
        return new RenderDeviceOpenGL();
    }

    VSTATE CloseRenderDevice(RenderDevice* renderDevice)
    {
        if(!renderDevice)
        {
            return VSTATE::V_FAIL;
        }
        delete renderDevice;
        renderDevice = nullptr;
        return VSTATE::V_OK;
    }
}

#endif // RENDERDEVICEOPENGL_H
