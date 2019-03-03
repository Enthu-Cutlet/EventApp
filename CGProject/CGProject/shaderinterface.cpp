#include "shaderinterface.h"
#include<stdio.h>
#include<stdlib.h>

ShaderInterface::ShaderInterface(const char *sourceVS, const char *sourceFS)
{
    shader= new ShaderLoader(_getTextFromFile(sourceVS), _getTextFromFile(sourceFS));
    _aPositionVertex= glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
    _uColor= glGetUniformLocation(shader->getProgramHandle(), "uColor");

}
ShaderInterface::~ShaderInterface(){
    delete shader;
}

GLuint ShaderInterface::getProgamHandle(){
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex(){
    return _aPositionVertex;

}

GLint ShaderInterface::get_uColor(){
    return _uColor;

}
char *ShaderInterface::_getTextFromFile(const char *fileName){
    FILE *fp= fopen(fileName, "rt");
    fseek(fp,0, SEEK_END);
    int x= (int)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *str=(char*) malloc(sizeof(char)*(x+1));
    x= (int)fread(str, sizeof(char), x, fp);
    str[x]='\0';
    return str;
}
