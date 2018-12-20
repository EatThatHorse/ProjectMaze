#include "c_maze"



// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
maze::maze(){
    this->zeroRoom = new NavRoom(NULL,NULL,NULL,0,0);

    this->lastRoomAdded = zeroRoom;
    this->currentRoom = zeroRoom;
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::SET_CURR(NavRoom* newAdres){

    this->currentRoom = newAdres;
}
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
NavRoom* maze::LAST_ROOM_ADDED(){
    return this->lastRoomAdded;
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::AddRoom (Direction option, bool goInside=1){
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

    room* CurrentRoom;
    room* tmp;
    int w = 0;
    int e = 0;

    CurrentRoom = this->currentRoom;

    while (CurrentRoom != lastRoomAdded ) {
//        cout<<"START\n ";
//        cout<<"curr : ";
//        CurrentRoom->DEBUG_SHOWVARS();
        tmp = CurrentRoom;
        if (CurrentRoom->NORTH() != NULL) {
//            cout<<"1 :";
            CurrentRoom->DEBUG_SHOWVARS();

            while ( CurrentRoom->EAST() != NULL ) {
                CurrentRoom = CurrentRoom->EAST();
                CurrentRoom->DEBUG_SHOWVARS();
//                cout<<"666";
            }
            CurrentRoom = tmp;

            while ( CurrentRoom->WEST() != NULL ) {
                CurrentRoom = CurrentRoom->WEST();
                CurrentRoom->DEBUG_SHOWVARS();
//                cout<<"555";
            }

            CurrentRoom = tmp;
            CurrentRoom = CurrentRoom->NORTH();
        } else {
//            cout<<"2 \n";
            tmp = CurrentRoom;
            CurrentRoom->DEBUG_SHOWVARS();

            while ( CurrentRoom->EAST() != NULL ) {
//                cout<<"444";
                CurrentRoom = CurrentRoom->EAST();
                CurrentRoom->DEBUG_SHOWVARS();
                if (CurrentRoom->NORTH() != NULL) {
                    e = e+1;
                }
            }
            CurrentRoom = tmp;


            while ( CurrentRoom->WEST() != NULL ) {
//                cout<<"333";
                CurrentRoom = CurrentRoom->WEST();
                CurrentRoom->DEBUG_SHOWVARS();
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
    lastRoomAdded->DEBUG_SHOWVARS();
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
void maze::AddFloor(){

    Droom* tmpRoom;

    int x;

    x = RandomSet(-8,8);

    switch (x) {

        case 0:
            AddRoom(UP); /// jeden w gore
            break;
        case 1:
            AddRoom(RIGHT); /// up + prawko
            AddRoom(UP);
           break;
        case -1:
            AddRoom(LEFT); /// up + lewo + up
            AddRoom(UP);
            break;
        case 2:
            AddRoom(RIGHT);
            AddRoom(RIGHT); /// up + dwa razy w prawo
            AddRoom(UP);
            break;
        case -2:
            AddRoom(LEFT);
            AddRoom(LEFT);  /// up + dwa razy w lewo
            AddRoom(UP);
            break;
        case 3:
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);  /// trzy razy prawo + up
            break;
        case -3:
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);  ///trzy razy lewo + up
            break;
        case 4:
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);///  cztery razy prawo + up
            break;
        case -4:
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);            ///  cztery razy lewo  + up
            break;
        case 5:
            AddRoom(RIGHT,0);
            AddRoom(UP);              ///jeden w gore - zaulek w prawo z obecnego
            break;
        case -5:
            AddRoom(LEFT,0);
            AddRoom(UP);             ///jeden w gore - zaulek w lewo  z obecnego
            break;
        case 6:
            AddRoom(LEFT,0);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);                     /// zaulek w lewo + prawo 2x + up
            break;
        case -6:
            AddRoom(RIGHT,0);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);                     /// zaulek w prawo+ lewo 2x + up
            break;
         case 7:
            AddRoom(LEFT,0);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);                     /// zaulek w lewo + prawo 3x + up
            break;
        case -7:
            AddRoom(RIGHT,0);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);                     /// zaulek w prawo+ lewo 3x + up
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
}

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
int maze::RandomSet(int Rmin, int Rmax){

    srand(time(NULL));

    int r = Rmax - Rmin;
    return (std::rand()%r )+ Rmin;
}

