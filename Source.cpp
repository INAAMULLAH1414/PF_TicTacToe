#include<iostream>
#include<conio.h>
#define col 3
using namespace std;
bool getInputAndSetCell(char[][col], bool);
void showBoard(char[][col]);
bool rowAndColomnsame(char[][3]);
bool ifDiagonalSame(char[][col]);
void playGame(void);
int main()
{
	char ch;
	do
	{
		playGame();
		cout << "\n\nDo you want to play again...." << "\nY-Yes" << "\nN-No";
		ch = _getch();
	} 	while (ch == 'Y' || ch == 'y');
	return 0;
}


bool getInputAndSetCell(char board[][col], bool playerOne)
{
	bool error = false;
	int row, colomn;
	if (playerOne)
		cout << "\nPlayer One Turn : " << endl;
	else
		cout << "\nPlayer Two Turn : " << endl;
	do
	{
		if (error)
			cout << "\nError : This position already marked or Invalid input..\n\n";

		cout << "Enter row and colomn position seprated by space : ";
		cin >> row >> colomn;
		error = true;
	} 	while (row < 0 || colomn < 0 || board[row][colomn] != '*');

	if (playerOne)
	{
		board[row][colomn] = 'X';
		playerOne = false;
	}
	else
	{
		board[row][colomn] = 'O';
		playerOne = true;
	}
	return playerOne;

}

void showBoard(char board[][col])
{
	cout << "\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl << endl;
	}
}


bool rowAndColomnsame(char board[][col])
{
	if (board[0][0] == 'O' || board[0][0] == 'X')
	{
		if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) //ist colomn
			return true;
		//else return false;
	}
	if (board[0][1] == 'O' || board[0][1] == 'X')
	{
		if (board[0][1] == board[1][1] && board[0][1] == board[2][1]) //2nd colomn
			return true;
		//else return false;
	}
	if ((board[0][2] == 'O') || (board[0][2] == 'X'))
	{	//3rd colomn
		if ((board[0][2] == board[1][2]) && (board[0][2] == board[2][2]))
			return true;
		//else return false;
	}
	if (board[0][0] == 'O' || board[0][0] == 'X')
	{
		if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) //ist row	
			return true;
		//else return false;
	}
	if (board[1][0] == 'O' || board[1][0] == 'X')
	{
		if (board[1][0] == board[1][1] && board[1][0] == board[1][2]) //2nd row
			return true;
		//else return false;
	}
	if (board[2][0] == 'O' || board[2][0] == 'X')
	{
		if (board[2][0] == board[2][1] && board[2][0] == board[2][2]) //3rd row
			return true;
		//else return false;
	}
	else return false;
}

bool ifDiagonalSame(char board[][col])
{
	if (board[0][0] == 'O' || board[0][0] == 'X')
	{
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) //primary diagonal
			return true;
		//else return false;
	}
	if (board[0][2] == 'O' || board[0][2] == 'X')
	{
		if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) //secondary diagonal
			return true;
		//else return false;
	}
	else return false;
}





void playGame(void)
{
	int count = 0;
	bool playerOne = true, winner = false;
	char board[col][col];
	system("cls");
	cout << "\t\t\tTic-Tac-Toe Game\n\n\n";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = '*';
	showBoard(board);
	do
	{
		playerOne = getInputAndSetCell(board, playerOne);
		count++;
		showBoard(board);
		if (count > 4)
		{
			winner = ifDiagonalSame(board);
			if (!winner)
				winner = rowAndColomnsame(board);

			if (winner)
			{
				if (!playerOne)
					cout << "\nPlayer One Wins..\n";
				else
					cout << "\nPlayer Two Wins..\n";
			}
		}
	} 	while (!winner && count != 9);
	if (count == 9)
		cout << "\nGame Draw...";
}
