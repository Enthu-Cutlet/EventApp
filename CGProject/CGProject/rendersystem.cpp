#include "rendersystem.h"

RenderSystem::RenderSystem():_window(glfwGetCurrentContext())
{
    shaders= new std::vector<ShaderInterface *>;
    ShaderInterface *shader= new ShaderInterface("Shader.vs", "Shader.fs");
    shaders->push_back(shader);

}
RenderSystem::~RenderSystem(){
    delete shaders->at(0);
    delete shaders;

}
RenderSystem& RenderSystem::getRenderSystem(){
    static RenderSystem* renderSystemObject= NULL;
    if(renderSystemObject== NULL){
        renderSystemObject= new RenderSystem();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        gluPerspective(75.0f,1280.0f/720.0f,1,1000);
        glViewport(0.0f,0.0f,1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);

    }
}
void RenderSystem::deleteRenderSystem(){
    RenderSystem *r= &getRenderSystem();
    if(r!=NULL){
        delete r;
    }

}
void RenderSystem::render(VertexBuffer *vertexBuffer){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(1);
    glLoadIdentity();
    gluLookAt(0.0f,0.0f,-5.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glUniform4f(0, 1.0f, 0.0f,0.0f,1.0f);
    vertexBuffer->configureVertexAttributes(0);
    vertexBuffer->renderVertexBuffer();
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

