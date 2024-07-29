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
		std::cout << "\n�������� ������� � ������ �������: "
			<< queue.getFront();
		std::cout << "\n�������� ������� � ����� �������: "
			<< queue.getRear() << '\n';
		std::cout << "������ �������:" << queue.size() << '\n';
		std::cout << "\n������� �������� �� �������:";
		queue.deleteFront();
		queue.deleteRear();
		std::cout << "\n�������� ������ ������� � �������: " <<queue.getFront() << '\n';
		std::cout << "\n�������� ��������� ������� � �������: " << queue.getRear() << '\n';
		std::cout << "������ �������:" << queue.size() << '\n';

		std::cout << "\n������� ������ �������:\n";
		Deque<int> queue2;
		queue2.insertFront(-123);
		queue2.insertRear(56);
		queue2.display();

		std::cout << "\n������������� �������:\n";
		Deque<int>* queue3 = queue2.clone();
		queue3->display();

		std::cout << "\n����� ��������:\n";
		Deque<int> sum = *queue3 + queue2;
		sum.display();

		std::cout << "\n������� ��������� �������:\n";
		Deque<int> queue4;
		queue4.insertFront(12);
		queue4.insertFront(45);
		queue4.insertFront(56);
		queue4.display();
		std::cout << "\n���������� ��������:\n";
		Deque<int> same = *queue3 * queue4;
		same.display();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}


