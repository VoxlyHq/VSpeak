// Translator.h

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include <memory>
#include <vector>
#include <map>
// Include other necessary headers, e.g., for tensors, models, etc.

typedef enum {
    S2ST, S2TT, T2ST, T2TT, ASR, INVALID_TASK
} Task;

Task getTaskFromString(const char* taskStr);

enum class Modality {
    SPEECH, TEXT
};


struct vtranslate_context {
};
struct vtranslate_state {
};


class TextTokenzier {
};

class UnitTokenzier {
};

class WaveformToFbankConverter{
};

class Collater{
};

class AudioDecoder{
};

class Vocoder{
};

class VTranslate {
public:
    VTranslate(std::string model_name, std::string vocoder_name);

    std::string predict(const std::string& input, Task task, const std::string& tgt_lang, const std::string& s_lang);

    ~VTranslate();

private:
      vtranslate_context ctx;
      vtranslate_state state;
      std::string model_path;
};

#endif // TRANSLATOR_H