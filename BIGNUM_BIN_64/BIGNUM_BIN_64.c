#include "BIGNUM_BIN_64.h"
const ull shf[64]=
{
    0x0000000000000001ULL,0x0000000000000002ULL,0x0000000000000004ULL,0x0000000000000008ULL,0x0000000000000010ULL,0x0000000000000020ULL,0x0000000000000040ULL,0x0000000000000080ULL,
    0x0000000000000100ULL,0x0000000000000200ULL,0x0000000000000400ULL,0x0000000000000800ULL,0x0000000000001000ULL,0x0000000000002000ULL,0x0000000000004000ULL,0x0000000000008000ULL,
    0x0000000000010000ULL,0x0000000000020000ULL,0x0000000000040000ULL,0x0000000000080000ULL,0x0000000000100000ULL,0x0000000000200000ULL,0x0000000000400000ULL,0x0000000000800000ULL,
    0x0000000001000000ULL,0x0000000002000000ULL,0x0000000004000000ULL,0x0000000008000000ULL,0x0000000010000000ULL,0x0000000020000000ULL,0x0000000040000000ULL,0x0000000080000000ULL,
    0x0000000100000000ULL,0x0000000200000000ULL,0x0000000400000000ULL,0x0000000800000000ULL,0x0000001000000000ULL,0x0000002000000000ULL,0x0000004000000000ULL,0x0000008000000000ULL,
    0x0000010000000000ULL,0x0000020000000000ULL,0x0000040000000000ULL,0x0000080000000000ULL,0x0000100000000000ULL,0x0000200000000000ULL,0x0000400000000000ULL,0x0000800000000000ULL,
    0x0001000000000000ULL,0x0002000000000000ULL,0x0004000000000000ULL,0x0008000000000000ULL,0x0010000000000000ULL,0x0020000000000000ULL,0x0040000000000000ULL,0x0080000000000000ULL,
    0x0100000000000000ULL,0x0200000000000000ULL,0x0400000000000000ULL,0x0800000000000000ULL,0x1000000000000000ULL,0x2000000000000000ULL,0x4000000000000000ULL,0x8000000000000000ULL
};
const int miniPrime[1228] = {
    3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
    181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,
    421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,
    673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,
    953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,
    1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,
    1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,
    1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,
    2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,
    2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,
    2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,
    3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,
    3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,
    3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,
    4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,
    4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,
    4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,
    5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,
    5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,
    5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,
    6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,
    6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,
    6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,
    7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,
    7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919,7927,
    7933,7937,7949,7951,7963,7993,8009,8011,8017,8039,8053,8059,8069,8081,8087,8089,8093,8101,8111,8117,8123,8147,8161,8167,8171,8179,8191,8209,8219,8221,8231,8233,8237,8243,8263,8269,8273,8287,8291,8293,
    8297,8311,8317,8329,8353,8363,8369,8377,8387,8389,8419,8423,8429,8431,8443,8447,8461,8467,8501,8513,8521,8527,8537,8539,8543,8563,8573,8581,8597,8599,8609,8623,8627,8629,8641,8647,8663,8669,8677,8681,
    8689,8693,8699,8707,8713,8719,8731,8737,8741,8747,8753,8761,8779,8783,8803,8807,8819,8821,8831,8837,8839,8849,8861,8863,8867,8887,8893,8923,8929,8933,8941,8951,8963,8969,8971,8999,9001,9007,9011,9013,
    9029,9041,9043,9049,9059,9067,9091,9103,9109,9127,9133,9137,9151,9157,9161,9173,9181,9187,9199,9203,9209,9221,9227,9239,9241,9257,9277,9281,9283,9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,
    9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,
    9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973
};
const int testPrime[10]={2,3,7,61,24251};
const char alphalist[16]="0123456789ABCDEF";


int hex2val(char ch)
{
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='a'&&ch<='f') return ch-'a'+10;
    if(ch>='A'&&ch<='F') return ch-'A'+10;
    return -1;
}
int BN_get_bit_size(const BIGNUM* a)
{
    int unit=BN_get_unitnum(a);
    if(unit==0) return 0;
    int size=(unit-1)*BASEBIT;
    ull tmp=a->num[unit-1];
    while(tmp)
    {
        tmp>>=1;
        ++size;
    }
    return size;
}
int BN_is_negative(const BIGNUM* a)
{
    return (a->num[NUMSIZE-1]&shf[BASEBIT-1])!=0;
}
int BN_bit_inverse(pBIGNUM res,const BIGNUM* a)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        res->num[i]=~a->num[i];
    return 1;
}
int BN_bit_opposite(pBIGNUM res,const BIGNUM* a)
{
    BN_bit_inverse(res,a);
    BN_add_one(res,res);
    return 1;
}

int BN_bit_xor(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        res->num[i]=a->num[i]^b->num[i];
    return 1;
}
int BN_bit_and(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        res->num[i]=a->num[i]&b->num[i];
    return 1;
}
int BN_bit_or(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        res->num[i]=a->num[i]|b->num[i];
    return 1;
}

void BN_clear(pBIGNUM a)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        a->num[i]=ZERO;
}
int BN_copy(pBIGNUM a,const BIGNUM* b)
{
    *a=*b;
    return 1;
}
void BN_swap(pBIGNUM a,pBIGNUM b)
{
    BIGNUM c = *a;
    *a = *b;
    *b = c;
}
void BN_printf(const BIGNUM* a,int flag)
{
    int i;
    char buffer[NUMSIZE*BASEBIT+10];
    switch(flag)
    {
        case 10:
            BN_bn2dec(buffer,a);
            break;
        case 16:
            BN_bn2hex(buffer,a);
            break;
        default:
            if(flag>0&&flag<16)
                BN_bn2any(buffer,a,flag);
            else
            {
                sprintf(buffer,"0x");
                for(i=NUMSIZE-1; i >= 0; --i)
                    sprintf(buffer+2+(NUMSIZE-i-1)*16,"%016I64X",a->num[i]);
            }
    }
    printf("%s",buffer);
}
int BN_bn2any(char a[],const BIGNUM* b,int base)
{
    if(base<0||base>16) return 0;
    int len=0,temp;
    BIGNUM tb=*b;
    if(BN_is_zero(b))
    {
        sprintf(a,"0(%d)",base);
        return 1;
    }
    while(BN_is_zero(&tb)==0)
    {
        temp=BN_div_word(&tb,base);
        if(temp<0) return 0;
        a[len++]=alphalist[temp];
    }
    if(BN_is_negative(b)) a[len++]='-';
    a[len]='\0';
    int i;
    char j;
    for(i=0;i<len/2;i++)
    {
        j=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=j;
    }
    sprintf(a+len,"(%d)",base);
    return 1;
}
int BN_bn2dec(char a[],const BIGNUM* b)
{
    BIGNUM tb=*b;
    if(BN_is_zero(&tb))
    {
        sprintf(a,"0");
        return 1;
    }
    int len=0,i,sign=BN_is_negative(&tb);
    char j;
    if(sign) BN_bit_opposite(&tb,&tb);
    while(!BN_is_zero(&tb))
        a[len++]=(char)BN_div_word(&tb,10)+'0';
    if(sign)
        a[len++]='-';
    a[len]='\0';
    for(i=0;i<len/2;i++)
    {
        j=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=j;
    }
    return 1;
}
int BN_bn2hex(char a[],const BIGNUM* b)
{
    int i,sign=BN_is_negative(b);
    sprintf(a,"0x");
    for(i=NUMSIZE-1; i >= 0; --i)
    {
        if(sign&&b->num[i]==INF) continue;
        else if(b->num[i]==ZERO) continue;
        else
        {
            sprintf(a+2,"%I64X",b->num[i]);
            break;
        }
    }
    int stpos=--i,len=strlen(a);
    if(i<-1)
        sprintf(a+len,"0");
    for( ;i >= 0; --i)
        sprintf(a+len+(stpos-i)*16,"%016I64X",b->num[i]);

    return 1;
}
int BN_any2bn(pBIGNUM a,const char b[],int base)
{
    int i,len=strlen(b),sign=(b[0]=='-'),tmp;
    if(b[len-1]==')')
    {
        char flag[10];
        sprintf(flag,"(%d)",base);
        int flaglen=strlen(flag);
        if(strcmp(b+len-flaglen,flag)!=0)
            return 0;
        len-=flaglen;
    }
    BN_zero(a);
    for(i=sign; i<len; ++i)
    {
        BN_mul_word(a,base);
        tmp=hex2val(b[i]);
        if(tmp<0||tmp>=base)
        {
            BN_zero(a);
            return 0;
        }
        BN_add_word(a,tmp);
    }
    if(sign) BN_bit_opposite(a,a);
    return 1;
}
int BN_dec2bn(pBIGNUM a,const char b[])
{
    int i,len=strlen(b),sign=(b[0]=='-');
    BN_zero(a);
    for(i=sign; i<len; ++i)
    {
        BN_mul_word(a,10);
        if(b[i]<'0'||b[i]>'9')
        {
            BN_zero(a);
            return 0;
        }
        BN_add_word(a,b[i]-'0');
    }
    if(sign) BN_bit_opposite(a,a);
    return 1;
}
int BN_hex2bn(pBIGNUM a,const char b[])
{
    int i,len=strlen(b),sign=(b[0]=='-');
    BN_zero(a);
    if(len>NUMSIZE*16) return 0;
    i=sign;
    if(b[sign]=='0'&&b[sign+1]=='x')
        i+=2;
    for(; i<len; ++i)
    {
        BN_lshift(a,a,4);
        switch(b[i])
        {
        case '0':
            a->num[0]|=0x0;
            break;
        case '1':
            a->num[0]|=0x1;
            break;
        case '2':
            a->num[0]|=0x2;
            break;
        case '3':
            a->num[0]|=0x3;
            break;
        case '4':
            a->num[0]|=0x4;
            break;
        case '5':
            a->num[0]|=0x5;
            break;
        case '6':
            a->num[0]|=0x6;
            break;
        case '7':
            a->num[0]|=0x7;
            break;
        case '8':
            a->num[0]|=0x8;
            break;
        case '9':
            a->num[0]|=0x9;
            break;
        case 'a':
            a->num[0]|=0xA;
            break;
        case 'b':
            a->num[0]|=0xB;
            break;
        case 'c':
            a->num[0]|=0xC;
            break;
        case 'd':
            a->num[0]|=0xD;
            break;
        case 'e':
            a->num[0]|=0xE;
            break;
        case 'f':
            a->num[0]|=0xF;
            break;
        case 'A':
            a->num[0]|=0xA;
            break;
        case 'B':
            a->num[0]|=0xB;
            break;
        case 'C':
            a->num[0]|=0xC;
            break;
        case 'D':
            a->num[0]|=0xD;
            break;
        case 'E':
            a->num[0]|=0xE;
            break;
        case 'F':
            a->num[0]|=0xF;
            break;
        default:
            BN_zero(a);
            return 0;
        }
    }
    if(sign) BN_bit_opposite(a,a);
    return 1;
}
int BN_lshift1(pBIGNUM res,const BIGNUM* a)
{
    //丢弃最高位,0补最低位
    int i,reg_lt=0,reg_rt=0;
    for(i = 0; i < NUMSIZE; ++i)
    {
        reg_lt=((a->num[i]&shf[BASEBIT-1])!=0);
        res->num[i]=(a->num[i]<<1);
        if(reg_rt)
            res->num[i] |= shf[0];
        reg_rt = reg_lt;
    }
    return 1;
}
int BN_rshift1(pBIGNUM res,const BIGNUM* a)
{
    //正数补0,负数补1
    int i,reg_lt=BN_is_negative(a),reg_rt=0;
    for(i = NUMSIZE-1; i >= 0; --i)
    {
        reg_rt=((a->num[i]&shf[0])!=0);
        res->num[i]=(a->num[i]>>1);
        if(reg_lt)
            res->num[i] |= shf[BASEBIT-1];
        reg_lt = reg_rt;
    }
    return 1;
}
int BN_lshift(pBIGNUM res,const BIGNUM* a,int n)
{
    if(n<0) return 0;
    n%=(NUMSIZE*BASEBIT);
    int dn=n/BASEBIT;
    n%=BASEBIT;
    *res=*a;
    while(dn--) BN_lshift_basebit(res,res);
    while(n--) BN_lshift1(res,res);
    return 1;
}
int BN_rshift(pBIGNUM res,const BIGNUM* a,int n)
{
    if(n<0) return 0;
    n%=(NUMSIZE*BASEBIT);
    int dn=n/BASEBIT;
    n%=BASEBIT;
    *res=*a;
    while(dn--) BN_rshift_basebit(res,res);
    while(n--) BN_rshift1(res,res);
    return 1;
}
int BN_lshift_basebit(pBIGNUM res,const BIGNUM* a)
{
    //丢弃最高位,0补最低位
    int i;
    for(i=NUMSIZE-1; i >=1; --i)
        res->num[i]=a->num[i-1];
    res->num[0]=ZERO;
    return 1;
}
int BN_rshift_basebit(pBIGNUM res,const BIGNUM* a)
{
    //正数补0,负数补1
    int i,sign=BN_is_negative(a);
    for(i=0; i<NUMSIZE-1; ++i)
        res->num[i]=a->num[i+1];
    if(sign)
        res->num[NUMSIZE-1]=INF;
    else
        res->num[NUMSIZE-1]=ZERO;
    return 1;
}
BIGNUM BN_value_one()
{
    BIGNUM a;
    BN_one(&a);
    return a;
}
int BN_set_word(pBIGNUM a,ll w)
{
    int i;
    if(w<0)
    {
        for(i=NUMSIZE-1; i>=1; --i)
            a->num[i]=INF;
    }
    else
    {
        for(i=NUMSIZE-1; i>=1; --i)
            a->num[i]=ZERO;
    }
    a->num[0]=w;
    return 1;
}
ll BN_get_word(const BIGNUM* a)
{
    int i;
    int flag=((a->num[0]&shf[BASEBIT-1])!=ZERO);
    if(flag)
    {
        for(i=NUMSIZE-1; i>=1; --i)
        {
            if(a->num[i]!=INF)
                return 0;
        }
    }
    else
    {
        for(i=NUMSIZE-1; i>=1; --i)
        {
            if(a->num[i]!=ZERO)
                return 0;
        }
    }
    return a->num[0];
}
int BN_one(pBIGNUM a)
{
    int i;
    a->num[0]=ONE;
    for(i=1; i<NUMSIZE; ++i)
        a->num[i]=ZERO;
    return 1;
}
int BN_zero(pBIGNUM a)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
        a->num[i]=ZERO;
    return 1;
}
int BN_is_zero(const BIGNUM* a)
{
    int i;
    for(i=0; i<NUMSIZE; ++i)
    {
        if(a->num[i]!=ZERO)
            return 0;
    }
    return 1;
}
int BN_is_one(const BIGNUM* a)
{
    int i;
    if(a->num[0]!=ONE) return 0;
    for(i=1; i<NUMSIZE; ++i)
    {
        if(a->num[i]!=ZERO)
            return 0;
    }
    return 1;
}
int BN_is_word(const BIGNUM* a,ll w)
{
    int i,flag = w<0;
    if(a->num[0]!=w) return 0;
    if(flag)
    {
        for(i=1; i<NUMSIZE; ++i)
        {
            if(a->num[i]!=INF)
                return 0;
        }
    }
    else
    {
        for(i=1; i<NUMSIZE; ++i)
        {
            if(a->num[i]!=ZERO)
                return 0;
        }
    }
    return 1;
}
int BN_is_odd(const BIGNUM* a)
{
    return a->num[0]&ONE;
}


int BN_ucmp(const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM ta=*a,tb=*b;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    return BN_cmp(&ta,&tb);
}
int BN_cmp(const BIGNUM* a,const BIGNUM* b)
{
    int a_sign=BN_is_negative(a),b_sign=BN_is_negative(b),i;
    if(a_sign!=b_sign) return a_sign<b_sign?1:-1;
    for(i=NUMSIZE-1; i>=0; --i)
    {
        if(a->num[i]!=b->num[i])
            return a->num[i]>b->num[i]?1:-1;
    }
    return 0;
}
int BN_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM ta=*a,tb=*b;
    ull carry=ZERO;
    int i;
    for(i=0; i<NUMSIZE; ++i)
    {
        if(carry==ZERO)
        {
            res->num[i]=ta.num[i]+tb.num[i];
            if(res->num[i]<ta.num[i]&&res->num[i]<tb.num[i])
                carry=ONE;
            else
                carry=ZERO;
        }
        else
        {
            res->num[i]=ta.num[i]+tb.num[i]+carry;
            if(res->num[i]<=ta.num[i]&&res->num[i]<=tb.num[i])
                carry=ONE;
            else
                carry=ZERO;
        }
    }
    return 1;
}
int BN_add_one(pBIGNUM res,const BIGNUM* a)
{
    ull carry=ONE,pre;
    *res=*a;
    int i;
    for(i=0; i<NUMSIZE; ++i)
    {
        pre=res->num[i];
        res->num[i]=res->num[i]+carry;
        if(res->num[i]>=pre) return 1;
    }
    return 1;
}
int BN_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM opb=*b;
    BN_bit_opposite(&opb,&opb);
    return BN_add(res,a,&opb);
}
//快速加，慢
int BN_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM ta=*a,tb=*b;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb),res_sign;
    res_sign=(a_sign^b_sign);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    BN_zero(res);
    while(!BN_is_zero(&tb))
    {
        if(tb.num[0]&shf[0])
            BN_add(res,res,&ta);
        BN_lshift1(&ta,&ta);
        BN_rshift1(&tb,&tb);
    }
    if(res_sign)
        BN_bit_opposite(res,res);
    return 1;
}
int BN_sqr(pBIGNUM res,const BIGNUM* a)
{
    return BN_mul(res,a,a);
}
int BN_get_unitnum(const BIGNUM* a)
{
    int i,sign=BN_is_negative(a);
    if(sign)
    {
        for(i=NUMSIZE-1; i>=0; --i)
            if(a->num[i]!=INF)
                return i+1;
        return 1;
    }
    else
    {
        for(i=NUMSIZE-1; i>=0; --i)
            if(a->num[i]!=ZERO)
                return i+1;
    }
    return 0;
}
/*
////2^64进制除法+二分
int BN_div(pBIGNUM res,pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(BN_is_zero(b))
    {
        BN_zero(res);
        BN_zero(rem);
        return 0;
    }
    if(BN_ucmp(a,b)<0)
    {
        *rem=*a;
        BN_zero(res);
        return 1;
    }
    BIGNUM ta=*a,tb=*b,tmp,mid,left,right;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb),res_sign;
    res_sign=(a_sign^b_sign);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    BN_zero(rem);
    BN_zero(res);
    BN_zero(&left);
    BN_zero(&right);
    BN_zero(&mid);
    int i,ta_len=BN_get_unitnum(&ta);
    for(i=ta_len-1; i>=0; --i)
    {
        BN_lshift_basebit(rem,rem);
        BN_zero(&tmp);
        tmp.num[0]=ta.num[i];
        BN_add(rem,rem,&tmp);
        left.num[0]=ZERO;
        right.num[0]=ZERO;
        right.num[1]=1;
        BN_add_one(&tmp,&left);
        while(BN_cmp(&tmp,&right)<0)
        {

            //BN_zero(&mid);
            //BN_add(&mid,&mid,&left);
            //BN_add(&mid,&mid,&right);
            //BN_rshift1(&mid,&mid);

            mid.num[0]=left.num[0]+right.num[0];
            mid.num[1]=right.num[1];
            if(mid.num[0]<left.num[0]&&mid.num[0]<right.num[0])
                mid.num[1]++;
            mid.num[0]>>=1;
            if(mid.num[1])
            {
                mid.num[1]>>=1;
                mid.num[0]|=shf[BASEBIT-1];
            }
            BN_mul(&tmp,&tb,&mid);
            if(BN_cmp(&tmp,rem)<=0)
                left.num[0]=mid.num[0];
            else
            {
                right.num[1]=0;
                right.num[0]=mid.num[0];
            }
            BN_add_one(&tmp,&left);
        }
        res->num[i]=left.num[0];
        BN_mul(&tmp,&tb,&left);
        BN_sub(rem,rem,&tmp);
    }
    if(res_sign)
        BN_bit_opposite(res,res);
    if(a_sign)
        BN_bit_opposite(rem,rem);
    return 1;
}
//2^64进制除法+二分
int BN_mod(pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(BN_is_zero(b))
    {
        BN_zero(rem);
        return 0;
    }
    if(BN_ucmp(a,b)<0)
    {
        *rem=*a;
        return 1;
    }
    BIGNUM ta=*a,tb=*b,tmp,mid,left,right;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    BN_zero(rem);
    BN_zero(&left);
    BN_zero(&right);
    BN_zero(&mid);
    int i,ta_len=BN_get_unitnum(&ta);
    for(i=ta_len-1; i>=0; --i)
    {
        BN_lshift_basebit(rem,rem);
        BN_zero(&tmp);
        tmp.num[0]=ta.num[i];
        BN_add(rem,rem,&tmp);
        left.num[0]=ZERO;
        right.num[0]=ZERO;
        right.num[1]=1;
        BN_add_one(&tmp,&left);
        while(BN_cmp(&tmp,&right)<0)
        {
            mid.num[0]=left.num[0]+right.num[0];
            mid.num[1]=right.num[1];
            if(mid.num[0]<left.num[0]&&mid.num[0]<right.num[0])
                mid.num[1]++;
            mid.num[0]>>=1;
            if(mid.num[1])
            {
                mid.num[1]>>=1;
                mid.num[0]|=shf[BASEBIT-1];
            }
            BN_mul(&tmp,&tb,&mid);
            if(BN_cmp(&tmp,rem)<=0)
                left.num[0]=mid.num[0];
            else
            {
                right.num[1]=0;
                right.num[0]=mid.num[0];
            }
            BN_add_one(&tmp,&left);
        }
        BN_mul(&tmp,&tb,&left);
        BN_sub(rem,rem,&tmp);
    }
    if(a_sign)
        BN_bit_opposite(rem,rem);
    return 1;
}

*/
//二进制竖式
int BN_div(pBIGNUM res,pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(BN_is_zero(b))
    {
        BN_zero(res);
        BN_zero(rem);
        return 0;
    }
    BIGNUM ta=*a,tb=*b;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb),res_sign;
    res_sign=(a_sign^b_sign);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    BN_zero(rem);
    BN_zero(res);
    int i,ix,iy,ta_len=BN_get_unitnum(&ta)*BASEBIT;
    for(i=ta_len-1; i>=0; --i)
    {
        BN_lshift1(res,res);
        BN_lshift1(rem,rem);
        ix=i/BASEBIT;
        iy=i%BASEBIT;
        if((ta.num[ix]&shf[iy])!=0)
            rem->num[0]=(rem->num[0]|shf[0]);
        if(BN_cmp(rem,&tb)>=0)
        {
            BN_sub(rem,rem,&tb);
            res->num[0]=(res->num[0]|shf[0]);
        }
    }
    if(res_sign)
        BN_bit_opposite(res,res);
    if(a_sign)
        BN_bit_opposite(rem,rem);
    return 1;
}
//二进制竖式
int BN_mod(pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(BN_is_zero(b))
    {
        BN_zero(rem);
        return 0;
    }
    BIGNUM ta=*a,tb=*b;
    int a_sign=BN_is_negative(&ta),b_sign=BN_is_negative(&tb);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    if(b_sign) BN_bit_opposite(&tb,&tb);
    BN_zero(rem);
    int i,ix,iy,ta_len=BN_get_unitnum(&ta)*BASEBIT;
    for(i=ta_len-1; i>=0; --i)
    {
        BN_lshift1(rem,rem);
        ix=i/BASEBIT;
        iy=i%BASEBIT;
        if((ta.num[ix]&shf[iy])!=0)
            rem->num[0]=(rem->num[0]|shf[0]);
        if(BN_cmp(rem,&tb)>=0)
            BN_sub(rem,rem,&tb);
    }
    if(a_sign)
        BN_bit_opposite(rem,rem);
    return 1;
}

//r = ( (a % m) + m) % m
int BN_nnmod(pBIGNUM res,const BIGNUM* a,const BIGNUM* m)
{
    BIGNUM ta=*a,tm=*m;
    BN_mod(res,&ta,&tm);
    if(BN_is_negative(res)==0) return 1;
    BN_add(res,res,&tm);
    return 1;
}
int BN_mod_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    BIGNUM ta=*a,tb=*b,tm=*m;
    //BN_mod(&ta,&ta,&tm);
    //BN_mod(&tb,&tb,&tm);
    BN_add(res,&ta,&tb);
    BN_nnmod(res,res,&tm);
    return 1;
}
int BN_mod_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_sub(res,&ta,&tb);
    BN_nnmod(res,res,&tm);
    return 1;
}
int BN_mod_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    BIGNUM tm=*m,ta=*a,tb=*b;
    BN_mod(&ta,&ta,&tm);
    BN_mod(&tb,&tb,&tm);
    if(BN_mul(res,&ta,&tb)==0) return 0;
    return BN_nnmod(res,res,&tm);
}
/*
//快速加，防止中间过程溢出用，慢，慎用！
int BN_mod_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_nnmod(&ta,&ta,&tm);
    BN_nnmod(&tb,&tb,&tm);
    BN_zero(res);
    while(!BN_is_zero(&tb))
    {
        if(tb.num[0]&shf[0])
            BN_mod_add(res,res,&ta,&tm);
        BN_lshift1(&ta,&ta);
        BN_mod(&ta,&ta,&tm);
        BN_rshift1(&tb,&tb);
    }
    return 1;
}*/
int BN_mod_sqr(pBIGNUM res,const BIGNUM* a,const BIGNUM* m)
{
    return BN_mod_mul(res,a,a,m);
}
int BN_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM ta=*a,tb=*b;
    int b_sign=BN_is_negative(&tb);
    if(b_sign) return 0;
    BN_one(res);
    while(!BN_is_zero(&tb))
    {
        if(tb.num[0]&shf[0])
            BN_mul(res,res,&ta);
        BN_sqr(&ta,&ta);
        BN_rshift1(&tb,&tb);
    }
    return 1;
}

int BN_mod_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_nnmod(&ta,&ta,&tm);
    BN_nnmod(&tb,&tb,&tm);
    BN_one(res);
    while(!BN_is_zero(&tb))
    {
        if(tb.num[0]&shf[0])
            BN_mod_mul(res,res,&ta,&tm);
        BN_mod_sqr(&ta,&ta,&tm);
        BN_rshift1(&tb,&tb);
    }
    return 1;
}

int BN_gcd(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    BIGNUM ta=*a,tb=*b;
    BN_mod(&ta,&ta,&tb);
    if(BN_is_zero(&ta))
    {
        *res=tb;
        return 1;
    }
    return BN_gcd(res,&tb,&ta);
}
int BN_add_word(pBIGNUM a,ll w)
{
    BIGNUM b;
    BN_set_word(&b,w);
    return BN_add(a,a,&b);
}
int BN_sub_word(pBIGNUM a,ll w)
{
    BIGNUM b;
    BN_set_word(&b,-w);
    return BN_add(a,a,&b);
}
int BN_mul_word(pBIGNUM a,ll w)
{
    BIGNUM b;
    BN_set_word(&b,w);
    return BN_mul(a,a,&b);
}

//二进制竖式
ll BN_div_word(pBIGNUM a,ll w)
{
    if(w==0)
    {
        BN_clear(a);
        return 0;
    }
    int w_sign=0;
    if(w<0)
    {
        w_sign=1;
        w=-w;
    }
    int a_sign=BN_is_negative(a),res_sign;
    ull rem=0;
    BIGNUM res;
    res_sign=(a_sign^w_sign);
    if(a_sign) BN_bit_opposite(a,a);
    BN_zero(&res);
    int i,ix,iy,ta_len=BN_get_unitnum(a)*BASEBIT;
    for(i=ta_len-1; i>=0; --i)
    {
        BN_lshift1(&res,&res);
        rem<<=1;
        ix=i/BASEBIT;
        iy=i%BASEBIT;
        if((a->num[ix]&shf[iy])!=0)
            rem|=shf[0];
        if(rem>=w)
        {
            rem-=w;
            res.num[0]|=shf[0];
        }
    }
    ll remm=rem;
    if(res_sign)
        BN_bit_opposite(&res,&res);
    if(a_sign)
        remm=-remm;
    *a=res;
    return remm;
}
//二进制竖式
ll BN_mod_word(const BIGNUM* a,ll w)
{
    if(w==0) return 0;
    ll s=0;
    BIGNUM ta=*a;
    int a_sign=BN_is_negative(a);
    if(a_sign) BN_bit_opposite(&ta,&ta);
    int i,ix,iy,ta_len=BN_get_unitnum(&ta)*BASEBIT;
    for(i=ta_len-1; i>=0; --i)
    {
        ix=i/BASEBIT;
        iy=i%BASEBIT;
        s=(s<<1)%w;
        if((ta.num[ix]&shf[iy])!=0)
            s=(s+1)%w;
    }
    if(a_sign) s=-s;
    return s;
}
/*
//通用
ll BN_div_word(pBIGNUM a,ll w)
{
    BIGNUM tem;
    BN_set_word(&tem,w);
    if(BN_div(a,&tem,a,&tem)==0) return 0;
    return BN_get_word(&tem);
}
//通用
ll BN_mod_word(const BIGNUM* a,ll w)
{
    BIGNUM tem;
    BN_set_word(&tem,w);
    if(BN_mod(&tem,a,&tem)==0) return 0;
    return BN_get_word(&tem);
}
*/
int BN_extgcd(const BIGNUM* a,const BIGNUM* b,pBIGNUM d,pBIGNUM x,pBIGNUM y)
{
    BIGNUM ta=*a,tb=*b,tem1,tem2;
    if(BN_is_zero(&tb))
    {
        *d=ta;
        BN_one(x);
        BN_zero(y);
        return 1;
    }
    BN_mod(&tem1,&ta,&tb);
    BN_extgcd(&tb,&tem1,d,y,x);
    BN_div(&tem1,&tem2,&ta,&tb);
    BN_mul(&tem1,x,&tem1);
    BN_sub(y,y,&tem1);
    return 1;
}
int BN_mod_inverse(pBIGNUM res,const BIGNUM* a,const BIGNUM* m)
{
    BIGNUM d,x,y;
    BN_extgcd(a,m,&d,&x,&y);
    if(BN_is_one(&d)==0)
    {
        BN_clear(res);
        return 0;
    }
    BN_nnmod(res,&x,m);
    return 1;
}

ull get_random_ull()
{

    ull ans=ZERO;
    int i;
    for(i=0; i<8; ++i)
    {
        ans <<= 8;
        ans |= random(0x00,0xff);
    }
    return ans;
}

int BN_rand(pBIGNUM rnd,int bits,int top,int bottom)
{
    int i,exsize = bits%BASEBIT;
    int bsize = bits/BASEBIT+(exsize!=0);
    if(bsize<=0) bsize=1;
    if(bsize > NUMSIZE) return 0;
    BIGNUM n;
    BN_zero(rnd);
    BN_one(&n);
    BN_lshift(&n,&n,bits);
    for(i=0; i<bsize; ++i)
        rnd->num[i]=get_random_ull();
    BN_mod(rnd,rnd,&n);
    BN_rshift1(&n,&n);
    switch(top)
    {
    case -1:
        BN_bit_or(rnd,rnd,&n);
        BN_sub(rnd,rnd,&n);
        break;
    case 0:
        BN_bit_or(rnd,rnd,&n);
        break;
    case 1:
        BN_set_word(&n,3);
        BN_lshift(&n,&n,bits-2);
        BN_bit_or(rnd,rnd,&n);
        break;
    }
    if(bottom)
        rnd->num[0]|=shf[0];
    return 1;
}

/*
int BN_rand(pBIGNUM rnd,int bits,int top,int bottom)
{
    int i,bsize = bits/BASEBIT;
    if(bsize<=0) bsize=1;
    if(bsize > NUMSIZE) return 0;
    BN_zero(rnd);
    for(i=0; i<bsize; ++i)
        rnd->num[i]=get_random_ull();
    switch(top)
    {
    case -1:
        if((rnd->num[bsize-1]&shf[BASEBIT-1])==0)
            rnd->num[bsize-1]+=shf[BASEBIT-1];
        break;
    case 0:
        rnd->num[bsize-1]|=shf[BASEBIT-1];
        break;
    case 1:
        rnd->num[bsize-1]|=0xC000000000000000ULL;
        break;
    }
    if(bottom)
        rnd->num[0]|=shf[0];
    return 1;
}*/
int check(const BIGNUM* a,ll s,const BIGNUM* t,const BIGNUM* n)//不是素数返回1，可能是素数返回0
{
    ll i;
    BIGNUM ta=*a,tt=*t,tn=*n,ret,temp,n_1=*n;
    BN_sub_word(&n_1,1);
    BN_mod_exp(&temp,&ta,&tt,&tn);
    ret=temp;
    for(i=0; i<s; ++i)
    {
        BN_mod_sqr(&ret,&temp,&tn);
        if(BN_is_one(&ret)&&(BN_is_one(&temp)==0)&&(BN_cmp(&temp,&n_1)!=0))
            return 1;
        temp=ret;
    }
    if(BN_is_one(&ret)==0)
            return 1;
    return 0;
}
int BN_is_prime(const BIGNUM* n,int checks,int do_trial_division)//do_trial_division为真时先尝试除以小素数)
{
    BIGNUM two,tenThousand;
    BN_set_word(&two,2);
    BN_set_word(&tenThousand,10000);
    int tmp = BN_cmp(n,&two);
    if(tmp==-1) return 0;
    else if(tmp==0) return 1;
    if(BN_is_odd(n)==0) return 0;
    if(do_trial_division&&BN_cmp(n,&tenThousand)>0&&BN_trial_division(n))
        return 0;
    ll s=0;
    BIGNUM t=*n,a; //n-1=(2^s)*t
    BN_sub_word(&t,1);
    while(!BN_is_odd(&t))
    {
        BN_rshift1(&t,&t);
        ++s;
    }
    int i,unitnum=BN_get_unitnum(n);
    for(i=0; i<checks; ++i)
    {
        if(i<5&&i<checks-1)
        {
            BN_set_word(&a,testPrime[i]);
            if(BN_cmp(&a,n)>=0) continue;
        }
        else
        {
            do{
                BN_rand(&a,unitnum*BASEBIT,-1,1);
                BN_nnmod(&a,&a,n);
            }while(BN_cmp(&a,n)>=0||BN_is_zero(&a));
        }
        if(check(&a,s,&t,n)) return 0;
    }
    return 1;
}
int BN_is_prime_slower(const BIGNUM* n,int checks)
{
    BIGNUM two,tenThousand;
    BN_set_word(&two,2);
    BN_set_word(&tenThousand,10000);
    int tmp = BN_cmp(n,&two);
    if(tmp==-1) return 0;
    else if(tmp==0) return 1;
    if(BN_is_odd(n)==0) return 0;
    BIGNUM t=*n,ans,a; //n-1=(2^s)*t
    BN_sub_word(&t,1);
    int i,unitnum=BN_get_unitnum(n);
    for(i=0; i<checks; ++i)
    {
        if(i<5&&i<checks-1)
        {
            BN_set_word(&a,testPrime[i]);
            if(BN_cmp(&a,n)>=0) continue;
        }
        else
        {
            do{
                BN_rand(&a,unitnum*BASEBIT,-1,1);
                BN_nnmod(&a,&a,n);
            }while(BN_cmp(&a,n)>=0||BN_is_zero(&a));
        }
        BN_mod_exp(&ans,&a,&t,n);
        if(BN_is_one(&ans)==0) return 0;
    }
    return 1;
}
int BN_trial_division(const BIGNUM* n)
{
    int i;
    for(i=0; i<24; ++i)
    {
        if(BN_mod_word(n,miniPrime[i])==0)
            return 1;
    }
    return 0;
}
/*
int BN_generate_prime(pBIGNUM ret,int num,int safe)//safe为真时生成安全素数
{
    BIGNUM rnd;
    int flag=0;
    //int cnt=0;
    BN_rand(&rnd,num,0,1);
    do{
        flag=BN_is_prime(&rnd,5,1);
        if(flag==0) BN_add_word(&rnd,2);
        else if(flag==1&&safe)
        {
            BIGNUM xp;
            BN_rshift1(&xp,&rnd);
            if((flag=BN_is_odd(&xp))==0)
                BN_add_word(&rnd,2);
            else if((flag=BN_is_prime(&xp,5,1))==0)
                BN_add_word(&rnd,2);
        }
        if(flag==-1) return 0;
        //cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    *ret = rnd;
    //printf("共计算了%d次\n",cnt);
    return 1;
}*/
/*
int BN_generate_prime(pBIGNUM ret,int num,int mode,int safe)//mode为真时时间稳定但很慢，safe为真时生成安全素数
{
    int flag=0;
    //int cnt=0;
    BN_rand(ret,num,0,1);
    do{
        if(mode)
            flag=BN_next_prime(ret,num,ret);
        else
            flag=BN_rand_prime(ret,num);
        if(flag==1&&safe)
            flag=BN_is_safe_prime(ret);
        //cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    //printf("共计算了%d次\n",cnt);
    return 1;
}
*/

int BN_generate_prime(pBIGNUM ret,int num,int mode,int safe)//mode为真时时间稳定但很慢，safe为真时生成安全素数
{
    int flag=0;
    //int cnt=0;
    if(safe)
    {
        num-=1;
        BIGNUM tmp;
        BN_rand(&tmp,num,0,1);
        do
        {
            if(mode)
                flag=BN_next_prime(&tmp,num,&tmp);
            else
                flag=BN_rand_prime(&tmp,num);
            if(flag==1)
            {
                BN_lshift1(ret,&tmp);
                ret->num[0]|=shf[0];
                flag=BN_is_prime(ret,5,1);
            }
            //cnt++;
            //printf("正在计算%d次\n",cnt);
        }while(flag!=1);
    }
    else
    {
        BN_rand(ret,num,0,1);
        do
        {
            if(mode)
                flag=BN_next_prime(ret,num,ret);
            else
                flag=BN_rand_prime(ret,num);
            //cnt++;
            //printf("正在计算%d次\n",cnt);
        }
        while(flag!=1);
    }
    //printf("共计算了%d次\n",cnt);
    return 1;
}
int BN_rand_prime(pBIGNUM ret,int num)
{
    int flag=0;
    //int cnt=0;
    do{
        BN_rand(ret,num,0,1);
        flag=BN_is_prime(ret,5,1);
        if(flag==-1) return 0;
        //cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    //printf("共计算了%d次\n",cnt);
    return 1;
}
int BN_next_prime(pBIGNUM ret,int num,const BIGNUM* start)
{
    int flag=0;
    //int cnt=0;
    if(start!=NULL)
    {
        if(BN_is_negative(start))
            return -1;
        *ret=*start;
        if(BN_is_odd(ret))
            BN_add_word(ret,2);
        else
            BN_add_word(ret,1);
    }
    else BN_rand(ret,num,0,1);
    do{
        flag=BN_is_prime(ret,5,1);
        if(flag==0) BN_add_word(ret,2);
        if(flag==-1) return 0;
        //cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    //printf("共计算了%d次\n",cnt);
    return 1;
}
int BN_is_safe_prime(const BIGNUM* a) //1是0不是-1出错
{
    int flag=BN_is_prime(a,5,1);
    if(flag!=1) return flag;
    BIGNUM xp;
    BN_rshift1(&xp,a);
    if(BN_is_odd(&xp)==0)
        return 0;
    return BN_is_prime(&xp,5,1);
}
