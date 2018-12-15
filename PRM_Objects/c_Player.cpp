
#include "c_Player"


int player::Move (Direction current){
    /** Metoda wpierw modyfikuje wyglad gracza, zmieniajac na jeden z [Animation Symbols / Char's]
        Natepnie wykonuje metode dziedziczonej klasy [Unit], w celu faktycznego przemieszczenia gracza.
    */

    /// Zmiana wygladu gracza
    if (current == UP)
        this->symbol = ((char)S_UP);        // [↑]

    if (current == DOWN)
        this->symbol = ((char)S_DOWN);      // [↓]

    if (current == LEFT)
        this->symbol = ((char)S_LEFT);      // [←]

    if (current == RIGHT)
        this->symbol = ((char)S_RIGHT);     // [→]

    /// Przemieszczenie gracza
    this->Unit::Move(current);
    return current;
}

