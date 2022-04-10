#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./MainStructs.h"
#include "./AlgorithmPatterns.h"

Person * CheckIfPersonASlave(Person * person)
{
    return person->Lord;
}

bool CheckIfHasGeneralLord(Person * firstPerson, Person * lastPerson)
{
    return (firstPerson->Lord == lastPerson->Lord);
}

