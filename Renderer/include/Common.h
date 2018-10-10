#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

typedef struct VCOLOR_TYPE
{
    union {
        struct {
            float r;
            float g;
            float b;
            float a;
        };
        float c[4];
    };

    //Equals > ==
    /*inline bool operator==(VCOLOR_TYPE c)
    {
        return ((r <= c.r && r >= c.r) &&
                (g <= c.g && g >= c.g) &&
                (b <= c.b && b >= c.b) &&
                (a <= c.a && a >= c.a));
    }*/
} VCOLOR;

typedef struct VMATERIAL_TYPE
{
    VCOLOR diffuse;
    VCOLOR ambient;
    VCOLOR specular;
    VCOLOR emissive;
    float specPower;

    //Equals > ==
    /*inline bool operator==(VMATERIAL_TYPE m)
    {
        return ((diffuse == m.diffuse) &&
                (ambient == m.ambient) &&
                (specular == m.specular) &&
                (emissive == m.emissive) &&
                (power <= m.power && power >= m.power));
    }*/

} VMATERIAL;

typedef struct VTEXTURE_TYPE
{
    float alpha;
    char* name;
    void* data;
    VCOLOR* colorKeys;
    uint32_t numKeys;
} VTEXTURE;

typedef struct VSKIN_TYPE
{
    bool alpha;
    uint32_t material;
    uint32_t textures[8];
} VSKIN;

#endif // COMMON_H

