# queue001

#include <iostream>

using namespace std;

template <typename T>
class queue_t {
	struct node_t {
		node_t * next;
		T value;
	};
	node_t * head;
	node_t * tail;
public:
	queue_t() {
		head = nullptr;
		tail = nullptr;
	}

	~queue_t() {
		if (head == nullptr &&  tail == nullptr) {
			return;
		}
		else {
			T tmp;
			while (head != nullptr) tmp = pop();
			head = nullptr;
			tail = nullptr;
			return;
		}
		/*else if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		else if (head == nullptr &&  tail == nullptr) {
			T tmp;
			while (head != nullptr) tmp = pop();
			head = nullptr;
			tail = nullptr;
			return;
		}*/
	}

	void push(T value) {
		if (head == nullptr && tail == nullptr) {
			head = new node_t;
			head->next = nullptr;
			head->value = value;
			tail = head;
		}
		else {
			tail->next = new node_t;
			tail = tail->next;
			tail->value = value;
			tail->next = nullptr;
		}
	}

	T pop() {
		if (head == nullptr) {
			throw "empty queue";
		}
		else {
			T result;
			result = head->value;
			node_t * tmp = head;
			head = head->next;
			delete tmp;
			return result;
		}
	}
	void print() {
		for (node_t * tmp = head; tmp != nullptr; tmp = tmp->next) {
			cout << "+---+    ";
		}
		cout << endl;
		for (node_t * tmp = head; tmp != nullptr; tmp = tmp->next) {
			cout << "| " << tmp->value << " |";
			if (tmp->next != nullptr) {
				cout << "--->";
			}
		}
		cout << endl;
		for (node_t * tmp = head; tmp != nullptr; tmp = tmp->next) {
			cout << "+---+    ";
		}
		cout << endl;
		cout << endl;
	}
};

int main()
{
	int data;
	char oper;
	queue_t<int> list;

	cin >> oper;

	while (oper != 'q') {

		switch (oper)
		{
		case '=':
			list.print();
			break;

		case '+':
			cin >> data;
			list.push(data);
			list.print();
			break;

		case '-':
			int tmp = list.pop();
			list.print();
			break;
		}

		cin >> oper;
	}


	cin.get();
	cin.get();
	return 0;
}
