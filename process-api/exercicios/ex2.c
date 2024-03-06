#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("Hello (pid:%d)\n", (int) getpid());
  int arq = open("./test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (arq == -1) {
    perror("Erro ao abrir o arquivo");
    exit(1);
  } 
  ssize_t iQtdeWrite;
  char aBuffer[100];
	int rc = fork();
	if(rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// filho (novo processo)
    strcpy(aBuffer,"Esta linha foi gravada pelo filho.");
    iQtdeWrite = write (arq, &aBuffer, strlen(aBuffer));
    printf("filho gravou %d", iQtdeWrite);
		printf("filho (pid:%d)\n", (int) getpid());
	} else {
    wait(NULL); // comente para ser gravado primeiro pelo pai, pois a execução assim espera o filho terminar
    strcpy(aBuffer,"Esta linha foi gravada pelo pai.");
    iQtdeWrite = write (arq, &aBuffer, strlen(aBuffer));
    printf("pai gravou %d", iQtdeWrite);
		printf("pai de %d (pid:%d)\n", rc, (int) getpid());
	}
  close(arq);
	return 0;
}
