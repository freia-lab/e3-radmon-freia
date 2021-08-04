#include <registryFunction.h>
#include <epicsExport.h>
    
static float my_sub_test(aSubRecord *prec) {
        float *a;
        a = (float *)prec->a;
        prec->outa=a+3;
        return 0; /* process output links */
}
epicsRegisterFunction(my_sub_test);
	

