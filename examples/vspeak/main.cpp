#include "vtranslate.h"
#include <iostream>
#include "common.h"

int main(int argc, char ** argv) {
    std::cout << "Hello, World!" << std::endl;
   
    gpt_params params;

    if (!gpt_params_parse(argc, argv, params)) {
        return 1;
    }

    // Example usage
    Task task = getTaskFromString(params.task.c_str());
    if (task == INVALID_TASK) {
        printf("Invalid task string\n");
    } else {
        printf("Valid task: %d\n", task);
    }

    std::string model_name = params.model;
    std::string vocoder_name = params.vocoder;

    // Create an instance of Translator
    VTranslate translator(model_name, vocoder_name);

    // Example input and task for prediction
    std::string input = "Hello, world!";
    std::string t_lang = "en"; // Target language
    std::string s_lang = "en"; // Source language

    // Call the predict method
    auto res = translator.predict(input, task, t_lang, s_lang);
    auto result = std::get<0>(res);

    // Print the result
    std::cout << "Prediction result: " << result << std::endl;

    return 0;
}

//1) Get all this stuff into hard coded
//2) add arguments for all of it 