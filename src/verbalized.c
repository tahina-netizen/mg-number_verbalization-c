#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "../include/verbalized.h"

char* verbalized_str(Verbalized* v) {
    assert(v);
    return v->_underlying;
}

bool verbalized_equals(Verbalized a, Verbalized b) {
    return strcmp(a._underlying, b._underlying) == 0;
}

void verbalized_delete(Verbalized* v) {
    free(v->_underlying);
    free(v);
}