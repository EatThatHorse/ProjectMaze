
#include "c_Player"

#include <iostream>

int player::Move (Direction current){
    /** Metoda wpierw modyfikuje wyglad gracza, zmieniajac na jeden z [Animation Symbols / Char's]
        Natepnie wykonuje metode dziedziczonej klasy [Unit], w celu faktycznego przemieszczenia gracza.
    */

    // ------------------------------------------------------------
    /// Przemieszczenie Gracza
    this->Unit::Move(current);

    std::cout << xpos << "      " << ypos << "      [" << this->frontThing << "]";


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

    /// NATRAFILISMY NA DRZWI ───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───
    if (this->frontThing=='|'){     // Drzwi z Lewej LUB Prawej Strony
        // ------------------------------------------------------------
        if (this->xpos == 2){       // [←] Drzwi z LEWEJ Strony
            this->roomPos = roomPos->WEST();    // Przemieszczenie sie do Pokoju.
            this->xpos = 67;                    // Odbicie gracza na druga strone pokoju.
            return;
        }
        if (this->xpos == 67){      // [→] Drzwi z PRAWEJ Strony
            roomPos = roomPos->EAST();  // Przemieszczenie sie do Pokoju.
            this->xpos = 2;             // Odbicie gracza na druga strone pokoju.
            return;
        }
        // ------------------------------------------------------------
    }
    if (this->frontThing=='-'){     // Drzwi z Gory LUB Dolu
        // ------------------------------------------------------------
        if (this->ypos == 2){       // [↑] Drzwi u GORY Strony
            roomPos = roomPos->NORTH(); // Przemieszczenie sie do Pokoju.
            this->ypos = 33;            // Odbicie gracza na druga strone pokoju.
            return;
        }
        if (this->ypos == 33){      // [↓] Drzwi z DOLU Strony
            roomPos = roomPos->SOUTH(); // Przemieszczenie sie do Pokoju.
            this->ypos = 2;             // Odbicie gracza na druga strone pokoju.
            return;
        }
        // ------------------------------------------------------------
    }
    ///  ───-───-───-───-───--───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───-───
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











