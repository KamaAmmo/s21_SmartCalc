#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "s21_smart_calc.h"

void display(stack top) {
  while (top != NULL) {
    putchar((*top).data);
    top = (*top).next;
  }
  putchar(' ');
}

char isEmpty(stack top) {
  if (top == NULL) return true;
  return false;
}

void push(stack *top, char info) {
  node *newnode = (node *)malloc(sizeof(node));
  newnode->data = info;
  newnode->next = *top;
  *top = newnode;
}

char pop(stack *top) {
  if (isEmpty(*top)) {
    // printf("Stack is empty");
    return -1;
  }
  char result = (*top)->data;
  node *temp = *top;
  *top = (*top)->next;
  free(temp);
  return result;
}

char peak(stack top) { return (*top).data; }

void destroy(stack *top) {
  while (*top != NULL) {
    node *temp = (*top);
    *top = (*top)->next;
    free(temp);
  }
}
