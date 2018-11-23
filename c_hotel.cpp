
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




int hotel::RandomSet(int Rmin, int Rmax) {

        int r = Rmax - Rmin;
        srand(time(NULL));
        return std::rand()%r + Rmin;
}

///Egzekucja Gryficy Gnildy


void hotel :: Ok_Path(int ile,int RoL){ ///[Grzybo]----- Metoda ktora tworzy wlasciwa siezke labiryntu, (bez slepyhc uliczek)

    room* LastRoom;  /// wedrowny wskaznik

    LastRoom = lastRoom; ///przekazanie do zmiennej wartosci z Heada




    room* tmp; /// wedrowny pokoj pomocniczy do tworzenia pokoiiiii

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid)); /// tu tworze pierwszy pokoj , zawcze jest jeden w gore wiec poza petla

    LastRoom = tmp;

    LastRoom->ShowALL(); // wyswietlenie pomocnicze

    lastRoom = LastRoom; //aktualizacja lastRoom z Head'a

    if(RoL != 0){



    if(RoL>0){ /// RoL od Right or Left, znak tej zminnej decyduje gdzie idzue labirynt, musialem to rozdzielic bo nie da sie w pentli wybierac czy lastroom idzie do westczy east
                /// za RoL mysle ze bd slurzyl x od switcha i scenariusz bd tak ze jak x>0 to w prawo (RandomSet)
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1));///nowy pokoj z wid o jeden wiekszy bo w prawo
                LastRoom = tmp;
                LastRoom->ShowALL();
                lastRoom = LastRoom;
     }
    }

    if(RoL<0){

    for (int i=1;i<ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,lastRoom->lvl,lastRoom->wid-1)); ///nowy pokoj z wid o jeden mniejszy bo w lewo
                LastRoom = tmp;
                LastRoom->ShowALL();
                lastRoom = LastRoom;


    }

    }

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid));
///ostatni pokoj tez zawsze w gore wiec ten tez poza petla
    currentRoom = tmp;
    }


    currentRoom = tmp; /// w sumie currentRoom tutaj nie jest potrzebny ale poza metoda bedzie wiec A K T U A L I Z A C J A
                        ///tu akurat dla scenariusza 0 XD
    currentRoom->ShowALL();
}

///EGZEKUCJA GRYFICY GNILDY [KONIEC]

/// ProstowSciane

void hotel :: Blind_Path(int ile, int RoL){ /// tworzenie zaulkow slepych, mam w glowie tak ze najpierw jest tworzone to a potem wlasciwa scierzka
/// bo tu LastRoom nam sie nie zmienia po zakonczeniu pracy metody

     room* LastRoom;

     LastRoom = lastRoom;

     room* tmp;

     if(RoL>0){
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1));
                LastRoom = tmp;
                LastRoom->ShowALL();

    }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,LastRoom->lvl,LastRoom->wid-1));
                LastRoom = tmp;
                LastRoom->ShowALL();

    }
    }

/// i teraz dylemat mam ale mysle ze bd gitara
/// bo jak nie zwroce Last Rooma to na zewnatrz metody bd taki sam jak wczesniej, i tak ma byc, dlatego void :)
///PROSTOWSCIANE [KONIEC]
}



void hotel :: AddFloor (){///[GRZYBO] nowy pokoj, super metoda,uzywa i okPath i blindPath i Randoma

    int x ;
    x = RandomSet(-6,6);

    cout<<x<<"\n";


    switch (x) {

        case 0:
            Ok_Path(x,x);
            break;
        case 1:
            Ok_Path(1,x);
           break;
        case -1:
            Ok_Path(2,x);
            break;
        case 2:
            Ok_Path(2,x);
            break;
        case -2:
            Ok_Path(2,x); /// JAKIE TO JEST KURWA DOOOOOOBRE!!!!!!
            break;          ///KUTASY Z NIEBA LECA!!!!!!!!!
        case 3:
            Ok_Path(3,x);
            break;
        case -3:
            Ok_Path(3,x);
            break;
        case 4:
            Ok_Path(4,x);
            break;
        case -4:
            Ok_Path(4,x);
            break;
        case 5:
            Blind_Path(1,1);
            Ok_Path(1,0);
            break;
        case -5:
            Blind_Path(1,-1);
            Ok_Path(1,0);
            break;
        case 6:
            Blind_Path(1,1);
            Ok_Path(2,1);
            break;
        case -6:
            Blind_Path(1,-1);
            Ok_Path(2,-1);
            break;
///na razie napisałem tyle ale moge jeszce duuuuuuuzo wiecej dodac dla urozmaicenia :]



    }
}





