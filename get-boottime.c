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

#define NSEC_PER_USEC   1000        /* nanoseconds per microsecond */
#define USEC_PER_SEC    1000000     /* microseconds per second */
#define NSEC_PER_SEC    1000000000  /* nanoseconds per second */
#define timeval2nsec(tv) (tv.tv_sec * NSEC_PER_SEC + tv.tv_usec * NSEC_PER_USEC)

int main (int argc, char *argv[]) {
    struct timeval boottime = get_boottime();
    printf("%ld\n", timeval2nsec(boottime));
    printf("%ld.%06ld\n", boottime.tv_sec, boottime.tv_usec);
    return 0;
}
