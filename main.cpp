
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





int main (){

    // [Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───
    /**
        - Czas już testowac wszystko w main'nie.
        - Tutaj tworzysz jeden obiekt typu hotel.
        - Na nim będziemy pracować przez całe zapętlenie gry. [GREAT LOOP]
    */
    // End.[Kacu] ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ─── ───

    return 0;
}

