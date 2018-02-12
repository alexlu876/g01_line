#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"



//algo to determine oct
int octant(int x0, int y0, int x1, int y1){
  

  int d_x = x1 - x0;
  int d_y = y1 - y0;

  //oct 1
  if(d_x >= d_y && d_y >= 0){
    return 1;
  }

  //oct 2
  if(d_x <= d_y && d_y >= 0){
    return 2;
  }

  //oct 8
  if(d_x >= d_y * -1 && d_y < 0){
    return 8;
  }

  //oct 7
  if(d_x <= d_y * -1 && d_y < 0){
    return 7;
  }

  return 0;
}



//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  //make sure we are drawing left to right
  if(x1 < x0){
    draw_line(x1, y1, x0, y0, s, c);
  }

  else{

    int A = y1 - y0;
    int B = x1 - x0;
    
    //make my life easier avoid pass by value stuff
    int x = x0;
    int y = y0;
    
    int oct = octant(x0, y0, x1, y1); 
    
    int d;

    if(oct == 1){
      
      d = A + A - B;
      while(x < x1){
        plot(s, c, x, y);
        if(d > 0){
          y++;
          d -= B + B;
        }
        x++;
        d += A + A;
      }
    }

    else if(oct == 2){

      d = A - B - B;
      while(y < y1){
        plot(s, c, x, y);
        if(d < 0){
          x++;
          d += A + A;
        }
        y++;
        d -= B + B;
      }
    }

    else if(oct == 7){
      
      d = A + B + B;
      while(y > y1){
        plot(s, c, x, y);
        if(d > 0){
          x++;
          d += A + A;
        }
        y--;
        d += B + B;
      }
    }
    
    else if(oct == 8){
      
      d = A + A + B;
      while(x < x1){
        plot(s, c, x, y);
        if(d < 0){
          y--;
          d += B + B;
        }
        x++;
        d += A + A;
      }
    }
  }
}
  






















































