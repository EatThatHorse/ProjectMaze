#include "c_ContainerRecord"

/// KONSTRUKTORY / DESTRUKTORY
ConRecord::ConRecord(int Tindex, ConRecord* prev, int xpos, int ypos, char symbol){
         // : keptValue(xpos, ypos, symbol) { // LISTA INICJALIZACYJNA
    this->keptValue = new Obstacle(xpos, ypos, PLAYER, symbol);

    this->previousRecord = prev;
    this->nextRecord = 0;
    this->index = Tindex;
}
ConRecord::~ConRecord() {
    this->previousRecord = 0;
    this->nextRecord = 0;
    this->index = -1;

}

void ConRecord::ShowRecord (){
    cout << " prev: (" << previousRecord;

    if (previousRecord == 0)    cout << ")\t ";
    else                        cout << ")";

    cout << " self: (" << this << ")"
         << " next: (" << nextRecord;

    if (nextRecord == 0) cout << ")\t\t";
    else                 cout << ")\t";

    cout << " id: [" << index << "]"
         << " X,Y: [" << keptValue->xpos << "," << keptValue->ypos << "]"
         << " char: ['" << keptValue->symbol << "']";
}
