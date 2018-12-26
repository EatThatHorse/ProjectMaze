
#include "c_Game"


Game::Game(bool* T_GLOOP){    // KONSTRUKTOR
    this->GLOOP = T_GLOOP;
}


void Game::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
    */
    // METODY WYWOLANIA GRY.
    GameVer01();

    return;
}


void Game::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    maze HeadMaze;

//    HeadMaze.ShowMaze();
    HeadMaze.HERO.ShowGui();
    cout << "\n\n\n";
    HeadMaze.walker->RenderRoom(); // PreRender. Wykonanie Pierwszej Klatki.

    *GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli:
        //   - Jeden Input, Jeden Klawisz
        //   - Jedna Klatka, Jeden Frame

        int InputEvent;
        InputEvent = Input::Run01G(HeadMaze);

        if (InputEvent!=224) {      // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                          // Czyszczenie, Zerowanie Konsoli.

//            HeadMaze.ShowMaze();
            HeadMaze.HERO.ShowGui();
            cout << "\n\n\n";
            HeadMaze.walker->RenderRoom();    // Main Render
        }
    }
    return;
}



