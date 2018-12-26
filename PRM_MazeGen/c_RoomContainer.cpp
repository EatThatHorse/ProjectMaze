#include "c_RoomContainer"

RoomContainer::RoomContainer(char** tab){
    TabMod(tab);
}

void RoomContainer::ShowContainers(){
    cout<<"Traps: \n";
    TrapContainer.ShowKontener();
    cout<<"Items: \n";
    ItemContainer.ShowKontener();
    cout<<"Walls: \n";
    WallContainer.ShowKontener();
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
    srand(time(NULL));

    for (int i=posY1; i<=posY2; ++i){
        for (int j=posX1; j<=posX2; ++j){
            los = (rand() % 100) + 0;
            if (los < chan){

                TrapContainer.AddRecord(j,i,'@');
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
