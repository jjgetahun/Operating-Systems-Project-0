#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int glob_count = 0;

struct timeval glob_start, glob_end;

void syscall_timer() {

    gettimeofday(&glob_start, NULL);

    while (glob_count < 100000) {

        getpid();
        glob_count++;

    }

    gettimeofday(&glob_end, NULL);

}

int main (int argc, char ** argv) {

    syscall_timer();

    printf("Syscalls Performed: %d\n", glob_count);

    long int interval = ((glob_end.tv_sec*1000000)+glob_end.tv_usec)-((glob_start.tv_sec*1000000)+glob_start.tv_usec);

    float interval_in_ms = (float)interval/1000.0f;

    printf("Total Elapsed Time: %.3f ms\n", interval_in_ms);

    printf("Average Time Per Syscall: %.8f ms\n", interval_in_ms/(float)glob_count);

    return 0;

}
