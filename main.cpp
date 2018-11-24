
#include <iostream>
using std::cout;
using std::cin;




// [Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───
#include "c_hotel"
#include "c_room"
// End.[Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───




// [Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───
/*  class HOTEL
      - [room*] wskaznik do pokazywania na zerowy pokoj.
      - [room*] wskaznik do pokazywania na ostatni dodany pokoj.
*/

/*  class ROOM
      - [room*] wskaznik do pokazywania na pokoj North.
      - [room*] wskaznik do pokazywania na pokoj East.
      - [room*] wskaznik do pokazywania na pokoj West.

      // Polozenie Pokoju:
      - [int] wysokosc   [0;+oo)
      - [int] szerokosc (-oo;+oo)
*/

//  _____________________________________
/// Ogolne Dzialanie Programu / Projetku
/*  PRESS START TO PLAYGAME !
    <button pressed>
    ...
    [metoda lub funkcja] Preparations for Game to Run:
      1) Create empty hotel
      2) Create First room. (zero room)
        2.1) bez metody?: utworzenie pustego pokoju
        2.2) bez metody?: nadanie mu poczatkowych wartosci.
        2.3) bez metody?: podpiecie go do obydwu wskaznikow z hotelu (zerowy i ostatni)
      3) Metoda A [klasy hotel]: tworzy cale kolejne pietro.
        3.1)[A] Funkcja losujaca scenariusz
        3.2)[A] Petla?
            3.3) Metoda tworzaca jeden pokoj [klasa room], Nadajaca mu odpowiednie wartosci.
                 Jako argument przyjmuje wylosowany scenariusz (int)
                 Na koniec podpina ten pokoj do wksaznika na ostatni dodany pokoj. (w klasie hotel)
            3.4) Kolejny Krok Petli, Az wszystkie pokoje z danego scenariusza zostana podpiete.
    //Koniec [Preparations for Game to Run], (Jak na razie)

    [metoda lub funkcja] GREAT LOOP:
      1) Gracz Gra. Funkcja Update smiga co klatke Renderu.
      2) Gracz dochodzi do ostatnich drzwi:
        2.1) Metoda A [klasy hotel]: tworzy cale kolejne pietro.
      3) Kolejny Krok GREAT LOOP, Gracz dalej gra (1).
*/
// End.[Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───

// ◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘ [Kacu]   1/2
#include <iostream>
using std::cout;

class unit {
public: /// KONSTRUKTOR
    unit (unit* t_north, int t_lvl){
        this->north = t_north;
        this->south = NULL;     // Jak na razie nie ma nic nizej, Wiec zostawiamy pusty.
        this->lvl = t_lvl;


        // t_north jest wskaznikiem na poprzedni unit. Moge wiec go troche zmodyfikowac.
        // Np ustawic jego wskaznik south na obiekt ktory wlasnie tworzymy.
        if (t_north != NULL)    // nalezy pamietac o zerowym unicie. On nie ma w northu zadnego elementu.
            t_north->south = this;
    }
public: /// ZMIENNE
    unit* north;
    unit* south;
    int lvl;
public: /// METODY
    void Show(){
        cout << " " << (char)254
             << " lvl: " << this->lvl;
    }
    void ShowALL(){
        cout << " "                 << (char)254
             << " lvl: "            << this->lvl
             << "        "
             << "  adresUnitu: ["   << this
             << "] North: ["        << this->north
             << "] South: ["        << this->south
             << "]";
    }
};

class container {
 public:
    unit* first;
    unit* last;
};
// ◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘ end: [Kacu]

int main (){

    // [Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───
    /**
        - Czas już testowac wszystko w main'nie.
        - Tutaj tworzysz jeden obiekt typu hotel.
        - Na nim będziemy pracować przez całe zapętlenie gry. [GREAT LOOP]
    */
    // End.[Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───


 ///[GRZYBO] testy OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/*
    #define KACU_MADE_CODE_DIRTYY     // UnComment To Run some Kacu Code. Comment To Run Grzybo Code.
    #ifndef KACU_MADE_CODE_DIRTYY

    // hotel HeadHotel;

    hotel hHotel;

    hHotel.r1->lvl = 1;
    hHotel.r1->wid = 2;

    hHotel.r1->PrintRoom();

    //HeadHotel.AddFloor();

    //HeadHotel.PrintHotel();

    #else
    // ◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘ [Kacu]   2/2
     Walczysz dzielnie!
        Wkrada ci sie blad logiczny ktory nie wiesz jak przeskoczyc. (tak sie domyslam patrzac na kod..)
            Klasa hotel posiada w sobie wskazniki do 6 pokoi.
            Oznacza to ze jeden obiekt typu hotel moze trzymac w sobie 6 obiektow typu room.

            Pokaze ci jak sprawic by jeden obiekt typu hotel trzymal w sobie [ 0 ; +oo ) obiektow typu room.
            Korzystam z dwoch klas zdefiniowanych nad mainem. [container]-hotel,  [unit]-pokoj.
     */


     /*


    // VER_1: Only Units.   ---------------------------------------------------------------------------------
    unit zero (NULL, 0);    // Zerowy unit. Ma nazwe. Wiec bede mogl z niego korzystac wiele razy.
    cout << "test czy wypisuje pokoj zero:    "; zero.Show();
    unit* lastUnit;         // Wskaznik na ostatni dodany unit. Niezbedne do dodawania nowych.
    lastUnit = &zero;       // Jak na razie mamy jeden Unit. Od niego zaczynamy.
    int iloscUnitow = 1;    // Pokazuje ile unitow powstalo. Jak na razie mamy tylko zerowy wiec 1.

    // Dodajmy teraz 7 Unitow.
    for (int i=1; i<=1; ++i){
        // (new int) W ten sposob tworze obiekt typu int. Nie ma on nazwy ani wartosci.
        //           Ale nadal fizycznie istnieje w pamieci. Posiada swoj adres,
        //           wiec jezeli go znasz to jestes w stanie operowac tym obiektem tak jak by mial nazwe.

        // (new unit) Tutaj mamy inna sytuacje, poniewaz celowo zablokowalem domyslny konstruktor. (nie piszac go)
        //            Ale tak to zasada ta sama. tworze obiekt typu unit. Tylko ze odpowiednim konstruktorem.

        unit* tmp;  // tymczasowo wskazuje na nowopowstaly obiekt. Ten wskaznik znika razem z wykonaniem petli.
                    // oznacza to ze gdy petla rozpocznie kolejny krok, stracimy dostep do utworzonego unitu.
                    // Do czego to? Zobaczysz nizej.
        tmp = (new unit(lastUnit, i));    // nadalem mu adres poprzedniego unitu. lastUnit jest wskaznikiem, wiec bez &.

        // Dla wlasnej wygody wskaznik south poprzedniego obiektu rowniez ustawiam w konstroktorze nowego obiektu.

        lastUnit = tmp; // Aby wszystkie unity nie wskazywaly na zerowy, musimy przeskoczyc wskaznikiem.
                        // Teraz unit ktory wlasnie utworzylismy jest ostatni/najnowszy.
        ++iloscUnitow;  // Koniec, mamy nowy Unit. zwiekszamy iloscUnitow o jeden.
    }

    // Sprawdźmy czy dziala. Wyswietlmy wszystkie unity.
    unit* currentUnit = &zero;  // Potrzebujemy nowego wskaznika ktory bedzie "wedrowal" przez unity.

    cout << "\n\n\n"
         << "Wypisz wszystkie unity co masz!\n";

    for (int i=1; i <= iloscUnitow; ++i){   // moglem zaczac od 0, ale jakos mi tutaj logiczniej jak zaczne od [1] i [<=]
       // currentUnit->Show();                // wyswietlamy to gdzie jestesmy.
        currentUnit->ShowALL();          // Odkomentuj jedno, zakomentuj drugie. Mozesz porownac adresy  :D.

        if (i<iloscUnitow) cout << "\n " << (char)18 << "\n";   // Maly zabieg estetyczny.
        else cout << "\n\n\n";

        currentUnit = currentUnit->south;   // wedruj dalej.
    }

    // Dziala!  :D
    // Da sie to zrobic lepiej wykorzystujac klase container. Wtedy wgl nie operujemy unitami.
    // Wiecej rzeczy dzieje sie automatycznie.

    // Wyzwanie nadal czeka na ciebie! Twoje pokoje nie ida tylko w jednym kierunku.
    // I jak zrobisz wyswietlanie to bedzie lecialo od tylu. Od ostatniego pokoju
    // Masz tydzien!  xp [brutal]

    // ◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘◙◘ end: [Kacu]
     #endif // End: KACU_MADE_CODE_DIRTYY

     */


     ///[GRZYBO] MOJE PIERDOLY ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        hotel HeadHotel;
        room zero_Room(NULL,NULL,NULL,0,0,1);
        HeadHotel.nr = 1;

        zero_Room.ShowALL();

        HeadHotel.lastRoom = &zero_Room;

        HeadHotel.AddFloor();

        getchar(); /// dodalem to bo w obu wywolaniach AddFloor byly te same liczby wylosowane

        HeadHotel.AddFloor();


        ///numerowanie pokoi dziala dobrze!!!!!!









        //HeadHotel.lastRoom->ShowALL();

        //HeadHotel.currentRoom->ShowALL();














    return 0;
}

