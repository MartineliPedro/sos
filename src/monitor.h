#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"


void monitor_putc(char c);
void monitor_clearscr();
void monitor_writestring(const char* string);

#endif