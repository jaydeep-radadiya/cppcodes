/*
1. inbuilt sort function
2. frequency sort
3. below method
*/

void sort012(int *arr, int n) {
    int left = 0;
    int mid = 0;
    int right = n - 1;

    while (mid <= right) {
        if (arr[mid] == 0)
            swap(arr[left++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 2)
            swap(arr[right--], arr[mid]);
    }
}