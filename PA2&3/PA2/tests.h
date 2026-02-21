#ifndef TESTS_H
#define TESTS_H

#include "record.h"
#include "modify.h"
#include "menus.h"
#include "play.h"

int insertTest(Node* playlist);
int deleteTest(Node* playlist);
int shuffleTest(Node* playlist, int order[]);

#endif //TESTS_H