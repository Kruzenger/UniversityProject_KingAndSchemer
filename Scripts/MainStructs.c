#include <stdio.h>

#include "./MainStructs.h"

struct Person
{
    int num;
    Person * lord;
    Person ** friends;
    Person ** slaves;
};

struct Tree
{
    Person King;
    Person Schemer;
};