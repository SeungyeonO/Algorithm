#include <iostream>
using namespace std;

int solution(int k, int n){
    if(k == 0 || n == 1)
        return n;
    
    int num = solution(k, n-1) + solution(k-1, n);
    return num;
}

int main() {
    int T, k, n;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> k;
        cin >> n;
        
        cout << solution(k, n) << endl;
    }
    
    return 0;
    
}