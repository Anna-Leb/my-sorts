//сортировка выбором
#include <iostream>
#include <time.h>
#include <cstdlib>
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

 srand(time(NULL));  
 for (int i = 0; i < list_len; i++) 
 {
    list[i] = rand() % 100;
 }

 cout << "Массив до сортировки: " << endl;
 for (int i = 0; i < list_len; i++)
    cout << list[i] << '\t';
 cout << endl;

 sel_sort(list, list_len);

 cout << "Массив после сортировки: " << endl;
 for (int i = 0; i < list_len; i++)
    cout << list[i] << '\t';
 cout << endl;
}

//сорировка вставками
#include <iostream>
#include <time.h>
#include <cstdlib>
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

    srand(time(NULL));  
    for (int i = 0; i < list_len; i++) 
    {
        list[i] = rand() % 100;
    }
    
    cout << "Массив до сортировки: \n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    
    ins_sort(list, list_len);
    
    cout << "\n";
    
    cout << "Массив после сортировки:" << "\n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    return 0;
}

//сортировка слиянием
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void merge (int list[], int p, int q, int r)
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


int merge_sort (int list[], int p, int r)
{
    int q;
    if (p < r) 
    {
        q = (p + r)/2;
        
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

    srand(time(NULL));  
    for (int i = 0; i < list_len; i++) 
    {
        list[i] = rand() % 100;
    }
    
    cout << "Массив до сортировки: \n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    
    merge_sort(list, 0, list_len - 1);
    
    cout << "\n";
    
    cout << "Массив после сортировки:" << "\n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    return 0;
}

//быстрая сортировка
#include <iostream>
#include <time.h>
#include <cstdlib>
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

    srand(time(NULL));  
    for (int i = 0; i < list_len; i++) 
    {
        list[i] = rand() % 100;
    }
    
    cout << "Массив до сортировки: \n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    
    quick_sort(list, 0, list_len);
    
    cout << "\n";
    
    cout << "Массив после сортировки:" << "\n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    return 0;
}

//сортировка подсчетом. Я не разобралась.... Но хотя бы есть
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
using namespace std;

void count_sort(vector<int>& list, int k) 
{
    vector<int> count(k + 1, 0);

    for (int i = 0; i < list.size(); i++)
    {
        count[list[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(list.size());
    for (int i = list.size() - 1; i >= 0; i--)
    {
        output[count[list[i]] - 1] = list[i];
        count[list[i]]--;
    }

    for (int i = 0; i < list.size(); i++) 
    {
        list[i] = output[i];
    }
}

int main()
{
    int list_len;
    cout << "Введите длину массива: ";
    cin >> list_len;

    vector<int> list;

    int* list = new int[list_len];

    srand(time(NULL));
    for (int i = 0; i < list_len; i++)
    {
        list[i] = rand() % 100;
    }

    cout << "Массив до сортировки: \n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }

    int k = *max_element(list.begin(), list.end());

    count_sort(list, k);

    cout << "\n";

    cout << "Массив после сортировки:" << "\n";
    for (int i = 0; i < list_len; i++)
    {
        cout << list[i] << "\t";
    }
    return 0;
}
