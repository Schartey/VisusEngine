#ifndef RENDERER_H
#define RENDERER_H

#include "RenderDevice.h"

enum RDERROR {
    RD_SUCCESS,
    DLOPEN_ERROR,
    DLSYM_ERROR,
    INIT_ERROR
};

typedef RenderDevice* (*CreateRenderDevice_t)();

class Renderer
{
public:
    Renderer();
    int CreateRenderDevice(const char* api, int width, int height, const char* title);
    RenderDevice* GetRenderDevice();
    char* GetError();
    ~Renderer();

private:
    void* _libHandle;
    CreateRenderDevice_t _CreateRenderDevice;

    RenderDevice* _renderDevice;

    static char* error;

};

#endif // RENDERER_H
