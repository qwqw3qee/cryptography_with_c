#include "BIGNUM_DEC.h"

const char alphalist[16]="0123456789ABCDEF";
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
void BN_clear(pBIGNUM a)
{
    if(a==NULL) return;
    memset(a->num,0,sizeof(a->num));
    a->length = 1;
    a->sign = 0;
}

int BN_copy(pBIGNUM a, const BIGNUM* b)
{
    if(a==NULL || b==NULL) return 0;

    if(memcpy(a->num,b->num,sizeof(b->num))==NULL) return 0;
    a->length = b->length;
    a->sign = b->sign;
    return 1;
}
void BN_swap(pBIGNUM a,pBIGNUM b)
{
    if(a==NULL||b==NULL) return;
    BIGNUM c = *a;
    *a = *b;
    *b = c;
}

void BN_printf(const BIGNUM* a,int flag)
{
    if(a->length<=0)
    {
        puts("NULL");
        return;
    }
    char buffer[NUMSIZE*10];
    switch(flag)
    {
        case 2:
            BN_bn2dec(buffer,a);
            break;
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
                BN_bn2dec(buffer,a);
    }
    printf("%s",buffer);
    //putchar('\n');
}
int BN_bn2bin(char a[],const BIGNUM* b)
{
    if(b->length==0)
        return 0;
    int len=0;
    BIGNUM tb=*b;
    while(BN_is_zero(&tb)==0)
    {
        if(BN_is_odd(&tb))
            a[len++]='1';
        else
            a[len++]='0';
        BN_div_word(&tb,2);
    }
    if(b->sign) a[len++]='-';
    a[len]='\0';
    int i;
    char j;
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
    if(b->length==0) return 0;
    int len=0,temp;
    BIGNUM tb=*b;
    while(BN_is_zero(&tb)==0)
    {
        temp=BN_div_word(&tb,16);
        if(temp<0) return 0;
        a[len++]=alphalist[temp];
    }
    a[len++]='x';
    a[len++]='0';
    if(b->sign) a[len++]='-';
    a[len]='\0';
    int i;
    char j;
    for(i=0;i<len/2;i++)
    {
        j=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=j;
    }
    return 1;
}
int BN_bn2any(char a[],const BIGNUM* b,int base)
{
    if(b->length==0) return 0;
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
    if(b->sign) a[len++]='-';
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
    if(a==NULL||b==NULL) return 0;
    if(b->length<=0) return 0;
    int i=0,j=0;
    if(b->sign) a[j++]='-';
    for(i = b->length-1; i >= 0; i--)
        a[j++]=b->num[i]+'0';
    a[j]='\0';
    return 1;
}
int BN_dec2bn(pBIGNUM a,const char b[])
{
    if(a==NULL||b==NULL) return 0;
    BN_clear(a);
    int i = 0,j = strlen(b)-1;
    if(j<0||j>NUMSIZE-1) return 0;
    a->sign=(b[0]=='-');
    while(j>=a->sign)
    {
        if(b[j]>='0'&&b[j]<='9')
            a->num[i++]=b[j--]-'0';
        else
        {
            BN_clear(a);
            return 0;
        }
    }
    a->length=i;
    return 1;
}
int hex2val(char ch)
{
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='a'&&ch<='f') return ch-'a'+10;
    if(ch>='A'&&ch<='F') return ch-'A'+10;
    return -1;
}
int BN_hex2bn(pBIGNUM a,const char b[])
{
    int i,len=strlen(b),temp,sign;
    BN_zero(a);
    sign=(b[0]=='-');
    i=sign;
    if(b[sign]=='0'&&b[sign+1]=='x')
        i+=2;
    for(; i<len; ++i)
    {
        BN_mul_word(a,16);
        temp = hex2val(b[i]);
        if(temp<0)
        {
            BN_zero(a);
            return 0;
        }
        BN_add_word(a,temp);
    }
    a->sign=sign;
    return 1;
}
int BN_any2bn(pBIGNUM a,const char b[],int base)
{
    int i,len=strlen(b),temp,sign;
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
    sign=(b[0]=='-');
    for(i=sign; i<len; ++i)
    {
        BN_mul_word(a,base);
        temp = hex2val(b[i]);
        if(temp<0||temp>=base)
        {
            BN_zero(a);
            return 0;
        }
        BN_add_word(a,temp);
    }
    a->sign=sign;
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
    if(a==NULL) return 0;
    a->sign=0;
    if(w==0)
        return BN_zero(a);
    if(w<0)
    {
        a->sign=1;
        w=-w;
    }
    a->length=0;
    while(w)
    {
        a->num[a->length++]=w%10;
        w /= 10;
    }
    return 1;
}
ll BN_get_word(const BIGNUM* a)
{
    if(a==NULL) return 0;
    if(a->length>19) return 0;
    int i;
    ll ans=0;
    for(i=a->length-1; i>=0; --i)
    {
        ans*=10;
        ans+=a->num[i];
    }
    if(a->sign) ans=-ans;
    return ans;
}
int BN_one(pBIGNUM a)
{
    if(a==NULL) return 0;
    a->num[0] = 1;
    a->length = 1;
    a->sign = 0;
    return 1;
}
int BN_zero(pBIGNUM a)
{
    if(a==NULL) return 0;
    a->num[0] = 0;
    a->length = 1;
    a->sign = 0;
    return 1;
}

int BN_is_zero(const BIGNUM* a)
{
    return (a->length==1&&a->num[0]==0);
}
int BN_is_one(const BIGNUM* a)
{
    return (a->length==1&&a->num[0]==1&&a->sign==0);
}
int BN_is_word(const BIGNUM* a,ll w)
{
    if(a==NULL) return 0;
    int w_sign=0;
    if(w<0)
    {
        w_sign=1;
        w=-w;
    }
    if(w_sign!=a->sign) return 0;
    int i=0;
    while(w)
    {
        if(i>=a->length) return 0;
        if(a->num[i]!=w%10) return 0;
        w /= 10;
        ++i;
    }
    if(i<a->length) return 0;
    return 1;
}
int BN_is_odd(const BIGNUM* a)
{
    if(a==NULL) return 0;
    if(a->length<=0) return 0;
    return a->num[0]%2;
}

int BN_trim(pBIGNUM a)
{
    int i=a->length-1;
    while(i>0)
    {
        if(a->num[i]==0) --i;
        else break;
    }
    a->length=i+1;
    return 1;
}
int BN_ucmp(const BIGNUM* a,const BIGNUM* b)
{
    if(a->length!=b->length) return a->length<b->length?-1:1;
    int i;
    for(i = a->length-1; i >= 0; --i)//之前忘记减1了，居然一直没有发现……
    {
        if(a->num[i]!=b->num[i]) return a->num[i]<b->num[i]?-1:1;
    }
    return 0;
}
int BN_cmp(const BIGNUM* a,const BIGNUM* b)
{
    if(a->sign!=b->sign) return a->sign<b->sign?1:-1;
    return a->sign?-BN_ucmp(a,b):BN_ucmp(a,b);
}

int BN_uadd(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{

    if(a->length < b->length)
    {
        const BIGNUM* p = a;
        a = b;
        b = p;
    }
    int i,carry=0;
    BIGNUM ta=*a,tb=*b;
    for(i=0;i<tb.length;i++)
    {
        res->num[i]=ta.num[i]+tb.num[i]+carry;
        carry=res->num[i]/10;
        res->num[i]=res->num[i]%10;
    }
    for(;i<ta.length;i++)
    {
        res->num[i]=ta.num[i]+carry;
        carry=res->num[i]/10;
        res->num[i]=res->num[i]%10;
    }
    if(carry)
    {
        if(i+1>NUMSIZE)
        {
            BN_clear(res);
            return 0;
        }
        res->num[i++]=carry;
    }
    res->length=i;
    return 1;
}

int BN_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||a==NULL||b==NULL) return 0;
    BIGNUM ta=*a,tb=*b;
    BN_clear(res);
    if(ta.sign==tb.sign)
    {
        res->sign=ta.sign;
        return BN_uadd(res,&ta,&tb);
    }
    if(ta.sign)
    {
        res->sign=tb.sign;
        return BN_usub(res,&tb,&ta);
    }
    if(tb.sign)
    {
        res->sign=ta.sign;
        return BN_usub(res,&ta,&tb);
    }
    return 0;
}
int BN_usub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(BN_ucmp(a,b)==-1)
    {
        const BIGNUM* p = a;
        a = b;
        b = p;
        res->sign=!res->sign;
    }
    int i,borrow=0;
    BIGNUM ta=*a,tb=*b;
    for(i=0; i<tb.length; ++i)
    {
        res->num[i]=ta.num[i]-tb.num[i]-borrow;
        if(res->num[i]<0)
        {
            res->num[i]=res->num[i]+10;
            borrow=1;
        }
        else
            borrow=0;
    }
    for(; i<ta.length; ++i)
    {
        res->num[i]=ta.num[i]-borrow;
        if(res->num[i]<0)
        {
            res->num[i]=res->num[i]+10;
            borrow=1;
        }
        else
            borrow=0;
    }
    res->length=ta.length;
    BN_trim(res);
    return 1;
}
int BN_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||a==NULL||b==NULL) return 0;
    BIGNUM ta=*a,tb=*b;
    BN_clear(res);
    if(ta.sign==tb.sign)
    {
        res->sign=ta.sign;
        return BN_usub(res,&ta,&tb);
    }
    res->sign=ta.sign;
    return BN_uadd(res,&ta,&tb);
}
int BN_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||a==NULL||b==NULL) return 0;
    if(a->length+b->length>NUMSIZE) return 0;
    if(BN_is_zero(a)||BN_is_zero(b))
    {
        BN_zero(res);
        return 1;
    }
    int carry,temp;
    int i,j,pos;
    BIGNUM ta=*a,tb=*b;
    BN_clear(res);
    for(i=0; i<tb.length; ++i)
    {
        carry=0;
        for(j=0; j<ta.length; ++j)
        {
            temp = tb.num[i]*ta.num[j]+carry;
            carry = temp/10;
            temp = temp%10;
            pos = i+j;
            res->num[pos] = res->num[pos]+temp;
            carry = carry + res->num[pos]/10;
            res->num[pos] = res->num[pos]%10;
        }
        if(carry>0)
        {
            res->num[i+j] = carry;
            res->length = i+j+1;
        }
        else
            res->length = i+j;
    }
    res->sign = (ta.sign!=tb.sign);
    return 1;
}
int BN_sqr(pBIGNUM res,const BIGNUM* a)
{
    if(res==NULL||a==NULL) return 0;
    if(a->length+a->length>NUMSIZE) return 0;
    if(BN_is_zero(a))
    {
        BN_zero(res);
        return 1;
    }
    int carry,temp;
    BIGNUM ta=*a;
    BN_clear(res);
    int i,j,pos;
    for(i=0; i<ta.length; ++i)
    {
        carry=0;
        for(j=0; j<ta.length; ++j)
        {
            temp = ta.num[i]*ta.num[j]+carry;
            carry = temp/10;
            temp = temp%10;
            pos = i+j;
            res->num[pos] = res->num[pos]+temp;
            carry = carry + res->num[pos]/10;
            res->num[pos] = res->num[pos]%10;
        }
        if(carry>0)
        {
            res->num[i+j] = carry;
            res->length = i+j+1;
        }
        else
            res->length = i+j;
    }
    res->sign = 0;
    return 1;
}
int BN_div(pBIGNUM res,pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||rem==NULL||a==NULL||b==NULL) return 0;
    if(BN_is_zero(b)) return 0;
    BIGNUM ta=*a,tb=*b;
    BN_clear(res);
    BN_clear(rem);
    int ccmp=BN_ucmp(&ta,&tb);
    if(ccmp==0)
    {
        BN_one(res);
        BN_zero(rem);
        res->sign=(ta.sign!=tb.sign);
        return 1;
    }
    if(ccmp<0)
    {
        BN_zero(res);
        BN_copy(rem,&ta);
        return 1;
    }
    int i,j,k,m=0;//k试商 m商位数
    for(i=ta.length-1; i>=0; --i)
    {
        rem->length=tb.length+1;
        for(j=tb.length; j>0; --j)
            rem->num[j]=rem->num[j-1];
        rem->num[0]=ta.num[i];
        BN_trim(rem);
        k=0;
        while(BN_ucmp(rem,&tb)>=0)
        {
            BN_usub(rem,rem,b);
            ++k;
        }
        res->num[m++]=k;
    }
    res->length=m;
    for(i=0;i<m/2;i++)
    {
        j=res->num[i];
        res->num[i]=res->num[m-1-i];
        res->num[m-1-i]=j;
    }
    res->sign=(a->sign!=b->sign);
    rem->sign=a->sign;
    BN_trim(res);
    return 1;
}
int BN_mod(pBIGNUM rem,const BIGNUM* a,const BIGNUM* b)
{
    if(rem==NULL||a==NULL||b==NULL) return 0;
    if(BN_is_zero(b)) return 0;
    BIGNUM ta=*a,tb=*b;
    BN_clear(rem);
    int ccmp=BN_ucmp(&ta,&tb);
    if(ccmp==0)
    {
        BN_zero(rem);
        return 1;
    }
    if(ccmp<0)
    {
        BN_copy(rem,&ta);
        return 1;
    }
    int i,j;
    for(i=ta.length-1; i>=0; --i)
    {
        rem->length=tb.length+1;
        for(j=tb.length; j>0; --j)
            rem->num[j]=rem->num[j-1];
        rem->num[0]=ta.num[i];
        BN_trim(rem);
        while(BN_ucmp(rem,&tb)>=0)
            BN_usub(rem,rem,b);
    }
    return 1;
}
//r = ( (a % m) + m) % m
int BN_nnmod(pBIGNUM res,const BIGNUM* a,const BIGNUM* m)
{
    if(res==NULL||a==NULL||m==NULL) return 0;
    BIGNUM ta=*a,tm=*m;
    BN_mod(res,&ta,&tm);
    if(res->sign==0) return 1;
    if(BN_add(res,res,&tm)==0)
    {
        BN_clear(res);
        return 0;
    }
    return 1;
}
int BN_mod_add(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    if(res==NULL||a==NULL||b==NULL||m==NULL) return 0;
    BIGNUM ta=*b,tb=*a,tm=*m;
    //BN_mod(&ta,&ta,&tm);
    //BN_mod(&tb,&tb,&tm);
    if(BN_add(res,&ta,&tb)==0)
    {
        BN_clear(res);
        return 0;
    }
    BN_nnmod(res,res,&tm);
    return 1;
}
int BN_mod_sub(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    if(res==NULL||a==NULL||b==NULL||m==NULL) return 0;
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_sub(res,&ta,&tb);
    BN_nnmod(res,res,&tm);
    return 1;
}

int BN_mod_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    if(res==NULL||a==NULL||b==NULL||m==NULL) return 0;
    BIGNUM tm=*m,ta=*a,tb=*b;
    BN_mod(&ta,&ta,&tm);
    BN_mod(&tb,&tb,&tm);
    if(BN_mul(res,&ta,&tb)==0) return 0;
    return BN_nnmod(res,res,&tm);
}
/*
//快速加，慢
int BN_mod_mul(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    if(res==NULL||a==NULL||b==NULL||m==NULL) return 0;
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_mod(&ta,&ta,&tm);
    BN_mod(&tb,&tb,&tm);
    if(BN_mul(res,&ta,&tb)==0)
    {
        BN_clear(res);
        return 0;
    }
    BN_nnmod(res,res,&tm);
    return 1;
}*/
int BN_mod_sqr(pBIGNUM res,const BIGNUM* a,const BIGNUM* m)
{
     return BN_mod_mul(res,a,a,m);
}
int BN_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||a==NULL||b==NULL) return 0;
    if(b->sign) return 0;
    BIGNUM ta=*a,tb=*b;
    BN_one(res);
    while(BN_is_zero(&tb)==0)
    {
        if(BN_is_odd(&tb))
        {
            if(BN_mul(res,res,&ta)==0)
            {
                BN_clear(res);
                return 0;
            }
        }
        if(BN_sqr(&ta,&ta)==0)
        {
            BN_clear(res);
            return 0;
        }
        BN_div_word(&tb,2);
    }
    return 1;
}
int BN_mod_exp(pBIGNUM res,const BIGNUM* a,const BIGNUM* b,const BIGNUM* m)
{
    if(res==NULL||a==NULL||b==NULL||m==NULL) return 0;
    BIGNUM ta=*a,tb=*b,tm=*m;
    BN_nnmod(&ta,&ta,&tm);
    BN_nnmod(&tb,&tb,&tm);
    BN_one(res);
    while(BN_is_zero(&tb)==0)
    {
        if(BN_is_odd(&tb))
        {
            if(BN_mod_mul(res,res,&ta,&tm)==0)
            {
                BN_clear(res);
                return 0;
            }
        }
        if(BN_mod_sqr(&ta,&ta,&tm)==0)
        {
            BN_clear(res);
            return 0;
        }
        BN_div_word(&tb,2);
    }
    return 1;
}
int BN_gcd(pBIGNUM res,const BIGNUM* a,const BIGNUM* b)
{
    if(res==NULL||a==NULL||b==NULL) return 0;
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
    if(a==NULL) return 0;
    BIGNUM b;
    BN_set_word(&b,w);
    return BN_add(a,a,&b);
}
int BN_sub_word(pBIGNUM a,ll w)
{
    if(a==NULL) return 0;
    BIGNUM b;
    BN_set_word(&b,w);
    return BN_sub(a,a,&b);
}
int BN_mul_word(pBIGNUM a,ll w)
{
    if(a==NULL) return 0;
    int w_sign=0;
    if(w<0)
    {
        w_sign=1;
        w=-w;
    }
    int i;
    ll carry=0;
    for(i=0; i<a->length; ++i)
    {
        carry=a->num[i]*w+carry;
        a->num[i]=carry%10;
        carry /= 10;
    }
    while(carry)
    {
        if(a->length>NUMSIZE)
        {
            BN_clear(a);
            return 0;
        }
        a->num[a->length++]=carry%10;
        carry /= 10;
    }
    a->sign=(a->sign!=w_sign);
    return 1;
}
ll BN_div_word(pBIGNUM a,ll w)
{
    if(a==NULL) return 0;
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
    int i,j,ok=0;
    ll rem=0;
    BIGNUM ans;
    BN_clear(&ans);
    for(i=a->length-1; i>=0; --i)
    {
        rem=(rem*10+a->num[i]);
        if(rem>=w)
        {
            ok=1;
            ans.num[ans.length++]=(rem/w);
            rem%=w;
        }
        else if(ok==1)  ans.num[ans.length++]=0;
    }
    if(BN_is_zero(&ans))
    {
        rem=BN_get_word(a);
        BN_zero(a);
        return rem;
    }
    for(i=0;i<ans.length/2;i++)
    {
        j=ans.num[i];
        ans.num[i]=ans.num[ans.length-1-i];
        ans.num[ans.length-1-i]=j;
    }
    ans.sign=(a->sign!=w_sign);
    BN_trim(&ans);
    if(a->sign) rem=-rem;
    *a=ans;
    return rem;

}
ll BN_mod_word(const BIGNUM* a,ll w)
{
    if(a==NULL) return 0;
    if(w==0) return 0;
    ll s=0;
    int i=0;
    for(i=a->length-1; i>=0; --i)
        s = ((s*10)%w+a->num[i])%w;
    if(a->sign) s=-s;
    return s;
}
int BN_extgcd(const BIGNUM* a,const BIGNUM* b,pBIGNUM d,pBIGNUM x,pBIGNUM y)
{
    if(a==NULL||b==NULL||d==NULL||x==NULL||y==NULL) return 0;
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
    if(res==NULL||a==NULL||m==NULL) return 0;
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
int get_random(char a[],int len) //len:十六进制位数
{
    int leni = len/2+1;
    int i;
    for(i=0; i<leni; ++i)
        sprintf(a+2*i,"%02x",random(0x00,0xff));
    a[len]='\0';
    return 1;
}

int BN_rand(pBIGNUM rnd,int bits,int top,int bottom)
{
    if(BITS10(bits) > NUMSIZE ||BITS10(bits)<=0) return 0;
    BN_zero(rnd);
    char temp[NUMSIZE*10];
    if(get_random(temp,bits/4)!=1) return 0;
    char sign=hex2val(temp[0]);
    switch(top)
    {
    case -1:
        if(sign>7) temp[0]=random(0,7)+'0';
        break;
    case 0:
        if(sign<8) temp[0]=alphalist[random(8,15)];
        break;
    case 1:
        if(sign<12) temp[0]=alphalist[random(12,15)];
        break;
    }
    if(BN_hex2bn(rnd,temp)!=1) return 0;
    if(bottom)
    {
        if(BN_is_odd(rnd)==0)
            BN_add_word(rnd,1);
    }
    return 1;
}

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

int BN_is_prime(const BIGNUM* n,int checks,int do_trial_division)//do_trial_division为真时先尝试除以小素数
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
    int i;
    BIGNUM t=*n,a; //n-1=(2^s)*t
    BN_sub_word(&t,1);
    while(!BN_is_odd(&t))
    {
        BN_div_word(&t,2);
        ++s;
    }
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
                BN_rand(&a,BITS2(n->length),-1,1);
                BN_nnmod(&a,&a,n);
            }while(BN_cmp(&a,n)>=0||BN_is_zero(&a));
        }
        //BN_printf(&a,10);
        //printf("\n");
        if(check(&a,s,&t,n)) return 0;
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
int isPrime(ll n)
{
    ll i;
    for(i = 2; i*i<=n; ++i)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
*/
int BN_is_prime_slower(const BIGNUM* n,int checks)
{
    BIGNUM two;
    BN_set_word(&two,2);
    int tmp = BN_cmp(n,&two);
    if(tmp==-1) return 0;
    else if(tmp==0) return 1;
    if(BN_is_odd(n)==0) return 0;
    BIGNUM t=*n,ans,a; //n-1=(2^s)*t
    BN_sub_word(&t,1);
    int i;
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
                BN_rand(&a,BITS2(n->length),-1,1);
                BN_nnmod(&a,&a,n);
            }while(BN_cmp(&a,n)>=0||BN_is_zero(&a));
        }
        BN_mod_exp(&ans,&a,&t,n);
        //BN_printf(&a,10);
        //printf("\n");
        if(BN_is_one(&ans)==0)
            return 0;
    }
    return 1;
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
            BIGNUM xp=rnd;
            BN_div_word(&xp,2);
            if((flag=BN_is_prime(&xp,5,1))==0)
                BN_add_word(&rnd,2);
        }
        if(flag==-1) return 0;
       // cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    *ret = rnd;
    //printf("共计算了%d次\n",cnt);
    return 1;
}
*/
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
        if(safe&&flag==1)
            flag=BN_is_safe_prime(ret);
        //cnt++;
        //printf("正在计算%d次\n",cnt);
    }while(flag!=1);
    //printf("共计算了%d次\n",cnt);
    return 1;
}*/
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
                *ret=tmp;
                BN_mul_word(ret,2);
                BN_add_word(ret,1);
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
        if(start->sign)
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
    BIGNUM xp=*a;
    BN_div_word(&xp,2);
    if(BN_is_odd(&xp)==0)
        return 0;
    return BN_is_prime(&xp,5,1);
}
