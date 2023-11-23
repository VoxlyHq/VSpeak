#include "vtranslate.h"
#include <iostream>

int main(int argc, char ** argv) {
    std::cout << "Hello, World!" << std::endl;

    // Example usage
    Task task = getTaskFromString("S2ST");
    if (task == INVALID_TASK) {
        printf("Invalid task string\n");
    } else {
        printf("Valid task: %d\n", task);
    }

    return 0;
}