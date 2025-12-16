#ifndef HEADER_H
#define HEADER_H

#define STACK_HEADER_SIZE sizeof(struct StackHeader)
struct StackHeader
{
  void *stack_cursor;
  void *stack_start;
  int stack_max_size;
};

#endif
