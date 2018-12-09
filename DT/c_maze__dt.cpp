#ifdef C_MAZE__DT

// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
/*
- Mamy juz jeden obiekt typu hotel. Powstal on w mainie().
            - Teraz to co chcemy zrobic to dodawac do niego pokoje.
            - Proponuje napisanie 3 metod.
              Albo
              jednej wiekszej a nastepnie podzielic ja na mniejsze.
              (nie wszystko da sie od razu zaplanowac)
        */

            /** - Metoda zajmuje sie dodaniem calego pietra na raz.
                  Rozpoczynamy gre → Dodajemy poczotkowe pietro →
                  gracz je przechodzi → dodajemy kolejne pietro →
                  gracz je przechodzi → dodajemy kolejne pietro → ...

                - W argumencie przyjmuje referencje do glownego hotelu utworzonego w mainie().
                  Dzieki temu wszelkie zmiany ktore dokonamy na HeadHotel dokonaja sie na tym glownym, mainowym hotelu.
                - Zwracamy void, bo dzialajac na referencji nie musimy zwracac hotelu.
                  W miare pisania mozesz zmienic void na bool lub int, w celu kontroli bledow.

                - Metoda musi wiedziec jaki rodzaj pietra ma dodac.
                  Wiec najpierw odpalamy inna metode ktora nam wylosuje set.
                  [RandomSet]
                - Dalej pewnie switch case do kazdego scenariusza, setu.
                    [Przykład dla setu 0]
                    - zaczynamy od [HeadHotel.lastRoom] poniewaz to adres ostatniego dodanego pokoju.
                    - tworzymy nowyPokoj. dodajemy go do northWskaznika pokoju lastRoom.
                        HeadHotel.lastRoom->north = &nowyPokoj;  // znak & zwraca adres nowyPokoj.
                    - To najprostszy przyklad wiec konczymy. Jeszcze tylko zUpdatowac lastRoom by wskazywal na
                      nowy, najwyzszy pokoj. Czyli:
                        HeadHotel.lastRoom = &nowyPokoj;  // Wczesniej modyfikowalismy pokoj na ktory wskazywal lastRoom.
                                                          // Teraz modyfikujemy lastRoom ktory jest zmienna z klasy hotel.

                    [Przykład dla setu 5]       ─┬┘       // [Jeden PRAWO i jeden UP] + Jeden pokoj w LEWO (slepy zaulek).
                    - Ponownie, zaczynamy od [HeadHotel.lastRoom]. Caly poczatek tak samo.
                    - tworzymy nowyPokoj. dodajemy go do northWskaznika pokoju lastRoom.
                        HeadHotel.lastRoom->north = &nowyPokoj;
                    - Updatujemy lastRoom by wskazywal na nowy pokoj. [┬]
                        HeadHotel.lastRoom = &nowyPokoj;
                    - Teraz zabral bym sie za slepy zaulek w lewo. Robie nowy pokoj i podpinam go do lastRoom.
                        HeadHotel.lastRoom->west = &nowyPokoj;  // Zobacz ze robie to do wskaznika WEST!
                    - Jak mam juz podpiecie lastRoom [┬] do nowego pokoju(slepego zaulka) [─].
                      To musze podpiac z drugiej strony. Czyli Nowy pokoj [─] do lastRoom [┬].
                        HeadHotel.lastRoom->west->east = HeadHotel.lastRoom;    // bez &, bo lastRoom jest wskaznikiem.
                                              |     └─ wskaznik east pokoju slepy zaulek [─]. Bo:
                                              └─────── west juz wskazuje na pokoj slepy zaulek [─].
                                                       Dostalem sie do czego chcialem za pomocom wskaznikow.
                    - Nastepnie, jak mam juz zaulek z glowy, Biere sie za glowna droge w PRAWO.
                      wskaznik HeadHotel.lastRoom nadal wskazuje na [┬]. wiec lece od razu w prawo.
                        HeadHotel.lastRoom->east = &nowyPokoj;
                        // Pamietam by podpiac w drugo strone. Czyli to [┘] z tym [┬], wiec:
                        HeadHotel.lastRoom->east->west = HeadHotel.lastRoom;
                        // zmianiam ustawienie wskaznika lastRoom na pokoj z prawej.
                        HeadHotel.lastRoom = HeadHotel.lastRoom->east       // Teraz jestesmy tu [┘].
                        // wiec pozostaje nam jeden UP. Ale go nie dodajemy teraz! Bo bysmy w jednym casie skoczyli o dwa pietra.
                        // zrobilismy to:  [─┬┘] Czyli zaczynajac raz juz poszlismy do gory robiac to [┬].

                - Moja propozycja na Sety:
                    0          |         Ostatecznie to zawsze jest jeden do gory. Nie mniej, nie wiecej. Na raz dodajemy maks jedno pietro.
                    1          ┌┘        Jeden w PRAWO i jeden do gory.
                   -1         └┐         Jeden w LEWO i jeden do gory.
                    2          ┌─┘       Dwa w PRAWO i jeden do gory.
                   -2        └─┐         Dwa w LEWO i jeden do gory.
                    3          ┌──┘      Trzy w PRAWO i jeden ...
                   -3       └──┐         Trzy w LEWO i jeden ...

                    I mysle by dalej w prawo/lewo nie isc, dac tylko slepe zaulki.
                    Jak bedzie ostatecznie. Zobaczymy w miare rozwoju projektu.

                    4         ─┤         [Jeden UP] + Jeden pokoj w LEWO (slepy zaulek).
                   -4          ├─        [Jeden UP] + Jeden pokoj w PRAWO (slepy zaulek).
                    5         ─┬┘        [Jeden PRAWO i jeden UP] + Jeden pokoj w LEWO (slepy zaulek).
                   -5         └┬─        [Jeden LEWO i jeden UP] + Jeden pokoj w PRAWO (slepy zaulek).
                    6         ─┬─┘       [Dwa PRAWO i jeden UP] + Jeden pokoj w LEWO (slepy zaulek).
                   -6        └─┬─        [Dwa LEWO i jeden UP] + Jeden pokoj w PRAWO (slepy zaulek).
                    7         ─┬──┘      [Trzy PRAWO i jeden UP] + Jeden pokoj w LEWO (slepy zaulek).
                   -7       └──┬─        [Trzy LEWO i jeden UP] + Jeden pokoj w PRAWO (slepy zaulek).

                   Tak Mozna bez konca, tak dlugo jak bedziesz mial checi. Tylko nie zaczynaj nowych gdy stare nie dzialaja!

                    8        ──┤         [Jeden UP] + Dwa LEWO (slepy zaulek).
                   -8          ├──       [Jeden UP] + Dwa PRAWO (slepy zaulek).
                    9        ──┬┘        [Jeden PRAWO i jeden UP] + Dwa LEWO (slepy zaulek).
                   -9         └┬──       [Jeden LEWO i jeden UP]  + Dwa PRAWO (slepy zaulek).
                   10        ──┬─┘       [Dwa PRAWO i jeden UP]   + Dwa LEWO (slepy zaulek).
                  -10        └─┬──       [Dwa LEWO i jeden UP]    + Dwa PRAWO (slepy zaulek).
                   11        ──┬──┘      [Trzy PRAWO i jeden UP]  + Dwa LEWO (slepy zaulek).
                  -11       └──┬──       [Trzy LEWO i jeden UP]   + Dwa PRAWO (slepy zaulek).

                  Wszystko to powyzej jest jedynie moja propozycja. Jak znajdziesz wygodniejszy dla siebie
                  rozklad scenariuszy, uzywaj swojego. Liczby nie musza tez byc ujemne, jak wolisz by wszystkie byly dodatnie.
            */
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■

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
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
#endif // C_MAZE__DT
