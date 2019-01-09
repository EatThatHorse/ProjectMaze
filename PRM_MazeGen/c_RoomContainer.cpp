#include "c_RoomContainer"

RoomContainer::RoomContainer(int Tlvl, int Twid, int Tnr){
    this->lvl = Tlvl;
    this->wid = Twid;
    this->nr = Tnr;

    this->RoomContainerDanger(10,10,20,20,5);
}

void RoomContainer::ShowContainers(){
    cout<<"Traps: \n";
    TrapContainer.ShowKontener();
    cout<<"Items: \n";
    ItemContainer.ShowKontener();
    cout<<"Walls: \n";
    WallContainer.ShowKontener();
}


void RoomContainer::AllocateContainers(){
    ConRecord* walker = this->WallContainer.kontener;

    while (walker != NULL){
        this->EditPX_F (                    // Przekazanie Obstacla do Renderu
            walker->keptValue->XPOS(),
            walker->keptValue->YPOS(),
            walker->keptValue->SYMBOL()
        );
        walker = walker->nextRecord;
    }

}

void RoomContainer::RoomContainerDanger(int posX1,int posY1,int posX2,int posY2,int chan){


    /// Zapewnienie Warunkow.

    // Metoda Sprawdzajaca czy obiek znajduje sie w Przedziale
    // W Przypadku gdyby nie Modyfikuje wprowadzone zmienne - za pomocą wskaznikow
    // Nie testowana duzo. W przypadku bledow, sprawdzic w pierwszej kolejnosci.
    RepairArg(&posX1, &posY1, &posX2, &posY2);


    /// Losowanie, Wypelnianie Znakami:
    // ------------------------------------------------------------
    int los;
    float variety = 3.14159265;
    srand(time(NULL));


    if (this->nr > 0)       variety = (variety + (this->nr*100)) * this->nr;
    if (this->lvl > 0)      variety = (variety + (this->lvl*100)) * this->nr;
    if (this->wid > 0)      variety = (variety + (this->wid*100)) * this->nr;
    if (this->wid < 0)      variety = (variety - (this->wid*100)) * this->nr;

    if (variety == 0)       variety = 3.14159265;

    variety += 0.141;

    while (variety < 100 || variety > 1000){
        while (variety < 100) variety *= variety;
        while (variety > 1000) variety *= 0.314159265;
    }

    chan = chan*variety*0.01;

    for (int i=posY1; i<=posY2; ++i){
        for (int j=posX1; j<=posX2; ++j){
            los = (rand() % (int)variety) + 1;
            if (los < chan){
                WallContainer.AddRecord(j,i,'@');
            }
        }
    }
    // ------------------------------------------------------------


}
void RoomContainer::TabMod(char** tab){
    ConRecord* tmp;
    tmp = TrapContainer.KONTENER();

    while(tmp->nextRecord != NULL ){
        tab[tmp->keptValue->xpos][tmp->keptValue->ypos] = tmp->keptValue->symbol;
    }
}
