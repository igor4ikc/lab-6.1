//ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* c, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		c[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int Sum(int* c, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if ((c[i] > 0) || (c[i] % 2 != 0))
			S += c[i];
	return S;
}

int kilkist_i(int c[], const int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if ((c[i] > 0) || (c[i] % 2 != 0))
			k++;
	}
	return k;
}
int zamina_i(int zam[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		if ((zam[size] > 0) || (zam[size] % 2 != 0))
			cout << 0 << " ";
	}
	return 0;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
		const int n = 27;
	int c[n];

	int Low = -35;
	int High = 25;

	Create(c, n, Low, High);
	Print(c, n);

	cout << "S = " << Sum(c, n) << endl;

	cout << "k = " << kilkist_i(c, n) << endl;

	return 0;
}
//рекурсивний спосіб
int Sum_r(int* с, const int size, int i)
{
	if (i < size)
		return с[i] + Sum(с, size);
	else
		return 0;
}
int kilkist_r(int c[], const int size, int k = 0)
{
	if ((c[size] > 0) || (c[size] % 2 != 0))
		k++;
	if (!(size < 27))
		return k;
	else
		return kilkist_r(c, size + 1, k);
}
int zamina_r(int zam[], const int size)
{
	if ((zam[size] > 0) || (zam[size] % 2 != 0))
		cout << 0 << " ";
	else
		cout << zam[size] << " ";
	if (size != 27)
		return zamina_r(zam, size + 1);
}
