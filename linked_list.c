#include <stdio.h>

struct Node {
	int val;
	struct Node *next;
}

void deleteList(struct Node *head) {
	struct Node *p = head;
	while (p) {
		struct Node *t = p->next;
		free(p);
		p = t;
	}
}

int main() {
	return 0;
}
