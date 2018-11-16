

#include "c_GreatLoop"
#include <iostream>
using std::cout;


    // WcisnietyLubNie KeyPressed (SprawdzanyZnak);

    // 25 ↓
    // 24 ↑
    // 26 →
    // 27 ←


int main (){
    int ERRORS;
    {   GreatLoop GREATLOOP;
        ERRORS = GREATLOOP.Execute();       // Wywolanie Programu.
    }

    /// Ostateczna Obsluga bledow.
    if (ERRORS == 0)
        return 0;       // NO A SINGLE ERROR.
}
