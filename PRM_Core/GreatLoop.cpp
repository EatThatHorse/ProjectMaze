
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

    MAIN_TEST_DEBUG();

    //GameVer01();
    //GameVer02();
    //GrzyboVer01();



    #endif
    return;
}


#include "../c_Container"
#include <iostream>
using namespace std;


void GreatLoop::MAIN_TEST_DEBUG() {



/*

    Container testTab;

    // TEST 0 ----------------------------------
    cout << "\n TEST 0 - konstruktor kontenera. Brak modyfikacji."
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 1 ----------------------------------
    testTab.AddRecord (2,2,'A');
    testTab.AddRecord (3,4,'B');
    testTab.AddRecord (6,7,'C');
    testTab.AddRecord (8,5,'D');
    cout << "\n TEST 1 - Dodawanie 4 Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 2 --------------------------------------------------------------------
    testTab.DeleteLastRecord ();
    testTab.DeleteLastRecord ();
    cout << "\n TEST 2 - Usuwanie 2 Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 3 --------------------------------------------------------------------
    testTab.AddRecord (0,0,'K');
    testTab.AddRecord (0,0,'K');
    testTab.AddRecord (0,0,'K');
    cout << "\n TEST 3 - Ponowne Dodawanie 3 Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 4 --------------------------------------------------------------------
    testTab.DeleteKontener();
    cout << "\n TEST 4 - Kasowanie Wszystkich Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 5 --------------------------------------------------------------------
    testTab.DeleteLastRecord ();
    testTab.DeleteLastRecord ();
    testTab.DeleteLastRecord ();
    testTab.DeleteLastRecord ();
    testTab.DeleteLastRecord ();
    cout << "\n TEST 5 - Kasowanie Jeszcze 5, Nie Istniejacych Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

    // TEST 6 --------------------------------------------------------------------
    testTab.AddRecord (2,2,'A');
    testTab.AddRecord (3,4,'B');
    testTab.AddRecord (0,0,'K');
    testTab.AddRecord (7,9,'Z');
    cout << "\n TEST 6 - Dodawanie Do Pustego Kontenera 4 Rekordow"
         << "\n --------------------------------------------------------------------\n";
    testTab.ShowKontener(); cout << "\n";

*/


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
    //        this->Render::Run01G(HERO);      // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    return;
}


void GreatLoop::GrzyboVer01() {

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



