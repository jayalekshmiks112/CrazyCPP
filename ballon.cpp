#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10; 
pair<int, int> balloon_location; 
char map[SIZE][SIZE]; 
void locate();

void locate() {
    srand(time(NULL)); 
    int x = rand() % SIZE; 
    int y = rand() % SIZE; 
    if (x==0 || y==0)
    {
        locate();
    }
    balloon_location = make_pair(x, y); 
}

void display() {
    int i=0;
    for (i = 0; i <SIZE; i++) {
       int j=0;
        
        for (j = 0; j <SIZE; j++) {
        if (i==0 && j==0 )
        {
            cout<<" ";
        }
        else if(i!=0 && j==0)
        {
            cout<<i;
        }
        else if(i==0 && j!=0)
        {
            cout<<" "<<j;
        }
        else
        {
            if (i == (balloon_location.first) && j == (balloon_location.second)) 
            {
                map[i][j] =' G';
                cout <<" "<<map[i][j]; 
            }
            else  
            {
                cout <<" $";
            }
        }
        
            
        }
        cout << endl;
    }
}

void guess(int x, int y) 
{
    if (x == balloon_location.first && y == balloon_location.second) 
    {
        cout << "Eureka! You found the balloon at (" << x << ", " << y << ")." << endl;
    } 
    else 
    {
        cout << "Oops!! Wrong guess." << endl;
        if (x < balloon_location.first) {
            cout << "The balloon is to the east w.r.t x coordinate." << endl;
        } else if (x > balloon_location.first) {
            cout << "The balloon is to the west w.r.t x coordinate." << endl;
        }
        if (y > balloon_location.second) {
            cout << "The balloon is to the north w.r.t y coordinate." << endl;
        } else if (y < balloon_location.second) {
            cout << "The balloon is to the south w.r.t y coordinate." << endl;
        }
    }
}

int main() 
{
    locate(); 
    int n;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Display balloon position" << endl;
        cout << "2. Guess balloon position" << endl;
        cout << "3. Exit" << endl;
        cin >> n;
        switch (n) 
        {
            case 1:
                display(); 
                break;
            case 2:
                int x, y;
                    cout << "Enter your guess for the x coordinate of the balloon(0-10): ";
                    cin >> x ;
                    cout << "Enter your guess for the y coordinate of the balloon(0-10): ";
                    cin >> y ;
                    if(x>10||x<0 || y<0 || y>10)
                        cout<<"Coordiantes should be between 0-10"<<endl;
                    else
                    guess(x, y); 
                break;
            case 3:
                cout << "Thank you!"<<endl;
                exit(0);
                break;
            default: 
                cout<<"Inavlid choice"<<endl;
        }
    }while(1);
    return 0;
}

