#ifndef ELGAMAL_H_INCLUDED
#define ELGAMAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BIGNUM_BIN_32.h"
#include "BASE64.h"
#include "MD5.h"
#define KEYSIZE 512
typedef struct  elgamalkey
{
    int type;
    BIGNUM y,g,p;
    BIGNUM x;
}ELGKEY,*pELGKEY;
typedef struct elgamalsign
{
    int valid;
    BIGNUM m,r,s;
}ELGSIGN,*pELGSIGN;

int MD5_gets(unsigned char* md5val,unsigned char* str,int len);
int MD52char(char* md5,unsigned char* md5val);
int ELG_genKey(pELGKEY priKey,pELGKEY pubKey);
void ELG_key_printf(const ELGKEY* a,int base);
void ELG_sign_printf(const ELGSIGN* sign,int base);
int ELG_sign(pELGSIGN elgSign,const BIGNUM* m,const ELGKEY* priKey);
int ELG_verify(const ELGSIGN* elgSign,const ELGKEY* pubKey);
int ELG_bn2base64(char* s,const BIGNUM* bn,int blen);
int ELG_base642bn(pBIGNUM bn,const char* s,int len);
int ELG_key2base64(char* s,const ELGKEY* key);
int ELG_base642key(ELGKEY* key,const char* s);
int ELG_sign2base64(char* s,const ELGSIGN* sign);
int ELG_base642sign(pELGSIGN sign,const char* s,int len);

int ELG_char2bn(pBIGNUM bn,const char* str,int len);
int ELG_bn2char(char* str,const BIGNUM* bn,int len);
int ELG_sign_md5(pELGSIGN elgSign,const char* md5,const ELGKEY* priKey);
int ELG_sign_text(pELGSIGN elgSign,const char* str,int len,const ELGKEY* priKey);
int ELG_cmp_signature_text(const char* str,int len,const ELGSIGN* elgSign);
int ELG_cmp_signature_md5(const char* md5,const ELGSIGN* elgSign);
int ELG_key2file(const char* filename,const ELGKEY* key);
int ELG_file2key(pELGKEY key,const char* filename);
int ELG_getfile_md5(char* md5,const char* filename);

#endif // ELGAMAL_H_INCLUDED
