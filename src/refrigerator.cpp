#include "refrigerator.h"

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

bool refrigerator::is_valid_temperature(int temperature_C) {
		static const int MIN_TEMP = -40;
		static const int MAX_TEMP = 0;
		return (MIN_TEMP <= temperature_C and temperature_C <= MAX_TEMP);
}

std::ostream & operator<<(std::ostream & sink, const refrigerator & object) {
	if(object.working()) {
		sink << "Refrigerator[" << object.get_temperature() << "C]";
	}
	else {
		sink << "Refrigerator[OFF]";
	}
	return sink;
}
