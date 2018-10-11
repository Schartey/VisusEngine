#include "Asset/ImageLoader.h"

#include "IL/ilut.h"

ImageLoader::ImageLoader()
{
    ilInit();
}

bool ImageLoader::LoadImage(const char* name, Image img, int &err)
{
    img.imageId = ilGenImage();
    ilBindImage(img.imageId); 			// Bind the image

    bool success = ilLoadImage(name); 	// Load the image file
                                    // If we managed to load the image, then we can start to do things with it...
    if (success)
    {
        img.data = ilGetData();
        if (!img.data) {
            ilBindImage(0);
            ilDeleteImages(1, &img.imageId);
            return false;
        }

        img.width = ilGetInteger(IL_IMAGE_WIDTH);
        img.height = ilGetInteger(IL_IMAGE_HEIGHT);
        img.type = ilGetInteger(IL_IMAGE_TYPE);
        img.format = ilGetInteger(IL_IMAGE_FORMAT);
    }
    else
    {
        err = static_cast<int>(ilGetError());
        return false;
    }
    return true;
}

ImageLoader::~ImageLoader()
{
    ilShutDown();
}
