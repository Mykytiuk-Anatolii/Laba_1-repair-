#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <unordered_map>
#include <climits>
using namespace std;
const int MAX_SIZE = 200;



//Завдання 1:
//9. Задано одновимірні масиви А і В розміру N. Всі додатні елементи масиву А замінити
//елементами з відповідними індексами масиву В.

void task1(int N, int A[])
{
    int B_index = 0, B[MAX_SIZE];
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter B[" << i << "]: "; cin >> B[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0)
        {
            A[i] = B[i];
            B_index++;
        }
    }

    if (B_index == 0)
    {
        printf("There is no positive numbers!");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            printf("A[%d]: %d\n", i, A[i]);
        }
    }
}

//Завдання 2:
//9. Знайти номер першого мінімального елемента серед елементів, більших Т1 і
// розташованих правіше першого елемента, рівного Т2.

void task2(int N, int A[MAX_SIZE])
{

    int B[MAX_SIZE], T1, T2, flag = 0, index_T2, buf = 1;
    cout << "Enter T1:" << endl << "T1=";
    cin >> T1;
    cout << "Enter T2:" << endl << "T2=";
    cin >> T2;
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        if (i == i)B[i] = 100;
    }
    for (int i = 0; i < N; i++)
    {
        flag++;
        if (A[i] == T2)
        {
            flag = i;
            break;
        }
    }
    cout << "Index element == T2 :  " << flag << endl;
    index_T2 = flag - 1;
    for (int i = 0; i < N; i++)
    {
        if (i == flag)break;
        else if (i != flag)
        {
            A[i] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] == buf)i++;
        else if (A[i] > T1)
        {
            B[i] = A[i];
        }
    }
    int min = B[0];
    for (int i = 0; i < N; i++)
    {
        if (B[i] < min)
        {
            min = B[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] == min)
        {
            cout << "Index_founded element= " << i;
        }
    }
}

//Завдання 3:
//9. Задано масив цілих чисел A(n), n <= 400. Розробити програму, яка знаходить
//максимальне серед тих чисел, які не повторюються.

void task3(int N, int A[])
{
    const int M_S = 400;

    using namespace std;

    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++) {
        freq[A[i]]++;
    }

    int max_val = INT_MIN;
    for (auto it : freq) {
        if (it.second == 1 && it.first > max_val) {
            max_val = it.first;
        }
    }

    if (max_val == INT_MIN) {
        cout << "All elements are repeated" << endl;
    }
    else {
        cout << "The maximum value that doesn't repeat is: " << max_val << endl;
    }

}

//Меню
int realise_functions()
{
    int function_number = 0;
    printf("Possible functions:\n   Function 1: Input/Output from console to file\n   Function 2: Input array from console + Input random numbers to array + Output array to binary file\n   Function 3: Input/Output array from file to file to console\n   Function 4: InputOutput array from file to vector to console\n");
    printf("Enter function number you want to use: ");
    scanf_s("%d", &function_number);
    system("cls");
    return function_number;
}
int realise_tasks()
{
    printf("Tasks:\n   Task 1: \n   Task 2: \n   Task 3: \n");
    int task_manager = 0;
    printf("Enter task number you want to do: ");
    scanf_s("%d", &task_manager);
    system("cls");
    return task_manager;
}
//Функції введення масивів з консолі та запис масивів в текстовий файл(текстові файли);
void output_file_for_int(int task_manager)
{
RESIZE:  int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("Please enter N > 0!\n");
        goto RESIZE;

    }
    int A[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        printf("Enter A[%d]: ", i);
        scanf_s("%d", &A[i]);
    }
    if (task_manager == 1)
    {
        task1(N, A);
    }
    else if (task_manager == 2)
    {
        task2(N, A);
    }
    else if (task_manager == 3)
    {
        task3(N, A);
    }

    ofstream MyFile("file.txt");

    for (int i = 0; i < N; i++)
    {
        MyFile << A[i] << "   ";
    }

    MyFile.close();
}
//Функції введення розміру масиву(масивів) з консолі, створення масиву(масивів) з використанням датчика випадкових чисел 
int input_arrays_size()
{
    int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    return N;
}
int* random_array_for_int( int task_manager)
{
    srand(time(0));
    int A[MAX_SIZE];
    int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 10;
        if (rand() % 2 == 1)
        {
            A[i] = -A[i];
        }
        printf("A[%d]: %d\n", i, A[i]);
    }
    if (task_manager == 1)
    {
        task1(N, A);
    }
    else if (task_manager == 2)
    {
        task2(N, A);
    }
    else if (task_manager == 3)
    {
        task3(N, A);
    }
    return A;
}
//Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
//Вхідні дані зчитаються з файлів, результати записуються в нові файли та виводиться в консоль.
void read_from_file_to_file_to_console_for_int(int task_manager)
{
    char temp_file_data[MAX_SIZE];
    int temp_index = 0;
    int* pA = new int[MAX_SIZE];
    int A_index = 0;
    ifstream MyFile;
    MyFile.open("file.txt");
    if (!MyFile.is_open()) return;
    if (MyFile.fail()) return;
    int temp = 0;
    bool negative_indicator = false;

    while (MyFile.good() && temp_index < 200)
    {
        MyFile.get(temp_file_data[temp_index]);
        temp_index++;
    }
    for (int i = 0; i < temp_index; i++)
    {
        if (temp_file_data[i] != ' ' && temp_file_data[i] != '-')
        {
            temp = temp * 10 + int(temp_file_data[i]) - 48;
        }
        else if (temp_file_data[i] == '-')
        {
            negative_indicator = true;
        }
        else
        {
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == false)
            {
                pA[A_index] = temp;
                A_index++;
                temp = 0;
            }
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == true)
            {
                pA[A_index] = -temp;
                A_index++;
                temp = 0;
                negative_indicator = false;
            }
        }
    }

    for (int i = 0; i < A_index; i++)
    {
        printf("A[%d]: %d\n", i, pA[i]);
    }
    if (task_manager == 1)
    {
        task1(A_index, pA);
    }
    else if (task_manager == 2)
    {
        task2(A_index, pA);
    }
    else if (task_manager == 3)
    {
        task3(A_index, pA);
    }
    MyFile.close();

    ofstream NewFile("newfile.txt");
    for (int i = 0; i < A_index; i++)
    {
        NewFile << pA[i] << "   ";
    }
    NewFile.close();
}
//Функцію читає дані з файлів в контейнер (vector, valarray або array) та з контейнера дані виводиться в консоль.
void read_from_file_to_container_to_console_for_int(int task_manager)
{
    char temp_file_data[MAX_SIZE];
    int temp_index = 0;
    int A[MAX_SIZE];
    int A_index = 0;
    vector<int> A_vector;
    ifstream MyFile;
    MyFile.open("file.txt");
    if (!MyFile.is_open()) return;
    if (MyFile.fail()) return;
    int temp = 0;
    bool negative_indicator = false;
    while (MyFile.good() && temp_index < 200)
    {
        MyFile.get(temp_file_data[temp_index]);
        temp_index++;
    }
    for (int i = 0; i < temp_index; i++)
    {
        if (temp_file_data[i] != ' ' && temp_file_data[i] != '-')
        {
            temp = temp * 10 + int(temp_file_data[i]) - 48;
        }
        else if (temp_file_data[i] == '-')
        {
            negative_indicator = true;
        }
        else
        {
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == false)
            {
                A_vector.push_back(temp);
                A[A_index] = temp;
                A_index++;
                temp = 0;
            }
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == true)
            {
                A_vector.push_back(-temp);
                A[A_index] = -temp;
                A_index++;
                temp = 0;
            }
        }
    }

    for (int i = 0; i < A_index; i++)
    {
        printf("A[%d]: %d\n", i, A_vector[i]);
    }

    if (task_manager == 1)
    {
        task1(A_index, A);
    }
    else if (task_manager == 2)
    {
        task2(A_index, A);
    }
    else if (task_manager == 3)
    {
        task3(A_index, A);
    }
}
int main()
{
TASK:  int task_manager = realise_tasks();
    if (task_manager > 3 || task_manager < 1)
    {
        printf("Please enter number from 1 to 3!\n");
        goto TASK;
    }
FUNK:  int function_manager = realise_functions();
    if (function_manager > 4 || function_manager < 1)
    {
        printf("Please enter number from 1 to 4!\n");
        goto FUNK;
    }
    {
        switch (function_manager)
        {
        case 1:
            output_file_for_int(task_manager);
            break;
        case 2:
            random_array_for_int(task_manager);
            break;
        case 3:
            read_from_file_to_file_to_console_for_int(task_manager);
            break;
        case 4:
            read_from_file_to_container_to_console_for_int(task_manager);
            break;
        default:
            break;
        }
    }

    string answer;
FIN:  printf("\nDo you want to do one more task? Enter 'yes' if you do, and 'no' if you don`t: ");
    cin >> answer;
    if (answer == "yes")
    {
        system("cls");
        goto TASK;
    }
    if (answer == "no")
    {
        system("cls");
        printf("Bye!");
    }
    else
    {
        system("cls");
        printf("Please enter 'yes' or 'no'\n");
        goto FIN;
    }
}
