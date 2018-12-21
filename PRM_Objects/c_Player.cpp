
#include "c_Player"


int player::Move (Direction current){
    /** Metoda wpierw modyfikuje wyglad gracza, zmieniajac na jeden z [Animation Symbols / Char's]
        Natepnie wykonuje metode dziedziczonej klasy [Unit], w celu faktycznego przemieszczenia gracza.
    */

    // ------------------------------------------------------------
    /// Przemieszczenie Gracza
    this->Unit::Move(current);

    // ------------------------------------------------------------
    /// Zmiana wygladu Gracza
    if (current == UP)      this->symbol = ((char)S_UP);        // [↑]
    if (current == DOWN)    this->symbol = ((char)S_DOWN);      // [↓]
    if (current == LEFT)    this->symbol = ((char)S_LEFT);      // [←]
    if (current == RIGHT)   this->symbol = ((char)S_RIGHT);     // [→]

    this->roomPos->EditPX (xpos, ypos, symbol);     // Zmien wyglad Gracza.
    return current;
}

void player::Action (){
    /** Metoda wywolywana w Inpucie, dla klawisza [ENTER] [E] [e] */

    if (this->frontThing=='|'){      // Drzwi z Lewej LUB Prawej Strony
        // ------------------------------------------------------------
        if (this->symbol==(char)S_LEFT)         // [←] Drzwi z LEWEJ Strony
//            this->roomPos = roomPos->WEST();
            roomPos->SET_NORTH(this->roomPos);

        if (this->symbol==(char)S_RIGHT)        // [→] Drzwi z PRAWEJ Strony
            roomPos = roomPos->EAST();

        // ------------------------------------------------------------
    }
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











