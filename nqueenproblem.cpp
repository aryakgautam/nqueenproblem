#include<iostream>
#include<vector>

using namespace std ;

bool isSafe ( int row , int col , vector < vector < char > > board , int n ) 
{
        int x = row ;
        int y = col ;

        while ( y >= 0 ) // checking queen in previous column
        {
            if ( board [ x ] [ y ] == 'Q' )
            {
                return false ;
            }
            y -- ;
        }


        // now checking upper- left diagonal 
    
        x = row ;
        y = col ;

        while ( x >= 0 && y >= 0 )
        {
            if ( board [ x ] [ y ] == 'Q'  )
            {
                return false ;
            }

            x -- ;
            y -- ;
        }

        //  for lower left diagonal 

        x = row ;
        y = col ;

        while ( x < n && y >= 0 )
        {
            if ( board [ x ] [ y ] == 'Q' )
            {
                return false ;
            }

            x ++ ; 
            y -- ;
        }

        return true ;
}

void printSolution ( vector < vector < char > > & board , int n )
{
    for ( int i = 0 ; i < n ; i ++ )
    {
        for ( int j = 0 ; j < n ; j ++)
        {
            cout << board [ i ] [ j ] << " " ;
        }
        cout << endl ;
    }
    cout << endl << endl ;
}

void solve ( vector < vector < char > > board , int col , int n  )
{
    // base case 
    if ( col >= n )
    {
        printSolution ( board , n ) ;
        return ;
    }
    for ( int row = 0 ; row < n ; row ++ )
    {
        if ( isSafe ( row , col , board , n ) ) {
        board [ row ] [ col ] = 'Q' ;
        // recurssive call 
        solve ( board , col + 1 , n  ) ;
        //  backtracking 
        board [ row ] [ col ] = '-' ;
        }
    }
}

int main () 
{
    int n = 5 ; // n x n ka board hai 
    vector < vector < char > > board ( n , vector < char > ( n , '-' ) ) ; // created a 2-d vector i.e. board 

    int column = 0 ;

    solve ( board , column , n ) ;
}