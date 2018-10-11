#ifndef RENDERER_H
#define RENDERER_H

#include "RenderDevice.h"
#include "Asset/AssetManager.h"

enum RDERROR {
    RD_SUCCESS,
    DLOPEN_ERROR,
    DLSYM_ERROR,
    INIT_ERROR
};

class Renderer
{
public:
    Renderer();
    int CreateRenderDevice(const char* api, int width, int height, const char* title);
    RenderDevice* GetRenderDevice();
    void Release();
    char* GetError();
    ~Renderer();

private:
    void* _libHandle;

    RenderDevice* _renderDevice;
    AssetManager* _assetManager;
    static char* error;

};

#endif // RENDERER_H
