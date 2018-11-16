
#include "c_GreatLoop"



void DEBUG_INPUT ();





/// DEFINICJE METOD KLASY --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
int GreatLoop::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
        Metoda wywolywana w MAIN().
    */
    int ERRORS;
    // -------------------------------
    ERRORS = GameVer01();
    // -------------------------------

    if (ERRORS == 0) return 0;

    return 0;   // Bez ERROROW.
}


int GreatLoop::GameVer01() {
    /** Pierwsza wersja Funkcji Sterującej Programem. */

    //#define PRM__DEBUG_INPUT    // UnComment To Enable DEBUG_INPUT
    #ifdef PRM__DEBUG_INPUT
    {       /// When Active: No Game is runnig. Just DEBUG_INPUT.
        while(1) DEBUG_INPUT();
    }
    #else   /// When Active: Regular Game runnig.

    player HERO;
    Render RENDER;

    GLOOP = true;           // GREAT LOOP - Wykonywana tak długo jak działa program.
    while (GLOOP) {
        /**   Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.   */

        int InputEvent = this->Input::Run(HERO);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                      // Czyszczenie, Zerowanie Konsoli.
            this->Update::Run(RENDER, HERO);    // Zmiany logiczne na planszy.
            RENDER.Run(HERO);                   // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    #endif
    return 0;
}


void DEBUG_INPUT (){
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



