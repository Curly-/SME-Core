#include "SME_timer.h"

#include <time.h>

long getMS() {
    long ret = 0;
#ifdef _WIN32
    ret = clock();
#endif
#ifdef __linux__
    timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    ret = ts.tv_nsec / 1000000 + ts.tv_sec * 1000;
#endif
    return ret;
}

void SME::Timer::start() {
    running = true;
}

void SME::Timer::stop() {
    if (running) ms = getMS();
    running = false;
}

void SME::Timer::reset() {
    ms = startms = getMS();
}

unsigned long SME::Timer::getTime() {
    if (running) ms = getMS();
    return ms - startms;
}