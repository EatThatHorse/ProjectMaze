
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

char tab[34][70]; //pierwszy nawias to wiersze, drugi to kolumny

char ppo = 196;     //ppo  - pojedynzca pozioma
char ppi = 179;     //ppi - pojedyncza pionowa
char lgr = 218;     //lgr - lewy górny róg
char pgr = 191;     //pgr - prawy górny róg
char ldr = 192;     //ldr - lewy dolny róg
char pdr = 217;     //pdr - prawy dolny róg

string margin29 = "                             ";




void TabLine(int wierszyk){
///każda linijka sciany----------------------------------------------
	tab [wierszyk][0] = ' ';
	tab [wierszyk][1] = ppi;

	for (int x=2; x<=67; ++x)
		tab [wierszyk][x] = ' ';

	tab [wierszyk][68] = ppi;
	tab [wierszyk][69] = ' ';

	cout << "\n";
}

void RenderRoom (){


	// Zaczynamy funkcję, odpalamy fora:

	bool north = true;

/*	 for (int wiersz=0; wiersz<70; ++wiersz){
		tab [0][wiersz] = wiersz;
		cout << tab[0][wiersz];
	}*/

	// nadanie wartości elementom w tablicy kurwa!!!! CHAR
	for (int wiersz=0; wiersz<35; ++wiersz){
		for (int kolumny=0; kolumny<70; ++kolumny){
			tab [wiersz][kolumny] = ' '; ///jedna ciapka( ' ) to char, dwuciapek( " ) to string (const char*)
		}
	}

//	tab [2][2] = 218;

	if (north){
///linijka pierwsza----------------------------------------------
   // cout << margin29;

    for (int x=0; x<=31; ++x)		//cout << " ";
		tab [0][x] = ' ';

	tab [0][32] = ppi;    			// cout << ppi;

	for (int x=33; x<=35; ++x)
		tab [0][x] = ' ';

	tab [0][36] = ppi;



///druga linijka----------------------------------------------

	tab [1][0] = ' ';

	tab [1][1] = lgr;
	for (int x=2; x<=31; ++x)
        tab [1][x] = ppo;

	tab [1][32] = pdr;
    for (int x=33; x<=35; ++x)
        tab [1][x] = ' ';

	tab [1][36] = ldr;

    for (int x=37; x<=67; ++x)
        tab [1][x] = ppo;


    tab [1][68] = pgr;
    tab [1][69] = ' ';


	///trzecia linijka----------------------------------------------
	TabLine(2);
	///czwarta linijka----------------------------------------------
	TabLine(3);
	///piata linijka----------------------------------------------
	TabLine(4);


    }







/*
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
    }

*/


	// wyswietla 34 wiersze o 70 kolumnach (ktore nie sa w kolejnch wierszach klonami)
	// wyswietla wszystkie elementy tablicy 34x70
	for (int wiersz=0; wiersz<35; ++wiersz){
		for (int kolumny=0; kolumny<70; ++kolumny){
			cout << tab[wiersz][kolumny];
		}
		cout << "\n";
	}

	// ...



		/*
			int wiersz = 0;

			(wiersz<35) <=> (0<35) TAK
				zobacz tablice tab, otwórz szuflade o numerze [0][wiersz] <=> [0][0]
				i wbij do środka wartość 0.
				Wyświetl to co wpisałeś wyżej.

				<koniec tablicy>
				++wiersz <=> zwiększenie zmiennej wiersz o jeden
				wiersz jest teraz równy 1.

			(wiersz<35) <=> (1<35) TAK
				zobacz tablice tab, otwórz szuflade o numerze [0][wiersz] <=> [0][1]
				i wbij do środka wartość 0.
				Wyświetl to co wpisałeś wyżej.

				<koniec tablicy>
				++wiersz <=> zwiększenie zmiennej wiersz o jeden
				wiersz jest teraz równy 2.

			...

				wiersz jest teraz równy 35.
			(wiersz<35) <=> (35<35) NIE


		*/
}


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
//    AsciiRoom(true, false, true, false);

    RenderRoom();

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



/* [old] TO DO: [nie zaczynaj kolejnych krokow az nie ukonczysz poprzednich]

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


/** TO DO:
_________________________________________________________________________________________________________________________
Kroki 6-8 będą wypisywały nowe rzeczy w konsoli, więc jak by ci coś starszego zasłaniało wgląd to zakomentuj to w mainie.
Musisz widzieć co się dzieje, co robisz. Te kroki mają na celu otworzenia tamtej furtki i ułatwienia ci przyszłej pracy.
  **6) - For Fun, For Practice: Napisz sobie w mainie pętle for przez 10 elementów, (czyli wykonującą się 10 razy)
                                i niech każdy z tych elementów zostanie wypisany. (używając tego samego fora)
                                Nie potrzeba tworzyć żadnych zmiennych. (poza tymi wyliczającymi w forze, int i=0)

  **7) - For Fun, For Practice: Napisz Drugą pętlę for która będzie sie wywoływać 5 razy.
                                Do jej środka wpisz couta z nową linią. (cout << "\n";)
                                Pod coutem - nadal w pętli - wstaw całą swoją pętlę z kroku **6.

  **8) - For Fun, For Practice: Pobaw się teraz. Najpierw pozmieniaj ilość wykonywania się obydwu pętli.
                                Czyli np zamiast 5 i 10 niech się wykonują 6 i 2 razy.
                                Pozmieniaj informacje wejściowe do obydwu coutów. dodawaj nawiasy, spacje, zmieniaj
                                wartości, zmieniaj kolejność wypisywania. Eksperymentuj.

    * - To co wykonałeś nazywa się zagnieżdżaniem petli. (pętla w pętli)
_________________________________________________________________________________________________________________________

    9) Modyfikacja Funkcji: [TabLine(int)]
        - Zmień nazwę tej funkcji na ClearLine(int).

    10) Modyfikacja Funkcji: [RenderRoom ()]
        - W momencie pisania tego TODO posiadamy poprawnie narysowane 5 linijek. (0,1,2,3,4)
          Obecnie, pierwsze co robi ta funkcja to dwie pętle for, które wędrują po całej tablicy,
          przez wszystkie jej elementy (w każdej kolumnie i w każdym wierszu)
          I jak te pętle tak wędrują po tablicy, do każdego jej elementu jest wstawiana wartość ' ' (spacji).
          (zmiane wartości robi linijka):

            tab [wiersz][kolumny] = ' '; ///jedna ciapka( ' ) to char, dwuciapek( " ) to string (const char*)

          Oznacza to że wszystkie elementy naszej tablicy tab trzymają w sobie wartość ' ' (spacji).
            [ ][ ][ ]
            [ ][ ][ ]
            [ ][ ][ ]
            [ ][ ][ ]
            [ ][ ][ ]
            [ ][ ][ ]
            [ ][ ][ ]
          Tutaj symboliczne przedstawiam tablice tab. Zamiast Pisać 33*70 elementów, napisałem 3*7.
          W Każdym jej elemencie jest spacja. Elementów mamy 33*70 = 2310.

          Polecenie: Ta pierwsza pętla w pętli uzupełniająca tablice spacjami zostaje, więc patrzymy na kolejne instrukcje.
          Zakomentuj - wyłącz - wszystkie miejsca kodu, które do tablicy tab wstawiają spacje.
          Nie potrzebujemy ich, ponieważ spacje już tam są. Ale też zostaw je zakomentowane, ponieważ pierwsze 5 linijek
          kodu już teraz dobrze pokazują jak narysować następne. Rysując następne linijki nie pisz zakomentowanego wstawiania spacji.

        - W tej funkcji znajduje się bool north. Obecnie jest lokalna (bo znajduje się w funkcji RenderRoom).
          Spraw aby ta zmienna była globalna (czyli przenieś ją poza funkcję).
          Niech się znajduje pod deklaracją tablicy tab.
          Pod nią dopisz reszte potrzebnych flag. (south, east, west)

        - Dokończ funkcję RenderRoom() aby rysowało cały room.

        - Zmień nazwe funckji RenderRoom() na ClearRoom().

    11) Napisz nową funkcję o nazwie RenderRoom().
        Ostatnie (aktywne,nie zakomenotwane) linijki funkcji ClearRoom() posiadają zagnieżdżoną pętlę.
        Jej zadaniem jest wypisanie wszystkich elementów tablicy tab na ekran konsoli.
        (wypisanie w konsoli elementów tablicy robi linijka):

            cout << tab[wiersz][kolumny];

        Przenieś ten fragment kodu do nowo napisanej funkcji RenderRoom().
        Popraw maina. Niech najpierw odpala funkcję ClearRoom(), a następnie RenderRoom().

    12) Robi się ciasno. Utwórz dwa nowe pliki.
        - [c_roomDes]     // Ten tutaj nie posiada formatu. Dosłownie to wygląda [c_Droom.]
        - [roomDes.cpp]   // Uważaj by nie było .c  - ma być .cpp

    13) w pliku [c_roomDes]
        - Napisz niezbędne dyrektywy. #ifndef itd...
        - Napisz deklaracje nowej klasy o nazwie [Droom]
    *Aby wykonać krok 13:
      - zajrzyj do notatek z korsaża jak edukowałem ciebie i grzybo LUB
      - przeszukaj internety LUB
      - pisz do mnie  xp

    14) Łatwo w tym kroku o nieporozumienia. Proponuję najpierwsz przeczytać cały punkt 14,
        poukładać sobie w głowie co w jakim pliku, kiedy, będzie robione. Dopiero rozpocząć wykonywać TODO(14)
        Zwróć uwagę na różnice między deklaracja a definicja funkcji.. Definicja to to gdzie piszesz instrukcje { }.

        w pliku [c_roomDes]
        - Na początku wszystko będziemy robić publicznie, oszczędzi to problemów które na starcie są nic nie warte.
          W tym celu, na początku deklaracji nowej klasy użyj etykiety  [ public: ]
        - Skopiuj do klasy wszystkie zmienne globalne z pliku main.cpp

        w pliku [roomDes.cpp]
        - zaincluduj plik c_roomDes.
        - Skopiuj tutaj całe definicje funkcji RenderRoom() i ClearRoom().
        - Bezpośrednio przed nazwami obydwu funkcji dopisz  [ nazwaKlasy:: ] Jaka jest nazwa klasy?

        w pliku [c_roomDes]
        - Zrób kilka linijek odstępu. Tutaj skopiuj deklaracje dwóch funkcji RenderRoom() i ClearRoom().

        Od tej pory, plik main posiada dwie FUNKCJE o nazwie RenderRoom() i ClearRoom(),
        a klasa Droom posiada dwie METODY o nazwie RenderRoom() i ClearRoom().
        Metoda to funkcja która należy do jakiejś klasy.

        funkcja RenderRoom() to coś zupełnie innego niż metoda RenderRoom().
        Choć nazywają się tak samo i wykonują to samo...
        Największa różnica między nimi to sposób wywołania. Funkcje można wywołać dowolnie,
        a Metode można wywołać tylko dla jakiegoś obiektu danego typu (klasa=typ).
        Dzięki temu, Metoda może zrobić więcej niż Funkcja.

        Oczywiście jak zmodyfikujesz Funkcje RenderRoom() to NIE zmodyfikujesz metody RenderRoom().
        To są dwa odzielne byty.

    15) Sprawdzamy czy działa, w pliku [main.cpp]
        - zaincluduj plik c_roomDes.
        - Wyłącz wszystko co znajdowało się w funkcji main().

        Powtórzenie słownictwa:
            int x;
             │  └──── nazwa zmiennej
             └─── typ zmiennej (typ fundametalny)

            Droom y;
              │   └──── nazwa obiektu (zmiennej o typie własnym, czyli takim który sami napisaliśmy)
              └─── typ obiektu (typ własny - nazywa się tak samo jak nazwa klasy. Klasa = typ)

        - Utwórz nowy obiekt typu Droom o nazwie testRoom.
        - Wywołaj dla nowego obiektu dwie metody, ClearRoom() i RenderRoom(), w tej kolejności.
          Obiekt danej klasy ma dostęp do wszystkiego co w deklaracji danej klasy posiada etykietę public: .
          Dostęp uzyskuje się za pomocą kropki. Czyli aby wywołać metodę, piszesz najpierw nazwę obektu, kropka, metoda, bez spacji.
          Rozróżnij, obiekt od klasy lub nazwe obiektu od nazwy klasy...
          Nie da się wywołać metody dla danej klasy. Da się wywołac metodę dla danego obiektu.
*/















