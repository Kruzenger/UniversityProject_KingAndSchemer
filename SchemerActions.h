#include <stdio.h>
#include <stdbool.h>

#include "./MainStructs.h"

bool CanMakeFriends(Person * Schemer, Person * person); // checks if you can become friends with a person

void MakeFriends(Person * Schemer, Person * person); // makes friends with a person


void FallOut(Person * Schemer, Person * person); // fall out with a person


bool CanBecomeASlave(Person * Schemer, Person * person); // checks if you have a Lord

void BecomeASlave(Person * Schemer, Person * person); // mahes you a slave of a person


bool CanForceToBeASlave(Person * Schemer, Person * person); // checks if you can force a person to become a slave

bool CanMakeConspiracy(Person * Schemer, Person * person); // checks if you can make conspiracy of a person

void MakeSlave(Person * Schemer, Person * person); // makes someone our slave
