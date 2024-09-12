#include <iostream>
#include <cmath>
using namespace std;

// The implementation of P may vary with each test case
double P(int i, int j);

double findMapPeakRows(int startIndex, int endIndex, int currentColumn, int numOfColumns) {
    if(startIndex == endIndex) {
        double currentMax = -INFINITY;

        for(int j = currentColumn; j < numOfColumns; j++) {
            if(P(startIndex,j) > currentMax) {
                currentMax = P(startIndex,j);
            }
        }
        return currentMax;
    }
    int middleIndex = startIndex+(endIndex-startIndex)/2;
    double currentMax = -INFINITY;
    int currentMaxIndex = -1;
    int currentColumnIndex = currentColumn;

    for(int j = currentColumn; j < numOfColumns; j++) {
        if(P(middleIndex,j) > currentMax && P(middleIndex,j+1) < P(middleIndex,j)) {
            currentMax = P(middleIndex,j);
            currentMaxIndex = j;
            break;
        }
        currentColumnIndex = j;
    }

    if(currentMaxIndex != -1) {
        currentColumnIndex = currentMaxIndex;
    }

    if(P(middleIndex-1,currentMaxIndex) > currentMax) {
        return findMapPeakRows(startIndex,middleIndex-1,currentColumnIndex,numOfColumns);
    }
    else if(P(middleIndex+1,currentMaxIndex) > currentMax) {
        return findMapPeakRows(middleIndex+1,endIndex,currentColumnIndex,numOfColumns);
    }
    else {
        return currentMax;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int numOfRows, numOfColumns;
    cin >> numOfRows >> numOfColumns;

    if(numOfRows != 1 && numOfColumns != 1) {
        cout << (int)floor(findMapPeakRows(0,numOfRows-1,0,numOfColumns)) << '\n';
    }
    else {
        cout << (int)floor(P(numOfRows,numOfColumns)) << '\n';
    }

    return 0;
}