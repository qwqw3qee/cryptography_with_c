#include <stdio.h>
#include <stdlib.h>
#include "ELGamal.h"


void key_import();
void key_output();
void sign();
void verify();
void sign_text();
void sign_file();
void menu_printf();
void test_base64_encode();
void test_base64_decode();
void menu_select(int casee);




ELGKEY priKey,pubKey;


void key_import()
{
    char ch[10];
    printf("\t--1.导入私钥--------\n");
    printf("\t--2.导入公钥--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(ELG_file2key(&priKey,"private_key.txt")<=0)
            printf("导入私钥失败\n");
        else
            printf("导入私钥成功\n");
        ELG_key_printf(&priKey,10);
        break;
    case '2':
        if(ELG_file2key(&pubKey,"public_key.txt")<=0)
            printf("导入公钥失败\n");
        else
            printf("导入公钥成功\n");
        ELG_key_printf(&pubKey,10);
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
        if(ELG_key2file("private_key.txt",&priKey)<=0)
            printf("导出私钥失败\n");
        else
            printf("导出私钥成功\n");
        ELG_key_printf(&priKey,10);
        break;
    case '2':
        if(ELG_key2file("public_key.txt",&pubKey)<=0)
            printf("导出公钥失败\n");
        else
            printf("导出公钥成功\n");
        ELG_key_printf(&pubKey,10);
        break;
    default:
        printf("输入无效!\n");
    }
}
void sign()
{
    char ch[10];
    printf("\t---请选择要签名的内容----\n");
    printf("\t-----1.文本--------------\n");
    printf("\t-----2.文件--------------\n");
    scanf("%s",ch);
    getchar();
    switch(ch[0])
    {
    case '1':
        sign_text();
        break;
    case '2':
        sign_file();
        break;
    default:
        printf("输入无效\n");
    }
}
void sign_text()
{
    char text[1024000],mi[10240];
    printf("请输入要签名的文本(按Ctrl+Z结束输入):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("正在签名,请稍后...");
    int len;
    ELGSIGN elgSign;
    if(ELG_sign_text(&elgSign,text,i-2,&priKey)<=0)
    {
        printf("签名失败!\n");
        return;
    }
    len=ELG_sign2base64(mi,&elgSign);
    ELG_sign_printf(&elgSign,16);
    printf("\n签名长度:%d(Bytes),内容(base64编码格式):\n%s\n",len,mi);
}
void sign_file()
{
    char text[10240],mi[10240],md5[100];
    printf("请输入要签名的文件路径:\n");
    gets(text);
    if(ELG_getfile_md5(md5,text)!=1)
    {
        printf("获取文件md5失败!\n");
        return;
    }
    printf("正在签名,请稍后...");
    int len;
    ELGSIGN elgSign;
    if(ELG_sign_md5(&elgSign,md5,&priKey)<=0)
    {
        printf("签名失败!\n");
        return;
    }
    len=ELG_sign2base64(mi,&elgSign);
    ELG_sign_printf(&elgSign,16);
    printf("\nmd5:%s\n",md5);
    printf("签名长度:%d(Bytes),内容(base64编码格式):\n%s\n",len,mi);
}

void verify()
{
    char text[10240];
    printf("请输入签名(base64编码格式)(按Ctrl+Z结束输入):\n");
    int i=0,flag;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    ELGSIGN elgSign;
    if(ELG_base642sign(&elgSign,text,i-2)<=0)
    {
        printf("解析签名失败\n");
        return;
    }
    ELG_sign_printf(&elgSign,16);
    char ch[10];
    printf("\t---请选择要验证的内容----\n");
    printf("\t-----1.文本--------------\n");
    printf("\t-----2.文件--------------\n");
    scanf("%s",ch);
    getchar();
    switch(ch[0])
    {
    case '1':
        printf("请输入文本(按Ctrl+Z结束输入):\n");
        i=0;
        while(scanf("%c",&text[i++])!=EOF)
                ;
        flag=ELG_cmp_signature_text(text,i-2,&elgSign);
        if(flag==-1)
        {
            printf("待验证的文本的md5与签名不同!\n");
            return;
        }
        else if(flag==0)
        {
            printf("比对md5时出错!\n");
            return;
        }
        break;
    case '2':
        printf("请输入文件路径:\n");
        gets(text);
        char md5[50];
        if(ELG_getfile_md5(md5,text)!=1)
        {
            printf("获取文件md5失败!\n");
            return;
        }
        printf("md5:%s\n",md5);
        flag=ELG_cmp_signature_md5(md5,&elgSign);
        if(flag==-1)
        {
            printf("待验证的文件的md5与签名不同!\n");
            return;
        }
        else if(flag==0)
        {
            printf("比对md5时出错!\n");
            return;
        }
        break;
    default:
        printf("输入无效\n");
        return;
    }
    printf("正在验证,请稍后...");
    if(pubKey.type!=2)
        flag=ELG_verify(&elgSign,&priKey);
    else
        flag=ELG_verify(&elgSign,&pubKey);
    if(flag==1)
        printf("\n签名验证成功!合法签名!\n");
    else if(flag==-1)
        printf("\n签名验证失败!非法签名!\n");
    else
        printf("\n密钥或签名发生错误!\n");
}

void menu_printf()
{
  printf("\n\t-------菜单---------\n");
    printf("\t--1.密钥生成--------\n");
    printf("\t--2.密钥查看--------\n");
    printf("\t--3.密钥导入--------\n");
    printf("\t--4.密钥导出--------\n");
    printf("\t--5.信息签名--------\n");
    printf("\t--6.签名验证--------\n");
    printf("\t--7.base64编码------\n");
    printf("\t--8.base64解码------\n");
    printf("\t--9.退出------------\n");
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
void menu_select(int casee)
{
    switch(casee)
    {
    case 1:
        ELG_genKey(&priKey,&pubKey);
    case 2:
        ELG_key_printf(&priKey,16);
        ELG_key_printf(&pubKey,16);
        break;
    case 3:
        key_import();
        break;
    case 4:
        key_output();
        break;
    case 5:
        sign();
        break;
    case 6:
        verify();
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
