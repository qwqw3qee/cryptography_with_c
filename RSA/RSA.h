#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED

/*
    RSA原理
    https://blog.csdn.net/kikajack/article/details/80703894
    RSA密钥格式
    https://www.cnblogs.com/jukan/p/5527922.html
    base64在线加解密
    http://tools.jb51.net/tools/base64_decode-gb2312.php

*/
#include <stdio.h>
#include <stdlib.h>
#include "BASE64.h"
#include "BIGNUM_BIN_32.h"
#define KEYSIZE 512
#define EN_BLK_SIZE 117
#define DE_BLK_SIZE 128
/*
    KEYSIZE p和q的大小，密钥大小为两倍的KEYSIZE(单位为比特)
    EN_BLK_SIZE 加密分块的大小，一般为密钥大小-11(单位为字节)
    DE_BLK_SIZE 脱密分块的大小，一般为密钥大小(单位为字节)
    参考密钥大小对应的设置值
    1024位密钥:
    #define KEYSIZE 512
    #define EN_BLK_SIZE 117
    #define DE_BLK_SIZE 128
    2048位密钥:
    #define KEYSIZE 1024
    #define EN_BLK_SIZE 245
    #define DE_BLK_SIZE 256
*/
typedef struct rsakey
{
    int type;
    BIGNUM n,e,p,q,d;
} RSAKEY,*pRSAKEY;


int RSA_genKey(pRSAKEY priKey,pRSAKEY pubKey);
void RSA_key_printf(const RSAKEY* a,int base);
int RSA_encrypt(pBIGNUM c,const BIGNUM* m,const RSAKEY* pubKey);
int RSA_decrypt(pBIGNUM m,const BIGNUM* c,const RSAKEY* priKey);
int RSA_key_output(char* s,const RSAKEY* key);
int RSA_key_import(RSAKEY* key,const char* s);
int RSA_char2bn(pBIGNUM bn,const char* str,int len);
int RSA_bn2char(char* str,const BIGNUM* bn,int len);
int RSA_text_encrypt(char* mi,const char* yuan,int yuanLen,const RSAKEY* pubKey);
int RSA_text_decrypt(char* yuan,const char* mi,int miLen,const RSAKEY* priKey);
int RSA_text_encrypt_base64(char* mi,const char* yuan,int yuanLen,const RSAKEY* pubKey);
int RSA_text_decrypt_base64(char* yuan,const char* mi,int miLen,const RSAKEY* priKey);
int RSA_key2file(const char* filename,const RSAKEY* key);
int RSA_file2key(pRSAKEY key,const char* filename);


#endif // RSA_H_INCLUDED
