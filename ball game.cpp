#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int board_size=10;
const char empty= ' ';
const char ball = 'o';
const char player ='p';
int main(){
    srand(time(0));
    char board[board_size][board_size];
    int playerrow=board_size-1;
    int playercol=board_size/2;
    int ballrow=0;
    int ballcol=rand()%board_size;
    for(int row=0;row<board_size;++row){
        for(int col=0;col<board_size;++col){
            board[row][row]=empty;
        }
    }
    board[playerrow][playercol]=player;
    board[ballrow][ballcol]=ball;
    bool gameRunning =true;
    int score=0;
    while(gameRunning){
        system("cls");
        for(int row=0;row<board_size;++row){
            for(int col=0;col<board_size;++col){
                cout<<board[row][row]<<" ";
            }
            cout<<endl;
        }
        char move;
        cout<<"enter your move ( a- left , d- right ) : "<<endl;
        cin>>move;
        board[playerrow][playercol]=empty;
        
        if(move=='a'&&playercol>0){
            --playercol;
        }
        else if(move=='d'&&playercol<=board_size-1){
            ++playercol;
        }
        board[playerrow][playercol]=player;
        board[ballrow][ballcol]=empty;
        if(ballcol<playerrow){
            ++ballrow;
        }
        else{
            //randomnly move ball left or right 
            int direction=rand()%2;
            if(direction==0&&ballcol>0){
                --ballcol; //left
            }
            else if(direction==1&&ballcol<board_size-1){
                ++ballcol;
            }
            ++ballrow;
        }
        if(ballrow==playerrow&&ballcol==playercol){
            ++score;
            ballrow=0;
            ballcol=rand()%board_size;
        }
        board[ballrow][ballcol]=ball;
        if(ballrow==board_size-1){
            gameRunning=false;
        }


    }
    cout<<"game over! your score = "<<score<<endl;
    return 0;
}