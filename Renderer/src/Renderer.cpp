#include "Renderer.h"

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

char* Renderer::error = new char[256];

Renderer::Renderer()
{
}

int Renderer::CreateRenderDevice(const char* api, int width, int height, const char* title)
{
    if(strcmp(api, "OpenGL") == 0)
    {
#ifdef _WIN32
        //Not implemented yet
#else
        _libHandle = dlopen("libRenderDeviceOpenGL.so", RTLD_LAZY);
        if(!_libHandle)
        {
            strcpy(Renderer::error, dlerror());
            return DLOPEN_ERROR;
        }
        dlerror();

        typedef RenderDevice* (*CreateRenderDevice_t)();
        CreateRenderDevice_t _CreateRenderDevice = (CreateRenderDevice_t) dlsym(_libHandle, "CreateRenderDevice");

        if(!_CreateRenderDevice)
        {
            //dlclose will remove contents of dlerror(), therefor Renderer::error = dlerror(), will result in wrong data after call
            strcpy(Renderer::error, dlerror());
            dlclose(_libHandle);
            return DLSYM_ERROR;
        }

        _renderDevice = _CreateRenderDevice();

        if(_renderDevice->Init(width, height, title) != RDERROR_OGL::OGL_INIT_SUCCESS)
        {
            int errNum;
            _renderDevice->GetError(errNum, error);
            return INIT_ERROR;
        }
#endif
    }
#ifdef _WIN32
    else if(strcmp(api, "Direct3D"))
    {
        //Not implemented yet
    }
#endif

    _assetManager = new AssetManager(_renderDevice->GetAssetManagerDevice());

    return RDERROR::RD_SUCCESS;
}

RenderDevice* Renderer::GetRenderDevice()
{
    return _renderDevice;
}

void Renderer::Release()
{
    if(!_libHandle)
    {
        Renderer::error = "No handle to library";
        return;
    }
    typedef bool (*CloseRenderDevice_t)(RenderDevice*);
    CloseRenderDevice_t _CloseRenderDevice = (CloseRenderDevice_t) dlsym(_libHandle, "CloseRenderDevice");

    if(!_CloseRenderDevice)
    {
        //dlclose will remove contents of dlerror(), therefor Renderer::error = dlerror(), will result in wrong data after call
        strcpy(Renderer::error, dlerror());
        dlclose(_libHandle);
    }

    if(_renderDevice)
    {
        if(!_CloseRenderDevice(_renderDevice))
        {
            Renderer::error = "Closing Render Device failed";
            _renderDevice = nullptr;
        }
    }

    if(_libHandle)
    {
        dlclose(_libHandle);
    }
}

char* Renderer::GetError()
{
    return error;
}

Renderer::~Renderer()
{

}
