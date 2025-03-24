#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

// Khởi tạo danh sách rỗng
void Init(Node*& pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách có rỗng không
bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Tạo một Node mới với giá trị x
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Chèn một phần tử vào đầu danh sách
void InsertFirst(Node*& pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// Chèn một phần tử vào sau nút p
void InsertAfter(Node* p, int x) {
    if (p != NULL) {
        Node* q = CreateNode(x);
        q->next = p->next;
        p->next = q;
    }
}

// Duyệt và in ra danh sách
void ShowList(Node* pHead) {
    if (pHead == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* p = pHead;
    while (p != NULL) {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Tìm kiếm một nút có giá trị x trong danh sách
Node* Find(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

// Xóa nút đầu danh sách
void DeleteFirst(Node*& pHead) {
    if (IsEmpty(pHead)) {
        cout << "Danh sach rong, khong the xoa!" << endl;
        return;
    }
    Node* p = pHead;
    pHead = pHead->next;
    delete p;
}

// Xóa nút có giá trị x (xóa phần tử đầu tiên có giá trị x)
void Remove(Node*& pHead, int x) {
    if (pHead == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* p = pHead;
    Node* prev = NULL;
    while (p != NULL && p->info != x) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Khong tim thay phan tu co gia tri " << x << endl;
        return;
    }
    if (prev == NULL) { // Nếu phần tử cần xóa là nút đầu danh sách
        pHead = pHead->next;
    } else {
        prev->next = p->next;
    }
    delete p;
    cout << "Da xoa phan tu co gia tri " << x << endl;
}

// Sắp xếp danh sách bằng Selection Sort
void SelectionSort(Node*& pHead) {
    if (pHead == NULL) return;
    Node* p = pHead;
    while (p != NULL) {
        Node* minNode = p;
        Node* q = p->next;
        while (q != NULL) {
            if (q->info < minNode->info)
                minNode = q;
            q = q->next;
        }
        // Hoán đổi giá trị
        int temp = p->info;
        p->info = minNode->info;
        minNode->info = temp;
        p = p->next;
    }
}

// Xóa toàn bộ danh sách
void ClearList(Node*& pHead) {
    Node* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

int main() {
    Node* head;
    Init(head);

    // Thêm các phần tử vào danh sách (InsertFirst)
InsertFirst(head, 30);
    InsertFirst(head, 10);
    InsertFirst(head, 20); // Danh sách lúc này: 20 -> 10 -> 30

    cout << "Danh sach sau khi them InsertFirst: ";
    ShowList(head);

    // Sử dụng InsertAfter: chèn sau nút có giá trị 10
    Node* node10 = Find(head, 10);
    if (node10 != NULL) {
        InsertAfter(node10, 25); // Chèn 25 sau 10
    }
    cout << "Danh sach sau khi InsertAfter (sau phan tu 10): ";
    ShowList(head);

    // Xóa phần tử có giá trị 20
    Remove(head, 20);
    cout << "Danh sach sau khi Remove (xoa phan tu 20): ";
    ShowList(head);

    // Sắp xếp danh sách bằng Selection Sort
    SelectionSort(head);
    cout << "Danh sach sau khi SelectionSort: ";
    ShowList(head);

    // Xóa toàn bộ danh sách
    ClearList(head);
    cout << "Danh sach sau khi ClearList: ";
    ShowList(head);

    return 0;
}
