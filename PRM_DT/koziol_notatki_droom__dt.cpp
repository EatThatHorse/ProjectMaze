//#include <windows.h>
 //system("pause");

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

		    /// Etap zerowy:
    /* Posiadamy jedną komórkę pamięci w której trzymamy zmienną typu [char**]
        ┌┐
        └┘<──── char** tab; <──── zmienna o nazwie [tab], o typie [char**]
                            <──── dzięki nazwie posiadamy dostęp do tej komórki.
                            <──── dzięki typowi kompilator wie co trzyma dana komórka.
    */

    /// Etap pierwszy:
//    tab = new char*[ROWS];

    /* Do naszej pojedynczej komórki wstawiamy tablice typu [char*].
       Każde z nowych, małych prostokącików to nowe komórki pamięci.                             [35]
       Posiadają one swoje nazwy i swoje typy.                                               typ ilość
       Każdy z nowych prostokącików jest typu [char*],                                        │    │
       ponieważ kazaliśmy utworzyć 35 prostokąciki typu [char*]. Ten fragment kodu:     new char*[ROWS];
       Oznacza to że wartości jakie trzymają te prostokąciki to wskaźniki do komórek typu char.
        ┌──┐
        │┌┐│
        │└┘<──── to jest zmienna o Nazwie tab[0], zero jest indeksem. Nazwa tab[0] pozwala na dostęp do tej komórki.
        │┌┐│
        │└┘<──── tab[1]
        │. │
        │. │
        │. │
        │┌┐│
        │└┘<──── tab[34]    // typu [char*]
        └──┘<──── tab;      // typu [char**]

        ┌──────────────────────────────────────────────────────────────────┐
        │ INDEKSY TEŻ SĄ CZĘŚCIĄ NAZWY! NAZWA = DOSTĘP DO KOMÓRKI PAMIĘCI. │
        └──────────────────────────────────────────────────────────────────┘
    */

    /// Etap drugi:
//    for(int row=0; row<ROWS; ++row)  // Pętla przeskakuje przez wszystkie 35 wiersze. Indeksy Od 0 do 34
//        tab[row] = new char[COLUMNS];  // I w karzdym wierszu co się pojawi dodaje tablice 70 elementów typu [char].

    /* W tym etapie do każdego wiersza dodajemy tablice 70 elementów.
       Robimy to tak samo jak w poprzednim etapie.
       Teraz obecnie najmniejsze prostokąciki są typu [char].
       W nich, i tylo w nich, będziemy wpisywali to co ma być wypisane w konsoli.

       Zrobiłem to w pętli For, aby nie pisać tego ręcznie 34 razy dla każdego wiersza. Niech for wędruje przez 34 wiersze.

        ┌─────────────┐
        │┌───────────┐│
        ││┌┐┌┐_ _ _┌┐││    ......   <=>      ......           ┌┐┌┐_ _ _┌┐
        ││└┘└┘     └┘││                                       └┤└┘     └┘<──── tab[0][69]
        │└───────────┘<──── tab[0]                        tab[0][0]
        │┌───────────┐│
        ││┌┐┌┐_ _ _┌┐││    ......   <=>      ......           ┌┐┌┐_ _ _┌┐
        ││└┘└┘     └┘││                                       └┤└┘     └┘<──── tab[1][69]
        │└───────────┘<──── tab[1]                        tab[1][0]
        │.            │                                       │  └──── kolumna
        │.            │                                     wiersz
        │.            │
        │┌───────────┐│
        ││┌┐┌┐_ _ _┌┐││    ......   <=>      ......           ┌┐┌┐_ _ _┌┐
        ││└┘└┘     └┘││                                       └┤└┘     └┘<──── tab[34][69]
        │└───────────┘<──── tab[34] // typu [char*]       tab[34][0]
        └─────────────┘<──── tab;   // typu [char**]
    */

    /// CO DALEJ?
    /* W zasadzie nie zauważysz różnicy. Jendak zmiana była. niezbędna.
       Tak zmieniam wartość komórki (15;60) na symbol spacji:

            tab[15][60] = ' ';

       Tak wypisuje wartość komórki (2;59)

            cout << tab[2][59];
                     │  │   │
                     │  │   └─ 3) tab[2][59] to nazwa zmiennej typu [char]. W takich zmiennych trzymamy znaki które
                     │  │                                                   będą następnie updatowane i wyświetlane.
                     │  │
                     │  └─ 2) tab[2] to nazwa zmiennej typu [char*]. Daje dostęp do wiersza o indeksie 2.
                     │                                               Zmieniając indeks zmieniamy wiersz.
                     │
                     └─ 1) nazwa zmiennej typu [char**]. Daje dostęp do największego prostokąta w którym
                                                         Wszystko inne się znajduje.

        ┌──────────────────────────────────────────────────────────────────┐
        │ INDEKSY TEŻ SĄ CZĘŚCIĄ NAZWY! NAZWA = DOSTĘP DO KOMÓRKI PAMIĘCI. │
        └──────────────────────────────────────────────────────────────────┘    */



/**
    - pułapka ktora sprawia, ze gracz przestaje widziec mape
    - bomba, ktora niszczy sciany rowniez. Wybucha jak ktos (gracz/zombie) wdepnie
*/
