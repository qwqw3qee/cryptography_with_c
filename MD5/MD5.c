#include "MD5.h"
const unsigned int rolArray[4][4] = {
    { 7, 12, 17, 22 },
    { 5,  9, 14, 20 },
    { 4, 11, 16, 23 },
    { 6, 10, 15, 21 }
};//循环左移-位数表
unsigned int conY[64] = {
    0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
    0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,
    0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
    0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,
    0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
    0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
    0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
    0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
};//32bit常数表

unsigned char PADDING[]={
 0x80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};//补全最后一块;
const int conX[4][4]={
    {0,1,2,3},
    {3,0,1,2},
    {2,3,0,1},
    {1,2,3,0}
};
const int mN[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
    1, 6,11, 0, 5,10,15, 4, 9,14, 3, 8,13, 2, 7,12,
    5, 8,11,14, 1, 4, 7,10,13, 0, 3, 6, 9,12,15, 2,
    0, 7,14, 5,12, 3,10, 1, 8,15, 6,13, 4,11, 2, 9
};


//初始化
void MD5Init(MD5_CTX *context)
{
    context->count[0] = 0;
    context->count[1] = 0;
    //分别赋固定值
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
}

/*
//常数表生成
void initConY(unsigned int* conY)
{
    ll b=1;
    b <<= 32;
    for(int i=0; i<64; ++i)
    {
        if(i%8==0) printf("\n");
        conY[i] = b*fabs(sin(i+1));
        printf("0x%08x,",conY[i]);

    }
}
*/
void MD5Update(MD5_CTX* context,unsigned char* input,unsigned int inputlen)
{
    unsigned int i,index,partlen;//index:原有结构中剩余的数据大小(字节)
                                 //partlen:可填充的数据大小(字节)
    index = (context->count[0]/8)%64;//512bit=64Byte
    partlen = 64-index;
    context->count[0] += (inputlen*8); //把新增的数据大小加进去(比特)
    if(context->count[0]<(inputlen*8)) //加法溢出了
        ++context->count[1];
    context->count[1] += (inputlen>>29); //把inputlen*8左边溢出的3位加到高位
    if(inputlen >= partlen)
    {
        memcpy(&context->buffer[index],input,partlen);
        MD5Transform(context->state,context->buffer);
        for(i=partlen; i+64<=inputlen; i+=64)
            MD5Transform(context->state,&input[i]);
        index=0;
    }
    else i=0;
    memcpy(&context->buffer[index],&input[i],(inputlen-i));
}
void MD5Final(MD5_CTX* context,unsigned char digest[16])
{

    unsigned int index,padlen;//index:原有结构中剩余的数据大小(字节)
                                 //padlen:可填充的数据大小(字节)
    unsigned char bits[8];

    index = (context->count[0]/8)%64;//512bit=64Byte
    padlen = (index<56)?(56-index):(120-index);
    memcpy(bits,context->count,8);
    MD5Update(context,PADDING,padlen);
    MD5Update(context,bits,8);
    memcpy(digest,context->state,16);
}
void MD5Transform(unsigned int state[4],unsigned char block[64])
{
    unsigned int ts[4] = {state[0],state[1],state[2],state[3]};
    unsigned int* m=(unsigned int*)block;
    int i = 0,i_y;
    for(i=0; i < 16; ++i)
    {
        i_y=i%4;
        FF(ts[conX[i_y][0]],ts[conX[i_y][1]],ts[conX[i_y][2]],ts[conX[i_y][3]],m[mN[i]],conY[i],rolArray[0][i_y]);
    }

    for(; i < 32; ++i)
    {
        i_y=i%4;
        GG(ts[conX[i_y][0]],ts[conX[i_y][1]],ts[conX[i_y][2]],ts[conX[i_y][3]],m[mN[i]],conY[i],rolArray[1][i_y]);
    }
    for(; i < 48; ++i)
    {
        i_y=i%4;
        HH(ts[conX[i_y][0]],ts[conX[i_y][1]],ts[conX[i_y][2]],ts[conX[i_y][3]],m[mN[i]],conY[i],rolArray[2][i_y]);
    }
    for(; i < 64; ++i)
    {
        i_y=i%4;
        II(ts[conX[i_y][0]],ts[conX[i_y][1]],ts[conX[i_y][2]],ts[conX[i_y][3]],m[mN[i]],conY[i],rolArray[3][i_y]);
    }
    for(i=0; i<4; ++i)
        state[i]+=ts[i];
}

