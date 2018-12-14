
#include "c_GreatLoop"


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

    MAIN_TEST_DEBUG();

    //GameVer01();
    //GameVer02();
    GrzyboVer01();





    #endif
    return;
}

    #include <iostream>
    using namespace std;
void GreatLoop::MAIN_TEST_DEBUG() {

    cout << "test main";
}

void GreatLoop::GameVer01() {
    /** Pierwsza wersja Funkcji Steruj¹cej Rozgrywk¹. */

    player HERO;

    GLOOP = true;           // GREAT LOOP - Wykonywana tak d³ugo jak dzia³a program.
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
    /** Pierwsza wersja Funkcji Steruj¹cej Rozgrywk¹. */

    player HERO;

    GLOOP = true;           // GREAT LOOP - Wykonywana tak d³ugo jak dzia³a program.
    while (GLOOP) {
        //   Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        int InputEvent = this->Input::Run01G(HERO);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");                  // Czyszczenie, Zerowanie Konsoli.
            this->Update::Run01G(HERO);      // Zmiany logiczne na planszy.
    //        this->Render::Run01G(HERO);      // Render. Aktywowany Tyle razy ile cokolwiek siê zmieni na ekranie.
        }
    }
    return;
}


void GreatLoop::GrzyboVer01() {

    /** Pierwsza wersja Funkcji Steruj¹cej Rozgrywk¹. */

    menu EXEC;

    int currentChoose = 0;


    //this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.
    EXEC.ShowMENU(currentChoose);
    GLOOP = true;   // GREAT LOOP - Wykonywana tak d³ugo jak dzia³a program.
    while (GLOOP) {
        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

        //int InputEvent = this->menu::Input(GLOOP, currentChoose);
        int InputEvent = EXEC.Input(GLOOP, currentChoose);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");         // Czyszczenie, Zerowanie Konsoli.
            EXEC.ShowMENU(currentChoose);
            //this->ShowMENU(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek siê zmieni na ekranie.
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



