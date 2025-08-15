#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct st_t {
	item_t *base;
	item_t *top;
	int size;
	struct st_t *previous;
} Stack;

Stack *create_stack(int size) {
	Stack *st;
	st = (Stack *) malloc(sizeof(Stack));
	st->base = (item_t *) malloc(size * sizeof(item_t));
	st->size = size;
	st->previous = NULL;
	st->top = st->base;
	return st;
}

int empty_stack(Stack *st) {
	return (st->top == st->base) && (st->previous == NULL);
}

void push(item_t x, Stack *st) {
	if (st->top >= st->base + st->size) {
		Stack *tmp = create_stack(st->size);
		tmp->previous = st;
		st = tmp;
	}
	*(st->top) = x;
	st->top += 1;
}

void print_empty(Stack *st) {
	if (empty_stack(st)) printf("stack is empty\n");
	else printf("stack is not empty\n");
}

item_t pop(Stack *st) {
	if (st->top == st->base) {
		Stack *tmp = st;
		st = st->previous;
		free(tmp->base);
		free(tmp);
	}
	st->top -= 1;
	return *(st->top);
}

item_t top_element(Stack *st) {
	if (st->top == st->base)
		return *(st->previous->top - 1);
	return *(st->top - 1);
}

void remove_stack(Stack *st) {
	Stack *prev;
	do {
		prev = st->previous;
		free(st->base);
		free(st);
		st = prev;
	} while (st != NULL);
}


int main() {
	Stack *st = create_stack(10);
	push(4, st);
	print_empty(st);
	printf("top of stack is %d\n", top_element(st));
	item_t a = pop(st);
	printf("popped %d\n", a);
	print_empty(st);
	remove_stack(st);
	return 0;
}
