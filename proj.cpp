// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <dos.h>

using namespace std; //Подключение пространства имён

int stateM = 0;
string location = {"base.txt"};
void MainMenu();

void funk_1();
void funk_2();
void funk_3();
void funk_4();
void funk_5();
void funk_6();
void funk_7();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do {
		system("cls");
		MainMenu();
		system("cls");

		switch (stateM) {
		case 0: {
			return 0;
			break;
		}
		case 1: {
			funk_1();
			break;
		}
		case 2: {
			funk_2();
			break;
		}
		case 3: {
			funk_3();
			break;
		}
		case 4: {
			funk_4();
			break;
		}
		case 5: {
			funk_5();
			break;
		}
		case 6: {
			funk_6();
			break;
		}
		case 7: {
			funk_7();
			break;
		}

		}

	} while (true);
}


void MainMenu() {
	cout << "	МЕНЮ\n"
		<< "(0) Выход из программы.\n"
		<< "(1) Добавление новых элементов.\n"
		<< "(2) Вывод всей бд на экран.\n"
		<< "(3) Выборка из бд по фильтрам: лейбл.\n"
		<< "(4) Выборка из бд по фильтрам: группа.\n"
		<< "(5) Выборка из бд по фильтрам: название альбома.\n"
		<< "(6) Выборка из бд по расширеным фильтрам: диапазоном ('от' и 'до'): цена.\n"
		<< "(7) Выборка из бд по расширеным фильтрам: диапазоном ('от' и 'до'): год выхода альбома.\n"

		<< "Ваш выбор: ";
	cin >> stateM;
}


void funk_1() {

	string l, n, a;
	int c, y;

	ofstream output("base.txt", ios_base::app);
	if (!output.is_open()) {
		cout << "Файл не может быть открыт.\n";
		return;
	}

	getline(cin, l);
	cout << "Введите лейбл звукозаписи: ";
	getline(cin, l);
	cout << "Введите название группы: ";
	getline(cin, n);
	cout << "Введите название альбома: ";
	getline(cin, a);
	cout << "Введите год выпуска альбома ";
	cin >> y;
	cout << "Введите цену альбома: ";
	cin >> c;
	output << l << "\n" << n << "\n" << a << "\n" << y << "\n" << c << "\n";
	output.close();

}
void funk_2() {
	setlocale(0, "");
	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}
	while (!input.eof()) {
		string a, b, c, d, e;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d);
		getline(input, e);
		if (e != "") {
			cout << "Лейбл звукозаписи: " << a << ".\n";
			cout << "Название группы: " << b << ".\n";
			cout << "Название альбома: " << c << ".\n";
			cout << "Год выпуска альбома: " << d << ".\n";
			cout << "Цена альбома: " << e << ".\n";
			cout << "*___*___*___*___*___*___*___*___\n";
		}
	}
	input.close();
	system("pause");
}
void funk_3() {
	map <string, string> Data;
	string l;
	getline(cin, l);
	cout << "Введиет лейбл звукоаписи: ";
	getline(cin, l);
	cout << "________________________________\n";

	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}
	while (!input.eof()) {
		string a, b, c, d, e;
		//input >> a >> b >> c >> d >> e;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d);
		getline(input, e);
		if (e != "" and a.find(l) != -1) {
			Data.insert(pair<string, string>(a, "Лейбл звукозаписи: " + a + ".\n"
				+ "Название группы: " + b + ".\n"
				+ "Название альбома: " + c + ".\n"
				+ "Год выпуска альбома: " + d + ".\n"
				+ "Цена альбома: " + e + ".\n"
				+ "*___*___*___*___*___*___*___*___\n"));

		}

	}
	for (auto const& v : Data) {
		cout << v.second;
	}
	input.close();
	system("pause");
}
void funk_4() {
	map <string, string> Data;
	string l;
	getline(cin, l);
	cout << "Введиет название группы: ";
	getline(cin, l);
	cout << "________________________________\n";

	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}
	while (!input.eof()) {
		string a, b, c, d, e;
		//input >> a >> b >> c >> d >> e;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d);
		getline(input, e);
		if (e != "" and b.find(l) != -1) {
			Data.insert(pair<string, string>(b, "Лейбл звукозаписи: " + a + ".\n"
				+ "Название группы: " + b + ".\n"
				+ "Название альбома: " + c + ".\n"
				+ "Год выпуска альбома: " + d + ".\n"
				+ "Цена альбома: " + e + ".\n"
				+ "*___*___*___*___*___*___*___*___\n"));

		}

	}
	for (auto const& v : Data) {
		cout << v.second;
	}
	input.close();
	system("pause");
}
void funk_5() {
	string l;
	map <string, string> Data;
	getline(cin, l);
	cout << "Введиет название альбома: ";
	getline(cin, l);
	cout << "________________________________\n";

	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}

	while (!input.eof()) {
		string a, b, c, d, e;

		//input >> a >> b >> c >> d >> e;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d);
		getline(input, e);
		if (e != "" and c.find(l) != -1) {
			Data.insert(pair<string, string>(e, "Лейбл звукозаписи: " + a + ".\n"
				+ "Название группы: " + b + ".\n"
				+ "Название альбома: " + c + ".\n"
				+ "Год выпуска альбома: " + d + ".\n"
				+ "Цена альбома: " + e + ".\n"
				+ "*___*___*___*___*___*___*___*___\n"));

		}

	}
	for (auto const& v : Data) {
		cout << v.second;
	}
	input.close();
	system("pause");
}
void funk_6() {
	map<int, string> Data;
	string l;
	int after, before;
	//getline(cin, l);
	cout << "Введиет диапазон (от и до) для фильтрации по цене: ";
	cin >> after >> before;
	cout << "________________________________\n";

	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}
	while (!input.eof()) {
		string a, b, c, d, e_;
		int e;
		//input >> a >> b >> c >> d >> e;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d);
		getline(input, e_);
		e = atoi(e_.c_str());
		//cout <<  a  << b << c << d << e <<'\n';
		if (after <= e and e <= before and d != "")
			Data.insert(pair<int, string>(e, "Лейбл звукозаписи : " + a + "\n" +
				"Название группы: " + b + "\n" +
				"Название альбома: " + c + "\n" +
				"Год выпуска альбома: " + d + "\n" +
				"Цена альбома: " + to_string(e) + "\n" +
				"*___*___*___*___*___*___*___*___\n"));
	}
	for (auto const& v : Data) {
		cout << v.second;
	}
	input.close();
	system("pause");

}
void funk_7() {
	map<int, string> Data;
	string l;
	int after, before;
	getline(cin, l);
	cout << "Введиет диапазон (от и до) для фильтрации по году выпуска: ";
	cin >> after >> before;
	cout << "________________________________\n";

	ifstream input(location, ios_base::in);
	if (!input.is_open()) {
		cout << "Файл не может быть открыт.\n";
		Sleep(2000);
		return;
	}
	while (!input.eof()) {
		string a, b, c, d_, e;
		int d;
		getline(input, a);
		getline(input, b);
		getline(input, c);
		getline(input, d_);
		getline(input, e);
		d = atoi(d_.c_str());
		if (after <= d and d <= before and e != "")
			Data.insert(pair<int, string>(d, "Лейбл звукозаписи : " + a + "\n" +
				"Название группы: " + b + "\n" +
				"Название альбома: " + c + "\n" +
				"Год выпуска альбома: " + to_string(d) + "\n" +
				"Цена альбома: " + e + "\n" +
				"*___*___*___*___*___*___*___*___\n"));
	}
	for (auto const& v : Data) {
		cout << v.second;
	}
	input.close();
	system("pause");

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
