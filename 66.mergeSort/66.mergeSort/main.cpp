#include<iostream>
#include <vector>
using namespace std;

// ���� ������ ���� �ܰ�
void merge(vector<int>& _data, vector<int>& _sorted, int start, int end)
{

   // std::cout << "����: [" << left << ", " << right << "]" << std::endl;

    int mid = (start + end) / 2; // mid: ���� ������ �߰� �ε��� (����/������ ������ ������ ����)

    int lidx = start;    // lidx: ���� �κп��� ���� ���� �ε��� (start ~ mid)
    int ridx = mid + 1;  // ridx: ������ �κп��� ���� ���� �ε��� (mid+1 ~ end)
    int sortidx = start;       // k: ���� ����� ������ �ε��� (start ~ end)

    // �� ������ ���ϸ鼭 ���� ���� _sorted�� ����
    while (lidx <= mid && ridx <= end)
    {
        if (_data[lidx] <= _data[ridx])           // ���� ���� �� �۰ų� ������
            _sorted[sortidx++] = _data[lidx++];      // ���� ���� ����� ����, i�� k ����
        else
            _sorted[sortidx++] = _data[ridx++];      // ������ ���� �� ������ ������ ���� ����� ����, j�� k ����
    }

    // ���� ���� ���� ����
    while (lidx <= mid)
        _sorted[sortidx++] = _data[lidx++];

    // ���� ������ ���� ����
    while (ridx <= end)
        _sorted[sortidx++] = _data[ridx++];

    // ���� ����� ���� �����Ϳ� ����
    for (int i = start; i <= end; i++) _data[i] = _sorted[i];
}


void partition(vector<int>& _data,vector<int>&_sorted,int left, int right, int depth)
{
    //std::cout << std::string(depth * 2, ' ') << "partition ����: [" << left << ", " << right << "]" << std::endl;
    int mid = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        partition(_data, _sorted, left, mid, depth + 1);
        partition(_data, _sorted, mid + 1, right, depth + 1);
        merge(_data, _sorted, left, right);
    }
    //std::cout << std::string(depth * 2, ' ') << "partition ����: [" << left << ", " << right << "]" << std::endl;
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
left, right => �迭�� ����Ű�� �ε��� ��ȣ


left = 0, right = 7
0 < 7    TRUE
{
    mid = (0 + 7) / 2  = 3
    PARTITION(_data, _sorted, 0, 3);         // [1, 3, 5, 6]
    PARTITION(_data,sorted, 3 + 1, 7);       // [2, 4, 7, 8]
    MERGE(_data, _sorted, 0, right);         // ������ ���� [1, 2, 3, 4, 5, 6, 7, 8]
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
    PARTITION(_data, _sorted, 0, 0);        // �ƹ��͵� ����
    PARTITION(_data,sorted, 0 + 1, 1);      // �ƹ��͵� ����
    MERGE(_data, _sorted, 0, 1);            // left = data[0] = 6, right = data[1] = 5      =>  MERGE�� �����ϰ� ��ħ.
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
    MERGE(_data, _sorted, 0, 3);            // ���� ������ ���� [2, 4, 7, 8]
}

3-1.
left = 4, right = 5
4 < 5   TRUE
{
    mid = (4 + 5) / 2 = 4
    PARTITION(_data, _sorted, 4, 4);        // �ƹ��͵� ����
    PARTITION(_data,sorted, 4 + 1, 5);      // �ƹ��͵� ����
    MERGE(_data, _sorted, 4, 5);            // data[4] = 8, data[5] = 7 MERGE �Լ� ����.
}

3-2.
left = 6, right = 7
6 < 7   TRUE
{
    mid = (6 + 7) / 2 = 6
    PARTITION(_data, _sorted, 6, 6);        // �ƹ��͵� ����
    PARTITION(_data,sorted, 6 + 1, 7);      // �ƹ��͵� ����
    MERGE(_data, _sorted, 6, 7);            // data[6] = 2, data[7] = 4 MERGE �Լ� ����.
}
*/