#include <stdio.h>
#include <stdlib.h>
typedef int Typekey;
typedef int Typeval;

#define MAX_SIZE 13
typedef int (*Hashfunc)(Typekey);

typedef struct HashNode
{
    Typekey key;
    Typeval val;
    struct HashNode *next;
}HashNode;

typedef struct Hashtable
{
    HashNode* data[MAX_SIZE];
    int size;
    Hashfunc func;   
}Hashtable;

int Hashfun(Typekey key)
{
    return key%MAX_SIZE;
}
void Hashinit(Hashtable *hash)
{
    if(hash==NULL)
        return ;
    hash->size=0;
    hash->func=Hashfun;
    int i=0;
    for(i=0;i<MAX_SIZE;i++)
    {
        hash->data[i]=NULL;
    }
}
HashNode* CreateHashNode(Typekey key, Typeval value)
{
    HashNode* new_node=(HashNode*)malloc(sizeof(HashNode));
    new_node->key=key;
    new_node->val=value;
    new_node->next=NULL;
    return new_node;
}
void Hashinsert(Hashtable *hash,Typekey key,Typeval value)
{
    //判断是否大于MAX_SIZE，大于直接返回
    //根据Key值计算要插入的位置
    //判断要插入的元素是否重复，重复直接返回
    //不重复直接头插
    if(hash==NULL)
        return ;
    if(hash->size>=MAX_SIZE)
        return ;
    int offset;
    offset=hash->func(key);
    HashNode* cur=hash->data[offset];
    while(1)
    {
        while(cur!=NULL)
        {
            if(cur->key==key)
                return ;
            cur=cur->next;
        }
        HashNode *newnode=CreateHashNode(key,value);
        newnode->next=hash->data[offset];
        hash->data[offset]=newnode;
        break ;
    }
    hash->size++;
}
int main()
{
    Hashtable hash;
    Hashinit(&hash);
    Hashinsert(&hash,180,180);
    Hashinsert(&hash,750,750);
    Hashinsert(&hash,600,600);
    Hashinsert(&hash,430,430);
    Hashinsert(&hash,541,541);
    Hashinsert(&hash,900,900);
    Hashinsert(&hash,460,460);
    Hashinsert(&hash,443,443);
    printf("%d %d",((&hash)->data[1])->key,((&hash)->data[1])->next->key);
    return 0;
}
