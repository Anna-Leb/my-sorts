//сортировка перебором
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
