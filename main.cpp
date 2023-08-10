#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string> hours = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" };
	string time;
	int hour = 0;
	int minute = 0;
	int remainder = 0;
	bool oclock = false;
	bool amyes = true;
	vector<vector<string>> grid = { {"I", "T", "L", "I", "S", "A", "S", "A", "M", "P", "M"}, 
		                            {"A", "C", "Q", "U", "A", "R", "T", "E", "R", "D", "C"},
	                                {"T", "W", "E", "N", "T", "Y", "F", "I", "V", "E", "X"},
		                            {"H", "A", "L", "F", "S", "T", "E", "N", "F", "T", "O"},
		                            {"P", "A", "S", "T", "E", "R", "U", "N", "I", "N", "E"},
		                            {"O", "N", "E", "S", "I", "X", "T", "H", "R", "E", "E"},
		                            {"F", "O", "U", "R", "F", "I", "V", "E", "T", "W", "O"},
		                            {"E", "I", "G", "H", "T", "E", "L", "E", "V", "E", "N"},
		                            {"S", "E", "V", "E", "N", "T", "W", "E", "L", "V", "E"},
									{"T", "E", "N", "S", "E", "O", "C", "L", "O", "C", "K"}};
	vector<vector<bool>> gridtrue(10, vector<bool>(11, false));
	cin >> time;

	if (time.size() == 6) {
		hour = time[0] - '0';
		minute = ((time[2] - '0') * 10) + (time[3] - '0');
		if (time.substr(4, 2) == "PM") {
			if (hour < 12) {
				hour += 12;
			}
		}
		else {
			if (hour > 11) {
				return 0;
			}
		}
	}
	else {
		hour = ((time[0] - '0') * 10) + (time[1] - '0');
		minute = ((time[3] - '0') * 10) + (time[4] - '0');
		if (time.substr(5, 2) == "PM") {
			if (hour < 12) {
				hour += 12;
			}
		}
		else {
			if (hour > 11) {
				return 0;
			}
		}
	}

	if (minute < 0 || minute > 59 || hour < 1 || hour > 23) {
		return 0;
	}
	if (hour > 12 && hour < 24) {
		hour -= 12;
		amyes = false;
	}
	if (hour == 12) {
		amyes = false;
	}

	gridtrue[0][0] = true;
	gridtrue[0][1] = true;
	gridtrue[0][3] = true;
	gridtrue[0][4] = true;

	if (minute < 35) {//use past and current hour
		cout << "It is ";
		while (minute % 5 > 0) {
			remainder++;
			minute--;
		}
		if (minute == 0) {
			oclock = true;
		}
		else if (minute == 5) {
			cout << "five past ";
			gridtrue[2][6] = true;//f
			gridtrue[2][7] = true;//i
			gridtrue[2][8] = true;//v
			gridtrue[2][9] = true;//e

		}
		else if (minute == 10) {
			cout << "ten past ";
			gridtrue[3][5] = true;//t
			gridtrue[3][6] = true;//e
			gridtrue[3][7] = true;//n

		}
		else if (minute == 15) {
			cout << "a quarter past ";
			gridtrue[1][0] = true;//a
			gridtrue[1][2] = true;//q
			gridtrue[1][3] = true;//u
			gridtrue[1][4] = true;//a
			gridtrue[1][5] = true;//r
			gridtrue[1][6] = true;//t
			gridtrue[1][7] = true;//e
			gridtrue[1][8] = true;//r

		}
		else if (minute == 20) {
			cout << "twenty past ";
			gridtrue[2][0] = true;//t
			gridtrue[2][1] = true;//w
			gridtrue[2][2] = true;//e
			gridtrue[2][3] = true;//n
			gridtrue[2][4] = true;//t
			gridtrue[2][5] = true;//y

		}
		else if (minute == 25) {
			cout << "twenty five past ";
			gridtrue[2][0] = true;//t
			gridtrue[2][1] = true;//w
			gridtrue[2][2] = true;//e
			gridtrue[2][3] = true;//n
			gridtrue[2][4] = true;//t
			gridtrue[2][5] = true;//y
			gridtrue[2][6] = true;//f
			gridtrue[2][7] = true;//i
			gridtrue[2][8] = true;//v
			gridtrue[2][9] = true;//e
		}
		else {
			cout << "half past ";
			gridtrue[3][0] = true;//h
			gridtrue[3][1] = true;//a
			gridtrue[3][2] = true;//l
			gridtrue[3][3] = true;//f
		}
		if (minute != 0) {
			gridtrue[4][0] = true;//p
			gridtrue[4][1] = true;//a
			gridtrue[4][2] = true;//s
			gridtrue[4][3] = true;//t
		}

	}
	else {//use to and next hour
		hour++;
		if (hour == 13) {
			hour = 1;
		}
		cout << "It is ";
		while (minute % 5 > 0) {
			remainder++;
			minute--;
		}
		if (minute == 0) {
			oclock = true;
		}
		else if (minute == 55) {
			cout << "five to ";
			gridtrue[2][6] = true;//f
			gridtrue[2][7] = true;//i
			gridtrue[2][8] = true;//v
			gridtrue[2][9] = true;//e
		}
		else if (minute == 50) {
			cout << "ten to ";
			gridtrue[3][5] = true;//t
			gridtrue[3][6] = true;//e
			gridtrue[3][7] = true;//n
		}
		else if (minute == 45) {
			cout << "a quarter to ";
			gridtrue[1][0] = true;//a
			gridtrue[1][2] = true;//q
			gridtrue[1][3] = true;//u
			gridtrue[1][4] = true;//a
			gridtrue[1][5] = true;//r
			gridtrue[1][6] = true;//t
			gridtrue[1][7] = true;//e
			gridtrue[1][8] = true;//r
		}
		else if (minute == 40) {
			cout << "twenty to ";
			gridtrue[2][0] = true;//t
			gridtrue[2][1] = true;//w
			gridtrue[2][2] = true;//e
			gridtrue[2][3] = true;//n
			gridtrue[2][4] = true;//t
			gridtrue[2][5] = true;//y
		}
		else if (minute == 35) {
			cout << "twenty five to ";
			gridtrue[2][0] = true;//t
			gridtrue[2][1] = true;//w
			gridtrue[2][2] = true;//e
			gridtrue[2][3] = true;//n
			gridtrue[2][4] = true;//t
			gridtrue[2][5] = true;//y
			gridtrue[2][6] = true;//f
			gridtrue[2][7] = true;//i
			gridtrue[2][8] = true;//v
			gridtrue[2][9] = true;//e
		}
		gridtrue[3][9] = true;
		gridtrue[3][10] = true;

	}

	cout << hours[hour];
	if (hour == 1) {
		gridtrue[5][0] = true;
		gridtrue[5][1] = true;
		gridtrue[5][2] = true;

	}
	else if (hour == 2) {
		gridtrue[6][8] = true;
		gridtrue[6][9] = true;
		gridtrue[6][10] = true;

	}
	else if (hour == 3) {
		gridtrue[5][6] = true;
		gridtrue[5][7] = true;
		gridtrue[5][8] = true;
		gridtrue[5][9] = true;
		gridtrue[5][10] = true;

	}
	else if (hour == 4) {
		gridtrue[6][0] = true;
		gridtrue[6][1] = true;
		gridtrue[6][2] = true;
		gridtrue[6][3] = true;

	}
	else if (hour == 5) {
		gridtrue[6][4] = true;
		gridtrue[6][5] = true;
		gridtrue[6][6] = true;
		gridtrue[6][7] = true;

	}
	else if (hour == 6) {
		gridtrue[5][3] = true;
		gridtrue[5][4] = true;
		gridtrue[5][5] = true;

	}
	else if (hour == 7) {
		gridtrue[8][0] = true;
		gridtrue[8][1] = true;
		gridtrue[8][2] = true;
		gridtrue[8][3] = true;
		gridtrue[8][4] = true;

	}
	else if (hour == 8) {
		gridtrue[7][0] = true;
		gridtrue[7][1] = true;
		gridtrue[7][2] = true;
		gridtrue[7][3] = true;
		gridtrue[7][4] = true;
	}
	else if (hour == 9) {
		gridtrue[4][7] = true;
		gridtrue[4][8] = true;
		gridtrue[4][9] = true;
		gridtrue[4][10] = true;

	}
	else if (hour == 10) {
		gridtrue[9][0] = true;
		gridtrue[9][1] = true;
		gridtrue[9][2] = true;

	}
	else if (hour == 11) {
		gridtrue[7][5] = true;
		gridtrue[7][6] = true;
		gridtrue[7][7] = true;
		gridtrue[7][8] = true;
		gridtrue[7][9] = true;
		gridtrue[7][10] = true;
	}
	else if (hour == 12) {
		gridtrue[8][5] = true;
		gridtrue[8][6] = true;
		gridtrue[8][7] = true;
		gridtrue[8][8] = true;
		gridtrue[8][9] = true;
		gridtrue[8][10] = true;

	}

	if (oclock) {
		cout << " o'clock";
		gridtrue[9][5] = true;//o
		gridtrue[9][6] = true;//c
		gridtrue[9][7] = true;//l
		gridtrue[9][8] = true;//o
		gridtrue[9][9] = true;//c
		gridtrue[9][10] = true;//k
	}

	cout << endl;

	if (remainder > 0) {
		cout << "plus " << remainder << " minute";
		if (remainder != 1) {
			cout << "s";
		}
		cout << endl;
	}
	if (amyes) {
		cout << "AM" << endl;
	}
	else {
		cout << "PM" << endl;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			if (gridtrue[i][j]) {
				cout << grid[i][j];
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}

	return 0;
}
