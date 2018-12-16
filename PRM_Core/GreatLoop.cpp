
#include "c_GreatLoop"


//_________________________________
void GreatLoop::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
        Metoda wywolywana w MAIN().
    */

    // MAIN PRZYSTOSOWANY DO PRACY Z KODEM.    CLEAN IT AFTER. LEAVE IT ENABLED.
    MAIN_TEST_DEBUG();

    // METODY WYWOLANIA PROGRAMU, MENU LUB GRY.
    //MenuVer01();

    return;
}

#include "../PRM_MazeGen/c_maze"
//#include "../c_room"


//_________________________________
void GreatLoop::MAIN_TEST_DEBUG() {
    /** WorkSpace Przygotowany Specjalnie do TWOICH Testow.
        Traktuj go jak zwyklego MAIN'A.
        Domyslnie:
         - Jest Wywolywany
         - Nie Posiada Instrukcji
        Po zakonczeniu pracy pozostaw go w stanie w jakim go zastales.
    */

    maze Head;

    Head.AddFloor();

    Head.currentRoom->ClearRoom();

    int tmpChan = 15;
    int tmpChan2 = 5;

    Head.currentRoom->Danger(2,2,20,10,tmpChan);     //lg
    Head.currentRoom->Danger(25,13,43,22,5);        //sr
    Head.currentRoom->Danger(2,25,20,35,tmpChan);    // lewy dol rog
    Head.currentRoom->Danger(48,2,69,10,tmpChan);    //prawy gor rog
    Head.currentRoom->Danger(48,25,69,35,tmpChan);   // prawy dol rog
    Head.currentRoom->Danger(25,4,43,10,tmpChan2);   // sr gora
    Head.currentRoom->Danger(6,13,20,22,tmpChan2);   // sr lewo
    Head.currentRoom->Danger(49,13,63,22,tmpChan2);  // sr prawo
    Head.currentRoom->Danger(25,25,43,31,tmpChan2);  // sr dol

    Head.currentRoom->RenderRoom();

    Head.SET_CURR(Head.LASTROOM());


}


//_________________________________
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




