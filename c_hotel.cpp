
#include "c_hotel"
//#include "c_room"

 /*hotel MakeHotel(room* pok1, room* pok2, room* pok3, room* pok4, room* pok5,room* pok6){
            hotel h;
            h.r1 = pok1;
            h.r2 = pok2;
            h.r3 = pok3;
            h.r4 = pok4;
            h.r5 = pok5;
            h.r6 = pok6;
            return h;
       }


*/
/*hotel hotel::SetRoom(room tmpRoom){ /// tworzenie nowych roomow, losowanie jakich i ilu, argumenty to obecny pokoj, zwraca pudelo z pokojami w srodku



        srand(time(NULL));
        int x = std::rand()%13 -6;

        if (x==0) {
            hotel h;
            room room0;
            room0.MakeRoom(tmpRoom.lvl + 1,tmpRoom.wid,NULL,NULL,tmpRoom.Me,NULL);
//            h.MakeHotel(&room0,NULL,NULL,NULL,NULL,NULL);
            return h;
        }
        if(x==1) {
            hotel h;
            room room0;
            room room1;
            room0.MakeRoom(tmpRoom.lvl,tmpRoom.wid + 1,NULL,NULL,NULL,tmpRoom.Me);
            room1.MakeRoom(tmpRoom.lvl + 1,tmpRoom.wid + 1,NULL,NULL,room0.Me,NULL);
//            h.MakeHotel(&room0,&room1);
            return h;
            }
      /*  if (x==2) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 2,NULL,NULL,room1.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2);
            return h;
        }
        if (x==3) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room1 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room1.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2);
            return h;
        }
        if (x==4) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room1 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room1.Me);
            room room3 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room2.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3);
            return h;

        }
        if (x==5) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room0.Me,NULL);
            room room2 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room3 = MakeRoom(room.lvl,room.wid - 2,NULL,room2.Me,NULL,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3);
            return h;

        }
        if (x==6) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 2,NULL,NULL,room1.Me,NULL);
            room room3 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room4 = MakeRoom(room.lvl,room.wid - 2,NULL,room3.Me,NULL,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3,&room4);
            return h;

        }
        if (x==-1) {

        }
        if (x==-2) {

        }
        if (x==-3) {

        }
        if (x==-4) {

        }
        if (x==-5) {

        }
        if (x==-6) {

    }    }
        */


void hotel::PrintHotel(){ ///[GRZYBO] wypisywanie za hotelu

        r1->PrintRoom();
        r2->PrintRoom();
        r3->PrintRoom();
        r4->PrintRoom();
        r5->PrintRoom();
        r6->PrintRoom();
}

int RandomSet(int Rmin, int Rmax) {

        int r = Rmax - Rmin;
        srand(time(NULL));
        return std::rand()%r + Rmin;
}

///Egzekucja Gryficy Gnildy
///[Grzybo]----- Metoda ktora tworzy wlasciwa siezke labiryntu, (bez slepyhc uliczek)

room* Path(hotel& HeadHotel,int ile,int RoL){


    room* LastRoom = &HeadHotel.lastRoom; /// wedrowny wskaznik

    room* tmp; /// wedrowny pokoj pomocniczy do tworzenia pokoiiiii

    tmp = (new room(LastRoom,NULL,NULL,LastRoom.lvl+1,LastRoom.wid)); /// tu tworze pierwszy pokoj , zawcze jest jeden w gore wiec poza petla

    LastRoom = tmp;

    if(RoL>0){ /// RoL od Right or Left, znak tej zminnej decyduje gdzie idzue labirynt, musialem to rozdzielic bo nie da sie w pentli wybierac czy lastroom idzie do westczy east
                /// za RoL mysle ze bd slurzyl x od switcha i scenariusz bd tak ze jak x>0 to w prawo (RandomSet)
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom.lvl,LastRoom.wid+1));///nowy pokoj z wid o jeden wiekszy bo w prawo
                LastRoom = tmp;
    }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,LastRoom.lvl,LastRoom.wid-1)); ///nowy pokoj z wid o jeden mniejszy bo w lewo
                LastRoom = tmp;
    }
    }

    tmp = (new room(LastRoom,NULL,NULL,LastRoom.lvl+1,LastRoom.wid));
///ostatni pokoj tez zawsze w gore wiec ten tez poza petla
    LastRoom = tmp;



    return LastRoom; ///zwracamy lastroom ¿eby wiadomobylo o co chodzi, gdzie jestesmy, i dokonddd zmierzamy




}

///EGZEKUCJA GRYFICY GNILDY [KONIEC]

/// ProstowSciane

void Blind(hotel& HeadHotel,int ile, int RoL){ /// tworzenie zaulkow slepych, mam w glowie tak ze najpierw jest tworzone to a potem wlasciwa scierzka
/// bo tu LastRoom nam sie nie zmienia po zakonczeniu pracy metody
     room* LastRoom = &HeadHotel.lastRoom;
     room* tmp;

     if(RoL>0){
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom.lvl,LastRoom.wid+i));
                LastRoom = tmp;
    }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){
LastRoom = tmp;
                tmp = (new room(NULL,LastRoom,NULL,LastRoom.lvl,LastRoom.wid-i));
                LastRoom = tmp;
    }
    }

/// i teraz dylemat mam ale mysle ze bd gitara
/// bo jak nie zwroce Last Rooma to na zewnatrz metody bd taki sam jak wczesniej, i tak ma byc, dlatego void :)
///PROSTOWSCIANE [KONIEC]
}


void AddFloor (hotel& HeadHotel,int x){///nowy pokoj z wid o jeden wiekszy bo w prawo



    switch (x) {

        case 0:
        room room0(LastRoom,LastRoom.lvl+1,LastRoom.wid);

        HeadHotel.lastRoom->north = &newRoom;
        HeadHotel.lastRoom = &newRoom;

        break;

        case 1:
        room newRoom0;
        room newRoom1;

        HeadHotel.lastRoom->north = &newRoom0;
        newRoom0.east->west = &newRoom1;

        break;


    }


}


