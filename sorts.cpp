//сортировка выбором
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
using namespace std;

int find_smallest(int list[], int start_p, int list_len)
{
    int smallest_p = start_p;

    for (int i = start_p; i < list_len; i++)
    {
        if (list[i] < list[smallest_p])
            smallest_p = i;
    }
    return smallest_p;
}

void sel_sort(int list[], int list_len)
{
    for (int i = 0; i < list_len; i++)
    {
        int smallest_p = find_smallest(list, i, list_len);
        swap(list[i], list[smallest_p]);
    }
    return;
}

int main()
{
    int list_len;
    cout << "Введите длину массива: ";
    cin >> list_len;

    int* list = new int[list_len];
    srand(time(0));
    for (int i = 0; i < list_len; i++)
    {
        list[i] = rand();
    }
    
    auto begin = std::chrono::steady_clock::now();
    
    sel_sort(list, list_len);  
    
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";

    cout << "\n"; 
}

//сорировка вставками
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
using namespace std;

void ins_sort (int list[], int list_len)
{
    for (int i = 1; i < list_len; i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            swap(list[j], list[j + 1]);
            j--;
        }
    }
}

int main()
{
    int list_len;
    cout << "Введите длину массива: ";
    cin >> list_len;

    int* list = new int[list_len]; 
    srand(time(0));
    for (int i = 0; i < list_len; i++) 
    {
        list[i] = rand();
    }
    
    auto begin = std::chrono::steady_clock::now();
    
    ins_sort(list, list_len);
    
    cout << "\n";
    
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";

    cout << "\n";    
    return 0;
}

//сортировка слиянием
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
using namespace std;

void merge(int list[], int p, int q, int r)
{
    int i, j, k;
    int left_len = q - p + 1;
    int right_len = r - q;

    int left_list[left_len], right_list[right_len];

    for (int a = 0; a < left_len; a++)
    {
        left_list[a] = list[p + a];
    }
    for (int a = 0; a < right_len; a++)
    {
        right_list[a] = list[q + 1 + a];
    }

    i = j = 0;
    k = p;

    while (i < left_len && j < right_len)
    {
        if (left_list[i] <= right_list[j])
        {
            list[k] = left_list[i];
            i++;
        }
        else
        {
            list[k] = right_list[j];
            j++;
        }
        k++;
    }

    while (i < left_len)
    {
        list[k] = left_list[i];
        k++;
        i++;
    }

    while (j < right_len)
    {
        list[k] = right_list[j];
        k++;
        j++;
    }
}


int merge_sort(int list[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;

        merge_sort(list, p, q);
        merge_sort(list, q + 1, r);

        merge(list, p, q, r);
    }
}

int main()
{
    int list_len;
    cout << "Введите длину массива: ";
    cin >> list_len;

    int* list = new int[list_len];
    srand(time(0));
    for (int i = 0; i < list_len; i++)
    {
        list[i] = rand();
    }

    auto begin = std::chrono::steady_clock::now();

    merge_sort(list, 0, list_len - 1);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";

    cout << "\n";

    return 0;
}

//быстрая сортировка
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>
using namespace std;

int partition(int list[], int p, int r)
{
    int x = list[r];
    int i = p - 1;
    for (int j = p; j < r; ++j)
    {
        if (list[j] <= x)
        {
            i = i + 1;
            if (i >= p)
                swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[r]);
    return i + 1;
}


void quick_sort(int list[], int p, int r)
{
    if (p >= r)
        return;

    auto q = partition(list, p, r);
    quick_sort(list, p, q - 1);
    quick_sort(list, q + 1, r);
}
int main()
{
    int list_len;
    cout << "Введите длину массива: ";
    cin >> list_len;

    int* list = new int[list_len];

    srand(time(0));
    for (int i = 0; i < list_len; i++)
    {
        list[i] = rand();
    }

    auto begin = std::chrono::steady_clock::now();

    quick_sort(list, 0, list_len);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";

    cout << "\n";


    return 0;
}
//сортировка подсчетом. Я не разобралась.... Но хотя бы есть
#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <cstdlib> 
#include <chrono>
using namespace std;


int get_max(vector<int>& list)
{
    int max = list[0];
    for (int i = 1; i < list.size(); i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    return max;
}

void counting_sort(vector<int>& list, int exp)
{
    int n = list.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        count[(list[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(list[i] / exp) % 10] - 1] = list[i];
        count[(list[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        list[i] = output[i];
    }
}

void radix_sort(vector<int>& list)
{
    int max = get_max(list);
    int exp = 1;

    while (max / exp > 0)
    {
        counting_sort(list, exp);
        exp *= 10;
    }
}

int main()
{
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    vector<int> list(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        list[i] = rand();
    }

    cout << "Начало \n";

    auto begin = std::chrono::steady_clock::now();

    radix_sort(list);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";
}
//сортировка по разрядам (я ее тем более не понимаю........)
#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>
#include <chrono>
#include <cstdlib> 
using namespace std;


int get_max(vector<int>& list)
{
    int max = list[0];
    for (int i = 1; i < list.size(); i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    return max;
}

void counting_sort(vector<int>& list, int exp)
{
    int n = list.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
    {
        count[(list[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(list[i] / exp) % 10] - 1] = list[i];
        count[(list[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        list[i] = output[i];
    }
}

void radix_sort(vector<int>& list)
{
    int max = get_max(list);
    int exp = 1;

    while (max / exp > 0)
    {
        counting_sort(list, exp);
        exp *= 10;
    }
}

int main()
{
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    vector<int> list(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        list[i] = rand();
    }

    auto begin = std::chrono::steady_clock::now();

    radix_sort(list);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Время работы сортировки: " << elapsed_ms.count() << " ms\n";

    return 0;
}
