#include <stdio.h>
#include <stdlib.h>

#include "./MainStructs.h"

char * TreeRead(); // Считывает всех персон из файла и возвращает список персон

Person * PersonsCreate(int num); // Создаёт персон

Tree TreeCreate(Person * persons); // Объединяет персон, как-либо связанных с королём в компаненту связанности

Person * GetPerson(Tree * tree); // ищет и возвращает персону из дерева