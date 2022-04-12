#include <stdio.h>
#include <string.h>
#include "./Tree.h"

OperationLine * RelationsRead(FILE * input)
{
    int n = 0;
    char * s;
    fscanf(input, "%s", s);
    
    int k = 0;
    int num = 0;
    while(s[k] != NULL)
    {
        if(s[k] == '\n')
            num++;
    }
    
    OperationLine * operationLine = (OperationLine *)calloc(num, sizeof(OperationLine));
    
    for(int i = 0; i < num; i++)
    {
        char * buffer[2];
        strcpy(buffer, s);
        operationLine[i].operation = buffer[0];
        strcpy(buffer, s);
        operationLine[i].person1 = (int)(buffer[0] - '0');
        strcpy(buffer, s);
        operationLine[i].person2 = (int)(buffer[0] - '0');
    }
    
    
}


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
    while( input != NULL)
    {
        
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
int main(){
    
}
