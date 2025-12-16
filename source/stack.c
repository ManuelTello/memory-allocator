#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include "stack.h"
#include "header.h"

struct StackHeader stack_create(int size)
{
  void *stack_addr = mmap(NULL,
			   size,
			   PROT_READ|PROT_WRITE,
			   MAP_ANONYMOUS|MAP_PRIVATE,
			   -1, 0);
  struct StackHeader header;
  header.stack_start = stack_addr;
  header.stack_cursor = stack_addr;
  header.stack_max_size = size;
  return header;
}

void *stack_alloc(struct StackHeader *header, int size)
{
  if(header->stack_cursor + size > header->stack_start + header->stack_max_size)
  {
    return NULL;
  }

  void *pointer = header->stack_cursor;
  header->stack_cursor = header->stack_cursor + size;
  return pointer;
}

void stack_free(struct StackHeader *header, void *pointer, bool do_zero_out)
{
  if(do_zero_out)
  {
    int to_zero_out = (int)((header->stack_cursor + header->stack_max_size) - pointer);
    unsigned char *byte = header->stack_cursor - to_zero_out;
    for(int i = 0; i < to_zero_out; i = i + 1)
    {
      *byte = 0;
      byte = byte + i;
    }
  }

  header->stack_cursor = pointer;
}
