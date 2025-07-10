#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <numeric>

using namespace std;

class Game {
private:
    char boardDefault[5][4];
    char boardSet[5][4];
    char boardCurrent[5][4];
    int tries;

    void gotoxy(short x, short y) {
        HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        pos.X = x - 1;
        pos.Y = y - 1;
        SetConsoleCursorPosition(hCon, pos);
    }

    void CreateBoard() {
        char row = 'A';
        cout << "\n\n\n\t\t";
        for (int j = 0; j < 4; j++) {
            cout << "\t" << j;
        }
        cout << endl << endl << "\t\t\t";
        for (int j = 0; j < 25; j++) {
            cout << "*";
        }
        cout << endl << endl;

        for (int i = 0; i < 5; i++) {
            cout << "\t" << row;
            for (int j = 0; j < 4; j++) {
                boardDefault[i][j] = '@';
                boardCurrent[i][j] = boardDefault[i][j];
                cout << "\t" << boardDefault[i][j];
            }
            cout << endl << endl;
            row++;
        }
    }

    void FillBoard() {
        char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
        vector<int> indices(20);
        iota(indices.begin(), indices.end(), 0);
        random_shuffle(indices.begin(), indices.end());

        int k = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                boardSet[i][j] = items[indices[k] / 2];
                k++;
            }
        }
    }

    void DisplayBoard() {
        char row = 'A';
        cout << "\n\n\n\t";
        for (int j = 0; j < 4; j++) {
            cout << "\t" << j;
        }
        cout << endl << endl << "\t\tA";
        for (int j = 0; j < 25; j++) {
            cout << "*";
        }
        cout << endl << endl;

        for (int i = 0; i < 5; i++) {
            cout << "\t" << row;
            for (int j = 0; j < 4; j++) {
                cout << "\t" << boardCurrent[i][j];
            }
            cout << endl << endl;
            row++;
        }
    }

    bool CheckPair(int r1, int c1, int r2, int c2) {
        return boardSet[r1][c1] == boardSet[r2][c2];
    }

    void UpdateBoard(int r1, int c1, int r2, int c2, bool match) {
        if (match) {
            boardCurrent[r1][c1] = boardSet[r1][c1];
            boardCurrent[r2][c2] = boardSet[r2][c2];
        } else {
            boardCurrent[r1][c1] = '@';
            boardCurrent[r2][c2] = '@';
        }
    }

public:
    Game() : tries(0) {
        srand(time(0));
        FillBoard();
    }

    void Play() {
        CreateBoard();
        while (true) {
            DisplayBoard();

            cout << "\nEnter the coordinates of the first cell (e.g., A0): ";
            char r1;
            int c1;
            cin >> r1 >> c1;

            cout << "Enter the coordinates of the second cell (e.g., A1): ";
            char r2;
            int c2;
            cin >> r2 >> c2;

            int row1 = r1 - 'A';
            int row2 = r2 - 'A';

            if (row1 < 0 || row1 >= 5 || row2 < 0 || row2 >= 5 || c1 < 0 || c1 >= 4 || c2 < 0 || c2 >= 4) {
                cout << "Invalid coordinates. Try again." << endl;
                continue;
            }

            boardCurrent[row1][c1] = boardSet[row1][c1];
            boardCurrent[row2][c2] = boardSet[row2][c2];
            DisplayBoard();

            if (CheckPair(row1, c1, row2, c2)) {
                cout << "It's a match!" << endl;
            } else {
                cout << "Not a match. Try again." << endl;
                UpdateBoard(row1, c1, row2, c2, false);
            }

            tries++;
            if (IsGameOver()) {
                cout << "Congratulations! You completed the game in " << tries << " tries." << endl;
                break;
            }
        }
    }

    bool IsGameOver() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (boardCurrent[i][j] == '@') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Game memoryGame;
    memoryGame.Play();
    return 0;
}
