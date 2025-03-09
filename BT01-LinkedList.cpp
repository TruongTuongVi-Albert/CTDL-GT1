#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SinhVien {
	long mssv;
	string hoTen;
	char ngaySinh[11];
	char queQuan[50];
	double diemTB;
};

template <typename T>
struct Node
{
	// Vùng thông tin
	T data;
	// Vùng liên kết
	Node* next;
};

template <typename T>
struct LinkedList
{
	Node <T>* head;
	Node <T>* tail;
};

// Khởi tạo rỗng
void init(LinkedList<T>& l) {
	l.head = l.tail = NULL;
}

// Tạo Node
template <typename T>
Node <T>* createNode(T x) {
	Node<T>* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

// Thao tác thêm đầu danh sách
template <typename T>
void insertFirst(LinkedList<T>& l, T newElm) {
	Node<T>* p = createNode(newElm);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}

// Thao tác thêm cuối danh sách
template <typename T>
void insertLast(LinkedList<T>& l, T newElm) {
	Node<T>* p = createNode(newElm);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

// Kiểm tra danh sách rỗng
template <typename T>
bool isEmpty(const LinkedList<T>& l) {
	return l.head == NULL;
}

// Xuất 1 Sinh Viên
void xuat1Sv(const SinhVien& sv) {
	cout << "===============================\n";
	cout << "ID: ";
	cout << sv.mssv << endl;
	cout << "Ho va ten: ";
	cout << sv.hoTen << endl;
	cout << "Ngay sinh: ";
	cout << sv.ngaySinh << endl;
	cout << "Que quan: ";
	cout << sv.queQuan << endl;
	cout << "Diem trung binh: ";
	cout << sv.diemTB << endl;
	cout << "===============================\n";
}

ostream& operator <<(ostream& out, const SinhVien sv) {
	out << "===============================\n"
		<< "ID: "<< sv.mssv << endl
		<< "Ho va ten: "<< sv.hoTen << endl
		<< "Ngay sinh: "<< sv.ngaySinh << endl
		<< "Que quan: "<< sv.queQuan << endl
		<< "Diem trung binh: "<< sv.diemTB << endl
		<< "===============================\n";

	return out;
}

// Thao tác duyệt danh sách
template <typename T>
void printList(const LinkedList<T> l) {
	if (!isEmpty(l)) {
		Node* p = l.head;
		while (p != NULL) {
			/*xuat1Sv(p->data);*/
			cout << p->data << " ";
			p = p->next;
		}
	}
	cout << endl;
}

template <typename T>
void readFile(LinkedList<T>& l) {
	ifstream inFile("Sinh vien.txt");

	if (inFile.is_open()) {
		while(!inFile.eof()) {
			SinhVien sv;
			inFile >> sv.mssv;
			inFile.ignore(1);
			getline(inFile, sv.hoTen, '#');
			inFile.getline(sv.ngaySinh, 11, '#');
			inFile.getline(sv.queQuan, 50, '#');
			inFile >> sv.diemTB;

			insertLast(l, sv);
		}
		// Dong file
		inFile.close();
	}
}

//Sap xep danh sach: ID, Ho ten, Que quan, Diem TB
int cmpWithIdAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.mssv - sv2.mssv;
}

int cmpWithIdDesc(SinhVien sv1, SinhVien sv2) {
	return -(sv1.mssv - sv2.mssv);
}

int cmpWithNameAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.hoTen.compare(sv2.hoTen);
}

int cmpWithAddAsc(SinhVien sv1, SinhVien sv2) {
	return strcmp(sv1.queQuan, sv2.queQuan);
}

// Sắp xếp danh sách
template <typename T>
void Sort(LinkedList<T>& l, int comparator(T, T)) {
	for (Node* i = l.head; i->next != NULL; i = i->next) {
		for (Node* j = i->next; j->next != NULL; j = j->next) {
			if (comparator(j->data, i->data)<0)
				swap(j->data, i->data);
		}
	}
}

// Xóa phần tử đầu danh sách
template <typename T>
void delFist(LinkedList<T>& l) {
	if (!isEmpty(l)) {
		Node* p = l.head;
		if (l.head == l.tail) {
			l.tail = NULL;
		}
		l.head = p->next;
		delete p;
	}
	else {
		cout << "Danh sach rong! \n";
	}
}

// Xóa phần tử cuối danh sách
template <typename T>
void delLast(LinkedList<T>& l) {
	if (!isEmpty(l)) {
		Node* pLast = l.tail;
		Node* pPrev = l.head;

		if (l.head == l.tail) {
			l.head = l.tail = NULL;
			delete pLast;
			return;
		}
		while (pPrev->next != l.tail) {
			pPrev = pPrev->next;
		}
		pPrev->next = NULL;
		l.tail = pPrev;
		delete pLast;
	}
	else
	{
		cout << "Danh sach rong!\n";
	}
}

// Hủy danh sách
template <typename T>
void detroyList(LinkedList<T>& l) {
	while (!isEmpty(l))
	{
		delFist(l);
	}
}

int main() {
	// Định nghĩa

	// Khai báo

	//Khởi tạo rỗng

	// Thao tác trên danh sách

	// Giải phóng danh sách
	return 0;
}