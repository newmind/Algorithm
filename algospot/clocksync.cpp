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

bool is_synced(uint32_t  arr) {
    const uint32_t all_12 = 0x0000;
    return arr == all_12;
}

void sync(int btn, uint32_t clocks, int clicks, int* min_click) {
    if (is_synced(clocks)) {
      *min_click = min(clicks, *min_click);
      return;
    }
    if (btn == button.size() || clicks > *min_click) {
      return;
    }

    for (size_t i = 0; i < 4; i++) {
        sync(btn+1, clocks, clicks+i, min_click);

        // rotate
        for (size_t j = 0; j < button[btn].size(); j++) {
            uint32_t clock_i = button[btn][j];
            uint32_t n = (clocks >> (clock_i*2)) & 3;
            n = (n + 1) & 3;
            n = n << clock_i*2;
            clocks &= ~(3<<(clock_i*2));
            clocks |= n;
        }
    }
    // 4바퀴 돌아서 원래 상태로 돌아가게 해야 함
}


int main() {
//   cin.tie(NULL);
//   ios::sync_with_stdio(false);

  int C;
  cin >> C;


  while (C--) {

    unsigned int clocks = 0; // 32 bits, 모두 12시 0x0000, 하나를 2 bits 로
    for (size_t i = 0; i < 16; i++) {
      int clock;
      cin >> clock;
      clock =  (clock / 3) & 3;
      clocks = clocks | (clock << (i*2));
    }

    int min_click = 987654321;
    sync(0, clocks, 0, &min_click);

    if (min_click == 987654321)
        min_click = -1;
    cout << min_click << endl;

    // for (size_t i = 0; i < 12; i++) {
    //     int clock;
    //     cin >> clock;
    //     bits = bits |  clock<<(i*2));
    // }
    // sync(0, arr, 0);
  }

  return 0;
}
