#include "c_maze"



// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
maze::maze() {
    this->veryFirstRoom = new NavRoom(NULL,NULL,NULL,0,0);
        // Przygotowanie Nowo Powstalego Pokoju.
        veryFirstRoom->SET_DOORS();
        veryFirstRoom->ClearRoom();
        veryFirstRoom->Danger(1,1,80,80,10);

    this->lastRoomAdded = veryFirstRoom;
    this->HERO.roomPos = this->veryFirstRoom;

    this->AddFloor();
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::AddRoom (Direction option, bool goInside=1){
    /** Dodaje nowe pokoje do [lastRoomAdded].
        Pokoje sa tworzone z pomoca tymczasowego wskaźnika.
        Po zakonczonej pracy moze wejsc do utworzonego pokoju.
    */

    NavRoom* tmp;

    switch (option){
    case UP:    // NavRoom( SOUTH  ,EAST,WEST,      lvl        ,      wid      )
        tmp = (new NavRoom(lastRoomAdded,NULL,NULL,lastRoomAdded->LVL()+1,lastRoomAdded->WID()));       // 1) Dodaj pokoj do gory od lastRoom.
        lastRoomAdded->SET_NORTH(tmp);                                                     // 2) Ustaw wszystkie wskazniki i inne wartosci nowego pokoju, oraz lastRoom.
        break;

    case LEFT:  // NavRoom(SOUTH,EAST   ,WEST,      lvl      ,      wid        )
        tmp = (new NavRoom(NULL,lastRoomAdded,NULL,lastRoomAdded->LVL(),lastRoomAdded->WID()-1));
        lastRoomAdded->SET_WEST(tmp);
        break;

    case RIGHT: // NavRoom(SOUTH,EAST, WEST  ,      lvl      ,      wid        )
        tmp = (new NavRoom(NULL,NULL,lastRoomAdded,lastRoomAdded->LVL(),lastRoomAdded->WID()+1));
        lastRoomAdded->SET_EAST(tmp);
        break;

    case DOWN:
        // Need To Define Every Option
        break;
    }

    /// PART 2
    if (goInside){
        lastRoomAdded = tmp; // wejdz do pokoju = ustaw lastRoomAdded na nowy pokoj.
    }
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::ShowMaze (){

    NavRoom* CurrentRoom;   // Starts with last added room on the top. Then he walks down.
    NavRoom* tmp;
    int w = 0;
    int e = 0;

    CurrentRoom = this->veryFirstRoom;

    while (CurrentRoom != lastRoomAdded ) { // Biggest Loop, As long as there is any room left.
        cout << "Floor:[" << CurrentRoom->LVL()
             << "]============== --------------------------"
             << "---------------------------------------------------------\n";
//        cout<<"START\n ";
//        cout<<"curr : ";
//        CurrentRoom->DEBUG_ALLVARS();
        tmp = CurrentRoom;
        if (CurrentRoom->NORTH() != NULL) {
//            cout<<"1 :";
            CurrentRoom->DEBUG_ALLVARS();

            while ( CurrentRoom->EAST() != NULL ) {
                CurrentRoom = CurrentRoom->EAST();
                CurrentRoom->DEBUG_ALLVARS();
//                cout<<"666";
            }
            CurrentRoom = tmp;

            while ( CurrentRoom->WEST() != NULL ) {
                CurrentRoom = CurrentRoom->WEST();
                CurrentRoom->DEBUG_ALLVARS();
//                cout<<"555";
            }
            CurrentRoom = tmp;
            CurrentRoom = CurrentRoom->NORTH();

        } else {
//            cout<<"2 \n";
            tmp = CurrentRoom;
            CurrentRoom->DEBUG_ALLVARS();

            while ( CurrentRoom->EAST() != NULL ) {
//                cout<<"444";
                CurrentRoom = CurrentRoom->EAST();
                CurrentRoom->DEBUG_ALLVARS();
                if (CurrentRoom->NORTH() != NULL) {
                    e = e+1;
                }
            }
            CurrentRoom = tmp;


            while ( CurrentRoom->WEST() != NULL ) {
//                cout<<"333";
                CurrentRoom = CurrentRoom->WEST();
                CurrentRoom->DEBUG_ALLVARS();
                if (CurrentRoom->NORTH() != NULL) {
                    w = w+1;
                }
            }
            CurrentRoom = tmp;

            if (e>w) {
                while ( CurrentRoom->NORTH() == NULL ) {
                    CurrentRoom = CurrentRoom->EAST();
                }
                CurrentRoom = CurrentRoom->NORTH();
//                cout<<"222";
            }

            if (e<w){
                while ( CurrentRoom->NORTH() == NULL ) {
                    CurrentRoom = CurrentRoom->WEST();
                }
                CurrentRoom = CurrentRoom->NORTH();
//                cout<<"111";
            }
        }
//        cout<<"KONIEC\n";
    }
//    cout<<"**********";
    cout << "Floor:[" << CurrentRoom->LVL()
         << "]============== --------------------------"
         << "---------------------------------------------------------\n";
    lastRoomAdded->DEBUG_ALLVARS();
}



// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void recur_UpdateFloor (Direction dir, NavRoom* tmproom){
    /** Rekurencyjna SubFunkcja metody maze::UpdateLastFloor.
        Pozawala na wedrowanie po pietrze z uwzglednieniem zaulkow.
    */
    // Pojawilismy sie w tym pokoju, posprzatajmy.
    tmproom->SET_DOORS();
    tmproom->ClearRoom();

    if (dir == LEFT) // Przybylismy z pokoju po PRAWEJ
        if (tmproom->WEST() != NULL) // Zobaczmy czy mozemy isc dalej w LEWO.
            recur_UpdateFloor (LEFT, tmproom->WEST());  // SKORO TAK, Idziemy dalej w LEWO

    if (dir == RIGHT) // Przybylismy z pokoju po LEWEJ
        if (tmproom->EAST() != NULL) // Zobaczmy czy mozemy isc dalej w PRAWO.
            recur_UpdateFloor (RIGHT, tmproom->EAST()); // SKORO TAK, Idziemy dalej w PRAWO

}    // Dalej nie mozemy wedrowac, to koniec.

void maze::UpdateLastFloor(){
    /** Naprawia ostatnie, dodane pietro */

    // Zaczyna od lastRoomAdded, czysci go.
    // Wedruje przez cale pietro ponizej lastRoomAdded.
    NavRoom* tmpRoom = this->lastRoomAdded;

    // Czyszczenie last room:
    tmpRoom->SET_DOORS();
    tmpRoom->ClearRoom();

    if (tmpRoom->SOUTH() != NULL){ // Ide poziom nizej, O ile moge.
        tmpRoom = tmpRoom->SOUTH();
        // Czyszczenie
        tmpRoom->SET_DOORS();
        tmpRoom->ClearRoom();
    }else{ return; }

    if (tmpRoom->WEST() != NULL){ // Zobaczmy czy mozemy isc w LEWO.
        /** SKORO TAK, Idziemy w LEWO **/
        recur_UpdateFloor (LEFT, tmpRoom->WEST());
    }   // Cala Galaz po LEWEJ zalatwiona.

    if (tmpRoom->EAST() != NULL){ // Zobaczmy czy mozemy isc dalej w PRAWO.
        /** SKORO TAK, Idziemy w PRAWO **/
        recur_UpdateFloor (RIGHT, tmpRoom->EAST());
    }   // Cala Galaz po PRAWEJ zalatwiona.
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::AddFloor(){
    /** Losuje Scenariusz,
        generuje jedno cale pietro,
        naprawia rozmieszczenie drzwi.
    */
    NavRoom* tmpRoom;           // potrzebny do dodawania zaulkow.
    int x = RandomSet(-8,8);

    switch (x) {
    case 0:
        AddRoom(UP);                /// jeden w gore
        break;
    case 1:
        AddRoom(RIGHT);             /// up + prawko
        AddRoom(UP);
       break;
    case -1:
        AddRoom(LEFT);              /// up + lewo + up
        AddRoom(UP);
        break;
    case 2:
        AddRoom(RIGHT);
        AddRoom(RIGHT);             /// up + dwa razy w prawo
        AddRoom(UP);
        break;
    case -2:
        AddRoom(LEFT);
        AddRoom(LEFT);              /// up + dwa razy w lewo
        AddRoom(UP);
        break;
    case 3:
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(UP);                /// trzy razy prawo + up
        break;
    case -3:
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(UP);                ///trzy razy lewo + up
        break;
    case 4:
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(UP);                ///  cztery razy prawo + up
        break;
    case -4:
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(UP);                ///  cztery razy lewo  + up
        break;
    case 5:
        AddRoom(RIGHT,0);
        AddRoom(UP);                ///jeden w gore - zaulek w prawo z obecnego
        break;
    case -5:
        AddRoom(LEFT,0);
        AddRoom(UP);                 ///jeden w gore - zaulek w lewo  z obecnego
        break;
    case 6:
        AddRoom(LEFT,0);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(UP);                /// zaulek w lewo + prawo 2x + up
        break;
    case -6:
        AddRoom(RIGHT,0);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(UP);                /// zaulek w prawo+ lewo 2x + up
        break;
     case 7:
        AddRoom(LEFT,0);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(UP);                /// zaulek w lewo + prawo 3x + up
        break;
    case -7:
        AddRoom(RIGHT,0);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(UP);                /// zaulek w prawo+ lewo 3x + up
        break;
    case 8:
        tmpRoom = lastRoomAdded;
        AddRoom(LEFT);
        AddRoom(LEFT);
        lastRoomAdded = tmpRoom;

        AddRoom(RIGHT);
        AddRoom(RIGHT);
        AddRoom(UP);                /// zaulek w lewo 2x + prawo 2x + up
        break;
    case -8:
        tmpRoom = lastRoomAdded;
        AddRoom(RIGHT);
        AddRoom(RIGHT);
        lastRoomAdded = tmpRoom;

        AddRoom(LEFT);
        AddRoom(LEFT);
        AddRoom(UP);                /// zaulek w prawo 2x + lewo 2x + up
        break;
    }

    // Napraw nie ustawione drzwi.
    UpdateLastFloor();
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
int maze::RandomSet(int Rmin, int Rmax){
    /** Losowanie scenariusza na dodawanie pokoju do pietra **/

    srand(time(NULL));

    int r = Rmax - Rmin;
    return (std::rand()%r )+ Rmin;
}

