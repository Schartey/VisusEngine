#ifndef RENDERDEVICE_H
#define RENDERDEVICE_H

enum RDERROR_OGL {
    OGL_INIT_SUCCESS,
    GLFW_INIT_ERROR,
    CREATE_WINDOW_ERROR
};

enum RDERROR_D3D {
    D3D_INIT_SUCCESS
};

class RenderDevice
{
public:
    virtual int Init(int width, int height, const char* title) = 0;
    virtual void CloseRenderDevice() = 0;
    virtual void GetError(int &error, const char* description) = 0;
    virtual ~RenderDevice() = 0;

};

#endif // RENDERDEVICE_H
