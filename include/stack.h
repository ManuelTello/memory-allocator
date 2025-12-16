#ifndef STACK_H
#define STACK_H

struct StackHeader stack_create(int size);
void *stack_alloc(struct StackHeader *header, int size);
void stack_free(struct StackHeader *header, void *pointer, bool do_zero_out);

#endif
