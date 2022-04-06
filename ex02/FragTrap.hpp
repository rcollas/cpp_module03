#ifndef CPP_MODULE03_FRAGTRAP_HPP
#define CPP_MODULE03_FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(FragTrap const &src);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap &operator=(FragTrap const &rhs);

	private:
};


#endif
