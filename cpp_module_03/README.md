# Master C++

**c++** is a high-level, general-purpose programming language , first released was in 1985 as an extention of **C** programming language, adding object-oriented (OOP) features.

## Module 03 :
Understand Inheritance and virtual functions .


### ex00:
>    *ClapTrap* : class of object that has attributes and methods .

### ex01:
>    *ScavTrap* : class that inherits from ClapTrap but it does its thing in its style and has it own abilities .


### ex02:
>    *FragTrap* : class that inherits from ClapTrap but it does its thing in its style and has it own abilities .


### ex03:

>    *DiamondTrap* : class that inherit from FragTrap, ScavTrap and has it own abilities.

the problem here is (FragTrap, ScavTrap) has the same base ClapTrap so having both of them would cuz the diamondtrap to have 2 claptraps which lead to ambiguity (which claptrap to interact with 1 or 2), to solve this we need to have shared claptrap and making FlagTrap and ScavTrap inherit virtually clapTrap, an other thing to worry about is virtual functions since fragTrap has it own attack so as scavTrap which mean 2 attack and this would lead to ambiguity,
to solve this we need override the function or say which one to use ,