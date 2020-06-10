// 给出一个N次函数，保证在范围[l,r]内存在一点x，使得[l,x]上单调增，[x,r]上单调减。试求出x的值。
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n;
double l, r;
vector<double> func;

double cal(double x){
    double sum = func[0];
    for(int i=0; i<n; i++){
        sum = sum * x + func[i+1];
    }
    return sum;
}

int main(){
    cin >> n >> l >> r;
    func.resize(n+1);
    for(int i=0; i<n+1; i++){
        double c = 0;
        cin >> c;
        func[i] = c;
    }
    while((r - l) >= 1e-6){
        double lmid = (l+r)/2.0;
        double rmid = (lmid+r)/2.0;
        if(cal(lmid)>cal(rmid))
            r = rmid;
        else
            l = lmid;
    }
    cout.precision(5);
    cout << l << endl;
   //printf("%.5f\n", l);
    return 0;
}
