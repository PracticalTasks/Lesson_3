#include<iostream>
#include <list>
#include<vector>

using namespace std;

//Task 1
void average(list<float>& lst)
{
	float avg{ 0 };
	for (const auto& val : lst)
	{
		avg += val;
	}
	
	lst.push_back( avg /= lst.size());	
}

//Task 2
class SquareMatrix
{
	vector <vector<float>>mtx;
	int order;
public:
	SquareMatrix(int _order) : order(_order)
	{}

	void setMatrix(vector<vector<float>> _mtx)
	{
		mtx = _mtx;
	}

	auto& getMatrix()
	{
		return mtx;
	}

	float determinant()
	{
		int det{ 0 };
		if (order < 1 || order >3)
		{
			cout << "Не верный размер матрицы!!!" << endl;
			return 0;
		}
		else if (order == 1)
			return mtx[0][0];
		else if (order == 2)
			return mtx[0][0] * mtx[1][1] - mtx[1][0] * mtx[0][1];
		else
		{
			return mtx[0][0] * mtx[1][1] * mtx[2][2] - mtx[0][0] *
				mtx[1][2] * mtx[2][1] - mtx[0][1] * mtx[1][0] *
				mtx[2][2] + mtx[0][1] * mtx[1][2] * mtx[2][0] +
				mtx[0][2] * mtx[1][0] * mtx[2][1] - mtx[0][2] *
				mtx[1][1] * mtx[2][0];
		}

	}
};

//Task 3
//template <class T>
class MyIt
{
	const int SIZE;
	int* bgn;
	int* _end;

public:
	MyIt(int* ptr, const int SZ) : SIZE(SZ)
	{
		bgn = ptr;
		_end = ptr + SZ;
	}

	int* begin()
	{
		return bgn;
	}

	int* end()
	{
		return _end;
	}
};

int main()
{
	{
		cout << "Task 1\n";
		list<float> lst{ 3.4f,2.1f,7.0f,4.0f,5.7f };
		average(lst);
		for (auto& i : lst)
			cout << i<<' ';
		cout << endl;
	}

	{
		cout << "\nTask 2\n";
		SquareMatrix sqrMatrix(3);
		vector<vector<float>> mtx{ {1,4,6},{4,76,6},{12,8,3} };
		sqrMatrix.setMatrix(mtx);
		float det{ 0 };
		det = sqrMatrix.determinant();
		cout << det << endl;
	}

	{
		cout << "\nTask 3\n";
		const int SZ = 10;
		int arr[SZ]{ 1,2,3,4,5,6,7,8,9,0 };
		MyIt myit(arr,SZ);

		for (auto& i : myit)
		{
			cout << i << ' ';
		}
		cout << endl;
	}

}