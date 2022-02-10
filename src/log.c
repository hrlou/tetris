#define LOG_C
#include "include/log.h"

void _log_leading(const enum log_level level, const char* func, const int line) {
	time_t timer;
	struct tm* tm_info;
	static char tm_buf[26];
	static char level_str[2][6] = { "DEBUG\0", "INFO\0", "WARN\0", "ERROR\0" };

	timer = time(NULL);
	tm_info = localtime(&timer);
	strftime(tm_buf, 26, "%Y-%m-%dT%H:%M:%S", tm_info);
	fprintf(stderr, "[%s %s %s:%d] ", tm_buf, level_str[level], func, line);
}

void _log_printf(const enum log_level level, const char* func, const int line, const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	_log_leading(level, func, line);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fputc('\n', stderr);
}