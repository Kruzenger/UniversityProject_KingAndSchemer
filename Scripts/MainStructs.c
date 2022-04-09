#include <stdio.h>

#include "./MainStructs.h"

struct person
{
    int name;

    Person * Lord;

    Person * friends[0];
    Person * LastFriend;

    Person * slaves[0];
    Person * LastSlave;
};

struct tree
{
    Person * King;
    Person * Schemer;
};