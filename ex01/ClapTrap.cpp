#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name(""),
						m_hitPoints(10),
						m_energyPoints(10),
						m_attackDamage(0) {

	std::cout << "Default constructor called on \x1B[32m";
	std::cout << *this << "\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {

	std::cout << "Destructor called on \x1B[31m";
	std::cout << *this << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:
	m_name(name),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0) {

	std::cout << "Overload constructor called on \x1B[32m";
	std::cout << *this << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) :

	m_name(src.m_name),
	m_hitPoints(src.m_hitPoints),
	m_energyPoints(src.m_energyPoints),
	m_attackDamage(src.m_attackDamage) {

	std::cout << "Copy constructor called on \x1B[33m";
	std::cout << *this << "\033[0m" << std::endl;
	*this = src;
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

std::string ClapTrap::getName() const {

	if (m_name.empty()) {
		return "No name";
	} else {
		return this->m_name;
	}
}

void ClapTrap::attack(const std::string& target) {

	if (m_hitPoints == 0 || m_energyPoints == 0) {
		std::cout << "\x1B[33m" << m_name;
		std::cout << " can't attack" << "\033[0m" << std::endl;
		return ;
	}
	m_energyPoints > 0 ? m_energyPoints-- : 0;

	std::cout << "\x1B[35mClapTrap " << m_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << m_attackDamage;
	std::cout << " points of damage!\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (m_hitPoints == 0) {
		std::cout << "\x1B[31m" << m_name << " is dead\033[0m" << std::endl;
		return ;
	}

	amount >= m_hitPoints ? m_hitPoints = 0 : m_hitPoints -= amount;

	std::cout << "\x1B[31mClapTrap " << m_name;
	std::cout << " takes " << amount;
	std::cout << " points of damage!" << std::endl;
	std::cout << "Actual hit points : ";
	std::cout << m_hitPoints << "\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (m_hitPoints == 0 || m_energyPoints == 0) {
		std::cout << "\x1B[33m" << m_name;
		std::cout << " can't be repaired" << "\033[0m" << std::endl;
		return ;
	}

	m_energyPoints > 0 ? m_energyPoints-- : 0;
	amount > UINT32_MAX - m_hitPoints ? m_hitPoints = UINT32_MAX :
			m_hitPoints += amount;

	std::cout << "\x1B[32mClapTrap " << m_name;
	std::cout << " has been repaired, gaining " << amount;
	std::cout << " hit points" << std::endl;
	std::cout << "Actual hit points : ";
	std::cout << m_hitPoints << "\033[0m" << std::endl;
}
