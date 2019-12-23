#include <stdio.h>
#include <stdlib.h>
#include "BIGNUM_BIN_64.h"

int main()
{
    srand(time(NULL));
    BIGNUM a;
    char ss[2048];

    //样例:生成素数
    while(1)
    {
        int st=BN_generate_prime(&a,128,1,0);
        BN_bn2dec(ss,&a);
        if(st==1)
        {
            printf("%s有极大可能是素数\n",ss);
            //break;
        }
        else if(st==0)
            printf("%s不是素数\n",ss);
        else
            printf("出错\n");
    }
    return 0;
}
