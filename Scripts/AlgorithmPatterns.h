#include <stdio.h>

FriendPerson ** FindChainOfFriendsToUs(Person * headPerson, Person * schemersLord, int numOfMen, bool slaves); // Finds chain of friends to us +++

// Some functions for findChainOfFriends function

FriendPerson * RecursiveFindOfChain(Person * headPerson, Person * schemersLord, Person ** personsPassed, bool slaves); // Recursive

void FreeChains(FriendPerson ** chains);



