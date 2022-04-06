#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {

	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
	this->m_maxHitPoints = 100;
	std::cout << "\x1B[32mFragTrap " << m_name << " created\033[0m" <<
	std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->m_hitPoints = 100;
	this->m_maxHitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "\x1B[32mFragTrap " << m_name << " created\033[0m"
	<< std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {

	std::cout << "\x1B[32mFragTrap " << m_name << " cloned\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {

	this->m_name = rhs.m_name;
	this->m_hitPoints = rhs.m_hitPoints;
	this->m_maxHitPoints = rhs.m_maxHitPoints;
	this->m_energyPoints = rhs.m_energyPoints;
	this->m_attackDamage = rhs.m_attackDamage;
	return *this;
}

FragTrap::~FragTrap() {

	std::cout << "\x1B[32mFragTrap " << m_name << " has been destroyed\033[0m"
	<< std::endl;
}
