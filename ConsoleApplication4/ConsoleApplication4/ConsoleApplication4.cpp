#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    int a;
    cout << "Введите число элементов массива ( > 1000): ";
    cin >> a;

    if (a <= 1000) {
        cout << "Ошибка: число элементов должно быть больше 0!\n";
        return 1;
    }

    int* array = new int[a];
    cout << "Исходный массив:\n";
    srand(time(0));
    for (int i = 0; i < a; i++) {
        array[i] = rand() % 18;
        cout << array[i] << " ";
    }
    cout << endl;

    sort(array, array + a);

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < a; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int* array2 = new int[a];
    int* values = new int[a];
    int index = 0, cnt = 1;

    for (int i = 0; i < a - 1; i++) {
        if (array[i] == array[i + 1]) {
            cnt++;
        }
        else {
            values[index] = array[i];
            array2[index++] = cnt;
            cnt = 1;
        }
    }
    values[index] = array[a - 1];
    array2[index++] = cnt;

    cout << "\nУпаковка массива:\n";
    for (int i = 0; i < index; i++) {
        cout << "(" << values[i] << ", " << array2[i] << ") ";
    }
    cout << endl;

    int* unpackedArray = new int[a];
    int pos = 0;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < array2[i]; j++) {
            unpackedArray[pos++] = values[i];
        }
    }

    cout << "\nРаспакованный массив:\n";
    for (int i = 0; i < a; i++) {
        cout << unpackedArray[i] << " ";
    }
    cout << endl;

    bool arraysEqual = true;
    for (int i = 0; i < a; i++) {
        if (array[i] != unpackedArray[i]) {
            arraysEqual = false;
            break;
        }
    }

    if (arraysEqual) {
        cout << "\nМассивы совпадают!\n";
    }
    else {
        cout << "\nМассивы не совпадают!\n";
    }

    delete[] array;
    delete[] array2;
    delete[] values;
    delete[] unpackedArray;

    return 0;
}
