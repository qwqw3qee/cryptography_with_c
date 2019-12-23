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
    printf("\t--1.����˽Կ--------\n");
    printf("\t--2.���빫Կ--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(ELG_file2key(&priKey,"private_key.txt")<=0)
            printf("����˽Կʧ��\n");
        else
            printf("����˽Կ�ɹ�\n");
        ELG_key_printf(&priKey,10);
        break;
    case '2':
        if(ELG_file2key(&pubKey,"public_key.txt")<=0)
            printf("���빫Կʧ��\n");
        else
            printf("���빫Կ�ɹ�\n");
        ELG_key_printf(&pubKey,10);
        break;
    default:
        printf("������Ч!\n");
    }
}
void key_output()
{
    char ch[10];
    printf("\t--1.����˽Կ--------\n");
    printf("\t--2.������Կ--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(ELG_key2file("private_key.txt",&priKey)<=0)
            printf("����˽Կʧ��\n");
        else
            printf("����˽Կ�ɹ�\n");
        ELG_key_printf(&priKey,10);
        break;
    case '2':
        if(ELG_key2file("public_key.txt",&pubKey)<=0)
            printf("������Կʧ��\n");
        else
            printf("������Կ�ɹ�\n");
        ELG_key_printf(&pubKey,10);
        break;
    default:
        printf("������Ч!\n");
    }
}
void sign()
{
    char ch[10];
    printf("\t---��ѡ��Ҫǩ��������----\n");
    printf("\t-----1.�ı�--------------\n");
    printf("\t-----2.�ļ�--------------\n");
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
        printf("������Ч\n");
    }
}
void sign_text()
{
    char text[1024000],mi[10240];
    printf("������Ҫǩ�����ı�(��Ctrl+Z��������):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("����ǩ��,���Ժ�...");
    int len;
    ELGSIGN elgSign;
    if(ELG_sign_text(&elgSign,text,i-2,&priKey)<=0)
    {
        printf("ǩ��ʧ��!\n");
        return;
    }
    len=ELG_sign2base64(mi,&elgSign);
    ELG_sign_printf(&elgSign,16);
    printf("\nǩ������:%d(Bytes),����(base64�����ʽ):\n%s\n",len,mi);
}
void sign_file()
{
    char text[10240],mi[10240],md5[100];
    printf("������Ҫǩ�����ļ�·��:\n");
    gets(text);
    if(ELG_getfile_md5(md5,text)!=1)
    {
        printf("��ȡ�ļ�md5ʧ��!\n");
        return;
    }
    printf("����ǩ��,���Ժ�...");
    int len;
    ELGSIGN elgSign;
    if(ELG_sign_md5(&elgSign,md5,&priKey)<=0)
    {
        printf("ǩ��ʧ��!\n");
        return;
    }
    len=ELG_sign2base64(mi,&elgSign);
    ELG_sign_printf(&elgSign,16);
    printf("\nmd5:%s\n",md5);
    printf("ǩ������:%d(Bytes),����(base64�����ʽ):\n%s\n",len,mi);
}

void verify()
{
    char text[10240];
    printf("������ǩ��(base64�����ʽ)(��Ctrl+Z��������):\n");
    int i=0,flag;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    ELGSIGN elgSign;
    if(ELG_base642sign(&elgSign,text,i-2)<=0)
    {
        printf("����ǩ��ʧ��\n");
        return;
    }
    ELG_sign_printf(&elgSign,16);
    char ch[10];
    printf("\t---��ѡ��Ҫ��֤������----\n");
    printf("\t-----1.�ı�--------------\n");
    printf("\t-----2.�ļ�--------------\n");
    scanf("%s",ch);
    getchar();
    switch(ch[0])
    {
    case '1':
        printf("�������ı�(��Ctrl+Z��������):\n");
        i=0;
        while(scanf("%c",&text[i++])!=EOF)
                ;
        flag=ELG_cmp_signature_text(text,i-2,&elgSign);
        if(flag==-1)
        {
            printf("����֤���ı���md5��ǩ����ͬ!\n");
            return;
        }
        else if(flag==0)
        {
            printf("�ȶ�md5ʱ����!\n");
            return;
        }
        break;
    case '2':
        printf("�������ļ�·��:\n");
        gets(text);
        char md5[50];
        if(ELG_getfile_md5(md5,text)!=1)
        {
            printf("��ȡ�ļ�md5ʧ��!\n");
            return;
        }
        printf("md5:%s\n",md5);
        flag=ELG_cmp_signature_md5(md5,&elgSign);
        if(flag==-1)
        {
            printf("����֤���ļ���md5��ǩ����ͬ!\n");
            return;
        }
        else if(flag==0)
        {
            printf("�ȶ�md5ʱ����!\n");
            return;
        }
        break;
    default:
        printf("������Ч\n");
        return;
    }
    printf("������֤,���Ժ�...");
    if(pubKey.type!=2)
        flag=ELG_verify(&elgSign,&priKey);
    else
        flag=ELG_verify(&elgSign,&pubKey);
    if(flag==1)
        printf("\nǩ����֤�ɹ�!�Ϸ�ǩ��!\n");
    else if(flag==-1)
        printf("\nǩ����֤ʧ��!�Ƿ�ǩ��!\n");
    else
        printf("\n��Կ��ǩ����������!\n");
}

void menu_printf()
{
  printf("\n\t-------�˵�---------\n");
    printf("\t--1.��Կ����--------\n");
    printf("\t--2.��Կ�鿴--------\n");
    printf("\t--3.��Կ����--------\n");
    printf("\t--4.��Կ����--------\n");
    printf("\t--5.��Ϣǩ��--------\n");
    printf("\t--6.ǩ����֤--------\n");
    printf("\t--7.base64����------\n");
    printf("\t--8.base64����------\n");
    printf("\t--9.�˳�------------\n");
}
void test_base64_encode()
{
    char text[1024000],mi[1024000];
    printf("������Ҫ������ı�(��Ctrl+Z��������):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("���ڱ���,���Ժ�...");
    int len=base64_encode(mi,(unsigned char*)text,i-2);
    if(len<=0)
    {
        printf("����ʧ��!\n");
        return;
    }
    printf("\n���ĳ���:%d(Bytes),����(base64�����ʽ):\n%s\n",len,mi);
}
void test_base64_decode()
{
    char text[1024000],yuan[1024000];
    printf("������Ҫ������ı�(base64�����ʽ)(��Ctrl+Z��������):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("���ڽ���,���Ժ�...");
    int len=base64_decode((unsigned char*)yuan,text,i-2);
    if(len<=0)
    {
        printf("����ʧ��!\n");
        return;
    }
    printf("\nԭ�ĳ���:%d(Bytes),����:\n%s\n",len,yuan);
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
        printf("������Ч!\n");
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
        printf("��ѡ��:");
        scanf("%s",ch);
        getchar();
        if(ch[0]=='9')
            break;
        menu_select(ch[0]-'0');
    }
    return 0;
}
