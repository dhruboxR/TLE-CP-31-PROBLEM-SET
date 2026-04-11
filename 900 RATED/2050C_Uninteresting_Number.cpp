/*
2050C - UNINTERESTING NUMBER [ codeforces ] 

Given a number with a length not more than 10^5 
You can perform the following operation any number of times 
- Chooe one digit, square it and replace the original digit with the square result 
[ if you choose digit x then the value of x^2 must be less than 10 (x^2 < 10) ]

IS IT POSSIBLE TO OBTAIN A NUMBER THAT IS DIVISIBLE BY 9 THROUGH THESE OPERATIONS 
*/  

#include <bits/stdc++.h>
#define int long long int 
using namespace std ;

void solve() {
    // we will read the number in a string because it's way too long 
    string number ;     cin >> number ; 

    bool divisible = false ; 
    int sumof_digits = 0 , count_two = 0, count_three = 0;

    for(char digit : number) {
        sumof_digits += digit - '0' ;  // converting char to int and adding in the sum 

        // count the frequency of the digits 2 & 3 
        if(digit == '2') {
            count_two++ ;
        } if(digit == '3') {
            count_three++ ;
        }
    }
    // if our sum is already divisible by 9 then we are done here 
    if(sumof_digits % 9 == 0) {
        cout << "YES" << endl ;
        return ;
    }
    // else we move towards the operation & check every possible combination maximimum 100 each
    for(int i=0; i<=min(count_two,10LL); i++) {
        for(int j=0; j<=min(count_three,10LL); j++) {

            divisible = divisible || ( ( sumof_digits+(2*i)+(6*j) ) % 9 == 0) ;
            if(divisible) break ;
        }
        if(divisible) break ;
    }

    cout << (divisible ? "YES" : "NO") << endl ;
}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ; 

    int test_case;  cin >> test_case;
    while( test_case-- ) {
        solve() ; 
    }

    return 0 ; 
}