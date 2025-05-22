#include <iostream>
#include <ctime>
#include<fstream>
#include <chrono>  // measure the tile via using some functions included here
#include <algorithm>
using namespace std;
using namespace std::chrono; // for the   high_resolution_clock
const int SET_SIZE = 100;
char charList[SET_SIZE];
int removeDuplicatedChars(char arr[]);
void printList(char arr[]);
//-----------------------------------------------------------------------
void swapValues(int& left, int& right) {
    int tmp = left;
    left = right;
    right = tmp;
}

//-----------------------------------------------------------------------
int main()
{
    srand(time(nullptr));
    for (int i = 0; i < SET_SIZE; ++i) {
        charList[i] = 'A' + rand() % 26;
    }

    printList(charList);

    cout << "Sorting Array " << endl;
    auto start = high_resolution_clock::now();  //first time stamp
    sort(charList, charList + sizeof(charList));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); // second time stamp
    cout << "Sort time (in microseconds): " << duration.count() << endl;

    printList(charList);

    cout << "Removing Duplicates and Printing" << endl;
    start = high_resolution_clock::now();  //first time stamp
    removeDuplicatedChars(charList);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start); // second time stamp
    cout << "Removal + Sort time (in microseconds): " << duration.count() << endl;

    printList(charList);

}

int removeDuplicatedChars(char arr[]) {
    int firstPosition = 0;
    int nextPosition = firstPosition + 1;
    int uniqueItems = 0;

    while (nextPosition <= SET_SIZE) {
        if (arr[nextPosition] == arr[firstPosition]) {
            arr[nextPosition] = '~';
            ++nextPosition;
        }
        else {
            firstPosition = nextPosition;
            nextPosition = firstPosition + 1;
            uniqueItems++;
        }
    }

    sort(charList, charList + sizeof(charList));

    for (int i = uniqueItems - 1; i < SET_SIZE; ++i) {
        if (arr[i] == '~') {
            arr[i] = '$';
        }
    }
    
    cout << "Number of unique items: " << uniqueItems << endl;

    return uniqueItems;

}

void printList(char arr[]) {
    for (int i = 0; i < SET_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
