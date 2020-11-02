#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int d1 = 0;
int d2 = 0;
int* getNext(string p)
{
	int* next = new int[p.length()];
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < (int)p.length() - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			d1++;
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}
int KMP(string T, string p)
{
	int i = 0;
	int j = 0;
	int* next = getNext(p);
	while (i < (int)T.length() && j < (int)p.length())
	{
		if (j == -1)
		{
			d1++;
			i++;
			j++;
		}
		else if (T[i] == p[j])
		{
			d1++;
			i++;
			j++;
			
		}
		else
		{
			j = next[j];
			
		}

	}
	if (j == (int)p.length())
	{
		return i - j;
	}
	return -1;
}
int BM(string s, string s1)
{
	int i = s1.size() - 1;
	int j = s1.size() - 1;
	while (i < s.size())
	{
		j = s1.size() - 1;
		while (s[i] == s1[j])
		{
			d2++;
			i--;
			j--;
			if (j < 0)
				break;
		}
		if (j < 0)
			break;
		while (j >=0)
		{
			d2++;
			if (s[i] == s1[j])
				break;
			j--;
		}
		
		i = i + s1.size() - j - 1;

	}
	if (j == -1) 
	{
		return (i+1 );
	}
	return -1;

}
int main()
{
	clock_t start, end_time1, end_time2;
	srand(time(0));
	string s2;
	for (int i=0; i < 200000; i++)
		s2 += char(rand() % 200);
	string s3;
	for (int j = 10000; j < 30000; j++)
		s3 += s2[j];
	start = clock();
	getNext(s3);
	cout<<KMP(s2, s3)<<endl;
	end_time1 = clock();
	cout << "KMP算法运行的时间："<<(double)(end_time1 - start) <<"ms"<< endl;
	cout << "KMP算法比较次数：" << d1 << endl;
	cout << BM(s2, s3) << endl;
	end_time2 = clock();
	cout << "BM算法运行的时间：" << (double)(end_time2 - end_time1) <<"ms"<< endl;
	cout << "BM算法比较次数：" << d2<< endl;
}