#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "Overload ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {

	std::cout << "ScavTrap " << m_name << " cloned" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {

	this->m_name = rhs.m_name;
	this->m_hitPoints = rhs.m_hitPoints;
	this->m_energyPoints = rhs.m_energyPoints;
	this->m_attackDamage = rhs.m_attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap " << m_name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {

	if (m_energyPoints == 0 || m_hitPoints == 0) {
		std::cout << m_name << " can't attack" << std::endl;
		return ;
	}

	m_energyPoints > 0 ? m_energyPoints-- : 0;

	std::cout << "ScavTrap " << m_name;
	std::cout << " attacks and deals " << m_attackDamage;
	std::cout << " damage to " << target << std::endl;
}

void ScavTrap::guardGate() {

	std::cout << "ScavTrap " << m_name;
	std::cout << " entered gate keeper mode" << std::endl;
}

