#include <iostream>
using namespace std;

void input(int*, int);
void output(int*, int);

void insert(int*, int*, int, int);
void insertBefore(int*, int*, int, int);
void insertAfter(int*, int*, int, int);

void deletePosition(int*, int*, int);
void deleteValue(int*, int*, int);
void deleteBefore(int*, int*, int);
void deleteAfter(int*, int*, int);

void searchValue(int*, int*, int);
void searchPosition(int*, int*, int);
void searchMinimum(int*, int*);

void selectionSort(int*, int*);

int getVariant(int);
int getValue();
int getPosition();
int getElement();

void printMenu();
void printSearchMenu();
void printInsertMenu();
void printDeleteMenu();
void incorrectPosition();
void elementNotFound();
void listIsFull();

const int maxn = 15;

int main()
{
    int arrayList[maxn];
    int *list = arrayList;
    int s = 0, last = 0, v, val, pos, el;
    int* lastn = &last;
    cout << "Enter the size of your list: ";
    cin >> s;
    while (s < 0)
    {
        cout << "Incorrect initialization of array. Try again: ";
        cin >> s;
    }
    if (s > 0)
    {
        input(list, s);
    }
    last = s;
    do {
        system("CLS");
        printMenu();
        v = getVariant(6);
        switch (v) {
        case 1: 
            output(list, last);
            break;
        case 2:
            int m;
            printInsertMenu();
            m = getVariant(3);
            switch (m){
            case 1:
                val = getValue();
                pos = getPosition();
                insert(list, lastn, val, pos);
                break;
            case 2:
                val = getValue();
                el = getElement();
                insertBefore(list, lastn, val, el);
                break;
            case 3:
                val = getValue();
                el = getElement();
                insertAfter(list, lastn, val, el);
                break;
            }
            break;
        case 3:
            int d;
            printDeleteMenu();
            d = getVariant(4);
            switch (d)
            {
            case 1:
                pos = getPosition();
                deletePosition(list, lastn, pos);
                break;
            case 2:
                val = getValue();
                deleteValue(list, lastn, val);
                break;
            case 3:
                el = getElement();
                deleteBefore(list, lastn, el);
                break;
            case 4:
                el = getElement();
                deleteAfter(list, lastn, el);
                break;
            }
            break;
        case 4:
            int s;
            printSearchMenu();
            s = getVariant(3);
            switch (s)
            {
            case 1:
                val = getValue();
                searchValue(list, lastn, val);
                break;
            case 2:
                pos = getPosition();
                searchPosition(list, lastn, pos);
                break;
            case 3:
                searchMinimum(list, lastn);
                break;
            }
            break;
        case 5:
            cout << "Selection sort ended successfully!" << endl;
            selectionSort(list, lastn);
            break;
        case 6:
            break;
        }
        if (v != 1 && v != 6)
        {
            output(list, last);
        }
        system("pause");
    } while (v != 6);
    return 0;
    
}

//integer values
int getElement()
{
    int m;
    cout << "Enter element value: ";
    cin >> m;
    return m;
}
int getValue()
{
    int m;
    cout << "Enter value: ";
    cin >> m;
    return m;
}
int getPosition()
{
    int p;
    cout << "Enter position: ";
    cin >> p;
    return p;
}
int getVariant(int s)
{
    int k;
    cin >> k;
    while (k < 1 || k > s)
    {
        cout << "Incorrect input. Try again: ";
        cin >> k;
    }
    return k;
}

//Messages
void printMenu()
{
    cout << "(1: OUTPUT, 2: INSERT, 3: DELETE, 4: SEARCH, 5: SORT, 6: EXIT)" << endl;
    cout << "Select any value you want:";
}
void printSearchMenu()
{
    cout << "(1: SEARCH VALUE, 2: SEARCH POSITION, 3: SEARCH MINIMUM)" << endl;
    cout << "Which search we will use:";
}
void printInsertMenu()
{
    cout << "(1: INSERT POSITION, 2: INSERT BEFORE, 3: INSERT AFTER)" << endl;
    cout << "Which insert we will use:";
}
void printDeleteMenu()
{
    cout << "(1: DELETE POSITION, 2: DELETE VALUE, 3: DELETE BEFORE, 4: DELETE AFTER)" << endl;
    cout << "Which delete we will use:";
}
void incorrectPosition()
{
    cout << "You entered incorrect position!" << endl;
}
void elementNotFound()
{
    cout << "Element not found!" << endl;
}
void listIsFull() {;
cout << "List is already full!!!";
}

//input and output
void input(int* n, int l)
{
    cout << "Fill the list: " << endl;
    for (int i = 0; i < l; i++)
    {
        cin >> n[i];
    }
}
void output(int* n, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (i != l - 1)
            cout << "L(" << i << ")=" << n[i] << ", ";
        else
            cout << "L(" << i << ")=" << n[i];
    }
    cout << endl;
}

//insert
void insert(int* n, int* l, int m, int p)
{
    if (*l < maxn)
    {
        if (p <= *l && p >= 0)
        {
            if (p == *l)
            {
                n[p] = m;
                *l += 1;
            }
            else if (p < *l)
            {
                for (int i = *l; i > p; i--)
                {
                    n[i] = n[i - 1];
                }
                n[p] = m;
                *l += 1;
            }
        }
        else {
            incorrectPosition();
        }
    }
    else {
        listIsFull();
    }
}
void insertBefore(int* n, int* l, int m, int p)
{
    if (*l < maxn)
    {
        int pos = -1;
        for (int i = 0; i < *l; i++)
        {
            if (p == n[i])
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            for (int i = *l; i > pos; i--)
            {
                n[i] = n[i - 1];
            }
            n[pos] = m;
            *l += 1;
        }
        else
        {
            elementNotFound();
        }
    }
    else {
        listIsFull();
    }
}
void insertAfter(int* n, int* l, int m, int p)
{
    if (*l < maxn)
    {
        int pos = -1;
        for (int i = 0; i < *l; i++)
        {
            if (p == n[i])
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            *l += 1;
            for (int i = *l; i > pos + 1; i--)
            {
                n[i] = n[i - 1];
            }
            n[pos + 1] = m;
        }
        else {
            elementNotFound();
        }
    }
    else {
        listIsFull();
    }
}

//delete
void deletePosition(int* n, int* l, int p)
{

        if (p < *l && p >= 0)
        {
            if (p == *l - 1)
            {
                *l -= 1;
            }
            else if (p < *l - 1)
            {
                for (int i = p; i < *l - 1; i++)
                {
                    n[i] = n[i + 1];
                }
                *l -= 1;
            }
        }
        else {
            incorrectPosition();
        }

}
void deleteValue(int* n, int* l, int v)
{
    int pos = - 1;
    for (int i = 0; i < *l; i++)
    {
        if (v == n[i])
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        if (pos == *l - 1)
        {
            *l -= 1;
        }
        else if (pos < *l - 1)
        {
            for (int i = pos; i < *l - 1; i++)
            {
                n[i] = n[i + 1];
            }
            *l -= 1;
        }
    }
    else
    {
        elementNotFound();
    }
}
void deleteBefore(int* n, int* l, int v)
{
    int pos = 0;
    for (int i = 0; i < *l; i++)
    {
        if (v == n[i])
        {
            pos = i;
        }
    }
    if (pos != 0)
    {
            for (int i = pos - 1; i < *l - 1; i++)
            {
                n[i] = n[i + 1];
            }
            *l -= 1;
    }
    else
    {
        elementNotFound();
    }
}
void deleteAfter(int* n, int* l, int v)
{
    int pos = *l - 1;
    for (int i = 0; i < *l; i++)
    {
        if (v == n[i])
        {
            pos = i;
            break;
        }
    }
    if (pos != *l - 1)
    {
        for (int i = pos + 1; i < *l - 1; i++)
        {
            n[i] = n[i + 1];
        }
        *l -= 1;
    }
    else
    {
        elementNotFound();
    }
}

//search
void searchValue(int* n, int* l, int v)
{
    int m = -1;
    for (int i = 0; i < *l; i++)
    {
        if (v == n[i])
        {
            m = i; 
            break;
        }
    }
    if (m != -1)
    {
        cout << "Element found at index: " << m << endl;
    }
    else
    {
        elementNotFound();
    }
}
void searchPosition(int* n, int* l, int p)
{
    int el = INT16_MIN;
    if (0 <= p && p < *l)
    {
        for (int i = 0; i < *l; i++)
        {
            if (i == p)
            {
                el = n[i];
                break;
            }
        }
        cout << "Value of position " << p << ": " << el << endl;
    }
    else {
        incorrectPosition();
    }
}
void searchMinimum(int* n, int* l)
{
    int min = n[0];
    int p = 0;
    for (int i = 1; i < *l; i++)
    {
        if (n[i] < min)
        {
            min = n[i];
            p = i;
        }
    }
    cout << "Position of minimum element in list is: " << p << endl;
}

//sort
void selectionSort(int* n, int* l)
{
    for (int i = 0; i < *l - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < *l; j++)
        {
            if (n[j] < n[min])
            {
                min = j;
            }
        }
        int temp = n[i];
        n[i] = n[min];
        n[min] = temp;
    }
}