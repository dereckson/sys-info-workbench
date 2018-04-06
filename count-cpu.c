#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdio.h>

int read_integer_sysctl_value (const char *name) {
    size_t len = 4;
    int value;

    int result = sysctlbyname(name, &value, &len, NULL, 0);

    return value;
}

int count_cpu () {
    return read_integer_sysctl_value("hw.ncpu");
}

int main (int argc, char *argv[]) {
    printf("%d\n", count_cpu());
    return 0;
}
