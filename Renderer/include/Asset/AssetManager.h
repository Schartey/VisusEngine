#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Asset.h"
#include "AssetManagerDevice.h"

#include <vector>
#include <stdint.h>

//Takes care of cross-device stuff and asks AssetManagerDevice for things needed from device specific stuff
class AssetManager
{
public:
    AssetManager(AssetManagerDevice* assetManagerDevice);

    uint32_t AddTexture(const char* name);
    uint32_t AddMaterial(const char* name, Color diffuse, Color ambient, Color specular, Color emissive, float specPower);

    bool LoadImageForTexture(uint32_t tId, const char* name);

    ~AssetManager(void);

private:
    ImageLoader* _imageLoader;
    AssetManagerDevice* _assetManagerDevice;

    uint32_t _numTextures;
    uint32_t _numMaterials;

    std::vector<Texture> _textures;
    std::vector<Material> _materials;

};

#endif // ASSETMANAGER_H
