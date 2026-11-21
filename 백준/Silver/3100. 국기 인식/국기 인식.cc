#include <algorithm>
#include <cstdio>

using namespace std;

int cntH[3][26];
int cntV[3][26];

int main( void ) {
    for( int r = 0; r < 6; ++r ) {
        char buff[10];
        scanf( "%s", buff );
        for( int c = 0; c < 9; ++c ) {
            cntH[r/2][buff[c]-'A']++;
            cntV[c/3][buff[c]-'A']++;
        }
    }

    int best = 0;
    
    for( int i = 0; i < 26; i++ ) 
        for( int j = 0; j < 26; j++ ) 
            for( int k = 0; k < 26; k++ ) {
                if( i == j || j == k ) continue;
                best = max( best, cntH[0][i] + cntH[1][j] + cntH[2][k] );
                best = max( best, cntV[0][i] + cntV[1][j] + cntV[2][k] );
            }
    
    printf( "%d\n", 6*9 - best );

    return 0;
}
