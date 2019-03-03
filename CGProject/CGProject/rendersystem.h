#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<vertexbuffer.h>
#include<vector>
#include<shaderinterface.h>

class RenderSystem
{
public:
    static RenderSystem& getRenderSystem();
    void deleteRenderSystem();
    void render(VertexBuffer *vertexBuffer);
private:
    GLFWwindow* _window ;
    std::vector<ShaderInterface *> *shaders;
    RenderSystem();
    ~RenderSystem();
};

#endif // RENDERSYSTEM_H
