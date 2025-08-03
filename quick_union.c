#include <stdio.h>

#define N 10

int main() {
	int p, q, id[N];
	int p_root, q_root;
	// init id array
	for (int i=0; i<N; i++)
		id[i] = i;
	while (scanf("%d %d", &p, &q) == 2) {
		for (p_root=p; p_root != id[p_root]; p_root=id[p_root]) ;
		for (q_root=q; q_root != id[q_root]; q_root=id[q_root]) ;
		if (p_root == q_root) continue;
		id[p_root] = q_root;
		printf("%d %d\n", p, q);
	}
	return 0;
}
