#include<stdio.h> 
#include<stdlib.h>
typedef struct node//�ڵ����� 
{
   int data;//��� 
   int key;//����ֵ 
   struct node *next;
} ListNode,*LinkList;
/*������ѭ������*/
LinkList InitList(int n)
{
	ListNode *p,*q,*R;
	int i,a;
	R=(ListNode *)malloc(sizeof(ListNode));//RΪͷ�ڵ�
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
    p->next=R->next;//ʹ���һ�����ָ���һ����㣬����һ��ѭ����
    return R;
}
/*�ӻ���ɾ���ڵ�*/
LinkList DelList(int n,int m,LinkList R)
 {
 	int i,j;
    ListNode *p,*q;
    p=R;
    for(i=1;i<=n;i++)//���ɾ�����
       {
          for(j=1;j<=m-1;j++)
              p=p->next;//pָ���k-1��Ԫ��
          q=p->next;//qָ���k��Ԫ��
          p->next=q->next;//ɾ��qָ��Ľ�㣬ʹp����q����һ���������
          printf("%d ",q->data);
          m=q->key;//��k����q��������ֵ
          free(q);
          R=p;//��ΪRΪͷ��㣬����������ĵ�1��Ԫ��
       }
       return R;
 }
 int main()
 {
 	LinkList R;
 	int n,a[20],m,i;
 	printf("������Ϊ��");
	scanf("%d",&n);
	printf("��һ�α�������Ϊ��");
	scanf("%d",&m);
	printf("��˳�����������ֵ��");
	R=InitList(n);
	printf("����˳��Ϊ��"); 
	R=DelList(n,m,R);
	return 0;
  } 

