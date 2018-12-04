
#include <windows.h>
#include <iostream>
using std::cout;
using std::cin;
using std::string;


/**
Dzień dobry. Mam na imię mikołaj.
Wymiary okien:
    - Marginesy: 29
    - Górne okno: 70x8
    - Dolne okno: 70x30

    186 podw. pionowa               ║
    205 podw. pozioma               ═
    201 podw. lewy górny róg        ╔
    187 podw. prawy górny róg       ╗
    200 podw. lewy dolny róg        ╚
    188 podw. prawy dolny róg       ╝

                                    ╦
                                    ╬
                                    ╣
                                    ╠
                                    ╩

    196 poj pozioma                 │
    179 poj pionowa                 ─
    218 lewy górny róg              ┌
    191 prawy górny róg             ┐
    192 lewy dolny róg              └
    217 prawy dolny róg             ┘

                                    ┬
                                    ┼
                                    ┤
                                    ├
                                    ┴

                                    █
                                    ▓
                                    ▒
                                    ░

                                    ▀
                                    ■
                                    ▄*/

int tab[30][66];

void AsciiBox (int width, int height, string odstep){

    char ppo = 196;     //ppo  - pojedynzca pozioma
    char ppi = 179;     //ppi - pojedyncza pionowa
    char lgr = 218;     //lgr - lewy górny róg
    char pgr = 191;     //pgr - prawy górny róg
    char ldr = 192;     //ldr - lewy dolny róg
    char pdr = 217;     //pdr - prawy dolny róg


    /// górna kreska------------------------------------
    cout << odstep
         << lgr;            //lewy górny róg

    for (int x=0; x<(width - 2); ++x) {
        cout << ppo;        //pojedyncza pozioma
    }
    cout << pgr             //prawy górny róg
         << "\n";           //debug pierwszego wiersza bocznych kresek



    for (int x=0 ;x<height ;++x) {       //boczne kreski górnej ramki
        cout << odstep
             << ppi;        //pojedyncza pionowa
        for (int x=0; x<(width -2) ;x++) {
            cout << " ";
        }
        cout << ppi         //pojedyncza pionowa
             << "\n";
    }

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

///AsciRoom-------------------------------------------------------------------------------
void AsciiRoom (bool north, bool south, bool east, bool west){
    char ppo = 196;     //ppo  - pojedynzca pozioma
    char ppi = 179;     //ppi - pojedyncza pionowa
    char lgr = 218;     //lgr - lewy górny róg
    char pgr = 191;     //pgr - prawy górny róg
    char ldr = 192;     //ldr - lewy dolny róg
    char pdr = 217;     //pdr - prawy dolny róg

    string margin29 = "                             ";

if (north){
///gorne drzwi otwarte----------------------------------------------
    cout << margin29;

    for (int x=0; x<32; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<32; ++x)
        cout << " ";
    cout << margin29;

    cout << "\n";
///krawedz gorna + drzwi----------------------------------------------
    cout << margin29
         << lgr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pdr;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ldr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pgr
         << margin29;

    cout << "\n";
    } else {
///gorne drzwi zamkniete----------------------------------------------
    cout << margin29;

    for (int x=0; x<38; ++x)
        cout << " ";

    cout << margin29;

    cout << "\n";
///krawedz gorna + drzwi----------------------------------------------
    cout << margin29
         << lgr;

    for (int x=0; x<66; ++x)
        cout << ppo;
    cout << pgr;

    cout << margin29;

    cout << "\n";
    }
///sciany----------------------------------------------
    for (int x=0; x<14; ++x){
        cout << margin29
             << ppi;

         for (int x=0; x<66; ++x)
            cout << " ";

         cout << ppi
              << margin29;
         cout << "\n";
    }
if (east){
///drzwi boczne----------------------------------------------
    if (west){
        cout << "                            "
             << ppo
             << pdr;

        for (int x=0; x<66; ++x)
                cout << " ";

        cout << ldr
             << ppo
             << "                            ";

        for (int x=0; x<2; ++x)
            cout << "\n";

        cout << "                            "
             << ppo
             << pgr;

        for (int x=0; x<66; ++x)
                cout << " ";

        cout << lgr
             << ppo
             << "                            ";
        cout << "\n";
    } else{
        cout << margin29
             << ppi;

        for (int x=0; x<66; ++x)
                cout << " ";

        cout << ldr
             << ppo
             << "                            "
             << "\n";

        for (int x=0; x<2; ++x){
            cout << margin29
                 << ppi
                 << "\n";
        }

        cout << margin29
             << ppi;

        for (int x=0; x<66; ++x)
                cout << " ";

        cout << lgr
             << ppo
             << "                            "
             << "\n";
    }
} else {
///drzwi boczne zamkniete----------------------------------------------
   if (west){
    cout << "                            "
         << ppo
         << pdr;

    for (int x=0; x<66; ++x)
        cout << " ";

    cout << ppi
         << margin29
         << "\n";

    for (int x=0; x<2; ++x){
        cout << margin29;

        for (int x=0; x<66; ++x)
            cout << " ";

        cout << ppi
             << margin29
             << "\n";
        }
    cout << "                            "
         << ppo
         << pgr;

    for (int x=0; x<66; ++x)
            cout << " ";

    cout << ppi
         << margin29
         << "\n";

    }else{
    for (int x=0; x<4; ++x){
        cout << margin29
             << ppi;

        for (int x=0; x<66; x++)
            cout << " ";

        cout << ppi
             << margin29
             << "\n";

        }
    }


}
///sciany----------------------------------------------
    for (int x=0; x<14; ++x){
        cout << margin29
             << ppi;

         for (int x=0; x<66; ++x)
            cout << " ";

         cout << ppi
              << margin29;
         cout << "\n";
    }
if (south){
    ///krawedz dolna + drzwi otwarte----------------------------------------------
    cout << margin29
         << ldr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pgr;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << lgr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pdr
         << margin29;

    cout << "\n";

///dolne drzwi----------------------------------------------
    cout << margin29;

    for (int x=0; x<32; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<32; ++x)
        cout << " ";

    cout << margin29;

    cout << "\n";
} else {
       ///krawedz dolna + drzwi zamkniete----------------------------------------------
    cout << margin29
         << ldr;

    for (int x=0; x<66; ++x)
        cout << ppo;

    cout << pdr
         << margin29;

    cout << "\n";

///dolne drzwi----------------------------------------------
    cout << margin29;

    for (int x=0; x<38; ++x)
        cout << " ";

    cout << margin29;

    cout << "\n";
    }


/*///gorne drzwi otwarte----------------------------------------------
    cout << margin29;

    for (int x=0; x<32; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<32; ++x)
        cout << " ";

    cout << margin29;

    cout << "\n";
///krawedz gorna + drzwi----------------------------------------------
    cout << margin29
         << lgr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pdr;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ldr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pgr
         << margin29;

    cout << "\n";

///sciany----------------------------------------------
    for (int x=0; x<14; ++x){
        cout << margin29
             << ppi;

         for (int x=0; x<66; ++x)
            cout << " ";

         cout << ppi
              << margin29;
         cout << "\n";
    }



///drzwi boczne----------------------------------------------
    cout << "                            "
         << ppo
         << pdr;

    for (int x=0; x<66; ++x)
            cout << " ";

    cout << ldr
         << ppo
         << "                            ";

    for (int x=0; x<2; ++x)
        cout << "\n";

    cout << "                            "
         << ppo
         << pgr;

    for (int x=0; x<66; ++x)
            cout << " ";

    cout << lgr
         << ppo
         << "                            ";
    cout << "\n";

///sciany----------------------------------------------
    for (int x=0; x<14; ++x){
        cout << margin29
             << ppi;

         for (int x=0; x<66; ++x)
            cout << " ";

         cout << ppi
              << margin29;
         cout << "\n";
    }

///krawedz dolna + drzwi----------------------------------------------
    cout << margin29
         << ldr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pgr;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << lgr;

    for (int x=0; x<31; ++x)
        cout << ppo;
    cout << pdr
         << margin29;

    cout << "\n";

///dolne drzwi----------------------------------------------
    cout << margin29;

    for (int x=0; x<32; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<2; ++x)
        cout << " ";
    cout << ppi;

    for (int x=0; x<32; ++x)
        cout << " ";

    cout << margin29;

    cout << "\n";
*/
}

// [Kacu] Oj tabulacja motzno.
int main (){
/*    char ppo = 196;     //ppo  - pojedynzca pozioma
    char ppi = 179;     //ppi - pojedyncza pionowa
    char lgr = 218;     //lgr - lewy górny róg
    char pgr = 191;     //pgr - prawy górny róg
    char ldr = 192;     //ldr - lewy dolny róg
    char pdr = 217;     //pdr - prawy dolny róg

    string margin29 = "                             ";
*/
    string margin29 = "                             ";

//   AsciiBox(70,8, margin29);
//    AsciiBox(70,30, margin29);
    AsciiRoom(true, false, true, false);

/*
/// górna kreska górnej ramki ------------------------------------
    cout << margin29;
    cout << lgr;        //lewy górny róg

    for (int x=0 ;x<68 ;++x) {
        cout << ppo;    //pojedyncza pozioma
    }
    cout << pgr;        //prawy górny róg

    cout << "\n";       //debug pierwszego wiersza bocznych kresek

    for (int x=0 ;x<8 ;++x) {       //boczne kreski górnej ramki
        cout << margin29;
        cout << ppi;    //pojedyncza pionowa
        for (int x=0; x<68 ;x++) {
            cout << " ";
        }
        cout << ppi;    //pojedyncza pionowa
        cout << "\n";
    }

/// dolna kreska górnej ramki ------------------------------------
    cout << margin29;
    cout << ldr;        //lewy dolny róg
    for (int x=0 ;x<68 ;++x) {
        cout << ppo;    //pojedyncza pozioma
    }
    cout << pdr;        //prawy dolny róg
    cout << "\n";       //przerwa między ramkami

//####################################################################################################################
*/
/*
    /// górna kreska dolnej ramki ------------------------------------
    cout << margin29;
    cout << (char) lgr; //lewy górny róg
    for (int x=0 ;x<68 ;++x) {
        cout << ppo;    //pionowa pojdyncza
    }
    cout << pgr;        //prawy górny róg

    cout << "\n";       //debug pierwszego wiersza bocznych kresek

    ///boczne kreski dolnej ramki ------------------------------------
    for (int x=0 ;x<30 ;++x) {
        cout << margin29;
        cout << ppi;    //pojedyncza pionowa
        for (int x=0; x<68 ;x++) {
            cout << " ";
        }
        cout << ppi;    //pojedyncza pionowa

        cout << "\n";
    }

    /// dolna kreska dolnej ramki ------------------------------------
    cout << margin29;

    cout << ldr;        //lewy dolny róg
    for (int x=0 ;x<68 ;++x) {
        cout << ppo;    //pojedyncza pozioma
    }
    cout << pdr;        //prawy dolny róg

    cout << "\n";

*/
    system("pause");
    return 0;
}



/** TO DO: [nie zaczynaj kolejnych krokow az nie ukonczysz poprzednich]

    1) - Spraw, by main wygladal tak↓, Jednoczesnie robil to samo co teraz (rysowal dwie ramki).
            int main (){
                AsciiBox (70,8,margin29);
                AsciiBox (70,30,margin29);

                system("pause");
                return 0;
            }
      - Oznacza to ze masz napisac funkcje o nazwie AsciiBox(int width, int height, string odstep)
        skladnia funkcji:
        TYP_ZWRACANY  NAZWA_FUNKCJI  (OPCJONALNE_ARGUMENTY_FUNKCJI) { INSTRUKCJE/CIALO_FUNKCJI }
      - Do napisania funkcji wykorzystaj to co juz napisales. To bedzie kopiuj-wklej + kilka modyfikacji.

    2) - Zoptymalizuj swoja nowa funkcje. Kilka tipow:
          - cout to funkcja, kazde wywolanie funkcji kosztuje.
            wiec lepiej jest pszeslac cout'owi wiekszy strumien niz odpalic kilka coutow.
            Przyklad:   NIE
                cout << margin29;
                cout << ppi;
            Przyklad:   TAK
                cout << margin29 << ppi;
          - Pamietaj o symbolu konca instrukcji [;], on pokazuje gdzie instrukcja sie konczy. Jest tylko jeden na instrukcje.

    3) - To teraz nowa funkcja AsciiRoom. Ta narysuje pokoj.
         Wymiary i ostateczny wyglad w pliku [instrukcje AsciiRoom.png]

    4) - Ulepszenie funkcji AsciiRoom. Dodanie tablicy znakow.

    5) - Ulepszenie funkcji AsciiRoom. Rysuje drzwi lub nie, w zaleznosci od podanych wartosci.
         Raz beda wszystkie 4, raz tylko dwa, raz trzy... Wiecej mozliwosci customizacji.
*/














