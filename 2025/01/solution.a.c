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

    if (direction == 'L') {
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
      current = (current + step) % 100;
    }

    if (current == 0) {
      password++;
    }
  }

  printf("password: %d\n", password);

  fclose(file);
}
