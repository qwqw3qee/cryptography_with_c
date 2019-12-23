#include <stdio.h>
#include <stdlib.h>
#include "BIGNUM_BIN_32.h"
int main()
{
    srand(time(NULL));
    BIGNUM a,b,d;
    char ss[2048];
    //样例:素数测定
    scanf("%s",ss);
    BN_dec2bn(&a,ss);
    if(BN_is_prime(&a,5,1)==1)
        printf("%s有极大可能是素数\n",ss);
    else
        printf("%s不是素数\n",ss);
    return 0;
}
