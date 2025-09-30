/*
 * File:   lcdFuncts.c
 * Author: eikhy
 *
 * Created on 29. september 2025, 13:23
 */

#include <xc.h>

char* int_to_string(unsigned int value) {
  static char buffer[6];
  unsigned int i = 0;
  while (value > 0) {
    buffer[i++] = (value % 10 + '0');
    value /= 10;
  };
  char* buffer_pointer = buffer;
  return buffer_pointer;
};
