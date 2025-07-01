#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_linkedlist() {
  IntNode *list = IntNode_create(1);
  assert(list->value == 1);

  IntNode_prepend(&list, 0);
  assert(list->value == 0);

  IntNode_append(&list, 2);
  assert(list->next->next->value == 2);

  assert(IntNode_length(&list) == 3);
  assert(IntNode_length(NULL) == 0);

  IntNode_insert(&list, 1, 100);
  assert(IntNode_length(&list) == 4);
  assert(list->next->value == 100);

  IntNode *head = list;
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL \n");
}

int main() {
  test_linkedlist();

  return 0;
}
