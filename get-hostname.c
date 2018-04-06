#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTNAME_LEN 255

char error[255];

void handle_gethostname_error () {
    if (errno == EFAULT) {
        strcpy(error, "The name or namelen argument gave an invalid address. Please report this bug.");
        return;
    }

    if (errno == ENAMETOOLONG) {
        sprintf(error, "The hostname is longer than %d characters.", MAX_HOSTNAME_LEN);
        return;
    }

    sprintf(error, "Can't get the hostname. Unknown error, errno=%d. Please report this bug.", errno);
}

int main (int argc, char *argv[]) {
    int result;
    char hostname[MAX_HOSTNAME_LEN];

    result = gethostname(hostname, MAX_HOSTNAME_LEN);
    if (result == -1) {
        fprintf(stderr, "%s: %s\n", argv[0], error);
        return 1;
    }

    printf("%s\n", hostname);
    return 0;
}
