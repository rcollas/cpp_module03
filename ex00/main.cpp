#include "ClapTrap.hpp"

int main() {

	ClapTrap brockovicz;
	ClapTrap myEnemy("Villain");
	ClapTrap myFriend(myEnemy);

	myFriend.attack("the void");
	myFriend.attack("himself");
	myEnemy.takeDamage(1);
	myFriend.takeDamage(1);
	myEnemy.beRepaired(1);
	myFriend.beRepaired(1);
	myEnemy.takeDamage(4294967295);
	myEnemy.beRepaired(4294967295);
	myEnemy.attack("a bad guy");

	return 0;
}

