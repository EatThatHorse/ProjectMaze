
#ifdef C_GREATLOOP__DT


void GreatLoop::GameVerOldTemplate() {  // gameVer02
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



#endif // C_GREATLOOP__DT
