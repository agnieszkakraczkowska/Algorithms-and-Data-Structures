#include <iostream>
using namespace std;

string generateSurname(string aristocrats[], int index1, int index2, int index3, int index4) {
    return aristocrats[index1%1500].substr(0, 3) + aristocrats[index2%1500].substr(3,3) + aristocrats[index3%1500].substr(6,3) + aristocrats[index4%1500].substr(9,3);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int numOfAristocrats, firstGenerationStrength, n1, n2, n3, n4;
    cin >> numOfAristocrats >> firstGenerationStrength;
    string aristocrats[1500];
    int lastUpdatedIndex = 0;
    for(int i = 0; i < numOfAristocrats; i++) {
        if(i < firstGenerationStrength) {
            cin >> aristocrats[i%1500];
            lastUpdatedIndex = i%1500;
        }
        else {
            cin >> n1 >> n2 >> n3 >> n4;
            aristocrats[i%1500] = generateSurname(aristocrats, n1, n2, n3, n4);
            lastUpdatedIndex = i%1500;
        }
    }
    cout << aristocrats[lastUpdatedIndex] << endl;

    return 0;
}