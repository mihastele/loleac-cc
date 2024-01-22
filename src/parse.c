#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "parse.h"

int parse_file_header(int fd, int *numEmployeesOut)
{
    if (fd == -1)
    {
        printf("Invalid file descriptor\n");
        return STATUS_ERROR;
    }

    struct dbheader_t header = {0};

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        printf("Error reading file header\n");
        return STATUS_ERROR;
    }

    *numEmployeesOut = header.count;
    return STATUS_SUCCESS;

    return 0;
}