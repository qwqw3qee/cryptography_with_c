#include <stdio.h>
#include "RSA.h"

void key_import();
void key_output();
void encrypt();
void decrypt();
void test_base64_encode();
void test_base64_decode();
void menu_printf();
void menu_select(int casee);


RSAKEY priKey,pubKey;


void key_import()
{
    char ch[10];
    printf("\t--1.导入私钥--------\n");
    printf("\t--2.导入公钥--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(RSA_file2key(&priKey,"private_key.txt")<=0)
            printf("导入私钥失败\n");
        else
            printf("导入私钥成功\n");
        RSA_key_printf(&priKey,10);
        break;
    case '2':
        if(RSA_file2key(&pubKey,"public_key.txt")<=0)
            printf("导入公钥失败\n");
        else
            printf("导入公钥成功\n");
        RSA_key_printf(&pubKey,10);
        break;
    default:
        printf("输入无效!\n");
    }
}
void key_output()
{
    char ch[10];
    printf("\t--1.导出私钥--------\n");
    printf("\t--2.导出公钥--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(RSA_key2file("private_key.txt",&priKey)<=0)
            printf("导出私钥失败\n");
        else
            printf("导出私钥成功\n");
        RSA_key_printf(&priKey,10);
        break;
    case '2':
        if(RSA_key2file("public_key.txt",&pubKey)<=0)
            printf("导出公钥失败\n");
        else
            printf("导出公钥成功\n");
        RSA_key_printf(&pubKey,10);
        break;
    default:
        printf("输入无效!\n");
    }
}
void encrypt()
{
    char text[1024000],mi[1024000];
    printf("请输入要加密的文本(按Ctrl+Z结束输入):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("正在加密,请稍后...");
    int len;
    if(priKey.type==1)
        len=RSA_text_encrypt_base64(mi,text,i-2,&priKey);
    else len=RSA_text_encrypt_base64(mi,text,i-2,&pubKey);
    if(len<=0)
    {
        printf("加密失败!\n");
        return;
    }
    printf("\n密文长度:%d(Bytes),内容(base64编码格式):\n%s\n",len,mi);
}
void decrypt()
{
    char text[1024000],yuan[1024000];
    printf("请输入要脱密的文本(base64编码格式)(按Ctrl+Z结束输入):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("正在解密,请稍后...");
    int len=RSA_text_decrypt_base64(yuan,text,i-2,&priKey);
    if(len<=0)
    {
        printf("脱密失败!\n");
        return;
    }
    printf("\n原文长度:%d(Bytes),内容:\n%s\n",len,yuan);
}
void test_base64_encode()
{
    char text[1024000],mi[1024000];
    printf("请输入要编码的文本(按Ctrl+Z结束输入):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("正在编码,请稍后...");
    int len=base64_encode(mi,(unsigned char*)text,i-2);
    if(len<=0)
    {
        printf("编码失败!\n");
        return;
    }
    printf("\n密文长度:%d(Bytes),内容(base64编码格式):\n%s\n",len,mi);
}
void test_base64_decode()
{
    char text[1024000],yuan[1024000];
    printf("请输入要解码的文本(base64编码格式)(按Ctrl+Z结束输入):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("正在解码,请稍后...");
    int len=base64_decode((unsigned char*)yuan,text,i-2);
    if(len<=0)
    {
        printf("解码失败!\n");
        return;
    }
    printf("\n原文长度:%d(Bytes),内容:\n%s\n",len,yuan);
}
void menu_printf()
{
  printf("\n\t-------菜单---------\n");
    printf("\t--1.密钥生成--------\n");
    printf("\t--2.密钥查看--------\n");
    printf("\t--3.密钥导入--------\n");
    printf("\t--4.密钥导出--------\n");
    printf("\t--5.信息加密--------\n");
    printf("\t--6.信息脱密--------\n");
    printf("\t--7.base64编码------\n");
    printf("\t--8.base64解码------\n");
    printf("\t--9.退出------------\n");
}

void menu_select(int casee)
{
    switch(casee)
    {
    case 1:
        RSA_genKey(&priKey,&pubKey);
    case 2:
        RSA_key_printf(&priKey,10);
        RSA_key_printf(&pubKey,10);
        break;
    case 3:
        key_import();
        break;
    case 4:
        key_output();
        break;
    case 5:
        encrypt();
        break;
    case 6:
        decrypt();
        break;
    case 7:
        test_base64_encode();
        break;
    case 8:
        test_base64_decode();
        break;
    default:
        printf("输入无效!\n");
    }
}


int main()
{
    srand(time(NULL));
    memset(&priKey,0,sizeof(priKey));
    memset(&pubKey,0,sizeof(pubKey));
    char ch[10];
    while(1)
    {
        menu_printf();
        printf("请选择:");
        scanf("%s",ch);
        getchar();
        if(ch[0]=='9')
            break;
        menu_select(ch[0]-'0');
    }
    return 0;
}
