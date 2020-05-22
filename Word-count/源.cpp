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
	ifstream fin("textfile.txt");//要统计的文件
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
	fin.open("textfile.txt");
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
