#include <iostream>
#include <cstdlib>
using namespace std;

// Ham random tu 1 den 3
int random(int min, int max)
{
   // x is in [0,1[
   double x = rand()/static_cast<double>(RAND_MAX+1); 

   // [0,1[ * (max - min) + min is in [min,max[
   int that = min + static_cast<int>( x * (max - min) );

   return that;
}

// Ham kiem tra thang chua
bool checkwin(char map[][3], char player)
{
    // Check cot ( y )
    for (int i = 0; i < 3; i++)
    {
        if (map[i][0] == player && map[i][1] == player && map[i][2] == player)
            return true;
    }
    // Check hang ( x )
    for (int i = 0; i < 3; i++)
    {
        if (map[0][i] == player && map[1][i] == player && map[2][i] == player)
            return true;
    }
    // Duong cheo
    if (map[0][0] == player && map[1][1] == player && map[2][2] == player)
            return true;
    if (map[0][2] == player && map[1][1] == player && map[2][0] == player)
            return true;
    
    return false;
}

// In ra bang tran dau
void printMap(char map[][3])
{
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 3; j++)
        {
            cout << map[i][j] <<" ";
        }
        cout<<"\n";
    }

}

int main()
{   
    // Create MAPPPPP
    char map[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            map[i][k] = '-';
        }
    }

    char Player ='X';
    char Robot = 'O';
    // Goi vi tri quuan co la x, y 
    int x, y;

    while(true)
    {
        printMap(map);
        // Nguoi dung nhap ban phim
        cout<<"\nVVui long nhap vi tri muon chon (hang (1 - 3), cot (1 - 3)) : ";
        // Kiem tra no da exit ?
        while (true)
        {
            while(true)
            {
                cin>>x>>y;
                if( x <= 0 || x >= 4  || y <= 0 || y >= 4)
                {
                    cout<<"Nhap lai : ";
                }
                else 
                    break;
            }
            
            if (map[x - 1][y - 1] != '-')
            { 
                cout<<"Nhap lai : ";
                continue;
            }
            else
            {
                map[x - 1][y - 1] = Player;
                break;
            }
        }
        cout << "\033[2J\033[1;1H"; // Clear man hinh

        // Kiem tra xong chưa =))
        if (checkwin(map, Player)) 
        {
            break;
        }

        while(true)
        {
            x = random(0, 4);
            y = random(0, 4);

            if(map[x][y] == Player || map[x][y] == Robot)
                continue;
            else
                map[x][y] = Robot;
                break;
        }

        if (checkwin(map, Robot)) 
        {
            break;
        }

    }

    //Hien ket qua match
    if (checkwin(map, Player)) 
    {
        cout<<"Nguoi Dung chien thang !";
    }
    else if (checkwin(map, Robot)) 
    {
        cout<<"Robot chiên thang !";
    }
    else
        cout<<"Hoa";

    return 0;
}
