// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 1000;
const int INF = 1 << 30;
char s[MAXN + 1];
void mygetline(char *pc)
{
	char c;

	while ((c = getchar()) != '\n' && c != EOF)
		*pc++ = c;
	*pc = '\0';
}

int main()
{
	int p, pos;
	string cp, line;

	// 输入数据：整数p和当前目录  
	cin >> p >> cp;
	getchar();

	// 输入p个路径进行正规化处理  
	for (int i = 1; i <= p; i++) {
		// 输入路径  
		mygetline(s);
		line = s;

		// 非根路径处理  
		if (line[0] != '/')
			line = cp + "/" + line + "/";

		// 去除多个"/"  
		while ((pos = line.find("//")) != -1) {
			int count = 2;
			while (line[pos + count] == '/')
				count++;
			line.erase(pos, count - 1);
		}

		// 去除"./"  
		while ((pos = line.find("/./")) != -1)
			line.erase(pos + 1, 2);

		// 去除最后的"/"  
		if (line.size() > 1 && line[line.size() - 1] == '/')
			line.erase(line.size() - 1);

		// 去除"../"  
		while ((pos = line.find("/../")) != -1) {
			if (pos == 0)
				line.erase(pos, 3);
			else {
				int spos;
				spos = line.rfind("/", pos - 1);
				line.erase(spos, pos - spos + 3);
			}

			if (line.size() == 0)
				line = "/";
		}

		// 输出结果  
		cout << line << endl;
	}

	return 0;
}