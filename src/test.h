#ifndef REFRIGERATOR_TEST_H_
#define REFRIGERATOR_TEST_H_

/**
 * Test case :
 * A newly created refrigerator is off.
 */
bool test_refrigerator_is_off();

/**
 * Test case :
 * A newly created refrigerator is start()-ed and is indeed so.
 */
bool test_refrigerator_starts();

/**
 * Test case :
 * A started refrigerator changes temperature after a valid set_temperature().
 */
bool test_refirgerator_changes_temperature();

/**
 * Test case :
 * A started refrigerator does not change temperature after an invalid set_temperature().
 */
bool test_refirgerator_does_not_change_temperature();

/**
 * Test case:
 * A stopped refrigerator won't change its temperature.
 */
bool test_refrigerator_stopped_temperature_change();

/**
 * Test case:
 * A new refrigerator has a valid brand name.
 */
bool test_refrigerator_has_brand_name();

/**
 * Test case:
 * A working refrigerator stops.
 */
bool test_refrigerator_stops();

#endif // REFRIGERATOR_TEST_H_
