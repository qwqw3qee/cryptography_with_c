#ifndef BIGNUM_DEC_H_INCLUDED
#define BIGNUM_DEC_H_INCLUDED
/*
    头文件写法
    https://blog.csdn.net/zhanshen112/article/details/80193797
    https://www.cnblogs.com/gaosheng-221/p/6198625.html
    https://blog.csdn.net/u010148687/article/details/80080663
    二进制运算
    https://blog.csdn.net/harry_128/article/details/80150502
    大小端问题
    https://baike.baidu.com/item/%E5%A4%A7%E5%B0%8F%E7%AB%AF%E6%A8%A1%E5%BC%8F/6750542?fr=aladdin
    左右移位
    https://www.cnblogs.com/myblesh/articles/2431806.html
    大数运算
    https://blog.csdn.net/qq_36894136/article/details/79074728
    https://blog.csdn.net/qq_39539647/article/details/80327301
    openssl中与大数相关内容
    https://blog.csdn.net/liangjisheng/article/details/79445661
    https://blog.csdn.net/jnxxhzz/article/details/81235981
    大整数开根
    https://blog.csdn.net/LOI__DiJiang/article/details/49026811
    大数乘除整数
    https://blog.csdn.net/rhythm0_0/article/details/80027814
    大数取模运算
    https://blog.csdn.net/wu_cai_/article/details/44536271
    逆元的几种求法
    https://blog.csdn.net/guhaiteng/article/details/52123385
    Miller Rabin测试
    https://blog.csdn.net/qq_41791981/article/details/81945351
    https://www.cnblogs.com/elpsycongroo/p/7692812.html
    大素数随机生成
    http://ju.outofmemory.cn/entry/93761
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUMSIZE 2048
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define BITS2(x) ((x)/0.301+1)
#define BITS10(x) ((x)*0.301+1)

typedef struct bignum
{
    char num[NUMSIZE];
    int length;
    int sign;
}BIGNUM,*pBIGNUM;
typedef long long ll;

void BN_clear(pBIGNUM a);
int BN_copy(pBIGNUM a, const BIGNUM* b);
void BN_swap(pBIGNUM a,pBIGNUM b);
void BN_printf(const BIGNUM* a,int flag);
int hex2val(char ch);
int BN_bn2bin(char a[],const BIGNUM* b);
int BN_bn2hex(char a[],const BIGNUM* b);
int BN_bn2dec(char a[],const BIGNUM* b);
int BN_bn2any(char a[],const BIGNUM* b,int base);
int BN_dec2bn(pBIGNUM a,const char b[]);
int BN_hex2bn(pBIGNUM a,const char b[]);
int BN_any2bn(pBIGNUM a,const char b[],int base);

int BN_one(pBIGNUM a);
int BN_zero(pBIGNUM a);
BIGNUM BN_value_one();
int BN_set_word(pBIGNUM a,ll w);
ll BN_get_word(const BIGNUM* a);
int BN_is_zero(const BIGNUM* a);
int BN_is_one(const BIGNUM* a);
int BN_is_word(const BIGNUM* a,ll w);
int BN_is_odd(const BIGNUM* a);

int BN_trim(pBIGNUM a);
int BN_ucmp(const BIGNUM* a,const BIGNUM* b);
int BN_cmp(const BIGNUM* a,const BIGNUM* b);
int BN_uadd(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_usub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_sqr(pBIGNUM res,const BIGNUM* a);
int BN_div(pBIGNUM res,pBIGNUM rem,const BIGNUM* a,const BIGNUM* b);
int BN_mod(pBIGNUM rem,const BIGNUM* a,const BIGNUM* b);
int BN_nnmod(pBIGNUM res,const BIGNUM* a,const BIGNUM* m);
int BN_mod_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m);
int BN_mod_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m);
int BN_mod_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m);
int BN_mod_sqr(pBIGNUM res,const BIGNUM* a,const BIGNUM* m);
int BN_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_mod_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m);
int BN_gcd(pBIGNUM res,const BIGNUM* a,const BIGNUM* b);
int BN_add_word(pBIGNUM a,ll w);
int BN_sub_word(pBIGNUM a,ll w);
int BN_mul_word(pBIGNUM a,ll w);
ll BN_div_word(pBIGNUM a,ll w);
ll BN_mod_word(const BIGNUM* a,ll w);
int BN_extgcd(const BIGNUM* a,const BIGNUM* b,pBIGNUM d,pBIGNUM x,pBIGNUM y);
int BN_mod_inverse(pBIGNUM res,const BIGNUM* a,const BIGNUM* m);

int get_random(char a[],int len);
int BN_rand(pBIGNUM rnd,int bits,int top,int bottom);
//bits:需要生成随机数的位数
//top:为设置最高位的值，top=-1表示最高位设置为0,top=0表示最高位设置为1,top=1时，最高两位都设置成1
//bottom:不为0时，可以生成奇的随机数
int check(const BIGNUM* a,ll s,const BIGNUM* t,const BIGNUM* n);//不是素数返回1，可能是素数返回0
int BN_is_prime(const BIGNUM* a,int checks,int do_trial_division);
int BN_is_prime_slower(const BIGNUM* n,int checks);
int BN_trial_division(const BIGNUM* n);
int BN_generate_prime(pBIGNUM ret,int num,int mode,int safe);//mode为真时时间稳定但很慢，safe为真时生成安全素数
int BN_rand_prime(pBIGNUM ret,int num);
int BN_next_prime(pBIGNUM ret,int num,const BIGNUM* start);
int BN_is_safe_prime(const BIGNUM* a); //1是0不是-1出错




#endif // BIGNUM_DEC_H_INCLUDED
