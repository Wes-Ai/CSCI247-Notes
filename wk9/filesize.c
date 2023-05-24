#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    // FILE* fp = fopen(argv[1], "r");

    // fseek(fp, 0, SEEK_END);

    // long endbytes = ftell(fp);

    // printf("Size: %ld\n", endbytes);
    // fclose(fp);



    // struct stat statbuf;
    // stat(argv[1], &statbuf);
    // printf("Size=%ld\n", statbuf.st_size);



    int fd = open(argv[1], O_RDONLY);
    long end = lseek(fd, 0, SEEK_END);
    printf("Size=%ld\n", end);
    close(fd);
}
