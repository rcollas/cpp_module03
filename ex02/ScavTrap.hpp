#ifndef CPP_MODULE03_SCAVTRAP_HPP
#define CPP_MODULE03_SCAVTRAP_HPP


#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const &src);
		virtual ~ScavTrap();

		ScavTrap& operator=(ScavTrap const &rhs);

		void attack(std::string const &target);
		void guardGate();
};


#endif
