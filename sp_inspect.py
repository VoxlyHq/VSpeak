import sentencepiece as spm

# Load your SentencePiece model
sp = spm.SentencePieceProcessor(model_file='/Users/hyper/.cache/torch/hub/fairseq2/assets/tokenizers/eedae72756484b914014c3c4/tokenizer.model')

# Get the size of the vocabulary
vocab_size = sp.get_piece_size()

print(f"Vocabulary size: {vocab_size}")

# List tokens from key 0 to 10
for i in range(1, 100):  # 11 because range is exclusive of the upper bound
    token = sp.id_to_piece(i)
    print(f"Key {i}: {token}")
