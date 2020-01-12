#include<iostream>
using namespace std;
bool win1(int array1[2][2]){
	int col = 0,row=0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (array1[i][j] == 1) {
				col++;
			}
		}
		if (col == 3) {
			cout << "value of col is 3";
			return true;
		}
		else {
			col = 0;
		}
	 }
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (array1[j][i] == 1) {
				row++;
			}
		}
		if (row == 3) {
			cout << "value of row is 3";
			return true;
		}
		else {
			row = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (array1[i][i] == 1) {
			cnt++;
		}
	}
	if (cnt == 3) {
		cout << "value of diagonal1 is 3";
		return true;
	}
	cnt = 0;
	for (int i = 0; i < 3;i++) {
		if (array1[i][2 - i] == 1) {
			cnt++;
		}
	}
	if (cnt == 3) {
		cout << "value of diagonal is 3";
		return true;
	}
	return false;
}
bool win2(int array1[2][2]) {
	int col = 0, row = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (array1[i][j] == 2) {
				col++;
			}
		}
		if (col == 3) {
			return true;
		}
		else {
			col = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (array1[j][i] == 2) {
				row++;
			}
		}
		if (row == 3) {
			return true;
		}
		else {
			row = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (array1[i][i] == 2) {
			cnt++;
		}
	}
	if (cnt == 3) {
		return true;
	}
	cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (array1[i][2 - i] == 2) {
			cnt++;
		}
	}
	if (cnt == 3) {
		return true;
	}
	return false;
}
class tictactoe {
	int array1[2][2];
public:
	tictactoe() {
		initializer();
	}
	void initializer() { // Initialization of array
		for(int i=0;i<3;i++){
			for (int j = 0; j < 3; j++) {
				array1[i][j] = 0;
			}
		}
		game(array1);
	}
	void printmatrix(int array1[2][2]){
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << array1[i][j] << " ";
			}
			cout << endl;
	  }
	} 
	void game(int array1[2][2]){
		for (int i = 0; i < 5; i++) {
			cout << "Provide Row number and column number of your input" << endl;
			int row, col;
			cin >> row >> col;
			if (array1[row][col] == 0) {
				array1[row][col] = 1;
			}
			else {
				cout << "you are disquaified" << endl;
				break;
			}
			cout << "before win1"<<endl;
			printmatrix(array1);
			if (win1(array1)) {
				cout << "you win" << endl;
				return;
			}
			int flag = 5;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (array1[j][k] == 0) {
						array1[j][k] = 2;
						flag = 4;
						break;
					}	
				}
				cout << "executed" << endl;
				if (flag == 4) {
					break;
				}
			}
			if (win2(array1)) {
				cout << "you lost" << endl;
			}
			printmatrix(array1);
		}
	}
};
int main(){
	cout<<"Hello World";
	tictactoe t;
}
