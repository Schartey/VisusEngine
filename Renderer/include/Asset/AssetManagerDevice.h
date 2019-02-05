#ifndef ASSETMANAGERDEVICE_H
#define ASSETMANAGERDEVICE_H

#include "ImageLoader.h"

class AssetManagerDevice
{
public:
    AssetManagerDevice();

    virtual bool CreateTexture(Texture texture);
    virtual void SetImageLoader(ImageLoader* imageLoader);

    virtual ~AssetManagerDevice(void) {}
};

#endif // ASSETMANAGERDEVICE_H
