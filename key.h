#ifndef KEY_H
#define KEY_H
/*
struct "key" defines a single key from keyboard. It's properties are:
-name of file which holds sound corresponding to this key
-name of file which holds picture corresponding to this key
-position on the keyboard
-size of the key
*/
static struct key{
    char *sound, *note;
    int posX,posY,lenX,lenY;
} tab[] = {
    {"Sounds/Db2.wav","Notes/space.png",4,0,4,4}, {"Sounds/Eb2.wav","Notes/space.png",10,0,4,4},
    {"Sounds/Gb2.wav","Notes/space.png",22,0,4,4},
    {"Sounds/Ab2.wav","Notes/space.png",28,0,4,4}, {"Sounds/Bb2.wav","Notes/space.png",34,0,4,4},
    {"Sounds/Db3.wav","Notes/space.png",46,0,4,4}, {"Sounds/Eb3.wav","Notes/space.png",52,0,4,4},
    {"Sounds/Gb3.wav","Notes/Gb3.png",64,0,4,4},
    {"Sounds/Ab3.wav","Notes/Ab3.png",70,0,4,4}, {"Sounds/Bb3.wav","Notes/Bb3.png",76,0,4,4},
    {"Sounds/Db4.wav","Notes/Db4.png",88,0,4,4}, {"Sounds/Eb4.wav","Notes/Eb4.png",94,0,4,4},
    {"Sounds/Gb4.wav","Notes/Gb4.png",106,0,4,4},
    {"Sounds/Ab4.wav","Notes/Ab4.png",112,0,4,4}, {"Sounds/Bb4.wav","Notes/Bb4.png",118,0,4,4},
    {"Sounds/Db5.wav","Notes/Db5.png",130,0,4,4}, {"Sounds/Eb5.wav","Notes/Eb5.png",136,0,4,4},
    {"Sounds/Gb5.wav","Notes/Gb5.png",148,0,4,4},
    {"Sounds/Ab5.wav","Notes/Ab5.png",154,0,4,4}, {"Sounds/Bb5.wav","Notes/Bb5.png",160,0,4,4},

    {"Sounds/C2.wav","Notes/space.png",0,0,6,7}, {"Sounds/D2.wav","Notes/space.png",6,0,6,7},
    {"Sounds/E2.wav","Notes/space.png",12,0,6,7}, {"Sounds/F2.wav","Notes/space.png",18,0,6,7},
    {"Sounds/G2.wav","Notes/space.png",24,0,6,7}, {"Sounds/A2.wav","Notes/space.png",30,0,6,7},
    {"Sounds/B2.wav","Notes/space.png",36,0,6,7}, {"Sounds/C3.wav","Notes/space.png",42,0,6,7},
    {"Sounds/D3.wav","Notes/space.png",48,0,6,7}, {"Sounds/E3.wav","Notes/space.png",54,0,6,7},
    {"Sounds/F3.wav","Notes/F3.png",60,0,6,7}, {"Sounds/G3.wav","Notes/G3.png",66,0,6,7},
    {"Sounds/A3.wav","Notes/A3.png",72,0,6,7}, {"Sounds/B3.wav","Notes/B3.png",78,0,6,7},
    {"Sounds/C4.wav","Notes/C4.png",84,0,6,7}, {"Sounds/D4.wav","Notes/D4.png",90,0,6,7},
    {"Sounds/E4.wav","Notes/E4.png",96,0,6,7}, {"Sounds/F4.wav","Notes/F4.png",102,0,6,7},
    {"Sounds/G4.wav","Notes/G4.png",108,0,6,7}, {"Sounds/A4.wav","Notes/A4.png",114,0,6,7},
    {"Sounds/B4.wav","Notes/B4.png",120,0,6,7}, {"Sounds/C5.wav","Notes/C5.png",126,0,6,7},
    {"Sounds/D5.wav","Notes/D5.png",132,0,6,7}, {"Sounds/E5.wav","Notes/E5.png",138,0,6,7},
    {"Sounds/F5.wav","Notes/F5.png",144,0,6,7}, {"Sounds/G5.wav","Notes/G5.png",150,0,6,7},
    {"Sounds/A5.wav","Notes/A5.png",156,0,6,7}, {"Sounds/B5.wav","Notes/B5.png",162,0,6,7},
    {"Sounds/C6.wav","Notes/C6.png",168,0,6,7}
};

#endif
