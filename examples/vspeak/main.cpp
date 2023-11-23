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

    std::string model_name = "model_card";
    std::string vocoder_name = "vocoder_card";

    // Create an instance of Translator
    VTranslate translator(model_name, vocoder_name);

    // Example input and task for prediction
    std::string input = "Hello, world!";
    std::string t_lang = "en"; // Target language
    std::string s_lang = "en"; // Source language

    // Call the predict method
    std::string result = translator.predict(input, task, t_lang, s_lang);

    // Print the result
    std::cout << "Prediction result: " << result << std::endl;

    return 0;
}

//1) Get all this stuff into hard coded
//2) add arguments for all of it 