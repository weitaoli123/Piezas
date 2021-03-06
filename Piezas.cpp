#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    turn = X;
    board = {{Blank, Blank, Blank, Blank}, 
            {Blank, Blank, Blank, Blank},
            {Blank, Blank, Blank, Blank}};
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    board = {{Blank, Blank, Blank, Blank}, 
            {Blank, Blank, Blank, Blank},
            {Blank, Blank, Blank, Blank}};
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    Piece cur_piece = turn;
    if(turn == X)
        turn = O;
    else
        turn = X;
    if(column >=  BOARD_COLS || column < 0)
        return Invalid;
    else if(board[0][column] != Blank)
        return Blank;
    for(int i = 1; i < BOARD_ROWS; i++)
    {
        if(board[i][column] != Blank)
        {
            board[i-1][column] = cur_piece;
            return cur_piece;
        }
    }
    board[BOARD_ROWS-1][column] = cur_piece;
    return cur_piece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row >= BOARD_ROWS || row < 0 || column >= BOARD_COLS || column < 0)
        return Invalid;
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int x_score = 0;
    int o_score = 0;
    for(int i = 0; i < BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
            if(board[i][j] == Blank)
                return Invalid;
            int row_adj = 0;
            int col_adj = 0;
            for(int k = j; k < BOARD_COLS; k++)
            {
                if(board[i][j] == board[i][k])
                   row_adj++;
                else
                   break;
            }
           for(int k = i; k < BOARD_ROWS; k++)
            {
                if(board[i][j] == board[k][j])
                   col_adj++;
                else
                   break;
            }
            if(board[i][j] == X)
            {
                if(row_adj > x_score)
                       x_score = row_adj;
                if(col_adj > x_score)
                       x_score = row_adj;
            }
            else
            {
                if(row_adj > o_score)
                       o_score = row_adj;
                if(col_adj > o_score)
                       o_score = row_adj;
            }
        }
    }
    if(x_score > o_score)
        return X;
    else if(o_score > x_score)
        return O;
    else 
        return Blank;
}
