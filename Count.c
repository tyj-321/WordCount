#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
void WordCount(char a, FILE* b);

int main() {
	char ch;
	FILE* fp;
	while (1) {
		printf("查询字符数输入c,查询单词数输入w:");
		scanf("%c", &ch);
		fp = fopen("word.txt", "r");
		if (fp == NULL) {
			printf("打开文件错误!\n");
			return 0;
		}
		WordCount(ch, fp);
		fclose(fp);
		getchar();
	}

	return 0;
}
void WordCount(char a, FILE* b) {
	char ch;
	int charnum = 0;
	int worldnum = 0;
	if (a == 'c') {
		ch = fgetc(b);
		while (ch != EOF) {
			charnum++;
			ch = fgetc(b);
		}
		printf("字符个数为%d\n", charnum);
	}
	else if (a == 'w') {
		ch = fgetc(b);
		while (ch != EOF) {
			if (ch == 32) {
				worldnum++;
				ch = fgetc(b);
			}
			ch = fgetc(b);
		}
		printf("单词个数为%d\n", worldnum + 1);
	}

	else {
		printf("输入错误!\n");
	}
}