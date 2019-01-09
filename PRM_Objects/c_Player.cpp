
#include "c_Player"

#include <iostream>

int player::Move (Direction current){
    /** Metoda najpierw okresla kierunek, predkosc i wyglad gracza.
        Natepnie modyfikuje polozenie Playera oraz char'y na renderowanej tablicy.
    */

    // Variables Choosen to Execute:
    unsigned char** TAB_TMP = this->roomPos->TAB();     // Only for Reading Purposes.
    int X_DIFF;         // Difference between Object X Position
    int Y_DIFF;         // Difference between Object Y Position
    int SPEED_TMP;

    // ---------------------------------------------------------------------------------------------
    if (current == UP) {
        X_DIFF =  0;
        Y_DIFF = -1;
        SPEED_TMP = this->speedVY;
        this->symbol = ((char)S_UP);        // [↑]  zmiana wygladu
    }
    if (current == DOWN) {
        X_DIFF = 0;
        Y_DIFF = 1;
        SPEED_TMP = this->speedVY;
        this->symbol = ((char)S_DOWN);      // [↓]  zmiana wygladu
    }
    if (current == LEFT) {
        X_DIFF = -1;
        Y_DIFF =  0;
        SPEED_TMP = this->speedHX;
        this->symbol = ((char)S_LEFT);      // [←]  zmiana wygladu
    }
    if (current == RIGHT) {
        X_DIFF = 1;
        Y_DIFF = 0;
        SPEED_TMP = this->speedHX;
        this->symbol = ((char)S_RIGHT);     // [→]  zmiana wygladu
    }
    // ---------------------------------------------------------------------------------------------

    for (int tmp=1; tmp<=SPEED_TMP; ++tmp){     // Tyle ile [SPEED_TMP], tyle krokow zrobic.
        // ---------------------------------------------------------------------------------------------
        this->frontThing = TAB_TMP[ypos+Y_DIFF][xpos+X_DIFF];

        if (frontThing == ' ') {                // Czy pole PRZED Obiektem jest puste?
            /** TAK, moze zrobic krok. **/
            this->roomPos->EditPX (xpos, ypos, ' ');        // Tam gdzie stal zostaje puste pole.
            this->ypos = (this->ypos + Y_DIFF);             // Przemieszczamy sie: [Y-1]
            this->xpos = (this->xpos + X_DIFF);             // Przemieszczamy sie: [X-1]
            this->roomPos->EditPX (xpos, ypos, symbol);     // Tam gdzie idzie pojawia sie obiekt.
        }else{
            /** NIE, jest przeszkoda. Koniec ruchu. **/
            this->roomPos->EditPX (xpos, ypos, symbol);     // Update Symbolu, w razie gdyby gracz sie nie przemiescil, a obrocil.
            return current;
        }
        // ---------------------------------------------------------------------------------------------
    }
    return 0;
}

int player::Action (){
    /** Metoda wywolywana w Inpucie, dla klawisza [ENTER] [E] [e] */


    unsigned char** TAB_TMP = this->roomPos->TAB();;     // Only for Reading Purposes.

    if (this->symbol == (char)S_UP)     this->frontThing = TAB_TMP[ypos-1][xpos+0];
    if (this->symbol == (char)S_DOWN)   this->frontThing = TAB_TMP[ypos+1][xpos+0];
    if (this->symbol == (char)S_LEFT)   this->frontThing = TAB_TMP[ypos+0][xpos-1];
    if (this->symbol == (char)S_RIGHT)  this->frontThing = TAB_TMP[ypos+0][xpos+1];



    /// NATRAFILISMY NA DRZWI ───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───
    if (this->frontThing=='|'){     // Drzwi z Lewej LUB Prawej Strony
        // ------------------------------------------------------------
        this->roomPos->EditPX (xpos, ypos, ' ');    // Tam gdzie stal zostaje puste pole.

        if (this->xpos == 2){       // [←] Drzwi z LEWEJ Strony

            this->roomPos = roomPos->WEST();        // Przemieszczenie sie do Pokoju.
            this->xpos = 67;                        // Odbicie gracza na druga strone pokoju.
            return 0;                               // Nothing to do, zero
        }
        if (this->xpos == 67){      // [→] Drzwi z PRAWEJ Strony
            roomPos = roomPos->EAST();              // Przemieszczenie sie do Pokoju.
            this->xpos = 2;                         // Odbicie gracza na druga strone pokoju.
            return 0;                               // Nothing to do, zero
        }
        // ------------------------------------------------------------
    }
    if (this->frontThing=='-'){     // Drzwi z Gory LUB Dolu
        // ------------------------------------------------------------
        this->roomPos->EditPX (xpos, ypos, ' ');    // Tam gdzie stal zostaje puste pole.

        if (this->ypos == 2){       // [↑] Drzwi u GORY Strony
            roomPos = roomPos->NORTH();             // Przemieszczenie sie do Pokoju.
            this->ypos = 33;                        // Odbicie gracza na druga strone pokoju.
            return 1;                               // Dodaj Pietro
        }
        if (this->ypos == 33){      // [↓] Drzwi z DOLU Strony
            roomPos = roomPos->SOUTH();             // Przemieszczenie sie do Pokoju.
            this->ypos = 2;                         // Odbicie gracza na druga strone pokoju.
            return 1;
        }
        // ------------------------------------------------------------
    }
    ///  ───-───-───-───-───--───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───
    return 0;   // Nothing to do, zero
}

void player::ShowGui(){
    /**

    */

    cout << "\n  room nr: " << roomPos->NR()  << "    ("
                            << roomPos->WID() << ","
                            << roomPos->LVL() << ")\n  "
                            << roomPos->b_north << "\n"
                            << roomPos->b_west << "   "
                            << roomPos->b_east << "\n  "
                            << roomPos->b_south;

}











