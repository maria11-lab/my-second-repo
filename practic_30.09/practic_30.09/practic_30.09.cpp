#include <iostream>
#include <string>
void count_digets(int num)
{
	int counter[10]{};
	while (num > 0)
	{
		int d = num % 10;
		counter[d] = counter[d] + 1;
		num /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (counter[i] > 0)
		{
			std::cout << "the number " << i << " meet " << counter[i] << " times\n";
		}
	}
}
/*int first_prime_factor(int num) Разделитть на 2 функции для удобства проверок
{
	int k = -1;
	for (int i = 2; i * i <= num; ++i)
	{
		if ((num) % i == 0)
		{
			bool is_prime = true;
			for (int j = 2; j * j <= i; ++j)
			{
				if (i % j == 0)
				{
					is_prime = false;
					break;
				}
			}
			if (is_prime)
			{
				return i;
			}
		}
	}
	return -1;
}*/

//функции с одномерными массивами 

void print_array(int* arr, const int n)
{
	std::cout << "\n";
	for (int i = 0; i < n; i ++ )
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << "\n";
}
void array_input(int* arr, const int n)
{
	std::cout << "\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << "enter " << i+1 << " element array: ";
		std::cin >> arr[i];
	}
	print_array(arr, n);
}
void revers_array(int* arr, int n)
{
	int polu_n = n / 2;
	for (int i = 0; i <= polu_n; i++)
	{
		std::swap(arr[i], arr[n - 1 - i]);
	}
	print_array(arr, n);
}
int* merge(int* arr1, int l1, int* arr2, int l2)
{
	if (arr1 == nullptr || arr2 == nullptr)
	{
		return nullptr;
	}
	if (l1 < 1 || l2 < 1)
	{
		return nullptr;
	}
	int* arr3 = new int[l1 + l2];
	int i = 0, j = 0, k = 0;
	while (i < l1 && j < l2)
	{
		if (arr1[i] < arr2[j])
		{
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		else
		{
			arr3[k] = arr2[j];
			j++;
			k++;
		}
	}
	while (j < l2)
	{
		arr3[k] = arr2[j];
		j++;
		k++;
	}
	while (i < l1)
	{
		arr3[k] = arr1[i];
		i++;
		k++;
	}
	return arr3;
}

//функции с двумерными массивами

void print_matrix(int** matrix, int num_line, int num_columns)
{
	std::cout << "\n";
	for (int i = 0; i < num_line; ++i)
	{
		for (int j = 0; j < num_columns; ++j)
		{
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << "\n";
	}
}
void enter_num_line_columns (int& num_line, int& num_columns)
{
	std::cout << "enter num line: ";
	std::cin >> num_line;
	std::cout << "enter num columns: ";
	std::cin >> num_columns;
}
int** din_memory_matrix(int num_line, int num_columns)
{
	int** matrix = new int* [num_line];
	for (int i = 0; i < num_line; ++i)
	{
		matrix[i] = new int[num_columns];
	}
	return matrix;
}
void input_matrix(int** matrix, int num_line, int num_columns)
{
	std::cout << "\n";
	for (int i = 0; i < num_line; ++i)
	{
		std::cout << "enter " << i+1 << " line of matrix: \n";
		for (int j = 0; j < num_columns; ++j)
		{
			std::cin >> matrix[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "original matrix: ";
	print_matrix(matrix, num_line, num_columns);
}
int** negotiv_to_zero(int** matrix, int num_line, int num_columns)
{
	for (int i = 0; i < num_line; ++i)
	{
		for (int j = 0; j < num_columns; ++j)
		{
			if (matrix[i][j] < 0)
			{
				matrix[i][j] = 0;
			}
		}
	}
	std::cout << "final matrix: ";
	print_matrix(matrix, num_line, num_columns);
	return matrix;
}
int** num3(int** matrix, int num_line, int num_columns)
{
	for (int i = 0; i < num_line; ++i)
	{
		for (int j = 0; j < num_columns; ++j)
		{
			if (i >= j)
			{
				matrix[i][j] = i;
			}
			else
			{
				matrix[i][j] = j;
			}
		}
	}
	print_matrix(matrix, num_line, num_columns);
	return matrix;
}
int** swap_line(int** matrix, int num_line, int num_columns)
{
	int k = 0;
	std::cout << "Enter the line number you want to change with the first line: ";
	std::cin >> k;
	for (int j = 0; j < num_columns && k>0; ++j)
	{
		int x = matrix[0][j];
		matrix[0][j] = matrix[k - 1][j];
		matrix[k - 1][j] = x;
	}
	print_matrix(matrix, num_line, num_columns);
	return matrix;
}
int num8(int** matrix, int num)
{
	int num_negotiv = 0;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			if (matrix[i][j] < 0) {
				++num_negotiv;
			}
		}
	}
	std::cout << "the number of positive elements in the lower diagonal of the square matrix: " << num_negotiv;
	return num_negotiv;
}
void enter_num_sq_mat(int& num)
{
	std::cout << "enter num line in square matrix: ";
	std::cin >> num;
}
int** arithmetic_square(int** square, int num)
{
	for (int j = 0; j < num; ++j)
	{
		square[0][j] = 1;
	}
	for (int i = 0; i < num; ++i)
	{
		square[i][0] = 1;
	}
	for (int i = 1; i < num; ++i)
	{
		for (int j = 1; j < num; ++j)
		{
			square[i][j] = square[i - 1][j] + square[i][j - 1];
		}
	}
	print_matrix(square, num, num);
	return square;
}
//------------------------------------------------------------------------------------------>
void bubble_sort(int** a, int n, int m)
{
	bool swaped;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			swaped = false;
			for (int k = 0; k < m - 1 - j; ++k)
			{
				if (a[i][k] > a[i][k + 1])
				{
					std::swap(a[i][k], a[i][k + 1]);
					swaped = true;
				}
			}
			if (!swaped) break;
		}
	}
	std::cout << "sorted matrix:";
	print_matrix(a, n, m);
}












//------------------------------------------------------------------------------------------>
void sumElArr(int* arr, int n, int& sum)
{
	if (n == 0)
	{
		std::cout << sum;
		return;
	}
	sum = sum + arr[n-1];
	n = n - 1;
	sumElArr(arr, n , sum);
}
int main()
{
	/*
	int num;
	std::cout << "enter nember = ";  std::cin >> num;
	count_digets(num);
	std::cout << num << "\n";
	
	начало работы с одномерными массивами 

	const int odd_n = 5;
	int odd_array[odd_n];
	array_input(odd_array, odd_n);
	std::cout << "2 element: " << odd_array[1];
	revers_array(odd_array, odd_n);
	std::cout << "2 element: " << odd_array[1];

	const int even_n = 5;
	int even_array[even_n];
	array_input(even_array, even_n);
	int n = odd_n + even_n;
	print_array(merge(odd_array, odd_n, even_array, even_n),n);

	начало работы с матрицами

	int l2 = 0, c2 = 0;
	enter_num_line_columns(l2, c2);
	int** matrix = din_memory_matrix(l2, c2);
	input_matrix(matrix, l2, c2);
	negotiv_to_zero(matrix, l2, c2);

	int l2 = 0, c2 = 0;
	enter_num_line_columns(l2, c2);
	int** matrix = din_memory_matrix(l2, c2);
	input_matrix(matrix, l2, c2);
	swap_line(matrix, l2, c2);
	delete[] matrix;

	int n = 0;
	enter_num_sq_mat(n);
	int** sq_mat = din_memory_matrix(n, n);
	input_matrix(sq_mat, n, n);
	num8(sq_mat, n);
	delete[] sq_mat;

	int n = 0;
	enter_num_sq_mat(n);
	int** ar_sq = din_memory_matrix(n, n);
	arithmetic_square(ar_sq, n);
	delete[] ar_sq;

	std::cout << "enter a string consisting only of 0 and 1:\n";
	std::string s;
	getline(std::cin, s);
	int n = s.size();
	std::cout<<"p = "<<first_prime_factor(n);*/



	/*int array[1000];
	int count[101]{};
	int size; std::cin >> size;
	for (int i = 0; i < size; ++i)
	{
		++count[array[i]];
	}
	int k = 0;
	for (int i = 0; i < 101; ++i)
	{
		while (count[i] != 0)
		{
			array[k] = i;
			++k;
			--count[i];
		}
	}
	bool swaped;
	for (int i = 0; i < size - 1; ++i)
	{
		swaped = false;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				swaped = true;
			}
		}
		if (!swaped) break;
	}
	for (int i = 1; i < size; ++i)
	{
		int x = array[i];
		for (int j = i - 1; j > 0 && array[j] > x; --j)
		{
			array[j + 1] = array[j];
			array[j] = x;
		}
	}
	int n = 0, m = 0;
	enter_num_line_columns(n,m);
	int** mat = din_memory_matrix(n, m);
	input_matrix(mat, n, m);
	bool yb;
	std::cout << "How would you like to sort? (Enter 1 if descending, 0 if ascending)";
	//тут будет свич
	bubble_sort(mat, n, m);*/
/*int a = 10, b = 100;
std::cout << ((a == b) ? "not" : "yes");
int c[] = { 0,1,2,3,4 };
for (int* x = c + 4; x >= c; x--) std::cout << *x;
*/
int n = 5;
int* ab = new int[n];
array_input(ab, n);
int sum = 0;
sumElArr(ab, n, sum);
srand(time(NULL));
int p = 2+rand()%27;
std::cout << " " << p << "\n";
int num = 2;
int** matrix = new int* [num];
int col = 4, y = 1;
for (int i = 0; i < num; ++i)
{
	matrix[i] = new int[col*y];
	++y;
}
for (int j = 0; j < col; ++j)
{
	std::cout << "input a num:";
	std::cin>>matrix[0][j];
}
for (int j = 0, k = 0; j < col * y && k < col; j += 2, ++k) 
{
	matrix[1][j] = matrix[0][k] - 1;
	matrix[1][j+1] = matrix[0][k] - 1;
}
y = 1;
for (int i = 0; i < num; ++i)
{
	for (int j = 0; j < col * y; ++j)
	{
		std::cout << matrix[i][j]<<" ";
	}
	std::cout << "\n";
	++y;
}
return 0;
}