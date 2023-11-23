#include "vtranslate.h";
#include <string.h>
#include <stdio.h>

Task getTaskFromString(const char* taskStr) {
    if (strcmp(taskStr, "S2ST") == 0) {
        return S2ST;
    } else if (strcmp(taskStr, "S2TT") == 0) {
        return S2TT;
    } else if (strcmp(taskStr, "T2ST") == 0) {
        return T2ST;
    } else if (strcmp(taskStr, "T2TT") == 0) {
        return T2TT;
    } else if (strcmp(taskStr, "ASR") == 0) {
        return ASR;
    } else {
        return INVALID_TASK; // Or handle the error as appropriate
    }
}
