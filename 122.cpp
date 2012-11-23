/*
 *NAME:The Book
 *LANG:C++
 *SOURCE:sgu122
 *METHOD:����ORE�����Ĺ��ܶٻ�·����.
 *1������ѡȡһ����,������������������һֱ��չ,ֱ���޷�������չ,�γ���һ����
 *2������ѡȡ�������е�ĳһ���㣬�Ѵ�����㿪ʼ��β����һ�ݵ�ȫ���û�һ�£��Ϳ����γ�һ����
 *3������û��е�������N������ô����������δ��ǵĵ�������һ���ܽ��ڻ��е��ϵģ����������ƻ����������صڶ���
 *TIMES:8
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int mn =1100;
int n,k,i,j,listNum;
int L[mn],R[mn],head,tail;
bool adj[mn][mn] ={0};
bool visit[mn];
string s;
void reverse(){//checked
    int tmp[mn],t = head,num=1;
    tmp[num]=head;
    while (t!=tail){
	t=R[t];tmp[++num]=t;
    }tmp[++num]=tail;
    if (adj[head][tail]){
	R[tail] = head;L[head] = tail;
	return ;
    }
    else for (int i=2;i<num-1;++i)
	     if (adj[head][tmp[i+1]] && adj[tail][tmp[i]]){
		 L[head] = R[head];R[head] = tmp[i+1];
		 L[tmp[i+1]] = head;R[tail] = tmp[i];
		 R[tmp[i]]=L[tmp[i]];L[tmp[i]] = tail;
		 for (int j = i-1;j>=2;--j){
		     int p = L[tmp[ j ]];
		     L[tmp[ j ]] = R[tmp[ j ]];R[tmp[ j ]]=p;
		 }
		 return;
	     }
}
void add(){
    int tmp[mn],t = head,num=1;
    tmp[num]=head;
    while (t!=tail){
	t=R[t];tmp[++num]=t;
    }tmp[++num]=tail;int pos;
    for (int i=1;i<=n;++i)
	if (visit[i]){pos = i;visit[i]=false;break;}
    for (int i =1;i<=num;++i)
	if (adj[tmp[i]][pos]){
	    head = R[tmp[i]];tail = pos;
	    R[tmp[i]] = pos;
	    L[pos] = tmp[i];
	    R[pos] = 0;
	    listNum++;
	    return;
	}
}
int findHead(){//checked
    for (int i=1;i<=n;++i)
	if (visit[i] && adj[head][i]){
	    L[head] = i;R[i]=head;L[i]=0;visit[i]=false;
	    return i;
	}
    return 0;
}
int findTail(){//checked
    for (int i=1;i<=n;++i)
	if (visit[i] && adj[tail][i]){
	    R[tail] = i;L[i]=tail;R[i]=0;visit[i]=false;
	    return i;
	}
    return 0;
}
void print(){
    int tmp[mn],t = 1,num=1;
    tmp[num]=1;
    while (R[t]!=1){
	t=R[t];tmp[++num]=t;
    }
    for (int i=1;i<=num;++i) cout << tmp[i] << " " ;
    cout << 1 << " " << endl;
}
void insert(){int v;//checked
    //�������˽��в��ϵ���չ
    while (v=findHead()) {head = v;listNum ++;}
    while (v=findTail()) {tail = v;listNum ++;}
    reverse();//Let���ܶ�·��Ϊ���ܶٻ�·
    if (listNum == n) print();//�����·��Ԫ������N��,��ô���
    else{
	int tmp = listNum;
	add();
	insert();
    }
}
void init(){//checked
    cin >> n;getchar();
    for (i = 1;i <= n;++i){
	getline(cin,s);k=0;
	for (int j=0;j<s.size();++j)
	    if (s[j]!=' ') k=k*10+s[j]-'0';
	    else {adj[i][k]=true;k=0;}
	if (k!=0){
	    adj[i][k]=true;k=0;
	}
    }memset(visit,true,sizeof(visit));
    tail = head = listNum = 1;visit[1]=false;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    init();
    insert();
    return 0;
}
