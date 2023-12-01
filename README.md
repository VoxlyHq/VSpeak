# VSpeak (Voxy Speak)

Welcome to Voxy Speak(VSpeak), an open-source library revolutionizing language translation in software applications. VSpeak is a robust C++ implementation of the Meta Seams Communication library and the ambitious NLLB (No Language Left Behind) project. Our goal is to bridge communication barriers by enabling seamless translation between 200 different languages. We are targeting embedded devices

It uses the [GGML](https://github.com/ggerganov/ggml) tensor library underneath for performance. 

![VSpeak](docs/voxie.jpg)

## Features

- **Multilingual Support**: Translate between a vast range of 200 languages.
- **Audio and Text Translation**: Whether it's spoken words or written texts, VSpeak has got you covered.
- **Cross-Platform Compatibility**: VSpeak supports Kotlin bindings for Android and Swift bindings for iOS, making it a versatile choice for mobile application developers.
- **Real-Time Translation**: Experience near-instantaneous translation for fluid, natural communication.
- **High Accuracy**: Powered by advanced algorithms to ensure precise translations.

## Getting Started

To start using VSpeak in your project, follow these simple steps:

### Prerequisites

Ensure you have a C++ compiler and environment set up. VSpeak is compatible with most modern C++ environments.

### Installation

1. Clone the VSpeak repository:
   ```bash
   git clone https://github.com/voxlyhq/vspeak.git

   LAMA_METAL=1 LLAMA_DEBUG=1 make -j 4 main 

   ./main -p "i just ate" --src-lang=eng --tgt-lang=tha --log-enable -m  vspeak.gguf
   ```
*Remove the LLAMA_METAl if you aren't on OSX
   

## Download a model from hugging face

Right now its only the V1 models, please open a PR if you do other conversions

## Usage 

Right now you specify both src and target language, in future you can skip on the source.
```
-p "Text you want translated"
-tgt_lang tha
-src_lang eng
```
todo: add the speech vocoder, right now we only do text translation bits.

## To convert models 

```bash
pip3 install -r requirements.txt

python3 convert_nllb.py  --vocab-dir=tokenizer.model --ctx 4096  --start_key model --prefix_model=target_letter_decoder --outfile vspeak.gguf   multitask_unity_large.pt
bck-i-search: nllb_
```

## Contributing

We encourage contributions! If you have ideas on how to improve VSpeak or add new features, feel free to fork the repository, make your changes, and submit a pull request.

## License

VSpeak is released under the [MIT License](LICENSE).

## Acknowledgments

A huge thank you to everyone involved in the Meta Seams Communication library and the NLLB project for their groundbreaking work in language translation technology.

---

Happy translating!

