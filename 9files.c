#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

// everything in linux is a file
int main(int argc, char *argv[])
{
    /*
    File Descriptors
    0 - stdin
    1 - stdout -> outputs
    2 - stderr -> errors to be filtered for specific logging
    */

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }

    char *mydata = "This is some data to write to the file\n";
    int len = write(fd, mydata, strlen(mydata));

    close(fd);
    return 0;
}