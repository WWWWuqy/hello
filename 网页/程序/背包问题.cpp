#include<stdio.h>
#define maxsize 20//ջ������ 
int ans=0;//�ⷨ�ĸ���
typedef struct
{
    int size[maxsize];
    int top;//ջ�� 
}seqstack;

void initstack(seqstack &s)//����һ����ջ 
{
    s.top=0;
    int i;
    for(i=0;i<maxsize;i++)
        s.size[i]=0;
}

void push(seqstack &s,int x)//����xΪ�µ�ջ��Ԫ�� 
{
    if(s.top+1==maxsize) printf("�������硣\n");
    else   
    {
        s.size[s.top++]=x;
    }
}

void pop(seqstack &s)//ɾ��ջ��Ԫ�� 
{
    if(s.top==-1) printf("�������硣\n");
    else  s.top--;
}

void knap(seqstack &s,int num,int w[],int T)//sΪջ��numΪ���������wΪ����Ʒ���
{
    int k=0,i=0,j=1;
    do  
    {  
        while(T>0&&k<=num)  //������δ����Ϊ�������һ������ 
        {   
            if(T>=w[k])   
            {    
                push(s,k);//����kΪ�µ�ջ��Ԫ�� 
                T-=w[k];  //������Ϊw[k] ������װ�������� 
            }   
            k++;  
        }  
        if(T==0)  //�������� 
        {
            printf("\n��%d����ѡ������",j );
            for(i=0;i<s.top;i++)   
            {    
                printf("%d  ",w[s.size[i]]);   
            }   
            j++;   
            printf("��\n");  
        }  
        pop(s);//��ջ����  
        k=s.size[s.top];//kΪջ��Ԫ�� 
        s.size[s.top]=0; //��ջ��Ԫ��ɾ�� 
        T+=w[k];  //�˻ص�ǰһ�� 
        k++; 
    }while(!(s.top==0&&k==num)); 
    if(j==1) printf("�Ҳ����ⷨ"); 
}

int main()
 {
    seqstack s;
    initstack(s);
    int T;//�������
    printf("�����뱳�������");
    scanf("%d",&T);
    int num;//�������
    printf("���������������");
    scanf("%d",&num);
    int w[maxsize];//�������������
    printf("�����뱳���ڸ������������\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&w[i]);
     }
    knap(s,num,w,T);
    return 0;
 }
