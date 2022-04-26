#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Scripts/Tree.h"
#include "./Scripts/SchemerActions.h"
#include "./Scripts/AlgorithmPatterns.h"
#include "./Scripts/MainStructs.h"
#include "./Scripts/ConspiracyAlgorithm.h"

int main() 
{
    Tree tree;
    Person *Persons;
    OperationLine *operationLines;
    FileWorker(&tree, &operationLines);
    TreeCreate(&tree, &Persons, operationLines);

    TheConspiracyAlgorithm(tree);

    free(operationLines);
    FreeTree(&Persons, tree.n);
}