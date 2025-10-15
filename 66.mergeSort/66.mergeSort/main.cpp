#include<iostream>
#include <vector>
using namespace std;

// 병합 정렬의 병합 단계
void merge(vector<int>& _data, vector<int>& _sorted, int start, int end)
{

   // std::cout << "병합: [" << left << ", " << right << "]" << std::endl;

    int mid = (start + end) / 2; // mid: 현재 구간의 중간 인덱스 (왼쪽/오른쪽 구간을 나누는 기준)

    int lidx = start;    // lidx: 왼쪽 부분에서 비교할 현재 인덱스 (start ~ mid)
    int ridx = mid + 1;  // ridx: 오른쪽 부분에서 비교할 현재 인덱스 (mid+1 ~ end)
    int sortidx = start;       // k: 병합 결과를 저장할 인덱스 (start ~ end)

    // 두 구간을 비교하면서 작은 값을 _sorted에 저장
    while (lidx <= mid && ridx <= end)
    {
        if (_data[lidx] <= _data[ridx])           // 왼쪽 값이 더 작거나 같으면
            _sorted[sortidx++] = _data[lidx++];      // 왼쪽 값을 결과에 저장, i와 k 증가
        else
            _sorted[sortidx++] = _data[ridx++];      // 오른쪽 값이 더 작으면 오른쪽 값을 결과에 저장, j와 k 증가
    }

    // 남은 왼쪽 구간 복사
    while (lidx <= mid)
        _sorted[sortidx++] = _data[lidx++];

    // 남은 오른쪽 구간 복사
    while (ridx <= end)
        _sorted[sortidx++] = _data[ridx++];

    // 병합 결과를 원본 데이터에 복사
    for (int i = start; i <= end; i++) _data[i] = _sorted[i];
}


void partition(vector<int>& _data,vector<int>&_sorted,int left, int right, int depth)
{
    //std::cout << std::string(depth * 2, ' ') << "partition 진입: [" << left << ", " << right << "]" << std::endl;
    int mid = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        partition(_data, _sorted, left, mid, depth + 1);
        partition(_data, _sorted, mid + 1, right, depth + 1);
        merge(_data, _sorted, left, right);
    }
    //std::cout << std::string(depth * 2, ' ') << "partition 복귀: [" << left << ", " << right << "]" << std::endl;
}

int main()
{
    vector<int> data = { 6,5,3,1,8,7,2,4 };
    vector<int> sorted;
    sorted.resize(data.size());
    partition(data, sorted, 0, data.size() - 1, 0);

    for (int i = 0; i < data.size(); i++) printf("%d\n", data[i]);
}


/*
left, right => 배열을 가리키는 인덱스 번호


left = 0, right = 7
0 < 7    TRUE
{
    mid = (0 + 7) / 2  = 3
    PARTITION(_data, _sorted, 0, 3);         // [1, 3, 5, 6]
    PARTITION(_data,sorted, 3 + 1, 7);       // [2, 4, 7, 8]
    MERGE(_data, _sorted, 0, right);         // 마지막 병합 [1, 2, 3, 4, 5, 6, 7, 8]
}


left = 0, right = 3
0 < 3   TRUE
{
    mid = (0 + 3) / 2 = 1
    PARTITION(_data, _sorted, 0, 1);        // [5, 6]
    PARTITION(_data,sorted, 1 + 1, 3);      // [1, 3]
    MERGE(_data, _sorted, 0, 3);
}


left = 0, right = 1
0 < 1   TRUE
{
    mid = (0 + 1) / 2 = 0
    PARTITION(_data, _sorted, 0, 0);        // 아무것도 안함
    PARTITION(_data,sorted, 0 + 1, 1);      // 아무것도 안함
    MERGE(_data, _sorted, 0, 1);            // left = data[0] = 6, right = data[1] = 5      =>  MERGE로 정렬하고 합침.
}

left = 0, right = 0
0 < 0   FALSE

---

2-1.
left = 4, right = 7
4 < 7   TRUE
{
    mid = (4 + 7) / 2 = 5
    PARTITION(_data, _sorted, 4, 5);        // [7, 8]
    PARTITION(_data,sorted, 5 + 1, 7);      // [2, 4]
    MERGE(_data, _sorted, 0, 3);            // 우측 마지막 병합 [2, 4, 7, 8]
}

3-1.
left = 4, right = 5
4 < 5   TRUE
{
    mid = (4 + 5) / 2 = 4
    PARTITION(_data, _sorted, 4, 4);        // 아무것도 안함
    PARTITION(_data,sorted, 4 + 1, 5);      // 아무것도 안함
    MERGE(_data, _sorted, 4, 5);            // data[4] = 8, data[5] = 7 MERGE 함수 실행.
}

3-2.
left = 6, right = 7
6 < 7   TRUE
{
    mid = (6 + 7) / 2 = 6
    PARTITION(_data, _sorted, 6, 6);        // 아무것도 안함
    PARTITION(_data,sorted, 6 + 1, 7);      // 아무것도 안함
    MERGE(_data, _sorted, 6, 7);            // data[6] = 2, data[7] = 4 MERGE 함수 실행.
}
*/