#ifndef LOG_H
#define LOG_H

enum log_level {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
};

void _log_leading(const enum log_level level, const char* func, const int line);
void _log_printf(const enum log_level level, const char* func, const int line, const char* fmt, ...);

#define EXPAND(X) X
#define log_printf(TYPE, ...) \
	_log_printf(TYPE, __func__, __LINE__, __VA_ARGS__)

#define log_debug(...) EXPAND(log_printf(LOG_DEBUG, __VA_ARGS__))
#define log_info(...) EXPAND(log_printf(LOG_INFO, __VA_ARGS__))
#define log_warn(...) EXPAND(log_printf(LOG_WARN __VA_ARGS__))
#define log_error(...) EXPAND(log_printf(LOG_ERROR, __VA_ARGS__))

#endif // LOG_H

#ifdef LOG_C
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#endif // LOG_C