
#include "c_Game"


/// [Kacu] ŚMIECIIIII -----------------------------
#include "../PRM_Objects/c_Player"
#include "../PRM_MazeGen/c_maze"

/// [Kacu] ŚMIECIIIII -----------------------------



//_________________________________
void Game::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
    */


    // METODY WYWOLANIA GRY.
    GameVer01();

    return;
}









//_________________________________
void Game::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    maze HeadMaze;

    HeadMaze.HERO.ShowGui();
    HeadMaze.veryFirstRoom->RenderRoom(); // PreRender. Wykonanie Pierwszej Klatki.

//    HeadMaze.ShowMaze();

//    cout << "\n\n\n";
//
//



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
            HeadMaze.HERO.roomPos->RenderRoom();
        }
    }
    return;
}



