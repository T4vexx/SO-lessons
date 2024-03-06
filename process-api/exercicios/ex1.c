#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("Hello (pid:%d)\n", (int) getpid());
  int x = 100;
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// filho (novo processo)
    x = 200;
		printf("filho (pid:%d x = %d)\n", (int) getpid(),x);
	} else {
    x = 150;
		printf("pai de %d (pid:%d x = %d)\n", rc, (int) getpid(), x);
	}
	return 0;
}
