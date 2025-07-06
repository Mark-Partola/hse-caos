#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void) {
	int workers = 5;
	pid_t pids[5];

	for (int i = 0; i < workers; i++) {
		pids[i] = fork();

		if (pids[i] < 0) {
			perror("[parent]: error during fork\n");
			exit(1);
		}

		if (pids[i] == 0) {
			printf("[child]: %d run\n", i);
			sleep(1);
			exit(100 + i);
		}
	}

	int stat;
	for (int i = 0; i < workers; i++) {
		pid_t cpid = waitpid(pids[i], &stat, 0);
		if (WIFEXITED(stat)) {
			int exitstatus = WEXITSTATUS(stat);
			printf("[parent]: child %d terminated with status %d\n", cpid, exitstatus);
		}
	}

	return 0;
}
