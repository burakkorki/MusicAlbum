//
//  MusicAlbum.cpp
//  PartA
//
//  Created by Burak Korkmaz on 19.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "MusicAlbum.h"
using namespace std;
#include <string>
#include <iostream>
MusicAlbum::MusicAlbum(const string maArtist,
                       const string maTitle,
                       const int maYear){
    artist = maArtist;
    title = maTitle;
    year = maYear;
    songs = NULL;
    noSongs = 0;
    
}

MusicAlbum::~MusicAlbum(){
    if(songs)
        delete [] songs;
}

MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy){
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
    
    if(maToCopy.noSongs>0){
        
        noSongs = maToCopy.noSongs;
        songs = new Song[noSongs];
        for(int i = 0; i<noSongs;i++){
            songs[i]=maToCopy.songs[i];
        }
    }
    else{
        songs = NULL;
        noSongs = 0;
    }
}

void MusicAlbum::operator=(const MusicAlbum &right){
    artist = right.artist;
    title = right.title;
    year = right.year;
    if(&right != this){
        if (noSongs != right.noSongs){
            if(noSongs>0)
                delete [] songs;
            noSongs = right.noSongs;
            if (noSongs > 0)
                songs = new Song[noSongs];
            else
                songs = NULL;
        }
        for(int i = 0 ; i < noSongs ; i++){
            songs[i]=right.songs[i];
        }
    }
}

string MusicAlbum::getMusicAlbumArtist(){
    return artist;
}

string MusicAlbum::getMusicAlbumTitle(){
    return title;
}

int MusicAlbum::getMusicAlbumYear(){
    return year;
}

void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds){
    /*int minute = 0;
    int second = 0;
    for(int i = 0 ;i< noSongs ; i++){
        minute = minute +songs[i].getMins();
        second = second +songs[i].getSecs();
    }
    minutes = minute + second/60;
    seconds = second %60;*/
    minutes = 0;
    seconds = 0;
    for(int i = 0 ;i< noSongs ; i++){
        minutes = minutes + songs[i].getMins();
        seconds = seconds + songs[i].getSecs();
    }
    minutes = minutes + seconds/60;
    seconds = seconds %60;
//    cout <<noSongs <<" Minutes "<<minutes << "Seconds"<< seconds << endl;
}

bool MusicAlbum::addSong(const string sName, const int sMins, const int sSecs){
    for(int i = 0; i<noSongs;i++ ){
        if(songs[i].getSongName()==sName)
            return false;
    }
    if(noSongs!=0){
        Song *temp = songs;
        
        songs = new Song[noSongs+1];
        
        for(int i= 0; i < noSongs;i++){
            songs[i]=temp[i];
        }
        
        delete [] temp;
        
    }
    else
        songs = new Song[noSongs+1];
    songs[noSongs]=Song(sName,sMins,sSecs);
    noSongs++;
    
    return true;
}

bool MusicAlbum::removeSongs(){
    if(songs){
        delete [] songs;
        noSongs = 0;
        return true;
    }
    return false;
}
