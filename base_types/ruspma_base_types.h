#ifndef RUSPMA_BASE_TYPES_H
#define RUSPMA_BASE_TYPES_H

/* Value types */
enum { RUSPMA_ATOM, RUSPMA_LIST };

/* Atom types */
enum { RUSPMA_SYMBOL, RUSPMA_KEYWORD, RUSPMA_STRING,
       RUSPMA_DOUBLE, RUSPMA_INT, RUSPMA_CLOSURE,
       RUSPMA_FUNCTION };

#endif