#include <iostream>
using namespace std;

class Person {
private:
    string surname;
    int numberOfMinutes;

public:
    Person(string surname, int numberOfMinutes) {
        this->surname = surname;
        this->numberOfMinutes = numberOfMinutes;
    }

    string getSurname() {
        return this->surname;
    }

    int getNumberOfMinutes() {
        return this->numberOfMinutes;
    }
};

void insertSortPeopleByMinutes(Person* people[], int n, Person* newPerson) {
    people[n] = newPerson;
    int i = n;
    while (i > 0 && (people[i - 1]->getNumberOfMinutes() < newPerson->getNumberOfMinutes() ||
                     (people[i - 1]->getNumberOfMinutes() == newPerson->getNumberOfMinutes() &&
                      newPerson->getSurname().compare(people[i - 1]->getSurname()) < 0))) {
        people[i] = people[i - 1];
        i--;
    }
    people[i] = newPerson;
}


void calculateSetMinutes(Person* people[], int n) {
    long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += 1 + people[i]->getNumberOfMinutes()*i;
    }
    int total = sum%(1000000+3);
    cout << '\n' << total << endl;
}

void printPeopleArray(Person* people[], int p) {
    for(int i = 0; i < p; i++) {
        cout << people[i]->getSurname() << " ";
    }
}

void sortAndCalculateSet(int n, int p) {
    Person* people[n+1];
    string surname;
    int numberOfMinutes;
    for(int i = 0; i < n; i++) {
        cin >> surname >> numberOfMinutes;
        Person* person = new Person(surname, numberOfMinutes);
        insertSortPeopleByMinutes(people,i,person);
    }
    printPeopleArray(people,p);
    calculateSetMinutes(people,n);

    for(int i = 0; i < n; i++) {
        delete people[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, p;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> p;
        sortAndCalculateSet(n,p);
    }

    return 0;
}