#ifdef C_ROOM__DT
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
// VER_1: Only Units.   ---------------------------------------------------------------------------------
    unit zero (NULL, 0);    // Zerowy unit. Ma nazwe. Wiec bede mogl z niego korzystac wiele razy.
    cout << "test czy wypisuje pokoj zero:    "; zero.Show();
    unit* lastUnit;         // Wskaznik na ostatni dodany unit. Niezbedne do dodawania nowych.
    lastUnit = &zero;       // Jak na razie mamy jeden Unit. Od niego zaczynamy.
    int iloscUnitow = 1;    // Pokazuje ile unitow powstalo. Jak na razie mamy tylko zerowy wiec 1.

    // Dodajmy teraz 7 Unitow.
    for (int i=1; i<=1; ++i){
        // (new int) W ten sposob tworze obiekt typu int. Nie ma on nazwy ani wartosci.
        //           Ale nadal fizycznie istnieje w pamieci. Posiada swoj adres,
        //           wiec jezeli go znasz to jestes w stanie operowac tym obiektem tak jak by mial nazwe.

        // (new unit) Tutaj mamy inna sytuacje, poniewaz celowo zablokowalem domyslny konstruktor. (nie piszac go)
        //            Ale tak to zasada ta sama. tworze obiekt typu unit. Tylko ze odpowiednim konstruktorem.

        unit* tmp;  // tymczasowo wskazuje na nowopowstaly obiekt. Ten wskaznik znika razem z wykonaniem petli.
                    // oznacza to ze gdy petla rozpocznie kolejny krok, stracimy dostep do utworzonego unitu.
                    // Do czego to? Zobaczysz nizej.
        tmp = (new unit(lastUnit, i));    // nadalem mu adres poprzedniego unitu. lastUnit jest wskaznikiem, wiec bez &.

        // Dla wlasnej wygody wskaznik south poprzedniego obiektu rowniez ustawiam w konstroktorze nowego obiektu.

        lastUnit = tmp; // Aby wszystkie unity nie wskazywaly na zerowy, musimy przeskoczyc wskaznikiem.
                        // Teraz unit ktory wlasnie utworzylismy jest ostatni/najnowszy.
        ++iloscUnitow;  // Koniec, mamy nowy Unit. zwiekszamy iloscUnitow o jeden.
    }

    // Sprawdźmy czy dziala. Wyswietlmy wszystkie unity.
    unit* currentUnit = &zero;  // Potrzebujemy nowego wskaznika ktory bedzie "wedrowal" przez unity.

    cout << "\n\n\n"
         << "Wypisz wszystkie unity co masz!\n";

    for (int i=1; i <= iloscUnitow; ++i){   // moglem zaczac od 0, ale jakos mi tutaj logiczniej jak zaczne od [1] i [<=]
       // currentUnit->Show();                // wyswietlamy to gdzie jestesmy.
        currentUnit->ShowALL();          // Odkomentuj jedno, zakomentuj drugie. Mozesz porownac adresy  :D.

        if (i<iloscUnitow) cout << "\n " << (char)18 << "\n";   // Maly zabieg estetyczny.
        else cout << "\n\n\n";

        currentUnit = currentUnit->south;   // wedruj dalej.
    }
// ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■

#endif // C_ROOM__DT

