#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include<GL/glew.h>
#include<iostream>
#include <cstdlib>
#include<cstdio>
#include<vertexbuffer.h>
#include<rendersystem.h>
#include<GLFW/glfw3.h>

class GameManager
{
public:

    GLFWwindow *window;
    static GameManager& getGameManager();
    void deleteGameManager();
    void runGame();

private:
    bool _isRunning;
    RenderSystem* _renderSystemObject;
    VertexBuffer *vertexBufferObject;
    GameManager(bool run);
     ~GameManager();
};

#endif // GAMEMANAGER_H
