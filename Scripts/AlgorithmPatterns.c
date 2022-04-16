#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./MainStructs.h"
#include "./AlgorithmPatterns.h"
#include "./SchemerActions.h"

void AddPerson(Person * friendPerson, Person ** personsPassed)
{
    int i = 0;
    for(i = 0; personsPassed[i]; i++);

    personsPassed[i] = friendPerson;
}

bool IsInPersonPassed(Person * friendPerson, Person ** personsPassed)
{
    for(int i = 0; personsPassed[i]; i++)
        if(personsPassed[i] == friendPerson)
            return true;

    return false;
}

FriendPerson ** FindChainOfFriendsToUs(Person * headPerson, Person * lord, int numOfMen, bool slaves)
{
    FriendPerson ** Chains;
    Chains = (FriendPerson **)calloc(numOfMen, sizeof(FriendPerson *));
    int counter = 0;

    Person ** personsPassed = calloc(numOfMen, sizeof(Person*));
    personsPassed[0] = headPerson;

    for (int i = 0; headPerson->FriendsList.Friends[i]; i++)
    {
        Chains[counter] = RecursiveFindOfChain(headPerson->FriendsList.Friends[i], lord, personsPassed, slaves);
        if(Chains[counter] != NULL)
        {
            FriendPerson * friendPerson = (FriendPerson *)calloc(1, sizeof(FriendPerson));
            friendPerson->person = headPerson;
            friendPerson->next = Chains[counter];
            Chains[counter]->previous = friendPerson;

            for(int j = 0; Chains[counter + 1]; j++)
            {
                Chains[counter] = Chains[counter]->next;
            }
            counter++;
        }
    }

    free(personsPassed);

    return Chains;
}

FriendPerson * RecursiveFindOfChain(Person * headPerson, Person * lord, Person ** personsPassed, bool slaves)
{
    if(slaves && headPerson->Lord == lord)
        return NULL;

    if(headPerson->Lord == lord)
    {
        FriendPerson * friendPerson = (FriendPerson *)calloc(1, sizeof(FriendPerson));
        friendPerson->person = headPerson;
        return friendPerson;
    }

    AddPerson(headPerson, personsPassed);

    for(int i = 0; headPerson->FriendsList.Friends[i]; i++)
    {
        if(!IsInPersonPassed(headPerson->FriendsList.Friends[i], personsPassed))
        {
            FriendPerson * friendPersonNext = RecursiveFindOfChain(headPerson->FriendsList.Friends[i], lord, personsPassed, slaves);
            if(friendPersonNext != NULL)
            {
                FriendPerson * friendPerson = (FriendPerson *)calloc(1, sizeof(FriendPerson));
                friendPerson->person = headPerson;
                friendPerson->next = friendPersonNext;
                friendPersonNext->previous = friendPerson;
                return friendPerson;
            }
        }
    }

    return NULL;
}

void FreeChains(FriendPerson ** Chains)
{
    for(int i = 0; Chains[i] != NULL; i++)
    {
        while(Chains[i]->previous != NULL)
        {
            free(Chains[i]->next);
            Chains[i] = Chains[i]->previous;
        }
        free(Chains[i]->next);
        free(Chains[i]);
    }
    free(Chains);
}

