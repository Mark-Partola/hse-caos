#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	int fd = open("ostep.fork-2.out", O_WRONLY | O_CREAT, 0644);
	if (fd == -1) {
		perror("[parent]: error during open");
		exit(1);
	}

	char *value = "something from parent\n";
	write(fd, value, strlen(value));

	int pid = fork();

	if (pid < 0) {
		perror("[parent]: error during fork\n");
		exit(1);
	}

	if (pid == 0) {
		printf("[child]: works\n");
		char *value = "something from forked child\n";
		write(fd, value, strlen(value));
	} else {
		printf("[parent]: works\n");
		char *value = "something from forked parent\n";
		write(fd, value, strlen(value));
	}
}
