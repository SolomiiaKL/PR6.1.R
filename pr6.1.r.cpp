#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

// Критерій Варіанта 14: «всі, крім парних з індексами, кратними 13»
bool Suitable(const int x, const int i)
{
	return !(x % 2 == 0 && i % 13 == 0);
}

// Рекурсивна функція формування масиву
void Create(int* p, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		p[i] = Low + rand() % (High - Low + 1);
		Create(p, size, Low, High, i + 1);
	}
}

// Рекурсивна функція виведення масиву
void Print(const int* p, const int size, int i)
{
	if (i < size)
	{
		cout << setw(4) << p[i];
		Print(p, size, i + 1);
	}
	else
		cout << endl;
}

// Рекурсивна функція обчислення кількості елементів за критерієм
int Count(const int* p, const int size, int i)
{
	if (i >= size)
		return 0;
	if (Suitable(p[i], i))
		return 1 + Count(p, size, i + 1);
	return Count(p, size, i + 1);
}

// Рекурсивна функція обчислення суми елементів за критерієм
int Sum(const int* p, const int size, int i)
{
	if (i >= size)
		return 0;
	if (Suitable(p[i], i))
		return p[i] + Sum(p, size, i + 1);
	return Sum(p, size, i + 1);
}

// Рекурсивна функція заміни нулями елементів за критерієм
void Replace(int* p, const int size, int i)
{
	if (i < size)
	{
		if (Suitable(p[i], i))
			p[i] = 0;
		Replace(p, size, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;       
	int p[n];
	int Low = 15;           
	int High = 94;          

	Create(p, n, Low, High, 0);
	cout << "Started massiv:\n";
	Print(p, n, 0);

	int totalCount = Count(p, n, 0);
	int totalSum = Sum(p, n, 0);

	cout << "Sum of elements = " << totalSum << endl;
	cout << "Count of elements = " << totalCount << endl;

	Replace(p, n, 0);
	cout << "Modified massiv:\n";
	Print(p, n, 0);

	return 0;
}