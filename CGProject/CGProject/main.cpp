#include<gamemanager.h>
using namespace std;

int main(int argc, char *argv[])
{
    GameManager *g= &GameManager::getGameManager();
    if (g != NULL){
        g->runGame();
        g->deleteGameManager();
    }

    return 0;
}
