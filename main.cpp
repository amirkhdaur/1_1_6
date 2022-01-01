#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace fileTools {
	string __fastcall readFile(string name, string extension = "txt") {
		ifstream file;
		file.open(name + "." + extension);
		string str = "";

		if (file.is_open()) {
			while (!file.eof()) {
				char tmp;
				file.get(tmp);
				str += tmp;
			}
			file.close();
		}
		else {
			cout << "failed to open the file";
		}

		return str;
	}
	void __fastcall createFile(string name, string text, string extension = "txt") {
		ofstream file(name + "." + extension);
		if (file.is_open()) {
			file << text;
			file.close();	
		}
		else {
			cout << "failed to open the file";
		}
	}
}

// 1. Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
// Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран. 
// Не забыть освободить память. =) Разбить программу на функции.
typedef unsigned long long int task1_v;

void __fastcall initArray1(task1_v* arr, const size_t size) {
	task1_v value = 1;
	for (size_t i = 0; i < size; i++, value <<= 1) {
		arr[i] = value;
	}
}

void __fastcall printArray1(task1_v* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

inline void task1() {
	cout << "TASK 1" << endl;

	size_t size;
	cout << "Enter size: ";
	cin >> size;

	task1_v* arr = new (nothrow) task1_v[size];
	if (arr == nullptr) {
		cout << "failed to allocate memory";
		return;
	}
	
	initArray1(arr, size);
	printArray1(arr, size);

	delete[] arr;

	cout << endl << endl;
}


// 2. Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. 
// Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
void __fastcall initArray2(int** arr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

void __fastcall printArray2(int** arr, size_t n, size_t m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void task2() {
	cout << "TASK 2" << endl;

	size_t n, m;
	n = m = 4;
	int** arr = new (nothrow) int* [n];
	if (arr == nullptr) {
		cout << "failed to allocate memory";
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = new (nothrow) int[m];
		if (arr[i] == nullptr) {
			cout << "failed to allocate memory";
			return;
		}
	}

	initArray2(arr, n, m);
	printArray2(arr, n, m);

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	cout << endl << endl;
}


// 3. Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом 
// (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
inline void task3() {
	cout << "TASK 3" << endl;

	const string str_1 = "string qwerty 123 hello world :3 zxc qwe !!!!!()()()";
	const string str_2 = "some text 789 rito c++ c oop cup :d vvvvvvvbbnbnbfdkv";
	string file_1, file_2;

	cout << "Enter file 1: ";
	cin >> file_1;
	fileTools::createFile(file_1, str_1);

	cout << "Enter file 2: ";
	cin >> file_2;
	fileTools::createFile(file_2, str_2);

	cout << endl << endl;
}


// 4. Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
void __fastcall spliceFiles(string name_1, string name_2, string output) {
	string str_1 = fileTools::readFile(name_1);
	string str_2 = fileTools::readFile(name_2);
	string str_3 = str_1 + "\n" + str_2;
	fileTools::createFile(output, str_3);
}

inline void task4() {
	cout << "TASK 4" << endl;

	string name_1, name_2, name_3;
	cout << "Enter file 1: ";
	cin >> name_1;
	cout << "Enter file 2: ";
	cin >> name_2;
	cout << "Enter file 3: ";
	cin >> name_3;

	spliceFiles(name_1, name_2, name_3);

	cout << endl << endl;
}


// 5. Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово
// в указанном пользователем файле (для простоты работаем только с латиницей). 
// Используем функцию find которая есть в строках std::string.
inline void task5() {
	cout << "TASK 5" << endl;

	string file, word;
	
	cout << "Enter file: ";
	cin >> file;
	cout << "Enter word: ";
	cin >> word;

	string text = fileTools::readFile(file);
	if (text.find(word) != string::npos) {
		cout << "we found the word";
	}
	else {
		cout << "we didn't find the word";
	}

	cout << endl << endl;
}


int main() {
	task1();
	task2();
	task3();
	task4();
	task5();
	
	return 0;
}
