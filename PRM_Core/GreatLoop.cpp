
#include "c_GreatLoop"


void GreatLoop::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
        Metoda wywolywana w MAIN().
    */

    MAIN_TEST_DEBUG();

    MenuVer01();

    return;
}


#include "../c_Container"
#include <iostream>
using namespace std;


void GreatLoop::MAIN_TEST_DEBUG() {
    /** WorkSpace Przygotowany Specjalnie do TWOICH Testow.
        Traktuj go jak zwyklego MAIN'A.
        Domyslnie:
         - Jest Wywolywany
         - Nie Posiada Instrukcji
        Po zakonczeniu pracy pozostaw go w stanie w jakim go zastales.
    */


}


void GreatLoop::MenuVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    menu EXEC;
    int currentChoose = 0;

    //this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.
    EXEC.ShowMENU(currentChoose);
    GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        //int InputEvent = this->menu::Input(GLOOP, currentChoose);
        int InputEvent = EXEC.Input(GLOOP, currentChoose);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");         // Czyszczenie, Zerowanie Konsoli.
            EXEC.ShowMENU(currentChoose);
            //this->ShowMENU(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    return;
}




