#ifdef C_DROOM__DT

char tab[34][70]; //pierwszy nawias to wiersze, drugi to kolumny

bool north = true;
bool south = false;
bool east = true;
bool west = true;

char ppo = 196;     //ppo  - pojedynzca pozioma
char ppi = 179;     //ppi - pojedyncza pionowa
char lgr = 218;     //lgr - lewy górny róg
char pgr = 191;     //pgr - prawy górny róg
char ldr = 192;     //ldr - lewy dolny róg
char pdr = 217;     //pdr - prawy dolny róg

string margin29 = "                             ";

void ClearLine(char** tab, int wierszyk){
///ka¿da linijka sciany----------------------------------------------
	tab [wierszyk][0] = ' ';
	tab [wierszyk][1] = ppi;

	for (int x=2; x<=67; ++x)
		tab [wierszyk][x] = ' ';

	tab [wierszyk][68] = ppi;
	tab [wierszyk][69] = ' ';

}

void RenderRoom(char** tab){

	// wyswietla 36 wiersze o 70 kolumnach (ktore nie sa w kolejnych wierszach klonami)
	// wyswietla wszystkie elementy tablicy 36x70
	for (int wiersz=0; wiersz<36; ++wiersz){

        cout << "\n" << margin29 ;

		for (int kolumny=0; kolumny<70; ++kolumny){
			cout << tab[wiersz][kolumny];
		}
	}

}


void ClearRoom (char** tab){

	// nadanie wartoœci elementom w tablicy kurwa!!!! CHAR
	for (int wiersz=0; wiersz<35; ++wiersz){
		for (int kolumny=0; kolumny<70; ++kolumny){
			tab [wiersz][kolumny] = ' '; ///jedna ciapka( ' ) to char, dwuciapek( " ) to string (const char*)
		}
	}

	if (north){
///linijka pierwsza----------------------------------------------
        tab [0][33] = ppi;
        tab [0][36] = ppi;

///druga linijka----------------------------------------------
        tab [1][1] = lgr;
        for (int x=2; x<=32; ++x)
            tab [1][x] = ppo;

        tab [1][33] = pdr;

        tab [1][36] = ldr;

        for (int x=37; x<=67; ++x)
            tab [1][x] = ppo;

        tab [1][68] = pgr;

    }else{
///linijka druga zamkniete----------------------------------------------
        tab [1][1] = lgr;

        for (int x=2; x<=67; ++x)
            tab [1][x] = ppo;

        tab [1][68] = pgr;
    }
///sciany pierwsza para----------------------------------------------
    for (int x=2; x<=15; ++x)
        ClearLine(tab, x);

///drzwi east west otwarte----------------------------------------------
    if  (east && west){
        tab [16][0] = ppo;
        tab [16][1] = pdr;
        tab [16][68] = ldr;
        tab [16][69] = ppo;

        tab [19][0] = ppo;
        tab [19][1] = pgr;
        tab [19][68] = lgr;
        tab [19][69] = ppo;
    }

/// drzwi east otwarte west zamkniete----------------------------------------------
    if (east && !west){
        tab [16][0] = ppo;
        tab [16][1] = pdr;
        tab [16][68] = ppi;

        tab [17][68] = ppi;

        tab [18][68] = ppi;

        tab [19][0] = ppo;
        tab [19][1] = pgr;
        tab [19][68] = ppi;

    }
///drzwi east zamkniete west otwarte----------------------------------------------
    if (!east && west){
        tab [16][0] = ppo;
        tab [16][1] = pdr;
        tab [16][68] = ppi;

        tab [17][68] = ppi;

        tab [18][68] = ppi;

        tab [19][0] = ppo;
        tab [19][1] = pgr;
        tab [19][68] = ppi;
    }
///drzwi east zamkniete west zamkniete----------------------------------------------
    if(!east && !west){
        tab [16][1] = ppi;
        tab [16][68] = ppi;

        tab [17][1] = ppi;
        tab [17][68] = ppi;

        tab [18][1] = ppi;
        tab [18][68] = ppi;

        tab [19][1] = ppi;
        tab [19][68] = ppi;
    }

///sciany druga para----------------------------------------------
    for (int x=20; x<=33; ++x)
        ClearLine(tab, x);

///przedostatnia linijka otwarta----------------------------------------------
    if (south){

        tab [34][1] = ldr;
        for (int x=2; x<=32; ++x)
            tab [34][x] = ppo;

        tab [34][33] = pgr;
        tab [34][35] = lgr;

        for (int x=36; x<=67; ++x)
            tab [34][x] = ppo;

        tab [34][68] = pdr;

        tab [35][33] = ppi;
        tab [35][35] = ppi;

    }else{
        tab [34][1] = ldr;
        for (int x=2; x<=67; ++x)
            tab [34][x] = ppo;

        tab [34][68] = pdr;
    }
}

void AsciiBox (int width, int height, string odstep){
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
}

/*
    char** tab;
    int ROWS = 36;
    int COLUMNS = 70;


    tab = new char*[ROWS];


        /// Etap drugi:
    for(int row=0; row<ROWS; ++row)  // Pêtla przeskakuje przez wszystkie 35 wiersze. Indeksy Od 0 do 34
        tab[row] = new char[COLUMNS];


    ClearRoom(tab);
    RenderRoom(tab);

*/


// string margin29 = "                             ";
//   AsciiBox(70,8, margin29);
//    AsciiBox(70,30, margin29);
//    AsciiRoom(true, false, true, false);
//    AsciiBox (70, 3,  margin29);





#endif // C_DROOM__DT
