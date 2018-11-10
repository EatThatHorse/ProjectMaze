room::room MakeRoom(int lvl,int wid ,room* n,room* e,room* s,room* w ) { ///tworzy jeden pokoj, jesli bez argumentow - pokoj 00
			room room;

			room.lvl = lvl;
			room.wid = wid;
			room.north = n;
			room.east = e;
			room.south = s;
			room.west = w;
			room.Me = this;


            }

			return room;
	}
room::void PrintRoom(room room){
		cout<<room.lvl<<endl;
		cout<<room.wid<<endl;
		cout<<room.north<<endl;
		cout<<room.east<<endl;
		cout<<room.south<<endl;
		cout<<room.west<<endl;
	}

room :: hotel SetRoom(room room){ /// tworzenie nowych roomow, losowanie jakich i ilu, argumenty to obecny pokoj, zwraca pudelo z pokojami w srodku
		srand(time(NULL));
		int x = std::rand()%13 -6;

		if ( x==0) {
                hotel h;
                room room0 = MakeRoom(room.lvl + 1,room.wid,NULL,NULL,room.Me,NULL);
                h = MakeHotel(&room0);
					return h;
		}
		if( x==1){
                hotel h;
                room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
                room room1 = MakeRoom(room.lvl + 1,room.wid + 1,NULL,NULL,room0.Me,NULL);
                h = MakeHotel(&room0,&room1);
                    return h;
            }
        if ( x==2) {
                hotel h;
                room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
				room room1 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room0.Me);
				room room2 = MakeRoom(room.lvl + 1 ,room.wid + 2,NULL,NULL,room1.Me,NULL);
                h = MakeHotel(&room0,&room1,&room2);
                    return h;
        }
        if (x==3){
                hotel h;
                room room0 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
				room room1 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room0.Me);
				room room2 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room1.Me,NULL);
                h = MakeHotel(&room0,&room1,&room2);
                    return h;
        }



	}
