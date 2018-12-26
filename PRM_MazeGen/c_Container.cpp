#include "c_Container"

/// KONSTRUKTORY / DESTRUKTORY
Container::Container(){
    this->konSIZE = 0;
    this->kontener = 0;
    this->lastRecord = 0;
}
Container::~Container(){
    DeleteKontener();
}


/// METODY
void Container::ShowKontener (){
    /** Wypisuje Wszystkie Informacje O Kontenerze i Jego Rekordach.
        Zaczyna Od Rekordu o zerowym indeksie [kontener], Od niego wedruje dalej,
        az do braku Rekordow. Pointer = 0.
    */
    ConRecord* tmpWalker = kontener;    // Wskaznik Wedrowny - Przez Wszystkie Rekordy.

    // Naglowek --------------------------------------
    cout << " Kontener:   firstR: ("<< kontener
         << ")  lastR: (" << lastRecord
         << ")  iloscR: [" << konSIZE
         << "]\n\n";
    // Zobacz czy sa Rekordy -------------------------
    if (tmpWalker == 0) {
        cout << "  [Brak Rekordow] \n";
        return;
    }
    // Else:
    do {
        tmpWalker->ShowRecord();            // Wyswietl - Metoda klasy [ConRecord]
        cout << "\n";
        tmpWalker = tmpWalker->nextRecord;  // Przemiesc sie do nastepnego
    } while (tmpWalker != 0);               // Az nie bedziesz mial gdzie sie przemiescic.
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void Container::AddRecord (int xpos, int ypos, char symbol) {
    /** Dodaje Nowy Rekord.
        Argumenty Przyjmuja domyslne wartosci:
           int xpos=0, int ypos=0, char symbol='K'
        Na Nowo Dodany Rekord Wskazujemy Pointerem: lastRecord.
    */
    ++konSIZE;

    if (kontener == 0){
        // Gdy Rekord Jest Pierwszym w Kontenerze.
        kontener = new ConRecord(0, 0, xpos, ypos, symbol);
        lastRecord = kontener;
    }else{
        // Gdy Rekord Jest Kolejnym w Kontenerze.
        lastRecord->nextRecord = new ConRecord (konSIZE-1, lastRecord, xpos, ypos, symbol);
        lastRecord = lastRecord->nextRecord;
    }
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void Container::DeleteLastRecord (){
    /** Metoda Kasuje Jeden Rekord.
        Gdy Zostal tylko Kontener, kasuje Kontener.
        Gdy nie ma nid, robi nic.
    */
    if (kontener==0){   // Sprawdz czy jest co kasowac.
        return;
    }
    --konSIZE;          // Cos na pewno skasujemy. Wiec Ilosc Rekordow - 1.

    if (kontener == lastRecord){    // Sprawdz czy kasujemy kontener.
        delete lastRecord;
        kontener = lastRecord = 0;
        return;                     // Kontener skasowany. Brak Rekordow. Wskazniki wyzerowane. Koniec.
    }

    ConRecord* hangman = lastRecord;            // Nie kasujemy Kontenera.

    lastRecord = lastRecord->previousRecord;    // Cofamy sie lastRecordem o krok do tylu.
    lastRecord->nextRecord = 0;                 // Zerujemy wskaznik na Rekord ktory zaraz usuniemy.
    delete hangman;                             // Kasujemy Rekord
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void Container::DeleteKontener (){
    /** Metoda Kasuje Wszystkie Rekordy, Razem z Kontenerem.
        Dodatkowo, Jest Wywolywana w Destruktorze.
    */
    while (lastRecord->previousRecord != 0) {   // Skasowanie wszystkich Rekordow poza kontenerem.
        DeleteLastRecord();
    }
    DeleteLastRecord(); // Skasowanie zerowego Rekordu - kontenera.
}
ConRecord* Container::KONTENER(){return this->kontener;}
