//Fermat's Primality testing

#include<bits/stdc++.h>
using namespace std;

int gcd(long long int a, int b){
    while(b > 0){
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

long long int pow(int a, long long int n, long long int p){
    long long int res = 1;
    for(int i = 1; i <= n; i++){
        res = (res * a) % p;
    }
    return res;
}

// long long int pow(int a, long long int x, long long int n){
//     long long int res = 1;
//     while(x > 0){
//         if(x % 2 == 0){
//             res = (res * a) % n;
//         }
//         x = x >> 1;
//         a = (a*a) % n;
//     }
//     return res;
// }

bool isPrime(long long int n){
    if(n <= 1 || n == 4){
        return false;
    }
    if(n == 2 || n == 3){
        return true;
    }
    if(n % 2 == 0){
        return false;
    }
    int k = 100;
    while(k > 0){
        int a = 2 + rand() % (n - 4);
        if(gcd(n,a) != 1){
            return false;
        }
        if(pow(a, n-1, n) != 1){
            return false;
        }
        k--;
    }
    return true;
}

int main(){
    srand(time(0));
    long long int num;
    cin >> num;
    if(isPrime(num)){
        cout << "The number is prime" << endl;
    }
    else{
        cout << "The number is composite" << endl;
    }
    return 0;
}