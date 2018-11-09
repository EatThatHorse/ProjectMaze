
    #include "PrMaze"       // Plik Zawierajacy Deklaracje Projektowego Namespace'a.

    #include <conio.h>      // getch / kbhit



    int PrM::Input (){
        /** Zakaz Uzywania Cout, Nie zadziala
            Wynika to z sposobu dzialania getch() i system("cls")   */

        unsigned char znak;
        znak = getch();   // Oczekiwanie na Input.
        if (znak == 224) return 224;    // PUNKT KONTROLNY - Wynika z dzialania getch().

        // Obsluga Input Eventow: -------------------------------------
        if (znak == 27) {       // ESCAPE
            return znak;
        }
        if (znak == 32) {       // SPACJA
            return znak;
        }
        if (znak == 13) {       // ENTER
            return znak;
        }
        if (znak == 75){        // ← (left)
            return znak;
        }
        if (znak == 77){        // → (right)
            return znak;
        }
        if (znak == 72){        // ↑ (up)
            return znak;
        }
        if (znak == 80) {       // ↓ (down)
            return znak;
        }

        return 224;     // 224 - z decyzji [Kacu]: kod bledu nakazujacy robic nic.
    }
