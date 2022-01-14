#include<stdio.h>
#define maxsize 20//栈的容量 
int ans=0;//解法的个数
typedef struct
{
    int size[maxsize];
    int top;//栈顶 
}seqstack;

void initstack(seqstack &s)//创建一个空栈 
{
    s.top=0;
    int i;
    for(i=0;i<maxsize;i++)
        s.size[i]=0;
}

void push(seqstack &s,int x)//插入x为新的栈顶元素 
{
    if(s.top+1==maxsize) printf("数组上溢。\n");
    else   
    {
        s.size[s.top++]=x;
    }
}

void pop(seqstack &s)//删除栈顶元素 
{
    if(s.top==-1) printf("数组下溢。\n");
    else  s.top--;
}

void knap(seqstack &s,int num,int w[],int T)//s为栈，num为物体个数，w为各物品体积
{
    int k=0,i=0,j=1;
    do  
    {  
        while(T>0&&k<=num)  //若背包未满且为读到最后一个物体 
        {   
            if(T>=w[k])   
            {    
                push(s,k);//插入k为新的栈顶元素 
                T-=w[k];  //将重量为w[k] 的物体装到背包中 
            }   
            k++;  
        }  
        if(T==0)  //背包已满 
        {
            printf("\n第%d种挑选方法（",j );
            for(i=0;i<s.top;i++)   
            {    
                printf("%d  ",w[s.size[i]]);   
            }   
            j++;   
            printf("）\n");  
        }  
        pop(s);//出栈操作  
        k=s.size[s.top];//k为栈顶元素 
        s.size[s.top]=0; //将栈顶元素删除 
        T+=w[k];  //退回到前一步 
        k++; 
    }while(!(s.top==0&&k==num)); 
    if(j==1) printf("找不到解法"); 
}

int main()
 {
    seqstack s;
    initstack(s);
    int T;//背包体积
    printf("请输入背包体积：");
    scanf("%d",&T);
    int num;//物体个数
    printf("请输入物体个数：");
    scanf("%d",&num);
    int w[maxsize];//背包内物体体积
    printf("请输入背包内各个物体体积：\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&w[i]);
     }
    knap(s,num,w,T);
    return 0;
 }
