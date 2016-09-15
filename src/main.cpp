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

// This is getting unwielding for two reasons, one practical and one conceptual.
// The practical reason is that the refrigerator class is defined and declared
// in our main.cpp file and there is too much code to move through.
// The conceptual reason is that another programmer can't reuse the class in
// his program unless he copy-pastes the class definition and, even more so
// the conceptual problem is that, as it is, the refrigerator class has its
// implementation available and anyone can change how start() or any other
// method works or, even if they don't change them write code that uses a
// refrigerator based on assumptions on how its methods work, as oppose to
// just seeing the interface.
//
// For this reason we moved the refrigerator class outside in its own files.
// One refrigerator.h HEADER FILE which contains only the interface and a
// refrigerator.cpp IMPLEMENTATION FILE which contains the actual functionality
// of a refrigerator.
//
// You can look at the build products and see that refrigerator.cpp is compiled
// independently into machine code as refrigerator.o (OBJECT FILE).
// Now main.cpp can just use the refrigerator.h HEADER which allows checks at
// compile time that calls to refrigerator methods are syntactically correct
// but re-use the refrigerator.o OBJECT FILE directly after compilation.
// If we don't change the refrigerator implementation, we can just re-use the
// object file and skip compilation.
// Even more so, we can give another programmer just the header and the object
// file and he can use a refrigerator without actually seeing the implementation
// code (!)

// Now we simply include the header and have the class available (just like when
// you have std::cout available when you include iostream.
// The difference is that iostream is a system-wide header and it is included
// with angle brackets <iostream> and the compiler will know to look in the 
// standard location of headers on this OS, while our refrigerator is local to
// this project and is included in double quotes "refrigerator.h" which means
// the compiler will look for it in the project directory.
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
