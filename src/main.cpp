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

	// Test that we can change the temperature of a refrigerator:
	passed = passed or test_change_refrigerator_temperature(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : can set refrigerator temperature !" << std::endl;
		goto done;
	}

	// however this is not quite ok ... let's look at the temperature test
	// function to see why:

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
	bool passed = false;

	// here I am setting a 'valid' temperature, that is something in line
	// with what a real refrigerator would accept in order to function properly:
	const int freezing = -10;
	r.set_temperature(freezing);
	passed = (freezing == r.get_temperature());

	// however a real user of our refrigerator class could as well do this
	// and, as you can see, the tests still succeed !
  const int boiling = 100;
	r.set_temperature(boiling);
	passed = (boiling == r.get_temperature());

	return passed;
}

/**
 * Tests if a refrigerator actually stops.
 */
bool test_stop_refrigerator(refrigerator & r) {
	r.stop();
	return(false == r.working());
}
