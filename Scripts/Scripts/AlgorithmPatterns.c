#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./MainStructs.h"
#include "./AlgorithmPatterns.h"

bool IsInCloseList(FriendPerson * closeList[0], FriendPerson * person)
{
    for(int i = 0; closeList[i]; i++)
        if(closeList[i] == person)
            return true;

    return false;
}

bool IsInOpenList(FriendPerson * openList[0], FriendPerson * person)
{
    for(int i = 0; openList[i]; i++)
        if(openList[i]->Person == person->Person)
            return true;
            
    return false;
}

FriendPerson ** AddPersonsToOpenList(FriendPerson * oldOpenList[0], FriendPerson * closeList[0], int numOfMen, bool isSlave)
{
    FriendPerson * openList[numOfMen];

    int sizeOfOpenList = 0;
    int sizeOfCloseList = 0;

    for(int i = 0; oldOpenList[i]; i++)
    {
        for(int j = 0; oldOpenList[i]->Person->Friends[j]; j++)
        {
            FriendPerson * person = (FriendPerson *)calloc(1, sizeof(FriendPerson));
            person->Person = oldOpenList[i]->Person->Friends[j];
            person->Previous = oldOpenList[i];

            if(!oldOpenList[i]->Person->Friends[j]->Lord && !IsInOpenList(openList, person) && !IsInCloseList(closeList, person))
                if(!oldOpenList[i]->Person->Friends[j]->Lord || !isSlave)
                {
                    openList[sizeOfOpenList] = person;
                    sizeOfOpenList++;
                }
        }

        closeList[sizeOfCloseList] = oldOpenList[i];
    }

    return openList;
}

FriendPerson * FindChainOfFriendsToOurSlave(Person * person, Person * schemer, int numOfMen)
{
    FriendPerson * openList[numOfMen];
    FriendPerson * closeList[numOfMen];

    openList[0]->Person = person;

    while(openList[0] != NULL)
    {
        for (int i = 0; openList[i] != NULL; i++)
            for(int j = 0; schemer->Slaves[j] != NULL; j++)
                if(openList[i]->Person == schemer->Slaves[j])
                    return openList[i]; 

        openList = AddPersonsToOpenList(openList, closeList, numOfMen, true);
    }
    
    return NULL;
}

FriendPerson * FindChainOfFriendsToUs(Person * person, Person * schemersLord, int numOfMen)
{
    FriendPerson * openList[numOfMen];
    FriendPerson * closeList[numOfMen];

    openList[0]->Person = person;

    while(openList[0] != NULL)
    {
        for (int i = 0; openList[i] != NULL; i++)
            for(int j = 0; schemersLord->Slaves[j] != NULL; j++)
                if(openList[i]->Person == schemersLord->Slaves[j])
                    return openList[i]; 

        openList = AddPersonsToOpenList(openList, closeList, numOfMen, false);
    }
    
    return NULL;
}

