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
    printf("\t--1.����˽Կ--------\n");
    printf("\t--2.���빫Կ--------\n");
    scanf("%s",&ch[0]);
    switch(ch[0])
    {
    case '1':
        if(RSA_file2key(&priKey,"private_key.txt")<=0)
            printf("����˽Կʧ��\n");
        else
            printf("����˽Կ�ɹ�\n");
        RSA_key_printf(&priKey,10);
        break;
    case '2':
        if(RSA_file2key(&pubKey,"public_key.txt")<=0)
            printf("���빫Կʧ��\n");
        else
            printf("���빫Կ�ɹ�\n");
        RSA_key_printf(&pubKey,10);
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
        if(RSA_key2file("private_key.txt",&priKey)<=0)
            printf("����˽Կʧ��\n");
        else
            printf("����˽Կ�ɹ�\n");
        RSA_key_printf(&priKey,10);
        break;
    case '2':
        if(RSA_key2file("public_key.txt",&pubKey)<=0)
            printf("������Կʧ��\n");
        else
            printf("������Կ�ɹ�\n");
        RSA_key_printf(&pubKey,10);
        break;
    default:
        printf("������Ч!\n");
    }
}
void encrypt()
{
    char text[1024000],mi[1024000];
    printf("������Ҫ���ܵ��ı�(��Ctrl+Z��������):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("���ڼ���,���Ժ�...");
    int len;
    if(priKey.type==1)
        len=RSA_text_encrypt_base64(mi,text,i-2,&priKey);
    else len=RSA_text_encrypt_base64(mi,text,i-2,&pubKey);
    if(len<=0)
    {
        printf("����ʧ��!\n");
        return;
    }
    printf("\n���ĳ���:%d(Bytes),����(base64�����ʽ):\n%s\n",len,mi);
}
void decrypt()
{
    char text[1024000],yuan[1024000];
    printf("������Ҫ���ܵ��ı�(base64�����ʽ)(��Ctrl+Z��������):\n");
    int i=0;
    while(scanf("%c",&text[i++])!=EOF)
        ;
    printf("���ڽ���,���Ժ�...");
    int len=RSA_text_decrypt_base64(yuan,text,i-2,&priKey);
    if(len<=0)
    {
        printf("����ʧ��!\n");
        return;
    }
    printf("\nԭ�ĳ���:%d(Bytes),����:\n%s\n",len,yuan);
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
void menu_printf()
{
  printf("\n\t-------�˵�---------\n");
    printf("\t--1.��Կ����--------\n");
    printf("\t--2.��Կ�鿴--------\n");
    printf("\t--3.��Կ����--------\n");
    printf("\t--4.��Կ����--------\n");
    printf("\t--5.��Ϣ����--------\n");
    printf("\t--6.��Ϣ����--------\n");
    printf("\t--7.base64����------\n");
    printf("\t--8.base64����------\n");
    printf("\t--9.�˳�------------\n");
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
