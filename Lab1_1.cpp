#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

int func(vector<int> massive, int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        if (k == massive[i])
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Вычисляем средний индекс (чтобы избежать переполнения)

        if (arr[mid] == target)
        {
            return mid; // Нашли значение, возвращаем его индекс
        }
        else if (arr[mid] < target)
        {
            low = mid + 1; // Искомое значение находится в правой половине
        }
        else
        {
            high = mid - 1; // Искомое значение находится в левой половине
        }
    }

    return -1; // Значение не найдено в массиве
}
int main()
{

    // открываем файл для записи

    //int massive[N];

    ofstream out;          // поток для записи
    out.open("hello.txt");
    for (unsigned cnt = 100; cnt < 1000000; cnt += 5000)
    {

        vector<int> a;
        a.resize(cnt);
        for (int i = 0; i < cnt; i++)
        {
            a[i] = i;
        }
        auto begin = chrono::steady_clock::now();
        for (int i = 0; i < 2500; i++)
        {
            int k = func(a, cnt, cnt);
        }
        auto end = chrono::steady_clock::now();
        auto time_span = chrono::duration_cast<chrono::milliseconds>(end - begin);
        cout << time_span.count() << " " << cnt << endl;
        out << time_span.count() << " " << cnt << endl;

    }
    out.close();
    std::cout << "File has been written" << std::endl;
    //cout << collatz_conjecture_max(a);
}