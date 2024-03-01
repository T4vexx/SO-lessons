all: cpu mem threads io

clean: 
	rm -f cpu mem thres io

cpu: cpu.c ./1lesson-dependencies/common.h
	gcc -o cpu cpu.c -Wall

mem: mem.c  ./1lesson-dependencies/common.h
	gcc -o mem mem.c -Wall

threads: threads.c  ./1lesson-dependencies/common.h ./1lesson-dependencies/common_threads.h
	gcc -o threads threads.c -Wall -pthread

io: io.c ./1lesson-dependencies/common.h
	gcc -o io io.c -Wall
