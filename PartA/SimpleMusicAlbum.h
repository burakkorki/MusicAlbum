//
//  MusicAlbum.hpp
//  PartA
//
//  Created by Burak Korkmaz on 19.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#ifndef __SIMPLE_MUSIC_ALBUM_H
#define __SIMPLE_MUSIC_ALBUM_H
#include <string>
using namespace std;
class MusicAlbum {
public:
    MusicAlbum(const string maArtist = "",
               const string maTitle = "",
               const int maYear = 0);
    ~MusicAlbum();
    MusicAlbum(const MusicAlbum &maToCopy);
    void operator=(const MusicAlbum &right);
    string getMusicAlbumArtist();
    string getMusicAlbumTitle();
    int getMusicAlbumYear();
private:
    string artist;
    string title;
    int year;
};
#endif
