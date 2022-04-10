#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./MainStructs.h"
#include "./AlgorithmPatterns.h"

Person * CheckIfPersonASlave(Person * person)
{
    return person->Lord;
}

bool CheckIfFriends(Person * firstPerson, Person * lastPerson)
{
    for (int i = 0; firstPerson->Friends[i] == firstPerson->LastFriend; i++)
        if(firstPerson->Friends[i] == lastPerson)
            return true;

    return false;
}

