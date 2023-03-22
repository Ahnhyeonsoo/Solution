#include <iostream>
#include <string>
#include <map>
#include <Windows.h> // 윈도우즈 API를 사용하기 위한 헤더 파일
using namespace std;

map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int roman_to_int(string roman) {
    int result = 0;
    int prev = 0;
    for (char c : roman) {
        int curr = roman_map[c];
        if (curr > prev) {
            result += curr - 2 * prev;
        } else {
            result += curr;
        }
        prev = curr;
    }
    return result;
}

bool is_valid_roman(string roman) {
    int count = 0;
    char prev = '\0';
    for (char c : roman) {
        if (roman_map.count(c) == 0) {
            return false;
        }
        if (c == prev) {
            count++;
            if (count >= 3) {
                return false;
            }
            if (c == 'V' || c == 'L' || c == 'D') {
                return false;
            }
        } else {
            count = 0;
            if (prev != '\0' && roman_map[c] > roman_map[prev]) {
                if (prev == 'V' || prev == 'L' || prev == 'D') {
                    return false;
                }
                if ((c == 'C' || c == 'X') && prev != 'I') {
                    return false;
                }
                if ((c == 'M' || c == 'D') && prev != 'C') {
                    return false;
                }
            }
        }
        prev = c;
    }
    return true;
}


DWORD WINAPI CheckEscape(LPVOID lpParam) {
    while (true) { 
        if (GetAsyncKeyState(VK_ESCAPE) < 0) { 
            exit(0); 
        }
        Sleep(10); 
    }
}

int main() {
    string roman; 
    cout << "로마 숫자를 입력하세요: ";
    cin >> roman; 
    
    
    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    while (true) { 
        if (is_valid_roman(roman)) { 
            int number = roman_to_int(roman); 
        } else { 
            cout << "올바르지 않은 로마 숫자입니다." << endl; 
        }
        cout << "로마 숫자를 입력하세요: ";
        cin >> roman; 
    }
    return 0; 
}