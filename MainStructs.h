#include <stdio.h>
#include <stdlib.h>

#ifndef A_H_INCLUDED // идентификатор ещё не определён
#define A_H_INCLUDED // определяем

typedef struct operationLine_st{
    char operation;
    int person1;
    int person2;
}OperationLine;

typedef struct friends_st
{
    struct person_st * Friends[0];
    struct person_st ** LastFriend;
    
}Friends;




typedef struct slaves_st
{

struct person_st * Slaves[0];
struct person_st ** LastSlave;

}Slaves;



typedef struct person_st{
    int name;
    
    struct person_st * Lord;
    
    Friends FriendsList;
    Slaves SlavesList;
}Person;

typedef struct tree_st
{
    int n;
    int k;
    Person * King;
    Person * Schemer;
}Tree;


typedef struct friendPersone_st
{
    //bool type;
    Person * person;
    // struct friendPersone_st * previous;
    struct friendPersone_st * next;
}FriendPersone;

#endif
