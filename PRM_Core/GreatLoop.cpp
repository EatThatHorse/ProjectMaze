
#include "c_GreatLoop"

#include "../c_maze"
#include "../c_room"
#include <stdio.h>



void DEBUG_KEYBOARD ();


void GreatLoop::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
        Metoda wywolywana w MAIN().
    */
    //#define PRM__DEBUG_INPUT    // UnComment To Enable DEBUG_INPUT
    #ifdef PRM__DEBUG_INPUT
    {       /// When Active: No Game is runnig. Just DEBUG_INPUT.
        while(1) DEBUG_KEYBOARD();
    }
    #else
    // _________________
    /// STARTING POINT:

    //GameVer01();
    //GameVer02();
    //MenuVer01();
    //TestRoom();   // Old Grzybo main.

    #endif
    return;
}


void GreatLoop::TestRoom() {

    room zeroRoom(NULL,NULL,NULL,0,0);
    maze Head(&zeroRoom);

///testowanko

    int x;
    cin>>x;

    for(int i = 0;i<x;++i ){

        getchar();
        Head.AddFloor();
        Head.ShowMaze();
        Head.SET_CURR(Head.LASTROOM());

    }

}

void GreatLoop::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    player HERO;

    GLOOP = true;           // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //   Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        int InputEvent = this->Input::Run01G(HERO);

        int x = 4;

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                  // Czyszczenie, Zerowanie Konsoli.

            x = (x < 2)? 2 : x;

            cout << x/2;

        }
    }
    return;
}

void GreatLoop::GameVer02() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    player HERO;

    GLOOP = true;           // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //   Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        int InputEvent = this->Input::Run01G(HERO);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                  // Czyszczenie, Zerowanie Konsoli.
            this->Update::Run01G(HERO);      // Zmiany logiczne na planszy.
            this->Render::Run01G(HERO);      // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    return;
}


void GreatLoop::MenuVer01() {
    /** Pierwsza wersja Funkcji Sterującej Rozgrywką. */

    int currentChoose = 0;

    this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.

    GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        int InputEvent = this->Input::Run01M(GLOOP, currentChoose);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                          // Czyszczenie, Zerowanie Konsoli.
            this->Render::Run01M(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    return;
}


void DEBUG_KEYBOARD (){
    /** Funkcja Pokazujaca w Konsoli Wcisniete Klawisze. */

    unsigned char x = getch();
    if (x != 224) {
        system("cls");    // Czyszczenie, Zerowanie Konsoli.
        cout << "\n MODE: DEBUG_INPUT \n"
             << "  - no game's running\n\n"
             << " Key Pressed:\n"
             << "  (unsigned char): " << x
             << "  (int): "           << (int)x
             << "\n\n";
    }
}



