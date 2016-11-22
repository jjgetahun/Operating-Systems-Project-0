#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

int glob_count = 0;

struct timeval glob_start, glob_end;

void sigfpe_handler(int signum) {

    if (glob_count == 0)
        gettimeofday(&glob_start, NULL);

    if (glob_count < 100000)
        glob_count++;

    else {

        gettimeofday(&glob_end, NULL);

        printf("Exceptions Occurred: %d\n", glob_count);

        long int interval = ((glob_end.tv_sec*1000000)+glob_end.tv_usec)-((glob_start.tv_sec*1000000)+glob_start.tv_usec);

        float interval_in_ms = (float)interval/1000.0f;

        printf("Total Elapsed Time: %.3f ms\n", interval_in_ms);

        printf("Average Time Per Exception: %.8f ms\n", interval_in_ms/(float)glob_count);

        exit(0);

    }
 
}

int main (int argc, char ** argv) {

    int x = 1;
    int y = 2;
    int z = 0;

    signal(SIGFPE, sigfpe_handler);

    x = y/z;

    return 0;

}
