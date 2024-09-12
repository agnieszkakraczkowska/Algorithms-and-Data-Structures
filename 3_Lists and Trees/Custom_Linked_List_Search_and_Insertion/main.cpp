#include <iostream>
#include <string>
using namespace std;

class Actor {
public:
    string name;
    long amountOfFans;

    Actor(string name, long amountOfFans) {
        this->name = name;
        this->amountOfFans = amountOfFans;
    }
};

class CustomList {
private:
    class Node {
    public:
        Actor* actor;
        Node* nextActor;
    };

    Node* firstActor;

public:
    CustomList() { this->firstActor = nullptr; }

//    void printList() {
//        Node* a = firstActor;
//        while (a != nullptr) {
//            cout << a->actor->name << " " << a->actor->amountOfFans << endl;
//            a = a->nextActor;
//        }
//    }

    ~CustomList() {
        Node* currentActor = firstActor;
        while(currentActor != nullptr) {
            Node* nextActor = currentActor->nextActor;
            delete currentActor->actor;
            delete currentActor;
            currentActor = nextActor;
        }
    }

    bool isUnique(string name, long amountOfFans) {
        Node* currentActor = firstActor;
        while(currentActor != nullptr) {
            if(currentActor->actor->name == name && currentActor->actor->amountOfFans == amountOfFans) {
                return false;
            }
            currentActor = currentActor->nextActor;
        }
        return true;
    }

    void addActor(string name, long amountOfFans) {
        if (isUnique(name, amountOfFans)) {
            Node* newNode = new Node;
            newNode->actor = new Actor(name, amountOfFans);
            newNode->nextActor = firstActor;
            this->firstActor = newNode;

            cout << "TAK" << '\n';
//            printList();
        } else {
            cout << "NIE" << '\n';
        }
    }

    void findActor(long maxAmountOfFans) {
        Node *currentNode = firstActor;
        Node *foundActor = nullptr;

        while (currentNode != nullptr) {
            if (currentNode->actor->amountOfFans <= maxAmountOfFans) {
                if (foundActor == nullptr || currentNode->actor->amountOfFans > foundActor->actor->amountOfFans ||
                    (currentNode->actor->amountOfFans == foundActor->actor->amountOfFans &&
                     currentNode->actor->name < foundActor->actor->name)) {
                    foundActor = currentNode;
                }
            }
            currentNode = currentNode->nextActor;
        }

        if (foundActor != nullptr) {
            cout << foundActor->actor->name << '\n';
            if (foundActor == firstActor) {
                firstActor = foundActor->nextActor;
                delete foundActor;
            } else {
                Node *currentNode = firstActor;
                while (currentNode->nextActor != foundActor) {
                    currentNode = currentNode->nextActor;
                }
                currentNode->nextActor = foundActor->nextActor;
                delete foundActor;
            }
        } else {
            cout << "NIE" << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    CustomList actorList;
    string numOfOperationText;
    int n, numOfOperation;
    string name;
    long amountOfFans, maxAmountOfFans;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin,numOfOperationText);
        numOfOperation = stoi(numOfOperationText);
        if (numOfOperation == 1) {
            getline(cin, name);
            cin >> amountOfFans;
            actorList.addActor(name,amountOfFans);
        } else if (numOfOperation == 2) {
            cin >> maxAmountOfFans;
            actorList.findActor(maxAmountOfFans);
        }
        cin.ignore();
    }

    return 0;
}