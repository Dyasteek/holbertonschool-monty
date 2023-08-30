#ifndef MONTY_H
#define MONTY_H

/*      libs    */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*      end     */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*      ext     */
extern int arg;
/*      end     */

/*	Prototypes	*/
void push(stack_t **stack, __attribute__((unused)) unsigned int line);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line);
void free_nudes(stack_t **stack);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
/*	end	*/

/*      text work       */
char *readin(const char *name);
char **readtext(char *text);
char *rdline(char *line, unsigned int linu, stack_t **stack, char *e1, char **e2);
/*      end     */

#endif