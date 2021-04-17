#include<stdio.h>
int s[1000000];
int t[1000000];
void Merge (int *s, int *t, int l, int mid, int r){
	int i = l, j = mid + 1, c = l;
	while (i != mid + 1 && j != r + 1){
		if (s[i] < s[j])
			t[c++] = s[i++];
		else
			t[c++] = s[j++];
	}//�Ƚ϶���Ԫ��
	while (i != mid + 1)
		t[c++] = s[i++];
	while (j != r + 1)
		t[c++] = s[j++];//����ʣ��Ԫ��
		int k;
	for ( k = l; k <= r; ++k)
		s[k] = t[k];//����ԭ����
}//��

void M_sort (int *s, int *t, int l, int r){
	if (l < r){
		int mid = (l + r) >> 1;
		M_sort(s, t, l, mid);
		M_sort(s, t, mid + 1, r);
		Merge(s, t, l, mid, r);
	}
}//��
int main(){
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&s[i]);
	}
	M_sort(s,t,0,9);
	for(i=0;i<10;i++){
		printf("%d  ",s[i]);
	}
	return 0;
}
