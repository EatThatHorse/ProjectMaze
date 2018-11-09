
#include <windows.h>
#include <iostream>
using std::cout;
using std::cin;
using std::string;
/**
Dzień dobry. Mam na imię mikołaj.
Wymiary okien:
    - Marginesy: 29
    - Górne okno: 70x8
    - Dolne okno: 70x30
/*


        186 podw. pionowa
        205 podw. pozioma
        201 podw. lewy górny róg
        187 podw. prawy górny róg
        200 podw. lewy dolny róg
        188 podw. prawy dolny róg

        196 poj pozioma
        179 poj pionowa
        218 lewy górny róg
        191 prawy górny róg
        192 lewy dolny róg
        217 prawy dolny róg
    */

int main (){

char ppo = 196; //ppo  - pojedynzca pozioma
char ppi = 179; //ppi - pojedyncza pionowa
char lgr = 218; //lgr - lewy górny róg
char pgr = 191; //pgr - prawy górny róg
char ldr = 192; //ldr - lewy dolny róg
char pdr = 217; //pdr - prawy dolny róg

string margin29 = "                             ";

                 //górna kreska górnej ramki
    cout << margin29;

cout << lgr;    //lewy górny róg
for (int x=0 ;x<68 ;++x) {
    cout << ppo;   //pojedyncza pozioma
}
cout << pgr;  //prawy górny róg



cout << "\n";  //debug pierwszego wiersza bocznych kresek

for (int x=0 ;x<8 ;++x) {         //boczne kreski górnej ramki

        cout << margin29;

    cout << ppi;  //pojedyncza pionowa
    for (int x=0; x<68 ;x++) {
        cout << " ";
    }
    cout << ppi;  //pojedyncza pionowa
    cout << "\n";
}

         //dolna kreska górnej ramki
    cout << margin29;

cout << ldr; //lewy dolny róg
for (int x=0 ;x<68 ;++x) {
    cout << ppo;   //pojedyncza pionowa
}
cout << pdr;    //prawy dolny róg



cout << "\n";             //przerwa między ramkami

//####################################################################################################################

                 //górna kreska dolnej ramki
    cout << margin29;
cout << (char) lgr;  //lewy górny róg
for (int x=0 ;x<68 ;++x) {
    cout << ppo;   //pionowa pojdyncza
}
cout << pgr;   //prawy górny róg


cout << "\n";  //debug pierwszego wiersza bocznych kresek

for (int x=0 ;x<30 ;++x) {         //boczne kreski dolnej ramki

        cout << margin29;

    cout << ppi;  //pojedyncza pionowa
    for (int x=0; x<68 ;x++) {
        cout << " ";
    }
    cout << ppi;  //pojedyncza pionowa
    cout << "\n";
}

        //dolna kreska dolnej ramki
    cout << margin29;

cout << ldr;  //lewy dolny róg
for (int x=0 ;x<68 ;++x) {
    cout << ppo;  //pojedyncza pozioma
}
cout << pdr;  //prawy dolny róg
cout << "\n";
system("pause");
    return 0;
}
