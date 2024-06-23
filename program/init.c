#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rw.h"
#include "prototypes.h"

/****
 set the initial configuration of the system
****/
void set_init_conf()
{
  int i, cnt=0;

  while(cnt==0){ /*=== to avoid a vacant system ===*/
    cnt = 0;
    for (i = 2; i < ctl.mat_size+2; i++){
      sys.mat0[i] = (int)(ctl.max_velocity*ran1()+1)*
	((int)(ran1()+ctl.concentration));
      if(sys.mat0[i]>0) cnt++;
    }
  }

  //  sys.mat0[2]=2;
  //  sys.mat0[3]=1;
  //  sys.mat0[4]=0;
  //  sys.mat0[5]=2;
  //  sys.mat0[6]=0;
  //  sys.mat0[7]=0;
  //  sys.mat0[8]=2;
  //  sys.mat0[9]=0;
  //  sys.mat0[10]=0;
  //  sys.mat0[11]=3;      
  
  sys.number_of_walkers = cnt;
/*
  printf("num = %d\n",cnt);
  printf("prob. = %f\n",(double)cnt/(double)ctl.mat_size);
  getchar();
*/
  set_bc(sys.mat0);
}

void open_files(void)
{
  if((fpout = fopen("../files/out","w"))==NULL){
    printf("cannot open out. Abort\n");
    exit(EXIT_FAILURE);
  }
}

void init_mem(void){
  int *mat_mem0, *mat_mem1, *mat_mem2;

  mat_mem0 = (int *)calloc(ctl.mat_size+4, sizeof(int)); 
  mat_mem1 = (int *)calloc(ctl.mat_size+4, sizeof(int)); 
  mat_mem2 = (int *)calloc(ctl.mat_size+4, sizeof(int)); 
  sys.mat0 = mat_mem0;
  sys.mat1 = mat_mem1;
  sys.mat2 = mat_mem2;
}

void show_matrix(int *field){
  int i;
/*
  for(i=0; i<ctl.mat_size+4; i++){
    printf(" %d",field[i]);
  }
  printf("\n");
*/
  for(i=2; i<ctl.mat_size+2; i++){
    printf(" %d",field[i]);
  }
  printf("\n");

}

void print_matrix(int *field){
  int i;
  for(i=2; i<ctl.mat_size+2; i++){
    fprintf(fpout," %d",field[i]);
  }
  fprintf(fpout,"\n");

}
