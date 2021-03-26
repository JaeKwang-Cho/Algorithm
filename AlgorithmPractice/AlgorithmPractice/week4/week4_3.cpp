#include <iostream>

using namespace std;
__int64 count_divide(__int64 input);
__int32 num_of_ones(__int64 num, __int64 l, __int64 r, __int64 start, __int64 end);

int main()
{
    long long int l, r, n, d , len;
    cin >> n >> l >> r;
    d = count_divide(n);
    len = 2*d - 1;

    cout << num_of_ones(n, l, r, 1, len);
    return 0;
}
__int32 num_of_ones(__int64 num, __int64 l, __int64 r , __int64 start,__int64 end)
{
    __int64 mid = (start + end) / 2 ;
    __int32 result = 0;

    if (num == 0 || l > end || r < start)
    {
        return 0;
    }
    if (num == 1) // l 혹은 r 확인
    {
        return 1;
    }
    
     
    // cout << num << ", ";
    // cout << l << ", ";
    // cout << r << ", ";
    // cout << start << ", ";
    // cout << end <<endl;

    
    if (l == start && r == end) // 전부
    {
        result += num;
    }
    else if (l == mid && r == end) // 반1
    {
        result += num/2;
        result += num % 2;
    }
    else if (l == start && r == mid) // 반2
    {
        result += num / 2;
        result += num % 2;
    }
    else if (l < mid && r == end) // 반 + 일부 1
    {
        result += num / 2;
        result += num % 2;
        result += num_of_ones(num / 2, l, mid - 1, start, mid - 1);
    }
    else if(l == start && r > mid) // 반 + 일부 2
    {
        result += num / 2;
        result += num % 2;
        result += num_of_ones(num / 2, mid + 1, r, mid + 1, end);
    }
    else if(l < mid && r > mid) // 가운데 끼고 일부
    {
        result += num % 2;
        result += num_of_ones(num / 2, l, mid - 1, start, mid - 1);
        result += num_of_ones(num / 2, mid + 1, r, mid + 1, end);
    }
    else if (l < mid && r < mid) // 왼쪽으로 치우쳐서 일부
    {
        result += num_of_ones(num / 2, l, r, start, mid - 1);
    }
    else if (l > mid && r > mid) // 오른쪽으로 치우져서 일부
    {
        result += num_of_ones(num / 2, l, r, mid + 1, end);
    }
    else if (l < mid && r == mid) // 왼쪽으로 치우쳐서 일부
    {
        result += num % 2;
        result += num_of_ones(num / 2, l, r, start, mid - 1);
    }
    else if (l == mid && r > mid) // 오른쪽으로 치우져서 일부
    {
        result += num % 2;
        result += num_of_ones(num / 2, l, r, mid + 1, end);
    }
    else if (l == mid && r == mid)
    {
        result += num % 2;
    }

    return result;
}
__int64 count_divide(__int64 input)
{
    __int64 result = 1;
    while (input > 1)
    {
        input /= 2;
        result *= 2;
    }
    return result;
}