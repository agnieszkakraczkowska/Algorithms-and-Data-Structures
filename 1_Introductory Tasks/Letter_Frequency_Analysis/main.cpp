#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> frequency(26, 0);

    char inputCharacter;

    while(cin.get(inputCharacter) && inputCharacter != '^') {
        if(inputCharacter == '^') {
            break;
        }
        if(isalpha(inputCharacter)) {
            inputCharacter = tolower(inputCharacter);
            int index = inputCharacter - 'a';
            frequency[index]++;
        }
    }

    int minFrequencyIndex = 0, maxFrequencyIndex = 0;
    int minFrequencyValue = 2000000, maxFrequencyValue = 0;
    for(int i = 0; i < 26; i++) {
        int currentValue = frequency[i];
        if(currentValue < minFrequencyValue && currentValue > 0) {
            minFrequencyValue = currentValue;
            minFrequencyIndex = i;
        }
        if(currentValue > maxFrequencyValue) {
            maxFrequencyValue = currentValue;
            maxFrequencyIndex = i;
        }
    }

    char minFrequencyLetter = minFrequencyIndex + 'a';
    char maxFrequencyLetter = maxFrequencyIndex + 'a';
    cout << maxFrequencyLetter << " " << minFrequencyLetter;

    return 0;
}