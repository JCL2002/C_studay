#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char txt[1048577];
char pat[1048577];
unsigned int k[1048577];

int KMP() {
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int i, j = 0;
	//next�ļ���
	if (!txt_len || !pat_len) {
		return 0;
		}
	k[0] = 0;
	k[1] = 1;
	for (i = 2; i < pat_len; i++) {
		if (pat[i - 1] == pat[k[i - 1] - 1]) { //����ܹ��γ���ȵ�ǰ��׺
			k[i] = k[i - 1] + 1;
			}
		else if (pat[i - 1] == pat[0]) {   //�޷������������ǰ��׺�������һ��Ԫ���ܹ������ǰ��׺
			k[i] = 2;
			}
		else {
			k[i] = 1;
			}
		}
	for (i = 0; i < txt_len;) {
		if (txt[i] != pat[j]) {
			if (k[j]) {
				j = k[j] - 1;
				}
			else {   //ָ��pat�ĵ�һ��Ԫ��ʱ
				i++;
				continue;
				}
			}
		else {
			i++;
			j++;
			if (j == pat_len) { //ƥ��ɹ�
				return i - pat_len + 1;
				}
			}
		}
	return 0;
	}

int BF() {
	int i, j;
	for (i = 0; i < strlen(txt) - strlen(pat) + 1; i++) {
		if (pat[0] == txt[i]) {
			for (j = 1; j < strlen(pat); j++) {
				if (pat[j] != txt[j + i]) {
					break;
					}
				}
			if (j == strlen(pat)) {
				return i + 1;
				}
			}
		}
	return 0;
	}

int main() {
	int i;
	for(i=0;i<1048576;i++){
		txt[i]='a';
	}
	txt[1048576]='b';
	for(i=0;i<10000;i++){
		pat[i]='a';
	}
	pat[10000]='b';
	int t1,t2,t3;int res1,res2;
	t1=time(NULL);
	res1=BF();
	t2=time(NULL);
	res2=KMP();
	t3=time(NULL);
	printf("��ʱ��\nBF:%d\tKMP:%d\n���:\nBF:%d\tKMP:%d",t2-t1,t3-t2,res1,res2);
	return 0;
	}
