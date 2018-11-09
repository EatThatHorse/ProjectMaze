
#ifdef Enything

    // #include "c_room"

    class bot {
        /** Klasa Bazowa dla:
                - class: player
                - class: moob
            Znajduja sie w niej informacje niezbedne dla
            wszystkiego co dowolnie skacze po pokoju.
        */

        //designedRoom* obstacles;          // Jakie przeszkody w pokoju/jak ma skakać + W ktorym pokoju się znajduje.
        // ^- Need to include c_room

        // In Room Position And Movement
        int xpos;
        int ypos;

        int speed;              // X steps/jumps per turn.
    };


    class player::bot {

    private: /// ZMIENNE
        // Ranked / Status
        int score;              // def.[0]
        int hp;                 // Need to test for Optimalization.

        // Animation Char's:
        char a_up = 24;         // [↑]
        char a_down = 25;       // [↓]
        char a_left = 27;       // [←]
        char a_right = 26;      // [→]
        char a_lastPos;         // Used for Player Render

    public: /// METODY
        void Input ();      // Left in the render-function. Checks for input for player. Also Moves Player?
        void ChangeCharacter (char a_newPos);
        void Render ();     // Used int drawRoom-function. It Draws current Animation Char.

    };

#endif // Enything

