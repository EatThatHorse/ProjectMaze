
#include "c_Render"

void AsciiButton (int, string, string, int);



void Render::Run01G (player gammer){
//        for (int col=0; col<30; ++col){
//            cout << "\n\t" << (char)186;
//            for (int verse=0; verse<70; ++verse){
//                cout << renderTab[verse][col];
//            }
//        }
    return;
}

void Render::Run01M (int option){


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


    int zazn = 2;
    int odzn = 0;


    if (option == 0){
        AsciiButton (20,"Nowa Gra",odstep,zazn);
    } else {
        AsciiButton (20,"Nowa Gra",odstep,odzn);
    }
    if (option == 1){
        AsciiButton (20,"Wczytaj",odstep,zazn);
    } else {
        AsciiButton (20,"Wczytaj",odstep,odzn);
    }

    cout << "\n\n";

    if (option == 2){
        AsciiButton (20,"Zamknij",odstep,zazn);
    } else {
        AsciiButton (20,"Zamknij",odstep,odzn);
    }

    cout << "\n\n";

    return;
}





void AsciiButton (int width, string Text, string odstep, int font){

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
    for (int x=0; x<(width-3-Text.length()) ;x++)
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
