
#include "c_Menu"
//#include "../c_menu"



Menu::Menu(bool* T_GLOOP){
    this->GLOOP = T_GLOOP;
}



void Menu::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow Tutaj.
    */
    // METODY WYWOLANIA MENU.
    MenuVer01();

    return;
}



void Menu::MenuVer01() {
    /** Pierwsza wersja Menu. */

//    menu EXEC;
//    int currentChoose = 0;
//
//    //this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.
//    EXEC.ShowMENU(currentChoose);
//    *GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
//    while (GLOOP) {
//        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.
//
//        //int InputEvent = this->menu::Input(GLOOP, currentChoose);
//        int InputEvent = EXEC.Input(*GLOOP, currentChoose);
//
//        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
//            system("cls");         // Czyszczenie, Zerowanie Konsoli.
//            EXEC.ShowMENU(currentChoose);
//            //this->ShowMENU(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
//        }
//    }
    return;
}
