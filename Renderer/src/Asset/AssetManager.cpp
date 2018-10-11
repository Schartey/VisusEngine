#include "Asset/AssetManager.h"

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

AssetManager::AssetManager(AssetManagerDevice* assetManagerDevice)
{
    _numTextures = 0;
    _numMaterials = 0;

    _imageLoader = new ImageLoader();
    _assetManagerDevice = assetManagerDevice;
    _assetManagerDevice->SetImageLoader(_imageLoader);
}

uint32_t AssetManager::AddTexture(const char* name)
{
    uint32_t numTex = _numTextures;
    Texture texture;

    strcpy(texture.name, name);
    _assetManagerDevice->CreateTexture(texture);

    _textures.push_back(texture);
    _numTextures++;

    return numTex;
}

uint32_t AssetManager::AddMaterial(const char* name, Color diffuse, Color ambient, Color specular, Color emissive, float specPower)
{
    uint32_t numMat = _numMaterials;
    Material material;

    strcpy(material.name, name);
    material.diffuse = diffuse;
    material.ambient = ambient;
    material.specular = specular;
    material.emissive = emissive;
    material.specPower = specPower;

    _materials.push_back(material);
    _numMaterials++;

    return numMat;
}
