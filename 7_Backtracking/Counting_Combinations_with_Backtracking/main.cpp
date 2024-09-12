#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int optionsCounter;

bool compareValues(const int& a, const int& b) {
    return a > b;
}

void calculateOptions(vector<int>& values, int lastIndex, int currentSum, int max) {
    if(currentSum > max) {
        return;
    }

    if(currentSum == max) {
        optionsCounter++;
        return;
    }

    for(int i = lastIndex; i < values.size(); i++) {
        calculateOptions(values,i+1,currentSum+values.at(i),max);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    short numOfSets, numOfValues, max;
    cin >> numOfSets;
    optionsCounter = 0;
    for(int i = 0; i < numOfSets; i++) {
        cin >> numOfValues;
        vector<int> values(numOfValues);
        for(int j = 0; j < numOfValues; j++) {
            cin >> values.at(j);
        }
        cin >> max;
        sort(values.begin(),values.end(), compareValues);
        if(numOfValues != 1) {
            calculateOptions(values,0,0,max);
            cout << optionsCounter << '\n';
        }
        else if(values.at(0) == max) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
        optionsCounter = 0;
    }
    return 0;
}