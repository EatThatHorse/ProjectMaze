
#include "c_Stats"



void Stats::Save(int nr){

            Score = nr;
            system("cls");

            cout<<"\n\n\n\n\n\n\n\t\t\tTWOJ NICK: ";
            cin>>PlayerName;

        }


void Stats::Write(){

            std::ofstream zapis("data.txt", std::ios_base::app);
            zapis<<"\n"<<PlayerName<<".........."<<Score;
            zapis.close();
        }

void Stats::Read(){

            std::fstream plik;

            plik.open("data.txt", std::ios::in);
            if(plik.good() == true)
            {
                while(!plik.eof())
                {
                    getline(plik,PlayerName);
                    cout <<PlayerName<<"\n"; //wyświetlenie linii
                }
                plik.close();
            }
        }
