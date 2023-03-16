#include <iostream>
using namespace std;
void add(void);
void find(void);
int check(void);
void delete_n(void);
void display(void);
struct input_arry
{
	int value;
	input_arry* nptr;
};
input_arry* fptr = NULL; input_arry* currentptr;
int main()
{
	char op;
	while (1)
	{
		cout << "\n-------------------------------This is the menu-----------------";
		cout << "\n1.Add Value\n2.Find Value\n3.Delete Value\n4.Print All Values\n5.Clear screen : ";
		cin >> op;
		switch (op)
		{
		case'1':
			add();
			break;
		case'2':
			find();
			break;
		case'3':
			delete_n();
			break;
		case'4':
			display();
			break;
		case'5':
			system("CLS");
			break;
		}
	}
}void add(void)
{
	input_arry* ptr;
	ptr = new input_arry;
	if (fptr == NULL)
	{
		cout << "Enter the value : ";
		cin >> ptr->value;
		ptr->nptr = NULL;
		fptr = ptr;
	}
	else
	{
		input_arry* check = fptr;
		cout << "Enter the value : ";
		cin >> ptr->value;
		if (ptr->value < check->value)
		{
			ptr->nptr = check;
			fptr = ptr;
		}
		else
		{
			int flag = 0;
			if (ptr->value > check->value)
			{
				while (check->nptr != NULL)
				{
					if (check->nptr->value > ptr->value)
					{
						flag = 1;
						break;
					}
					check = check->nptr;
				}
				if (flag == 0)
				{
					check->nptr = ptr;
					ptr->nptr = NULL;
				}
				else
				{
					ptr->nptr = check->nptr;
					check->nptr = ptr;
				}
			}
		}
	}
}
void find(void)
{
	int res;
	res = check();
	if (res == 1)
	{
		cout << "\n*********** " << currentptr->value << " Value found************\n";
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!Value not found!!!!!!!!!!!!!!!!!!!\n";
	}
}
int check(void)
{
	int flag = 0;
	int fin;
	cout << "Enter the value to perform operation :  ";
	cin >> fin;
	currentptr = fptr;
	while (currentptr != NULL)
	{
		if (currentptr->value == fin)
		{
			flag = 1;
			break;
		}
		currentptr = currentptr->nptr;
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void delete_n(void)
{
	int res;
	res = check();
	input_arry* keep = fptr;
	if (currentptr == keep)
	{
		fptr = currentptr->nptr;
		delete currentptr;
	}
	else
	{
		 input_arry* remove;
		if (res == 1)
		{
			while (keep->nptr != currentptr)
			{
				keep = keep->nptr;
			}
			remove = currentptr;
			keep->nptr = currentptr->nptr;
			delete currentptr;
		}
		else
		{
			cout << "!!!!!!!!!!!!!!!!!Value not found!!!!!!!!!!!!!!!!!!";
		}
	}
}
void display(void)
{
	if (fptr == NULL)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!No Data!!!!!!!!!!!!!!!!!!!";
	}
	else
	{
		input_arry* move = fptr;
		while (move != NULL)
		{
			cout << "\nValue : " << move->value;
			move = move->nptr;
		}
	}
}
