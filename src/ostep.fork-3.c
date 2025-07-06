#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int chan[2];
	if (pipe(chan) < 0) {
		perror("[parent]: error during pipe");
		exit(1);
	}

	int pid = fork();

	if (pid < 0) {
		printf("[parent]: error during fork\n");
		exit(1);
	}

	if (pid == 0) {
		printf("[child]: start\n");
		sleep(1);
		printf("[child]: end\n");
		close(chan[0]);
	} else {
		close(chan[1]);
		char buff[1];
		read(chan[0], buff, 1);
		printf("[parent]: start\n");
		sleep(1);
		printf("[parent]: end\n");
	}
}
