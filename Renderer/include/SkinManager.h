#ifndef SKINMANAGER_H
#define SKINMANAGER_H

#include "Common.h"
#include "../../General/include/General.h"

class SkinManager
{
public:
    virtual ~SkinManager(void) {}

    virtual VSTATE AddSkin(const VCOLOR* ambient,
                         const VCOLOR* diffuse,
                         const VCOLOR* emissive,
                         const VCOLOR* specular,
                         float specPower,
                         uint32_t* skindId) = 0;

    virtual long AddTexture(uint32_t skinId,
                            const char* name,
                            bool hasAlpha,
                            float alpha,
                            VCOLOR* colorKeys,
                            uint32_t numColorKeys) = 0;

    virtual long AddTextureHeightmapAsBump(uint32_t skindId,
                                   const char* name) = 0;

    virtual bool MaterialEqual(const VMATERIAL* mat0, const VMATERIAL* mat1) = 0;

    virtual VSKIN GetSkin(uint32_t skinId) = 0;

    virtual VMATERIAL GetMaterial(uint32_t matId) = 0;

    virtual const char* GetTextureName(uint32_t id, float* alpha, VCOLOR* ak, uint32_t* num) = 0;

    virtual void LogCurrentStatus(char* log, bool detail) = 0;
};

#endif // SKINMANAGER_H
