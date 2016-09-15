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
	void stop();
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
	void set_temperature(int temperature_C);
	/**
	 * Get the internal temperature of the refrigerator.
	 */
	int get_temperature() const;
private:
	// we need a member variable to hold the started/stopped state of a refrigerator:
	bool is_working;
};


bool test_refrigerator_is_off(const refrigerator &);
bool test_start_refrigerator(refrigerator &);

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
	// notice that this is getting repetitive (if not passed, notify user, jump:
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not starting !" << std::endl;
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
	// and we need to implement start() since we use it:
	r.start();
	return(true == r.working());
}
