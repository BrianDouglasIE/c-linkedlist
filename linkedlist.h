#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct IntNode {
  struct IntNode *next;
  int value;
} IntNode;

IntNode *IntNode_create(int value);
void IntNode_prepend(IntNode **list, int value);
void IntNode_append(IntNode **list, int value);
void IntNode_insert(IntNode **list, int index, int value);
int IntNode_length(IntNode **list);

#endif
