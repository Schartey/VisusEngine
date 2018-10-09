#include "Renderer.h"

#include <stdio.h>

int main(void)
{
    Renderer* renderer = new Renderer();
    if(renderer->CreateRenderDevice("OpenGL", 640, 480, "Test") != RD_SUCCESS)
    {
        char* err = renderer->GetError();
        printf("%s", err);
        fflush(stdout);
    }
}
