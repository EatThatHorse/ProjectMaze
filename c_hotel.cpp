
#include "c_hotel"
//#include "c_room"
hotel MakeHotel(room* pok1, room* pok2, room* pok3, room* pok4, room* pok5,room* pok6){
            hotel h;
            h.r1 = pok1;
            h.r2 = pok2;
            h.r3 = pok3;
            h.r4 = pok4;
            h.r5 = pok5;
            h.r6 = pok6;
            return h;
       }



hotel hotel::SetRoom(room tmpRoom){ /// tworzenie nowych roomow, losowanie jakich i ilu, argumenty to obecny pokoj, zwraca pudelo z pokojami w srodku



        srand(time(NULL));
        int x = std::rand()%13 -6;

        if (x==0) {
            hotel h;
            room room0;
            room0.MakeRoom(tmpRoom.lvl + 1,tmpRoom.wid,NULL,NULL,tmpRoom.Me,NULL);
//            h.MakeHotel(&room0,NULL,NULL,NULL,NULL,NULL);
            return h;
        }
        if(x==1) {
            hotel h;
            room room0;
            room room1;
            room0.MakeRoom(tmpRoom.lvl,tmpRoom.wid + 1,NULL,NULL,NULL,tmpRoom.Me);
            room1.MakeRoom(tmpRoom.lvl + 1,tmpRoom.wid + 1,NULL,NULL,room0.Me,NULL);
//            h.MakeHotel(&room0,&room1);
            return h;
            }
      /*  if (x==2) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 2,NULL,NULL,room1.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2);
            return h;
        }
        if (x==3) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room1 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room1.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2);
            return h;
        }
        if (x==4) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room1 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room1.Me);
            room room3 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room2.Me,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3);
            return h;

        }
        if (x==5) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl + 1 ,room.wid + 1,NULL,NULL,room0.Me,NULL);
            room room2 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room3 = MakeRoom(room.lvl,room.wid - 2,NULL,room2.Me,NULL,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3);
            return h;

        }
        if (x==6) {
            hotel h;
            room room0 = MakeRoom(room.lvl,room.wid + 1,NULL,NULL,NULL,room.Me);
            room room1 = MakeRoom(room.lvl,room.wid + 2,NULL,NULL,NULL,room0.Me);
            room room2 = MakeRoom(room.lvl + 1 ,room.wid + 2,NULL,NULL,room1.Me,NULL);
            room room3 = MakeRoom(room.lvl,room.wid - 1,NULL,room.Me,NULL,NULL);
            room room4 = MakeRoom(room.lvl,room.wid - 2,NULL,room3.Me,NULL,NULL);
            h = MakeHotel(&room0,&room1,&room2,&room3,&room4);
            return h;

        }
        if (x==-1) {

        }
        if (x==-2) {

        }
        if (x==-3) {

        }
        if (x==-4) {

        }
        if (x==-5) {

        }
        if (x==-6) {

        }
        */
    }

void hotel::PrintHotel(hotel h){ ///[GRZYBO] wypisywanie za hotelu

        h.r1->PrintRoom();
        h.r2->PrintRoom();
        h.r3->PrintRoom();
        h.r4->PrintRoom();
        h.r5->PrintRoom();
        h.r6->PrintRoom();
}


