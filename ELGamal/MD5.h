#ifndef MD5_H_INCLUDED
#define MD5_H_INCLUDED
/**
https://blog.csdn.net/chudongfang2015/article/details/51736426
**/
#include <stdio.h>
#include <math.h>
#include <string.h>

#define ROTATE_LEFT(x,n) (((x) << (n)) | ((x) >> (32-(n))))
#define F(x,y,z) (((x)&(y))|(((~(x))&(z))))
#define G(x,y,z) (((x)&(z))|((y)&(~(z))))
#define H(x,y,z) ((x)^(y)^(z))
#define I(x,y,z) ((y)^((x)|(~(z))))

#define FF(a,b,c,d,m,y,rol) {(a)+=F((b),(c),(d))+(m)+(y);(a)=ROTATE_LEFT((a),(rol));(a)+=(b);}
#define GG(a,b,c,d,m,y,rol) {(a)+=G((b),(c),(d))+(m)+(y);(a)=ROTATE_LEFT((a),(rol));(a)+=(b);}
#define HH(a,b,c,d,m,y,rol) {(a)+=H((b),(c),(d))+(m)+(y);(a)=ROTATE_LEFT((a),(rol));(a)+=(b);}
#define II(a,b,c,d,m,y,rol) {(a)+=I((b),(c),(d))+(m)+(y);(a)=ROTATE_LEFT((a),(rol));(a)+=(b);}

typedef long long ll;
typedef struct
{
    unsigned int count[2];
    unsigned int state[4];
    unsigned char buffer[64];
}MD5_CTX;

void MD5Init(MD5_CTX *context);
//void initConY(unsigned int* conY);
void MD5Update(MD5_CTX* context,unsigned char* input,unsigned int inputlen);
void MD5Final(MD5_CTX* context,unsigned char digest[16]);
void MD5Transform(unsigned int state[4],unsigned char block[64]);


#endif // MD5_H_INCLUDED
