#include "OpenGL/SkinManagerOpenGL.h"

#include <limits>
#include <boost/log/trivial.hpp>
#include <GLFW/glfw3.h>

#define MAX_ID std::numeric_limits<uint32_t>::max()

SkinManagerOpenGL::SkinManagerOpenGL()
{
    _numMaterials = 0;
    _numTextures = 0;
    _numSkins = 0;

    BOOST_LOG_TRIVIAL(info) << "SkinManagerOpenGL initialized";
}

SkinManagerOpenGL::~SkinManagerOpenGL()
{
    for(VTEXTURE texture : _textures)
    {
        if(texture.data)
        {
            glDeleteTextures(1, (static_cast<GLuint*>(texture.data)));
            texture.data = nullptr;
        }
        //Delete colorkeys?
        if(texture.name)
        {
            delete [] texture.name;
            texture.name = nullptr;
        }
        _textures.clear();
    }

    _materials.clear();
    _skins.clear();

    BOOST_LOG_TRIVIAL(info) << "SkinManagerOpenGl destroyed";
}

VSTATE SkinManagerOpenGL::AddSkin(const VCOLOR* ambient,
                                const VCOLOR* diffuse,
                                const VCOLOR* emissive,
                                const VCOLOR* specular,
                                float specPower,
                                uint32_t* skinId)
{
    VMATERIAL mat;
    mat.ambient = *ambient;
    mat.diffuse = *diffuse;
    mat.emissive = *emissive;
    mat.specular = *specular;
    mat.specPower = specPower;

    uint32_t nMat;
    bool bMat;

    for(nMat = 0; nMat < _numMaterials; nMat++)
    {
        if(MaterialEqual(&mat, &_materials[nMat])) {
            bMat = true;
            break;
        }
    }

    VSKIN skin;

    if(bMat)
    {
        skin.material = nMat;
    }
    else
    {
        _materials.push_back(mat);
        skin.material = _numMaterials;
        _numMaterials++;
    }
    skin.alpha = false;

    for(int i = 0; i < 8; i++)
    {
        skin.textures[i] = MAX_ID;
    }

    (*skinId) = _numSkins;
    _numSkins++;

    return V_OK;
}

VSKIN SkinManagerOpenGL::GetSkin(uint32_t skinId)
{
    VSKIN skin;
    if(skinId < _numSkins)
    {
        skin = _skins[skinId];
    }
    return skin;
}

VMATERIAL SkinManagerOpenGL::GetMaterial(uint32_t materialId)
{
    VMATERIAL material;
    if(materialId < _numMaterials)
    {
        material = _materials[materialId];
    }
    return material;
}

const char* SkinManagerOpenGL::GetTextureName(uint32_t id, float* alpha, VCOLOR* ak, uint32_t* num)
{
    if(id >= _numTextures) return nullptr;
    if(alpha) *alpha = _textures[id].alpha;
    if(num) *num = _textures[id].numKeys;

    if(_textures[id].colorKeys && ak)
    {
        memcpy(ak, _textures[id].colorKeys, sizeof(VCOLOR) * _textures[id].numKeys);
    }

    return _textures[id].name;
}

bool SkinManagerOpenGL::MaterialEqual(const VMATERIAL* mat0, const VMATERIAL* mat1)
{
    return (ColorEqual(&mat0->diffuse, &mat1->diffuse) &&
            ColorEqual(&mat0->ambient, &mat1->ambient) &&
            ColorEqual(&mat0->specular, &mat1->specular) &&
            ColorEqual(&mat0->emissive, &mat1->emissive) &&
            (mat0->power <= mat1->power && mat0->power >= mat1->power));
}

inline bool SkinManagerOpenGL::ColorEqual(const VCOLOR* col0, const VCOLOR* col1)
{
    return ((col0->r <= col1->r && col0->r >= col1->r) &&
            (col0->g <= col1->g && col0->g >= col1->g) &&
            (col0->b <= col1->b && col0->b >= col1->b) &&
            (col0->a <= col1->a && col0->a >= col1->a));
}



