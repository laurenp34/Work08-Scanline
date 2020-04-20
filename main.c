#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"

int main(int argc, char **argv) {

  screen s;
  color c;
  zbuffer zb;
  struct matrix * edges;
  struct matrix * polygons;
  struct stack * csystems;

  clear_screen(s);

  edges = new_matrix(4, 4);
  polygons = new_matrix(4, 4);
  csystems = new_stack();

  /* print_matrix(make_rotX(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotY(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotZ(M_PI/4)); */
  /* printf("\n"); */

  if ( argc == 2 )
    parse_file( argv[1], csystems, edges, polygons, s, zb );
  else
    parse_file( "stdin", csystems, edges, polygons, s, zb );

  // add_point(polygons, 10,10,0);
  // add_point(polygons, 70,10,0);
  // add_point(polygons, 10,90,0);
  // draw_polygons(polygons,s,zb,c);
  // scanline_convert(polygons,0,s,zb,c);

  free_matrix( edges );
  free_matrix( polygons );
  free_stack(csystems);

  // display(s);
}
