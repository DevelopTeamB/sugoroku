#include"GameMain.h"
#include<conio.h>
#include "size.h"

GameMain::GameMain()
{

}

bool GameMain::update()
{
	reversi.show();
	if (endCount >= 4||checkEnd())
	{
		reslut();
		cout << "�ǂ��ɂ��u���Ȃ��Ȃ�܂���"<<endl;
		cout << "����"<<blackCount<<endl;
		cout << "����" << whiteCount << endl;
		if (blackCount > whiteCount)
		{
			cout << "���̏����ł�"<< endl;
		}
		else if (blackCount < whiteCount)
		{
			cout << "���̏����ł�" << endl;
		}
		else
		{
			cout << "���������ł�" << endl;
		}
		cout << "�����L�[�������Ă�������";
		_getch();

		return false;
	}

	if (isSkip == false)
	{
		oldInputX = com.x;
		oldInputY = com.y;

		if (oldInputX != 0)
		{
			cout << "�O��̓��͂�[" << oldInputX << "," << oldInputY << "]�ł����B\n";
		}
	}
	else
	{
		cout << "����̓X�L�b�v���܂����B\n";
		cout << "�����L�[�������Ă�������";
		endCount++;
	}

	reversi.isSetUpdate(Stone::Black);

	isSkip = checkSkip();

	if (isSkip == false)
	{
		endCount = 0;
		playerInput();

		reversi.update(x - 1, y - 1, Stone::Black);
	}
	else
	{
		_getch();
	}

	system("cls");

	reversi.show();

	if (isSkip == false)
	{
		oldInputX = x;
		oldInputY = y;

		if (oldInputX != 0)
		{
			cout << "�O��̓��͂�[" << oldInputX << "," << oldInputY << "]�ł����B\n";
			cout << "�G�̔Ԃł��B" << endl;
			cout << "�����L�[�������Ă�������";
			_getch();
		}
	}
	else
	{
		cout << "�ǂ��ɂ��u���Ȃ��̂ŃX�L�b�v���܂��B"<<endl;
		cout << "�����L�[�������Ă�������";
		endCount++;
		_getch();
	}

	reversi.isSetUpdate(Stone::White);

	isSkip=com.Input(reversi.isSet,reversi.stone);

	if(isSkip==false)
	{
		endCount = 0;
		reversi.update(com.x - 1, com.y - 1, Stone::White);
	}

	system("cls");
	return true;
}

void GameMain::playerInput()
{
	cout << "���Ȃ��̔Ԃł��B\n";
	while (true)
	{
		cout << "1�`8�͈̔͂���͂��Ă�������\n";
		cout << "�c ��";
		cin >> inputX >> inputY;
		x = inputX[0] - '0';
		y = inputY[0] - '0';
		cout << "\n";
		//�΂�����͈͓̔��Ȃ��turu��break
		if ((x > 0 && x <= sizeof(reversi.stone) / sizeof(reversi.stone[0])) && (y > 0 && y <= sizeof(reversi.stone[0]) / sizeof(reversi.stone[0][0])) && inputX.length() == 1 && inputY.length() == 1)
		{
			if (reversi.isSet[x - 1][y - 1] == true)
			{
				if (reversi.stone[x - 1][y - 1] == Stone::None)
				{
					break;
				}
				else
				{
					cout << "���̏ꏊ�ɂ͂��łɐ΂��u���Ă���܂��B";
				}
			}
			else
			{
				cout << "���̏ꏊ�ɒu���܂���B";
			}
		}
		cout << "������x���͂��Ă�������\n";
	}

}

void GameMain::reslut()
{
	int count = 0;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (reversi.stone[i][j] == Stone::White)
			{
				whiteCount++;
			}
			if (reversi.stone[i][j] == Stone::Black)
			{
				blackCount++;
			}
		}
	}

}

bool GameMain::checkSkip()
{
	int count = 0;
	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (reversi.isSet[i][j] == true && reversi.stone[i][j] == Stone::None)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	return false;
	
}

bool GameMain::checkEnd()
{

	for (int i = 0; i < Wide; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if ( reversi.stone[i][j] == Stone::None)
			{
				return false;
			}
		}
	}
	return true;
}