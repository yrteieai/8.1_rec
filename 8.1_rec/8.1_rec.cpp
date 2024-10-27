#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// Рекурсивна функція для знаходження індексу третьої крапки
int FindThirdDot(char* str, int i = 0, int dotCount = 0) {
    if (str[i] == '\0') {
        return -1; // якщо третя крапка не знайдена
    }
    if (str[i] == '.') {
        dotCount++;
        if (dotCount == 3) {
            return i; // повертаємо індекс третьої крапки
        }
    }
    return FindThirdDot(str, i + 1, dotCount); // рекурсивний виклик
}

// Рекурсивна функція для заміни кожного четвертого символу на крапку
void ReplaceEveryFourth(char* str, int i = 0) {
    if (str[i] == '\0') {
        return; // вихід з рекурсії, якщо кінець рядка
    }
    if ((i + 1) % 4 == 0) {
        str[i] = '.'; // заміна кожного четвертого символу на крапку
    }
    ReplaceEveryFourth(str, i + 1); // рекурсивний виклик
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Викликаємо функцію для знаходження індексу третьої крапки
    int thirdDotIndex = FindThirdDot(str);
    if (thirdDotIndex != -1) {
        cout << "Index of third dot: " << thirdDotIndex << endl;
    }
    else {
        cout << "The string does not contain three dots." << endl;
    }

    // Викликаємо функцію для заміни кожного четвертого символу на крапку
    ReplaceEveryFourth(str);
    cout << "Modified string: " << str << endl;

    return 0;
}
