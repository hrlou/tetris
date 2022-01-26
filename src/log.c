#define LOG_C
#include "include/log.h"

void _log_leading(const log_type type, const char* func, const int line) {
	time_t timer;
	struct tm* tm_info;
	char buf[26];

	timer = time(NULL);
	tm_info = localtime(&timer);
	strftime(buf, 26, "%Y-%m-%dT%H:%M:%S", tm_info);
	fprintf(stderr, "[%s TEST %s:%d] ", buf, func, line);
}

void _log_print(const log_type type, const char* func, const int line, const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	_log_leading(type, func, line);
	vfprintf(stderr, fmt, args);
	va_end(args);
	fputc('\n', stderr);
}