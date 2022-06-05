#include <class_def.h>
using std::string ;


int main()
{
    string inputs, pos ;
    char move ;
    int col, tempCol ;
    int** kingsPlace ;
    int** map ;
    int whoseTurn, source_i, source_j, dest_i, dest_j ;
    Mohre** board ;
    board = new Mohre* [8] ;
    kingsPlace = new int* [2] ;
    map = new int* [8] ;
    for (int i = 0; i < 2; i++) {
        kingsPlace[i] = new int [2] ;
    }
    for (int i = 0; i < 8; i++) {
        board[i] = new Mohre [8] ;
    }
    for (int i = 0; i < 8; i++) {
        map[i] = new int [8] ;
    }

    cin>>pos ;
    whoseTurn = int(pos[0]) ;
    move = pos[1] ;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin>>inputs ;
            map[i][j] = -1 ;
            if (isalpha(inputs[0])) {
                if (inputs[1] == 'W'){
                    col = 87 ;
                    map[i][j] = 87 ;
                }
                else{ 
                    col = 66 ;
                    map[i][j] = 66 ; 
                }
                board[i][j].create_obj(i, j, inputs[0], col ) ;
                if (inputs[0] == 'K') {
                    if (inputs[1] == 'W') {
                        kingsPlace[1][0] == i ; 
                        kingsPlace[1][1] == j ;
                    }
                    else {
                        kingsPlace[0][0] == i ;
                        kingsPlace[0][1] == j ;
                    }
                }
            }
        }
    }
    if (int(move) == 77) {
        mate_moves(board, map, whoseTurn, kingsPlace) ;
    }

}