#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdio.h>

int read_integer_sysctl_value (const char *name) {
    size_t len = 4;
    int value;

    int result = sysctlbyname(name, &value, &len, NULL, 0);

    return value;
}

int get_cpu_speed () {
    return read_integer_sysctl_value("dev.cpu.0.freq");
}

int main (int argc, char *argv[]) {
    printf("%d\n", get_cpu_speed());
    return 0;
}
