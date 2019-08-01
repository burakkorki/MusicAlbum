//
//  SimpleMAC.cpp
//  PartA
//
//  Created by Burak Korkmaz on 19.11.2018.
//  Copyright © 2018 Burak Korkmaz. All rights reserved.
//

#include "SimpleMAC.h"

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
