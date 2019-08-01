//
//  Song.cpp
//  PartB
//
//  Created by Burak Korkmaz on 20.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "Song.h"

Song::Song(const string sName,
           const int sMins,
           const int sSecs){
    name = sName;
    mins = sMins;
    secs = sSecs;
}

Song::~Song(){
    
}

Song::Song(const Song &songToCopy){
    name = songToCopy.name;
    mins = songToCopy.mins;
    secs = songToCopy.secs;
}

void Song::operator=(const Song &right){
    name = right.name;
    mins = right.mins;
    secs = right.secs;
}

string Song::getSongName(){
    return name;
}

int Song::getMins(){
    return mins;
}

int Song::getSecs(){
    return secs;
}
