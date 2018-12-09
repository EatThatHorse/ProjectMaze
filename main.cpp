#include "c_maze"
#include "c_room"

#include<iostream>

using std::cin;

int main (){

    room zeroRoom(NULL,NULL,NULL,0,0);
    maze Head(&zeroRoom);

///testowanko

    int x;
    cin>>x;

    for(int i = 0;i<x;++i ){

        getchar();
        Head.AddFloor();
        Head.ShowMaze();
        Head.SET_CURR(Head.LASTROOM());

    }

    return 0;
}

