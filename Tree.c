#include <stdio.h>

#include "./Tree.h"


Person * PersonsCreate(){
    
    int N;
    int K;
    
    FILE * input;
    input = fopen( "./plots.in" , "r");
    fscanf(input, "%d", &N);
    fscanf(input, "%d", &K);
    
    Person *p = (Person*)calloc( N, sizeof(Person) + sizeof(Friends)*  K  +  sizeof(Slaves) * ( N - 1 ));
    p->FriendsList.LastFriend = &p->FriendsList.Friends[0];
    p->SlavesList.LastSlave = &p->SlavesList.Slaves[0];
    return p;
    
}// Создаёт персон

Tree TreeCreate(Person * persons)
{
    int N;
    int K;
    Tree  tree;
    FILE * input;
    input = fopen( "./plots.in" , "r");
    fscanf(input, "%d", &N);
    fscanf(input, "%d", &K);
    tree.n = N;
    tree.k = K;
    tree.King = &(persons[0]);
    tree.Schemer = &(persons[N - 1]);
    while(input != NULL)
    {
        char symbol;
        int man1;
        int man2;
        fscanf(input, "%c", &symbol);
        fscanf(input, "%c", &symbol);
        fscanf(input, "%d", &man1);
        fscanf(input, "%d", &man2);
        
        
        if( symbol == '='){
            *persons[man1 - 1].FriendsList.LastFriend = &persons[man2 - 1 ];
            persons[man1 - 1].FriendsList.LastFriend++;
            
            *persons[man2 - 1].FriendsList.LastFriend = &persons[man1 - 1 ];
            persons[man2 - 1].FriendsList.LastFriend++;
        }
        if ( symbol == '>'){
            *persons[man1 - 1].SlavesList.LastSlave = &persons[man2 - 1 ];
            persons[man1 - 1].SlavesList.LastSlave++;
            *persons[man2 - 1].Lord = persons[man1 - 1 ];
        }
    }
    return tree;
}
