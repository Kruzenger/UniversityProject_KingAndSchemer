#include <stdio.h>
#include <string.h>
#include "./Tree.h"

int fsize(FILE *fp)
{
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

int get_fsize(FILE *input)
{
    int file_size;
    file_size = fsize(input);
    return file_size;
}

int CountLines(FILE *input) {
    int a;
    // a = get_fsize(input);
    // return (a - 3) / 6;
    return 6;
}

void ReadNumbers (FILE *input, Tree *tree) {
    fscanf(input, "%d", &(tree->n));
    fscanf(input, "%d", &(tree->k));
}

void FileWorker(Tree *tree, OperationLine *operationLines) {
    FILE *input;
    input = fopen("../plots.in" , "r");
    int n = CountLines(input);
    ReadNumbers(input, tree);
    operationLines = RelationsRead(input, n);
    fclose(input);
}

OperationLine * RelationsRead(FILE *input, int n)
{
    OperationLine * operationLine = (OperationLine *)calloc(n + 1, sizeof(OperationLine));
    for(int i = 0; i < n; i++)
    {
        char * buffer[2];
        operationLine[i].NumOfOperation = i/(n - 1);
        fscanf(input, "%s", *(buffer));
        operationLine[i].operation = *(buffer[0]);
        fscanf(input, "%d", &operationLine[i].person1);
        // operationLine[i].person1 = (int)(buffer[0] - '0');
        fscanf(input, "%d", &operationLine[i].person1);
        // operationLine[i].person2 = (int)(buffer[0] - '0');
    }
    return operationLine;   
}

Person * PersonsCreate(Tree *tree){
    Person *p = (Person*)calloc(tree->n, sizeof(Person) + sizeof(Friends) * tree->k  +  sizeof(Slaves) * (tree->n - 1));
    p->FriendsList.LastFriend = &p->FriendsList.Friends[0];
    p->SlavesList.LastSlave = &p->SlavesList.Slaves[0];
    return p;
}// Создаёт персон

void TreeCreate(Tree *tree, Person * persons, OperationLine *operationLines)
{
    tree->King = &(persons[0]);
    tree->Schemer = &(persons[tree->n - 1]);
    for (int i = 0; operationLines[i].operation; i++) {
        if( operationLines[i].operation == '='){
            *persons[operationLines[i].person1- 1].FriendsList.LastFriend = &persons[operationLines[i].person2 - 1];
            persons[operationLines[i].person1- 1].FriendsList.LastFriend++;
            
            *persons[operationLines[i].person2 - 1].FriendsList.LastFriend = &persons[operationLines[i].person1 - 1];
            persons[operationLines[i].person2 - 1].FriendsList.LastFriend++;
        }
        if ( operationLines[i].operation == '>'){
            *persons[operationLines[i].person1 - 1].SlavesList.LastSlave = &persons[operationLines[i].person2 - 1];
            persons[operationLines[i].person1 - 1].SlavesList.LastSlave++;
            *persons[operationLines[i].person2 - 1].Lord = persons[operationLines[i].person1 - 1];
        }
    }
    free(operationLines);
}
