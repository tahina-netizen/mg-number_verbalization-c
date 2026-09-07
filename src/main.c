#include <stdio.h>
#include "verbalize.h"

void _verbalise(int number) {
    Verbalized* res = verbalize(number);
    printf("%d %s\n", number, verbalized_str(res));
}

int main(void) {
    _verbalise(0);
    _verbalise(11);
    _verbalise(123);
    _verbalise(7898);
    _verbalise(10000);
    _verbalise(123456);
    _verbalise(1000000);
    _verbalise(123456789);
}


