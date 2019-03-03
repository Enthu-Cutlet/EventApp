#ifndef SHADERINTERFACE_H
#define SHADERINTERFACE_H
#include<iostream>

#include<GL/glew.h>
#include<shaderloader.h>

class ShaderInterface
{
public:
    ShaderInterface(const char *sourceVS, const char *sourceFS);
    ~ShaderInterface();
    GLuint getProgamHandle();
    GLint get_aPositionVertex();
    GLint get_uColor();
private:
    ShaderLoader *shader;
    GLint _aPositionVertex;
    GLint _uColor;
    char *_vertexShaderString;
    char *_fragmentShaderString;
    char *_getTextFromFile(const char *fileName);
};

#endif // SHADERINTERFACE_H
