/*
1904A - FORKED !! [ codeforces ] : 900

lunchbox is done playing chess! His queen and king just got forked again! 
In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and queen.
Lunchbox knows that knights can be tricky, and in the version of chees that he is playing, knights are even 
tricker. Knights in lunchbox's modified game move 'a' tiles in one direction and 'b' tiles in the other.

Lunchbox is playing chess on an infinite chessboard which contains all cells (x,y) where x and y are integers.
Lunchbox's king and queen are placed on cells (x'k) and (y'k) and (x'q) and (y'q) repectively. 

Find the number of positions such that if a knight was placed on that cell, it would FORK! the king and queen 

INPUT 

Each test contains multiple test cases. The first line contains an integer t- the number of testcases. 
The description of testcases follows. 

The frist line of each test case contains two interge a and b - describing the possible moves of the knight 
The second line of each test case contains two integers xk and yk the position of lunchbox's king. 
The third line in a test case contains xq and yq- the position of Lunchbox's queen. 

It is guaranteed that lunchbox's queen and king will occuoy different cells.(x'k,y'k) != (x'q,y'q) 

OUTPUT 

Output the number of positions where the king and queen can get FORKED!! 

Example

InputCopy
4
2 1
0 0
3 3
1 1
3 1
1 3
4 4
0 0
8 0
4 2
1 4
3 4

OutputCopy
2
1
2
0

*/

#include <bits/stdc++.h>
using namespace std ;

void solve() {

    // knights position 
    int a,b ;   cin >> a >> b ; 

    // king's position 
    int king_x, king_y ;    cin >> king_x >> king_y ;
    
    // Queen's position 
    int queen_x, queen_y ;   cin >> queen_x >> queen_y ;

    int fork_squares = 0 ;

    if( a == b ) {
        int cordinate_x[4] = {-a, a, a, -a} ; 
        int cordinate_y[4] = {b, -b, b, -b} ;

        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                // knights position from king 
                int knight_kingX = king_x + cordinate_x[i] ;
                int knight_kingY = king_y + cordinate_y[i] ;

                // knights position from queen 
                int knight_queenX = queen_x + cordinate_x[j] ; 
                int knight_queenY = queen_y + cordinate_y[j] ;

                // if the xy cordinates of knight from king matches with the xy cordinates of knight from queen then
                // it is a FORK SQUARE !! 

                if(knight_kingX==knight_queenX && knight_kingY==knight_queenY) {
                    fork_squares++ ;
                }    
            }
        }
    } else {
        int cordinate_x[8] = {-a, a, a, -a, -b, b, b, -b} ; 
        int cordinate_y[8] = {b, -b, b, -b, a, -a, a, -a} ;

        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                // knights position from king 
                int knight_kingX = king_x + cordinate_x[i] ;
                int knight_kingY = king_y + cordinate_y[i] ;

                // knights position from queen 
                int knight_queenX = queen_x + cordinate_x[j] ; 
                int knight_queenY = queen_y + cordinate_y[j] ;

                if(knight_kingX==knight_queenX && knight_kingY==knight_queenY) {
                    fork_squares++ ;
                }    
            }
        }
    }

    cout << fork_squares << endl ;
}

int main() {

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL); 

    int test_case;  cin >> test_case; 

    while ( test_case-- ) {
        solve() ;
    }


    return 0 ;
}