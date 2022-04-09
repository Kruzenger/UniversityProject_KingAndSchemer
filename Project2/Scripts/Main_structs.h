#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;

struct Person
{
    int num;
    Person * lord;
    Person ** friends;
    Person ** slaves;
};

typedef struct Tree Tree;

struct Tree
{
    Person King;
    Person Schemer;
};