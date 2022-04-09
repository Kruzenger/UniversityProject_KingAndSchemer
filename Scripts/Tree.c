#include <stdio.h>
#include <stdlib.h>

#include "./Scripts/Tree.h"

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