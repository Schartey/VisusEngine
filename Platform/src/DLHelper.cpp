#include "DLHelper.h"

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

char* DLLibrary::error = nullptr;

DLLibrary::DLLibrary(const char* lib)
{
    _name = lib;
}

DL_ERROR DLLibrary::Load(DL_MODE dlMode)
{
#ifdef _WIN32
        //Not implemented yet
#else
        _libHandle = dlopen(_name, dlMode);
        if(!_libHandle)
        {
            strcpy(DLLibrary::error, dlerror());
            return DL_OPEN;
        }
        dlerror();
#endif
        return DL_SUCCESS;
}

DL_ERROR DLLibrary::DlSym(const char* symName, void* symFunc)
{
    symFunc = (void*) dlsym(_libHandle, symName);

    if(!symFunc)
    {
        strcpy(DLLibrary::error, dlerror());
        return DL_SYM;
    }

    return DL_SUCCESS;
}

char* DLLibrary::GetError()
{
    return error;
}

void DLLibrary::Release()
{
#ifdef _WIN32
        //Not implemented yet
#else
        dlclose(_libHandle);
#endif
}

DLLibrary::~DLLibrary()
{
    Release();
}

DL_ERROR dlLibraryOpen(const char* lib, DL_MODE dlMode, DLLibrary* _libHandle)
{
    DLLibrary* dlLibrary = new DLLibrary(lib);
    DL_ERROR err = dlLibrary->Load(dlMode);
    _libHandle = dlLibrary;

    return err;
}

DL_ERROR dlLibraryClose(DLLibrary* _libHandle)
{
    if(!_libHandle)
    {
        return DL_FAIL;
    }
    delete _libHandle;
    _libHandle = nullptr;
    return DL_SUCCESS;
}
