#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#pragma once


/*Поразрядная сортировка и функции для ее работы*/

//Максимальное число
int findMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//Функция для каждого разряда
void countSort(std::vector<int>& arr, int exp) {
    const size_t n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Считаем количество вхождений каждой цифры (0-9)
    for (size_t i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    //После этого действия count будет содеражать позицию на которую должен быть помещен элемент с i разрядом
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Строим выходной массив
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Копируем отсортированный массив в исходный
    for (size_t i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Основная функция
void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    //Проходим разряды
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}


/*Сортировка вставками*/

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Перемещаем элементы arr[0..i-1], которые больше чем key, на одну позицию вперед от текущей позиции
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*Сортировка Пузырьком*/

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значениями arr[j] и arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Если внутренний цикл не сделал ни одного обмена, то массив уже отсортирован
        if (!swapped) {
            break;
        }
    }
}

/*Сортировка Шейкера*/

void cocktailSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Если на проходе не было обменов, массив уже отсортирован
        if (!swapped)
            break;

        swapped = false;

        // Уменьшаем область сортировки справа
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Увеличиваем область сортировки слева
        ++start;
    }
}

/*Быстрая сортировка и функции для ее работы*/

// Функция для разделения массива на подмассивы относительно опорного элемента
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            // Увеличиваем индекс меньшего элемента и меняем элементы местами
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    // Помещаем опорный элемент на правильную позицию
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем подмассивы до и после опорного элемента
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Перегрузка сортировки для вызова с параметрами по умолчанию, просто передав vector
void quickSort(std::vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

/*Проверка строки на число*/
bool isNumber(const std::string& str)
{
    for (auto s : str) {
        if (!(s >= 48 && s <= 57)) return false;
    }
    return true;
}

/*Проверка строки на число*/
bool isStringIsNumber(const std::string& str) {
    std::stringstream sstr(str);
    std::string s;
    while (sstr >> s) {
        if (!isNumber(s)) {
            return false;
        }
    }
    return true;
}

// Статическая функция, которая возвращает случайное число
static int GetRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10000, 10000);
    return dis(gen);
}

// Функция, которая создает и выводит массив случайных чисел
std::vector<int> GenerateVector(const size_t& size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = GetRandomNumber();
    }
    return vec;
}