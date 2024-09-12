#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Monkey {
public:
    char letter;
    vector<Monkey*> handles;
    int maxAmountOfHandles;
    int numOfUsedHandles;

    Monkey() {}

    Monkey(char letter, int maxAmountOfHandles) {
        this->letter = letter;
        this->maxAmountOfHandles = maxAmountOfHandles;
        this->numOfUsedHandles = 0;
    }
};

void displayTree(Monkey* monkey) {
    if (monkey == nullptr)
        return;

    cout << monkey->letter;
    for(Monkey* handle : monkey->handles) {
        displayTree(handle);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int k, n, amountOfHandles;
    char monkeyLetter;
    Monkey* firstMonkey = nullptr;
    cin >> k;
    if(k > 0) {
        for(int i = 0; i < k; i++) {
            cin >> n;
            if(n > 0) {
                queue<Monkey*> monkeyQueue;
                for(int j = 0; j < n; j++) {
                    cin >> monkeyLetter >> amountOfHandles;
                    Monkey* newMonkey = new Monkey(monkeyLetter,amountOfHandles);
                    if(j == 0) {
                        monkeyQueue.push(newMonkey);
                        firstMonkey = newMonkey;
                    }
                    else {
                        if(!monkeyQueue.empty() && monkeyQueue.front()->numOfUsedHandles < monkeyQueue.front()->maxAmountOfHandles) {
                            monkeyQueue.front()->handles.push_back(newMonkey);
                            monkeyQueue.front()->numOfUsedHandles++;
                            monkeyQueue.push(newMonkey);
                        }
                        else {
                            monkeyQueue.pop();
                            if(!monkeyQueue.empty()) {
                                monkeyQueue.front()->handles.push_back(newMonkey);
                                monkeyQueue.front()->numOfUsedHandles++;
                                monkeyQueue.push(newMonkey);
                            }
                        }
                    }
                }
                displayTree(firstMonkey);
                cout << '\n';
            }
        }
    }

    return 0;
}