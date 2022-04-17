#include <stdio.h>

FriendPerson ** FindChainOfFriendsToUs(Person * headPerson, Person * schemersLord, int numOfMen, bool slaves, int k); // Finds chain of friends to us +++

// Some functions for findChainOfFriends function

FriendPerson * RecursiveFindOfChain(Person * headPerson, Person * schemersLord, Person ** personsPassed, bool slaves, int k); // Recursive +++

void SufferTroughChain(FriendPerson * Chain);

void FreeChains(FriendPerson ** chains);



