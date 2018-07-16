#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void swap(int *a,int *b)
{
    int temp=*a;
        *a=*b;
        *b=temp;
}
void bubble_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    int i,j,k;
    for(i=0;i<n-1;i++)//趟数                
    {
      for(j=0;j<n-1;j++)//每趟比较的次数,第一个和第二个比，条件成立,交换                       
      {                   //第二个和第三个比，条件成立交换，依次循环，最大的放在顶上减一  
             if(a[j]>a[j+1])                                                                 
                 swap(&a[j],&a[j+1]);                                                        
      }
      int k;
      for(k=0;k<10;k++)
      {
          printf("%d ",a[k]);
      }
      printf("\n");
    }
}
void Select_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    int i,j,k;
    for(i=0;i<n;i++)//擂主
    {
        for(j=i+1;j<n;j++)//擂主和他后面的每个打，条件成立交换，擂主换人（目前最小） 
        {                 //新擂主继续和后面打，循环                                      
            if(a[i]>a[j])                                                                 
                swap(&a[i],&a[j]);                                                        
      for(k=0;k<10;k++)
      {
          printf("%d ",a[k]);
      }
      printf("\n");
        }                                                                                 
      int k;
      for(k=0;k<10;k++)
      {
          printf("%d ",a[k]);
      }
      printf("\n");
    } 
}
void insert_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    int i,j;
    for(i=1;i<n;i++)//保存元素的前面一直有序，判断保存元素在前面有序元素中的位置
    {               //依次向后移动，插入前面保存的数在挪动后的空位
        int cur=i;
        int val=a[i];
        for(;cur>0;cur--)
        {
            if(val<a[cur-1])
            {
                a[cur]=a[cur-1];
            }
            else
            {
                break;
            }
        }
        a[cur]=val;
      int k;
      for(k=0;k<10;k++)
      {
          printf("%d ",a[k]);
      }
      printf("\n");
    }
}
void Shell_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    int gap;
    gap=n/2;
    int i,j;
    for(;gap>0;gap/=2)//每循环一次，就成2倍缩小步长
    {   
        for(j=gap;j<n;j++) //步长为gap的所有元素，进行插入排序!!!!错的
        {                  //这样只能计算一次步长的(j=gap;j<n;j+=gap)                 
            int cur=j;
            int val=a[cur];
            for(;cur>=gap;cur-=gap)
            {
                if(a[cur-gap]>val)
                {
                    a[cur]=a[cur-gap];
                }   
                else
                {
                    break;
                }
            }
            a[cur]=val;
            int k;
            for(k=0;k<10;k++)
            {
                printf("%d ",a[k]);
            }
            printf("\n");
            printf("%d",gap);
            printf("\n");
        }
         
    }
}
void Merge_array(int *a,int beg,int mid,int end,int *tmp)
{
    int cur1=beg;
    int cur2=mid;
    int i=beg;
    while(cur1<mid && cur2<end)
    {
        if(a[cur1]<a[cur2])
            tmp[i++]=a[cur1++];
        else
            tmp[i++]=a[cur2++];
    }
    while(cur1<mid)
    {
        tmp[i++]=a[cur1++];
    }
    while(cur2<end)
    {
        tmp[i++]=a[cur2++];
    }
    memcpy(a+beg,tmp+beg,sizeof(int)*(end-beg));
}
void _Merge_sort(int *a,int beg,int end,int *tmp)
{
    if((end-beg)<=1)
        return ;
    int mid=beg+(end-beg)/2;
    _Merge_sort(a,beg,mid,tmp);
    _Merge_sort(a,mid,end,tmp);
    Merge_array(a,beg,mid,end,tmp);   
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Merge_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    int *tmp=(int*)malloc(sizeof(int)*10);
    _Merge_sort(a,0,n,tmp);
}

int Partion(int *a,int beg,int end)
{
    //以最后一个数为基准，从前向后找到第一个比他大的数，从后往前找找到第一个比他小的数
    //进行交换，当left和right重合时，交换重合点的数和基准，返回left作为下次递归的end和beg
    int left=beg;
    int right=end-1;
    int tmp=a[right];
    while(left<right)
    {
        while(left<right && a[left]<=tmp)
        {
            left++;
        }
        while(left<right && a[right]>=tmp)
        {
            right--;
        }
        if(left<end)
        swap(&a[left],&a[right]);
    }
    swap(&a[left],&a[end-1]);
    return left;
}
void _Quick_sort(int *a,int beg,int end)
{
    if((end-beg)<=1)
        return ;
    int mid = Partion(a,beg,end);
    _Quick_sort(a,beg,mid);
    _Quick_sort(a,mid+1,end);
}
void Quick_sort(int *a,int n)
{
    if(a==NULL||n<=0)
        return;
    _Quick_sort(a,0,n);
}
    
int main()
{
    int i=0;
    int a[10]={9,5,2,7,6,4,8,1,7,8};
    //int a[10]={10,9,8,7,6,5,4,3,2,1};
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
 //   bubble_sort(a,10);
    //Select_sort(a,10);
  Shell_sort(a,10);
  //  Merge_sort(a,10);
    //insert_sort(a,10);
    
   // Quick_sort(a,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }

}
