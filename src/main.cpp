/******************************************************************************
 *
 * main.cpp
 *
 * Driver for testing the Refrigerator class.
 *
 *****************************************************************************/

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "tools.h"
#include "test.h"

int main(int argc, char * argv[]) {
	bool passed = false;

	passed = test_refrigerator_has_brand_name();
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator wrong brand name !" << std::endl;
		goto done;
	}

	passed = test_refrigerator_is_off();
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is off when created !" << std::endl;
		goto done;
	}

	// Test that start() actually works:
	passed = test_refrigerator_starts();
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not starting !" << std::endl;
		goto done;
	}

	// Test that we can change the temperature of a refrigerator:
	passed = test_refirgerator_changes_temperature();
	if(not passed) {
		std::cout << "TEST FAILED : can set refrigerator temperature !" << std::endl;
		goto done;
	}

	// Test that we can't change the temperature of a refrigerator with an invalid value:
	passed = test_refirgerator_does_not_change_temperature();
	if(not passed) {
		std::cout << "TEST FAILED : can't set invalid refrigerator temperature !" << std::endl;
		goto done;
	}

	// Test we can't change the temperature of a stopped refrigerator:
	passed = test_refrigerator_stopped_temperature_change();
	if(not passed) {
		std::cout << "TEST FAILED : can't change temperature of stopped refrigerator !" << std::endl;
		goto done;
	}

	// Test a started refrigerator stops:
	passed = test_refrigerator_stops();
	if(not passed) {
		std::cout << "TEST FAILED : refrigerator is not stopping !" << std::endl;
		goto done;
	}


	// let users of this program know we have a working refrigerator.
	std::cout << "ALL TESTS PASSED !" << std::endl;
done:

	return (passed)?(EXIT_SUCCESS):(EXIT_FAILURE);
}
