#include "c_Obstacle"



/// KONSTRUKTORY / DESTRUKTORY
Obstacle::Obstacle(int X, int Y, char S, DesRoom* roomPos){
    this->roomPos = roomPos;
    this->xpos = X;
    this->ypos = Y;
    this->symbol = S;
}

Obstacle::~Obstacle() {
    this->xpos = -1;
    this->ypos = -1;
    this->symbol = 'x';
}




