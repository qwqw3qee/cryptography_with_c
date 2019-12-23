#include <stdio.h>
#include <stdlib.h>
#include "BASE64.h"
int main()
{
    char input[1000],encode[1000],decode[1000];
    int len1,len2;
    scanf("%s",input);
    len1=base64_encode(encode,(unsigned char*)input,strlen(input));
    len2=base64_decode((unsigned char*)decode,encode,len1);
    printf("±àÂëÎª:\n%s\n½âÂëÎª\n%s\n",encode,decode);
    return 0;
}
