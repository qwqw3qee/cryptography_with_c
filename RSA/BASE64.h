#ifndef BASE64_H_INCLUDED
#define BASE64_H_INCLUDED
/*
    base64在线加解密
    http://tools.jb51.net/tools/base64_decode-gb2312.php
*/
int base64_encode(char* base64,const unsigned char * sourcedata,int datalen);
int base64_decode(unsigned char * dedata,const char * base64,int datalen);

#endif // BASE64_H_INCLUDED
