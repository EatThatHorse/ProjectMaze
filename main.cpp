
#include <iostream>
using std::cout;
using std::cin;
/**
Dzień dobry. Mam na imię mikołaj. Zająłem się tu ramkami i ich wymiarami (wymiary nie są dopasowane do okna #wersjabeta). Same wymiary okien trzeba przeskalować,
żeby wyglądały legitnie.
*/


    /*
        179 poj
        196


        186 podw
        218 lewy górny róg
        191 prawy górny róg
        192 lewy dolny róg
        217 prawy dolny róg
    */

int main (){


for (int x=0 ;x<20 ;++x) {                 //górna kreska górnej ramki
    cout << " ";
}
cout << (char) 218;
for (int x=0 ;x<68 ;++x) {
    cout << (char) 196;
}
cout << (char) 191;
for (int x=0 ;x<20 ;++x) {
    cout << " ";
}




cout << "\n";  //debug pierwszego wiersza bocznych kresek

for (int x=0 ;x<20 ;++x) {         //boczne kreski górnej ramki
    for (int x=0 ;x<20 ;++x) {
        cout << " ";
    }
    cout << (char)179;
    for (int x=0; x<68 ;x++) {
        cout << " ";
    }
    cout << (char)179;
    cout << "\n";
}

for (int x=0 ;x<20 ;++x) {        //dolna kreska górnej ramki
    cout << " ";
}
cout << (char) 192;
for (int x=0 ;x<68 ;++x) {
    cout << (char) 196;
}
cout << (char) 217;



cout << "\n";             //przerwa między ramkami



for (int x=0 ;x<20 ;++x) {                 //górna kreska dolnej ramki
    cout << " ";
}
cout << (char) 218;
for (int x=0 ;x<68 ;++x) {
    cout << (char) 196;
}
cout << (char) 191;
for (int x=0 ;x<20 ;++x) {
    cout << " ";
}

cout << "\n";  //debug pierwszego wiersza bocznych kresek

for (int x=0 ;x<35 ;++x) {         //boczne kreski górnej ramki
    for (int x=0 ;x<20 ;++x) {
        cout << " ";
    }
    cout << (char)179;
    for (int x=0; x<68 ;x++) {
        cout << " ";
    }
    cout << (char)179;
    cout << "\n";
}

for (int x=0 ;x<20 ;++x) {        //dolna kreska górnej ramki
    cout << " ";
}
cout << (char) 192;
for (int x=0 ;x<68 ;++x) {
    cout << (char) 196;
}
cout << (char) 217;
    return 0;
}
