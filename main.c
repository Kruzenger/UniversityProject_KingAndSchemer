#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./Scripts/Tree.h"
#include "./Scripts/SchemerActions.h"
// #include "./Scripts/ConspiracyAlgorithm.h"
#include "./Scripts/MainStructs.h"

int main() {
    Tree tree;
    Person *Persons;
    OperationLine *operationLines;
    FileWorker(&tree, &operationLines);
    TreeCreate(&tree, &Persons, operationLines);
    free(operationLines);
    free(Persons);
}
