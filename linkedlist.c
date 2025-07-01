#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

IntNode *IntNode_create(int value) {
  IntNode *node = malloc(sizeof(IntNode));
  if (node == NULL) {
    perror("memory allocation for IntNode failed");
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  return node;
}

void IntNode_prepend(IntNode **list, int value) {
  if (list == NULL)
    return;

  IntNode *node = IntNode_create(value);
  if (node == NULL)
    return;

  node->next = *list;
  *list = node;
}

void IntNode_append(IntNode **list, int value) {
  IntNode *node = IntNode_create(value);
  if (node == NULL) {
    return;
  }

  if (*list == NULL) {
    *list = node;
    return;
  }

  IntNode *head = *list;
  while (head->next != NULL) {
    head = head->next;
  }

  head->next = node;
}

int IntNode_length(IntNode **list) {
  if (list == NULL) {
    return 0;
  }

  int length = 0;

  IntNode *head = *list;
  while (head != NULL) {
    head = head->next;
    length++;
  }

  return length;
}

void IntNode_insert(IntNode **list, int index, int value) {
  if (list == NULL) {
    return;
  }

  if (index < 0 || index > IntNode_length(list)) {
    return;
  }

  if (index == 0) {
    IntNode_prepend(list, value);
    return;
  }

  IntNode *node = IntNode_create(value);
  if (node == NULL) {
    return;
  }

  int current_index = 0;
  IntNode *head = *list;
  while (head->next != NULL && current_index < index - 1) {
    head = head->next;
    current_index++;
  }

  node->next = head->next;
  head->next = node;
}

void IntNode_delete(IntNode **list, int index) {
  if (index < 0 || index > IntNode_length(list)) {
    return;
  }

  if (index == 0) {
    IntNode *to_delete = *list;
    *list = to_delete->next;
    free(to_delete);
    return;
  }

  int current_index = 0;
  IntNode *head = *list;
  while (head->next != NULL && current_index < index - 1) {
    head = head->next;
    current_index++;
  }

  if (head->next == NULL) {
    return;
  }

  IntNode *to_delete = head->next;
  head->next = to_delete->next;
  free(to_delete);
}

IntNode *IntNode_get(IntNode **list, int index) {
  if (index < 0) {
    return NULL;
  }

  int current_index = 0;
  IntNode *head = *list;
  while (head != NULL) {
    if (current_index == index) {
      return head;
    }
    head = head->next;
    current_index++;
  }

  return NULL;
}

void IntNode_free(IntNode **list) {
  IntNode *tmp;
  IntNode *head = *list;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
  *list = NULL;
}
