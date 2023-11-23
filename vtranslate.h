typedef enum {
    S2ST, S2TT, T2ST, T2TT, ASR, INVALID_TASK
} Task;

Task getTaskFromString(const char* taskStr);