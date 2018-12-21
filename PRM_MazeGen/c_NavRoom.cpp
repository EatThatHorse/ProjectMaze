
#include "c_NavRoom"

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■

int NavRoom::iloscPokoi = 0; //statyczna zmienna globalna

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
NavRoom::NavRoom(NavRoom* t_south, NavRoom* t_east, NavRoom* t_west, int t_lvl, int t_wid){

    ++iloscPokoi;

    this->north = NULL;
    this->south = t_south;
    this->east = t_east;
    this->west = t_west;
    this->lvl = t_lvl;
    this->wid = t_wid;
    this->nr = iloscPokoi;

    if (t_south != NULL)
        t_south->north = this;

}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
NavRoom::~NavRoom (){
    --iloscPokoi;
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■

int NavRoom::LVL(){ return this->lvl; }
int NavRoom::WID(){ return this->wid; }
int NavRoom::NR(){ return this->nr; }

NavRoom* NavRoom::NORTH(){ return this->north; }
NavRoom* NavRoom::EAST(){ return this->east; }
NavRoom* NavRoom::SOUTH(){ return this->south; }
NavRoom* NavRoom::WEST(){ return this->west;
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void NavRoom::SET_NORTH(NavRoom* roomX){
    this->north = roomX;
}

void NavRoom::SET_EAST(NavRoom* roomX){
    this->east = roomX;
}

void NavRoom::SET_WEST(NavRoom* roomX){
    this->west = roomX;
}

void NavRoom::SET_DOORS(){
    this->b_south = (this->south!=NULL)?  1 : 0;
    this->b_west =  (this->east!=NULL)?   1 : 0;
    this->b_east =  (this->west!=NULL)?   1 : 0;

}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
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
