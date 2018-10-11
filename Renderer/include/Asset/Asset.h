#ifndef ASSET_H
#define ASSET_H

#include <IL/il.h>

typedef struct Color
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
} Color;

typedef struct Image
{
    char* name;
    ILuint imageId;
    ILubyte* data;
    int width;
    int height;
    int type;
    int format;
} Image;

typedef struct Texture
{
    char* name;
    void* texId;
} Texture;

typedef struct Material
{
    Color diffuse;
    Color ambient;
    Color specular;
    Color emissive;

    char* name;
    float specPower;
} Material;

#endif //ASSET_H
