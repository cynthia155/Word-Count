#include <stdio.h>
#include <string.h>
int main()
{
	char filename[20];
	char words[100];
	int isLastBlank = 0;
	int i;  // ��ǰ�����������ĵ�i���ַ�
	char c;  // ��ȡ�����ַ�
	int bufferLen;
	int charNum = 0;  // ��ǰ�е��ַ���
	int wordNum = 0; // ��ǰ�еĵ�����
	int totalNum[2] = { 0, 0 };
	
	FILE *fp;
	fp = fopen("textfile.txt", "rb");
	if ((fp = fopen("textfile.txt", "rb")) == NULL) {
		printf("��ȡ�ļ�ʧ��\n");
	}
	else
		printf("��ȡ�ļ�\n");
	while (fgets(words, 1003, fp) != NULL) {
		bufferLen = strlen(words);
		// ����������������
		for (i = 0; i < bufferLen; i++) {
			c = words[i];
			if (c == ' ' || c == ',') {  // �����ո�,����
				!isLastBlank && wordNum++;  // ����ϸ��ַ����ǿո���ô��������1
				isLastBlank = 1;
			}
			else if (c != '\n'&&c != '\r') {  // ���Ի��з�
				charNum++;  //�ַ�����1
				isLastBlank = 0;
			}
		}
		!isLastBlank && wordNum++;  
		isLastBlank = 1; 
		totalNum[0] += charNum;  // ���ַ���
		totalNum[1] += wordNum;  // �ܵ�����
		printf("%-7d%-7d\n",  wordNum, charNum);
		charNum = 0;
		wordNum = 0;
	}
	printf("��������%d\n", wordNum);
	printf("�ַ�����%d\n", charNum);


	return 0;
}
