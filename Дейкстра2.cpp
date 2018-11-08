// Дейкстра2.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <ctime>
using namespace std;

int perestanovka(int *p, int n)
{
	int I = -1;

	for (int i = 1; i < n - 1; i++)
	{
		if (p[i] < p[i + 1])
			I = i;
	}

	if (!I)
		return I;

	int J = I + 1;

	for (int i = J + 1; i < n; i++)
	{
		if (p[I] < p[i])
			J = i;
	}

	int temp;
	temp = p[J];
	p[J] = p[I];
	p[I] = temp;
	//Inversion(p, n, I);НЕ МОЖЕТ ВЫЗВАТЬ ФУНКЦИЮ
	return I;
}
void Inversion(int *p, int n, int I)
{
	if (I >= 1) {
		int temp;

		bool ob = true;

		while (ob) {
			ob = false;

			for (int i = I + 1; i < n - 1; i++) {
				if (p[i] > p[i + 1])
				{
					ob = true;
					temp = p[i];
					p[i] = p[i + 1];
					p[i + 1] = temp;
				}
			}
		}
	}
}
void Origin(int *p,int start,int n)
{
	p[0] = start - 1;
	for (int i = 1; i < start; i++)
	{
		p[i] = i - 1;
	}
}

void Print(int *p, int n)
{
	for (int i = 0; i < n; i++) {
		cout << '[' << p[i] << ']' << ' ';
	}
	cout << endl;
}

int Cost(int **matr, int *p, int n)
{
	int cost = 0;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		cout << p[i] << "->" << p[i + 1] << '=' << matr[p[i]][p[i + 1]] << endl;
		cost += matr[p[i]][p[i + 1]];
	}
	cout << p[i] << "->" << p[0] << '=' << matr[p[i]][p[0]] << endl;
	cost += matr[p[i]][p[0]];
	return cost;
}

void Copy(int*p1, int*p2, int n)
{
	for (int i = 0; i < n; i++)
	{
		p1[i] = p2[i];
	}
}

int main()
{
	srand(time(0));

	int n;
	int I = 1;
	cout << "Enter the number of cities = ";
	cin >> n;

	int ** matr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			matr[i][j] = rand() % 10;
		matr[i][i] = -1;
	}

	for (int i = 0; i < n; i++) {
		Print(matr[i], n);
	}


	int *p = new int[n];
	
	for (int i = 0; i < n; i++)
		p[i] = i;
	int start;

	cout << "Enter the starting city = ";
	cin >> start;

	Origin(p,start,n);
	
	int *cheapway = new int[n];
	
	int cost = 1000, cost_temp;
	 
	unsigned int start_time = clock();

	while (I!=-1) {
		Print(p, n);
		cost_temp = Cost(matr, p, n);
		cout <<"Cost = " <<cost_temp << endl;
		if (cost_temp < cost) {
			cost = cost_temp;
			Copy(cheapway, p, n);
		}
		I = perestanovka(p, n);
		Inversion(p, n, I);
	}
	cout << "Cheper way" << endl;
	Print(cheapway, n);
	cout << cost<<endl;
	
	unsigned int end_time = clock();
	
	cout << endl << "WORKING TIME = "<<end_time - start_time << endl;

	system("pause");

    return 0;
}

