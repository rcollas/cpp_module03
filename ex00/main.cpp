#include "ClapTrap.hpp"

int main() {

	ClapTrap myEnemy("Villain");
	ClapTrap myFriend(myEnemy);

	myFriend.attack("the void");
	myFriend.attack("himself");
	myEnemy.takeDamage(1);
	myFriend.takeDamage(1);
	myEnemy.beRepaired(1);
	myFriend.beRepaired(1);
	myEnemy.takeDamage(100);
	myEnemy.beRepaired(2000);

	return 0;
}

