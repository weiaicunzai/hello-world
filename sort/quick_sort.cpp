#include <vector>
#include <iostream>
#include <algorithm>


void printArr(std::vector<int> &arr)
{
    for(auto n : arr)
        std::cout << n << " ";
    std::cout << std::endl;
}

int partition(std::vector<int> &arr, int low, int high, int pivot)
{
    int key = arr[pivot];
    while(low <= high)
    {
        while(arr[low] < key)
            low++;
        while(arr[high] > key)
            high--;
        
        if(low <= high)
        {
            std::swap(arr[low], arr[high]);
            //int temp = arr[low];
            //arr[low] = arr[high];
            //arr[high] = temp;
            low++;
            high--;
        }
    }
    return low;
}

void quickSort(std::vector<int> &arr, int low, int high)
{
    if(low >= high) return;
    int pivot = (low + high) / 2;
    int index = partition(arr, low, high, pivot);
    printArr(arr);
    quickSort(arr, low, index - 1);
    quickSort(arr, index, high);
}

void quickSort(std::vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}






int parition1(std::vector<int> &arr, int low, int high)
{
    int pivot_index = low;
    int key = arr[pivot_index];
    while(low <= high)
    {
        //while(arr[low] <= key)
        //cant write <= 
        //otherwise we mind sikp
        //the pivot and continue
        //move to the right
        //pivot = arr[0]
        //arr = {13, 12, 3, 4, 6, 7}
        //>= makes low stops and 7
        //> makes low stops and 13
        //which is what we want
        while(arr[low] < key)
            low++;
        
        //while(arr[high] >= key)
        while(arr[high] > key)
            high--;
        
        //if(arr[low] > arr[high])
        // we nned to stop at low = high
        // if we write code like arr[low] > arr[high]
        // the program will continue to execute
        // even when low > high
        if(low <= high)
            std::swap(arr[low++], arr[high--]);
    }
    return low;
}

void quickSort1(std::vector<int> &arr, int low, int high)
{
    // arr will always = 19
    //if(arr.size() <= 1) return;
    if(low >= high) return;
    int index = parition1(arr, low, high);
    printArr(arr);
    quickSort1(arr, low, index - 1);
    quickSort1(arr, index, high);
}

void quickSort1(std::vector<int> &arr)
{
    quickSort1(arr, 0, arr.size() - 1);
}


//quickSort has bug
//if we choose last element as pivot
//will end up both arr[low] and arr[high]
//all lagger than pivot

/* update:
  found the solution to this problem:
  change:
 //  if(low <= high)
 //     std::swap(arr[low++], arr[high--]);
  to:
       if(low >= high)
        return low;

        std::swap(arr[low++], arr[high--]);
*/

// this implementation is called 
int partition2(std::vector<int> &arr, int low, int high)
{
    //int key = arr[high];
    int key = arr[high];
    //while(low <= high)
    while(low <= high)
    {
        while(arr[low] < key)
            low++;
        while(arr[high] > key)
            high--;
        
       // if(low < high)
       //     std::swap(arr[low++], arr[high--]);      
        if(low >= high)
           return low;

        std::swap(arr[low++], arr[high--]);
    }
    return low;
}

void quickSort2(std::vector<int> &arr, int low, int high)
{
    if(low >= high) return;
    int index = partition2(arr, low, high);
    std::cout << index << std::endl;
    printArr(arr);
    quickSort2(arr, low, index - 1);
    quickSort2(arr, index, high);
}

void quickSort2(std::vector<int> &arr)
{
    quickSort2(arr, 0, arr.size() - 1);
}

int partition3(std::vector<int> &arr, int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
        }
    }
}

void quickSort3(std::vector<int> &arr, int low, int high)
{
    int index = partition3(arr, low, high);
    quickSort3(arr, low, index - 1);
    quickSort3(arr, index + 1, high);

}
void quickSort3(std::vector<int> &arr)
{
    quickSort3(arr, 0, arr.size() - 1);
}

void quickSort4(std::vector<int> &arr, int low)
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 33, 4234, 35, 66, 77, 234, 534, 53, 4545, 456, 5, 6, 87, 78};
    std::vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    quickSort2(test);
    printArr(test);
}