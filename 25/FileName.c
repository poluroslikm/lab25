#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int lab25task1();
int lab25task2();
int rand10(int mmax);
int* rand15(int n, int mmax);
double rand_double(double dmin, double dmax);
double* rand_double15(int n, int mmax);
int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "RUS");
	char c;
	printf("Введите номер задания лабораторной ");
	scanf("%c", &c);
	switch (c)
	{
	case '1':
		lab25task1();
		break;
	case '2':
		lab25task2();
		break;
	case '3':
		//lab19task3();
		break;
	default:
		printf("Неизвестная операция.\n");
	}
}
double rand_double(double dmin, double dmax)
{
	int z = dmin * 10000000, y = dmax * 10000000;
	double m = (z + rand() % (y-z));
	m /= 10000000;
	return m;
}
double rand15d(double dm)
{
	//int z = -dm * 10000000, y = dm * 10000000;
	double m = (-dm + 1.f* (dm + dm)* rand()/RAND_MAX);
	//m /= 10000000;
	return m;
}
int rand10(int mmax)
{
	int m = 1 + rand() % mmax;
	return m;
}
int* rand15(int n, int mmax)
{
	int* array1 = NULL;
	array1 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		array1[i] = rand10(mmax);
		//printf("%d\n", array1[i]);
	}
	return array1;
}
double* rand_double15(int n, double dm)
{
	double* array2 = NULL;
	array2 = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		array2[i] = rand15d(dm);
	}
	return array2;
}
int lab25task1()
{
	int m = 1 + rand() % 3;
	int k;
	printf("Угадайте цифру от 1 до 3\n");
	scanf("%d", &k);
	if (k == m) 
		printf("МОЛОДЕЦ ТЫ УГАДАЛ!!!!!"); 
	else 
		printf("Повезет в следующий раз, числом было %d",m);
}
int lab25task2()
{
	int n, mmax;
	double dmin, dmax, dm;
	int* ptr_array1 = NULL;
	double* ptr_array2 = NULL;
	printf("Введите размер массива\n");
	scanf("%d", &n);
	printf("Введите максимальное целое число для первого массива\n");
	scanf("%d", &mmax);
	//printf("Введите минимальное вещественное число для первого массива\n");
	//scanf("%lf", &dmin);
	//printf("Введите максимальное вещественное число для первого массива\n");
	//scanf("%lf", &dmax);
	printf("Введите интервал\n");
	scanf("%lf", &dm);
	//rand15(n, mmax);
	ptr_array1 = (int*)realloc(rand15(n, mmax), n * sizeof(int));
	ptr_array2 = (double*)realloc(rand_double15(n, dm), n * sizeof(double));
	for (int i = 0; i < n; i++)
	{
		printf("%2.d   %+7.5lf\n", ptr_array1[i], ptr_array2[i]);
	}
	free(ptr_array1);
	free(ptr_array2);
}