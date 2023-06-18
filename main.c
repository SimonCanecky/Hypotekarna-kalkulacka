#include <stdio.h>
#include "math.h"

double kalendar(double Sk,double M,double im,double Nr)
{
    double Rk,Mk,Dk;
    double Dk_1 = M;
    double R = 0;

    for (int i=1; i<=Nr; i++)
    {
        for (int j=1; j<=12; j++)
        {
            Rk = im*Dk_1;
            Mk = Sk-Rk;
            Dk = Dk_1-Mk;
            if(i == Nr && j == 12)
                printf("%-*d %-*d %-*.2lf %-*.2lf %-*.2lf\n",2,i,2,j,10,Rk,10,Mk,10,0.00);
            else
                printf("%-*d %-*d %-*.2lf %-*.2lf %-*.2lf\n",2,i,2,j,10,Rk,10,Mk,10,Dk);
            Dk_1 = Dk;
            R += Rk;
        }
    }
    return R;
}

int main()
{
    double M,Nr,ir,im,Nm,S,R;

    scanf("%lf %lf %lf",&M,&Nr,&ir);
    printf("%.0lf\n%.0lf\n%.2lf\n",M,Nr,ir);

    im = ir/100/12;
    Nm = Nr*12;
    S = M*(im/(1-pow((1/(1+im)),Nm)));
    printf("%.2lf\n",S);
    R = kalendar(S,M,im,Nr);
    printf("%.2lf",R);

    return 0;
}
