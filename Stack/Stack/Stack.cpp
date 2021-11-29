#include <iostream>
using namespace std;

void WaitClear()
{
	system("pause");
	system("cls");
}
class Node
{
	public:
		int data;
		Node* next;
};


class Stack
{
	private:
		Node* top;
	public:
		Stack() { top = NULL; }
		void push(int x);
		int pop();
		void Display();
};

void Stack::push(int x)
{
	Node *t = new Node;
	if (t == NULL)
		cout << "Stack is Full";
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int Stack::pop()
{
	int x = -1;
	if (top == NULL)
		cout << "La pila esta vacia\n";
	else
	{
		x = top->data;
		Node* t = top;
		top = top->next;
		delete t;
	}
	return x;
}

void Stack::Display()
{
	Node* p = top;
	while(p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Stack stk;
	int answer,value,y;
	do 
	{
		cout << "Elija que desea hacer\n";
		cout << "1. Push()" << endl;
		cout << "2. Pop()" << endl;
		cout << "3. Display()" << endl;
		cout << "4. Exit" << endl;
		cout << "\nRespuesta: ";
		cin >> answer;

		switch (answer)
		{
		case 1: system("cls");
			cout << "Escribe el numero que desea ingresar: ";
			cin >> value;
			stk.push(value);
			cout << "El numero " << value << " se ha ingresado correctamente!\n";
			WaitClear();
			break;

		case 2: system("cls");
			y = stk.pop();
			if(y != -1)
				cout << "Se ha eliminado el numero " << y << " de la pila\n";
			WaitClear();
			break;

		case 3: system("cls");
			cout << "Los numeros que estan en la pila son: \n";
			stk.Display();
			WaitClear();
			break;

		case 4:
			cout << "El programa ha finalizado !\n";
			break;
		default: system("cls");
			cout << "No es una opcion....\n";
			WaitClear();
			break;
		}
	} while (answer != 4);

}

