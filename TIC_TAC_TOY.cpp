#include<iostream>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
string n1 = "";
string n2 = "";
int column;
char token = 'X';
bool tie= false;

void functionOne() {
    cout << "   |   |  \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |  \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |  \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "  \n";
    cout << "   |   |  \n";
}

void functionTwo() {
    int digit;
    if(token == 'X') {
        cout << n1 << " Please enter:";
        cin >> digit;
    }
    if(token == 'O') {
        cout << n2 << " Please enter:";
        cin >> digit;
    }
    if(digit == 1) {
        row = 0;
        column = 0;
    } else if(digit == 2) {
        row = 0;
        column = 1;
    } else if(digit == 3) {
        row = 0;
        column = 2;
    } else if(digit == 4) {
        row = 1;
        column = 0;
    } else if(digit == 5) {
        row = 1;
        column = 1;
    } else if(digit == 6) {
        row = 1;
        column = 2;
    } else if(digit == 7) {
        row = 2;
        column = 0;
    } else if(digit == 8) {
        row = 2;
        column = 1;
    } else if(digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << "Invalid input!" << endl;
        return;
    }

    if(space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X'; // Switch players
    } else {
        cout << "Cell already occupied! Please try again." << endl;
        functionTwo();
    }
    functionOne();
}

bool functionThree() {
    for(int i = 0; i < 3; i++) {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] && (space[i][0] == 'X' || space[i][0] == 'O'))
            return true;
        if(space[0][i] == space[1][i] && space[0][i] == space[2][i] && (space[0][i] == 'X' || space[0][i] == 'O'))
            return true;
    }
    if((space[0][0] == space[1][1] && space[0][0] == space[2][2] && (space[0][0] == 'X' || space[0][0] == 'O')) ||
       (space[0][2] == space[1][1] && space[0][2] == space[2][0] && (space[0][2] == 'X' || space[0][2] == 'O')))
        return true;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'X' && space[i][j] != 'O')
                return false;
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);
    cout << n1 << " is player 1, so she will play first." << endl;
    cout << n2 << " is player 2, so she will play second." << endl;
    while(!functionThree()) {
        functionOne();
        functionTwo();
    }
    if(token == 'X' && tie == false) {
        cout << n2 << " wins!" << endl;
    } else if(token == 'O' && tie == false) {
        cout << n1 << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
    return 0;
}

