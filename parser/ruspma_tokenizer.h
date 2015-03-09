#ifndef RUSPMA_TOKENIZER_H
#define RUSPMA_TOKENIZER_H

typedef struct ruspma_tokenizer
{
  char **(*tokenize)(char*);
}ruspma_tokenizer;

#endif
