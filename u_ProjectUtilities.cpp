#include "u_ProjectUtilities"






void DEBUG_KEYBOARD (){
    /** Funkcja Pokazujaca w Konsoli Wcisniete Klawisze. */
    int exit = 0;
    cout << "\n MODE: DEBUG_KEYBOARD"
         << "\n  - no game's running"
         << "\n\n PRESS ANY BUTTON...";

    while (exit != 2){
        unsigned char x = getch();
        if (x != 224) {
            if (x == 27) ++exit;
            else         exit=0;
            system("cls");    // Czyszczenie, Zerowanie Konsoli.
            cout << "\n MODE: DEBUG_KEYBOARD"
                 << "\n  - no game's running"
                 << "\n\n Key Pressed:\n"
                 << "  (unsigned char): " << x
                 << "  (int): "           << (int)x
                 << "\n\n\n [PRESS ESC TWICE IN A ROW TO EXIT!]\n\n";
        }
    }
}


