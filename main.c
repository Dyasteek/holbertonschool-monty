#include "monty.h"

int main()
{
    stack_t *stack = NULL;

    arg = 1;
    push(&stack);
    arg = 2;
    push(&stack);
    arg = 3;
    push(&stack);
    pall(&stack);
    free_node(stack);
    return 0;
}