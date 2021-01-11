#include <iostream>
#include <queue>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	setlocale(LC_ALL, "Russian");
	std::queue<int> queue2, queue3, queue5, queue235; //Очереди с кратностью 2,3,5 и общая очередь со всеми элементами других очередей
	queue2.push(2); queue235.push(2); //Первоначальное заполнение очередей
	queue3.push(3); queue235.push(3);
	queue5.push(5); queue235.push(5);
	int N, minim; //N-кол-во выводимых чисел, minim - минимальное из тройки очередей queue2,queue3,queue5
	cout << "Сколько чисел вы хотите вывести?: ";
	cin >> N;
	int i=0;
	for (;;) //Алгоритм заполненеия очередей
	{ 
		minim = fmin(fmin(queue2.back(), queue3.back()), queue5.back()); // Поиск минимального из тройки очередей
		if ((minim = queue2.back()) && (queue2.size() + queue3.size() + queue5.size() != N)) 
		{ //Если мин. из очереди queue2 и это добавление не превышает запрашиваемое количество N, то элемент добавляется в queue2 и queue235(общую)
			queue2.push(minim * 2);
			queue235.push(minim * 2);
		}
		else break;
		if ((minim = queue3.back()) && (queue2.size() + queue3.size() + queue5.size() != N))
		{//Если мин. из очереди queue3 и это добавление не превышает запрашиваемое количество N, то элемент добавляется в queue3 и queue235(общую)
			queue3.push(minim * 2);
			queue235.push(minim * 2);
		}
		else break;
		if ((minim = queue5.back()) && (queue2.size() + queue3.size() + queue5.size() != N))
		{//Если мин. из очереди queue5 и это добавление не превышает запрашиваемое количество N, то элемент добавляется в queue5 и queue235(общую)
			queue5.push(minim * 2);
			queue235.push(minim * 2);
		}
		else break;
		i++;
	}
	int arr[1000] = { 0 }; // Передача очереди в массив
	for (int i = 0; i < N; i++) {
		arr[i] = queue235.front();
		queue235.pop();
	}
	int z;  // Сортировка пузырьком
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				z = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = z;
			}
		}
	}

	for (int i = 0; i < N; i++) { //Вывод
		cout << arr[i] << " ";
	}
	cout << endl;
}