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
	//next的计算
	if (!txt_len || !pat_len) {
		return 0;
		}
	k[0] = 0;
	k[1] = 1;
	for (i = 2; i < pat_len; i++) {
		if (pat[i - 1] == pat[k[i - 1] - 1]) { //如果能够形成相等的前后缀
			k[i] = k[i - 1] + 1;
			}
		else if (pat[i - 1] == pat[0]) {   //无法继续构成相等前后缀，但与第一个元素能构成相等前后缀
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
			else {   //指向pat的第一个元素时
				i++;
				continue;
				}
			}
		else {
			i++;
			j++;
			if (j == pat_len) { //匹配成功
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
	srand(time(NULL));
	char c;
	for (i = 0; i < 524288; i++) {
		c = i % 255 + 1;
		txt[i] = c;
		}
	txt[524288] = '\0';
	int j;
	j = rand() % 26;
	for (i = 0; i < 150000; i++) {
		pat[i] = txt[i + j];
		}
	pat[150000] = '\0';
	int t1, t2, t3;
	int res1, res2;
	t1 = time(NULL);
	res1 = BF();
	t2 = time(NULL);
	res2 = KMP();
	t3 = time(NULL);
	printf("bf:%d kmp:%d\n", t2 - t1, t3 - t2);
	printf("res1:%d  res2:%d\n", res1, res2);
	printf("%d", j + 1);
	return 0;
	}
