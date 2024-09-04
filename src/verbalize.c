#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/verbalized.h"
#include "../include/verbalize.h"

#define MAX_LENGTH_STR (500)

static const char* _verbalize_digit(int digit) {
    assert(digit >= 0 && digit < 10);

    static char* digit_to_name[] = {"aotra", "iray", "roa", "telo", "efatra", "dimy", "enina", "fito", "valo", "sivy"}; 

    return digit_to_name[digit];
}

static int _verbalize(int* digits, int digits_size, char* res) {
    static char* power10_to_name[] = {"!!!", "folo", "zato", "arivo", "alina", "etsy", "tapitrisa", "lavitrisa"};

    bool use_amby = true; // for the first time we use "amby", then for the rest we use "sy"
    for (int i=0; i < digits_size; i++) {
        int current_digit = digits[i];

        if (i == 0) {
            if (current_digit > 0) {
                strcat(res, _verbalize_digit(current_digit));
            }
        } else if (current_digit > 0) {
            if (strlen(res) > 0) {
                strcat(res, use_amby ? " amby " : " sy ");
                use_amby = false;
            }

            if (i > 3 || current_digit > 1) { // because we do not say "iray folo/alina/arivo" but instead just "folo/alina/arivo"
                strcat(res, _verbalize_digit(current_digit));
                strcat(res, " ");
            }

            assert(i >= 1 && i <= 7); // we only know the names up to 10^7
            strcat(res, power10_to_name[i]);
        }
    }

    return 0;
}

static int _verbalize_generic_case(int number, char* res) {
    /* Handling weird exceptional cases */
    if (number == 10) {
        strcat(res, "folo");
        return 0;
    }

    if (number == 100) {
        strcat(res, "zato");
        return 0;
    }

    if (number == 1000) {
        strcat(res, "arivo");
        return 0;
    }

    /* Code for extracting digits taken from: https://stackoverflow.com/a/515623 */

    /* count number of digits */
    int c = 0; /* digit position */
    int n = number;

    while (n != 0) {
        n /= 10;
        c++;
    }

    int digits_array[c]; // TODO: using VLA, may lead to stack overflow if c is too big

    c = 0;    
    n = number;

    /* extract each digit */
    while (n != 0) {
        digits_array[c] = n % 10;
        n /= 10;
        c++;
    }

    return _verbalize(digits_array, c, res);;
}

Verbalized* verbalize(int number) {
    assert(number >= 0);

    char* res = malloc(MAX_LENGTH_STR);
    assert(res);
    res[0] = '\0';

    Verbalized* res_wrapper = malloc(sizeof(Verbalized));
    assert(res_wrapper);

    if (number < 10) {
        strcat(res, _verbalize_digit(number));
    } else {
        char tmp[MAX_LENGTH_STR];
        tmp[0] = '\0';

        assert(!_verbalize_generic_case(number, tmp));
        strcat(res, tmp);
    }

    res_wrapper->_underlying = res;
    return res_wrapper;
}

