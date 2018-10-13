#ifndef DLHELPER_H
#define DLHELPER_H

#define DL_FAILED(x) !(x == DL_SUCCESS)

enum DL_ERROR {
    DL_SUCCESS,
    DL_FAIL,
    DL_OPEN,
    DL_SYM
};

#ifdef _WIN32

#else

enum DL_MODE {
    DL_LAZY = 0x000001
};
#endif

class DLLibrary {
public:
    DLLibrary(const char* lib);
    DL_ERROR Load(DL_MODE dlMode);
    DL_ERROR DlSym(const char* symName, void* symFunc);
    char* GetError();
    void Release();
    ~DLLibrary();
private:
    const char* _name;
    void* _libHandle;

    static char* error;
};

extern "C" {
    DL_ERROR dlLibraryOpen(const char* lib, DL_MODE dlMode, DLLibrary* _libHandle);
    DL_ERROR dlLibraryClose(DLLibrary* _libHandle);
}

#endif // DLHELPER_H
