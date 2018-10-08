#ifndef RENDERDEVICE_H
#define RENDERDEVICE_H

class RenderDevice
{
protected:
    virtual RenderDevice* CreateRenderDevice() = 0;
    virtual void CloseRenderDevice() = 0;
    virtual void GetError(int &error, const char* description) = 0;
    virtual ~RenderDevice() = 0;

};

#endif // RENDERDEVICE_H
