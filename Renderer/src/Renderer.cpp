#include "Renderer.h"

#include <stdio.h>
#include <string.h>

char* Renderer::error = new char[256];

Renderer::Renderer()
{
}

int Renderer::CreateRenderDevice(const char* api, int width, int height, const char* title)
{
    if(strcmp(api, "OpenGL") == 0)
    {
        if(!dlLibraryOpen("libRenderDeviceOpenGL.so", DL_MODE::DL_LAZY, _libHandle) || _libHandle)
        {
            strcpy(Renderer::error, _libHandle->GetError());
            return DLOPEN_ERROR;
        }
        typedef RenderDevice* (*CreateRenderDevice_t)();
        CreateRenderDevice_t _CreateRenderDevice;

        if(DL_FAILED(_libHandle->DlSym("CreateRenderDevice", &_CreateRenderDevice)) || !_CreateRenderDevice)
        {
            strcpy(Renderer::error, _libHandle->GetError());
            return DLSYM_ERROR;
        }

        _renderDevice = _CreateRenderDevice();

        if(_renderDevice->Init(width, height, title) != RDERROR_OGL::OGL_INIT_SUCCESS)
        {
            int errNum;
            _renderDevice->GetError(errNum, error);
            return INIT_ERROR;
        }
    }
    else if(strcmp(api, "Direct3D"))
    {
        //Not implemented yet
    }

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
    CloseRenderDevice_t _CloseRenderDevice;

    if(DL_FAILED(_libHandle->DlSym("CreateRenderDevice", &_CloseRenderDevice)) || !_CloseRenderDevice)
    {
        strcpy(Renderer::error, _libHandle->GetError());
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
        dlLibraryClose(_libHandle);
    }
}

char* Renderer::GetError()
{
    return error;
}

Renderer::~Renderer()
{

}
