// CCF.cpp : �������̨Ӧ�ó������ڵ㡣
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

	// �������ݣ�����p�͵�ǰĿ¼  
	cin >> p >> cp;
	getchar();

	// ����p��·���������滯����  
	for (int i = 1; i <= p; i++) {
		// ����·��  
		mygetline(s);
		line = s;

		// �Ǹ�·������  
		if (line[0] != '/')
			line = cp + "/" + line + "/";

		// ȥ�����"/"  
		while ((pos = line.find("//")) != -1) {
			int count = 2;
			while (line[pos + count] == '/')
				count++;
			line.erase(pos, count - 1);
		}

		// ȥ��"./"  
		while ((pos = line.find("/./")) != -1)
			line.erase(pos + 1, 2);

		// ȥ������"/"  
		if (line.size() > 1 && line[line.size() - 1] == '/')
			line.erase(line.size() - 1);

		// ȥ��"../"  
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

		// ������  
		cout << line << endl;
	}

	return 0;
}