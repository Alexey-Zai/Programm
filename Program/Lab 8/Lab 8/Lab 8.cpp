#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;

typedef struct shcoolBoy
{
	char surname[30];
	char name[30];
	char patronymic[30];
	int classroom;
	int mathematics;
	int physics;
	int russian;
	int literature;
	int id;
};

shcoolBoy Add(void) {
	shcoolBoy w;
	cout << "Фамилия: ";
	cin >> w.surname;
	cout << "Имя: ";
	cin >> w.name;
	cout << "Отчество: ";
	cin >> w.patronymic;
	cout << "Класс: ";
	cin >> w.classroom;
	cout << "Математика:  ";
	cin >> w.mathematics;
	cout << "Физика:  ";
	cin >> w.physics;
	cout << "русский язык: ";
	cin >> w.russian;
	cout << "литература: ";
	cin >> w.literature;
	return w;
}

void Print(shcoolBoy w)
{
	cout << "\nID: " << w.id;
	cout << "\nФамилия: " << w.surname;
	cout << "\nИмя: " << w.name;
	cout << "\nОтчество: " << w.patronymic;
	cout << "\nКласс: " << w.classroom;
	cout << "\nМатематика: " << w.mathematics;
	cout << "\nФизика: " << w.physics;
	cout << "\nрусский язык: " << w.russian;
	cout << "\nлитература: " << w.literature << "\n\n";
}

void fin(void)
{
	FILE* data;
	int num = 0;
	if ((data = fopen("data.txt", "wb")) == NULL) perror("не удается открыть фаил"), exit(110);
	bool cont = true;
	while (cont)
	{
		++num;
		shcoolBoy w = Add();
		w.id = num;
		fwrite(&w, sizeof(shcoolBoy), 1, data);
		cout << "Продолжить ввод данных (y/n): ";
		char h;
		cin >> h;
		cout << "\n";
		while (h != 'y' && h != 'n') {
			cout << "Ответ не распознан\n";
			cout << "Продолжить ввод данных, введите y(да) или n(нет):\n";
			cin >> h;
		}
		if (h == 'y') cont = true;
		else if (h == 'n') cont = false;
	}
	fclose(data);
}

int fout(void)
{
	int num = 0;
	FILE* data;
	shcoolBoy w;
	if ((data = fopen("data.txt", "rt")) == NULL) perror("не удается открыть фаил"), exit(210);
	fread(&w, sizeof(shcoolBoy), 1, data);
	while (!feof(data))
	{
		Print(w);
		num = w.id;

		fread(&w, sizeof(shcoolBoy), 1, data);
	}
	fclose(data);
	if (!num) perror("ошибка номерации"), exit(230);
	return num;
}

void del(void)
{
	FILE* data, * bof;
	if ((data = fopen("data.txt", "rb")) == NULL) perror("не удается открыть фаил"), exit(310);
	shcoolBoy w;
	bof = fopen("bof.txt", "wb");
	while (fread(&w, sizeof(shcoolBoy), 1, data) == 1)
	{
		if ((w.mathematics != 2) && (w.physics != 2) && (w.russian != 2) && (w.literature != 2)) {
			fwrite(&w, sizeof(shcoolBoy), 1, bof);
		}
		else
			cout << "Ученик " << w.surname << " удален\n";
	}
	fclose(data);
	fclose(bof);
	remove("data.txt");
	if (rename("bof.txt", "data.txt") != 0) perror("ошибка переименовывания"), exit(320);
}

void add(int number)
{
	FILE* data, * bof;
	shcoolBoy w;
	shcoolBoy bofw;
	int num = 1;
	++number;
	if ((data = fopen("data.txt", "rb")) == NULL) perror("не удается открыть фаил извлечения"), exit(410);
	if ((bof = fopen("bof.txt", "wb")) == NULL) perror("не удается открыть фаил для записи"), exit(411);

	while (fread(&w, sizeof(shcoolBoy), 1, data) == 1)
	{

		if (w.id == 1) {
			bofw = Add();
			bofw.id = 1;
			fwrite(&bofw, sizeof(shcoolBoy), 1, bof);
			w.id = w.id + 1;
			fwrite(&w, sizeof(shcoolBoy), 1, bof);
		}
		else
		{
			w.id = w.id + 1;
			fwrite(&w, sizeof(shcoolBoy), 1, bof);
		}
	}

	fclose(data);
	fclose(bof);
	remove("data.txt");
	if (rename("bof.txt", "data.txt") != 0) perror("ошибка переименовывания"), exit(420);
	return;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number = 0;
	fin();
	number = fout();
	cout << "Удаляем нерадивых учеников\n";
	del();
	number = fout();
	cout << "добовляем ученика\n";
	add(number);
	number = fout();
}