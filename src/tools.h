/*
 * tools.h
 *
 *  Created on: Sep 15, 2016
 *      Author: andrei
 */

#ifndef SRC_TOOLS_H_
#define SRC_TOOLS_H_

#include <cassert>
#include <typeinfo>
#include <iostream>
#include <cctype>
#include <sstream>

/**
 * Display useful info about an object on the stack:
 *
 * \tparam T the type of the object to print.
 * \param object an instance of T allocated on the stack.
 */
template<typename T>
void print_stack_object(const T & object) {

	// use C++ introspection to get the name of object's type (T)
	std::string name(typeid(T).name());
	assert(! name.empty());

	// clean up class name because it is mangled by gcc:
	std::string::iterator it = name.begin();
	while(std::isdigit(*it) && it != name.end()) ++it;
	name = std::string(it, name.end());

	// display only the last 4 characters of the address, usually it is enough
	// for example purposes.
	std::stringstream ss;
	ss << std::hex << &object;
	std::string address(ss.str());
	address = address.substr(address.length()-4, 4);


	std::cout << "* " << name <<
			     " object on the stack at address 0x... " << address <<
			     " of size " << sizeof(T) << " bytes" <<
				std::endl;
}



#endif /* SRC_TOOLS_H_ */
