#ifndef CPP_MODULE03_CLAPTRAP_HPP
#define CPP_MODULE03_CLAPTRAP_HPP

#include <iostream>

#define UINT32_MAX (4294967295U)

class ClapTrap {

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap& operator=(ClapTrap const &rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;

	private:
		std::string m_name;
		unsigned int m_hitPoints;
		unsigned int m_energyPoints;
		unsigned int m_attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &rhs);


#endif
