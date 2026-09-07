#include "verbalized.h"

/**
 * @param number must be >= 0
 * @return the result of the verbalization, can be NULL to indicate failed verbalization
 * The caller now owns it and has the reponsibility to free it using the appropriate function provided by this library.
 * (Do not directly use free())
 */
Verbalized* verbalize(int number);
