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
		if( is_valid_temperature(temperature_C) ) current_temperature = temperature_C;
	}
	/**
	 * Get the internal temperature of the refrigerator.
	 */
	int get_temperature() const {
		return current_temperature;
	}
private:
	/**
	 * Validate temperatures to be in the range of a real refrigerator:
	 * \param temperature_C temperature to check
	 * \return true if the temperature is in [-40,0]
	 */
	bool is_valid_temperature(int temperature_C) {
		static const int MIN_TEMP = -40;
		static const int MAX_TEMP = 0;
		return (MIN_TEMP <= temperature_C and temperature_C <= MAX_TEMP);
	}
private:
	bool is_working;
	int  current_temperature;
};


bool test_refrigerator_is_off(const refrigerator &);
bool test_start_refrigerator(refrigerator &);
bool test_change_refrigerator_temperature(refrigerator &);
bool test_stop_refrigerator(refrigerator &);


// Uncomment this line to build the test with a refrigerator instance allocated
// on the heap instead of on stack:
//#define ON_HEAP

int main(int argc, char * argv[]) {
	bool passed = false;

// These are CONDITIONAL COMPILATION PRAGMAS
// If the preprocessor sees a token called
// defined in any header or source file it will
// examine the lines between #ifdef and #else.
// Otherwise it will examine the line between
// #else and #endif and act as if the other
// two lines do not exist.
//
// This allows us to easily switch between testing
// refrigerators allocated on the heap and on the 
// stack when we build the project.
#ifdef ON_HEAP
	refrigerator * p_test_fridge = new refrigerator;
	refrigerator & test_fridge = *p_test_fridge;
#else
	refrigerator test_fridge;
#endif

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

	// Test that a working refrigerator can be stopped:
	passed = passed or test_stop_refrigerator(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not stopping !" << std::endl;
		goto done;
	}

	// let users of this program know we have a working refrigerator.
	std::cout << "ALL TESTS PASSED !" << std::endl;
done:
// make sure we delete the heap instance when compiling with ON_HEAP
#ifdef ON_HEAP
	delete p_test_fridge;
#endif
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

	// refrigerator accepts valid temperatures
	const int freezing = -10;
	r.set_temperature(freezing);
	passed = (freezing == r.get_temperature());

	// refrigerator rejects valid temperatures
  const int boiling = 100;
	r.set_temperature(boiling);
	passed = (freezing == r.get_temperature());

	return passed;
}

/**
 * Tests if a refrigerator actually stops.
 */
bool test_stop_refrigerator(refrigerator & r) {
	r.stop();
	return(false == r.working());
}
