#include <iostream>

template <typename T>
class Stack
{
public:
	template <typename T>
	void Push(T value)
	{

		index++;
		if (size <= index)
		{
			ResizeArray<T>();
		}
		arr[index] = value;
	};

	template <typename T>
	T Pop()
	{
		index--;

		if (index <= -1)
		{
			index = -1;
			return NULL;
		}

		return arr[index + 1];
	}

	void Show()
	{
		for (int i = 0; i <= index; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}

	int Count()
	{
		return index + 1;
	}




private:
	int size = 0;
	T* arr = new T[0];
	int index = -1;

	template <typename T>
	void ResizeArray()
	{
		size++;
		T* temp = arr;
		arr = new T[size];
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = temp[i];
		}
		delete temp;
	}
};

int main()
{
	int ct = 0;
	int ch;
	Stack<int> stack;

	int* a = new int[1];

	while (ct++ < 4)
	{
		std::cin >> ch;
		stack.Push(ch);
		stack.Show();
	}
	std::cout << "Pop: " << stack.Pop<int>() << '\n';
	stack.Show();
	std::cout << "count " << stack.Count() << '\n';
	std::cout << "Pop: " << stack.Pop<int>() << '\n';
	stack.Show();
	std::cout << "count " << stack.Count() << '\n';
	std::cout << "Pop: " << stack.Pop<int>() << '\n';
	stack.Show();
	std::cout << "count " << stack.Count() << '\n';
	ct = 0;
	while (ct++ < 5)
	{
		std::cin >> ch;
		stack.Push(ch);
		stack.Show();
	}

	return 0;
}
