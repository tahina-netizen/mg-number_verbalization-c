#ifndef __VERBALIZED_H__
#define __VERBALIZED_H__

#include <stdbool.h>

typedef struct {
    char* _underlying;
} Verbalized;

char* verbalized_str(Verbalized* v);

bool verbalized_equals(Verbalized a, Verbalized b);

void verbalized_delete(Verbalized* v);

#endif