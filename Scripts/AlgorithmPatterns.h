#include <stdio.h>

Person * CheckIfPersonASlave(Person * person); // checks if person has a lord +++

FriendPersone * FindChainOfFriendsToOurSlave(Person * person, Person * schemer); // Finds chain of friends to our slave

FriendPersone * FindChainOfFriendsToUs(Person * person, Person * schemer); // Finds chain of friends to us

// Some functions for findChainOfFriends function

bool CheckIfFriends(Person * firstPerson, Person * anotherPerson); // checks if persons are friends


