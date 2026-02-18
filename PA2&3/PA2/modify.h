#ifndef MODIFY_H
#define MODIFY_H

#include "menus.h"
#include "play.h"
#include "record.h"

int loadSongs(FILE* file, Node** playlist);
void storePlaylist(Node* playlist, FILE* file);
void insertSong(Node** playlist);
void deleteSong(Node** playlist);
void editSong(Node* playlist);

#endif //MODIFY_H