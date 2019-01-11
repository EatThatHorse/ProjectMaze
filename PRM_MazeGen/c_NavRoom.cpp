
#include "c_NavRoom"



int NavRoom::iloscPokoi = 0; //statyczna zmienna globalna




// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
//     KONSTRUKTORY / DESTRUKTORY       KONSTRUKTORY / DESTRUKTORY       KONSTRUKTORY / DESTRUKTORY       KONSTRUKTORY / DESTRUKTORY
NavRoom::NavRoom (NavRoom* t_south, NavRoom* t_east, NavRoom* t_west, int t_lvl, int t_wid)
        :RoomContainer(t_lvl, t_wid, (iloscPokoi+1))   {
    /** Tworzenie nowego pokoju.
        Ustawianie wskaznikow.
        Ustawiene koordynatow pokoju.
        Pomijamy boole drzwi poniewaz
        nie bylyby aktualne z tego poziomu = errory.
    **/
    ++iloscPokoi;               // Zwiekszamy ilosc wszystkich pokoi o jeden.

    // Ustawienie koordynatow:
    this->lvl = t_lvl;          // Wysokosc         [0,+oo)
    this->wid = t_wid;          // Szerokosc        (-oo,+oo)
    this->nr = iloscPokoi;      // Ktory to pokoj   [1,+oo)

    // Ustawienie wskaznikow:
    this->north = NULL;         // Dodajemy nowy pokoj, Nie istnieje zaden wyzej
    this->south = t_south;
    this->east = t_east;
    this->west = t_west;

    // Ustawienie wskaznika poprzedniego pokoju:
    if (t_south != NULL)        // Sprawdzamy czy jest to pierwszy dodany pokoj
        t_south->north = this;  // Nie jest, wiec ustawiamy wskaznik poprzedniego pokoju na nas.

}
NavRoom::~NavRoom (){
    /** Sprzatanie po skasowanym pokoju.
        Zerowanie Wskaznikow sasiadujacych pokoi.
        Update Bool'i drzwi sasiadujacych pokoi.
        Kasowanie Naszych Wskaznikow.

        Destruktor pozwala na Kasowanie Wszystkich Pokoi.
        Moze to doprowadzic do przerwania ciaglosci Maze'a
        W efekcie: Dwa nie polaczone subMaze'y
        Destruktor NIE ostrzega przed taka ewentualnoscia
    **/
    --iloscPokoi;                   // Zmniejszamy ilosc wszystkich pokoi o jeden.

    // Ustawienie sasiadujacych pokoi:
    if (this->north != NULL) {      // czy jest pokoj nad nami?
        /// TAK
        this->north->b_south = 0;   // Zamkniecie Jego drzwi do nas
        this->north->south = NULL;  // Wymazujemy Nas z jego pamieci.
    }
    if (this->south != NULL) {      // czy jest pokoj pod nami?
        this->south->b_north = 0;
        this->south->north = NULL;
    }
    if (this->west != NULL) {       // czy jest pokoj z lewej?
        this->west->b_east = 0;
        this->west->east = NULL;
    }
    if (this->east != NULL) {       // czy jest pokoj z prawej?
        this->east->b_west = 0;
        this->east->west = NULL;
    }

    // Kasowanie naszych wskaznikow:
    delete this->north;
    delete this->south;
    delete this->west;
    delete this->east;
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
//      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY      GETERY
int NavRoom::LVL(){ return this->lvl; }
int NavRoom::WID(){ return this->wid; }
int NavRoom::NR(){ return this->nr; }

NavRoom* NavRoom::NORTH(){ return this->north; }
NavRoom* NavRoom::EAST(){ return this->east; }
NavRoom* NavRoom::SOUTH(){ return this->south; }
NavRoom* NavRoom::WEST(){ return this->west; }

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
//      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY      SETERY
void NavRoom::SET_NORTH(NavRoom* roomX){ this->north = roomX; }
void NavRoom::SET_EAST(NavRoom* roomX){ this->east = roomX; }
void NavRoom::SET_WEST(NavRoom* roomX){ this->west = roomX; }

void NavRoom::SET_DOORS(){
    /** Ustawienie booli rysowania drzwi **/
    this->b_north = (this->north!=NULL)?  1 : 0;
    this->b_south = (this->south!=NULL)?  1 : 0;
    this->b_west =  (this->west!=NULL)?   1 : 0;
    this->b_east =  (this->east!=NULL)?   1 : 0;
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
//      DEBUG / CONSOLE      DEBUG / CONSOLE      DEBUG / CONSOLE      DEBUG / CONSOLE      DEBUG / CONSOLE      DEBUG / CONSOLE
void NavRoom::DEBUG_ALLVARS(){
    cout <<(char)254
         << " lvl: "            << this->lvl
         << " wid: "            << this->wid
         << " nr: "             << this->nr
         << "\t\tthis: ["       << this
         << "] N: ["        << this->north
         << "] S: ["        << this->south
         << "] E:  ["        << this->east
         << "] W:  ["        << this->west
         << "]\n";
}
void NavRoom::DEBUG_VARS(){
    cout << " [nr:"        << this->lvl
         << " pos:(" << this->lvl << "," << this->wid << ")]";
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■




