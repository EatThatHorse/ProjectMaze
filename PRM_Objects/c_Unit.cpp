
#include "c_Unit"


int Unit::Move (Direction current){
    /** Metoda odpowiedzialna za przemieszczanie sie Obiektu [Unit].
        Modyfikuje odziedziczone po klasie [Obstacle] zmienne polozenia.
    */
    // ---------------------------------------------------------------------------------------------
    // Variables Choosen to Execute:
    char** TAB_TMP;     // Only for Reading Purposes.
    int X_DIFF;         // Difference between Object X Position
    int Y_DIFF;         // Difference between Object Y Position

    int SPEED_TMP;
    // ---------------------------------------------------------------------------------------------
//    TAB_TMP = this->roomPos->TAB();

    if (current == UP) {
        X_DIFF =  0;
        Y_DIFF = -1;
        SPEED_TMP = this->speedVY;
        this->frontThing = TAB_TMP[ypos-1][xpos];
    }
    if (current == DOWN) {
        X_DIFF = 0;
        Y_DIFF = 1;
        SPEED_TMP = this->speedVY;
        this->frontThing = TAB_TMP[ypos+1][xpos];
    }
    if (current == LEFT) {
        X_DIFF = -1;
        Y_DIFF =  0;
        SPEED_TMP = this->speedHX;
        this->frontThing = TAB_TMP[ypos][xpos-1];
    }
    if (current == RIGHT) {
        X_DIFF = 1;
        Y_DIFF = 0;
        SPEED_TMP = this->speedHX;
        this->frontThing = TAB_TMP[ypos][xpos+1];
    }
    // ---------------------------------------------------------------------------------------------



    for (int tmp=1; tmp<=SPEED_TMP; ++tmp){     // Tyle ile [SPEED_TMP], tyle krokow zrobic.
        // ---------------------------------------------------------------------------------------------
        if (frontThing == ' ') {                // Czy pole PRZED Obiektem jest puste?
            /** TAK, moze zrobic krok. **/
//            this->roomPos->EditPX (xpos, ypos, ' ');        // Tam gdzie stal zostaje puste pole.
            this->ypos = (this->ypos + Y_DIFF);             // Przemieszczamy sie: [Y-1]
            this->xpos = (this->xpos + X_DIFF);             // Przemieszczamy sie: [X-1]
//            this->roomPos->EditPX (xpos, ypos, symbol);     // Tam gdzie idzie pojawia sie obiekt.
        }else{
            /** NIE, jest przeszkoda. Koniec ruchu. **/
            return current;
        }
        // ---------------------------------------------------------------------------------------------
    }
    return 0;
}

int Unit::Action (){

    return 0;
}


