#include"stdafx.h"
#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

double function(double x);//Прототип функции,возвращающей значение функции 
double functionDf1(double x);//Прототип функциии, возвращающей значение первой производной
double functionDf2(double x);//Прототип функции, возвращающей значение второй произодной
double MetodHord(double infinum, double supremum, double epsilon, int& k);//Прототип функции уточнения корней методом хорд
double MetodCas(double a, double b, double e, int& k);//Прототип функции уточнения корней методом касательных


int main()
{
	setlocale(LC_ALL, "Russian");//Подключение русского языка
	double a;//Нижняя граница поиска корней
	double b;//Верхняя граница поиска корней
	double eps;//Заданная точность
	double x1;//Корень полученный методом хорд
	double x2;//Корень полученный методом касательных
	int k1 = 0;//Количество итераций в методе хорд
	int k2 = 0;//Количество итераций в методе касательных
	cout << "Введите нижнюю границу поиска корней:\n";
	cin >> a;//Ввод нижней границы поиска корней
	cout << "Введите верхнюю границу поиска корней\n";
	cin >> b;//Ввод верхней границы поиска корней
	cout << "Введите точность поиска корней\n";
	cin >> eps;//Ввод заданной точности для поиска корней

	//Если заданная точность меньше нуля
	if (eps < 0) {
		cout << "Ошибка! Заданная точность должна быть больше нуля\n";
		return 1;//Завершение работы программы с кодом 1
	}

	cout << endl << "Уточнение корней методом хорд:\n";
	x1 = MetodHord(a, b, eps, k1);//Вызов функции поиска корней методом хорд
	cout << "x=" << x1 << endl;//Вывод корня
	cout << "Количество итераций:" << k1 << endl << endl;//Вывод кол-ва итераций
	cout << "Уточнение корней методом касательных:\n";
	x2 = MetodCas(a, b, eps, k2);//Вызов функции поиска корней методом касательных
	cout << "x=" << x2 << endl;//Вывод корня
	cout << "Количество итераций:" << k2 << endl;//Вывод кол-ва итераций
	return 0;//Завершение работы программы с кодом 0

}

/*////////////////////////////////////////////////////////////////////////////////

				 Р Е А Л И З А Ц И Я    Ф У Н К Ц И Й

//////////////////////////////////////////////////////////////////////////////////*/




//Реализация функции,возвращающей значение функции
double function(double x) {
	return x - sqrt(cos(0.387 * x));
}

//Реализация функции,возвращающей значение первой производной функции
double functionDf1(double x) {
	return 0.1935* (sin(0.387 * x) / sqrt(cos(0.387 * x))) + 1;
}
//Реализация функции,возвращающей значение второй производной функции
double functionDf2(double x) {
	return 0.0374* sin(pow(0.387 * x, 2)) / (cos(pow(0.387 * x, 1.5)) + 0.0749 * pow(cos(0.387 * x), 0.5));

}


//Реализация функции уточнения корней методом касательных
double MetodCas(double a, double b, double e, int& k) {
	double x;//Корень уравнения
	//Если выполняется первое условие сходимости
	if (function(a) * functionDf2(a) > 0) {
		x = a;
		cout;
	}//end if
	else {
		//Если выполняется второе условие сходимости
		if (function(b) * functionDf2(b) > 0) {
			x = b;

		}//end if
		//Если условие сходимости не выполняется
		else {
			x = -10E10;
			return x;
		}
	}
	if (x > -10E10) {
		k = 0;
		while (1) {
			x = x - function(x) / functionDf1(x);
			k = k + 1;
			if (fabs(function(x)) < e) break;
		}
		return x;
	}
}




//Реализация функции уточнения корней методом хорд
double MetodHord(double infinum, double supremum, double epsilon, int& k)
{
	while (fabs(supremum - infinum) > epsilon)
	{
		infinum = supremum - (supremum - infinum) * function(supremum) / (function(
			supremum) - function(infinum));
		supremum = infinum - (infinum - supremum) * function(infinum) / (function(
			infinum) - function(supremum));
		k++;
	}

	return supremum;
}
