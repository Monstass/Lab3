#include <iostream>
#include <ctime>
#include <cstdlib>

float made_of_matrix(float**, int, int);
float show_matrix(float**, int, int);
float transform_of_matrix(float**, float, float, float, float);
using namespace std;
int main()
{
    int columns, lines;
    float line_s, line_e, column_s, column_e;

    cout << "Enter the number of lines <16" << endl;
    while (1)
    {
        cin >> lines;
        if (lines < 16 && lines > 0)
        {
            break;
        }
        else
        {
            cout << "Error, try again" << endl;
        }
    }

    cout << "Enter the number of columns <21" << endl;
    while (1)
    {
        cin >> columns;
        if (columns < 21 && columns > 0)
        {
            break;
        }
        else
        {
            cout << "Error, try again" << endl;
        }
    }
    system("cls");
    float** A = new float* [lines];    // Выделение памяти
    for (int i = 0; i < lines; i++)
    {
        A[i] = new float[columns];
    }
    srand(time(NULL));
    made_of_matrix(A, lines, columns);
    show_matrix(A, lines, columns);

    while (1)
    {
        cout << endl << "Enter the start of the line spacing..." << endl;
        cin >> line_s;
        if (line_s <= lines && line_s > 0)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    while (1)
    {
        cout << endl << "Enter the end of the line spacing..." << endl;
        cin >> line_e;
        if (line_e <= lines && line_e > 0 && line_e >= line_s)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    while (1)
    {
        cout << endl << "Enter the start of the columns spacing..." << endl;
        cin >> column_s;
        if (column_s <= columns && column_s > 0)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }

    while (1)
    {
        cout << endl << "Enter the end of the line spacing..." << endl;
        cin >> column_e;
        if (column_e <= columns && column_e > 0 && column_e >= column_s)
        {
            break;
        }
        else
        {
            cout << "Error" << endl;
        }
    }
    system("cls");

    transform_of_matrix(A, line_s, line_e, column_s, column_e);

    for (int i = 0; i < lines; i++)
        delete[] A[i];
    delete[] A;
    return 0;
}

float made_of_matrix(float** array, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = rand() % 10;
        }
    }
    return 0;
}

float show_matrix(float** array, int lines, int columns)
{
    cout << "----Source matrix----" << endl;
    for (int i = 0; i < lines; i++)
    {
        cout << endl;
        for (int j = 0; j < columns; j++)
        {
            cout << array[i][j] << "\t";
        }
    }
    return 0;
}

float transform_of_matrix(float** array, float l_s, float l_e, float c_s, float c_e)
{
    for (int i = l_s - 1; i < l_e; i++)
    {
        cout << endl;
        for (int j = c_s - 1; j < c_e; j++)
        {
            cout << array[i][j] << "\t";
        }
    }
    return 0;
}
float mathexp(float ** array, float l_s, float l_e, float c_s, float c_e)
{
    int average, s = 0, sum = 0;
    for (int i = l_s - 1; i < l_e; i++)
    {
        for (int j = c_s - 1; j < c_e; j++)
        {
            s += 1;
            sum += array[i][j];
        }
    }
    average = sum / s;
    return (average); 
}
