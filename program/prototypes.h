/* prototypes.h */

/* control.c */
void get_control_param(void);

/* main.c */
int main(void);

/* dynamics.c */
void rand_decelerate();
void accelerate();
void decelerate();
void move_tf_1d();
void set_bc(int *ants);
void mk_copy(int *original, int *copy);

/* init.c */
void set_init_conf();
void init_mem(void);  
void open_files(void);
void show_matrix(int *field);
void print_matrix(int *field);
void print_averaged_velocity(void);

void   egg_disp(void);
void   egg_traffic(void);

/* ran.c */
double ran1(void);
