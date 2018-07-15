#include <stdio.h>
//1. 忽略字符串前的空白字符
//2. 字符串所表示数值的正负号
//3. 结束条件，遇到非数字或者字符'\0'结束
//4. 考虑溢出，分别与int值所能表示的最大(0x7fffffff)和最小值(0x8000000)进行比较
//5. 考虑异常输入情况下
int atoi(const char *str)
{
    int flag=1;
    long long result=0; //这里要用long long 如果用int，超出int的取值范围
    if(str==NULL)       //result就会在int的范围内显示为负数，也在合法区间中，无法return 0;
        return 0;
    while(*str==' ')
        str++;
    if(*str=='-')
    {
        flag=-1;
        str++;
    }
    else if(*str=='+')
    {
        str++;
    }
    while(*str<='9' && *str>='0')
    {
        result=result*10+*str-'0';
        if(flag==1)
        {
            if(result>((int)0x7fffffff))
            return 0;
        }
        else if(flag==-1 && -result<((int)0x80000000))
        {
            return 0;
        }
        str++;
    }
    return (int)flag*result;
    
}
int main()
{
    char *str1="8777777777777777777767";
    printf("%d ",atoi(str1));
     str1="-\\cs67";
    printf("%d ",atoi(str1));
     str1="67";
    printf("%d ",atoi(str1));
     str1="-dv67";
    printf("%d ",atoi(str1));
     str1="-66666666666666666666667 ";
    printf("%d ",atoi(str1));
    return 0;
}
