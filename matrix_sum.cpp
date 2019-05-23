//��������� ��� �������� ������

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
    int rows; //������ �������
    int columns; //������� �������
    vector<vector<int>> v; //������ ��� �������� �������

public:
    Matrix();
    Matrix(const int& num_rows, const int& num_cols); //����������� ��������� ����� �������
    void Reset(const int& num_rows, const int& num_cols); //����� ��� ��������������� �������
    int& At(int row, int col); //����� ������������ ������ �� ������ �������
    int At(int row, int col) const; //����� ������������ ������� �������
    int GetNumRows() const; //����� ���������� ���������� ����� �������
    int GetNumColumns() const; //����� ���������� ���������� �������� �������
};

//����������� �������� ������ ����������� ������, �� ���������� ������������ � �����
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

//����������� �������� ����� ������, �� ���������� ������������ � �����
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

//����������� �������� ����� ��� �������� ��������� ���������� �������� � ����� ����� ������
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

//����������� �������� ��� �������� ������, ���� ���������� �������� ��� ����� � ��� �� ���������� - ����������� ����������
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
    //������� ��� �������
    Matrix one;
    Matrix two;

    try
    {
        //����������� ���� ������
        cin>>one;
        cin>>two;
    }
    catch (out_of_range& s)
    {
        cout<<s.what()<<endl;
    }

    try
    {
        //������� � ������� ��������� �������� ���� ������
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
    // ���������� � ����� ����� ������ ��� ������� ������ ���� - ����������� ����������
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
    //���� ���������� � ����� ����� ������ ��� ������� ������� �� ������� ������� - ����������� ����������
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
