#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void copy(int old, int new);
int check(int old, int new);


int main(int argc, char *argv[]) {
    int fdold, fdnew;
    if (argc != 3) {
        printf("Need 2 arguments for copy program\n");
        exit(1);
    }

    fdold = open(argv[1], O_RDONLY);
    if (fdold == -1) {
        printf("Cannot open file %s\n", argv[1]);
        exit(1);
    }

    fdnew = open(argv[2], O_RDWR);
    if (fdnew == -1) {
        printf("Cannot create file %s\n", argv[2]);
        close(fdold);
        exit(1);
    }

    if (check(fdold, fdnew) == 0){
        copy(fdold, fdnew);
        printf("File copied successfully\n");
    }
    else{
        printf("Contents Already Present\n");
    }

    close(fdold);
    close(fdnew);
    exit(0);
}

void copy(int old, int new) {
    char buffer[2048];
    ssize_t count;

    while ((count = read(old, buffer, sizeof(buffer))) > 0) {
        write(new, buffer, count);
    }
}

int check(int old, int new) {
    char buffer_old[2048];
    char buffer_new[2048];
    ssize_t count_old, count_new;

    while ((count_old = read(old, buffer_old, sizeof(buffer_old))) > 0) {
        count_new = read(new, buffer_new, sizeof(buffer_new));
        if (count_new != count_old || memcmp(buffer_old, buffer_new, count_old) != 0) {  
            return 1;
        }
    }
    return 0;
}
