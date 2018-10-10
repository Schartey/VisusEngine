#ifndef SKINMANAGEROPENGL_H
#define SKINMANAGEROPENGL_H

#include "../../include/SkinManager.h"

#include <vector>

class SkinManagerOpenGL : public SkinManager
{
friend class OpenGLCache;

public:
    SkinManagerOpenGL(/* LOG */);
    ~SkinManagerOpenGL(void) override;

    virtual VSTATE AddSkin(const VCOLOR* ambient,
                         const VCOLOR* diffuse,
                         const VCOLOR* emissive,
                         const VCOLOR* specular,
                         float specPower,
                         uint32_t* skinId) override;

    virtual long AddTexture(uint32_t skinId,
                            const char* name,
                            bool hasAlpha,
                            float alpha,
                            VCOLOR* colorKeys,
                            uint32_t numColorKeys) override;

    virtual long AddTextureHeightmapAsBump(uint32_t skindId, const char* name) override;

    virtual bool MaterialEqual(const VMATERIAL* mat0, const VMATERIAL* mat1) override;

    virtual VSKIN GetSkin(uint32_t skinId) override;

    virtual VMATERIAL GetMaterial(uint32_t matId) override;

    virtual const char* GetTextureName(uint32_t id, float* alpha, VCOLOR* ak, uint32_t* num) override;

    virtual void LogCurrentStatus(char* log, bool detail) override;

protected:

    inline bool ColorEqual(const VCOLOR* col0, const VCOLOR* col1);

    long CreateTexture(VTEXTURE* texture, bool alpha);

protected:
    uint32_t _numSkins;
    uint32_t _numMaterials;
    uint32_t _numTextures;
    std::vector<VSKIN> _skins;
    std::vector<VMATERIAL> _materials;
    std::vector<VTEXTURE> _textures;
};

#endif // SKINMANAGEROPENGL_H
