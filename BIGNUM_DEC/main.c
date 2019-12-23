#include <stdio.h>
#include <stdlib.h>
#include "BIGNUM_DEC.h"

int main()
{
    srand(time(NULL));
    BIGNUM a,b,c,d;
    char ss[2048];
    //ÑùÀý:ÃÝÄ£ÔËËã
    scanf("%s",ss);
    BN_dec2bn(&a,ss);

    scanf("%s",ss);
    BN_dec2bn(&b,ss);

    scanf("%s",ss);
    BN_dec2bn(&c,ss);

    BN_mod_exp(&d,&a,&b,&c);
    BN_printf(&d,10);

    return 0;
}
