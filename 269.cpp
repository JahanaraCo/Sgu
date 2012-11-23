#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define maxn 251
using namespace std;

typedef int digit;
class bigNum{
public:
    vector <digit> a;
    int n;
public:
    bigNum(){//���캯�� 
	n=0;
    }
    int make (int c){//������ת��Ϊ���� 
	int l=0;
	a.resize(30);
	while (c>0){
	    a[l++]=c%10;
	    c/=10;
	}
	--l;
	while (l>0 && a[l]==0) --l;
	n=l+1;
	return l+1;
    }
    int make (string c){//���ַ�����ת��Ϊ���� 
	int l=c.size();
	a.resize(l);
	n=l;
	for (int i=0;i<l;++i){
	    a[i]=c[l-i-1]-'0';
	}
	--l;
	while (l>0 && a[l]==0) --l;
	n=l+1;
	return l+1;
    }
    void pout(){//��� 
	for (int i=n-1;i>-1;--i)
	    printf("%d",a[i]);
	printf("\n");
    }
    friend bigNum operator+(bigNum &a,bigNum &b){//����+ 
	bigNum r;
	int m=a.n>b.n?a.n:b.n;
	r.n=m;
	r.a.resize(m+10);
	for (int i=0;i<m;++i){
	    if (a.n>i) r.a[i]+=a.a[i];
	    if (b.n>i) r.a[i]+=b.a[i];
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	++r.n;
	while (r.n>0 && r.a[r.n]==0) --r.n;
	++r.n;
	return r;
    }
    friend bigNum operator -(bigNum &a,bigNum &b){//Ĭ�ϴ���a>b ����- 	
	bigNum r=a;
	int m=r.n;
	for (int i=0;i<m;++i){
	    if (b.n>i) r.a[i]-=b.a[i];int j=i;
	    while (r.a[j]<0){
		r.a[j]+=10;
		--r.a[j+1];
	    }
	}
	--m;
	while (m>0 && r.a[m]==0) --m;
	r.n=m+1;
	return r;
    }
    friend bool operator >(bigNum &a,bigNum &b){//����> �Ƚϴ�С 
	if (a.n>b.n) return 1;
	if (a.n<b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 1;
	    if (a.a[i]<b.a[i]) return 0;
	}
	return 0;
    }
    friend bool operator >=(bigNum &a,bigNum &b){//����>= �Ƚϴ�С 
	if (a.n>b.n) return 1;
	if (a.n<b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 1;
	    if (a.a[i]<b.a[i]) return 0;
	}
	return 1;
    }
    friend bool operator <(bigNum &a,bigNum &b){//����< �Ƚϴ�С
	if (a.n<b.n) return 1;
	if (a.n>b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 0;
	    if (a.a[i]<b.a[i]) return 1;
	}
	return 0;
    }
    friend bool operator <=(bigNum &a,bigNum &b){//����< �Ƚϴ�С
	if (a.n<b.n) return 1;
	if (a.n>b.n) return 0;
	for (int i=a.n-1;i>=0;--i){
	    if (a.a[i]>b.a[i]) return 0;
	    if (a.a[i]<b.a[i]) return 1;
	}
	return 1;
    }
    friend bool operator ==(bigNum &a,bigNum &b){//����== 
	if (a.n!=b.n) return 0;
	for (int i=0;i<a.n;++i)
	    if (a.a[i]!=b.a[i]) return 0;
	return 1;
    }
    friend bigNum operator * (bigNum &a,int b){//����* �߾���*�;��� 
	bigNum r=a;
	r.a.resize(r.n+100);
	int m=r.n;
	for (int i=0;i<m;++i)
	    r.a[i]*=b;
	for (int i=0;i<m;++i){
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	while (r.a[m]>=10) {r.a[m+1]+=r.a[m]/10;r.a[m++]%=10;}
	r.n=m+1;while (r.a[r.n-1]==0) --r.n;
	return r;
    }
    friend bigNum operator * (bigNum &a,bigNum &b){//����* �߾���*�߾��� 
	bigNum r,temp;
	if (a.n<b.n) {temp = a;a = b;b = temp;}
	r.a.resize(a.n+b.n);
	int k;
	for (int i=0;i<a.n;++i){
	    if (b.n<=i) continue;
	    temp=a*b.a[i];
	    temp=temp<<i;
	    r=r+temp;
	 	}
	r.n=a.n+b.n-1;
	for (int i=0;i<r.n;++i){
	    r.a[i+1]+=r.a[i]/10;
	    r.a[i]%=10;
	}
	while (r.n>0 && r.a[r.n]==0) --r.n;
	++r.n;
	return r;
    }
    friend bigNum operator << (bigNum &a,int b){//�������������������10�� 
	bigNum r;
	r.a.resize(a.n+b);
	for (int i=0;i<a.n;++i)
	    r.a[i+b]=a.a[i];
	r.n=a.n+b;
	return r;
    }
};
int n,k;
bigNum f[maxn],ff[maxn],temp;
int len[maxn];
int main(){
    ios::sync_with_stdio(false);
    scanf("%d %d\n",&n,&k);
    for (int i=1;i<=n;++i) scanf("%d",&len[i]);
    sort(len+1,len+n+1);
    ff[0].make(1);
    for (int i=1;i<=n;++i){
	for (int j=0;j<=k;++j){
	    f[j] = ff[j];
	    if (j>=1){
		temp = ff[j-1]*(len[i]-(j-1));
		f[j] = f[j] + temp;
	    }
	}

	for (int j=0;j<=n;++j) ff[j] = f[j];

    }
    f[k].pout();
    return 0;
}
