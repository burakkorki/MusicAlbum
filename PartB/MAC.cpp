//
//  SimpleMAC.cpp
//  PartA
//
//  Created by Burak Korkmaz on 19.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "MAC.h"
#include <iostream>
#include <string>
using namespace std;



MAC::MAC(){
    musicAlbums = NULL;
    noOfMusicAlbums = 0;
}

MAC::~MAC(){
    if(musicAlbums)
            delete [] musicAlbums;
}

MAC::MAC(const MAC &macToCopy){
    if(macToCopy.noOfMusicAlbums>0){
        
        noOfMusicAlbums = macToCopy.noOfMusicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
        for(int i = 0; i<noOfMusicAlbums;i++){
            musicAlbums[i]=macToCopy.musicAlbums[i];
        }
    }
    else{
        musicAlbums = NULL;
        noOfMusicAlbums = 0;
    }
}

void MAC::operator=(const MAC &right){
     if(&right != this){
         if (noOfMusicAlbums != right.noOfMusicAlbums){
             if(noOfMusicAlbums>0)
                 delete [] musicAlbums;
             noOfMusicAlbums = right.noOfMusicAlbums;
             if (noOfMusicAlbums > 0)
                 musicAlbums = new MusicAlbum[noOfMusicAlbums];
             else
                 musicAlbums = NULL;
         }
         for(int i = 0 ; i < noOfMusicAlbums ; i++){
             musicAlbums[i]=right.musicAlbums[i];
         }
     }
}

bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear){
    for(int i = 0; i<noOfMusicAlbums;i++ ){
        if(musicAlbums[i].getMusicAlbumArtist()==maArtist && musicAlbums[i].getMusicAlbumTitle()==maTitle )
            return false;
    }
    if(noOfMusicAlbums!=0){
        MusicAlbum *temp = musicAlbums;
        
        musicAlbums = new MusicAlbum[noOfMusicAlbums+1];
        
        for(int i= 0; i < noOfMusicAlbums;i++){
            musicAlbums[i]=temp[i];
        }
        
        delete [] temp;

    }
    else
        musicAlbums = new MusicAlbum[noOfMusicAlbums+1];
    musicAlbums[noOfMusicAlbums]=MusicAlbum(maArtist,maTitle,maYear);
    noOfMusicAlbums++;
   
    return true;
}
    


bool MAC::removeMusicAlbum(const string maArtist, const string maTitle){
    
    for(int i = 0; i<noOfMusicAlbums;i++ ){
        if(musicAlbums[i].getMusicAlbumArtist()==maArtist && musicAlbums[i].getMusicAlbumTitle()==maTitle ){
            MusicAlbum *temp = musicAlbums;
            musicAlbums = new MusicAlbum[noOfMusicAlbums-1];
            for(int j= 0; j < i;j++){
                musicAlbums[j]=temp[j];
            }
            for(int j= i+1; j < noOfMusicAlbums;j++){
                musicAlbums[j-1 ]=temp[j];
            }
            noOfMusicAlbums--;
            if(temp)
                delete [] temp;
            
            return true;
        }
    }
    return false;
}

int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums){
    allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
    for(int i = 0; i< noOfMusicAlbums;i++)
        allMusicAlbums[i] = musicAlbums[i];
    return noOfMusicAlbums;
}

bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs){
    for (int i = 0; i < noOfMusicAlbums; i++) {
        if(musicAlbums[i].getMusicAlbumArtist()==maArtist&&
           musicAlbums[i].getMusicAlbumTitle()==maTitle){
            if(musicAlbums[i].addSong(sName, sMins, sSecs))
                return true;
        }
    }
    return false;
}


bool MAC::removeSongs(const string maArtist, const string maTitle){
    for (int i = 0; i < noOfMusicAlbums; i++) {
        if(musicAlbums[i].getMusicAlbumArtist()==maArtist&&
           musicAlbums[i].getMusicAlbumTitle()==maTitle){
            if(musicAlbums[i].removeSongs())
                return true;
        }
    }
    return false;
}

void MAC::calculateAvgMusicAlbumLength(int &minutes, int &seconds){
    int minute = 0;
    int second = 0;
    for(int i = 0 ;i< noOfMusicAlbums ; i++){
        musicAlbums[i].calculateMusicAlbumLength(minutes, seconds);
        minute = minute + minutes;
        second = second + seconds;
//        cout << "For Minute " << minute << " Second " << second << endl;
    }
    second = second + 60 * minute;
    minutes = (second / noOfMusicAlbums)/60;
    seconds = (second / noOfMusicAlbums)%60;
//    cout <<noOfMusicAlbums <<"Minutes " << minutes << " Seconds " << seconds << endl;
}
