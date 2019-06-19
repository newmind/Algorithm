#include <iostream>
#include <memory>
#include <vector>

/**
 * https://algospot.com/judge/problem/read/CLOCKSYNC
 * Synchronizing Clocks
 */
using namespace std;

vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

bool is_synced(vector<int>&  arr) {
    for (size_t i = 0; i < arr.size(); i++) 
        if (arr[i] != 12) 
            return false;
    return true;    
}

void sync(int btn, vector<int>& arr, int clicks, int* min_click) {
    if (btn == button.size() || clicks > *min_click) {
        return;
    }
    if (is_synced(arr)) {
        *min_click = min(clicks, *min_click);
        return;
    }

    for (size_t i = 0; i < 4; i++) {
        sync(btn+1, arr, clicks+i, min_click);

        // rotate
        for (size_t j = 0; j < button[btn].size(); j++) {
            arr[button[btn][j]] += 3;
            if (arr[button[btn][j]] > 12)
                arr[button[btn][j]] = 3;

        }        
    }
    
}


int main() {
//   cin.tie(NULL);
//   ios::sync_with_stdio(false);

  int C;
  cin >> C;


  while (C--) {

    // int arr[16] = {0,};
    vector<int> arr(16);
    for (size_t i = 0; i < 16; i++) {
        cin >> arr[i];
    }

    int min_click = 987654321;
    sync(0, arr, 0, &min_click);

    if (min_click == 987654321) 
        min_click = -1;
    cout << min_click << endl;

    // int bits = 0; // 24 bits, 모두 12 시 (1<<24)-1
    // for (size_t i = 0; i < 12; i++) {
    //     int a;
    //     cin >> a;
    //     bits = bits | (a<<(i*2));
    // }
    // sync(0, arr, 0);    
  }

  return 0;
}
