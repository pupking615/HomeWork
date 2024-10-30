#include <iostream>
#include <algorithm> // 用於 std::copy

using namespace std;

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << '\n';
}

void change_size(int*& arr, int& size) {
    int new_size = size * 2;
    int* new_arr = new int[new_size];
    int* recycler = arr;

    // 將舊陣列複製到新的更大陣列中
    copy(arr, arr + size, new_arr);

    // 初始化新元素為零
    for (int i = size; i < new_size; i++) {
        new_arr[i] = 0;
    }

    delete[] recycler;
    arr = new_arr;
    size = new_size; // 將原始的 size 變數更新為新的大小
}

// 將陣列縮小至使用的大小
void shrink_size(int*& arr, int& size, int used_size) {
    if (used_size >= size) return; // 如果 used_size >= size，則不需要縮減

    int* new_arr = new int[used_size];
    int* recycler = arr;

    // 只將使用到的元素複製到新陣列
    copy(arr, arr + used_size, new_arr);

    delete[] recycler;
    arr = new_arr;
    size = used_size; // 更新 size 為新的使用大小
}

int main() {
    int size = 50;
    int* arr = new int[size];

    // 插入初始元素
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    print_arr(arr, size); // 輸出初始陣列

    // 將陣列大小加倍
    change_size(arr, size);
    print_arr(arr, size); // 輸出加倍大小後的新陣列

    // 將陣列縮小以釋放未使用的空間
    int used_size = 3; // 假設只使用前 50 個元素
    shrink_size(arr, size, used_size);
    print_arr(arr, size); // 輸出縮小後的陣列

    // 清理
    delete[] arr;
}

