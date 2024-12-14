#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void bubbleSortByRollNo(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

void quickSortBysgpa(Student students[], int low, int high) {
    if (low < high){
        float pivot = students[high].sgpa;
        int i = low - 1;
        for (int j = low; j < high; j++){
            if (students[j].sgpa > pivot){
                i++;
                swap(students[i], students[j]);
            }
        }
        swap (students[i + 1], students[high]);
        int pi = i + 1;
        quickSortBysgpa(students, low, pi - 1);
        quickSortBysgpa(students, pi + 1, high);
    }
}

void searchBysgpa(Student students[], int n, float sgpa) {
    cout << "Students with SGPA " << sgpa;
    for(int i = 0; i < n; i++){
        if(students[i].sgpa == sgpa) {
            cout << " Roll No.: " << students[i].rollNo << " Name: " << students[i].name << " SGPA: " << students[i].sgpa << endl;
        }
    }
}

void binarySearchByName(Student students[], int n, string name) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].name == name) {
            cout << "Found: Roll No: " << students[mid].rollNo << ", Name: " << students[mid].name << ", SGPA: " << students[mid].sgpa << endl;
            return;
        }
        else if (students[mid].name < name)
            left = mid + 1;
        else
            right = mid - 1;
    }
}

int main() {
   
    Student students[15] = {
        {101, "Alice", 8.5},
        {102, "Bob", 9.0},
        {103, "Charlie", 7.5},
        {104, "David", 8.0},
        {105, "Eve", 9.5},
        {106, "Frank", 8.2},
        {107, "Grace", 9.1},
        {108, "Heidi", 7.8},
        {109, "Ivan", 8.7},
        {110, "Judy", 9.3},
        {111, "Kathy", 7.9},
        {112, "Liam", 8.6},
        {113, "Mona", 8.8},
        {114, "Noah", 9.2},
        {115, "Olivia", 8.4}
    };

    int n = 15;  

    // 1. Bubble Sort by Roll Number
    bubbleSortByRollNo(students, n);
        cout << "Sorted by Roll No:" << endl;
            for (int i = 0; i < n; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }


    // 2. Insertion Sort by Name
    insertionSortByName(students, n);
        cout << "Sorted by Name:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }
   
    // 3. Quick Sort by SGPA
    quickSortBysgpa(students, 0, n - 1);
    cout << "Sorted By SGPA: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "RollNo: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }
   
    //4. Search By SGPA
    searchBysgpa(students, n, 8.5);
   
    //5. Binary search By name
    binarySearchByName(students, n, "Alice");
   
    return 0;
   
   
}