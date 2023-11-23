#include "vtranslate.h";
#include "llama_trans.h"
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


std::tuple<Modality, Modality> getModalitiesFromTask(const Task* task) {
    if (*task == Task::S2ST) {
        return std::make_tuple(Modality::SPEECH, Modality::SPEECH);
    } else if (*task == Task::S2TT) {
        return std::make_tuple(Modality::SPEECH, Modality::TEXT);
    } else if (*task == Task::T2ST) {
        return std::make_tuple(Modality::TEXT, Modality::SPEECH);
    } else {
        // Assuming Task::T2TT or other cases
        return std::make_tuple(Modality::TEXT, Modality::TEXT);
    }
}

#include <iostream>
// Include other necessary headers

VTranslate::VTranslate(std::string model_name, std::string vocoder_name) 
    : ctx(), // Initialize context
      state()    // Initialize state 
{
    std::cout << "VTranslate constructed with model: " << model_name << " and vocoder: " << vocoder_name << std::endl;
    this->model_path = model_name;

    auto mparams = llama_model_default_params();


    //Raw Load main model
    llama_model * model  = llama_load_model_from_file(this->model_path.c_str(), mparams);
    if (model == NULL) {
        fprintf(stderr, "%s: error: failed to load model '%s'\n", __func__, this->model_path.c_str());
        return;
    }

    TextTokenzier text_tokenizer;
    UnitTokenzier unit_tokenizer;
    Vocoder vocoder; // Load vocoder model
    AudioDecoder audio_decoder;
    Collater collater;
    WaveformToFbankConverter waveform_to_fbank_converter;

}

VTranslate::~VTranslate() {
    std::cout << "VTranslate destructed" << std::endl;
}

std::string VTranslate::predict(const std::string& input, Task task, const std::string& tgt_lang, const std::string& s_lang) {
    std::string result = "Predicted output for input: " + input + ", Task: " + std::to_string(static_cast<int>(task)) + ", Language: " + tgt_lang;

    auto modalities = getModalitiesFromTask(&task);

    // Access the elements of the tuple
    Modality inputModality = std::get<0>(modalities);
    Modality outputModality = std::get<1>(modalities);

    // Print the modalities
    std::cout << "Input Modality: " << (inputModality == Modality::SPEECH ? "SPEECH" : "TEXT") << std::endl;
    std::cout << "Output Modality: " << (outputModality == Modality::SPEECH ? "SPEECH" : "TEXT") << std::endl;


    return result;
}

