#include <iostream>
using namespace std;

void ExtendedBUCutRod(const int *p, int n, int *r, int *s)
{
    r[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int q = -1;
        for (int j = 1; j <= i; ++j)
        {
            int tmp = p[j - 1] + r[i - j];
            if (q < tmp)
            {
                q = tmp;
                s[i] = j;
            }
        }
        r[i] = q;
    }
}

//r[]保存长度为i的钢条最大收益,s[]保存最优解对应的第一段钢条的切割长度
void PrintBUCutRod(const int *p, int n, int *r, int *s)
{
    ExtendedBUCutRod(p, n, r, s);
    cout << "长度为" << n << "的钢条最大收益为:" << r[n] << endl;

    cout << "最优方案的钢条长度分别为:";
    while (n > 0)
    {
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}

//Test
int main()
{
    int n;
    while (cin >> n)
    {
        int *p = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }
        int *r = new int[n + 1];
        int *s = new int[n + 1];

        PrintBUCutRod(p, n, r, s);
    }

    return 0;
}


/*
7
1 5 8 9 10 17 17
*/