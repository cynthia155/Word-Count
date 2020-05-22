#include <stdio.h>
#include <string.h>
int main()
{
	char filename[20];
	char words[100];
	int isLastBlank = 0;
	int i;  // 当前读到缓冲区的第i个字符
	char c;  // 读取到的字符
	int bufferLen;
	int charNum = 0;  // 当前行的字符数
	int wordNum = 0; // 当前行的单词数
	int totalNum[2] = { 0, 0 };
	
	FILE *fp;
	fp = fopen("textfile.txt", "rb");
	if ((fp = fopen("textfile.txt", "rb")) == NULL) {
		printf("读取文件失败\n");
	}
	else
		printf("读取文件\n");
	while (fgets(words, 1003, fp) != NULL) {
		bufferLen = strlen(words);
		// 遍历缓冲区的内容
		for (i = 0; i < bufferLen; i++) {
			c = words[i];
			if (c == ' ' || c == ',') {  // 遇到空格,逗号
				!isLastBlank && wordNum++;  // 如果上个字符不是空格，那么单词数加1
				isLastBlank = 1;
			}
			else if (c != '\n'&&c != '\r') {  // 忽略换行符
				charNum++;  //字符数加1
				isLastBlank = 0;
			}
		}
		!isLastBlank && wordNum++;  
		isLastBlank = 1; 
		totalNum[0] += charNum;  // 总字符数
		totalNum[1] += wordNum;  // 总单词数
		printf("%-7d%-7d\n",  wordNum, charNum);
		charNum = 0;
		wordNum = 0;
	}
	printf("单词数：%d\n", wordNum);
	printf("字符数：%d\n", charNum);


	return 0;
}
