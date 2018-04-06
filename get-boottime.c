#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdio.h>

struct timeval read_timeval_sysctl_value (const char *name) {
    struct timeval value;
    size_t len = sizeof(value);

    int result = sysctlbyname(name, &value, &len, NULL, 0);

    return value;
}

struct timeval get_boottime () {
    return read_timeval_sysctl_value("kern.boottime");
}

int main (int argc, char *argv[]) {
    struct timeval boottime = get_boottime();
    printf("%ld.%06ld\n", boottime.tv_sec, boottime.tv_usec);
    return 0;
}
