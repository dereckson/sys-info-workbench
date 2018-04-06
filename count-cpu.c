#include <errno.h>
#include <pmc.h>
#include <stdio.h>
#include <string.h>

char error[120];

void handle_pmc_init_error () {
    if (errno == ENOENT) {
        strcpy(error, "The hwpmc(4) module was not found in the kernel.");
        return;
    }

    if (errno == EPROGMISMATCH) {
        strcpy(error, "The library's version number did not match that expected by hwpmc(4).");
        return;
    }

    if (errno == ENXIO) {
        strcpy(error, "PMC hardware on this system is unsupported.");
    }
}

int count_cpu (int *ncpu) {
    int result;

    result = pmc_init();
    if (result == -1) {
        handle_pmc_init_error();
        return 0;
    }

    *ncpu = pmc_ncpu();
    return 1;
}

void print_error () {
    fprintf(stderr, "%s\n", error);
}

int main (int argc, char *argv[]) {
    int ncpu;

    if (!count_cpu(&ncpu)) {
        print_error();
        return 1;
    }

    printf("%d\n", ncpu);
    return 0;
}
