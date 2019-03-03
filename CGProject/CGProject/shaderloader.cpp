#include "shaderloader.h"

ShaderLoader::ShaderLoader(const char *sourceVS, const char *sourceFS)
{
    _programHandle= glCreateProgram();
    GLuint vertexShader= shade(GL_VERTEX_SHADER, sourceVS);
    GLuint fragmentShader= shade(GL_FRAGMENT_SHADER, sourceFS);
    glAttachShader(_programHandle, vertexShader);
    glAttachShader(_programHandle, fragmentShader);
    glLinkProgram(_programHandle);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
GLuint ShaderLoader::getProgramHandle(){
    return _programHandle;
}
GLuint ShaderLoader::shade(GLenum shader, const char *src){
    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle,1, &src, NULL);
    glCompileShader(shaderHandle);
    return shaderHandle;

}
ShaderLoader::~ShaderLoader(){
    glDeleteProgram(_programHandle);
}
