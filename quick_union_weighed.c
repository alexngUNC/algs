#include <stdio.h>

#define N 10

// half path compression implemented Program 1.4
int main() {
	int p, q, id[N], size[N];
	int p_root, q_root;
	// init id array
	for (int i=0; i<N; i++) {
		id[i] = i; size[i] = 1;
	}
	while (scanf("%d %d", &p, &q) == 2) {
		for (p_root=p; p_root != id[p_root]; p_root=id[p_root])
			id[p_root] = id[id[p_root]];
		for (q_root=q; q_root != id[q_root]; q_root=id[q_root])
			id[q_root] = id[id[q_root]];
		if (p_root == q_root) continue;
		int p_root_size = size[p_root];
		int q_root_size = size[q_root];
		if (p_root_size > q_root_size) {
			id[q_root] = p_root;
			size[p_root] += q_root_size;
		} else {
			id[p_root] = q_root;
			size[q_root] += p_root_size;
		}
		printf("%d %d\n", p, q);
	}
	return 0;
}
