#include "c_RoomContainer"

RoomContainer::RoomContainer(int Tlvl, int Twid, int Tnr){
    this->lvl = Tlvl;
    this->wid = Twid;
    this->nr = Tnr;


//    this->RoomContainerDanger(2,2,16,16,10);
//    this->RoomContainerDanger(2,19,16,33,10);
//
//    this->RoomContainerDanger(53,2,67,16,10);
//    this->RoomContainerDanger(53,19,67,33,10);


    this->RoomContainerDanger(2,2,67,33,3);
    this->AddWalls();
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


void RoomContainer::DrawColumnM(int x, int y){
    WallContainer.AddRecord(x+1,y,(char)219);
    WallContainer.AddRecord(x+2,y,(char)219);
    WallContainer.AddRecord(x+3,y,(char)219);
    WallContainer.AddRecord(x+4,y,(char)219);

    WallContainer.AddRecord(x+0,y+1,(char)219);

    WallContainer.AddRecord(x+1,y+1,(char)219);
//    WallContainer.AddRecord(x+2,y+1,(char)219);
//    WallContainer.AddRecord(x+3,y+1,(char)219);
    WallContainer.AddRecord(x+4,y+1,(char)219);

    WallContainer.AddRecord(x+5,y+1,(char)219);

    WallContainer.AddRecord(x+1,y+2,(char)219);
    WallContainer.AddRecord(x+2,y+2,(char)219);
    WallContainer.AddRecord(x+3,y+2,(char)219);
    WallContainer.AddRecord(x+4,y+2,(char)219);
}

void RoomContainer::AddWalls(){

    int tmin=0;
    int tmax=3;
    int los;

    srand(time(NULL));
    los = (rand()% tmax-tmin) + tmin;

    /// M medium -------------------------------------------------
    if (los==0){ // 2 kolumny M_medium V_1
        DrawColumnM(47,7);
        DrawColumnM(17,26);
        return;
    }
    if (los==1){ // 2 kolumny M_medium V_2
        DrawColumnM(17,7);
        DrawColumnM(17,7);
        DrawColumnM(47,26);
        return;
    }
    if (los==2){ // 4 kolumny M_medium
        DrawColumnM(17,7);
        DrawColumnM(47,7);

        DrawColumnM(17,26);
        DrawColumnM(47,26);
        return;
    }
    if (los==3){ // 6 kolumn M_medium V
        DrawColumnM(17,7);
        DrawColumnM(32,7);
        DrawColumnM(47,7);

        DrawColumnM(17,26);
        DrawColumnM(32,26);
        DrawColumnM(47,26);
        return;
    }
    /// ----------------------------------------------------------

}





void RoomContainer::RoomContainerDanger(int posX1,int posY1,int posX2,int posY2,int chan){
    /// Zapewnienie Warunkow.
    // Metoda Sprawdzajaca czy obiekt znajduje sie w Przedziale
    // W Przypadku gdyby nie Modyfikuje wprowadzone zmienne - za pomocą wskaznikow
    // Nie testowana duzo. W przypadku bledow, sprawdzic w pierwszej kolejnosci.
    RepairArg(&posX1, &posY1, &posX2, &posY2);


    /// Losowanie, Wypelnianie Znakami:
    // ------------------------------------------------------------
    int los;
    float variety = 3.14159265;
    //float variety = 100;
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
            if (los < chan)
                WallContainer.AddRecord(j,i,(char)254); // 177  176
        }
    }
    // ------------------------------------------------------------
}
