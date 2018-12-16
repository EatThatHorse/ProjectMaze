
#include "c_Unit"


int Unit::Move (Direction current){
/** Metoda odpowiedzialna za przemieszczanie sie Obiektu [Unit].
    Modyfikuje odziedziczone po klasie [Obstacle] zmienne polozenia.
*/  /*  ───────────────────────────────────────────────────────────────────────
        POMOCNICZA ILUSTRACJA TABLICY:
        ...->tab[rowSize][colSize]
              └─ jest typu char**

              0  1  2  3 ... X       X= ...->(colSize-1) = 69
           0 [ ][ ][ ][ ][ ][ ]
           1 [ ][ ][ ][ ][ ][ ]
           2 [ ][ ][ ][ ][ ][ ]
          ...[ ][ ][ ][ ][ ][ ]    [-1 bo mowimy o ostatnich indeksach.]
           Y [ ][ ][ ][ ][ ][ ]

           Y = ...->(rowSize-1) = 32
        ───────────────────────────────────────────────────────────────────────
    */

    // ---------------------------------------------------------------------------------------------
    // Variables Choosen to Execute:
    char** TAB_TMP;     // Only for Reading Purposes.
    int X_DIFF;         // Difference between Object X Position
    int Y_DIFF;         // Difference between Object Y Position

    int SPEED_TMP;
    // ---------------------------------------------------------------------------------------------
    TAB_TMP = this->roomPos->TAB();

    if (current == UP) {
        X_DIFF =  0;
        Y_DIFF = -1;
        SPEED_TMP = this->speedVY;
    }
    if (current == DOWN) {
        X_DIFF = 0;
        Y_DIFF = 1;
        SPEED_TMP = this->speedVY;
    }
    if (current == LEFT) {
        X_DIFF = -1;
        Y_DIFF =  0;
        SPEED_TMP = this->speedHX;
    }
    if (current == RIGHT) {
        X_DIFF = 1;
        Y_DIFF = 0;
        SPEED_TMP = this->speedHX;
    }
    // ---------------------------------------------------------------------------------------------

    for (int tmp=1; tmp<=SPEED_TMP; ++tmp){       // Tyle ile [SPEED_TMP], tyle krokow zrobic.
        // ---------------------------------------------------------------------------------------------
        if (TAB_TMP[(ypos + Y_DIFF)][xpos + X_DIFF] == ' ') {       // Czy pole nad graczem jest puste?
            /** TAK, moze zrobic krok. **/
            this->roomPos->EditPX (xpos, ypos, ' ');        // Tam gdzie stalismy zostaje puste pole.
            this->ypos = (this->ypos + Y_DIFF);                  // Przemieszczamy sie: [Y-1]
            this->xpos = (this->xpos + X_DIFF);                  // Przemieszczamy sie: [Y-1]
            this->roomPos->EditPX (xpos, ypos, symbol);     // Tam gdzie idziemy pojawiamy sie my.
        }else{
            /** NIE, jest przeszkoda. Koniec ruchu. **/
            return current;
        }
        // ---------------------------------------------------------------------------------------------
    }
    return 0;
}
