#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	ClapTrap myEnemy("Villain");
	ClapTrap myFriend(myEnemy);

	ScavTrap myNewFriend("BleepBlop");

	myFriend.attack("the void");
	myFriend.attack("himself");
	myEnemy.takeDamage(1);
	myFriend.takeDamage(1);
	myEnemy.beRepaired(1);
	myFriend.beRepaired(1);
	myEnemy.takeDamage(100);
	myEnemy.beRepaired(2000);

	myNewFriend.attack("myFriend");
	myNewFriend.takeDamage(5);
	myNewFriend.beRepaired(UINT32_MAX);
	myNewFriend.beRepaired(UINT32_MAX);
	myNewFriend.takeDamage(200);
	myNewFriend.takeDamage(UINT32_MAX);
	myNewFriend.takeDamage(UINT32_MAX);
	myNewFriend.guardGate();
	std::cout << myNewFriend << std::endl;

	ScavTrap copy(myNewFriend);

	std::cout << myNewFriend << std::endl;

	return 0;
}

