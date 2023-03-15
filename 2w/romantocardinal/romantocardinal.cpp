#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;

int romanToDecimal(string romanNum) {
    int decimalNum = 0;
    for (int i = 0; i < romanNum.length(); i++) {
        if (romanNum[i] == 'I') {
            if (romanNum[i + 1] == 'V' || romanNum[i + 1] == 'X') {
                decimalNum -= 1;
            }
            else {
                decimalNum += 1;
            }
        }
        else if (romanNum[i] == 'V') {
            decimalNum += 5;
        }
        else if (romanNum[i] == 'X') {
            if (romanNum[i + 1] == 'L' || romanNum[i + 1] == 'C') {
                decimalNum -= 10;
            }
            else {
                decimalNum += 10;
            }
        }
        else if (romanNum[i] == 'L') {
            decimalNum += 50;
        }
        else if (romanNum[i] == 'C') {
            if (romanNum[i + 1] == 'D' || romanNum[i + 1] == 'M') {
                decimalNum -= 100;
            }
            else {
                decimalNum += 100;
            }
        }
        else if (romanNum[i] == 'D') {
            decimalNum += 500;
        }
        else if (romanNum[i] == 'M') {
            decimalNum += 1000;
        }
    }
    return decimalNum;
}

int main() {
    string romanNum;
    int decimalNum;

    while (true) {
        cout << "�θ� ���ڸ� �Է��ϼ��� (3999 ����, �����Ϸ��� ESC): ";
        getline(cin, romanNum);

        // ESC Ű�� ������ ���
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }

        decimalNum = romanToDecimal(romanNum);

        if (decimalNum >= 4000) {
            cout << "�Էµ� ���ڰ� 3999 �����̾�� �մϴ�." << endl;
        }
        else {
            cout << romanNum << " = " << decimalNum << endl;
        }
    }

    return 0;
}