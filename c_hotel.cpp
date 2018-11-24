
#include "c_hotel"
//#include "c_room"


int hotel::RandomSet(int Rmin, int Rmax) {

        srand(time(NULL));

        int r = Rmax - Rmin;
        return (std::rand()%r )+ Rmin;
}

///Egzekucja Gryficy Gnildy


void hotel :: Ok_Path(int ile,int RoL){ ///[Grzybo]----- Metoda ktora tworzy wlasciwa siezke labiryntu, (bez slepyhc uliczek)

/// pierwszy argument odpowiada za to ile pokoi w bok idzie, chyba ze RoL jest 0 bo wtedy to nie ma znaczenia
/// czyli np.: jak ile = 3 to wiemy ze ostatni pokoj bd na wid = 3 lub -3


    room* LastRoom;  /// wedrowny wskaznik

    LastRoom = lastRoom; ///przekazanie do zmiennej wartosci z Heada




    room* tmp; /// wedrowny pokoj pomocniczy do tworzenia pokoiiiii

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1)); /// tu tworze pierwszy pokoj , zawcze jest jeden w gore wiec poza petla



    LastRoom = tmp;

    LastRoom->ShowALL(); // wyswietlenie pomocnicze

    lastRoom = LastRoom; //aktualizacja lastRoom z Head'a

    if(RoL != 0){



    if(RoL>0){ /// RoL od Right or Left, znak tej zminnej decyduje gdzie idzue labirynt, musialem to rozdzielic bo nie da sie w pentli wybierac czy lastroom idzie do westczy east
                /// za RoL mysle ze bd slurzyl x od switcha i scenariusz bd tak ze jak x>0 to w prawo (RandomSet)
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1,lastRoom->nr+1));///nowy pokoj z wid o jeden wiekszy bo w prawo
                LastRoom = tmp;

                LastRoom->ShowALL();
                lastRoom = LastRoom;

     }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,lastRoom->lvl,lastRoom->wid-1,lastRoom->nr+1)); ///nowy pokoj z wid o jeden mniejszy bo w lewo
                LastRoom = tmp;

                LastRoom->ShowALL();
                lastRoom = LastRoom;



    }

    }

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1));
///ostatni pokoj tez zawsze w gore wiec ten tez poza petla
    LastRoom = tmp;
    lastRoom = LastRoom;


    }

    lastRoom = LastRoom;
    currentRoom = tmp; /// w sumie currentRoom tutaj nie jest potrzebny ale poza metoda bedzie wiec A K T U A L I Z A C J A
                        ///tu akurat dla scenariusza 0 XD
    LastRoom->ShowALL();
}

///EGZEKUCJA GRYFICY GNILDY [KONIEC]






/// ProstowSciane

void hotel :: Blind_Path(int ile, int RoL){ /// tworzenie zaulkow slepych, mam w glowie tak ze najpierw jest tworzone to a potem wlasciwa scierzka
/// bo tu LastRoom nam sie nie zmienia po zakonczeniu pracy metody
/// ta metoda dziala bardzo podobnie do Ok_Path ale nie akualizuje lastRoom z Head'a

     room* LastRoom;

     LastRoom = lastRoom;

     room* tmp;

     tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1));
                LastRoom = tmp;

                lastRoom->nr = lastRoom->nr+1;

                LastRoom->ShowALL();

                lastRoom =LastRoom;


     if(RoL>0){
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1,lastRoom->nr+1));
                LastRoom = tmp;
                lastRoom->nr = lastRoom->nr+1;

                LastRoom->ShowALL();

    }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,LastRoom->lvl,LastRoom->wid-1,lastRoom->nr+1));
                LastRoom = tmp;
                lastRoom->nr = lastRoom->nr+1;

                LastRoom->ShowALL();

    }
    }

/// bo jak nie zwroce Last Rooma to na zewnatrz metody bd taki sam jak wczesniej, i tak ma byc, dlatego void :)
///PROSTOWSCIANE [KONIEC]
}



void hotel :: AddFloor (){///[GRZYBO] nowy pokoj, super metoda,uzywa i okPath i blindPath i Randoma

    int x;

    x = RandomSet(-8,8);

    cout<<x<<"\n";


    switch (x) {

        /// jeszce raz: pierwszy arg - ile w bok, drugi - na ktora strone idzie, lewo lub prawo

        case 0:
            Ok_Path(x,x); /// jeden w gore
            break;
        case 1:
            Ok_Path(1,x); /// up + prawko + up
           break;
        case -1:
            Ok_Path(1,x); /// up + lewo + up
            break;
        case 2:
            Ok_Path(2,x); /// up + dwa razy w prawo + up
            break;
        case -2:
            Ok_Path(2,x);  /// up + dwa razy w lewo + up                        /// JAKIE TO JEST KURWA DOOOOOOBRE!!!!!!
            break;                                                              ///KUTASY Z NIEBA LECA!!!!!!!!!
        case 3:
            Ok_Path(3,x); ///up + trzy razy prawo + up
            break;
        case -3:
            Ok_Path(3,x); ///up + trzy razy lewo + up
            break;
        case 4:
            Ok_Path(4,x); /// up + cztery razy prawo + up
            break;
        case -4:
            Ok_Path(4,x); /// up + cztery razy lewo  + up
            break;
        case 5:
            Blind_Path(1,1); ///jeden w gore - zaulek w prawo z obecnego
            Ok_Path(1,0);
            break;
        case -5:
            Blind_Path(1,-1); ///jeden w gore - zaulek w lewo  z obecnego
            Ok_Path(1,0);
            break;
        case 6:
            Blind_Path(1,1); /// up + dwa razy w prawo + up - zaulek w prawo  z obecnego
            Ok_Path(2,1);
            break;
        case -6:
            Blind_Path(1,-1); /// up + dwa razy w lewo + up - zaulek w lewo  z obecnego
            Ok_Path(2,-1);
            break;
         case 7:
            Blind_Path(1,1); /// up + dwa razy w lewo + up - zaulek w prawo z obecnego
            Ok_Path(2,-1);
            break;
        case -7:
            Blind_Path(1,-1); /// up + dwa razy w prawo + up - zaulek w lewo  z obecnego
            Ok_Path(2,1);
            break;
        case 8:
            Blind_Path(2,-1); /// up + dwa razy w prawo + up - zaulek w lewo x2 z obecnego
            Ok_Path(2,1);
            break;
        case -8:
            Blind_Path(2,1); /// up + dwa razy w lewo + up - zaulek w prawo x2  z obecnego
            Ok_Path(2,-1);
            break;

///na razie napisałem tyle ale moge jeszce duuuuuuuzo wiecej dodac dla urozmaicenia :]



    }
}





