#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int MAXK=100+10;  
const int MAXN=16000+10;  
struct Zone  
{  
    int index;//���  
    int N;//��Ҫ������  
    int Q;//���������ķ�����  
}zone[MAXK];  
struct Stu  
{  
    int index;//���  
    int P;//ˮƽ  
    int w;//����  
}stu[MAXN];  
int p[MAXN];  
bool cmp1(Zone a,Zone b)//����Q�Ӵ�С����  
{  
    return a.Q>b.Q;  
}  
bool cmp2(Stu a,Stu b)//����w�Ӵ�С����  
{  
    return a.w>b.w;  
}  
int main()  
{  
    int k;  
    int i,j;  
    int num=0;  
    scanf("%d",&k);  
       
    for(i=0;i<k;i++)  
	{  
	    zone[i].index=i+1;  
	    scanf("%d",&zone[i].N);  
	    num+=zone[i].N;  
	}  
    for(i=0;i<k;i++)  
        scanf("%d",&zone[i].Q);  
    sort(zone,zone+k,cmp1);  
    for(i=0;i<num;i++)  
	{  
	    stu[i].index=i+1;  
	    scanf("%d",&stu[i].P);  
	}  
    for(i=0;i<num;i++)  
        scanf("%d",&stu[i].w);  
    sort(stu,stu+num,cmp2);  
    memset(p,-1,sizeof(p));  
    for(i=0;i<num;i++)//��һ���ȷ���ɼ��ﵽ�˵�  
	{  
	    for(j=0;j<k;j++)  
		{  
		    if(stu[i].P>zone[j].Q && zone[j].N)//ע�⣺��stu[i].P>zone[j].Q����>=  
			{  
			    p[stu[i].index]=zone[j].index;  
			    zone[j].N--;  
			    break;//���ζ��ź����ѧ��������ź���������������  
			}//Ҳ����˵����һ��ѧ��Ҳ�ӵ�һ������ʼ��  
		}  
	}  
    j=0;  
    for(i=0;i<num;i++)//����ʣ�µ���  
	{  
	    if(p[i+1]!=-1)  
		continue;//��ʾ�Ѿ�����  
	    while(zone[j].N==0)  
		j++;//��ʾ��ǰ�����Ѿ�����  
	    p[i+1]=zone[j].index;  
	    zone[j].N--;  
	}  
    for(i=1;i<=num;i++)  
	printf("%d ",p[i]);  
    return 0;  
}  
