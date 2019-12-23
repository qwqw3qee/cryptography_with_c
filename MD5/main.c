#include <stdio.h>
#include "MD5.h"

int main()
{
    MD5_CTX md5;  //定义一个MD5 text
    MD5Init(&md5);//初始化
    int i;
    unsigned char encrypt[1024];//要加密内容
    unsigned char decrypt[16]; //加密结果
    scanf("%s",encrypt);

    MD5Update(&md5,encrypt,strlen((char *)encrypt));//进行初步分组加密
    MD5Final(&md5,decrypt);   //进行后序的补足，并加密

    printf("原字符串:%s\nmd5(16位):",encrypt);
    for(i=4;i<12;i++)
    {
        printf("%02x",decrypt[i]);
    }

    printf("\nmd5(32位):");
    for(i=0;i<16;i++)
    {
        printf("%02x",decrypt[i]);
    }
    return 0;

}
