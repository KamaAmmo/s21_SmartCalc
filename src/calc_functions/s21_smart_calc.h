#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H
#include <stdbool.h>

#define EPS 1e-6
#define STEPS 600
#define STR_SIZE 256
#define LONG_STR_SIZE 512

typedef struct node {
  char data[10];
  double num;
  struct node *next;
} node;

typedef node *stack;
// stack
char isEmpty(stack top);
void push(stack *top, char *data);
char *pop(stack *top);
void destroy(stack *top);
void pushNum(stack *top, double info);
double popNum(stack *st);
double peak(stack st);
// //RPN
bool isOperator(char ch);
bool isOpenScope(char ch);
bool isCloseScope(char ch);
int isFun(char *str);  // if is's a function it will returns its len, else 0
int getPriority(char *ch);
char *s21_parser(char *str);
double s21_compute(char *str, double *x);
void computeOper(char *str, stack *st, double a, double b);
double s21_smart_calc(char *str, double *x);

// //helpers
void printOper(char **ptr, char *oper);
double convertStrToNum(char **str);
void printChar(char **write, char *read);
void convertChToStr(char *dest, char **src, int len);
bool s21_isCorrectInput(char *str);
void doOperation(char *str, stack *st);
bool isCorrectVal(char *str, stack *st);
#endif