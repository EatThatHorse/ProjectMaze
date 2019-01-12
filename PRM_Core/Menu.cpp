
#include "c_Menu"



Menu::Menu(bool* T_GLOOP){
    this->GLOOP = T_GLOOP;
}



void Menu::Execute(){
    /** Czynnosci wykonywane przez Program.
        Obsluga wiekszosci bledow Tutaj.
    */
    // METODY WYWOLANIA MENU.
    MenuVer01();

    return;
}



void Menu::MenuVer01() {
    /** Pierwsza wersja Menu. */

    //menu EXEC;
    int currentChoose = 0;

    //this->Render::Run01M(currentChoose);    // PreRender, Rysowanie Pierwszej Klatki.
    this->ShowMENU(currentChoose);
    this->enterGame = false;
    *GLOOP = true;   // GREAT LOOP - Wykonywana tak długo jak działa program.

    while (*GLOOP && !enterGame) {
        //  Jedno Wykonanie Petli = Jeden Input, Jeden Klawisz = Jedna Klatka, Jeden Frame.

//        int InputEvent = this->menu::Input(GLOOP, currentChoose);
        int InputEvent = this->Input(currentChoose);

        if (InputEvent != 224) {    // unikamy zdarzenia 224. Zawsze. Wynika to z dzialania [getch] <conio.h>
            system("cls");         // Czyszczenie, Zerowanie Konsoli.
            this->ShowMENU(currentChoose);
            //this->ShowMENU(currentChoose);    // Render. Aktywowany Tyle razy ile cokolwiek się zmieni na ekranie.
        }
    }
    return;
}




/// STUFF

#include "c_menu"



void Menu::AsciiButton (int width, string Text, string odstep, int font){

    char ppo,ppi,lgr,pgr,ldr,pdr;

    if (font == 0){
        ppo = 196;     //ppo - pojedynzca pozioma
        ppi = 179;     //ppi - pojedyncza pionowa
        lgr = 218;     //lgr - lewy górny róg
        pgr = 191;     //pgr - prawy górny róg
        ldr = 192;     //ldr - lewy dolny róg
        pdr = 217;     //pdr - prawy dolny róg
    } else if (font == 1) {
        ppo = 205;     //ppo - podw. pozioma
        ppi = 186;     //ppi - podw. pionowa
        lgr = 201;     //lgr - lewy górny róg
        pgr = 187;     //pgr - prawy górny róg
        ldr = 200;     //ldr - lewy dolny róg
        pdr = 188;     //pdr - prawy dolny róg
    } else if (font == 2) {
        ppo = 196;     //ppo - podw. pozioma
        ppi = 179;     //ppi - podw. pionowa
        lgr = 254;     //lgr - lewy górny róg
        pgr = 254;     //pgr - prawy górny róg
        ldr = 254;     //ldr - lewy dolny róg
        pdr = 254;     //pdr - prawy dolny róg
    }



    /// górna kreska------------------------------------
    cout << odstep << lgr;  //lewy górny róg

    for (int x=0; x<(width - 2); ++x)
        cout << ppo;        //pojedyncza pozioma
    cout << pgr << "\n";    //prawy górny róg

    cout << odstep << ppi << " " << Text;        //pojedyncza pionowa
    for (unsigned int x=0; x<(width-3-Text.length()) ;x++)
        cout << " ";
    cout << ppi << "\n";        //pojedyncza pionowa

    ///dolna kreska------------------------------------
    cout << odstep
         << ldr;            //lewy górndolny róg

    for (int x=0; x<(width - 2); ++x) {
        cout << ppo;    //pojedyncza pozioma
    }
    cout << pdr         //prawy dolny róg
         << "\n";       //debug pierwszego wiersza bocznych kresek

    return;
}







void Menu::ShowMENU(int& option){

    string odstep = "     ";

    cout << "\n\n"
         << odstep << " _____           _           _     __  __                        \n"
         << odstep << "|  __ \\         (_)         | |   |  \\/  |                     \n"
         << odstep << "| |__) |___ ___  _  ___  ___| |_  | \\  / | __ _ _______         \n"
         << odstep << "|  ___/ __ / _ \\| |/ _ \\/ __| __| | |\\/| |/ _` |_  / _ \\     \n"
         << odstep << "| |   | | | (_) | |  __/ (__| |_  | |  | | (_| |/ /  __/         \n"
         << odstep << "|_|   |_|  \\___/| |\\___|\\___|\\__| |_|  |_|\\__,_/___\\___|   \n"
         << odstep << "               _/ |                                              \n"
         << odstep << "              |__/                                               \n";

    cout << "\n\n";


    int zazn = 1;
    int odzn = 0;

    if (option < 0){
        option = 2;
    }

    if (option > 2){
        option = 0;
    }

    if (option == 0){
        AsciiButton (20,"Nowa Gra",odstep,zazn);
    } else {
        AsciiButton (20,"Nowa Gra",odstep,odzn);
    }


//    if (option == 1){
//        AsciiButton (20,"Wczytaj",odstep,zazn);
//    } else {
//        AsciiButton (20,"Wczytaj",odstep,odzn);
//    }

    if (option == 1){
        AsciiButton (20,"Tabela Wynikow",odstep,zazn);
    } else {
        AsciiButton (20,"Tabela Wynikow",odstep,odzn);
    }


   // cout << "\n\n";

    if (option == 2){
        AsciiButton (20,"Zamknij",odstep,zazn);
    } else {
        AsciiButton (20,"Zamknij",odstep,odzn);
    }



    cout << "\n\n";

    return;
}

void Menu::Write(int& choose){

    if (choose == 0){
        system("cls");
        cout<<"Nowa Gra! \n";
        getchar();
        enterGame = true;
    }
//    if (choose == 1){
//        system("cls");
//        cout<<"Wczytaj! \n";
//        getchar();
//    }
    if (choose == 1){
        system("cls");
        cout<<"Tabela ! \n";
        Stats Data;
        Data.Read();
        getchar();
    }
    if (choose == 2){
        system("cls");
        cout<<"KONIEC! \n";
        getchar();
        *GLOOP = false;
    }

}

int Menu::Input(int& option){
    /** Zakaz Uzywania Cout, Nie zadziala
        Wynika to z sposobu dzialania getch() i system("cls")   */

    unsigned char znak;
    znak = getch();   // Oczekiwanie na Input.
    if (znak == 224) return 224;    // PUNKT KONTROLNY - Wynika z dzialania getch().

    // Obsluga Input Eventow: -------------------------------------
    if (znak == 27) {       // ESCAPE
        if (option==2)
            *GLOOP = false;
        else
            option = 2;
        return znak;
    }
    if (znak == 13) {         // ENTER
        Write(option);
        return znak;
    }

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






