#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file = fopen("input.txt", "r");

  char line[1024];
  int current = 50;
  int password = 0;

  while (fgets(line, sizeof(line), file)) {
    char direction = line[0];
    int step = atoi(line + 1);
    int gap;

    if (direction == 'L') {
      gap = current;

      int tmp = current - step;
      if (tmp < 0) {
        current = 100 + (tmp % 100);

        if (current == 100) {
          current = 0;
        }
      } else {
        current = tmp;
      }
    } else {
      if (current == 0) {
        gap = 0;
      } else {
        gap = 100 - current;
      }

      current = (current + step) % 100;
    }

    if (current == 0) {
      password++;
    }

    if (step > gap) {
      int tmp = step;
      int hundred = tmp / 100;

      if (gap == 0) {
        if (tmp % 100 > 0) {
          password += hundred;
          continue;
        }
      }

      password += hundred;

      if (tmp % 100 > gap) {
        password++;
      }
    }
  }

  printf("password: %d\n", password);

  fclose(file);
}
