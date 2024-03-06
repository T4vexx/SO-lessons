#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("Hello (pid:%d)\n", (int) getpid());
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// filho (novo processo)
		printf("filho (pid:%d)\n", (int) getpid());
	} else {
		printf("pai de %d (pid:%d)\n", rc, (int) getpid());
	}
	return 0;
}
