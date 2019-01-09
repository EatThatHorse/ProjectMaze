
#include "c_Input"


//_________________________________________________________________________________________________________________
//───────────────────────────────────────────────────────────────────────────────────────────────────────────────── G-01
int Input::Run01G(maze& HEAD){
    /** Zakaz Uzywania Cout, Nie zadziala
        Wynika to z sposobu dzialania getch() i system("cls")
    */
    player& HERO = HEAD.HERO;


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
    if (znak==13 || znak==101 || znak==69) {      // ( ENTER || e || E )
        if (HERO.Action() == 1)
            if (HEAD.HERO.roomPos == HEAD.lastRoomAdded)
                HEAD.AddFloor();
        return znak;
    }
    if (znak==75 || znak==97 || znak==65){        // ( ← (left) || a || A )
        HERO.Move(LEFT);
        return znak;
    }
    if (znak==77 || znak==100 || znak==68){       // ( → (right) || d || D )
        HERO.Move(RIGHT);
        return znak;
    }
    if (znak==72 || znak==119 || znak==65){       // ( ↑ (up) || w || W )
        HERO.Move(UP);
        return znak;
    }
    if (znak==80 || znak==115 || znak==83) {      // ( ↓ (down) || s || S )
        HERO.Move(DOWN);
        return znak;
    }
    return 224;     // 224 - z decyzji [Kacu]: kod bledu nakazujacy robic nic.
}

//_________________________________________________________________________________________________________________
//───────────────────────────────────────────────────────────────────────────────────────────────────────────────── M-01


int Input::Run01M(bool& gloop, int& option){
    /** Zakaz Uzywania Cout, Nie zadziala
        Wynika to z sposobu dzialania getch() i system("cls")   */

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
}
