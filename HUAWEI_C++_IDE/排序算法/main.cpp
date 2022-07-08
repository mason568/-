//https://www.cnblogs.com/fnlingnzb-learner/p/9374732.html
#include<iostream>
#include"time.h"

using namespace std;


void Swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;

    return;
}

//�����������ѡȡ�ڱ���ǰ��
void QuickSort(int* h, int left, int right)
{
    if (h == NULL) return;
    if (left >= right) return;

    //��ֹ������е��¿�������Ч�ʽ���
    srand((unsigned)time(NULL));
    int len = right - left;
    int kindex = rand() % (len + 1) + left;
    Swap(h[left], h[kindex]);

    int key = h[left], i = left, j = right;
    while (i < j)
    {
        while (h[j] >= key && i < j) --j;
        if (i < j) h[i] = h[j];
        while (h[i] < key && i < j) ++i;
        if (i < j) h[j] = h[i];
    }

    h[i] = key;

    //QuickSort(&h[left],0,i-1);
    //QuickSort(&h[j+1],0,right-j-1);

    QuickSort(h, left, i - 1);
    QuickSort(h, j + 1, right);
}


//ð������
void BubbleSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;
    //i�Ǵ�����j�Ǿ����±�
    for (int i = 0; i < len - 1; ++i)
        for (int j = 0; j < len - 1 - i; ++j)
            if (h[j] < h[j + 1])
                Swap(h[j], h[j + 1]);

    return;
}

//ѡ������
void SelectionSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;

    int minindex, i, j;
    //i�Ǵ�����Ҳ���źõĸ���;j�Ǽ�����
    for (i = 0; i < len - 1; ++i)
    {
        minindex = i;
        for (j = i + 1; j < len; ++j)
        {
            if (h[j] < h[minindex]) minindex = j;
        }
        Swap(h[i], h[minindex]);
    }

    return;
}

//��������
void InsertSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;

    int i, j;
    //i�Ǵ�����Ҳ���źõĸ���;j�Ǽ�����
    for (i = 1; i < len; ++i)
        for (j = i; j > 0; --j)
            if (h[j] < h[j - 1]) Swap(h[j], h[j - 1]);
            else break;

    return;
}

//�鲢���� begin
void  MergeArray(int* arr, size_t left, size_t mid, size_t right, int* temp)
{
    if (arr == NULL) return;

    size_t i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
            continue;
        }

        temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    memcpy(&arr[left], temp, k * sizeof(int));

    return;
}

void MMergeSort(int* arr, size_t left, size_t right, int* temp)
{
    if (left < right)
    {
        size_t mid = (left + right) / 2;
        MMergeSort(arr, left, mid, temp);
        MMergeSort(arr, mid + 1, right, temp);
        MergeArray(arr, left, mid, right, temp);
    }
}

void MergeSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;
    int* temp = (int*)calloc(len, sizeof(int));
    MMergeSort(h, 0, len - 1, temp);

    memcpy(h, temp, sizeof(int) * len);

    free(temp);

    return;
}

//�鲢���� end


//ϣ������
void ShellSort(int* h, size_t len)
{
    if (h == NULL) return;
    if (len <= 1) return;

    for (int div = len / 2; div >= 1; div /= 2)
        for (int k = 0; k < div; ++k)
            for (int i = div + k; i < len; i += div)
                for (int j = i; j > k; j -= div)
                    if (h[j] < h[j - div]) Swap(h[j], h[j - div]);
                    else break;

    return;
}

//������ begin
/*
�󶥶�sort֮������Ϊ��С��������
*/
//====����=====
void AdjustHeap(int* h, int node, int len)  //----nodeΪ��Ҫ�����Ľ���ţ���0��ʼ���;lenΪ�ѳ���
{
    int index = node;
    int child = 2 * index + 1; //���ӣ���һ���ڵ���Ϊ0
    while (child < len)
    {
        //������
        if (child + 1 < len && h[child] < h[child + 1])
        {
            child++;
        }
        if (h[index] >= h[child]) break;
        Swap(h[index], h[child]);
        index = child;
        child = 2 * index + 1;
    }
}


//====����=====
void MakeHeap(int* h, int len)
{
    for (int i = len / 2; i >= 0; --i)
    {
        AdjustHeap(h, i, len);
    }
}

//====����=====
void HeapSort(int* h, int len)
{
    MakeHeap(h, len);
    for (int i = len - 1; i >= 0; --i)
    {
        Swap(h[i], h[0]);
        AdjustHeap(h, 0, i);
    }
}

//������ end

//��������

//MSD����


void print_result(const int * nums,int len) {
    
    for (int i = 0; i < len; i++)
    {
        cout<<*(nums+i)<<" ";
    }
    printf("\n");
}




int main()
{
    int A[10] = { 0 };
    srand((unsigned)time(NULL));

    printf("before:\n");
    for (int i = 0; i < 10; ++i)
    {
        A[i] = rand() % 100;
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("after:\n");
    //QuickSort(A,0,9);
    //print_result(A,10);
    BubbleSort(A,sizeof(A)/sizeof(int));
    print_result(A, 10);
    //print_result(A);
    //SelectionSort(A,sizeof(A)/sizeof(int));
    //InsertSort(A,sizeof(A)/sizeof(int));
    //MergeSort(A,sizeof(A)/sizeof(int));
    //ShellSort(A,sizeof(A)/sizeof(int));
    //HeapSort(A,sizeof(A)/sizeof(int));
    //RadixSort_LSD(A,sizeof(A)/sizeof(int));
    //RadixSort_MSD(A,sizeof(A)/sizeof(int));
    //RadixSort_LSD_Reverse(A,sizeof(A)/sizeof(int));
    //RadixSort_MSD_Reverse(A, sizeof(A) / sizeof(int));
    /*
    for (int i = 0; i < sizeof(A) / sizeof(int); ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    */
    return 0;
}