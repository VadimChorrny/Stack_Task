#include <iostream>
#include <list>
using namespace std;

template<typename T>
class FwdList
{
public:
	FwdList() = default;
	FwdList(const FwdList& arg);
	
	void pushFront(const T& data);
	void pushTail(const T& data);
	void pushAfter(const T& searchData, const T& insData);
	void eraseAfter(const T& searchData);
	void eraseFront();
	void eraseTail();
	bool isEmpty() const;
	void clear();
	bool Swap(const T& searchData, const T& data);
	void move();
	void print() const;
	void printFromRightToLeft() const;
	void printFromLeftToRight() const;
	~FwdList();

private:
	struct Node
	{
		T data;
		Node* next;
		Node* last;
		Node(const T& data, Node* next = nullptr)
			:data(data), next(next)
		{}
	};
	auto findNode(const T& data);

	Node* head = nullptr;
	Node* tail = nullptr;
};



template<typename T>
inline FwdList<T>::FwdList(const FwdList& arg)
{
	Node* temp = arg.head;
	while (temp != nullptr) {
		pushTail(temp->data);
		temp = temp->next;
	}
}



template<typename T>
inline void FwdList<T>::pushFront(const T& data)
{
	Node* tmp = new Node(data, head);
	//tmp->data = data;
	//tmp->next=head
	if (isEmpty()) tail = tmp; //first
	head = tmp;
}

template<typename T>
inline void FwdList<T>::pushTail(const T& data)
{
	Node* add = new Node(data, nullptr);
	if (!isEmpty())
		tail->next = add;
	else
		head = add;

	tail = add;

}

template<typename T>
inline void FwdList<T>::pushAfter(const T& searchData, const T& insData)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		Node* ins = new Node(insData, find->next);
		find->next = ins;
		if (find == tail)
			tail = ins;
	}
}

template<typename T>
inline void FwdList<T>::eraseAfter(const T& searchData)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		if (find->next != nullptr) {
			Node* temp = find->next;
			find->next = temp->next;
			delete temp;
		}
	}
}

template<typename T>
inline void FwdList<T>::print() const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

template<typename T>
inline void FwdList<T>::printFromRightToLeft() const
{
	/*Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->next << " ";
		temp = temp->data;
	}*/

	Node* temp = tail;
	while (1)
	{
		cout << temp->data << " ";
		if (temp->last == 0)
			break;
		temp = temp->last;
	}
}

template<typename T>
inline void FwdList<T>::printFromLeftToRight() const
{
	/*Node* temp = tail;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
		cout << temp->next << " ";
	}*/

	Node* temp = head;
	while (1)
	{
		cout << temp->data << " ";
		if (temp->next == 0)
			break;
		temp = temp->next;
	}

}


template<typename T>
inline void FwdList<T>::eraseFront()
{
	if (!isEmpty())
	{
		auto temp = head;
		head = head->next;
		if (isEmpty()/*head == nullptr*/)
			tail = nullptr;
#ifdef MY_DEBUG
		cout << "Was deleted " << temp->data << endl;
#endif
		delete temp;
	}
}

template<typename T>
inline void FwdList<T>::eraseTail() //make if 1 elem in all!!!!
{
	if (!isEmpty())
	{
		Node* temp = head;
		while (temp->next != tail)
			temp = temp->next;
		delete temp->next;
		tail = temp;
		tail->next = nullptr;
	}
}

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	if (head == nullptr)
		return true;
	return false;
}

template<typename T>
inline void FwdList<T>::clear()
{
	while (!isEmpty())
		eraseFront();
}

template<typename T>
inline bool FwdList<T>::Swap(const T& searchData, const T& data)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		find->data = data;

		if (find == tail)
		{
			tail->data = data;
		}
		return true;
	}
	return false;
}

template<typename T>
inline void FwdList<T>::move()
{
	Node* temp = head;
	FwdList <T> reversed_list;
	while (temp != nullptr) {
		reversed_list.pushFront(temp->data);
		temp = temp->next;
	}
	this->clear();
	*this = reversed_list;
}

template<typename T>
inline FwdList<T>::~FwdList()
{
	clear();
}

template<typename T>
inline auto FwdList<T>::findNode(const T& data)
{
	Node* res = head;
	while (res != nullptr && res->data != data)
		res = res->next;

	return res;
}

int main()
{

}