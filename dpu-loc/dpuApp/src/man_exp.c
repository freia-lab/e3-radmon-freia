#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 
#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>

static long man_exp_fun(aSubRecord *prec) {

double y;

y = *(double *)prec->a;
//y=y[0];

double exp,sig;


//Max is 9 900 *10^3, i.e 9.9e6
//1 -> 1e-1, 2 -> 1e-2, 3, 1e-3, 4 -> 1e0
//5 -> 1e3, 6 -> 1e2, 7 -> 1e1

if (y>60000) {

   sig=round(y/1000);
   exp = 5;

} else if (y>=1000) {

   sig=round(y);
   exp = 4;

} else if (y>=100) {

   sig=round(y*10);
   exp = 1;

} else if (y>=10) {

   sig=round(y*100);
   exp = 2;

} else  {

   sig=round(y*1000);
   exp = 3;

}

*(double *) prec->vala=sig;
*(double *) prec->valb=exp;


return 0;


}


epicsRegisterFunction(man_exp_fun);
