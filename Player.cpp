
#include "c_Player"

#include <iostream>





        int player::Move (direction current){
        /** Metoda odpowiedzialna za przemieszczanie sie gracza.
            Modyfikuje odziedziczone po klasie [bot] zmienne polozenia.
            Wywolywana jest dla obiektu HERO w klsie Update.            */

            /*  ───────────────────────────────────────────────────────────────────────
                POMOCNICZA ILUSTRACJA TABLICY:
                ...->tab[rowSize][colSize]
                      └─ jest typu char**

                      0  1  2  3 ... X       X= ...->(colSize-1) = 69
                   0 [ ][ ][ ][ ][ ][ ]
                   1 [ ][ ][ ][ ][ ][ ]
                   2 [ ][ ][ ][ ][ ][ ]
                  ...[ ][ ][ ][ ][ ][ ]    [-1 bo mowimy o ostatnich indeksach.]
                   Y [ ][ ][ ][ ][ ][ ]

                   Y = ...->(rowSize-1) = 32
                ───────────────────────────────────────────────────────────────────────
            */

            /** TESTY - dzialajace, trzeba wprowadzic do [c_roomDes] [roomDes.cpp] klasy Droom.
                SKASOWAĆ PO WPROWADZENIU!
                char** tab;
                int rows = 3;
                int columns = 5;

                tab = new char*[rows];
                for(int Trow=0; Trow<rows; ++Trow)
                    tab[Trow] = new char[columns];

                for(int Trow=0; Trow<rows; ++Trow)
                    for(int Tcol=0; Tcol<columns; ++Tcol)
                        tab[Trow][Tcol] = 'o';

                char** tabTMP = tab;

                for(int Trow=0; Trow<rows; ++Trow){
                    for(int Tcol=0; Tcol<columns; ++Tcol){
                        std::cout << tabTMP[Trow][Tcol];
                    }
                    std::cout << "\n";
                }
                SKASOWAĆ PO WPROWADZENIU!            */


            /*  Odkomentowac gdy bedzie gotowy Droom.
            int tRowSize = this->roomPosition->rowSize;
            int tColSize = this->roomPosition->colSize;

            char** tabTMP;
            tabTMP = this->roomPosition->tab;

            */


            if (current == UP) {
                /*  Odkomentowac gdy bedzie gotowy Droom.
                this->a_image = ((char)A_UP);    // [↑] Zmiana wygladu gracza.

                this->speed = ((this->speed) < 2) ?
                for (int tmp=1; tmp<=(this->speed/2); ++tmp){  // Tyle ile (speed/2), tyle krokow zrobic.

                    if (tabTMP[(ypos-1)][xpos] == ' ') {  // Czy pole nad graczem jest puste?
                        /// TAK, moze zrobic krok.
                        this->ypos = (this->ypos - 1);    // [Y-1]

                    }else{
                        /// NIE, jest przeszkoda. Koniec ruchu.

                    }
                }
                */

                this->ypos = (this->ypos - (this->speed/2));    // [Y-1]
                this->a_image = ((char)A_UP);    // [↑]
                return current;
            }
            if (current == DOWN) {
                this->ypos = (this->ypos + (this->speed/2));    // [Y+1]
                this->a_image = ((char)A_DOWN);    // [↓]
                return current;
            }
            if (current == LEFT) {
                this->xpos = (this->xpos - this->speed);        // [X-1]
                this->a_image = ((char)A_LEFT);    // [←]
                return current;
            }
            if (current == RIGHT) {
                this->xpos = (this->xpos + this->speed);        // [X+1]
                this->a_image = ((char)A_RIGHT);    // [→]
                return current;
            }
        }
