#ifndef ASSETMANAGERDEVICEOPENGL_H
#define ASSETMANAGERDEVICEOPENGL_H

#include "../../include/Asset/AssetManagerDevice.h"

class AssetManagerDeviceOpenGL : public AssetManagerDevice
{
public:
    AssetManagerDeviceOpenGL();

    virtual bool CreateTexture(Texture texture) override;
    virtual void SetImageLoader(ImageLoader* imageLoader) override;

    virtual ~AssetManagerDeviceOpenGL() override;
private:
    ImageLoader* _imageLoader;

};

extern "C" {
    AssetManagerDevice* CreateAssetManagerDevice() {
        return new AssetManagerDeviceOpenGL();
    }

    bool CloseAssetManagerDevice(AssetManagerDevice* assetManagerDevice)
    {
        if(!assetManagerDevice)
        {
            return false;
        }
        delete assetManagerDevice;
        assetManagerDevice = nullptr;
        return true;
    }
}

#endif // ASSETMANAGERDEVICEOPENGL_H
