#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

/* RWCA-1d uder cyclic boundary condition */

int main(void){

  open_files();
  get_control_param();
  init_mem();

  set_init_conf();

  mk_copy(sys.mat0, sys.mat1);

  /*----------- RWCA moving step -----------*/
  for(sys.time_step=0;
      sys.time_step<ctl.max_time_step;sys.time_step++) {
/*-------------- X interface -------------------*/
      egg_disp();
      //      egg_traffic();
      usleep(30000);  // enforce delay

      accelerate();  // step 1
      decelerate();  // step 2
      rand_decelerate(); //step 3
      move_tf_1d();
      mk_copy(sys.mat1, sys.mat0);  /* sys.mat1  =>  sys.mat0 */
  }
  /*-------- end of RWCA moving step -------*/
  return 0;  
}
