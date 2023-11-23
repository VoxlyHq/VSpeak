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


#include <iostream>
// Include other necessary headers

VTranslate::VTranslate(std::string model_name, std::string vocoder_name) {
    std::cout << "VTranslate constructed with model: " << model_name << " and vocoder: " << vocoder_name << std::endl;
}

VTranslate::~VTranslate() {
    std::cout << "VTranslate destructed" << std::endl;
}

std::string VTranslate::predict(const std::string& input, Task task, const std::string& tgt_lang, const std::string& s_lang) {
    std::string result = "Predicted output for input: " + input + ", Task: " + std::to_string(static_cast<int>(task)) + ", Language: " + tgt_lang;

    return result;
}
