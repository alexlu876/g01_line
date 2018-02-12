#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  //lines- tests for all quads
  /*
  //slope 0
  draw_line(0, 250, 500, 250, s, c);
  //slope undef
  draw_line(250, 0, 250, 500, s, c);
  //slope 1
  draw_line(0, 500, 500, 0, s, c);
  //slope -1
  draw_line(0, 0, 500, 500, s, c);

  //oct 1
  draw_line(250, 250, 350, 300, s, c);
  //oct 2
  draw_line(250, 250, 300, 400, s, c);
  //oct 3
  draw_line(250, 250, 200, 400, s, c);
  //oct 4
  draw_line(250, 250, 150, 300, s, c);
  //oct 5
  draw_line(250, 250, 150, 200, s, c);
  //oct 6
  draw_line(250, 250, 200, 100, s, c);
  //oct 7
  draw_line(250, 250, 300, 100, s, c);
  //oct 8
  draw_line(250, 250, 350, 200, s, c);
  */
  srand(time(NULL));
  int i;
  for(i = 0; i < 100; i++){
    c.red = rand() % 255;
    c.blue = rand() % 255;
    draw_line(rand() % 500, rand() % 500, rand() % 500, rand() % 500, s, c);
  }

  save_ppm(s, "lines.ppm");
  //display(s);
  //save_extension(s, "lines.png");
}


















































