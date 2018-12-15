

/**
Wymiary okien:
    - Marginesy: 29
    - Dolne okno: 70x36

    186 podw. pionowa               ║
    205 podw. pozioma               ═
    201 podw. lewy górny róg        ╔
    187 podw. prawy górny róg       ╗
    200 podw. lewy dolny róg        ╚
    188 podw. prawy dolny róg       ╝

    196 poj pozioma                 │
    179 poj pionowa                 ─
    218 lewy górny róg              ┌
    191 prawy górny róg             ┐
    192 lewy dolny róg              └
    217 prawy dolny róg             ┘

*/

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

            cout << tab[wiersz][kolumny]
;
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
