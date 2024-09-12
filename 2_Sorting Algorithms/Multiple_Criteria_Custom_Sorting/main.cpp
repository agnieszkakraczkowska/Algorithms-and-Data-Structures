#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string studentCode;
    float average;
    int distance;
    int birthMonth;

    Student() {}

    Student(string studentCode, float average, int distance, int birthMonth) {
        this->studentCode = studentCode;
        this->average = average;
        this->distance = distance;
        this->birthMonth = birthMonth;
    }
};

void printStudents(Student girls[], Student boys[], int n) {
    for(int i = 0; i < n; i++) {
        cout << girls[i].studentCode << " " << boys[i].studentCode << " ";
    }
}

bool compareStudents(Student student1, Student student2, char sortingOrder[]) {
    for (int i = 0; i < 3; i++) {
        switch (sortingOrder[i]) {
            case 'm':
                if (student1.birthMonth != student2.birthMonth) {
                    return student1.birthMonth < student2.birthMonth;
                }
                break; 
            case 's':
                if (student1.average != student2.average) {
                    return student1.average < student2.average;
                }
                break;
            case 'd':
                if (student1.distance != student2.distance) {
                    return student1.distance < student2.distance;
                }
                break;
        }
    }
    return false;
}

void insertSortStudents(Student students[], int n, char sortingOrder[]) {
    for (int i = 1; i < n; i++) {
        Student currentStudent = students[i];
        int j = i - 1;

        while (j >= 0 && compareStudents(students[j],currentStudent,sortingOrder)) {
            students[j+1] = students[j];
            j--;
        }

        students[j+1] = currentStudent;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    char sortingOrder[3];
    cin >> n;
    cin.ignore();
    cin >> sortingOrder[0] >> sortingOrder[1] >> sortingOrder[2];
    cin.ignore();

    Student girls[n];
    Student boys[n];
    string studentCode1, studentCode2;
    float average1, average2;
    int distance1, distance2;
    int birthMonth1, birthMonth2;

    for (int i = 0; i < n; i++) {
        cin >> studentCode1 >> average1 >> distance1 >> birthMonth1 >> studentCode2 >> average2 >> distance2 >> birthMonth2;
        cin.ignore();
        Student newGirlStudent(studentCode1,average1,distance1,birthMonth1);
        Student newBoyStudent(studentCode2,average2,distance2,birthMonth2);
        girls[i] = newGirlStudent;
        boys[i] = newBoyStudent;
    }

    insertSortStudents(girls,n,sortingOrder);
    insertSortStudents(boys,n,sortingOrder);

    printStudents(girls,boys,n);

    return 0;
}