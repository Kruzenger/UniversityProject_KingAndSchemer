#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MAINSTRUCTS_H
#define MAINSTRUCTS_H

typedef struct person_st
{
    int name;

    struct person_st * Lord;

    struct person_st * friends[0];
    struct person_st * LastFriend;

    struct person_st * slaves[0];
    struct person_st * LastSlave;
}Person;

typedef struct tree_st
{
    Person * King;
    Person * Schemer;
}Tree;

typedef struct friendPersone_st
{
    bool type;

    Person * person;
    // struct friendPersone_st * previous;
    struct friendPersone_st * next;
}FriendPersone;

#endif