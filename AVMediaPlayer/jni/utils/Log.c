/*
 *  android print log by level
 *
 */

#include "Log.h"

#include <android/log.h>

void android_utils_log_print(const char* tag, int level, const char *fmt, ...) {
    va_list ap; 
    char buf[1024];

    va_start(ap, fmt);
    vsnprintf(buf, 1024, fmt, ap); 
    va_end(ap); 

    __android_log_write(level, tag, buf);
}

void android_utils_log_fatal(const char* tag, const char *fmt, ...) {
    char buf[1024];

    if (fmt) {
        va_list ap; 
        va_start(ap, fmt);
        vsnprintf(buf, 1024, fmt, ap); 
        va_end(ap); 
    } else {
        snprintf(buf, 1024, "log fatal assert...");
    }

    __android_log_write(ANDROID_LOG_FATAL, tag, buf);

    __builtin_trap(); /* trap so we have a chance to debug the situation */
}
