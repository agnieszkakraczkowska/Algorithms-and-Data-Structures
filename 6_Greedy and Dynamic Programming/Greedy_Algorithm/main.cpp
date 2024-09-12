#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareX(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

void setCameras(vector<pair<int,int>>& camerasVector, int size) {
    bool* covered = new bool[size]();
    for(pair<int,int> camera : camerasVector) {
        bool set = false;
        for(int k = camera.first; k < camera.second+1; k++) {
            if(!covered[k]) {
                covered[k] = true;
                set = true;
                break;
            }
        }
        if(!set) {
            cout << "NIE" << '\n';
            return;
        }
    }
    cout << "TAK" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int numOfSets, numOfCameras;
    cin >> numOfSets;
    for(int i = 0; i < numOfSets; i++) {
        cin >> numOfCameras;
        int a, b;
        vector<pair<int,int>> x;
        for(int j = 0; j < numOfCameras; j++) {
            cin >> a >> b;
            x.push_back(make_pair(a,b));
        }
        sort(x.begin(),x.end(), compareX);
        setCameras(x, numOfCameras);
    }

    return 0;
}