#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

struct Elem
{
	Elem* next;
	int info;
};

void Create(Elem*& end, Elem*& begin, int a)
{

	Elem* tmp = new Elem;
	tmp->info = a;
	tmp->next = NULL;
	if (end != NULL)
	{
		end->next = tmp;
	}
	end = tmp;
	if (begin == NULL)
	{
		begin = tmp;
	}

}

void Print(Elem* begin)
{
	if (begin != NULL)
	{
		cout << begin->info << "\t";
		begin = begin->next;
		Print(begin);
	}

}

bool AreInElem(Elem* begin1, Elem* begin2, Elem* L, bool& result)
{
	if (begin1 == NULL)
	{
		return result;
	}
	if (L != NULL)
	{
		if (begin1->info == L->info)
		{
			result = true;
			if (true)
			{

			}
			AreInElem(begin1->next, begin2, L->next, result);
		}
		else
		{
			if (begin1->info == begin2->info)
			{
				result = false;
				AreInElem(begin1, begin2, begin2, result);
			}
			else
			{
				result = false;
				AreInElem(begin1->next, begin2, begin2, result);
			}

		}
	}
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* begin1 = NULL,
		* end1 = NULL,
		* begin2 = NULL,
		* end2 = NULL;
	bool result = false;
	int a1[5] = { 0,1,2,3,4 };
	int a2[3] = { 1,2,3 };
	for (int i = 0; i < 5; i++)
	{
		Create(end1, begin1, a1[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		Create(end2, begin2, a2[i]);
	}
	Print(begin2);
	cout << endl;
	Print(begin1);
	cout << endl;
	if (AreInElem(begin1, begin2,begin2,result))
	{
		cout << "���, ������ l1 ������� � ������ l2" << endl;
	}
	else
	{
		cout << "ͳ, ������ l1 �� ������� � ������ l2" << endl;
	}

	return 0;
}
