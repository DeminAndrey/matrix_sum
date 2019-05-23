//программа дл€ сложени€ матриц

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

class Matrix
{
private:
    int rows; //строки матрицы
    int columns; //столбцы матрицы
    vector<vector<int>> v; //вектор дл€ хранени€ матрицы

public:
    Matrix();
    Matrix(const int& num_rows, const int& num_cols); //конструктор создающий новую матрицу
    void Reset(const int& num_rows, const int& num_cols); //метод дл€ переопределени€ матрицы
    int& At(int row, int col); //метод возвращающий ссылку на €чейку матрицы
    int At(int row, int col) const; //метод возвращающий элемент матрицы
    int GetNumRows() const; //метод возвращает количество строк матрицы
    int GetNumColumns() const; //метод возвращает количество столбцов матрицы
};

//перегружаем оператор вывода экземпл€ров класса, по завершении возвращаемс€ в поток
ostream& operator<<(ostream& stream, const Matrix& obj)
{
    for(int i=0; i<obj.GetNumRows(); ++i)
    {
        for(int j=0; j<obj.GetNumColumns(); ++j)
        {
            if(j!=obj.GetNumColumns()-1)
            {
                stream<<obj.At(i, j)<<" ";
            }
            else
            {
                stream<<obj.At(i, j);
            }
        }
        cout<<endl;
    }
    return stream;
}

//перегружаем оператор ввода матриц, по завершении возвращаемс€ в поток
istream& operator>>(istream& stream, Matrix& obj)
{
    int a, b;
    cin>>a>>b;

    obj.Reset(a, b);
    for(int i=0; i<a; ++i)
        {
            for(int j=0; j<b; ++j)
                {
                    stream>>obj.At(i, j);
                }
        }

    return stream;
}

//перегружаем оператор равно дл€ проверки равенства количество столбцов и строк обеих матриц
bool operator==(const Matrix& obj1, const Matrix& obj2)
{
    if(obj1.GetNumRows()==obj2.GetNumRows()&&obj1.GetNumColumns()==obj2.GetNumColumns())
    {
        for(int i=0; i<obj1.GetNumRows(); ++i)
        {
            for(int j=0; j<obj1.GetNumColumns(); ++j)
                {
                    if(obj1.At(i, j)!=obj2.At(i, j))
                    {
                        return false;
                    }
                }
        }
        return true;
    }
    else return false;
}

//перегружаем оператор дл€ сложени€ матриц, если количество столбцов или строк у них не одинаковое - выбрасываем исключение
Matrix operator+(const Matrix& obj1, const Matrix& obj2)
{
    if(obj1.GetNumRows()==obj2.GetNumRows()&&obj1.GetNumColumns()==obj2.GetNumColumns())
    {
        Matrix c(obj1.GetNumRows(), obj1.GetNumColumns());
        for(int i=0; i<obj1.GetNumRows(); ++i)
        {
            for(int j=0; j<obj1.GetNumColumns(); ++j)
            {
                c.At(i, j)=obj1.At(i, j)+obj2.At(i, j);
            }
        }
        return c;
    }
    else
    {
        throw invalid_argument("invalid_argument");
    }
}


int main()
{
    //создаем две матрицы
    Matrix one;
    Matrix two;

    try
    {
        //стандартный ввод матриц
        cin>>one;
        cin>>two;
    }
    catch (out_of_range& s)
    {
        cout<<s.what()<<endl;
    }

    try
    {
        //выводим в консоль результат сложени€ двух матриц
        cout<<one+two;
    }
    catch (invalid_argument& s)
    {
        cout<<s.what()<<endl;
    }

    return 0;
}



Matrix::Matrix()
{
    rows = 0;
    columns = 0;
}

Matrix::Matrix(const int& num_rows, const int& num_cols)
{
    Reset(num_rows, num_cols);
}

void Matrix::Reset(const int& num_rows, const int& num_cols)
{
    // переданный в метод номер строки или столбца меньше нул€ - выбрасываем исключение
    if(num_rows<0||num_cols<0)
    {
        throw out_of_range("out_of_range");
    }
    else
    {
        rows=num_rows;
        columns=num_cols;
        v.resize(num_rows);
        for(int i=0; i<num_rows; i++)
        {
            v[i].resize(num_cols);
        }
    }
}

int& Matrix::At(int row, int col)
{
    //если переданный в метод номер строки или столбца выходит за пределы матрицы - выбрасываем исключение
    if(row>=GetNumRows()||col>=GetNumColumns())
    {
        throw out_of_range("out_of_range");
    }
    else return v.at(row).at(col);
}

int Matrix::At(int row, int col) const
{
    if(row>=GetNumRows()||col>=GetNumColumns())
    {
        throw out_of_range("out_of_range");
    }
    else return v.at(row).at(col);
}

int Matrix::GetNumRows() const
{
    return rows;
}

int Matrix::GetNumColumns() const
{
    return columns;
}
