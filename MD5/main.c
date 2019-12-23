#include <stdio.h>
#include "MD5.h"

int main()
{
    MD5_CTX md5;  //����һ��MD5 text
    MD5Init(&md5);//��ʼ��
    int i;
    unsigned char encrypt[1024];//Ҫ��������
    unsigned char decrypt[16]; //���ܽ��
    scanf("%s",encrypt);

    MD5Update(&md5,encrypt,strlen((char *)encrypt));//���г����������
    MD5Final(&md5,decrypt);   //���к���Ĳ��㣬������

    printf("ԭ�ַ���:%s\nmd5(16λ):",encrypt);
    for(i=4;i<12;i++)
    {
        printf("%02x",decrypt[i]);
    }

    printf("\nmd5(32λ):");
    for(i=0;i<16;i++)
    {
        printf("%02x",decrypt[i]);
    }
    return 0;

}
