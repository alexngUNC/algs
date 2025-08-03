#include <stdio.h>

#define N 10

int main() {
	int p, q, id[N];
	// init id array
	for (int i=0; i<N; i++)
		id[i] = i;
	while (scanf("%d %d", &p, &q) == 2) {
		int idq = id[q];
		int idp = id[p];
		if (idp == idq) continue;
		for (int i=0; i<N; i++) {
			if (id[i] == idp) id[i] = idq;
		}
		printf("%d %d\n", p, q);
	}
	return 0;
}
