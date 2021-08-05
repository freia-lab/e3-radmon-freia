#include <registryFunction.h>
#include <epicsExport.h>
#include <aSubRecord.h> 
#include <stdlib.h>
  
static double my_sub_test(aSubRecord *prec) {
        double *a;
        double *b= calloc(1,sizeof(double));
        a = (double *)prec->a;
        *b=*a+2;
        prec->vala=b;
        return 0; /* process output links */
}

epicsRegisterFunction(my_sub_test);
	


