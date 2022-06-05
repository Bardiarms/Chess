#include <class_def.h>
using std::cin ;
using std::cout ;
using std::endl ;
void Mohre::create_obj(int row1, int column1, char role1, int color1) 
    {
        row = row1 ;
        column = column1 ;
        role = role1 ;
        color = color1 ;
    }
int** Mohre::places_movement(int** map) 
    {   
        int** result ;
        result = new int* [21] ;
        for (int i = 0; i < 21; i++) {
            result[i] = new int [2] ;
        }
        switch (role) {
            case 75 :
                result = places_king(map) ;
                break ;
            case 81 :
                result = places_queen(map) ;
                break ;
            case 66 :
                result = places_bishop(map) ;
                break ;
            case 78 :
                result = places_knight(map) ;
                break ;
            case 82 :
                result = places_rook(map) ;
                break ;
            case 80 :
                result = places_pawn(map) ;
                break ;
        }
        return result ;
    }
    bool Mohre::movement(int di, int dj, int** map)
    {
        bool result ;
        switch (role) {
            case 75 :
                result = king(di, dj, map) ;
                break ;
            case 81 :
                result = queen(di, dj, map) ;
                break ;
            case 66 :
                result = bishop(di, dj, map) ;
                break ;
            case 78 :
                result = knight(di, dj, map) ;
                break ;
            case 82 :
                result = rook(di, dj, map) ;
                break ;
            case 80 :
                result = pawn(di, dj, map) ;
                break ;
        }
        return result ;
    }
int** Mohre::places_king(int** map)
    {   
        int** places ;
        int k = 0 ;
        places = new int* [9] ;
        for (int i = 0; i < 9; i++)
            places[i] = new int [2] ;
        for (int i = row-1; i < row+2; i++) {
            for (int j = column-1; j < column+2; j++) {
                if ((i>=0)&&(i<8)&&(j>=0)&&(j<8)) {
                    if(map[i][j] != color) {
                        places[k][0] = i ; 
                        places[k][1] = j ;
                        k++ ;
                    }
                }
            }
        }
        places[k][0] = -1 ;
        return places ;
    }
    int** Mohre::places_queen(int** map)
    {
        int** places ;
        int k = 0 ;
        places = new int* [25] ;
        for (int i = 0; i < 25; i++)
            places[i] = new int [2] ;
        int i = row - 1 ;
        while ((i>=0) && (int(map[i][column]) != color)) {
            places[k][0] = i ;
            places[k][1] = column ;
            k++ ;
            if (map[i][column] != -1)
                break ;
            i-- ;
        }
        i = row + 1 ;
        while ((i<=7) && (int(map[i][column]) != color)) {
            places[k][0] = i ;
            places[k][1] = column ;
            k++ ;
            if (map[i][column] != -1)
                break ;
            i++ ;
        }
        int j = column - 1 ;
        while ((j>=0) && (int(map[row][j]) != color)) {
            places[k][0] = row ;
            places[k][1] = j ;
            k++ ;
            if (int(map[row][j]) != -1)
                break ;
            j-- ;
        }
        j = column + 1 ;
        while((j<=7) && (int(map[row][j]) != color)) {
            places[k][0] = row ;
            places[k][1] = j ;
            k++ ;
            if (int(map[row][j]) != -1)
                break ;
            j++ ;
        }
        i = row - 1 ;
        j = column - 1 ;
        while((j>=0)&&(i>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j-- ; 
            i-- ;    
        }
        i = row + 1 ;
        j = column + 1 ;
        while((j<=7)&&(i<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j++ ; 
            i++ ;
        }
        i = row - 1 ; 
        j = column + 1 ;
        while((j<=7)&&(i>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j++ ; 
            i-- ;    
        }
        i = row + 1 ;
        j = column - 1 ;
        while((j>=0)&&(i<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j-- ; 
            i++ ;
        }
        cout<<k<<endl ;
        places[k][0] = -1 ;
        return places ;
    }
    int** Mohre::places_knight(int** map) 
    {
        int** places ;
        int k = 0, i, j ;
        places = new int* [9] ;
        for (int i = 0; i < 9; i++)
            places[i] = new int [2] ;
        i = row + 1 ; 
        j = column + 2 ;        
        if ((i<=7)&&(j<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row - 1 ; 
        j = column + 2 ;        
        if ((i>=0)&&(j<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row - 2 ; 
        j = column + 1 ;        
        if ((i>=0)&&(j<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row - 2 ; 
        j = column - 1 ;        
        if ((i>=0)&&(j>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row - 1 ; 
        j = column - 2 ;        
        if ((i>=0)&&(j>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row + 1 ; 
        j = column - 2 ;        
        if ((i<=7)&&(j>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row + 2 ; 
        j = column - 1 ;        
        if ((i<=7)&&(j>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        i = row + 2 ; 
        j = column + 1 ;        
        if ((i<=7)&&(j<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        places[k][0] = -1 ;
        return places ;
    }
    int** Mohre::places_bishop(int** map) 
    {
        int** places ;
        int k = 0, i, j ;
        places = new int* [22] ;
        for (int i = 0; i < 22; i++)
            places[i] = new int [2] ;
        i = row - 1 ;
        j = column - 1 ;
        while((j>=0)&&(i>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j-- ; 
            i-- ;
        }
        i = row + 1 ;
        j = column + 1 ;
        while((j<=7)&&(i<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j++ ; 
            i++ ;
        }
        i = row - 1 ; 
        j = column + 1 ;
        while((j<=7)&&(i>=0)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j++ ; 
            i-- ;
        }
        i = row + 1 ;
        j = column - 1 ;
        while((j>=0)&&(i<=7)&&(int(map[i][j]) != color)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
            if (int(map[i][j]) != -1)
                break ;
            j-- ; 
            i++ ;
        }
        places[k][0] = -1 ;
        return places ;
    }
    int** Mohre::places_rook(int** map)
    {
        int** places ;
        int k = 0, i, j ;
        places = new int* [22] ;
        for (int i = 0; i < 22; i++)
            places[i] = new int [2] ;
        i = row - 1 ;
        while ((i>=0) && (int(map[i][column]) != color)) {
            places[k][0] = i ;
            places[k][1] = column ;
            k++ ;
            if (map[i][column] != -1)
                break ;
            i-- ;
        }
        i = row + 1 ;
        while ((i<=7) && (int(map[i][column]) != color)) {
            places[k][0] = i ;
            places[k][1] = column ;
            k++ ;
            if (map[i][column] != -1)
                break ;
            i++ ;
        }
        j = column - 1 ;
        while ((j>=0) && (int(map[row][j]) != color)) {
            places[k][0] = row ;
            places[k][1] = j ;
            k++ ;
            if (int(map[row][j]) != -1)
                break ;
            j-- ;
        }
        j = column + 1 ;
        while((j<=7) && (int(map[row][j]) != color)) {
            places[k][0] = row ;
            places[k][1] = j ;
            k++ ;
            if (int(map[row][j]) != -1)
                break ;
            j++ ;
        }
        places[k][0] = -1 ;
        return places ;
    }
    int** Mohre::places_pawn(int** map)
    {
        int** places ;
        int k = 0, i, j ;
        places = new int* [5] ;
        for (int i = 0; i < 5; i++)
            places[i] = new int [2] ;
        i = row -1 ;
        if ((i>=0) && (int(map[i][column]) == -1)) {
            places[k][0] = i ;
            places[k][1] = column ;
            k++ ;
        }
        j = column - 1 ;
        if ((i>=0) && (j>=0) && (int(map[i][j]) != color) && (int(map[i][j]) != -1)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        j = column + 1 ;
        if ((i>=0) && (j<=7) && (int(map[i][j]) != color) && (int(map[i][j]) != -1)) {
            places[k][0] = i ;
            places[k][1] = j ;
            k++ ;
        }
        if (color == 87) {
            if (row == 6) {
                i = row -2 ;
                if (int(map[i][column]) == -1) {
                    places[k][0] = i ;
                    places [k][0] = column ;
                    k++ ;
                }
            }
        }
        else {
            if (row == 1) {
                i = row + 2 ;
                if (int(map[i][column]) == -1) {
                    places[k][0] = i ;
                    places[k][1] = column ;
                    k++ ;
                }
            }
        }
        places[k][0] = -1 ;
        return places ;
    }
    
    bool Mohre::king(int di, int dj, int** map)
    {
        if ((di<=7)&&(di>=0)&&(dj<=7)&&(dj>=0)) {
            if (((di == row-1)&&(dj == column))||((di==row-1)&&(dj==column-1))||((di == row)&&(dj == column -1))||((di== row+1)&&(dj== column-1))||((di==row+1)&&(dj==column))||((di==row+1)&&(dj==column+1))||((di==row)&&(dj==column+1))||((di==row-1)&&(dj==column+1))) {
                return true ;
            }
            else return false ;
        }
        else return false ;
    }
    bool Mohre::queen(int di, int dj, int** map)
    {
        if ((di<=7)&&(di>=0)&&(dj<=7)&&(dj>=0)) {
            if ((di==row)||(dj==column)||(abs(di-row)==abs(dj-column))||(abs(di-column)==abs(dj-row))) {
                return true ;
            }
            else return false ;
        }
        else return false ;
    }
    bool Mohre::bishop(int di, int dj, int** map)
    {
        if ((di<=7)&&(di>=0)&&(dj<=7)&&(dj>=0)) {
            if ((abs(di-row)==abs(dj-column))||(abs(di-column)==abs(dj-row))) {
                return true ;
            }
            else return false ;
        }
        else return false ;
    }
    bool Mohre::knight(int di, int dj, int** map)
    {
        if ((di<=7)&&(di>=0)&&(dj<=7)&&(dj>=0)) {
            if (((di==row-2)&&(dj==column-1))||((di==row-1)&&(dj==column-2))||((di==row+1)&&(dj==column-2))||((di==row+2)&&(dj==column-1))||((di==row+2)&&(dj==column+1))||((di==row+1)&&(dj==column+2))||((di==row-1)&&(dj==column+2))||((di==row-2)&&(dj==column+1))) {
                return true ;
            }
            else return false ;
        }
        else return false ;
    }
    bool Mohre::rook(int di, int dj, int** map)
    {
        if ((di<7)&&(di>0)&&(dj<7)&&(dj>0)) {
            if ((di == row)||(dj==column)) {
                return true ;
            } 
            else return false ;
        }
        else return false ;
    }
    bool Mohre::pawn(int di, int dj, int** map)
    {
        if ((di<=7)&&(di>=0)&&(dj<=7)&&(dj>=0)) {
            if ((dj == column)&&(di == row-1))
                return true ;
            else {
                if ((di== row-1)&&(dj == column+1)) {
                    if ((map[di][dj]!=color)&&(map[di][dj]!=-1))
                        return true ;
                        
                    else 
                        return false ;
                }    
                else {
                    if ((di==row-1)&&(dj==column-1)){
                        if ((map[di][dj]!=color)&&(map[di][dj]!=-1))
                            return true ;
                        else return false ;
                    }    
                    else return false ;
                    
                }
                
               
            }
        }
        else return false ;
    }
bool safeKing(int ki, int kj, int colorAscii, Mohre** board, int** map)
{
    // hameye doshmanaro check mikonim ke mitunan bezanan ya na (be vasileye tvabeye tooye class)
    bool res = false ;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((board[i][j].color != -1) && (board[i][j].color != colorAscii)) {
                res = board[i][j].movement(ki, kj, map) ;    
                if (res == true) {
                    return !res ;
                }
            }
        }
    }
    return !res ;
}
bool whoWins(Mohre** board, int i1, int j1, int** map, int color) 
{   
    int i, j, counter = 0, counter1 = 0 ;
    i = i1 -1 ; 
    j = j1 -1 ;
    for (i; i<i1+2; i++) {
        for (j; j<j1+2; j++) {
            if ((i>7)||(i<0))
                break ;
            else{
                if ((j<=7)&&(j>=0)) {
                    if (int(map[i][j])!=color)
                        counter1++ ;    
                    if (!safeKing(i, j, color, board, map))
                        counter++ ;
                }
            }
        }
    }
   if ((counter1 > 0) && (counter1 == counter)) 
        return true ;      // means kish va mat ;
    else return false ;
}
void mate_moves(Mohre** board, int** map, int color,int** kingsPlace)
{
    int** places ;
    int enemy_color, l ;
    bool res, f = false ;
    if (color == 87) {
        enemy_color = 66 ;
        l = 0 ;
    }
    else{ 
        enemy_color = 87 ;
        l = 1 ;
    }
    places = new int* [25] ;
    for (int i = 0; i < 25; i++) {
        places[i] = new int [2] ;
    }
    int source_i, source_j, temp_color, temp_role, source_color, source_role ;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //cout<<i<<" "<<j<<" "<<board[i][j].color<<endl ;
            if (board[i][j].color == color) {
                places = board[i][j].places_movement(map) ;
                int k = 0 ;
                source_color = board[i][j].color ;
                source_role = board[i][j].role ;
                board[i][j].color = -1 ;
                board[i][j].role = -1 ;
                //cout<<i<<" "<<j<<" "<<k<<" test"<<endl ;
                while (places[k][0] != -1) {
                    //cout<<k<<" "<<i<<" "<<j<<" "<<endl ;
                    temp_color = board[places[k][0]][places[k][1]].color ;
                    temp_role = board[places[k][0]][places[k][1]].role ;
                    board[places[k][0]][places[k][1]].color = source_color ;
                    board[places[k][0]][places[k][1]].role = source_role ;
                    res = whoWins(board, kingsPlace[l][0], kingsPlace[l][1], map, enemy_color ) ;
                    if (res == true) {
                        f = true ;
                        cout<<places[k][0]<<' '<<places[k][1]<<" asl"<<endl ;
                        }
                    board[places[k][0]][places[k][1]].color = temp_color ;
                    board[places[k][0]][places[k][1]].role = temp_role ;
                    k++;
                }
                board[i][j].color = source_color ;
                board[i][j].role = source_role ;
            }
        }
    } 
}