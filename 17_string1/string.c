#include <stdio.h>
#include <iostream>
using namespace std;
size_t strlen(const char *str)
{
    //strlen的返回值必须为无符号型
    if(str==NULL)
        return 0;
    size_t n=0;
    while(*str!='\0')
    {
        n++;
        str++;
    }
    return n;
}
char *_strcpy(char *des,const char *sou)
{
    //1.保存des地址
    //2.循环结束条件用des判断
    if(sou==NULL||des==NULL)
        return NULL;
    char *ret=des;
    do
    {
        *des++=*sou++;
    }  
    while(*des!='\0');
    return ret;
}
char *_memcpy(char *dst,const char *src,int len)//len为字符串长度加一
{
    //1.目的地址如果在原地址之间，包括'\0'，从前往后拷贝
    //2.否则正常从后往前
    if(dst==NULL||src==NULL)
        return NULL;
    char *ret=dst;
    if(dst>=src && dst<=src+len-1)
    {
        dst=dst+len-1;
        src=src+len-1;
        while(len--)
        {
            *dst--=*src--;
        }
    }
    else
        while(len--)
        {
            *dst++=*src++;
        }
    return ret;
}
int main()
{
    //const char *s="vdfvabberbq";
    char s[]="hello";
    //size_t l;
    //l=strlen(s);
    //printf("%d\n",l);

    char a[100];
    char *p=a;
    // p= _strcpy(p,s); 这里不能用p指针再接收返回的字符串，因为指针已经指向了字符串末尾的'\0'，又把
    //*(p+11)='\0';    strcpy返回的字符串赋值给p，'\0'被覆盖，字符就没有结束标志，输出随机，如果加上
    //'\0'就能合法输出       

    char *pt;
    pt= _strcpy(s,s+1)//可以 从后往前赋值
    //cout<<pt<<endl;
    //pt=_strcpy(s+1,s);//不可以要考虑内存重叠 从前往后赋值，从最后一个开始
    cout<<pt<<endl;

    return 0;
}
