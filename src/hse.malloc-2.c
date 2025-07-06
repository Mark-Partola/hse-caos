#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int n, result;
} Row;

int main(void) {
	int n = 20;
	Row *r = malloc(n * sizeof(*r));

	for (int i = 0; i < n; i++) {
		r[i].n = i;
		r[i].result = i * i;
	}

	for (int i = 0; i < n; i++) {
		Row item = *(r + i);
		printf("%d * %d = %d\n", item.n, item.n, item.result);
	}

	return 0;
}
