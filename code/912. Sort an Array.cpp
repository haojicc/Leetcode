/**
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time
complexity and with the smallest space complexity possible.
 */
#include <iostream>
#include <vector>
#define EOD INT_MIN
using namespace std;

class SolutionMergeSort {
public:
    typedef struct list{
        int key;
        int count;
        struct list *next;
    } LIST;

    vector<int> sortArray(vector<int>& nums) {
        data = nums;
        data.push_back(EOD);
        LIST *start, *temp;
        start = makeList();
        printList(start);

        start = mergeSort(start);
        printList(start);
        printRes(start, nums);
        return nums;
    }

private:
    vector<int> data;
    LIST *makeList(){
        LIST *p = NULL, *newnode;
        int i = 0;
        while (data[i] != EOD){
            newnode = (LIST *)malloc(sizeof(LIST));
            newnode->key = data[i];
            newnode->count = 0;
            newnode->next = p;
            p = newnode;
            i++;
        }
        return p;
    }

    void printList(LIST *p){
        while(p != NULL){
            printf("-<%d,%d>", p->key, p->count);
            p = p->next;
        }
        printf("\n");
    }

    void printRes(LIST *p, vector<int>& nums){
        auto item = nums.begin();
        while(p != NULL){
            *item = p->key;
            item++;
            p = p->next;
        }
        printf("\n");
    }

    LIST *mergeSort(LIST *p){
        LIST *first , *second;
        if(p == NULL) return p;
        if(p->next == NULL) return p;
        first = p;
        second = divide(first);
        first = mergeSort(first);
        second = mergeSort(second);
        p = merge(first, second);
        return p;
    }

    LIST *divide(LIST *p){
        LIST *div;
        int flag = 0;
        div = p;
        while (p->next != NULL){
            p = p->next;
            if(flag){flag = 0 ;div = div->next;}
            else{flag = 1;}
        }
        p = div->next;
        div->next = NULL;
        return p;
    }

    LIST *merge(LIST *p1, LIST *p2){
        LIST *top, *q;
        if((p1->key) < (p2->key)){
            top = q = p1;
            p1 = (p1->next);
        }
        else{
            top = q = p2;
            p2 = (p2->next);
        }
        q->count++;
        while((p1 != NULL) && (p2 != NULL)){
            if((p1->key) < (p2->key)){
                q->next = p1;
                p1 = p1->next;
                q = q->next;
            }
            else{
                q->next = p2;
                p2 = p2->next;
                q = q->next;
            }
            q->count++;
        }
        if(p1 == NULL) q->next = p2;
        else q->next = p1;
        return top;
    }
};

class SolutionHeapSort {
public:
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums, nums.size());
        return nums;
    }

private:
    void swap(int *a, int *b) {
        int temp = *b;
        *b = *a;
        *a = temp;
    }

    void max_heapify(vector<int>& nums, int start, int end) {
        // 建立父节点与子节点的index
        int dad = start;
        int son = dad * 2 + 1;
        while (son <= end) { // 控制子节点的index在堆的范围内
            if (son + 1 <= end && nums[son] < nums[son + 1])
                // 比较子节点大小，选择比较大的一个
                son++;
            if (nums[dad] > nums[son]) //如果父节点大于子节点，代表调整完毕，跳出函数
                return;
            else { //否则更新父节点与子节点的index，继续调整
                swap(&nums[dad], &nums[son]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }

    void heap_sort(vector<int>& arr, int len) {
        int i;
        // 初始化，建堆的过程，i从最后一个父节点开始调整
        for (i = len / 2 - 1; i >= 0; i--)
            max_heapify(arr, i, len - 1);
        // 开始排序过程，先将第一个元素和已排好元素前一位做交换，再调整堆的性质，直到排序完毕
        for (i = len - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            max_heapify(arr, 0, i - 1);
        }
    }
};

class SolutionQuickSort {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void swap(int *a, int *b) {
        int temp = *b;
        *b = *a;
        *a = temp;
    }

    int Partition(vector<int>& nums, int l, int r){
        int i = l, j = r + 1;
        int piovt = nums[l];

        while(true){
            while(nums[++i] <= piovt) if (i == r) break;
            while(piovt <= nums[--j]) if (j == l) break;
            if (i >= j) break;

            swap(&nums[i], &nums[j]);
        }
        swap(&nums[l], &nums[j]);
        return j;
    }

    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        int piovt = Partition(nums, l, r);
        quickSort(nums, l, piovt - 1);
        quickSort(nums, piovt + 1, r);
        return;
    }
};

int main() {
    SolutionMergeSort obj;
    SolutionHeapSort obj2;
    SolutionQuickSort obj3;

    vector<int> nums{11,13,15,17};
    vector<int> res = obj.sortArray(nums);
    vector<int> res2 = obj2.sortArray(nums);
    vector<int> res3 = obj3.sortArray(nums);


    cout << "MergeSort" << endl;
    for(auto item: res){
        cout << item << endl;
    }
    cout << "HeapSort" << endl;
    for(auto item: res2){
        cout << item << endl;
    }
    cout << "QuickSort" << endl;
    for(auto item: res3){
        cout << item << endl;
    }
}
