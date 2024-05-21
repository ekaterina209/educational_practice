#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#pragma once


/*����������� ���������� � ������� ��� �� ������*/

//������������ �����
int findMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//������� ��� ������� �������
void countSort(std::vector<int>& arr, int exp) {
    const size_t n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // ������� ���������� ��������� ������ ����� (0-9)
    for (size_t i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    //����� ����� �������� count ����� ���������� ������� �� ������� ������ ���� ������� ������� � i ��������
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // ������ �������� ������
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // �������� ��������������� ������ � ��������
    for (size_t i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// �������� �������
void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    //�������� �������
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}


/*���������� ���������*/

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // ���������� �������� arr[0..i-1], ������� ������ ��� key, �� ���� ������� ������ �� ������� �������
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*���������� ���������*/

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // ����� ���������� arr[j] � arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // ���� ���������� ���� �� ������ �� ������ ������, �� ������ ��� ������������
        if (!swapped) {
            break;
        }
    }
}

/*���������� �������*/

void cocktailSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // ������ ����� �������
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // ���� �� ������� �� ���� �������, ������ ��� ������������
        if (!swapped)
            break;

        swapped = false;

        // ��������� ������� ���������� ������
        --end;

        // ������ ������ ������
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // ����������� ������� ���������� �����
        ++start;
    }
}

/*������� ���������� � ������� ��� �� ������*/

// ������� ��� ���������� ������� �� ���������� ������������ �������� ��������
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // ������� �������
    int i = low - 1; // ������ �������� ��������

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            // ����������� ������ �������� �������� � ������ �������� �������
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    // �������� ������� ������� �� ���������� �������
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ������� ������� ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // �������� ������ �������� ��������
        int pi = partition(arr, low, high);

        // ���������� ��������� ���������� �� � ����� �������� ��������
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ���������� ���������� ��� ������ � ����������� �� ���������, ������ ������� vector
void quickSort(std::vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

/*�������� ������ �� �����*/
bool isNumber(const std::string& str)
{
    for (auto s : str) {
        if (!(s >= 48 && s <= 57)) return false;
    }
    return true;
}

/*�������� ������ �� �����*/
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

// ����������� �������, ������� ���������� ��������� �����
static int GetRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10000, 10000);
    return dis(gen);
}

// �������, ������� ������� � ������� ������ ��������� �����
std::vector<int> GenerateVector(const size_t& size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = GetRandomNumber();
    }
    return vec;
}