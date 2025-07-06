#include <stdlib.h>
#include <stdio.h>

typedef struct Point {
	char *name;
	int x, y;
} Point;

int main(void) {
	Point *p = malloc(sizeof(Point));
	if (p == NULL) {
		perror("allocation error");
		exit(1);
	}

	(*p).name = "A";
	(*p).x = 1;
	(*p).y = 2;

	printf("%s(%d, %d)\n", p->name, p->x, p->y);
	free(p);

	return 0;
}

