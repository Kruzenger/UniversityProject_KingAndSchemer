#include <stdio.h>

Person * CheckIfPersonASlave(Person * person); // checks if person has a lord +++

FriendPersone * FindChainOfFriendsToOurSlave(Person * person, Person * schemer); // Finds chain of friends to our slave

FriendPersone * FindChainOfFriendsToUs(Person * person, Person * schemer); // Finds chain of friends to us

// Some functions for findChainOfFriends function

bool CheckFriendLimit(Person * person, int limit); // Check is there friend limit

bool CheckIfHasGeneralLord(Person * firstPerson, Person * anotherPerson); // checks if persons has general lord +++

bool CheckIfFriends(Person * firstPerson, Person * anotherPerson); // checks if persons are friends


