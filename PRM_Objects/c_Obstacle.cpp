#include "c_Obstacle"



/// KONSTRUKTORY / DESTRUKTORY
Obstacle::Obstacle(int X, int Y, PRM_Object E, char S){
    this->xpos = X;
    this->ypos = Y;
    this->etykieta = E;

    if (S==0){
    }else{
        this->symbol = S;
    }

}

Obstacle::~Obstacle() {
    this->xpos = -1;
    this->ypos = -1;
    this->symbol = 'x';
}




