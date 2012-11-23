/*
 *NAME:Bridge painting
 *LANG:C++
 *SOURCE:sgu121
 *TIMES:3
 *METHOD:
 *�ҵ�һ����Ϊ�����ĵ�(���û����ô�Ӷ�Ϊż���ĵ㿪ʼ)
 *���ڴӶ�Ϊ�����ĵ������չ,
 *����������չ���ĵ�һ�����ߵ���ɫΪ1,
 *1��������ǿ�������������,����һ����,�ص������(��ʱ���������˸õ��������),
 *��ô���ǿ���ͨ���õ����һ����,������չ�߲�����ɫΪ2
 *2������������������ߣ�ֻ�ܷ���һ��·�������ܷ��ʻ�¸��
 *��ôͬ��������չ��һ��·����������ɫΪ2
 *����õ�Ϊż���㣬��Ȼ����ͬʱ��չ��ɫΪ1����ɫΪ2�ıߣ�����˵��
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int mn = 110;
struct node{
    int v;
    node * next;
};
node * g[mn];
int num[mn],l,now[mn],n,k;
int cc[mn][mn];
bool visit[mn][mn] = {0};
void insert(int x,int y){
    node *z = new node();
    z->v = x;z->next = g[y];g[y]=z;
}
void dfs(int p,int color){
    int c = 3-color;
    node *x = g[p];
    while (x){
	if (!visit[p][x->v] && !visit[x->v][p]) {
	    visit[p][x->v]=visit[x->v][p]=true;
	    cc[p][x->v] = cc[x->v][p] = c;
	    dfs(x->v,c);c = 3-c;
	}
	x = x->next;
    }
}
void print(node *x,int pos){
    if (x!=0) print(x->next,pos);
    else return ;
    cout << cc[pos][x->v] << " ";
}
int main(){
    cin >> n;memset(g,0,sizeof(g));
    for (int i=1;i<=n;++i){
	cin >> k;
	while (k){
	    insert(k,i);num[i]++;cin >> k;
	}now[i] = 1;
    }
    for (int i=1;i<=n;++i)
	if (num[i] & 1) dfs(i,1);
    for (int i=1;i<=n;++i)
	dfs(i,1);
    for (int i=1;i<=n;++i){
	node * x= g[i];int tmp=0;
	while (x!=0){
	    tmp = tmp | cc[i][x->v];
	    x=x->next;
	}
	if (tmp!=3 && num[i]>1){
	    cout << "No solution" << endl;
	    return 0;
	}
    }
    for (int i =1;i<=n;++i){
	print(g[i],i);
	cout << "0" << endl;
    }return 0;
}
