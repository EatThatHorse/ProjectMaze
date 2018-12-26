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



void RepairArg(int* posX1,int* posY1,int* posX2,int* posY2){
    /** Anchor1 Nigdy nie jest POD lub z PRAWEJ Anchora2.
        Anchor1 moze miec rowne wartosci co Anchor2.
            An1(X,Y) ■────┐
                     │/ / │
                     │ / /│
                     └────■ (X,Y)An2

        An1  <==>  Anchor_1  <==>  ( posX1, posY1 )
        An2  <==>  Anchor_2  <==>  ( posX2, posY2 )
    */

    bool Xtmp, Ytmp;
    Xtmp = Ytmp = true;

    // ---------------------------------------------------------------------------------------------
    // Warunki aby An1 nie wyszedł poza rysunek
    if (posX1 != 0){
        if (*posX1 <= 1){ *posX1 = 2;  }  // An1 over/behind LEFT wall
        if (*posX1 > 67){ *posX1 = 67; }  // An1 over/behind RIGHT wall
    }else{ Xtmp = false;}

    if (posY1 != 0){
        if (*posY1 <= 1){ *posY1 = 2;  }  // An1 over/behind UPPER wall
        if (*posY1 > 33){ *posY1 = 33; }  // An1 over/behind BOTTOM wall
    }else{ Ytmp = false;}
    // ---------------------------------------------------------------------------------------------
    // Warunki aby An2 nie wyszedł poza rysunek
    if (posX2 != 0){
        if (*posX2 <= 1){ *posX2 = 2;  }  // An2 over/behind LEFT wall
        if (*posX2 > 67){ *posX2 = 67; }  // An2 over/behind RIGHT wall
    }else{ Xtmp = false;}

    if (posY2 != 0){
        if (*posY2 <= 1){ *posY2 = 2;  }  // An2 over/behind UPPER wall
        if (*posY2 > 33){ *posY2 = 33; }  // An2 over/behind BOTTOM wall
    }else{ Ytmp = false;}
    // ---------------------------------------------------------------------------------------------
    if (Xtmp) {
        // testSUM_X Dodatnie -> An2 jest po PRAWEJ od An1    [GOOD - 1]
        // testSUM_X Ujemne   -> An2 jest po LEWEJ od An1     [BAD - 0]
        int testSUM_X;
        testSUM_X = *posX2 - *posX1;

        if(testSUM_X < 0) {     /** 0 1 **/// An2 jest po LEWEJ od An1
            int tmp = *posX1;
            *posX1 = *posX2;
            *posX2 = tmp;
        }
    }
    // ---------------------------------------------------------------------------------------------
    if (Ytmp) {
        // testSUM_Y Dodatnie -> An2 jest POD An1     [GOOD - 1]
        // testSUM_Y Ujemne   -> An2 jest NAD An1     [BAD - 0]
        int testSUM_Y;
        testSUM_Y = *posY2 - *posY1;

        if(testSUM_Y < 0) {     /** 1 0 **/// An2 jest NAD An1
            int tmp = *posY1;
            *posY1 = *posY2;
            *posY2 = tmp;
        }
    }
    // ---------------------------------------------------------------------------------------------
}


