#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція для підрахунку кількості входжень '+', '-', '=' у рядку
void CountSymbols(char* str, int& plusCount, int& minusCount, int& equalCount, int i = 1)
{
    if (str[i] == '\0')  // Базовий випадок: досягли кінця рядка
        return;

    // Перевіряємо символ на індексі `i` і збільшуємо відповідний лічильник
    if (str[i] == '+')
        plusCount++;
    else if (str[i] == '-')
        minusCount++;
    else if (str[i] == '=')
        equalCount++;

    // Рекурсивний виклик для наступного символу
    CountSymbols(str, plusCount, minusCount, equalCount, i + 1);
}

// Рекурсивна функція для заміни пар "++", "--", "==" на " ***"
char* ReplacePairs(char* dest, const char* str, char* t, int i = 0)
{
    if (str[i + 1] == '\0')  // Базовий випадок: кінець рядка
    {
        *t = '\0';
        return dest;
    }

    // Перевіряємо наявність пар "++", "--", "=="
    if (str[i] == str[i + 1] && (str[i] == '+' || str[i] == '-' || str[i] == '='))
    {
        strcat(t, "***");
        return ReplacePairs(dest, str, t + 3, i + 2);  // Переміщуємось на два символи вперед
    }
    else
    {
        *t++ = str[i++];  // Копіюємо поточний символ, якщо пара не знайдена
        *t = '\0';
        return ReplacePairs(dest, str, t, i);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Підрахунок кількості символів '+', '-', '=' у рядку
    int plusCount = 0, minusCount = 0, equalCount = 0;
    CountSymbols(str, plusCount, minusCount, equalCount);

    cout << "Number of elements '+': " << plusCount << endl;
    cout << "Number of elements '-': " << minusCount << endl;
    cout << "Number of elements '=': " << equalCount << endl;

    // Заміна пар "++", "--", "==" на "***"
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = ReplacePairs(dest1, str, dest1);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
