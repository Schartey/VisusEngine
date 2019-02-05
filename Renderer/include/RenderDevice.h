#ifndef RENDERDEVICE_H
#define RENDERDEVICE_H

#include "../../General/include/General.h"
#include "Asset/AssetManagerDevice.h"

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
    virtual bool IsRunning(void) = 0;
    virtual void StartRendering(bool clearPixel, bool clearDepth, bool clearStencil) = 0;
    virtual void StopRendering(void) = 0;
    virtual void Clear(bool clearPixel, bool clearDepth, bool clearStencil) = 0;
    virtual void SetClearColor(float red, float green, float blue, float alpha) = 0;
    virtual void Release(void) = 0;

    virtual AssetManagerDevice* GetAssetManagerDevice(void) = 0;

    virtual void GetError(int &error, const char* description) = 0;
    virtual ~RenderDevice(void) {}

};

#endif // RENDERDEVICE_H
