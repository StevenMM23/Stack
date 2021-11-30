// Equipo:
//      Alex        Bujosa          1098913
//      Jerry       Rivas           1089317
//      Sebastian   Henriquez       1101507
//      Ismael      Dicent          1100368
//      Steven      Martinez        1101817

#include <iostream>
using namespace std;

//Funcion para pausar y limpiar la consola
void WaitClear()
{
	system("pause");
	system("cls");
}

// Clase nodo que contiene las propiedades data y Nodo tipo puntero llamado siguiente
class Node
{
	public:
		int data;
		Node* next;
};

// Clase Stack que contiene un nodo puntero llamado top y las funciones que tiene Pila
class Stack
{
	private:
		Node* top;
	public:
		//Constructor que define el estado inicial de la propiedad top
		Stack() { top = NULL; } 
		void push(int x);
		int pop();
		void Display();
};

//Metedo Push de la Clase Stack
void Stack::push(int x)
{
	// Se crea un nodo puntero llamado t
	Node *t = new Node;

	// Programacion Defensiva
	if (t == NULL)
		cout << "Stack is Full";
	// Sino...
	else
	{
		// Al nodo *t se le asigna a data el valor de x (Parametro)
		t->data = x;

		// El puntero next de t apunta al nodo anterior que tiene top
		t->next = top;

		// top para a ser t que es el nuevo nodo creado y su next apunta al nodo anterior
		top = t;
	}
}

int Stack::pop()
{
	// -1 es el valor por defecto del Stack
	int x = -1;

	// Si top esta apuntando a NULL (Constructor) significa que la pila esta vacia
	if (top == NULL)
		cout << "The Stack is Empty\n";

	// De otra forma...
	else
	{
		// se le asigna a x el valor que tiene ese nodo que se eliminara
		x = top->data;

		// t sera el nodo que tiene el top
		Node* t = top;

		// Top se va para el nodo anterior (No se quiere involucrar en el lio de eliminacion)
		top = top->next;

		// Se elimina t pero Top logro escapar al nodo que apuntaba t (El anterior)
		delete t;
	}
	// Retorna x...
	return x;
}

void Stack::Display()
{
	// Se declara un nodo *p que lo igualamos a top
	Node* p = top;

	// Mientras ese nodo no este apuntando a NULL....
	while(p != NULL)
	{
		// Imprime el dato que tiene guardado p
		cout << p->data << " ";

		// Mueve al nodo que esta apuntando P y asi sucesivamente 
		p = p->next;
	}
	// Espacio...
	cout << endl;
}

int main()
{
	//Declaro la clase Stack para utilizar sus metodos
	Stack stk;

	// Declaro las variables que se utilizaran para el menu
	int answer,value,y;

	do 
	{
		cout << "Choose a option: \n";
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;
		cout << "\nAnswer: ";

		cin >> answer;

		// La respuesta introducida se evalua para saber en cual case cae
		switch (answer)
		{
		case 1: system("cls");
			cout << "Input a number: ";
			cin >> value;

			// Introduce el valor que desea en la pila 
			stk.push(value);
			cout << "The number" << value << " was inserted\n";
			WaitClear();
			break;

		case 2: system("cls");

			// Guarda en la variable y el elemento que fue eliminado de la pila (El ultimo elemento)
			y = stk.pop();

			// Si retorna diferente a -1 significa que elimino un numero y dira cual numero fue
			if(y != -1) 
				cout << "The number " << y << " has been deleted\n";
			WaitClear();
			break;

		case 3: system("cls");
			cout << "The numbers on the stack are: \n";

			// Muestras los numeros de la pila
			stk.Display();
			WaitClear();
			break;

		case 4: //Finaliza el programa

			cout << "The program has ended !\n";
			break;
		default: system("cls"); // En caso de que el numero no este en las opciones
			cout << "It's not an option....\n";
			WaitClear();
			break;
		}
	} while (answer != 4);

}

