/*
 *NAME:Help Needed!
 *LANG:C++
 *SOURCE:sgu139
 *TIMES:1
 *METHOD:�ж�0������λ�þ���Ŀ���ĺ��ܶ��پ���,�Լ������������ĸ���,�������ͬ��ż,��ôΪNO,����ΪYES.
 *PROVE:�����ƶ�0��ʱ,���ĺ��ܶ��پ���+����-1,���Ǵ�ʱ�������ĸ������������ı仯,��Ŀ��״̬�����ǲ�ͬ��ż��,���Է�����֤.
 */
#include <cstdio>
using namespace std;
int a[20],p;
int main(){
    for (int i=1;i<=16;++i){
	scanf("%d",&a[i]);
	if (! a[i]) p = (i % 4) + (i + 3)/4;
    }
    for (int i=1;i<16;++i)
	for (int j=i+1;j<=16;++j)
	    if (a[j]<a[i]) p--;
    if ((p+100) % 2) printf("YES\n");else printf("NO\n");
    return 0;
}
