#include <stdio.h>
#include <stdlib.h>

#include "./MainStructs.h"

int fsize(FILE *fp);

int get_fsize(FILE *input);

int CountLines(FILE *input);

void ReadNumbers (FILE *input, Tree *tree);

void FileWorker(Tree *tree, OperationLine **operationLines);

OperationLine * RelationsRead(FILE * input, int n);

Person * PersonsCreate(Tree *tree); // Создаёт персон

void TreeCreate(Tree *tree, Person ** persons, OperationLine *lines); // Объединяет персон, как-либо связанных с королём в компаненту связанности

Person * GetPerson(Tree * tree); // ищет и возвращает персону из дерева