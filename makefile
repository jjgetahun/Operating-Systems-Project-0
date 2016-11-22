all: timer

timer: time-syscall.c
	gcc -g -o time-syscall time-syscall.c
	gcc -g -o time-signal time-signal.c

clean:
	rm -rf *.o *.dSYM time-syscall time-signal
