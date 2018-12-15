
#include "c_Input"


//_________________________________________________________________________________________________________________
//───────────────────────────────────────────────────────────────────────────────────────────────────────────────── G-01
int Input::Run01G(player& HERO){
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
        HERO.Move(LEFT);
        return znak;
    }
    if (znak == 77){        // → (right)
        HERO.Move(RIGHT);
        return znak;
    }
    if (znak == 72){        // ↑ (up)
        HERO.Move(UP);
        return znak;
    }
    if (znak == 80) {       // ↓ (down)
        HERO.Move(DOWN);
        return znak;
    }
    return 224;     // 224 - z decyzji [Kacu]: kod bledu nakazujacy robic nic.
}

//_________________________________________________________________________________________________________________
//───────────────────────────────────────────────────────────────────────────────────────────────────────────────── M-01


//int Input::Run01M(bool& gloop, int& option){
    /** Zakaz Uzywania Cout, Nie zadziala
        Wynika to z sposobu dzialania getch() i system("cls")   */
/*
    unsigned char znak;
    znak = getch();   // Oczekiwanie na Input.
    if (znak == 224) return 224;    // PUNKT KONTROLNY - Wynika z dzialania getch().

    // Obsluga Input Eventow: -------------------------------------
    if (znak == 27) {       // ESCAPE
        if (option==2)
            gloop = false;
        else
            option = 2;
        return znak;
    }
    if (znak == 13) {

        return znak;
    }      // ENTER

    if (znak == 72) {       // ↑ (up)
        --option;
        return znak;
    }

    if (znak == 80) {       // ↓ (down)
        ++option;
        return znak;
    }


    return 224;     // 224 - z decyzji [Kacu]: kod bledu nakazujacy robic nic.
}*/
