#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void) {
	int pid = fork();

	if (pid < 0) {
		perror("[parent]: error during fork\n");
		exit(1);
	}

	if (pid == 0) {
		int pid = getpid();
		printf("[child %d]: start\n", pid);
		close(STDOUT_FILENO);
		printf("[child %d]: write in the closed stdout\n", pid);
	} else {
		int pid = getpid();
		printf("[parent %d]: finish\n", pid);
		int cpid = wait(NULL);
		printf("[parent %d]: waited %d\n", pid, cpid);
	}
}
