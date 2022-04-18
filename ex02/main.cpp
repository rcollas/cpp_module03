#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	ClapTrap myEnemy("Villain");
	ClapTrap myFriend(myEnemy);

	ScavTrap myNewFriend("BleepBlop");

	FragTrap fragTrap("ZeepZop");

	FragTrap clapCopy(FragTrap("Jolly"));

	myFriend.attack("the void");
	myFriend.attack("himself");
	myEnemy.takeDamage(1);
	myFriend.takeDamage(1);
	myEnemy.beRepaired(1);
	myFriend.beRepaired(1);
	myEnemy.beRepaired(0);
	myEnemy.takeDamage(100);

	fragTrap.attack("villain");

	myNewFriend.attack("myFriend");
	myNewFriend.takeDamage(5);
	myNewFriend.beRepaired(100);
	myNewFriend.takeDamage(200);
	std::cout << myNewFriend << std::endl;

	ScavTrap copy(myNewFriend);

	std::cout << myNewFriend << std::endl;

	return 0;
}

