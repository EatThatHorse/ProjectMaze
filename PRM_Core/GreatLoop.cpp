
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
    GameVer01();

    return;
}


//_________________________________
void GreatLoop::MAIN_TEST_DEBUG() {
    /** WorkSpace Przygotowany Specjalnie do TWOICH Testow.
        Traktuj go jak zwyklego MAIN'A.
        Domyslnie:
         - Jest Wywolywany
         - Nie Posiada Instrukcji
        Po zakonczeniu pracy pozostaw go w stanie w jakim go zastales.
    */
    // DEBUG_KEYBOARD ();   // You Can Tast It. If You Want.


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



/// [Kacu] ŚMIECIIIII -----------------------------
#include "../PRM_Objects/c_Player"
#include "../PRM_MazeGen/c_maze"

/// [Kacu] ŚMIECIIIII -----------------------------



//_________________________________
void GreatLoop::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    maze HeadMaze;
    player HERO(HeadMaze.zeroRoom);

    HeadMaze.AddFloor();
    HeadMaze.AddFloor();
    HeadMaze.currentRoom->ClearRoom();
    HeadMaze.currentRoom->Danger(1,1,80,80,10);


    //HeadMaze.SET_CURR(HeadMaze.LASTROOM());


    cout << "\n\n\n\n\n";
    HeadMaze.currentRoom->RenderRoom(); // PreRender. Wykonanie Pierwszej Klatki.


    GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli:
        //   - Jeden Input, Jeden Klawisz
        //   - Jedna Klatka, Jeden Frame

        int InputEvent;
        InputEvent = Input::Run01G(HERO,HeadMaze);

        if (InputEvent!=224) {      // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                          // Czyszczenie, Zerowanie Konsoli.
            HERO.ShowGui();
            cout << "\n\n\n\n\n";
            HERO.roomPos->RenderRoom();
        }
    }
    return;
}



