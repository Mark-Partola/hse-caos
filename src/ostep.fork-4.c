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
		const char filename[] = __FILE__ ".out";
		printf("[child %d]: opens file %s\n", pid, filename);
		close(STDOUT_FILENO);
		if (open(filename, O_CREAT | O_WRONLY, 0644) < 0) {
			perror("[child]: error during stdout file redirection\n");
			exit(1);
		}
		if (execlp("ls", "ls", "-la", NULL) < 0) {
			perror("[child]: error during exec\n");
			exit(1);
		}
	} else {
		int pid = getpid();
		printf("[parent %d]: finish\n", pid);
		int cpid = wait(NULL);
		printf("[parent %d]: waited %d\n", pid, cpid);
	}
}
