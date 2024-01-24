//
// Created by danil on 12/30/23.
//

#ifndef SANDBOX_COMMON_H
#define SANDBOX_COMMON_H
#include <inttypes.h>
#include <stdio.h>
size_t read_size() {
  size_t size = 0;
  int res = scanf("%zu", &size);
  if (res <= 0)
    return 0;
  return size;
}
#endif // SANDBOX_COMMON_H
