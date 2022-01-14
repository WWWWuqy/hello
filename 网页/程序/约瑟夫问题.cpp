#include<stdio.h> 
#include<stdlib.h>
typedef struct node//节点类型 
{
   int data;//编号 
   int key;//密码值 
   struct node *next;
} ListNode,*LinkList;
/*建立单循环链表*/
LinkList InitList(int n)
{
	ListNode *p,*q,*R;
	int i,a;
	R=(ListNode *)malloc(sizeof(ListNode));//R为头节点
    q=R;
    for (i=1;i<=n;i++)
       {
          p=(ListNode *)malloc(sizeof(ListNode));
          p->data=i;
          scanf("%d",&a);
          p->key=a;
          q->next=p;
          q=p;
    }
    p->next=R->next;//使最后一个结点指向第一个结点，构成一个循环。
    return R;
}
/*从环中删除节点*/
LinkList DelList(int n,int m,LinkList R)
 {
 	int i,j;
    ListNode *p,*q;
    p=R;
    for(i=1;i<=n;i++)//逐个删除结点
       {
          for(j=1;j<=m-1;j++)
              p=p->next;//p指向第k-1个元素
          q=p->next;//q指向第k个元素
          p->next=q->next;//删除q指向的结点，使p结点和q的下一个结点相连
          printf("%d ",q->data);
          m=q->key;//让k等于q结点的密码值
          free(q);
          R=p;//因为R为头结点，并不是链表的第1个元素
       }
       return R;
 }
 int main()
 {
 	LinkList R;
 	int n,a[20],m,i;
 	printf("总人数为：");
	scanf("%d",&n);
	printf("第一次报数上限为：");
	scanf("%d",&m);
	printf("按顺序输入各密码值：");
	R=InitList(n);
	printf("出列顺序为："); 
	R=DelList(n,m,R);
	return 0;
  } 

