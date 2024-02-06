#include <iostream>
#include <string>
using namespace std;

// 1
// int main()
// {
//   int st_c, st_r, ed_c, ed_r;
//   cin >> st_c >> st_r >> ed_c >> ed_r;
//   if(st_c == ed_c || st_r == ed_r || (ed_c - st_c) == (ed_r - st_r) || (ed_c - st_c) == (st_r - ed_r))
//     cout << "YES" << "\n";
//   else
//     cout << "NO" << "\n";
// }

// 2
// int main()
// {
//   string str;
//   cin >> str;
//   int sum = 0;
//   for(int i = 0; i < str.length(); i++)
//   {
//     sum += str[i] - '0';
//   }
//   cout << sum << "\n";
// }

// 3
// int main()
// {
//   int v, t;
//   cin >> v;
//   cin >> t;
//   int res = v * t % 109;
//   cout << ((res < 0) ? 109 + res : res) << "\n";
// }

// 4
// int main()
// {
//   float coeff = 1, n, res = 0;
//   cin >> n;
//   for(int i = 1; i <= n; i++) {
//     res += coeff/i;
//     coeff = -coeff;
//   }
//   cout << res << endl;
// }

// 5.1

// N - общ масса
// K - масса заготовки
// M - масса детали
// int make_process(int N, int K, int M, int res) {
//   if(N < K)
//     return res;
//   int workpieces_count = N / K;
//   int details_count = K / M;
//   // printf("%d %d %d %d \n", N, workpieces_count, details_count, res);
//   return make_process((N % K) + (K % M) * workpieces_count, K, M, workpieces_count * details_count + res);
// }

// int main() {
//   int N, K, M;
//   cin >> N >> K >> M;
//   cout << make_process(N, K, M, 0) << "\n";
// }

// 5.2
// int main() {
//   int N, K, M;
//   cin >> N >> K >> M;
//   int res = 0;
//   if(K >= M) {
//     while(N >= K) {
//       res += (N / K) * (K / M);
//       N = (N % K) + (K % M) * (N / K);
//     }
//   }
//   cout << res << endl;
// }

// 6
// int main() {
//   int n, m;
//   cin >> n >> m;
//   for(int i = 0; i <= n; i++) {
//     if(i == 0)
//       cout << "\t";
//     else
//       cout << i << "\t";
//     for(int j = 1; j <= n; j++) {
//       if(i == 0)
//         cout << j << "\t";
//       else
//         cout << (i * j) % m << "\t";
//     }
//     cout << "\n";
//   }
// }

// 7
// int main() {
//   char rows[7] = {' ', '2', '3', '4', '5', '6', '7'};
//   char columns[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//   for(char row : rows) {
//     if(row == ' ') {
//       cout << "\t";
//       for(char column : columns) {
//         cout << column << "\t";
//       }
//       cout << "\n";
//     } else {
//       cout << row << "\t";
//       for(char column : columns) {
//         string num;
//         num += row;
//         num += column;
//         int res = stoi(num, 0, 16);

//         cout << (char)res << "\t";
//       }
//       cout << "\n";
//     }
//   }
// }

// 8
// int main() {
//   int day, month, year;
//   cin >> day >> month >> year;
//   int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//   if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
//     days_in_month[1] = 29;
//   day += 2;
//   if(day > days_in_month[month - 1]) {
//     day = day % days_in_month[month - 1];
//     month += 1;
//   }
//   if(month > 12) {
//     month = month % 12;
//     year += 1;
//   }
//   cout << day << " " << month << " " << year << "\n";
// }