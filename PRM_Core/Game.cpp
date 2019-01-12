
#include "c_Game"


Game::Game(bool* T_GLOOP){    // KONSTRUKTOR
    this->GLOOP = T_GLOOP;
}


void Game::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
    */
    // METODY WYWOLANIA GRY.
    int score;
     score = GameVer01();

        Stats Data;
        Data.Save(score);    /// zapis nicka po rozgrywce
        Data.Write();       ///zapis do pliku



    return;
}


int Game::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    maze HeadMaze;

    {
        int x  = HeadMaze.HERO.xpos;
        int y  = HeadMaze.HERO.ypos;
        char s = HeadMaze.HERO.symbol;

        system("cls");
        cout << "\n\n\n";
        HeadMaze.HERO.ShowGui();
        HeadMaze.HERO.roomPos->EditPX (x,y,s);  // PreRender Gracza
        HeadMaze.HERO.roomPos->RenderRoom();    // PreRender. Wykonanie Pierwszej Klatki.


    }


    *GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (*GLOOP) {
        //  Jedno Wykonanie Petli:
        //   - Jeden Input, Jeden Klawisz
        //   - Jedna Klatka, Jeden Frame

        int InputEvent;
        InputEvent = Input::Run01G(GLOOP, HeadMaze);

        if (InputEvent!=224) {      // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                          // Czyszczenie, Zerowanie Konsoli.

            int x  = HeadMaze.HERO.xpos;
            int y  = HeadMaze.HERO.ypos;
            char s = HeadMaze.HERO.symbol;

            cout << "\n\n\n";
            HeadMaze.HERO.ShowGui();
            HeadMaze.HERO.roomPos->EditPX (x,y,s);  // PreRender Gracza
            HeadMaze.HERO.roomPos->RenderRoom();    // PreRender. Wykonanie Pierwszej Klatki.


            }
                }






    return 0;
}



