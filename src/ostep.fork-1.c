#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	char name[] = "- some name";
	printf("before fork\n");

	int pid = fork();

	if (pid < 0) {
		printf("[parent]: error during fork\n");
		exit(1);
	}

	if (pid == 0) {
		printf("[child]: forked\n");
		printf("[child]: name %s\n", name);
		name[0] = 'c';
		printf("[child]: name %s\n", name);
	} else {
		printf("[parent]: forked\n");
		printf("[parent]: name %s\n", name);
		name[0] = 'p';
		printf("[parent]: name %s\n", name);
	}
}
