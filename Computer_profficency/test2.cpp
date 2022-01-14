using namespace std;
# define s 3
typedef struct {
    string Moves[3];
    bool isoccupied[3];
}Table;

Table * board_update(Table *Board){

    
	Board[0].Moves[0]='o';

	return Board;
}