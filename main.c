#include <stdio.h>
#include <string.h>

#define BUFSIZE 4096

static void read_stdin();
static void read_file(char file_name[]);

int main(int argc, char *argv[]) {

    if (argc > 1) {
        for (int i = 1;i < argc;i++) {
            // if a file argument is "-", read from stdin
            if (strcmp(argv[i], "-") == 0) {
                read_stdin();
            } else {
                read_file(argv[i]);
            }
        }
    } else {
        read_stdin();
    }
}

static void read_stdin() {
    char buf[BUFSIZE];

    while (fgets(buf, BUFSIZE, stdin)) {
        printf("%s", buf);
    }
}


static void read_file(char file_name[]) {
    char buf[BUFSIZE];

    FILE *fp;
    fopen_s(&fp, file_name ,"rb");

    if (fp == NULL) {
        printf("%s%s","Error opening file ", file_name);
        return;
    }

    while (fgets(buf, BUFSIZE, fp)) {
        printf("%s", buf);
    }
}