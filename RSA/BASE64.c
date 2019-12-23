#include "BASE64.h"
#include <string.h>
const char * base64char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const char padding_char = '=';
const char DecodeTable[] =
{
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
    -2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
    -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
};
int base64_encode(char* base64,const unsigned char * sourcedata,int datalen)
{
    int i=0, j=0,rem;
    for (; i+3 <= datalen; i += 3)
    {
        base64[j++]=base64char[((sourcedata[i]>>2)&0x3f)];
        base64[j++]=base64char[(((sourcedata[i]<<4)&0x30)|((sourcedata[i+1]>>4)&0x0f))];
        base64[j++]=base64char[(((sourcedata[i+1]<<2)&0x3c)|((sourcedata[i+2]>>6)&0x03))];
        base64[j++]=base64char[((sourcedata[i+2])&0x3f)];
    }
    rem=datalen-i;
    unsigned char buf[3]= {0,0,0};
    memcpy(buf,sourcedata+i,rem);
    switch(rem)
    {
    case 2:
        base64[j++]=base64char[((buf[0]>>2)&0x3f)];
        base64[j++]=base64char[(((buf[0]<<4)&0x30)|((buf[1]>>4)&0x0f))];
        base64[j++]=base64char[((buf[1]<<2)&0x3c)];
        base64[j++]=padding_char;
        break;
    case 1:
        base64[j++]=base64char[((buf[0]>>2)&0x3f)];
        base64[j++]=base64char[((buf[0]<<4)&0x30)];
        base64[j++]=padding_char;
        base64[j++]=padding_char;
        break;
    }
    base64[j] = '\0';
    return j;
}

int base64_decode(unsigned char * dedata,const char * base64,int datalen)
{

    int bin=0,i=0,j=0,k=0;
    char ch;
    // 当前一个字符是“=”号
    /*
        在解码时，4个字符为一组进行一轮字符匹配。
        两个条件：
            1、如果某一轮匹配的第二个是“=”且第三个字符不是“=”，说明这个带解析字符串不合法，直接返回空
            2、如果当前“=”不是第二个字符，且后面的字符只包含空白符，则说明这个这个条件合法，可以继续。
    */
    for(i=0; i<datalen; ++i)
    {
        if (base64[i] == padding_char)
        {
            if (base64[i+1]!=padding_char&&(j%4)==1)
                return -1;
            continue;
        }
        ch = DecodeTable[(int)base64[i]];
        if (ch < 0 ) //用来过滤所有不合法的字符
            continue;/* a space or some other separator character, we simply skip over */
        switch(j % 4)
        {
        case 0:
            bin = (ch << 2);
            break;
        case 1:
            bin |= (ch >> 4);
            dedata[k++] = bin;
            bin = ((ch&0x0f)<<4);
            break;
        case 2:
            bin |= (ch>>2);
            dedata[k++] = bin;
            bin = ((ch&0x03)<< 6);
            break;
        case 3:
            bin |= ch;
            dedata[k++] = bin;
            break;
        }
        j++;
    }
    dedata[k]='\0';
    return k;
}
