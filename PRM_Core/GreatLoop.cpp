
#include "c_GreatLoop"


GreatLoop::GreatLoop (){    // KONSTRUKTOR
    this->GLOOP = true;
    Execute();
}


void GreatLoop::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow.
        Metoda wywolywana w MAIN() przez konstruktor.
    */
    Game Main_GAME(&this->GLOOP); // Game Exec
    Menu Main_MENU(&this->GLOOP); // Menu Exec

    // MAIN PRZYSTOSOWANY DO PRACY Z KODEM.    CLEAN IT AFTER. LEAVE IT ENABLED.
    MAIN_TEST_DEBUG();

    // METODY WYWOLANIA PROGRAMU, MENU LUB GRY.
    Main_MENU.Execute();
    if (this->GLOOP)
        Main_GAME.Execute();


    return;
}


void GreatLoop::MAIN_TEST_DEBUG() {
    /** WorkSpace Przygotowany Specjalnie do TWOICH Testow.
        Traktuj go jak zwyklego MAIN'A.
        Domyslnie:
         - Jest Wywolywany
         - Nie Posiada Instrukcji
        Po zakonczeniu pracy pozostaw go w stanie w jakim go zastales.
    */
     //DEBUG_KEYBOARD ();   // You Can Tast It. If You Want.


}



