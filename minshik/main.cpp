#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void Sort(int* arr, int n) {
    queue<int> que[512]; // que count
    int i, j, count, num;

    for (i = 0; i < 3; i++) {  // loop count
        for (j = 0; j < n; j++) 
        {
            num = (arr[j] >> (i * 9)) & 511;
            que[num].push(arr[j]);
        }
        count = 0;
        for (j = 0; j < 512; j++) {
            while (!que[j].empty()) {
                arr[count] = que[j].front();
                que[j].pop();
                count++;
            }
        }
    }

    for (j = 0; j < n; j++) {
        if ((arr[j] >> 27) == 0) que[0].push(arr[j]); // 양수일 때
        else que[1].push(arr[j]); // 음수일 때
    }
    j = 0;

    while (!que[1].empty()) {
        arr[j] = que[1].front(); que[1].pop(); j++;
    }
    while (!que[0].empty()) {
        arr[j] = que[0].front(); que[0].pop(); j++;
    }
}
bool nextPermutation(int* a, int n) {
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i]) i -= 1; //뒤에서 앞으로 가면서 i-1>=i가 아니면 끝(1번)
    if (i <= 0) return false; //만약 마지막 순열이라면 끝난다
    int j = n - 1;
    while (a[j] <= a[i - 1]) j -= 1; //뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다(2번)
    swap(a[i - 1], a[j]); //두 수의 위치를 바꾼다 (3번)
    j = n - 1;
    while (i < j) { //i<n-1까지의 수열을 뒤집는다 (4번)
        swap(a[i], a[j]);
        i += 1; j -= 1;
    }
    return true; //다음 수열이 존재한다 true
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int arr[9];
    int num;
    for(int i = 0;i<9;i++)
    {
        cin >> arr[i];
    }
    Sort(arr, 9);
    do
    {
        num = 0;
        for (int i =0; i < 7;i++)
            num += arr[i];
        if (num == 100)
            break;
    } while (nextPermutation(arr, 9));

    for (int i = 0; i < 7; i++)
        cout << arr[i] << "\n";
    return 0;
}
