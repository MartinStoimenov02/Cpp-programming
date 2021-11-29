#include <iostream>
using namespace std;

char Board[3][3];
    int BoardX;
    int BoardY;
    int XorO = 0;
    int WhoWon = 0;



bool WinX(){
    if (Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X'){
            WhoWon = 0;
        return true;
    }
    if (Board[2][0] == 'X' && Board[1][1] == 'X' && Board[0][2] == 'X'){
         WhoWon = 0;
        return true;
    }
    if (Board[1][0] == 'X' && Board[1][1] == 'X'&& Board[1][2] == 'X'){
         WhoWon = 0;
        return true;
    }
    if (Board[0][1] == 'X' && Board[1][1] == 'X'&& Board[2][1] == 'X'){
         WhoWon = 0;
        return true;
    }

}
bool WinO(){
    if (Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O'){
        WhoWon = 1;
        return true;
    }
    if (Board[2][0] == 'O' && Board[1][1] == 'O' && Board[0][2] == 'O'){
        WhoWon = 1;
        return true;
    }
    if (Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O'){
        WhoWon = 1;
        return true;
    }
    if (Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O'){
        WhoWon = 1;
        return true;
    }

}

int main(){

    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++){
            Board[x][y]='-';
        }
    }

    for(int y=0; y<3; y++){
        for(int x=0; x<3; x++){
            cout<<Board[x][y]<<' ';
        }
        cout<<endl;
    }

    while(WinX() == false && WinO() == false){
        cout<<"X:";
        cin>>BoardX;
        cout<<"Y:";
        cin>>BoardY;
        cout<<endl;
        if(XorO == 0){
            XorO = 1;
            if(Board[BoardX][BoardY] == '-'){
               Board[BoardX][BoardY] = 'O';
            }else{
                cout<<endl;
                cout<<"Nope ;D";
                cout<<endl;
                XorO = 0;
            }
        }else{
            XorO = 0;
            if(Board[BoardX][BoardY] == '-'){

               Board[BoardX][BoardY] = 'X';
            }else{
                cout<<endl;
                cout<<"Nope ;D";
                cout<<endl;
                XorO = 0;
            }
        }

        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                cout<<Board[x][y]<<' ';
            }
        cout<<endl;
        }
    }

    cout<<WhoWon<<" won!";
    system("pause");

    return 0;
}
