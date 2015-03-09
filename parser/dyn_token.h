#ifndef DYN_TOKEN_H
#define DYN_TOKEN_H

typedef struct dyn_token
{
  char *token;
  struct dyn_token *next_token;
}dyn_token;

#endif
