
#include "c_hotel"
//#include "c_room"





int hotel::RandomSet(int Rmin, int Rmax) {

        srand(time(NULL));

        int r = Rmax - Rmin;
        return (std::rand()%r )+ Rmin;
}

///Egzekucja Gryficy Gnildy






// ░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░░▒▓▓▒░
// TUATJ JESTEM! NOWE INSTRUKCJE!  :D
/** Dobrze bedzie napisac metode AddRoom. Bedzie to metoda klasy hotel.
    Abys sie nie narobil, oraz aby zrobic to jeszcze ladniej! Napisalem ci globalny Enumerator:

        enum nazwaEnuma { lista wyliczeniowa };     // Szablon
        enum roomDirection { LEFT, RIGHT, UP };     // znajduje sie w c_hotel linijka [11]

    Enumerator, podobnie jak int'y lub char'y, jest TYPEM danych.
    Enum ode mnie posiada 3 wartosci, { LEFT, RIGHT, UP }. Uzyjesz ich w nowym switch case.
    Dzialanie nowej metody:
    - W zaleznosci od opcji podanej w argumencie, utworzy jeden pokoj do gory, lub w lewo, lub w prawo.
    - W zaleznosci od drugiej opcji podanej w argumencie, wejdzie albo nie wejdzie do nowo utworzonego pokoju.
      Czyli ustawi, albo nie ustawi wskaznika hotelu lastRoom.
    Metoda wyglada tak:    [Mozesz skopiowac]
        void hotel::AddRoom (roomDirection option, bool goInside=1){
            /// PART 1
            switch (option){
            case UP:
                // 1) Dodaj pokoj do gory od lastRoom.
                // 2) Ustaw wszystkie wskazniki i inne wartosci nowego pokoju, oraz lastRoom.
                break;

            // 3) Wykonaj to samo dla pozostalych opcji:
            case LEFT:
                // Dodawanie pokoju na lewo od lastRoom.
                break;

            case RIGHT:
                // Dodawanie pokoju na prawo od lastRoom.
                break;
            }

            /// PART 2
            if (goInside){
                // wejdz do pokoju = ustaw lastRoom na nowy pokoj.
            }
        }
    Switch case zostal napisany tak by dzialal bez dodatkowych modyfikacji.
    Przyklad Metody AddFloor z uzyciem nowej metody.
        // NOPE:
        case 3:
            Ok_Path(3,x); /// up + trzy razy prawo + up
            break;
            // Rezygnujemy z jednego up. Dowolnie, pierwszego lub tego na koncu.
            // Jedno nowe pietro = jeden up.
            // Inaczej co każdy poziom (bardzo często) będziemy przemieszczali się dwa razy do gory.

        // YAS:
        case 3:     /// trzy razy prawo + up
            AddRoom(RIGHT);     // domyslnie bool goInside jest rowny 1. Wiec wchodzimy do srodka.
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);
            break;

        case 7:     /// [zaulek w prawo]  dwa razy w lewo + up
            AddRoom(RIGHT, 0);  // goInside jest rowny 0. Nie wchodzimy do srodka. Pozostajemy Tam gdzie stalismy.
            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);
            break;

        case 8:     /// [zaulek w lewo x2]  dwa razy w prawo + up
            // Ten przypadek jest nieco tricky. Bo aby dodac drugi zaulek trzeba wejsc do pierwszego zaulka.

            room* tmpRoom = lastRoom;   // tmpRoom bedzie trzymal pozycje miejsca w ktorym stoimy na poczatku case'a.
            AddRoom(LEFT);          // tworzymy dwa zaulki w lewo. Do pierwszego musimy wejsc aby nastepnie zrobic drugi.
            AddRoom(LEFT);          // Do drugiego dowolnie. Mozemy wejsc, nie musimy. BO:
            lastRoom = tmpRoom;     // Przenosimy sie, wracamy do pokoju z ktorego zaczelismy, aby teraz moc isc w [dwa razy w prawo + up]

            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);
            break;

    Ten sam sposob pozwoli nam dodac i 3 i 4 zaulki w lewo i w prawo i wgl.
    5min na zrobienie 26 scenariuszy. Labirynt o 5 poziomach to 26^5 losowych rozgrywek.[ 26^5 = 11 881 376 ]
    Nie wiem jaki wyjdzie nam poziom trudnosci. Celuje aby srednia rozgrywka trwala miedzy 20 a 50 poziomow.
    Tak sie robi mapy do gier!!!   xD, jaram sie.
    Dodatkowo kazdy pokoj bedzie mial inne wyposazenie/przeciwnikow/rzeczy w srodku. (dzialka mikolaja)
    GOTOWE - hehe  :D
*/

 void hotel::AddRoom (roomDirection option, bool goInside=1){
    room* tmp;

    switch (option){
    case UP:
        tmp = (new room(lastRoom,NULL,NULL,lastRoom->lvl+1,lastRoom->wid));        // 1) Dodaj pokoj do gory od lastRoom.
        lastRoom->north = tmp;                                                     // 2) Ustaw wszystkie wskazniki i inne wartosci nowego pokoju, oraz lastRoom.
        break;

    case LEFT:
        tmp = (new room(NULL,lastRoom,NULL,lastRoom->lvl,lastRoom->wid-1));
        lastRoom->west = tmp;
        break;

    case RIGHT:
        tmp = (new room(NULL,NULL,lastRoom,lastRoom->lvl,lastRoom->wid+1));
        lastRoom->east = tmp;
        break;
    }

    /// PART 2
    if (goInside){
        lastRoom = tmp;
        // wejdz do pokoju = ustaw lastRoom na nowy pokoj.
    }
}









void hotel::Ok_Path(int ile,int RoL){ ///[Grzybo]----- Metoda ktora tworzy wlasciwa siezke labiryntu, (bez slepyhc uliczek)

/// pierwszy argument odpowiada za to ile pokoi w bok idzie, chyba ze RoL jest 0 bo wtedy to nie ma znaczenia
/// czyli np.: jak ile = 3 to wiemy ze ostatni pokoj bd na wid = 3 lub -3


    room* LastRoom;  /// wedrowny wskaznik

    LastRoom = lastRoom; ///przekazanie do zmiennej wartosci z Heada




    room* tmp; /// wedrowny pokoj pomocniczy do tworzenia pokoiiiii

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1)); /// tu tworze pierwszy pokoj , zawcze jest jeden w gore wiec poza petla

    LastRoom->north = tmp;
  //LastRoom->ShowALL();

    LastRoom = tmp;

 //  LastRoom->ShowALL(); // wyswietlenie pomocnicze

    lastRoom = LastRoom; //aktualizacja lastRoom z Head'a

    if(RoL != 0){



    if(RoL>0){ /// RoL od Right or Left, znak tej zminnej decyduje gdzie idzue labirynt, musialem to rozdzielic bo nie da sie w pentli wybierac czy lastroom idzie do westczy east
                /// za RoL mysle ze bd slurzyl x od switcha i scenariusz bd tak ze jak x>0 to w prawo (RandomSet)
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1,lastRoom->nr+1));///nowy pokoj z wid o jeden wiekszy bo w prawo

                LastRoom->east = tmp;
              //  LastRoom->ShowALL();
                LastRoom = tmp;

             //  LastRoom->ShowALL();
                lastRoom = LastRoom;

     }
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,lastRoom->lvl,lastRoom->wid-1,lastRoom->nr+1)); ///nowy pokoj z wid o jeden mniejszy bo w lewo

                LastRoom->west = tmp;
              //  LastRoom->ShowALL();

                LastRoom = tmp;

             //   LastRoom->ShowALL();
                lastRoom = LastRoom;



    }

    }

    tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1));
    LastRoom->north = tmp;
  //  LastRoom->ShowALL();                                                                                   ///ostatni pokoj tez zawsze w gore wiec ten tez poza petla

    LastRoom = tmp;
    lastRoom = LastRoom;


    }

    LastRoom = tmp;
    lastRoom = LastRoom;
     /// w sumie currentRoom tutaj nie jest potrzebny ale poza metoda bedzie wiec A K T U A L I Z A C J A
                        ///tu akurat dla scenariusza 0 XD
  //  LastRoom->ShowALL();
}

///EGZEKUCJA GRYFICY GNILDY [KONIEC]



/// ProstowSciane

void hotel :: Blind_Path(int ile, int RoL){ /// tworzenie zaulkow slepych, mam w glowie tak ze najpierw jest tworzone to a potem wlasciwa scierzka
/// bo tu LastRoom nam sie nie zmienia po zakonczeniu pracy metody
/// ta metoda dziala bardzo podobnie do Ok_Path ale nie akualizuje lastRoom z Head'a

     room* LastRoom;
     room* tmp1;

     int licz =0;

        licz = lastRoom->nr;

     LastRoom = lastRoom;

     cout<<"1 :"<<licz<<"\n";



     room* tmp;

     tmp = (new room(LastRoom,NULL,NULL,LastRoom->lvl+1,LastRoom->wid,lastRoom->nr+1));
                LastRoom->north = tmp;
               // LastRoom->ShowALL();

                LastRoom = tmp;


                lastRoom = LastRoom;
                licz = licz + 1;
                cout<<licz;




              //  LastRoom->ShowALL();

                 tmp1 = lastRoom;




     if(RoL>0){
    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,NULL,LastRoom,LastRoom->lvl,LastRoom->wid+1,lastRoom->nr+1));
                LastRoom->east = tmp;
               // LastRoom->ShowALL();

                LastRoom = tmp;

                lastRoom = LastRoom;


                licz++;




              //  LastRoom->ShowALL();

    }
 //   tmp1->nr = LastRoom->nr;
    }

    if(RoL<0){

    for (int i=1;i<=ile;i++){

                tmp = (new room(NULL,LastRoom,NULL,LastRoom->lvl,LastRoom->wid-1,lastRoom->nr+1));

                LastRoom->west = tmp;
             //   LastRoom->ShowALL();

                LastRoom = tmp;

                lastRoom = LastRoom;

                licz++;


               // LastRoom->ShowALL();


    }

  //  tmp1->nr = LastRoom->nr ;
    }
         //   tmp1->nr = tmp1->nr + ile;

         tmp1->nr = licz;

          lastRoom = tmp1;

/// bo jak nie zwroce Last Rooma to na zewnatrz metody bd taki sam jak wczesniej, i tak ma byc, dlatego void :)
///PROSTOWSCIANE [KONIEC]
}
/*
void hotel:: ShowEAST(room* R){

        room* CurrentRoom;

        CurrentRoom = R;

        while ( CurrentRoom->east != NULL)
        {
             CurrentRoom->ShowALL();
             CurrentRoom = CurrentRoom->east;
        }
}
void hotel:: ShowWEST(room* R){

        room* CurrentRoom;


        CurrentRoom = R;

        while ( CurrentRoom->west != NULL)
        {
             CurrentRoom->ShowALL();
             CurrentRoom = CurrentRoom->west;
        }
}

*/
/*
[GRZYBO] Rozpiska jak to ma wygladac
    1. Wypisujemy obecny
    2. jesli idzie w gore to sprawdamy czy idzie na boki jesli tak to idziemy w bok do konca
    3. idziemy  w gore
    4
    (  n ie chcialo mi sie pisac dalej  XD )

*/
/*
void hotel:: ShowFloor(room* zero){


    room* CurrentRoom;
        room* tmp;
        int w = 0;
        int e = 0;

        CurrentRoom = zero;



        while (CurrentRoom != lastRoom )
        {    //   cout<<"START\n ";
              //  cout<<"curr : ";
               // CurrentRoom->ShowALL();
                tmp = CurrentRoom;
        if (CurrentRoom->north != NULL){
              //  cout<<"1 :";
                 CurrentRoom->ShowALL();



                while ( CurrentRoom->east != NULL )
                    {  CurrentRoom = CurrentRoom->east;
                         CurrentRoom->ShowALL();

                      //  cout<<"666";
                    }
                    CurrentRoom = tmp;

                while ( CurrentRoom->west != NULL )
                    {   CurrentRoom = CurrentRoom->west;
                        CurrentRoom->ShowALL();

                      //  cout<<"555";
                    }

            CurrentRoom = tmp;
            CurrentRoom = CurrentRoom->north;
            }

      else
        {
        //   cout<<"2 \n";

                tmp = CurrentRoom;

                CurrentRoom->ShowALL();

                while ( CurrentRoom->east != NULL )
                    {  // cout<<"444";
                        CurrentRoom = CurrentRoom->east;
                        CurrentRoom->ShowALL();
                        if (CurrentRoom->north != NULL){
                                e = e+1;
                        }


                    }

                CurrentRoom = tmp;






                while ( CurrentRoom->west != NULL )
                    {  // cout<<"333";
                        CurrentRoom = CurrentRoom->west;
                        CurrentRoom->ShowALL();
                         if (CurrentRoom->north != NULL){
                                w = w+1;
                        }


                    }


                    CurrentRoom = tmp;



                    if (e>w){

                             while ( CurrentRoom->north == NULL )
                       {
                         CurrentRoom = CurrentRoom->east;

                        }
                        CurrentRoom = CurrentRoom->north;
                    //   cout<<"222";

                    }





                    if (e<w){
                         while ( CurrentRoom->north == NULL )
                    {
                        CurrentRoom = CurrentRoom->west;
                    }
                     CurrentRoom = CurrentRoom->north;
                 //    cout<<"111";
                    }

                    }



      //  cout<<"KONIEC\n";
        }

       // cout<<"**********";
        lastRoom->ShowALL();




}

*/

void hotel::ShowHotel (room* zero){ ///chyba skonczony ha ha ha
    room* CurrentRoom;
    room* tmp;
    int w = 0;
    int e = 0;

    CurrentRoom = zero;


    while (CurrentRoom != lastRoom ) {
//        cout<<"START\n ";
//        cout<<"curr : ";
//        CurrentRoom->ShowALL();
        tmp = CurrentRoom;
        if (CurrentRoom->north != NULL) {
//            cout<<"1 :";
            CurrentRoom->ShowALL();

            while ( CurrentRoom->east != NULL ) {
                CurrentRoom = CurrentRoom->east;
                CurrentRoom->ShowALL();
//                cout<<"666";
            }
            CurrentRoom = tmp;

            while ( CurrentRoom->west != NULL ) {
                CurrentRoom = CurrentRoom->west;
                CurrentRoom->ShowALL();
//                cout<<"555";
            }

            CurrentRoom = tmp;
            CurrentRoom = CurrentRoom->north;
        } else {
//            cout<<"2 \n";
            tmp = CurrentRoom;
            CurrentRoom->ShowALL();

            while ( CurrentRoom->east != NULL ) {
//                cout<<"444";
                CurrentRoom = CurrentRoom->east;
                CurrentRoom->ShowALL();
                if (CurrentRoom->north != NULL) {
                    e = e+1;
                }
            }
            CurrentRoom = tmp;


            while ( CurrentRoom->west != NULL ) {
//                cout<<"333";
                CurrentRoom = CurrentRoom->west;
                CurrentRoom->ShowALL();
                if (CurrentRoom->north != NULL) {
                    w = w+1;
                }
            }
            CurrentRoom = tmp;

            if (e>w) {
                while ( CurrentRoom->north == NULL ) {
                    CurrentRoom = CurrentRoom->east;
                }
                CurrentRoom = CurrentRoom->north;
//                cout<<"222";
            }

            if (e<w){
                while ( CurrentRoom->north == NULL ) {
                    CurrentRoom = CurrentRoom->west;
                }
                CurrentRoom = CurrentRoom->north;
//                cout<<"111";
            }
        }
//        cout<<"KONIEC\n";
    }
//    cout<<"**********";
    lastRoom->ShowALL();
}




void hotel :: AddFloor (){///[GRZYBO] nowy pokoj, super metoda,uzywa i okPath i blindPath i Randoma

    int x ;

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



void hotel :: AddFloor2 (){///[GRZYBO] nowy pokoj, super metoda,uzywa i okPath i blindPath i Randoma

    room* tmpRoom;


    int x ;

    x = RandomSet(-8,8);

    cout<<x<<"\n";

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
            AddRoom(LEFT);  /// up + dwa razy w lewo                        /// JAKIE TO JEST KURWA DOOOOOOBRE!!!!!!
            AddRoom(UP);                                                    /// KUTASY Z NIEBA LECA!!!!!!!!!
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
            tmpRoom = lastRoom;
            AddRoom(LEFT);
            AddRoom(LEFT);
            lastRoom = tmpRoom;

            AddRoom(RIGHT);
            AddRoom(RIGHT);
            AddRoom(UP);                /// zaulek w lewo 2x + prawo 2x + up
            break;
        case -8:
            tmpRoom = lastRoom;
            AddRoom(RIGHT);
            AddRoom(RIGHT);
            lastRoom = tmpRoom;

            AddRoom(LEFT);
            AddRoom(LEFT);
            AddRoom(UP);                /// zaulek w prawo 2x + lewo 2x + up
            break;

///na razie napisałem tyle ale moge jeszce duuuuuuuzo wiecej dodac dla urozmaicenia :]



    }
}

/*

*/

