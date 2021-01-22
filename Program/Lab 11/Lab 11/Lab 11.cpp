#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale>
#include <iostream>

using namespace std;

FILE* MyFile;
const char* filename = "output.txt";

struct Node {
    int value;
    Node* next;
    Node* prev;
};

Node* CreateList(int ListSize) {
    Node* FirstElement, * LastElement, * tmp;
    if (ListSize == 0) {
        FirstElement = nullptr;
    }
    else {
        FirstElement = new(Node);
        FirstElement->value = 1;
        FirstElement->prev = nullptr;
        LastElement = FirstElement;
        for (int i = 2; i <= ListSize; ++i) {
            tmp = new(Node);
            tmp->value = i;
            tmp->prev = LastElement;
            LastElement->next = tmp;
            LastElement = tmp;
        }
        LastElement->next = nullptr;
    }
    return FirstElement;
}

void PrintList(Node* FirstElement) {
    if (FirstElement == nullptr) {
        cout << "Список пуст \n";
    }
    else {
        cout << "NULL ";
        while (FirstElement != nullptr) {
            cout << FirstElement->value << "; ";
            FirstElement = FirstElement->next;
        }
        cout << "NULL\n";
    }
}

void FilePrintList(Node* FirstElement) {
    MyFile = fopen(filename, "w");
    while (FirstElement != nullptr) {
        fprintf(MyFile, "%d ", FirstElement->value);
        FirstElement = FirstElement->next;
    }
    fclose(MyFile);
}

Node* CreateListFromFile() {
    MyFile = fopen(filename, "r");
    Node* FirstElement, * LastElement, * tmp;
    if (feof(MyFile)) {
        FirstElement = nullptr;
    }
    else {
        int key = 0;
        FirstElement = new (Node);
        fscanf(MyFile, "%d", &key);
        FirstElement->value = key;
        FirstElement->prev = nullptr;
        LastElement = FirstElement;
        fscanf(MyFile, "%d", &key);
        while (!feof(MyFile)) {
            tmp = new (Node);
            tmp->value = key;
            tmp->prev = LastElement;
            LastElement->next = tmp;
            LastElement = tmp;
            fscanf(MyFile, "%d", &key);
        }
        LastElement->next = nullptr;
    }
    fclose(MyFile);
    return FirstElement;
}

Node* AddFront(Node* FirstElement) {
    Node* CurFirst = new (Node);
    CurFirst->prev = nullptr;
    CurFirst->next = FirstElement;
    CurFirst->value = 1;
    FirstElement->prev = CurFirst;
    while (FirstElement) {
        FirstElement->value += 1;
        FirstElement = FirstElement->next;
    }
    return CurFirst;
}

Node* DeleteFromList(Node* FirstElement, int n) {
    if (FirstElement->value == n) {
        FirstElement->next->prev = nullptr;
        Node* CurFirst = FirstElement->next;

        delete FirstElement;

        return CurFirst;
    }
    else {
        Node* iter = FirstElement;
        while (iter) {
            if (iter->value == n) {
                iter->prev->next = iter->next;
                iter->next->prev = iter->prev;
                delete iter;
                break;
            }
            iter = iter->next;
        }
        return FirstElement;
    }
}

Node* DeleteList(Node* FirstElement) {
    while (FirstElement != 0) {
        Node* tmp = FirstElement->next;
        delete FirstElement;
        FirstElement = tmp;
    }
    return FirstElement;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "\nСоздание списка \n";
    int n;
    cout << "Введите желаемое число элементов списка ";
    cin >> n;
    Node* List = CreateList(n);
    cout << "\nПечать списка \n";
    PrintList(List);
    cout << "\nДобавление элемента в начало списка  \n";
    List = AddFront(List);
    cout << "\nПечать списка \n";
    PrintList(List);
    cout << "\nВывод в файл списка \n";
    FilePrintList(List);
    cout << "\nУдаление элемента с номером n \n";
    cout << "Введите n ";
    cin >> n;
    List = DeleteFromList(List, n);
    cout << "\nПечать списка  \n";
    PrintList(List);
    cout << "\nВосстановление списка из файла \n";
    List = CreateListFromFile();
    cout << "\nПечать списка \n";
    PrintList(List);

    return 0;
}