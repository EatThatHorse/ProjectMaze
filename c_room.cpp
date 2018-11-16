
#include "c_room"
/* [Kacu]
    Zwykle nie includujemy plikow .cpp
    Robimy na odwrot niz Sep, bo stosujemy PROJEKT.
    Roznice dzialania:
    ┌───────────────────────────────────────┬───────────────────────────────────────┐
    │   Projekt (my)                        │   Metoda Doczepiania (laborki Sep)    │
    ├───────────────────────────────────────┼───────────────────────────────────────┤
    │1) Jest Drzewo Projektu                │1) Nie ma Drzewa Projektu              │
    │    - jedna funkcja main()             │    - Kompilator znajduje tego main()'a│
    │      Kompilator zawsze ja znajdzie    │      Ktorego strona jest aktualnie    │
    │                                       │      otwarta.                         │
    │    - Trzeba dolaczac pliki [addfiles] │    - Wystarczy gdy pliki otwarte w c:b│
    │                                       │                                       │
    │2) Linkuje pliki w wieksza siatke:     │2) Tworzy jeden wielki, ciagly plik:   │
    │    ▓▓_____                            │   ▓▓                                  │
    │    │  ┌─▓▓   - Czyta Ten sam plik     │    │  * Caly podpunkt (2) nie jest    │
    │   ▓▓  │  │     tyle razy ile przejdzie│   ▓▓    do konca prawdziwy, uzywam    │
    │  ┌┴──▓▓  │     przez niego #include.  │    │    wielu uproszczen.             │
    │  └▓▓     ▓▓  - Wygodne gdy traktujemy │   ▓▓                                  │
    │                klase jako nowy typ.   │    │  * Ostatecznie obydwoma sposobami│
    │ - np: Mozemy includowac plik c_room   |         mozna osiagnac to samo. Glowna│
    │       wiele razy w roznych miejscach. |         roznica pojawia sie w (3)pkt. │
    │                                                                               │
    │3) Staramy sie trzymac definicje w plikach [*.cpp], a deklaracje w plikach [*.]│
    │   Co pozwala nam na podpinanie jedynie plikow [*.].                           │
    │   - Usprawnia to strukture projektu.                                          │
    │   - Ulatwia znalezienie bledow.                                               │
    │   - Hermetyzuje: Mozesz podejzec w pliku zawierajacym 20 linijek wszystko co  │
    │     jestes w stanie wykorzystac bez zaglebiania sie w dzialanie calego pliku, │
    │     majacego linijek 2000.                                                    │
    │                                                                               │
    │3.2) KONKLUZJA:                                                                │
    │   - Aby czegos uzyc (funkcja, klasa, metoda, obiekt, zmienna) wystarczy znac  │
    │     tego czegos nazwe. A pliki z deklaracja [*.]                              │
    │     pokazuja - prawie - tylko nazwe.                                          │
    └───────────────────────────────────────────────────────────────────────────────┘
*/


//room::room MakeRoom(int lvl,int wid ,room* n,room* e,room* s,room* w )
/* [Kacu]
    Wszystko w c++ posiada swoja fizyczna komorke pamieci.
    (zmienna, funkcja, obiekt, metoda), wszystko.

    Aby sie dostac do zawartosci komorki - niezaleznie od tego czy jest tam wartosc int czy
    instrukcje danej funkcji - korzystamy z dwoch narzedzi:
        - Nazwa (nazwa zmiennej,                           nazwa funkcji, itd..)
        - Adres (Adres zmiennej [np za pomoca wskaźnikow], Adres funkcji [istnieje cos takiego], itd..)

     ZMIENNA:
    ┌───────────────────────────────────────────────────────────────────────────┐
    │   TYP  NAZWA;                                                             │
    │    │     └ nazwa zmiennej. Za jej pomocą mowimy komputerowi               │
    │    │       z ktorej komorki pamieci ma czytac (przechowywana wartosc).    │
    │    │                                                                      │
    │    └ typ Zmiennej. Ile Miejsca dana komorka pamieci rezerwuje.            │
    │      Ile bitow ma maszyna przeczytac aby                                  │
    │      znac Wartosc przechowywana przez zmienna.                            │
    └───────────────────────────────────────────────────────────────────────────┘

     FUNKCJA:
    ┌───────────────────────────────────────────────────────────────────────────┐
    │   TYP  NAZWA  (ARGUMENTY);                                                │
    │    │     │         └ argumenty funkcji. Tymczasowe zmienne                │
    │    │     │           wykorzystywane w czasie trwania funkcji.             │
    │    │     │                                                                │
    │    │     └ nazwa funkcji. Za jej pomocą mowimy komputerowi                │
    │    │       z ktorej komorki ma czytac (instrukcje).                       │
    │    │                                                                      │
    │    └ typ ZWRACANY funkcji. Czego maszyna                                  │
    │      moze sie spodziewac po wykonaniu funkcji.                            │
    └───────────────────────────────────────────────────────────────────────────┘

     METODA:
    ┌───────────────────────────────────────────────────────────────────────────┐
    │   TYP  KLASA::NAZWA  (ARGUMENTY);                                         │
    │    │     │      │                └ argumenty metody. Tymczasowe zmienne   │
    │    │     │      │                  wykorzystywane w czasie trwania metody.│
    │    │     │      │                                                         │
    │    │     │      └ nazwa funkcji. Za jej pomocą mowimy komputerowi         │
    │    │     │        z ktorej komorki ma czytac (instrukcje).                │
    │    │     │                                                                │
    │    │     └ Maszyna musi wiedziec w jakiej Klasie ma szukac danej metody,  │
    │    │       a przeciez odnajduje odpowiednie miejsce pamieci po nazwie,    │
    │    │       nie po typie. Dlatego zapis: [KLASA::TYP NAZWA] Nie ma sensu.  │
    │    │                                                                      │
    │    └ typ ZWRACANY metody. Czego maszyna                                   │
    │      moze sie spodziewac po wykonaniu metody.                             │
    └───────────────────────────────────────────────────────────────────────────┘
*/


/** [Kacu]
    DOBRZE!!!
    Ale da sie lepiej!  ^^
    Metode MakeRoom przerobic na konstruktor.
*/
room room::MakeRoom(int lvl,int wid ,room* n,room* e,room* s,room* w ) { ///tworzy jeden pokoj, jesli bez argumentow - pokoj 00
    room room;

    room.lvl = lvl;
    room.wid = wid;
    room.north = n;
    room.east = e;
    room.south = s;
    room.west = w;
    room.Me = this;

    return room;
}

// [Kacu] - Odpowiednia tabulacje ustawiaj w trakcie pisania, nie na poczatku, nie na koncu.
//        - Unikniesz bledow jak ta zagubiona klamra.
//}


void room::PrintRoom(room room){
    cout << room.lvl   << "\n"
         << room.wid   << "\n"
         << room.north << "\n"
         << room.east  << "\n"
         << room.south << "\n"
         << room.west  << "\n";
    /* [Kacu]
      - endl to funkcja. Wywolanie kazdej funkcji kosztuje.
      - NORMALNIE NIE MA Z TYM PROBLEMU !!!
      - Tylko w ramach TEGO projektu unikamy endl'a, bo caly render to consola.

      - Podobnie cout, to tez funkcja.
        Lepiej jest zrobic wiekszy strumien niz wiele wywolan funkcji.
      - Zwroc uwage na srednik [;] - Jest tylko jeden, tam gdzie konczy sie instrukcja.

      - Tutejsza tabulacja to w polowie moj wymysl.
        Z jednej strony: cout znajduje sie na odpowiednim poziomie.
        Z drugiej jednak: wymyslilem sobie by kazdy [<<] byl w nowej lini.
      - Zasada jest jedna: PISAC TAK, ABY ULATWIC INNYM I SOBIE PRACE NAD KODEM.
    */
}

/** [Kacu] Zakomentowalem tymczasowo, aby ominac errory i skompilowac.

    hotel room::SetRoom(room room){ /// tworzenie nowych roomow, losowanie jakich i ilu, argumenty to obecny pokoj, zwraca pudelo z pokojami w srodku
        srand(time(NULL));
        int x = std::rand()%13 -6;

        if (x==0) {
            hotel h;
            room room0 = MakeRoom(room.lvl + 1,room.wid,NULL,NULL,room.Me,NULL);
            h = MakeHotel(&room0);
            return h;
        }
        if(x==1) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl + 1,room.wid + 1,NULL,NULL,room0.Me,NULL);
            h = MakeHotel(&room0,&room1);
            return h;
            }
        if (x==2) {
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
    }
*/
