#include "c_roomDes"

int main (){

    Droom testRoom;

    testRoom.ClearRoom();

    {
        int tmpChan = 30;
        int tmpChan2 = 20;

        testRoom.Danger(2,2,20,10,tmpChan); //lg
        testRoom.Danger(25,13,43,22,10); //sr
        testRoom.Danger(2,25,20,35,tmpChan); // lewy dol rog
        testRoom.Danger(48,2,69,10,tmpChan); //prawy gor rog
        testRoom.Danger(48,25,69,35,tmpChan); // prawy dol rog
        testRoom.Danger(25,4,43,10,tmpChan2); // sr gora
        testRoom.Danger(6,13,20,22,tmpChan2); // sr lewo
        testRoom.Danger(49,13,63,22,tmpChan2);// sr prawo
        testRoom.Danger(25,25,43,31,tmpChan2); // sr dol

    }



    ///srodek           25,13,43,22,tmpChan
    ///srodek 2x2:      34,17,35,18,100
    ///srodek 4x4:      32,16,36,19,100
    ///srodek 8x8:      31,14,38,21,100
    ///lewy gorny rog:  2,2,20,10,tmpChan
    ///lewy dolny rog:  2,28,15,35,100
    ///prawy gorny rog: 54,2,69,7,100
    ///prawy dolny rog: 54,28,69,35,100
    ///gora srodek :    25,5,43,10,100
    ///lewo srodek :    8,15,20,20,tmpChan
    ///prawo srodek :   49,15,61,20,tmpChan
    ///dol srodek :     25,25,43,30,tmpChan


  /*
    2,2,20,10,tmpChan); //lewo gora rog
    25,13,43,22,tmpChan); //sr
    2,25,20,35,tmpChan); // lewy dol rog
    48,2,69,10,tmpChan); //prawy gor rog
    48,25,69,35,tmpChan); // prawy dol rog
    25,4,43,10,tmpChan); // sr gora
    6,13,20,22,tmpChan); // sr lewo
    49,13,63,22,tmpChan);// sr prawo
    25,25,43,31,tmpChan); // sr dol
*/

    testRoom.RenderRoom();



    return 0;
}
