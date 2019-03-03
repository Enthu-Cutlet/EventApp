#include "gamemanager.h"

GLfloat vertices[]{
    -0.5f,-0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.0f,0.5f,0.0f
};
GameManager::GameManager(bool run){
    window=glfwGetCurrentContext();
    vertexBufferObject= new VertexBuffer(vertices,sizeof(vertices), GL_TRIANGLES,3, sizeof(GLfloat)*3);
    _renderSystemObject= &RenderSystem::getRenderSystem();
    GameManager::_isRunning=run;
}
GameManager::~GameManager(){
    _renderSystemObject->deleteRenderSystem();
}
GameManager& GameManager::getGameManager(){
    static GameManager *gameManagerObject= NULL;
    if (gameManagerObject==NULL){
        if (!glfwInit()){
            fprintf(stderr, "Failed to initialize GLFW\n");
            return *gameManagerObject;
        }
        glfwWindowHint(GLFW_DEPTH_BITS,24);
        glfwWindowHint(GLFW_RED_BITS,8);
        glfwWindowHint(GLFW_GREEN_BITS,8);
        glfwWindowHint(GLFW_BLUE_BITS,8);
        glfwWindowHint(GLFW_ALPHA_BITS,8);
        GLFWwindow* window= glfwCreateWindow(1200,800,"Doom", NULL, NULL);
        glfwMakeContextCurrent(window);
        gameManagerObject= new GameManager(true);
        if (!gameManagerObject->window){
            fprintf(stderr, "Failed to create winow.\n");
            delete gameManagerObject;
            *gameManagerObject= NULL;
            return *gameManagerObject;
        }

    }



    return *gameManagerObject;
}
void GameManager::deleteGameManager(){
    GameManager *g= &GameManager::getGameManager();
    if (g!=NULL){
        glfwDestroyWindow(g->window);
        delete g;

        glfwTerminate();
    }
}
void GameManager::runGame(){
    while (_isRunning) {
        _renderSystemObject->render(vertexBufferObject);
        _isRunning= !(glfwWindowShouldClose(window));
        std::cout << _isRunning<< std::endl;

    }

}
