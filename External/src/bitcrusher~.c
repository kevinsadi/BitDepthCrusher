/*
 * Patch created by Kevin Sadi. 11/29/2022
 *
 * This patch leverages bit depth to modify audio streams.
 */

#include "m_pd.h"

static t_class *bitcrush_tilde_class;

/**
 * this is our hack to allow object like behavior in C.
 *
 * Specifying signal input and output. Also specify bit depth inlet.
 */
typedef struct _bitcrush_tilde {
  t_object x_obj;

  t_int bd; // there is a chance specifying an int inlet will cause mayhem

  t_float f;
  t_inlet *x_in2;
  t_outlet *x_out;

} t_bitcrush_tilde;


/**
 * Here is the core of the external. This routine is called for every signal block.
 * The name of this function is arbitrary, this is called in the bitcrush_tilde_dsp() function.
 *
 * We do some C witchcraft in this function. We have to know how many elements in an array
 * are reserved for every operation, and then return a pointer to the same array, except incremented
 * by the amount of elements we used in this routine.
 */
t_int *bitcrush_tilde_perform(t_int *w)
{

}


/**
 * this is the "constructor" of the class
 * this method is called whenever a new object of this class is created
 * the name of this function is arbitrary and is registered to Pd in the
 * helloworld_setup() routine
 */
void *bitcrush_tilde_new(void)
{

  /*
   * return the pointer to the class - this is mandatory
   * if you return "0", then the object-creation will fail
   */
  return (void *)x;
}


/**
 * define the function-space of the class
 * within a single-object external the name of this function is special
 */
void bitcrush_tilde_setup(void) {
  /* create a new class */
  bitcrush_tilde_class = class_new(gensym("bitcrush~"),            /* the object's name is "bitcrush~" */
                               (t_newmethod)bitcrush_tilde_new,    /* the object's constructor is "helloworld_new()" */
                               (t_method)bitcrush_tilde_free,      /* special destructor */
                               sizeof(t_bitcrush_tilde),           /* the size of the data-space */
                               CLASS_DEFAULT,                      /* a normal pd object */
                               A_DEFFLOAT, 0);                     /* define input as a float */

  class_addmethod(bitcrush_tilde_class,
                  (t_method)bitcrush_tilde_dsp,
                  gensym("dsp"),
                  A_CANT, 0);
}