/******************************************************************************
 *
 * main.cpp
 *
 * Driver for testing the Refrigerator class.
 *
 *****************************************************************************/

#include <cstdlib>
#include <iostream>

#include "tools.h"

/*
 *  Here we declare the INTERFACE of our Refrigerator type.
 *  There are only member function declarations, no implementation code.
 *
 *  Other programmers that want to use Refrigerators in their code only
 *  need to look at this class declaration and understand HOW a Refrigerator
 *  can be used. They don't need to see the details of how start() or stop()
 *  or any other methods work.
 *
 *  So far we gave only the 'outline' of how Refrigerators are used.
 *  Notice there are no member variables in the refrigerator class so far.
 */

/** \brief A class that models a Refrigerator.
 *
 */
class refrigerator {
public:
	/**
	 * Turn on a refrigerator.
	 */
	void start();
	/**
	 * Turn off a refrigerator.
	 */
	void stop();
	/**
	 * Check if refrigerator is working.
	 * @return true if the refrigerator instance is started, false otherwise.
	 */
	bool working() const;
	/**
	 * Set the internal temperature of the refrigerator.
	 * @param temperature_C the new temperature, in Celsius degrees of the refrigerator.
	 */
	void set_temperature(int temperature_C);
	/**
	 * Get the internal temperature of the refrigerator.
	 */
	int get_temperature() const;
private:
};


int main(int argc, char * argv[]) {
	bool passed = false;

	// we create a new refrigerator instance on the stack and, surprisingly the
	// code compiles and runs !
	refrigerator test_fridge;

	// we can use the refrigerator class as it is.
	print_stack_object(test_fridge);

	// this is because, for one, we don't call any methods of test_fridge.
	// if we tried to start the refrigerator we would get a COMPILE TIME error:
	//
	// test_fridge.start(); // un-comment this line and try for yourself.
	//
	// when compiling the project:
	// Error ... undefined reference to `refrigerator::start()'
    //
	// as long as no code ever calls a method or an object (or a C function for that matter)
	// there is no error, the compiler 'sees' that it is not needed.

	return (passed)?(EXIT_SUCCESS):(EXIT_FAILURE);
}
