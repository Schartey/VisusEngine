#include "OpenGL/AssetManagerDeviceOpenGL.h"

#include "GLFW/glfw3.h"

AssetManagerDeviceOpenGL::AssetManagerDeviceOpenGL() : AssetManagerDevice()
{

}

bool AssetManagerDeviceOpenGL::CreateTexture(Texture texture)
{
    glGenTextures(1, static_cast<GLuint*>(texture.texId));

    return true;
}

void AssetManagerDeviceOpenGL::SetImageLoader(ImageLoader* imageLoader)
{
    _imageLoader = imageLoader;
}

AssetManagerDeviceOpenGL::~AssetManagerDeviceOpenGL()
{

}
