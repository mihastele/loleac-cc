#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage()
{
    printf("Usage: ./db -f <filepath> [-n] <<to create a new DB>> \n");
}

int main(int argc, char *argv[])
{

    char *filepath = NULL;
    bool newfile = false;
    int c;

    int dbfd = -1; // database file descriptor

    while ((c = getopt(argc, argv, "nf:")) != -1)
    {
        switch (c)
        {
        case 'n':
            newfile = true;
            break;

        case 'f':
            filepath = optarg;
            break;
        case '?':
            printf("Unknown option: %c\n", c);
            break;
        default:
            return -1;
        }
    }

    if (filepath == NULL)
    {
        printf("No filepath specified\n");
        print_usage();
        return -1;
    }

    if (newfile)
    {
        dbfd = create_db_file(filepath);
        if (dbfd == STATUS_ERROR)
        {
            printf("Unable to create DB file\n");
            return -1;
        }
    }
    else
    {
        dbfd = open_db_file(filepath);
        if (dbfd == STATUS_ERROR)
        {
            printf("Unable to open DB file\n");
            return -1;
        }
    }

    printf("New file: %d\n", newfile);
    printf("filepath: %s\n", filepath);

    return 0;
}