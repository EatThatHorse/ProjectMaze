
#include "c_Stats"



void Stats::Save(int nr){///zapis swojego nicka

    Score = nr;
    system("cls");

    cout<<"\n\n\n\n\n\n\n\t\tTWOJ NICK (MAX 3 ZNAKI): ";
    cin>>PlayerName;
    PlayerName.resize(3);

}
void Stats::Write(){///zapis do pliku

    std::ofstream zapis("data.txt", std::ios_base::app);
    zapis<<"\n"<<PlayerName<<"..........."<<Score;
    zapis.close();
}
void Stats::Read(){ ///odczyt pliku, urzywany do tabeli wynikow

    std::fstream plik;

    plik.open("data.txt", std::ios::in);
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik,PlayerName);
            cout <<"\t\t\t\t\t\t"<<PlayerName<<"\n"; //wyświetlenie linii
        }
        plik.close();
    }
}
