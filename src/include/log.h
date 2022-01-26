#ifndef LOG_H
#define LOG_H

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
} log_type;

void _log_leading(const log_type type, const char* func, const int line);
void _log_print(const log_type type, const char* func, const int line, const char* fmt, ...);

#define EXPAND(X) X
#define log_print(TYPE, ...) _log_print(TYPE, __func__, __LINE__, __VA_ARGS__)
#define log_info(...) EXPAND(log_print(LOG_INFO, __VA_ARGS__))

#endif // LOG_H

#ifdef LOG_C
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#endif // LOG_C