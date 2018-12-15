
#include "c_roomDes"

Droom::Droom(){  /// KONTSTRUKTOR
    this->tab = new char*[ROWS];
    for(int row=0; row<ROWS; ++row)  // Pêtla przeskakuje przez wszystkie 35 wiersze. Indeksy Od 0 do 34
        this->tab[row] = new char[COLUMNS];
}
void Droom::RenderRoom(){

	// wyswietla 36 wiersze o 70 kolumnach (ktore nie sa w kolejnych wierszach klonami)
	// wyswietla wszystkie elementy tablicy 36x70
	for (int wiersz=0; wiersz<36; ++wiersz){

        cout << "\n" << margin29 ;

		for (int kolumny=0; kolumny<70; ++kolumny){
			cout << tab[wiersz][kolumny];
		}
	}

}

void Droom::ClearRoom (){

	// nadanie wartoœci elementom w tablicy CHAR
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
        ClearLine(x);
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
        ClearLine(x);

///przedostatnia linijka otwarta----------------------------------------------
    if (south){

        tab [34][1] = ldr;
        for (int x=2; x<=32; ++x)
            tab [34][x] = ppo;

        tab [34][33] = pgr;
        tab [34][36] = lgr;

        for (int x=37; x<=67; ++x)
            tab [34][x] = ppo;

        tab [34][68] = pdr;

        tab [35][33] = ppi;
        tab [35][36] = ppi;

    }else{
        tab [34][1] = ldr;
        for (int x=2; x<=67; ++x)
            tab [34][x] = ppo;

        tab [34][68] = pdr;
    }
}

void Droom::ClearLine(int wierszyk){
///ka¿da linijka sciany----------------------------------------------
	tab [wierszyk][0] = ' ';
	tab [wierszyk][1] = ppi;

	for (int x=2; x<=67; ++x)
		tab [wierszyk][x] = ' ';

	tab [wierszyk][68] = ppi;
	tab [wierszyk][69] = ' ';
}





void Droom::Danger(int posX1,int posY1,int posX2,int posY2,int chan){

    if (posX1 <= 1){              // warunki aby anchory nie wyszły poza rysunek
        posX1 = 2;
    }
    if (posY1 <= 1){
        posY1 = 2;
    }

    if (posX2 <= 1){
        posX2 = 2;
    }
    if (posY2 <= 1){
        posY2 = 2;
    }

    if (posX1 > 67){
        posX1 = 67;
    }
    if (posY1 > 33){
        posY1 = 33;
    }

    if (posX2 > 67){
        posX2 = 67;
    }
    if (posY2 > 33){
        posY2 = 33;
    }


    int tmp;
    int testSUM_X = posX2 - posX1; // Dodatnie -> anchor2 jest po prawej od anchor1
    int testSUM_Y = posY2 - posY1; // Dodatnie -> anchor2 jest pod anchor1


    if(testSUM_X < 0 && testSUM_Y < 0){  // 0 0
        tmp = posX1;
        posX1 = posX2;
        posX2 = tmp;

        tmp = posY1;
        posY1 = posY2;
        posY2 = tmp;
    }
     if(testSUM_X >= 0 && testSUM_Y < 0){ // 1 0
        tmp = posY1;
        posY1 = posY2;
        posY2 = tmp;

     }
     if(testSUM_X < 0 && testSUM_Y >= 0){ // 0 1
        tmp = posX1;
        posX1 = posX2;
        posX2 = tmp;

     }


    int los;
    srand(time(NULL));




     for (int i=posY1; i<=posY2; ++i){
            for (int j=posX1; j<=posX2; ++j){

                los = (std::rand() % 100) + 0;
                if (los  < chan ){
                    tab[i][j]='#';
                }
            }

     }
/*    for (int wiersz=posX1; wiersz<=posX2; ++wiersz){
        for (int kol=posY1; kol<=posY2; ++kol){
        tab[i][j]=j+46;
        }

    }*/
}

