#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // === Шаг 1: создаём и заполняем файл input.txt ===
    ofstream fout("input.txt");
    if (!fout) {
        cout << "Ошибка при создании файла!" << endl;
        return 1;
    }

    // Пишем данные в файл
    // Пример: 3 операции, 4 числа: 10 + 5 - 2 * 3 = (10+5)-2=13 -> 13*3=39
    fout << "3 4\n";
    fout << "+ - *\n";
    fout << "10 5 2 3\n";
    fout.close();

    // === Шаг 2: читаем файл и обрабатываем данные ===
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    int N, M;
    fin >> N >> M;

    char ops[100];
    int nums[100];

    for (int i = 0; i < N; i++) {
        fin >> ops[i];
    }

    for (int i = 0; i < M; i++) {
        fin >> nums[i];
    }

    int res = nums[0];
    for (int i = 0; i < N; i++) {
        if (ops[i] == '+') {
            res += nums[i + 1];
        }
        else if (ops[i] == '-') {
            res -= nums[i + 1];
        }
        else if (ops[i] == '*') {
            res *= nums[i + 1];
        }
        else if (ops[i] == '/') {
            if (nums[i + 1] != 0) {
                res /= nums[i + 1];
            }
            else {
                cout << "Деление на ноль!" << endl;
                return 1;
            }
        }
        else {
            cout << "Неизвестная операция: " << ops[i] << endl;
            return 1;
        }
    }

    cout << "Результат = " << res << endl;

    return 0;
}
