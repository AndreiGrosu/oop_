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
#include "refrigerator.h"

bool test_refrigerator_is_off(const refrigerator &);
bool test_start_refrigerator(refrigerator &);
bool test_change_refrigerator_temperature(refrigerator &);
bool test_stop_refrigerator(refrigerator &);


// Uncomment this line to build the test with a refrigerator instance allocated
// on the heap instead of on stack:
//#define ON_HEAP

int main(int argc, char * argv[]) {
	bool passed = false;

#ifdef ON_HEAP
	refrigerator * p_test_fridge = new refrigerator;
	refrigerator & test_fridge = *p_test_fridge;
#else
	refrigerator test_fridge;
#endif

	print_stack_object(test_fridge);
	std::cout << test_fridge << std::endl;

	// Test that a new refrigerator is turned off:
	// Previously, the error was not taking into account the fact that C and C++
	// use short-circuit when evaluating expressions in logical operators.
	// in the following expression:
	//      a = f() || g()
	// if the result of f() is true then there is no point in evaluating g(), since
	// true || <antyhing> == true so the call to g() never happens !
	// the same for:
	//      a = f() && g()
	// if the result of f() is false, g() is never called because
	// false && <anthing> == false
	passed = test_refrigerator_is_off(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is off when created !" << std::endl;
		goto done;
	}

	// Test that start() actually works:
	passed = test_start_refrigerator(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not starting !" << std::endl;
		goto done;
	}

	// Test that we can change the temperature of a refrigerator:
	passed = test_change_refrigerator_temperature(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : can set refrigerator temperature !" << std::endl;
		goto done;
	}

	// Test that a working refrigerator can be stopped:
	passed = test_stop_refrigerator(test_fridge);
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not stopping !" << std::endl;
		goto done;
	}

	// let users of this program know we have a working refrigerator.
	std::cout << "ALL TESTS PASSED !" << std::endl;
done:
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
	std::cout << r << std::endl;

	// refrigerator rejects valid temperatures
  const int boiling = 100;
	r.set_temperature(boiling);
	passed = (freezing == r.get_temperature());
	std::cout << r << std::endl;

	return passed;
}

/**
 * Tests if a refrigerator actually stops.
 */
bool test_stop_refrigerator(refrigerator & r) {
	r.stop();
	return(false == r.working());
}
