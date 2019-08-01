//
//  Song.hpp
//  PartB
//
//  Created by Burak Korkmaz on 20.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __SONG_H
#define __SONG_H

#include <string>
using namespace std;
class Song {
public:
    Song(const string sName = "", const int sMins = 0, const int sSecs = 0);
    ~Song();
    Song(const Song &songToCopy);
    void operator=(const Song &right);
    string getSongName();
    int getMins();
    int getSecs();
private:
    string name;
    int mins;
    int secs;
};
#endif
