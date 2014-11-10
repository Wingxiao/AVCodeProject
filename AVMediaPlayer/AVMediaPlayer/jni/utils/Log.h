/*
 * android print log by level
 * 
 */

#ifndef UTILS_ANDROID_LOG_H
#define UTILS_ANDROID_LOG_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void android_utils_log_print(const char *tag, int level, const char *fmt, ...);

void android_utils_log_fatal(const char *tag, const char *fmt, ...);


#ifndef DEBUG_TAG 
#ifdef  TAG
#define DEBUG_TAG TAG
#else 
#define DEBUG_TAG  "AVMediaPlayer"
#endif 
#endif 

#define AVLOGD(logs...) android_utils_log_print(DEBUG_TAG, ANDROID_LOG_DEBUG, logs)
#define AVLOGI(logs...) android_utils_log_print(DEBUG_TAG, ANDROID_LOG_INFO, logs)
#define AVLOGW(logs...) android_utils_log_print(DEBUG_TAG, ANDROID_LOG_WARN, logs)
#define AVLOGE(logs...) android_utils_log_print(DEBUG_TAG, ANDROID_LOG_ERROR,logs)

#define AVASSERT(cond, logs, args...) \
    if (__builtin_expect(!(cond), false)) android_utils_log_fatal(DEBUG_TAG, logs" -> "#cond, ##args)

#ifdef __cplusplus 
};
#endif 

#endif
