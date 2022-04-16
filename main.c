#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Scripts/Tree.h"
#include "./Scripts/SchemerActions.h"
#include "./Scripts/ConspiracyAlgorithm.h"
#include "./Scripts/MainStructs.h"
#include "./Scripts/AlgorithmPatterns.h"

int main() {
    Tree tree;
    
    Person *Persons;
    OperationLine *operationLines;
    FileWorker(&tree, &operationLines);
    TreeCreate(&tree, &Persons, operationLines);
    FriendPerson ** FriendChains = FindChainOfFriendsToUs(tree.King, tree.Schemer->Lord, tree.n, false);
    FriendPerson ** SlaveChains = FindChainOfFriendsToUs(tree.King, tree.Schemer, tree.n, true);
    FreeChains(FriendChains);
    FreeChains(SlaveChains);
    free(operationLines);
    FreeTree(&Persons, tree.n);
}

