#include <iostream>
#include <string>
#include <vector>

using namespace std;

string days_2007(int a, int b) {
  string answer = "";
  const string dayOfWeek[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  vector<int> daysOfMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
  for (int i = 1; i < daysOfMonth.size(); ++i)
    daysOfMonth[i] += daysOfMonth[i - 1];
  int totalDays = daysOfMonth[a - 1] + (b - 1);
  answer = dayOfWeek[totalDays % 7];
  return answer;
}

int main(int argc, char const *argv[]) {
  int m, d;
  cin >> m >> d;
  cout << days_2007(m, d);
  return 0;
}
