#include "RSA.h"
int RSA_genKey(pRSAKEY priKey,pRSAKEY pubKey)
{
    BIGNUM p_1,q_1,phi_n,e,d;
    BN_generate_prime(&p_1,KEYSIZE,1,0);
    priKey->p=p_1;
    printf("generate p successfully!\n");
    BN_generate_prime(&q_1,KEYSIZE-2,1,0);
    priKey->q=q_1;
    printf("generate q successfully!\n");
    BN_mul(&phi_n,&p_1,&q_1);
    priKey->n=phi_n;
    printf("generate n successfully!\n");
    BN_sub_word(&p_1,1);
    BN_sub_word(&q_1,1);
    BN_mul(&phi_n,&p_1,&q_1);
    BIGNUM gcd;
    do
    {
        BN_rand(&e,KEYSIZE*2,0,1);
        BN_mod(&e,&e,&phi_n);
        BN_gcd(&gcd,&e,&phi_n);
    }
    while(BN_is_one(&gcd)==0);
    priKey->e=e;
    printf("generate e successfully!\n");
    BN_mod_inverse(&d,&e,&phi_n);
    priKey->d=d;
    printf("generate d successfully!\n");
    priKey->type=1;
    pubKey->type=2;
    BN_zero(&pubKey->p);
    BN_zero(&pubKey->q);
    BN_zero(&pubKey->d);
    pubKey->e=priKey->e;
    pubKey->n=priKey->n;
    return 1;
}
void RSA_key_printf(const RSAKEY* a,int base)
{
    if(a->type==1)
    {
        printf("\n-----------\ntype:Private Key");
        printf("\n-----n-----\n");
        BN_printf(&a->n,base);
        printf("\n-----e-----\n");
        BN_printf(&a->e,base);
        printf("\n-----p-----\n");
        BN_printf(&a->p,base);
        printf("\n-----q-----\n");
        BN_printf(&a->q,base);
        printf("\n-----d-----\n");
        BN_printf(&a->d,base);
        printf("\n-----------\n");
    }
    else if(a->type==2)
    {
        printf("\n-----------\ntype:Public Key");
        printf("\n-----n-----\n");
        BN_printf(&a->n,base);
        printf("\n-----e-----\n");
        BN_printf(&a->e,base);
        printf("\n-----------\n");
    }
    else
        printf("Wrong key!\n");
}
int RSA_encrypt(pBIGNUM c,const BIGNUM* m,const RSAKEY* pubKey)
{
    if(pubKey->type!=1&&pubKey->type!=2) return 0;
    return BN_mod_exp(c,m,&pubKey->e,&pubKey->n);
}
int RSA_decrypt(pBIGNUM m,const BIGNUM* c,const RSAKEY* priKey)
{
    if(priKey->type!=1) return 0;
    return BN_mod_exp(m,c,&priKey->d,&priKey->n);
}
int RSA_key_output(char* s,const RSAKEY* key)
{
    char str[3000];
    int base64Len=0,outputLen;
    s[base64Len++]=key->type+'0';
    s[base64Len++]='\n';
    outputLen=base64_encode(str,(unsigned char*)key->n.num,KEYSIZE/4);
    memcpy(&s[base64Len],str,outputLen);
    base64Len+=outputLen;
    s[base64Len++]='\n';
    outputLen=base64_encode(str,(unsigned char*)key->e.num,KEYSIZE/4);
    memcpy(&s[base64Len],str,outputLen);
    base64Len+=outputLen;
    s[base64Len++]='\n';
    if(key->type==2) return base64Len;
    outputLen=base64_encode(str,(unsigned char*)key->p.num,KEYSIZE/4);
    memcpy(&s[base64Len],str,outputLen);
    base64Len+=outputLen;
    s[base64Len++]='\n';
    outputLen=base64_encode(str,(unsigned char*)key->q.num,KEYSIZE/4);
    memcpy(&s[base64Len],str,outputLen);
    base64Len+=outputLen;
    s[base64Len++]='\n';
    outputLen=base64_encode(str,(unsigned char*)key->d.num,KEYSIZE/4);
    memcpy(&s[base64Len],str,outputLen);
    base64Len+=outputLen;
    s[base64Len++]='\n';
    s[base64Len++]='\0';
    return base64Len;
}
int RSA_key_import(RSAKEY* key,const char* s)
{


    unsigned char buffer[4000];
    key->type=s[0]-'0';
    int stpos,edpos,getLen;

    stpos=strstr(s,"\n")-s+1;
    edpos=strstr(s+stpos,"\n")-s;

    if(edpos-stpos<=0) return 0;
    getLen=base64_decode(buffer,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;
    RSA_char2bn(&key->n,(char*)buffer,getLen);

    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=base64_decode(buffer,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;
    RSA_char2bn(&key->e,(char*)buffer,getLen);

    if(key->type==2) return 1;

    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=base64_decode(buffer,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;
    RSA_char2bn(&key->p,(char*)buffer,getLen);


    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=base64_decode(buffer,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;
    RSA_char2bn(&key->q,(char*)buffer,getLen);


    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=base64_decode(buffer,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;
    RSA_char2bn(&key->d,(char*)buffer,getLen);

    return 1;

}
int RSA_char2bn(pBIGNUM bn,const char* str,int len)
{
    BN_zero(bn);
    memcpy(bn->num,str,len);
    return 1;
}
int RSA_bn2char(char* str,const BIGNUM* bn,int len)
{
    memcpy(str,bn->num,len);
    return 1;
}
int RSA_text_encrypt(char* mi,const char* yuan,int yuanLen,const RSAKEY* pubKey)
{
    if(pubKey->type!=1&&pubKey->type!=2) return 0;
    int i,miLen=0;
    BIGNUM block_mi,block_yuan;
    for(i=0; i+EN_BLK_SIZE<=yuanLen; i+=EN_BLK_SIZE)
    {
        RSA_char2bn(&block_yuan,yuan+i,EN_BLK_SIZE);
        RSA_encrypt(&block_mi,&block_yuan,pubKey);
        RSA_bn2char(mi+miLen,&block_mi,DE_BLK_SIZE);
        miLen+=DE_BLK_SIZE;
    }
    if(i<yuanLen)
    {
        char buffer[EN_BLK_SIZE+10];
        memset(buffer,0,EN_BLK_SIZE+10);
        memcpy(buffer,yuan+i,yuanLen-i);
        RSA_char2bn(&block_yuan,buffer,EN_BLK_SIZE);
        RSA_encrypt(&block_mi,&block_yuan,pubKey);
        RSA_bn2char(mi+miLen,&block_mi,DE_BLK_SIZE);
        miLen+=DE_BLK_SIZE;
    }
    return miLen;
}
int RSA_text_decrypt(char* yuan,const char* mi,int miLen,const RSAKEY* priKey)
{
    if(priKey->type!=1) return 0;
    int i,yuanLen=0;
    BIGNUM block_mi,block_yuan;
    for(i=0; i+DE_BLK_SIZE<=miLen; i+=DE_BLK_SIZE)
    {
        RSA_char2bn(&block_mi,mi+i,DE_BLK_SIZE);
        RSA_decrypt(&block_yuan,&block_mi,priKey);
        RSA_bn2char(yuan+yuanLen,&block_yuan,EN_BLK_SIZE);
        yuanLen+=EN_BLK_SIZE;
    }
    if(i<miLen)
    {
        char buffer[DE_BLK_SIZE+10];
        memset(buffer,0,DE_BLK_SIZE+10);
        memcpy(buffer,mi+i,miLen-i);
        RSA_char2bn(&block_mi,mi+i,DE_BLK_SIZE);
        RSA_decrypt(&block_yuan,&block_mi,priKey);
        RSA_bn2char(yuan+yuanLen,&block_yuan,EN_BLK_SIZE);
        yuanLen+=EN_BLK_SIZE;
    }
    return yuanLen;
}

int RSA_text_encrypt_base64(char* mi,const char* yuan,int yuanLen,const RSAKEY* pubKey)
{
    if(pubKey->type!=1&&pubKey->type!=2) return 0;
    int miLen,base64Len;
    char *buffer = (char*)malloc((yuanLen+KEYSIZE+100)*sizeof(char));
    if((miLen=RSA_text_encrypt(buffer,yuan,yuanLen,pubKey))<=0)
    {
        free(buffer);
        return 0;
    }
    if((base64Len=base64_encode(mi,(unsigned char*)buffer,miLen))<=0)
    {
        free(buffer);
        return 0;
    }
    free(buffer);
    return base64Len;
}

int RSA_text_decrypt_base64(char* yuan,const char* mi,int miLen,const RSAKEY* priKey)
{
    if(priKey->type!=1) return 0;
    int yuanLen,base64Len;
    char *buffer = (char*)malloc((miLen+KEYSIZE+100)*sizeof(char));
    if((base64Len=base64_decode((unsigned char*)buffer,mi,miLen))<=0)
    {
        free(buffer);
        return 0;
    }

    if((yuanLen=RSA_text_decrypt(yuan,buffer,base64Len,priKey))<=0)
    {
        free(buffer);
        return 0;
    }

    free(buffer);
    return yuanLen;
}
int RSA_key2file(const char* filename,const RSAKEY* key)
{
    FILE *fp;   //  头文件#include <stdio.h>
    if((fp=fopen(filename,"wt"))==NULL)
    {
        printf("file cannot open \n");
        exit(0);  //头文件#include <stdlib.h>
        //exit结束程序，一般0为正常推出，其它数字为异常，其对应的错误可以自己指定。
    }
    char *str=(char*)malloc(NUMSIZE*BASEBIT);
    if(RSA_key_output(str,key)<=0)
        printf("generate string error \n");
    else
        fputs(str,fp);
    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    free(str);
    return 1;
}

int RSA_file2key(pRSAKEY key,const char* filename)
{
    FILE *fp;   //  头文件#include <stdio.h>
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("file cannot open \n");
        exit(0);  //头文件#include <stdlib.h>
        //exit结束程序，一般0为正常推出，其它数字为异常，其对应的错误可以自己指定。
    }
    char *str=(char*)malloc(NUMSIZE*BASEBIT);
    int i=0;
    while((str[i++]=fgetc(fp))!=EOF)
        ;
    str[i]='\0';
    if(RSA_key_import(key,str)<=0)
        printf("convert string to key error \n");
    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    free(str);
    return 1;
}
