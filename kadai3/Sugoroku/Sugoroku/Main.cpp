#include <iostream>
#include"SugorokuDll.h"


using namespace std;

void main()
{
	int squareMax;
	while (true)
	{
		cout << "�}�X����\�����Ă��������B";
		if (cin >> squareMax)
		{
			if (squareMax > 0)
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "�P�ȏ�̐�������͂��Ă��������B" << endl<<endl;
			}
		}

		else
		{
			cin.clear();
			cin.ignore();
			cout << "�P�ȏ�̐�������͂��Ă��������B"<<endl<<endl;
		}
		
	}

	CSugorokuDll sugoroku(squareMax);

	while (sugoroku.update())
	{

	}
}
