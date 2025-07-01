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
void IntNode_delete(IntNode **list, int index);
IntNode *IntNode_get(IntNode **list, int index);
void IntNode_free(IntNode **list);
int IntNode_length(IntNode **list);

#endif
