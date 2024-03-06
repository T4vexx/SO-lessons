#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("Hello (pid:%d)\n",(int) getpid());
	int rc= fork();
	if(rc< 0) { // fork failed;exit 
		fprintf(stderr,"forkfailed\n");
		exit(1);
	} else if (rc == 0) {
		printf("child (pid:%d)\n", (int) getpid());
	} else {
		int rc_wait = wait(NULL);
		printf("parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	}
	return 0;
}
