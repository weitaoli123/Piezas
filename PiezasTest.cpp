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
  std::vector < std::vector<Piece> > test_board = 
  	{{Blank, Blank, Blank, Blank}, {Blank, Blank, Blank, Blank},{Blank, Blank, Blank, Blank}};
  ASSERT_EQ(board, test_board);
}
