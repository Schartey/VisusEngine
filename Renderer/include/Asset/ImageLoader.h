#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "Asset.h"

//Should I put this in its own library?
class ImageLoader
{
public:
    ImageLoader();

    bool LoadImage(const char* name, Image img, int &err);

    ~ImageLoader();
};

#endif // IMAGELOADER_H
