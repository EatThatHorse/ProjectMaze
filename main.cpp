

#include "c_GreatLoop"
#include <iostream>
using std::cout;


    // WcisnietyLubNie KeyPressed (SprawdzanyZnak);


int main (){
    int ERRORS;
    {   PrM::greatLoop GREATLOOP;
        ERRORS = GREATLOOP.Execute();       // Wywolanie Programu.
    }

    /// Ostateczna Obsluga bledow.
    if (ERRORS == 0)
        return 0;       // NO A SINGLE ERROR.
}
