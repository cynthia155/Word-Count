//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//char filename[20];
//	//char word;
//	//printf("[parameter] [input_file_name]/n");
//	//scanf("%s",word);
//	//
//	//FILE *fp; // 指向文件的指针
//	//char buffer[1003];
//	//int bufferLen;
//	//int i; //当前读到缓冲区的第i个字符
//	//char c;
//	//int isLastBlank = 0;// 上个字符是 否是空格
//	//int charNum = 0;// 当前行的字符数
//	//int wordNum = 0; //肖前行的单词数
//
//
//	
//	
//	return 0;
//}
#include <fstream>
#include <map>
#include <string>
using namespace std;

bool isdigit(char ch)
{
	return (ch >= ' ' && ch <= '9');
}

int main(void)
{
	map<string, int> words;  //转int类型
	ifstream fin("input.txt");//要统计的文件
	ofstream fout("output.txt");//结果存放在output中

	string str;
	int wordCount = 0;
	string d;
	int charCount = 0;


	if (!fin || !fout)
	{

		exit(1);
	}
	while (fin.good())
	{
		fin >> str;
		words[str]++;
	}
	fin.close();
	fin.open("input.txt");
	while (getline(fin, d)) //以行为单位读入文件
		charCount += d.size(); //累计字符数
	fin.close();

	for (map<string, int>::iterator mit = words.begin(); mit != words.end(); ++mit)
	{
		if (!isdigit((mit->first)[0]))
		{
			fout << "<" << mit->first << ">" << ": " << mit->second << endl;
			++wordCount;
		}
	}
	fout << "wordTotal: " << wordCount << endl;  // 文件输出单词个数
	fout << "charTotal: " << charCount << endl;   //文件输出字符个数
	fout.close();
	printf("单词数：%d\n", wordCount);
	printf("字符数：%d\n", charCount);
	return 0;
}
