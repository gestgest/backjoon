#include <iostream>
using namespace std;

class MyArray {
private:
    int index;
    int value;
public:
    int getIndex() { return index; }
    int getValue() { return value; }
    void setMyArray(int index, int value) { this->index = index; this->value = value; }

    bool operator < (MyArray a);
    bool operator <= (MyArray a);
};

bool MyArray::operator<(MyArray a) {
    if (this->value < a.getValue())
        return true;
    else
        return false;
}

bool MyArray::operator<=(MyArray a) {
    if (this->value <= a.getValue())
        return true;
    else
        return false;
}

class MyHeap {
public:
    MyArray* s;
    int n;
    MyHeap(int capacity) {
        this->n = 0;
        s = new MyArray[capacity + 1];
    }
    ~MyHeap() {
        delete[] s;
    }
    //함수
    void insert(MyArray array);
    //?
    MyArray min_delete();
};

void MyHeap::insert(MyArray array) {
    n++;
    int i = n;
    while (true)
    {
        if (i == 1)
        {
            s[i] = array;
            break;
        }
        else if (array < s[i / 2])
        {
            s[i] = s[i / 2];
            i /= 2;
        }
        else
        {
            s[i] = array;
            break;
        }
    }

}

MyArray MyHeap::min_delete() {
    MyArray myArray = s[1];
    int i = 1;
    s[i] = s[n];
    MyArray ppap = s[i];
    n--;
    while (true)
    {
        if (n < 2 * i)
            break;
        else if (n == 2 * i && s[2 * i] < ppap)
        {
            s[i] = s[2 * i];
            i = 2 * i;
            break;
        }
        else if (s[2 * i] < s[2 * i + 1] && s[2 * i] < ppap)
        {
            s[i] = s[2 * i];
            i = 2 * i;
        }
        else if (s[2 * i + 1] <= s[2 * i] && s[2 * i + 1] < ppap)
        {
            s[i] = s[2 * i + 1];
            i = 2 * i + 1;
        }
        else
            break;
    }
    s[i] = ppap;
    return myArray;
}


int main()
{
    int i;
    int n;
    int value;
    int number = 0;
    int before;
    cin >> n;
    int* s;
    s = new int[n];
    MyHeap heap(n);
    MyArray myArray;

    for (i = 0; i < n; i++)
    {
        cin >> value;
        myArray.setMyArray(i, value);
        heap.insert(myArray);
    }

    myArray = heap.min_delete();
    before = myArray.getValue();
    s[myArray.getIndex()] = number;

    for (i = 1; i < n; i++)
    {
        myArray = heap.min_delete();
        if (before != myArray.getValue())
        {
            number++;
            before = myArray.getValue();
        }

        s[myArray.getIndex()] = number;
    }

    for (i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }

    delete[] s;
}