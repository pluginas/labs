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
int cvadratSearch(vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return i + j;
            }
        }
    }
    return -1;

}
int main()
{



    ofstream out;
    out.open("hello.txt");
    for (unsigned cnt = 100; cnt < 1000000; cnt += 10000)
    {

        vector<int> a;
        a.resize(cnt);
        for (int i = 0; i < cnt; i++)
        {
            a[i] = i;
        }
        auto begin = chrono::steady_clock::now();
        for (int i = 0; i < 5000; i++)
        {

            unsigned seed = 1001;
            default_random_engine rng(seed);
            uniform_int_distribution<unsigned> dstr(0, 2 * cnt );
    //cout << dstr(rng) << endl;
    int k = cvadratSearch(a, dstr(rng));
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
