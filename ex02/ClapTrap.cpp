#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

	std::cout << "\x1B[34mClapTrap " << m_name << " created\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {

	std::cout << "\x1B[34mClapTrap " << m_name << " has been destroyed\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:
	m_name(name),
	m_hitPoints(10),
	m_maxHitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0) {

	std::cout << "\x1B[34mClapTrap " << m_name << " created\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) :

	m_name(src.m_name),
	m_hitPoints(src.m_hitPoints),
	m_maxHitPoints(src.m_maxHitPoints),
	m_energyPoints(src.m_energyPoints),
	m_attackDamage(src.m_attackDamage) {

	std::cout << "\x1B[34mClapTrap " << m_name << " created by copy\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {

	m_name = rhs.m_name;
	m_hitPoints = rhs.m_hitPoints;
	m_energyPoints = rhs.m_energyPoints;
	m_attackDamage = rhs.m_attackDamage;
	return *this;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &rhs) {

	out << rhs.getName();
	return out;
}

void ClapTrap::attack(const std::string& target) {

	if (m_hitPoints == 0 || m_energyPoints == 0)
		return ;
	m_energyPoints > 0 ? m_energyPoints-- : 0;

	std::cout << "ClapTrap " << m_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << m_attackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (m_hitPoints == 0) {
		std::cout << m_name << " is dead" << std::endl;
		return ;
	}

	amount > m_hitPoints ? m_hitPoints = 0 : m_hitPoints -= amount;

	std::cout << "ClapTrap " << m_name;
	std::cout << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << "Actual hit points : ";
	std::cout << m_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (m_hitPoints == 0 || m_energyPoints == 0) {
		std::cout << m_name << " can't be repaired" << std::endl;
		return ;
	}

	m_energyPoints > 0 ? m_energyPoints-- : 0;
	m_hitPoints + amount > m_maxHitPoints ?
		m_hitPoints = m_maxHitPoints : m_hitPoints += amount;

	std::cout << "ClapTrap " << m_name;
	std::cout << " has been repaired, gaining " << amount;
	std::cout << " hit points" << std::endl;
	std::cout << "Actual hit points : ";
	std::cout << m_hitPoints << std::endl;
}

std::string ClapTrap::getName() const {

	return this->m_name;
}