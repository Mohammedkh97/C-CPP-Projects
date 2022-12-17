#include <iostream>
using namespace std;


//Global Variables:
char Mat[3][3]={'1','2','3','4','5','6','7','8','9'};
char postion;
int x = 0 , o = 0 , c = 0;
char player ='X';

void MyMatrix(){
    system("cls");
    cout<<"My Matrix is: "<<endl;
    cout<<"---------"<<endl;
    for(int i= 0 ; i<3 ; i++){
        cout<<"| ";
        for (int j= 0 ; j<3 ; j++){
            cout<<Mat[i][j]<<" ";
            //cout<<" ";
        }
    cout<<"|";
    cout<<endl;
    //cout<<"------------"<<endl;
    }
    cout<<"---------"<<endl;
}
void Replace()
{
    cout <<"Enter your position player: {"<<player<<"}"<<endl;
    cin >> postion;
    for(int i= 0 ; i<3 ; i++){
        for (int j= 0 ; j<3 ; j++){
            if (Mat[i][j] == postion)
            Mat[i][j] =player;
            if (Mat[i][j] == player){
            cout<<"Already played! Try another one please"<<endl;
            Mat[i][j] = player;
            }
        }
    }
    if (player =='X')
        player ='O';
    else
    player='X';

}
char winner()  // its a character function because we need to know the status in form of word "winner or loser"
{

int x = 0 , o = 0 , c = 0;
for (int i=0 ; i <3 ;i++)
{
    for (int j=0 ; j<3 ; j++)
    {
        if (Mat[i][j] == 'X')
            x++;
        else if (Mat[i][j] == 'O')
            o++ ;
        if (x == 3)
            return 'X';
        if (o == 3)
            return 'O';
    }
    x=0;
    o=0;
}
for (int i=0 ; i <3 ;i++)
{
    for (int j=0 ; j<3 ; j++)
    {
        if (Mat[j][i] == 'X')
            x++;
        else if (Mat[j][i] == 'O')
            o++ ;
        if (x == 3)
            return 'X';
        if (o == 3)
            return 'O';
    }
    x=0;
    o=0;
}
if (Mat[0][0] == 'X' && Mat[1][1] =='X' && Mat[2][2] == 'X')
    return 'X';
if (Mat[0][2] == 'X' && Mat[1][1] =='X' && Mat[2][0] == 'X')
    return 'X';
if (Mat[0][0] == 'O' && Mat[1][1] =='O' && Mat[2][2] == 'O')
    return 'O';
if (Mat[0][2] == 'O' && Mat[1][1] =='O' && Mat[2][0] == 'O')
    return 'O';

for (int i = 0 ; i<3 ; i++)
{
    for (int j = 0 ; j <3 ; j++)
    {
        if (Mat[i][j] != 'X' && Mat[i][j] != 'O') // check if there is an empty place or not
            c++;
    }
}
if (c == 0)
    return 'Draw';

return 'c';
}
int main()
{
while(winner() =='c'){
    MyMatrix();
    Replace();
    winner();

    }

MyMatrix();
if (winner() == 'X')
    cout<<"X Player is the Winner !"<<endl;
if (winner() == 'O')
    cout<<"O Player is the Winner !"<<endl;
if (winner() == 'Draw')
    cout<<"No Winner (Draw)!"<<endl;
return 0;
}
