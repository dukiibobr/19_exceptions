#include <iostream>
#include <limits>
using namespace std;



//float divide(float a,float b) {
//	float res = 0;
//	if (b == 0)
//		throw exception("cant divide by 0");
//
//	/*if (b == 1)
//		throw 404;
//
//	if (b == 2)
//		throw "cant divide by 0 |string";
//
//	if (b == 3)
//		throw true;*/
//	
//	else
//	{
//		res = a / b;
//		cout << "result: " << res << endl;
//		return res;
//	}
//}

//class PasswordInvalidExcpetion:public exception {
//public:
//	PasswordInvalidExcpetion(const char* message):exception(message)  {}
//};
//
//class SmallPasswordException :public exception {
//	int length;
//public:
//	SmallPasswordException(const char *message,int length):length(length),exception(message) {}
//
//	void message() {
//		cout << what() << endl;
//		cout << "actual length: " << length << endl;
//	}
//};
//
//
//void validateLogin(const char* login,const char* password) {
//	if (strlen(password)<6)
//		throw SmallPasswordException("password too short", strlen(password));
//	
//	if (!islower(password[0]) or !isalpha(password[0]))
//		throw PasswordInvalidExcpetion("password is invalid");
//	
//	if (!isupper(login[0]) or !isalpha(login[0]))
//		throw exception("login is invalid");
//
//	cout << "loading" << endl;
//	
//}
//
//
//
//class MyArray {
//	int* arr;
//	int size;
//public:
//	MyArray(int size=20):size(size){
//		arr = new int[size] {};
//	}
//	void print()const  {
//		for (int i = 0; i < size; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//	int getEl(int index) {
//		if (index>=0 or index<size)
//			return arr[index];
//
//		else
//			throw out_of_range("index is smaller than 0 or biffer than size");
//	}
//
//	void checkLength(int len) {
//		if (len<0)
//			throw length_error("length error");
//		
//		cout << "length is valid" << endl;
//	}
//
//
//	void setSize(int newSize) {
//		if (newSize<0)
//			throw  invalid_argument("new size is smaller than 0");
//		
//		else
//		{
//			int* temp = new int[newSize];
//			for (int i = 0; i < size and i<newSize; i++)
//			{
//				temp[i] = arr[i];
//			}
//			delete[]arr;
//			arr = temp;
//			size = newSize;
//		}
//	}
//};






//1

//class Stack {
//private:
//	enum { EMPTY = -1 };
//	int* arr;
//	int size;
//	int topIndex;
//public:
//	Stack() = default;
//	Stack(int size) :size(size)
//	{
//		if (size < 0)
//			throw exception("size<0");
//
//		else{
//			arr = new int[size];
//		topIndex = EMPTY;
//		}
//	}
//	~Stack()
//	{
//		if (arr != nullptr)
//			delete[]arr;
//	}
//	bool IsFull()
//	{
//		if (size < 0)
//			throw exception("size<0");
//		
//		else
//		return topIndex == size - 1;
//	}
//	bool Push(int elem) {
//
//		if (!IsFull())
//		{
//			arr[++topIndex] = elem;
//			return true;
//		}
//		else
//		{
//			throw exception("stack is full");
//		}
//	}
//	bool IsEmpty()
//	{
//		return topIndex == EMPTY;
//	}
//	int Pop()
//	{
//		if (!IsEmpty())
//		{
//			return arr[topIndex--];
//		}
//		else
//		{
//			throw exception("stack is empty.nothing to delete now");
//		}
//
//	}
//	int GetCount()
//	{
//		return topIndex + 1;
//	}
//	void Clear()
//	{
//		
//		topIndex = EMPTY;
//	}
//	int Peek()
//	{
//		if (!IsEmpty())
//		{
//			return arr[topIndex];
//		}
//	}
//	void Print()
//	{
//		for (int i = 0; i <= topIndex; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//};



//2
template<typename T>
class List {
	struct Node {
		Node* prev;
		T value;
		Node* next;
		Node() :prev(nullptr), value{}, next(nullptr) {}
		Node(Node* p, T v, Node* n) :prev(p), value(v), next(n) {}
	};
	Node* head;
	Node* tail;
public:
	List() :head(nullptr), tail(nullptr) {}

	List(const List& other) :head(nullptr), tail(nullptr) {
		Node* current = other.head;

		while (current != nullptr)
		{
			addToTail(current->value);
			current = current->next;
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void addToHead(T val) {
		Node* newNode = new Node(nullptr, val, head);

		if (isEmpty()){
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}
	}

	void addToTail(T val) {
		Node* newNode = new Node(tail, val, nullptr);

		if (isEmpty())
			head = tail = newNode;

		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}


	void deleteFromHead() {
		if (head == nullptr)
			throw out_of_range("list is empty.cant delete");
		else
		{
			if (head->next == nullptr)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				head = head->next;
				delete head->prev;
				head->prev = nullptr;
			}
		}
	}

	void deleteFromTail() {
		if (head == nullptr)
			throw out_of_range("list is empty.cant delete");

		else
		{
			if (tail->prev == nullptr)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
			}
		}
	}

	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	void show() {
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	int getCount() {
		int count = 0;
		for (Node* i = head; i != nullptr; i = i->next)
		{
			count++;
		}
		return count;
	}

	void addByIndex(int index, T value) {
		if (index<0 or index>getCount())
			throw out_of_range("wrong index");

		if (index == 0)
			addToHead(value);

		else if (index == getCount())
			addToTail(value);

		else if (index > getCount())
			throw out_of_range("index>size");

		else if (index < 0)
			throw out_of_range("index<0");

		else
		{
			Node* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			Node* newNode = new Node(current->prev, value, current);
			current->prev->next = newNode;
			current->prev = newNode;
		}
	}

	void deleteByIndex(int index) {
		if (isEmpty())
			throw out_of_range("list is empty");

		if (index<0 or index>getCount())
			throw out_of_range("wrong index");


		if (index == 0)
			deleteFromHead();

		else if (index == getCount() - 1)
			deleteFromTail();

		else if (index > getCount() - 1)
			throw out_of_range("index>size");

		else if (index < 0)
			throw out_of_range("index<0");

		else
		{
			Node* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;

			delete current;
		}
	}

	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
};



int stringToInt(const char* str) {
	int res = 0;
	if (str==nullptr)
		throw invalid_argument("no words");

	if (str[0] == '\0')
		throw invalid_argument("empty string");

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit((unsigned char)str[i]))
			throw invalid_argument("leters in number");

		int digit = str[i] - '0';

		if (res > (numeric_limits<int>::max() - digit) / 10)
			throw out_of_range("number is too big");


		res = res * 10 + digit;
	}



	return res;
}

int main()
{
	//2

	try
	{
		cout << stringToInt("9835495834954854");
	}
	catch (invalid_argument ex)
	{
			cout << ex.what() << endl;
	}
	catch (out_of_range ex)
	{
			cout << ex.what() << endl;
	}
	catch (...) {
		cout << "unknown error" << endl;
	}


	//try
	//{
	//	List<int> l;
	//	for (int i = 0; i < 0; i++)
	//	{
	//		l.addToHead(i);
	//	}
	//	l.print();
	//	//l.deleteByIndex(2);
	//	l.print();
	//	//l.deleteFromHead();
	//	l.print();
	//	l.deleteFromTail();
	//	l.print();
	//	l.addByIndex(2, 99999);
	//	l.print();
	//}
	//catch (out_of_range ex)
	//{
	//	cout << ex.what() << endl;
	//}
	//catch (...) {
	//	cout << "unknown error" << endl;
	//}






//1
	/*try
	{
		Stack s(3);
		s.Push(5);
		s.Push(2);
		s.Push(9);
		s.Push(9);

		s.Print();

		s.Pop();
		s.Print();
		s.Print();
		s.IsFull();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		cout << "length error" << endl;
	}
	catch (...) {
		cout << "unknown error" << endl;
	}*/











	//MyArray arr(10);
	//arr.print();
	//try
	//{
	//	arr.getEl(100);
	//	arr.checkLength(-10);
	//	arr.setSize(-50);
	//}
	//catch (out_of_range ex)
	//{
	//	cout << ex.what() << endl;
	//}
	//catch(length_error ex){
	//	cout << ex.what() << endl;
	//}
	//catch(invalid_argument ex){
	//	cout << ex.what() << endl;
	//}





	/*char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << "enter login: "; cin >> login;
		cout << "enter password: "; cin >> password;
		try
		{
			validateLogin(login, password);
		}
		
		catch (PasswordInvalidExcpetion ex) {
			cout << "invalid do something" << endl;
			cout << "first letter must bbe small.a-z,A-Z,-9" << endl;
			cout << ex.what() << endl;
		}
		catch (SmallPasswordException ex) {
			ex.message();
			cout << "password must more than 6 symbols" << endl;
		}
		catch (exception ex)
		{
			cout << "general error" << endl;
			cout << ex.what() << endl;
			cout << "first sybol must be capital" << endl;
		}
		catch (...) {
			cout << "unknown exception" << endl;
		}
	}*/





	//float a, b;
	//cout << "eter numbers: ";
	//cin >> a>>b;
	//try
	//{
	//	float res = divide(a, b);
	//	cout << "result main: " << res << endl;
	//}
	//catch (exception ex)
	//{
	//	cout << ex.what() << endl;
	//}

	///*catch (int ex )
	//{
	//	cout << ex << endl;
	//}
	//catch (const char* ex )
	//{
	//	cout << ex << endl;      commented are rarely used
	//}
	//catch (bool ex )
	//{
	//	cout << "bool exception" << endl;
	//	cout << ex << endl;
	//}*/

	//catch (...) {
	//	cout << "unknown exception" << endl;
	//}





}


