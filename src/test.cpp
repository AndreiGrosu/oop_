#include <cassert>
#include "test.h"
#include "refrigerator.h"


bool test_refrigerator_is_off() {
	refrigerator fridge;
	return (false == fridge.working());
}

bool test_refrigerator_starts() {
	refrigerator fridge;
	fridge.start();
	return fridge.working();
}

bool test_refirgerator_changes_temperature() {
	refrigerator fridge;
	fridge.start();
	assert(fridge.working());
	const int freezing = -10;
	fridge.set_temperature(freezing);
	return (freezing == fridge.get_temperature());
}

bool test_refirgerator_does_not_change_temperature() {
	refrigerator fridge;
	fridge.start();
	assert(fridge.working());
	const int current_temp = fridge.get_temperature();
	const int boiling = 100;
	fridge.set_temperature(boiling);
	return (current_temp == fridge.get_temperature());
}

bool test_refrigerator_stopped_temperature_change() {
	refrigerator fridge;
	const int current_temp = fridge.get_temperature();
	const int freezing = -10;
	assert(not fridge.working());
	fridge.set_temperature(freezing);
	return (current_temp == fridge.get_temperature());
}

bool test_refrigerator_has_brand_name() {
	const char * text = "PENGUIN";
	std::string brand(text);
	refrigerator fridge(brand.c_str());
	brand[0] = 'M';
	std::string original(text);
	return (original == fridge.brand());
}

bool test_refrigerator_stops() {
	refrigerator fridge;
	fridge.start();
	assert(fridge.working());
	fridge.stop();
	return (false == fridge.working());
}
