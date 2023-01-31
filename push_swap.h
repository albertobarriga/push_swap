#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_stack
{
    int     *string;
    size_t  size;
    size_t  max_size;
}               t_stack;

