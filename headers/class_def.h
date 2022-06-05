#pragma once
#include <iostream>
using namespace std ;
#include <SFML/Graphics.hpp>
using namespace sf ;
class Mohre 
{
public:
    int row = -1, column = -1 ;
    char role ;
    int color = -1 ;
    void create_obj(int row1, int column1, char role1, int color1) ;
    int** places_movement(int** map) ;
    bool movement(int di, int dj, int** map) ;
    int** places_king(int** map) ;
    int** places_queen(int** map) ;
    int** places_knight(int** map) ;
    int** places_bishop(int** map) ;
    int** places_rook(int** map) ;
    int** places_pawn(int** map) ;
    bool king(int di, int dj, int** map) ;
    bool queen(int di, int dj, int** map) ; 
    bool bishop(int di, int dj, int** map) ;
    bool knight(int di, int dj, int** map) ;
    bool rook(int di, int dj, int** map) ;
    bool pawn(int di, int dj, int** map) ;
     
} ;
bool safeKing(int ki, int kj, int colorAscii, Mohre** board, int** map) ;
bool whoWins(Mohre** board, int i1, int j1, int** map, int color) ;
void mate_moves(Mohre** board, int** map, int color,int** kingsPlace) ;
