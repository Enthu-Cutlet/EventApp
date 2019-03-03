#ifndef SHADERLOADER_H
#define SHADERLOADER_H
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#define GL_GLEXT_PROTOTYPES

class ShaderLoader
{
public:
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    GLuint getProgramHandle();
    ~ShaderLoader();

private:
    GLuint _programHandle;
    GLuint shade(GLenum shader, const char *src);
};

#endif // SHADERLOADER_H
