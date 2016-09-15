#include "refrigerator.h"

const char * DEFAULT_BRAND = "A.C.M.E.";

refrigerator::refrigerator() {
	is_working = false;
	current_temperature = 0; //TODO
	this->brand_name = DEFAULT_BRAND;
}

refrigerator::refrigerator(const char * brand_name) {
	is_working = false;
	current_temperature = 0; //TODO
	this->brand_name = brand_name;
}

void refrigerator::start() {
		is_working = true;
}

void refrigerator::stop() {
		is_working = false;
}

bool refrigerator::working() const {
		return (is_working);
}

void refrigerator::set_temperature(int temperature_C) {
		if( is_valid_temperature(temperature_C) ) {
			current_temperature = temperature_C;
		}		
}

int refrigerator::get_temperature() const {
		return current_temperature;
}

const char * refrigerator::brand() const {
	return brand_name;
}

bool refrigerator::is_valid_temperature(int temperature_C) {
		static const int MIN_TEMP = -40;
		static const int MAX_TEMP = 0;
		return (MIN_TEMP <= temperature_C and temperature_C <= MAX_TEMP);
}

std::ostream & operator<<(std::ostream & sink, const refrigerator & object) {
	if(object.working()) {
		sink << "Refrigerator " << object.brand_name << "[" << object.get_temperature() << "C]";
	}
	else {
		sink << "Refrigerator " << object.brand_name << "[OFF]";
	}
	return sink;
}
