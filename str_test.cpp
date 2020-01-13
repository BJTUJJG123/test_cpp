/*************************************************************************
	> File Name: str_test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 26 Jul 2019 03:28:26 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
using std::vector;
#if 0
void num_uturn(void)
{
    int num = 0;
    cin >> num;
    vector<int> vec;
    while(num != 0)
    {
        int yu = num % 10;
        num = num / 10;
        vec.push_back(yu);
    }

    for(auto it = vec.begin(); it != vec.end();)// C++11
    {
        cout << *it ;
        *it = 0;
        cout << *it ;
        it++;
    }
    cout << endl;
}
#endif
template <class T>
void swap(T *a, T *b)
{
    T c = *a;
    *a = *b;
    *b = c;

}
/* 递归方法实现快速排序 */
template <class type>
void QuickSort(type *a, const int left, const int right)
{
   if(left < right)
   {
     int i = left;
     int j = right + 1;
     type pviot = a[left];
     do
     {
        do i++; while(a[i] < pviot);
        do j--; while(a[j] > pviot);
        type ai = a[i];
        type aj = a[j];
        if(i < j) swap(&a[i], &a[j]);
     }while(i < j);
     type al = a[left];
     type aj1 = a[j];
     swap(&a[left], &a[j]);

     QuickSort(a, left, j-1);
     QuickSort(a, j+1, right);
  }

}
