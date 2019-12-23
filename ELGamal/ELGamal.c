#include "ELGamal.h"

int MD5_gets(unsigned char* md5val,unsigned char* str,int len)
{
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5,str,len);
    MD5Final(&md5,md5val);
    return 1;
}
int MD52char(char* md5,unsigned char* md5val)
{
    int i=0;
    for(i=0;i<16;++i)
    {
        sprintf(md5+i*2,"%02x",md5val[i]);
    }

    return 1;
}
int ELG_genKey(pELGKEY priKey,pELGKEY pubKey)
{
    BIGNUM p,p_2,q,g,g_n2,g_nq,x,y;
    BN_generate_prime(&p,KEYSIZE,0,1);
    pubKey->p=priKey->p=p;
    printf("generate p successfully!\n");
    BN_rshift1(&q,&p);
    do
    {
        BN_rand(&g,KEYSIZE,0,0);
        BN_mod(&g,&g,&p);
        BN_mod_sqr(&g_n2,&g,&p);
        BN_mod_exp(&g_nq,&g,&q,&p);
    }while(BN_is_one(&g)||BN_is_one(&g_n2)||BN_is_one(&g_nq));
    pubKey->g=priKey->g=g;
    printf("generate g successfully!\n");
    p_2=p;
    BN_sub_word(&p_2,2);
    do
    {
        BN_rand(&x,KEYSIZE-1,0,0);
    }while(BN_is_zero(&x)||BN_cmp(&x,&p_2)>0);
    priKey->x=x;
    printf("generate x successfully!\n");
    BN_zero(&pubKey->x);
    BN_mod_exp(&y,&g,&x,&p);
    pubKey->y=priKey->y=y;
    printf("generate y successfully!\n");
    priKey->type=1;
    pubKey->type=2;
    return 1;
}

void ELG_sign_printf(const ELGSIGN* sign,int base)
{
    if(sign->valid==1)
    {
        printf("\n-----------\nvaild:%d",sign->valid);
        printf("\n-----m-----\n");
        BN_printf(&sign->m,base);
        printf("\n-----r-----\n");
        BN_printf(&sign->r,base);
        printf("\n-----s-----\n");
        BN_printf(&sign->s,base);
        printf("\n-----------\n");
    }
    else
        printf("Wrong signature!\n");
}

void ELG_key_printf(const ELGKEY* a,int base)
{
    if(a->type==1)
    {
        printf("\n-----------\ntype:Private Key");
        printf("\n-----y-----\n");
        BN_printf(&a->y,base);
        printf("\n-----g-----\n");
        BN_printf(&a->g,base);
        printf("\n-----p-----\n");
        BN_printf(&a->p,base);
        printf("\n-----x-----\n");
        BN_printf(&a->x,base);
        printf("\n-----------\n");
    }
    else if(a->type==2)
    {
        printf("\n-----------\ntype:Public Key");
        printf("\n-----y-----\n");
        BN_printf(&a->y,base);
        printf("\n-----g-----\n");
        BN_printf(&a->g,base);
        printf("\n-----p-----\n");
        BN_printf(&a->p,base);
        printf("\n-----------\n");
    }
    else
        printf("Wrong key!\n");
}



int ELG_sign(pELGSIGN elgSign,const BIGNUM* m,const ELGKEY* priKey)
{
    if(priKey->type!=1) return 0;
    BIGNUM k,k_n,p_2=priKey->p,p_1=priKey->p,gcd;
    BN_sub_word(&p_1,1);
    BN_sub_word(&p_2,2);
    do
    {
        BN_rand(&k,KEYSIZE-1,0,1);
        BN_gcd(&gcd,&k,&p_1);
    }while(BN_is_zero(&k)||BN_cmp(&k,&p_2)>0||BN_is_one(&gcd)!=1);
    BN_mod_inverse(&k_n,&k,&p_1);
    BN_mod_exp(&elgSign->r,&priKey->g,&k,&priKey->p);
    BN_mod_mul(&elgSign->s,&elgSign->r,&priKey->x,&p_1);
    BN_mod_sub(&elgSign->s,m,&elgSign->s,&p_1);
    BN_mod_mul(&elgSign->s,&elgSign->s,&k_n,&p_1);
    elgSign->m=*m;
    elgSign->valid=1;
    return 1;
}
int ELG_verify(const ELGSIGN* elgSign,const ELGKEY* pubKey)
{
    if(pubKey->type!=1&&pubKey->type!=2&&elgSign->valid!=1) return 0;
    BIGNUM ty,tr,left,right;
    BN_mod_exp(&ty,&pubKey->y,&elgSign->r,&pubKey->p);
    BN_mod_exp(&tr,&elgSign->r,&elgSign->s,&pubKey->p);
    BN_mod_mul(&left,&ty,&tr,&pubKey->p);
    BN_mod_exp(&right,&pubKey->g,&elgSign->m,&pubKey->p);
    BN_printf(&left,16);
    printf("...");
    BN_printf(&right,16);
    printf("...");
    return BN_cmp(&left,&right)==0?1:-1;
}




int ELG_bn2base64(char* s,const BIGNUM* bn,int bnlen)
{
    int len;
    char *str=(char*)malloc((bnlen+100)*sizeof(char));
    ELG_bn2char(str,bn,bnlen);
    len=base64_encode(s,(unsigned char*)str,bnlen);
    free(str);
    return len;
}
int ELG_base642bn(pBIGNUM bn,const char* s,int len)
{
    char *str=(char*)malloc((len+100)*sizeof(char));
    int bnlen=base64_decode((unsigned char*)str,s,len);
    if(bnlen<=0)
    {
        free(str);
        return 0;
    }
    int flag=ELG_char2bn(bn,str,bnlen);
    free(str);
    return flag;
}

int ELG_key2base64(char* s,const ELGKEY* key)
{
    int base64len=0,i;
    s[base64len++]=key->type+'0';
    s[base64len++]='\n';

    i=ELG_bn2base64(s+base64len,&key->y,KEYSIZE/8);
    if(i<=0) return 0;
    base64len+=i;
    s[base64len++]='\n';

    i=ELG_bn2base64(s+base64len,&key->g,KEYSIZE/8);
    if(i<=0) return 0;
    base64len+=i;
    s[base64len++]='\n';

    i=ELG_bn2base64(s+base64len,&key->p,KEYSIZE/8);
    if(i<=0) return 0;
    base64len+=i;
    s[base64len++]='\n';

    if(key->type==2) return base64len;

    i=ELG_bn2base64(s+base64len,&key->x,KEYSIZE/8);
    if(i<=0) return 0;
    base64len+=i;
    s[base64len++]='\n';
    s[base64len]='\0';
    return base64len;
}

int ELG_base642key(ELGKEY* key,const char* s)
{
    key->type=s[0]-'0';

    int stpos,edpos,getLen;
    stpos=strstr(s,"\n")-s+1;
    edpos=strstr(s+stpos,"\n")-s;

    if(edpos-stpos<=0) return 0;
    getLen=ELG_base642bn(&key->y,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;

    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=ELG_base642bn(&key->g,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;

    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=ELG_base642bn(&key->p,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;

    if(key->type==2) return 1;

    stpos=edpos+1;
    edpos=strstr(s+stpos,"\n")-s;
    if(edpos-stpos<=0) return 0;
    getLen=ELG_base642bn(&key->x,s+stpos,edpos-stpos);
    if(getLen<=0) return 0;

    return 1;
}



int ELG_sign2base64(char* s,const ELGSIGN* sign)
{
    if(sign->valid!=1) return 0;
    char *str=(char*)malloc((KEYSIZE+100)*sizeof(char));
    int len=0;
    ELG_bn2char(str,&sign->m,16);
    ELG_bn2char(str+16,&sign->r,KEYSIZE/8);
    ELG_bn2char(str+16+KEYSIZE/8,&sign->s,KEYSIZE/8);
    len=base64_encode(s,(unsigned char*)str,16+KEYSIZE/4);
    return len;
}
int ELG_base642sign(pELGSIGN sign,const char* s,int len)
{
    char *str=(char*)malloc((KEYSIZE)*sizeof(char));
    int len2=base64_decode((unsigned char*)str,s,len);
    if(len2<=0)
    {
        free(str);
        return 0;
    }
    ELG_char2bn(&sign->m,str,16);
    ELG_char2bn(&sign->r,str+16,KEYSIZE/8);
    ELG_char2bn(&sign->s,str+16+KEYSIZE/8,KEYSIZE/8);
    sign->valid=1;
    return 1;
}

int ELG_char2bn(pBIGNUM bn,const char* str,int len)
{
    BN_zero(bn);
    memcpy(bn->num,str,len);
    return 1;
}
int ELG_bn2char(char* str,const BIGNUM* bn,int len)
{
    memcpy(str,bn->num,len);
    return 1;
}
int ELG_sign_md5(pELGSIGN elgSign,const char* md5,const ELGKEY* priKey)
{
    if(priKey->type!=1) return 0;
    BIGNUM m;
    if(BN_hex2bn(&m,md5)!=1) return 0;
    if(BN_is_zero(&m)) return 0;
    return ELG_sign(elgSign,&m,priKey);
}
int ELG_sign_text(pELGSIGN elgSign,const char* str,int len,const ELGKEY* priKey)
{
    if(priKey->type!=1) return 0;
    BIGNUM m;
    unsigned char md5val[20];
    char md5[40];
    if(MD5_gets(md5val,(unsigned char*)str,len)!=1) return 0;
    MD52char(md5,md5val);
    if(BN_hex2bn(&m,md5)!=1) return 0;
    if(BN_is_zero(&m)) return 0;
    printf("\nmd5:%s\n",md5);
    return ELG_sign(elgSign,&m,priKey);
}
int ELG_cmp_signature_text(const char* str,int len,const ELGSIGN* elgSign)
{
    if(elgSign->valid!=1) return 0;
    BIGNUM m;
    unsigned char md5val[20];
    char md5[40];
    if(MD5_gets(md5val,(unsigned char*)str,len)!=1) return 0;
    MD52char(md5,md5val);
    if(BN_hex2bn(&m,md5)!=1) return 0;
    if(BN_is_zero(&m)) return 0;
    printf("\nmd5:%s\n",md5);
    return BN_cmp(&m,&elgSign->m)==0?1:-1;
}
int ELG_cmp_signature_md5(const char* md5,const ELGSIGN* elgSign)
{
    if(elgSign->valid!=1) return 0;
    BIGNUM m;
    if(BN_hex2bn(&m,md5)!=1) return 0;

    if(BN_is_zero(&m)) return 0;
    return BN_cmp(&m,&elgSign->m)==0?1:-1;
}
int ELG_key2file(const char* filename,const ELGKEY* key)
{
    FILE *fp;   //  头文件#include <stdio.h>
    if((fp=fopen(filename,"wt"))==NULL)
    {
        printf("file cannot open \n");
        exit(0);  //头文件#include <stdlib.h>
        //exit结束程序，一般0为正常推出，其它数字为异常，其对应的错误可以自己指定。
    }
    char *str=(char*)malloc(NUMSIZE*BASEBIT);
    if(ELG_key2base64(str,key)<=0)
        printf("generate string error \n");
    else
        fputs(str,fp);
    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    free(str);
    return 1;
}

int ELG_file2key(pELGKEY key,const char* filename)
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
    if(ELG_base642key(key,str)<=0)
        printf("convert string to key error \n");
    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    free(str);
    return 1;
}


int ELG_getfile_md5(char* md5,const char* filename)
{
    MD5_CTX md5_ctx;
    MD5Init(&md5_ctx);
    FILE *fp;   //  头文件#include <stdio.h>
    if((fp=fopen(filename,"rb"))==NULL)
    {
        printf("file cannot open \n");
        exit(0);  //头文件#include <stdlib.h>
        //exit结束程序，一般0为正常推出，其它数字为异常，其对应的错误可以自己指定。
    }
    char ch[10];
    unsigned char str[20];
    while((ch[0]=fgetc(fp))!=EOF)
        MD5Update(&md5_ctx,(unsigned char*)ch,1);
    MD5Final(&md5_ctx,(unsigned char*)str);
    MD52char(md5,str);
    if(fclose(fp)!=0)
        printf("file cannot be closed \n");
    return 1;
}
