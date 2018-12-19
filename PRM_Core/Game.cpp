
#include "c_Game"


/// [Kacu] ŒMIECIIIII -----------------------------
#include "../PRM_Objects/c_Player"
#include "../PRM_MazeGen/c_maze"

/// [Kacu] ŒMIECIIIII -----------------------------



//_________________________________
void Game::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
    */


    // METODY WYWOLANIA PROGRAMU, MENU LUB GRY.
    //MenuVer01();
    GameVer01();

    return;
}









//_________________________________
void Game::GameVer01() {
    /** Pierwsza wersja Funkcji Steruj¹cej Rozgrywk¹. */

    maze HeadMaze;
    player HERO(HeadMaze.zeroRoom);

    HeadMaze.AddFloor();
    HeadMaze.AddFloor();
    HeadMaze.currentRoom->ClearRoom();
    HeadMaze.currentRoom->Danger(1,1,80,80,10);


    //HeadMaze.SET_CURR(HeadMaze.LASTROOM());


    cout << "\n\n\n\n\n";
    HeadMaze.currentRoom->RenderRoom(); // PreRender. Wykonanie Pierwszej Klatki.


    *GLOOP = true;   // GREAT LOOP - Wykonywana tak d³ugo jak dzia³a program.
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



