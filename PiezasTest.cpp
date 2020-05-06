/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, ConstructorTest){
	Piezas board;
	for(int i = 0; i < BOARD_ROWS; i++)
	{
		for(int j = 0; j < BOARD_COLS; j++)
		{
			ASSERT_EQ(board.pieceAt(i,j), Blank);	  
		}
	}
}

TEST(PiezasTest, resetTest){
	Piezas board;
	board.dropPiece(0);
	board.reset();
	ASSERT_EQ(board.pieceAt(BOARD_ROWS-1,0), Blank);
	ASSERT_EQ(board.pieceAt(BOARD_ROWS,0), Invalid);
}

TEST(PiezasTest, dropPieceTest){
	Piezas board;
	ASSERT_NE(board.dropPiece(0), Blank);
	ASSERT_EQ(board.dropPiece(BOARD_COLS), Invalid);
	ASSERT_NE(board.dropPiece(0), Blank);
	ASSERT_NE(board.dropPiece(0), Blank);
	ASSERT_EQ(board.dropPiece(0), Blank);
}

TEST(PiezasTest, gameStateTest){
	Piezas board;
	ASSERT_EQ(board.gameState(), Invalid);
	for(int j = 0; j < BOARD_COLS; j++){
		for(int i = 0; i < BOARD_ROWS; i++){
			board.dropPiece(j);
		}	
	}
	ASSERT_EQ(board.gameState(), Blank);
}
