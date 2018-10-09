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

        _CreateRenderDevice = (CreateRenderDevice_t) dlsym(_libHandle, "CreateRenderDevice");

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
    _renderDevice->Init(width, height, title);
    _renderDevice->CloseRenderDevice();

    return RDERROR::RD_SUCCESS;
}

RenderDevice* Renderer::GetRenderDevice()
{
    return _renderDevice;
}

char* Renderer::GetError()
{
    return error;
}

Renderer::~Renderer()
{

}
