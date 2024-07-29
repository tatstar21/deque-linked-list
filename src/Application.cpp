#include <iostream>
#include "Deque.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		Deque<int> queue;
		queue.insertFront(5);
		queue.insertRear(17);
		std::cout << "\nВставили элемент в начало очереди: "
			<< queue.getFront();
		std::cout << "\nВставили элемент в конец очереди: "
			<< queue.getRear() << '\n';
		std::cout << "Размер очереди:" << queue.size() << '\n';
		std::cout << "\nУдалили элементы из очереди:";
		queue.deleteFront();
		queue.deleteRear();
		std::cout << "\nПоказать первый элемент в очереди: " <<queue.getFront() << '\n';
		std::cout << "\nПоказать последний элемент в очереди: " << queue.getRear() << '\n';
		std::cout << "Размер очереди:" << queue.size() << '\n';

		std::cout << "\nСоздаем вторую очередь:\n";
		Deque<int> queue2;
		queue2.insertFront(-123);
		queue2.insertRear(56);
		queue2.display();

		std::cout << "\nКлонированная очередь:\n";
		Deque<int>* queue3 = queue2.clone();
		queue3->display();

		std::cout << "\nСумма очередей:\n";
		Deque<int> sum = *queue3 + queue2;
		sum.display();

		std::cout << "\nСоздаем очередную очередь:\n";
		Deque<int> queue4;
		queue4.insertFront(12);
		queue4.insertFront(45);
		queue4.insertFront(56);
		queue4.display();
		std::cout << "\nОдинаковые элементы:\n";
		Deque<int> same = *queue3 * queue4;
		same.display();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}


