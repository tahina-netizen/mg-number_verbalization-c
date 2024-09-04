#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../include/verbalized.h"
#include "../include/verbalize.h"

static void myassert(bool cond, const char* msg) {
    if (!cond) {
        puts(msg);
        assert(0);
    }
}

static void _can_verbalize_number(int number, const char* expected_str_repr) {
    assert(number >= 0);

    Verbalized* actual = verbalize(number);
    char msg[500];

    sprintf(msg, "%d expected: %s, actual: %s", number, expected_str_repr, verbalized_str(actual));
    myassert(!strcmp(expected_str_repr, verbalized_str(actual)), msg);

    verbalized_delete(actual);
}

int main(void) {
    printf("Running tests ...\n");

    // testing for single digits
    _can_verbalize_number(0, "aotra");
    _can_verbalize_number(1, "iray");
    _can_verbalize_number(2, "roa");
    _can_verbalize_number(3, "telo");
    _can_verbalize_number(4, "efatra");
    _can_verbalize_number(5, "dimy");
    _can_verbalize_number(6, "enina");
    _can_verbalize_number(7, "fito");
    _can_verbalize_number(8, "valo");
    _can_verbalize_number(9, "sivy");

    // testing 2 digit numbers
    _can_verbalize_number(42, "roa amby efatra folo");
    _can_verbalize_number(69, "sivy amby enina folo");

    // testing 3 digit numbers
    _can_verbalize_number(420, "roa folo amby efatra zato");
    _can_verbalize_number(666, "enina amby enina folo sy enina zato");
    _can_verbalize_number(799, "sivy amby sivy folo sy fito zato");
    _can_verbalize_number(110, "folo amby zato");

    // testing 4 digit numbers
    _can_verbalize_number(1482, "roa amby valo folo sy efatra zato sy arivo");
    _can_verbalize_number(7985, "dimy amby valo folo sy sivy zato sy fito arivo");
    _can_verbalize_number(9009, "sivy amby sivy arivo");
    _can_verbalize_number(2010, "folo amby roa arivo");

    // testing 5 digit numbers
    _can_verbalize_number(11223, "telo amby roa folo sy roa zato sy arivo sy iray alina");
    
    // TODO: more ...

    // TODO: testing edge cases 
    _can_verbalize_number(10, "folo");
    _can_verbalize_number(100, "zato");
    _can_verbalize_number(1000, "arivo");
    _can_verbalize_number(10000, "iray alina");
    _can_verbalize_number(100000, "iray etsy");
    _can_verbalize_number(1000000, "iray tapitrisa");
    _can_verbalize_number(10000000, "iray lavitrisa");

    printf("[OK] all test passed :)\n");

    return 0;
}

