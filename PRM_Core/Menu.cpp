
#include "c_Menu"
#include "../c_menu"


//_________________________________
void Menu::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
    */

    // METODY WYWOLANIA PROGRAMU, MENU LUB GRY.
    //MenuVer01();
    MenuVer01();

    return;
}



//_________________________________
void Menu::MenuVer01() {
    /** Pierwsza wersja Funkcji Steruj¹cej Rozgrywk¹. */

    menu EXEC;
    int currentChoose = 0;

    //this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.
    EXEC.ShowMENU(currentChoose);
    *GLOOP = true;   // GREAT LOOP - Wykonywana tak d³ugo jak dzia³a program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        //int InputEvent = this->menu::Input(GLOOP, currentChoose);
        int InputEvent = EXEC.Input(*GLOOP, currentChoose);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");         // Czyszczenie, Zerowanie Konsoli.
            EXEC.ShowMENU(currentChoose);
            //this->ShowMENU(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek siê zmieni na ekranie.
        }
    }
    return;
}
