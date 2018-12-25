

#include "c_DesRoom"


//  ____________________________________________________________________________________________________________
//  ############################################################################################################
/// TYMCZASOWA FUNKCJA DO WYWOŁANIA W MAIN




void ko_room_design_EXEC (){
    /** Stary Main w ktorym testowano dzialanie metody Droom::Danger */

/*
    Droom testRoom;
    testRoom.ClearRoom();
    {
        int tmpChan = 30;
        int tmpChan2 = 20;

        testRoom.Danger(2,2,20,10,tmpChan);     //lg
        testRoom.Danger(25,13,43,22,10);        //sr
        testRoom.Danger(2,25,20,35,tmpChan);    // lewy dol rog
        testRoom.Danger(48,2,69,10,tmpChan);    //prawy gor rog
        testRoom.Danger(48,25,69,35,tmpChan);   // prawy dol rog
        testRoom.Danger(25,4,43,10,tmpChan2);   // sr gora
        testRoom.Danger(6,13,20,22,tmpChan2);   // sr lewo
        testRoom.Danger(49,13,63,22,tmpChan2);  // sr prawo
        testRoom.Danger(25,25,43,31,tmpChan2);  // sr dol
    }

    testRoom.RenderRoom();*/

    ///srodek           25,13,43,22,tmpChan
    ///srodek 2x2:      34,17,35,18,100
    ///srodek 4x4:      32,16,36,19,100
    ///srodek 8x8:      31,14,38,21,100
    ///lewy gorny rog:  2,2,20,10,tmpChan
    ///lewy dolny rog:  2,28,15,35,100
    ///prawy gorny rog: 54,2,69,7,100
    ///prawy dolny rog: 54,28,69,35,100
    ///gora srodek :    25,5,43,10,100
    ///lewo srodek :    8,15,20,20,tmpChan
    ///prawo srodek :   49,15,61,20,tmpChan
    ///dol srodek :     25,25,43,30,tmpChan
  /*
    2,2,20,10,tmpChan); //lewo gora rog
    25,13,43,22,tmpChan); //sr
    2,25,20,35,tmpChan); // lewy dol rog
    48,2,69,10,tmpChan); //prawy gor rog
    48,25,69,35,tmpChan); // prawy dol rog
    25,4,43,10,tmpChan); // sr gora
    6,13,20,22,tmpChan); // sr lewo
    49,13,63,22,tmpChan);// sr prawo
    25,25,43,31,tmpChan); // sr dol
*/
}





//  ____________________________________________________________________________________________________________
//  ############################################################################################################


//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
/// KONSTRUKTOR
DesRoom::DesRoom() {

    this->b_north = 0;
    this->b_south = 0;
    this->b_west =  0;
    this->b_east =  0;

    this->tab = new char*[ROWS];
    for(int row=0; row<ROWS; ++row)  // Petla przeskakuje przez wszystkie 35 wiersze. Indeksy Od 0 do 34
        this->tab[row] = new char[COLUMNS];

}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
/// METODY
void DesRoom::RenderRoom(){
	/** Wyswietla 36 wiersze o 70 kolumnach (ktore nie sa w kolejnych wierszach klonami)
        wyswietla wszystkie elementy tablicy 36x70
	*/
	for (int wiersz=0; wiersz<36; ++wiersz){
        cout << "\n" << margin29 ;
		for (int kolumny=0; kolumny<70; ++kolumny){
			cout << tab[wiersz][kolumny];
		}
	}
}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::ClearRoom (){
    /** ETAP 1
        Metoda Zeruje wszystkie elementy Tablicy,
        wstawiajac w nie ' ' [spacje].

        ETAP 2
        Metoda Uzupelnia Tablice o Obramowanie Pokoju oraz Drzwi.
    */
    /// ETAP 1
	/// nadanie wartosci wszystkim elementom w tablicy CHAR
	for (int wiersz=0; wiersz<ROWS; ++wiersz) {
		for (int kolumny=0; kolumny<COLUMNS; ++kolumny) {
			tab [wiersz][kolumny] = ' '; //jedna ciapka( ' ) to char, dwuciapek( " ) to string (const char*)
		}
	}

	/// ETAP 2
	if (b_north){
        /// drzwi NORTH otwarte ------------------------------------------------
        // linijka pierwsza -------------------------------------------
        tab [0][33] = ppi;          //  │
        tab [0][36] = ppi;          //  │

        // linijka druga ----------------------------------------------
        tab [1][1] = lgr;           //  ┌

        Line(2,32,1,ppo);           //  ─ [x31]

        tab [1][33] = pdr;          //  ┘
        tab [1][34] = '-';          //  -  <=> myslnik, nie [ppo]
        tab [1][35] = '-';          //  -  <=> myslnik, nie [ppo]
        tab [1][36] = ldr;          //  └

        Line(37,67,1,ppo);          //  ─ [x31]

        tab [1][68] = pgr;          //  ┐
        // ------------------------------------------------------------
    }else{
        /// drzwi NORTH zamkniete ----------------------------------------------
        // zamknieta linijka druga ------------------------------------
        tab [1][1] = lgr;           //  ┌
        Line(2,67,1,ppo);           //  ─ [x66]
        tab [1][68] = pgr;          //  ┐
        // ------------------------------------------------------------
    }

    /// sciany pierwsza para -----------------------------------------------
    for (int x=2; x<=15; ++x) { ClearLine(x); }         //  │ newLine │ [x14]

    /// Drzwi WEST ---------------------------------------------------------
    if (b_west){
        // otwarte ----------------------------------------------------
        tab [16][0] = ppo;      tab [16][1] = pdr;      //  ─ ┘
                                tab [17][1] = '|';      //    |
                                tab [18][1] = '|';      //    |
        tab [19][0] = ppo;      tab [19][1] = pgr;      //  ─ ┐
        // ------------------------------------------------------------
    }else{
        // zamkniete --------------------------------------------------
        tab [16][1] = ppi;         //  │
        tab [17][1] = ppi;         //  │
        tab [18][1] = ppi;         //  │
        tab [19][1] = ppi;         //  │
        // ------------------------------------------------------------
    }

    /// Drzwi EAST ---------------------------------------------------------
    if (b_east){
        // otwarte ----------------------------------------------------
        tab [16][68] = ldr;     tab [16][69] = ppo;     //  └ ─
        tab [17][68] = '|';                             //  |       │<- NIE
        tab [18][68] = '|';                             //  |       │
        tab [19][68] = lgr;     tab [19][69] = ppo;     //  ┌ ─
        // ------------------------------------------------------------
    }else{
        // zamkniete --------------------------------------------------
        tab [16][68] = ppi;         //  │
        tab [17][68] = ppi;         //  │
        tab [18][68] = ppi;         //  │
        tab [19][68] = ppi;         //  │
        // ------------------------------------------------------------
    }

    /// sciany druga para --------------------------------------------------
    for (int x=20; x<=33; ++x) { ClearLine(x); }        // │ newLine │ [x14]

    if (b_south){
        /// drzwi SOUTH otwarte ------------------------------------------------
        // linijka przedostatnia --------------------------------------
        tab [34][1] = ldr;          //  └
        Line(2,32,34,ppo);          //  ─ [x31]

        tab [34][33] = pgr;         //  ┐
        tab [34][34] = '-';         //  -
        tab [34][35] = '-';         //  -
        tab [34][36] = lgr;         //  ┌

        Line(37,67,34,ppo);         //  ─ [x31]

        tab [34][68] = pdr;         //  ┘

        // linijka ostatnia -------------------------------------------
        tab [35][33] = ppi;         //  │
        tab [35][36] = ppi;         //  │
        // ------------------------------------------------------------
    }else{
        /// drzwi SOUTH zamkniete ----------------------------------------------
        // zamknieta linijka ostatnia ---------------------------------
        tab [34][1] = ldr;          //  └
        Line(2,67,34,ppo);          //  ─ [x66]
        tab [34][68] = pdr;         //  ┘
        // ------------------------------------------------------------
    }
}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::ClearLine(int wierszyk){
    /// kazda linijka sciany----------------------------------------------
	tab [wierszyk][0] = ' ';
	tab [wierszyk][1] = ppi;

    Line (2,67,wierszyk,' ');

	tab [wierszyk][68] = ppi;
	tab [wierszyk][69] = ' ';
}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::Line (int X, int width, int Y, char value){
	for ( ; X<=width; ++X) tab [Y][X] = value;
}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::Danger(int posX1,int posY1,int posX2,int posY2,int chan){
    /** Metoda wytycza obszar generowania losowych Obstacli.
        W argumentach Podajemy szanse na wylosowanie Obstacla [chan].
        Oraz niezalezne X,Y Anchora1 i Anchora2,

        Anchor1 Nigdy nie jest POD lub z PRAWEJ Anchora2.
        Anchor1 moze miec rowne wartosci co Anchor2.
            An1(X,Y) ■────┐
                     │/ / │
                     │ / /│
                     └────■ (X,Y)An2
    */

    /// Zapewnienie Warunkow. Etap 1

    // Metoda Sprawdzajaca czy obiek znajduje sie w Przedziale
    // W Przypadku gdyby nie Modyfikuje wprowadzone zmienne - za pomocą wskaznikow
    // Nie testowana duzo. W przypadku bledow, sprawdzic w pierwszej kolejnosci.
    CheckEntry(&posX1, &posY1, &posX2, &posY2);


#ifdef TEST_IN_ERROR_CASE
    // ------------------------------------------------------------
    //  An1  <==>  Anchor_1  <==>  ( posX1, posY1 )
    //  An2  <==>  Anchor_2  <==>  ( posX2, posY2 )

    // Warunki aby An1 nie wyszedł poza rysunek
    if (posX1 <= 1){ posX1 = 2; }   // An1 over/behind LEFT wall
    if (posY1 <= 1){ posY1 = 2; }   // An1 over/behind UPPER wall

    if (posX1 > 67){ posX1 = 67; }  // An1 behind RIGHT wall
    if (posY1 > 33){ posY1 = 33; }  // An1 behind BOTTOM wall

    // Warunki aby An2 nie wyszedł poza rysunek
    if (posX2 <= 1){ posX2 = 2; }   // An2 over/behind LEFT wall
    if (posY2 <= 1){ posY2 = 2; }   // An2 over/behind UPPER wall

    if (posX2 > 67){ posX2 = 67; }  // An2 behind RIGHT wall
    if (posY2 > 33){ posY2 = 33; }  // An2 behind BOTTOM wall
    // ------------------------------------------------------------

    /// Zapewnienie Warunkow. Etap 2
    // ------------------------------------------------------------
    int testSUM_X = posX2 - posX1;  // Dodatnie -> An2 jest po PRAWEJ od An1    [GOOD - 1]
                                    // Ujemne   -> An2 jest po LEWEJ od An1     [BAD - 0]
    int testSUM_Y = posY2 - posY1;  // Dodatnie -> An2 jest POD An1     [GOOD - 1]
                                    // Ujemne   -> An2 jest NAD An1     [BAD - 0]

    if(testSUM_X < 0) {     /**  0 1  **/// An2 jest po LEWEJ od An1
        int tmp = posX1;
        posX1 = posX2;
        posX2 = tmp;
    }

    if(testSUM_Y < 0) {     /**  1 0  **/// An2 jest NAD An1
        int tmp = posY1;
        posY1 = posY2;
        posY2 = tmp;
    }
    // ------------------------------------------------------------
/*  Nie musimy rozpatrywac konkretnie (0,0)
    if(testSUM_X < 0 && testSUM_Y < 0){     ///  0 0
        int tmp = posX1;
        posX1 = posX2;
        posX2 = tmp;

        tmp = posY1;
        posY1 = posY2;
        posY2 = tmp;
    }
    W razie gdybym sie mylil, stare warunki:
    if(testSUM_X >= 0 && testSUM_Y < 0){    ///  1 0
    if(testSUM_X < 0 && testSUM_Y >= 0){    ///  0 1
*/
#endif // TEST_IN_ERROR_CASE

    /// Losowanie, Wypelnianie Znakami:
    // ------------------------------------------------------------
    int los;
    srand(time(NULL));

    for (int i=posY1; i<=posY2; ++i){
        for (int j=posX1; j<=posX2; ++j){
            los = (rand() % 100) + 0;
            if (los < chan){
                tab[i][j]='#';
            }
        }
    }
    // ------------------------------------------------------------

/*
    for (int wiersz=posX1; wiersz<=posX2; ++wiersz)
        for (int kol=posY1; kol<=posY2; ++kol)
            tab[i][j]=j+46;*/
    // ------------------------------------------------------------
}

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::CheckEntry(int* posX1,int* posY1,int* posX2,int* posY2){
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

//  ____________________________________________________________________________________________________________
//  ____________________________________________________________________________________________________________
void DesRoom::EditPX (int& posX, int& posY, char symbol){
    /** Pozwala na modyfikacje jednego symbolu w tablicy.
        Wykorzystywana przez klase Unit do przemieszczania sie po tablicy.

        Wersja Z Sprawdzeniem Wprowadzonych danych.
        Za malo przetestowana, Moze generowac bledy.
    **/
    CheckEntry (&posX, &posY);
    this->tab[posY][posX] = symbol;
}

void DesRoom::EditPX_F (int& posX, int& posY, char symbol){
    /** Pozwala na modyfikacje jednego symbolu w tablicy.
        Wykorzystywana przez klase Unit do przemieszczania sie po tablicy.

        Wersja BEZ Sprawdzania Wprowadzonych danych.
        Pozwala Uzytkownikowi na wprowadzenie bledow
        = shutdown Programu z poziomu Windowsa.
    **/
    this->tab[posY][posX] = symbol;
}








