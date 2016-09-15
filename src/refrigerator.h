// include guards prevent the preprocessor from including this multiple times:
#ifndef REFRIGERATOR_REFRIGERATOR_H_
#define REFRIGERATOR_REFRIGERATOR_H_

#include <ostream>

/** \brief A class that models a Refrigerator.
 *
 */
class refrigerator {
public:
	/**
	 * Turn on a refrigerator.
	 */
	void start();
	/**
	 * Turn off a refrigerator.
	 */
	void stop();
	/**
	 * Check if refrigerator is working.
	 * @return true if the refrigerator instance is started, false otherwise.
	 */
	bool working() const;
	/**
	 * Set the internal temperature of the refrigerator.
	 * @param temperature_C the new temperature, in Celsius degrees of the refrigerator.
	 */
	void set_temperature(int temperature_C);
	/**
	 * Get the internal temperature of the refrigerator.
	 */
	int get_temperature() const;

	friend std::ostream & operator<<(std::ostream & sink, const refrigerator & object);
private:
	/**
	 * Validate temperatures to be in the range of a real refrigerator:
	 * \param temperature_C temperature to check
	 * \return true if the temperature is in [-40,0]
	 */
	bool is_valid_temperature(int temperature_C);
private:
	bool is_working;
	int  current_temperature;
};

#endif // REFRIGERATOR_REFRIGERATOR_H_
