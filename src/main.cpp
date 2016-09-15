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
	void start() {
		is_working = true;
	}
	/**
	 * Turn off a refrigerator.
	 */
	void stop() {
		is_working = false;
	}
	/**
	 * Check if refrigerator is working.
	 * @return true if the refrigerator instance is started, false otherwise.
	 */
	bool working() const {
		return (is_working);
	}
	/**
	 * Set the internal temperature of the refrigerator.
	 * @param temperature_C the new temperature, in Celsius degrees of the refrigerator.
	 */
	void set_temperature(int temperature_C) {
		current_temperature = temperature_C;
	}
	/**
	 * Get the internal temperature of the refrigerator.
	 */
	int get_temperature() const {
		return current_temperature;
	}
private:
	// we need a member variable to hold the started/stopped state of a refrigerator:
	bool is_working;
	int  current_temperature;
};


bool test_refrigerator_is_off(const refrigerator &);
bool test_start_refrigerator(refrigerator &);
bool test_change_refrigerator_temperature(refrigerator &);
bool test_stop_refrigerator(refrigerator &);

int main(int argc, char * argv[]) {
	bool passed = false;

	refrigerator test_fridge;
	print_stack_object(test_fridge);

	// Test that a new refrigerator is turned off:
	passed = passed or test_refrigerator_is_off(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is off when created !" << std::endl;
		goto done;
	}

	// Test that start() actually works:
	passed = passed or test_start_refrigerator(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not starting !" << std::endl;
		goto done;
	}

	// There is a software development paradigm called TEST-DRIVEN DEVELOPMENT (TDD) which
	// we are employing here.
	// In this paradigm, all types (classes) we create must be covered by tests such that
	// if we change the implementation of a class, we can run these tests and see if
	// we broke something.
	//
	// One school of thought in the TDD community sais that it is better to write the tests
	// first for a given class and then implement the functionality in that class.
	// That is, we imagine the possible uses of our new class and write a test program
	// that should cover all these usages and then we procede to implement the class such
	// that our test program completes correctly.
	//
	// We've done the first two tests along with their implementation so now let's try
	// writing in advance all unit tests for our refrigerator and then implement the
	// functionality.

	// Test that we can change the temperature of a refrigerator:
	passed = passed or test_change_refrigerator_temperature(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : can set refrigerator temperature !" << std::endl;
		goto done;
	}

	// Test that a working refrigerator can be stopped:
	passed = passed or test_stop_refrigerator(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not stopping !" << std::endl;
		goto done;
	}

	// let users of this program know we have a working refrigerator.
	std::cout << "ALL TESTS PASSED !" << std::endl;
done:
	return (passed)?(EXIT_SUCCESS):(EXIT_FAILURE);
}

// Implementation of test functions goes here so there are not in our way when we look at what
// main() does:

/**
 * Tests if the given refrigerator is not working.
 */
bool test_refrigerator_is_off(const refrigerator & r) {
	return (false == r.working());
}

/**
 * Tests if a refrigerator actually starts.
 */
bool test_start_refrigerator(refrigerator & r) {
	r.start();
	return(true == r.working());
}

/**
 * Test that a change in temperature is actually performed.
 */
bool test_change_refrigerator_temperature(refrigerator & r) {
	const int freezing = -10;
	r.set_temperature(freezing);
	return (freezing == r.get_temperature());
}

/**
 * Tests if a refrigerator actually stops.
 */
bool test_stop_refrigerator(refrigerator & r) {
	r.stop();
	return(false == r.working());
}
