/*
Problem Statement: D. Distinct Split

You are given a string s and need to split it into two non-empty substrings a and b 
such that the sum of distinct characters in both substrings is maximized.
Formally, define f(x) as the number of distinct characters in string x.
Your goal is to maximize f(a) + f(b) 
while ensuring that a + b = s (i.e., s is split into two consecutive substrings).

Input Format  
- The first line contains an integer t (1 ≤ t ≤ 10^4) — the number of test cases.  
- Each test case consists of two lines:  
  - The first line contains an integer n (2 ≤ n ≤ 2 × 10^5) — the length of the string s.  
  - The second line contains the string s, consisting of lowercase English letters.  
- The sum of all n over all test cases does not exceed 2 × 10^5.

Output Format  
For each test case, output a single integer —
the maximum possible value of f(a) + f(b) such that a + b = s.

Example  
Input:  
5  
2  
aa  
7  
abcabcd  
5  
aaaaa  
10  
paiumoment  
4  
aazz  

Output:  
2  
7  
2  
10  
3  

Explanation  
- In the first test case, the only valid split is "a | a", giving f(a) + f(a) = 1 + 1 = 2.  
- In the second test case, splitting "abcabcd" as "abc | abcd" gives f(abc) + f(abcd) = 3 + 4 = 7.  
- In the third test case, all characters are the same, so any split results in f(a) + f(b) = 2.  
- The fourth test case maximizes f(a) + f(b) by splitting optimally.  
- The fifth test case finds the best split for "aazz".

*/

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   //[30 digits]

void solve() {
    int length;     cin >> length; 
    string word;    cin >> word; 

    // prefix and suffix vector
    vector<int> prefix(length, 0), suffix(length, 0);
    set<int> temp; 

    for(int i=0; i<length; i++) {
        temp.insert(word[i]);
        prefix[i] = temp.size();
    }
    temp.clear();   // clear the set to calculate the suffix
    for(int i=length-1; i>=0; i--) {
        temp.insert(word[i]);
        suffix[i] = temp.size();
    }

    int answer = LLONG_MIN; 
    for(int i=0; i+1<length; i++) {
        answer = max(answer, prefix[i]+suffix[i+1]);
    }
    cout << answer << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}

/*
word : abcabde
prefix ->   1   2   3   3   3   4   5      (size if the set upto that point)
            a   b   c   a   b   d   e
            5   5   5   4   3   2   1    <- suffix   
*/