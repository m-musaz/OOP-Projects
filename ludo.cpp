#include <iostream>
#include <ctime>

using namespace std;

string board[5][100];

int pos[5];int pos2[5];int stack_pos1[5];int stack_pos2[5];
int p1_onboard=0;int p2_onboard=0;int p1_home=0;int p2_home=0;
bool p1_win=false;bool p2_win=false;

string p1="@",p2="$";
void dispBoard()
{
    string box[] =
    {
                  "_______________________________________________________________________________________________________________________________________",
                  "|                                                     |"+board[1][11]+board[2][11]+board[3][11]+board[4][11]+"|"+board[1][12]+board[2][12]+board[3][12]+board[4][12]+"|"+board[1][13]+board[2][13]+board[3][13]+board[4][13]+"|                                                     |", 
                  "|    Player1                                          |________|________|________|                                                     |",
                  "|                                                     |"+board[1][10]+board[2][10]+board[3][10]+board[4][10]+"|        |"+board[1][14]+board[2][14]+board[3][14]+board[4][14]+"|                                                     |",                            
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][9]+board[2][9]+board[3][9]+board[4][9]+"|        |"+board[1][15]+board[2][15]+board[3][15]+board[4][15]+"|                                                     |",              
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][8]+board[2][8]+board[3][8]+board[4][8]+"|        |"+board[1][16]+board[2][16]+board[3][16]+board[4][16]+"|                                                     |", 
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][7]+board[2][7]+board[3][7]+board[4][7]+"|        |"+board[1][17]+board[2][17]+board[3][17]+board[4][17]+"|                                                     |", 
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][6]+board[2][6]+board[3][6]+board[4][6]+"|        |"+board[1][18]+board[2][18]+board[3][18]+board[4][18]+"|                                                     |", 
                  "|_____________________________________________________|________|________|________|_____________________________________________________|",                   
                  "|"+board[1][0]+board[2][0]+board[3][0]+board[4][0]+"|"+board[1][1]+board[2][1]+board[3][1]+board[4][1]+"|"+board[1][2]+board[2][2]+board[3][2]+board[4][2]+"|"+board[1][3]+board[2][3]+board[3][3]+board[4][3]+"|"+board[1][4]+board[2][4]+board[3][4]+board[4][4]+"|"+board[1][5]+board[2][5]+board[3][5]+board[4][5]+"|                          |"+board[1][19]+board[2][19]+board[3][19]+board[4][19]+"|"+board[1][20]+board[2][20]+board[3][20]+board[4][20]+"|"+board[1][21]+board[2][21]+board[3][21]+board[4][21]+"|"+board[1][22]+board[2][22]+board[3][22]+board[4][22]+"|"+board[1][23]+board[2][23]+board[3][23]+board[4][23]+"|"+board[1][24]+board[2][24]+board[3][24]+board[4][24]+"|",                        
                  "|________|________|________|________|________|________|                          |________|________|________|________|________|________|",                        
                  "|"+board[1][57]+board[2][57]+board[3][57]+board[4][57]+"|"+board[1][58]+board[2][58]+board[3][58]+board[4][58]+"|"+board[1][59]+board[2][59]+board[3][59]+board[4][59]+"|"+board[1][60]+board[2][60]+board[3][60]+board[4][60]+"|"+board[1][61]+board[2][61]+board[3][61]+board[4][61]+"|"+board[1][62]+board[2][62]+board[3][62]+board[4][62]+"|"+board[1][63]+board[2][63]+board[3][63]+board[4][63]+"          "+board[1][31]+board[2][31]+board[3][31]+board[4][31]+"|"+board[1][30]+board[2][30]+board[3][30]+board[4][30]+"|"+board[1][29]+board[2][29]+board[3][29]+board[4][29]+"|"+board[1][28]+board[2][28]+board[3][28]+board[4][28]+"|"+board[1][27]+board[2][27]+board[3][27]+board[4][27]+"|"+board[1][26]+board[2][26]+board[3][26]+board[4][26]+"|"+board[1][25]+board[2][25]+board[3][25]+board[4][25]+"|",
                  "|________|________|________|________|________|________|                          |________|________|________|________|________|________|",
                  "|"+board[1][56]+board[2][56]+board[3][56]+board[4][56]+"|"+board[1][55]+board[2][55]+board[3][55]+board[4][55]+"|"+board[1][54]+board[2][54]+board[3][54]+board[4][54]+"|"+board[1][53]+board[2][53]+board[3][53]+board[4][53]+"|"+board[1][52]+board[2][52]+board[3][52]+board[4][52]+"|"+board[1][51]+board[2][51]+board[3][51]+board[4][51]+"|                          |"+board[1][37]+board[2][37]+board[3][37]+board[4][37]+"|"+board[1][36]+board[2][36]+board[3][36]+board[4][36]+"|"+board[1][35]+board[2][35]+board[3][35]+board[4][35]+"|"+board[1][34]+board[2][34]+board[3][34]+board[4][34]+"|"+board[1][33]+board[2][33]+board[3][33]+board[4][33]+"|"+board[1][32]+board[2][32]+board[3][32]+board[4][32]+"|",
                  "|________|________|________|________|________|________|__________________________|________|________|________|________|________|________|",
                  "|                                                     |"+board[1][50]+board[2][50]+board[3][50]+board[4][50]+"|        |"+board[1][38]+board[2][38]+board[3][38]+board[4][38]+"|                                                     |",
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][49]+board[2][49]+board[3][49]+board[4][49]+"|        |"+board[1][39]+board[2][39]+board[3][39]+board[4][39]+"|                                                     |",
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][48]+board[2][48]+board[3][48]+board[4][48]+"|        |"+board[1][40]+board[2][40]+board[3][40]+board[4][40]+"|                                                     |",
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][47]+board[2][47]+board[3][47]+board[4][47]+"|        |"+board[1][41]+board[2][41]+board[3][41]+board[4][41]+"|                                                     |",
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][46]+board[2][46]+board[3][46]+board[4][46]+"|        |"+board[1][42]+board[2][42]+board[3][42]+board[4][42]+"|                                                     |",
                  "|                                                     |________|________|________|                                                     |",
                  "|                                                     |"+board[1][45]+board[2][45]+board[3][45]+board[4][45]+"|"+board[1][44]+board[2][44]+board[3][44]+board[4][44]+"|"+board[1][43]+board[2][43]+board[3][43]+board[4][43]+"|       Player2                                       |",
                  "|_____________________________________________________|________|________|________|_____________________________________________________|",
         "END"
    };
       
    int i = 0;
    while( box[i] != "END" )
    {
      cout << box[i++] << endl;
    }  
    


}
void stackGoti(int dice,string player,int input) //working
{
    if (player==p1)
    {
        board[stack_pos1[input]][pos[input]]="  ";// empty previous location
        pos[input]+=dice;
        int position=pos[input];
        for(int i=1 ; i<5 ; i++)
        {
            if(board[i][position]=="  ")
            {
                board[i][position]=p1+to_string(input); // adds the player into stack
                stack_pos1[input]=i;
                break;
            } 
        }
    }
    else
    {
        board[stack_pos2[input]][pos2[input]]="  ";// empty previous location
        pos2[input]+=dice;
        int position=pos2[input];
        for(int i=1 ; i<5 ; i++)
        {
            if(board[i][position]=="  ")
            {
                board[i][position]=p2+to_string(input);
                stack_pos2[input]=i;
                break;
            }  
        }
    }
    
    
}
void moveGoti(int input,int dice,string player) //done
{
    if (player==p1) // player1
    {
        int stack=stack_pos1[input];
        board[stack][pos[input]]="  "; // empty previous position
        stack_pos1[input]=1;// update stack pos
        pos[input]+=dice; // update postion array
        board[1][pos[input]]=p1+to_string(input); // update board
    }
    else //player 2
    {
        int stack=stack_pos2[input];
        board[stack][pos2[input]]="  "; // empty previous location
        stack_pos2[input]=1;// update stack pos
        pos2[input]+=dice; // update postion array
        board[1][pos2[input]]=p2+to_string(input); // update board
    }

}
void newGoti(string player) //not adding killed goti
{
    if (player == p1)
    {
        p1_onboard++;
        int num;
        for(int i=1;i<5;i++)
        {
            if (pos[i]==0)
            {
                num=i;
                break;
            }
        }
        pos[num]=1;
        stackGoti(0,player,num);
        cout<<"New Goti is set\n";
        dispBoard();
    }
    else
    {
        p2_onboard++;
        int num;
        for(int i=1;i<5;i++)
        {
            if (pos2[i]==32)
            {
                num=i;
                break;
            }
        }
        pos2[num]=33;  // change position
        stackGoti(0,player,num);
        cout<<"New Goti is set\n";
        dispBoard();
    }

}
void killGoti(int input,int dice,string player) // working
{
    // we already know player exists
    //to do= delete last location sey to make it disappear uskey bad
    if(player==p1) // player 1
    {
        board[stack_pos1[input]][pos[input]] = "  ";// empty previous
        pos[input] += dice;             // update position array
        int position = pos[input];      // using a variable for cleaner code
        stack_pos1[input]=1;


        for (int i = 1; i < 5; i++) // update positon of enemy to 0
        {
            if (pos2[i] == (position))
            {
                pos2[i] = 32; //updated
                board[stack_pos2[i]][position] = "  ";
                stack_pos2[i]=0;
                break;
            }
        }
        board[1][position] = p1+to_string(input); // update board
        
        p2_onboard--;
    }
    else //player 2
    {
        board[stack_pos2[input]][pos2[input]] = "  ";// empty previous
        pos2[input] += dice;             // update position array
        int position = pos2[input];      // using a variable for cleaner code
        stack_pos2[input]=1;

        for (int i = 1; i < 5; i++) // update positon of opponent peiece to 0
        {
            if (pos[i] == (position))
            {
                pos[i] = 0; // updated
                board[stack_pos1[i]][position] = "  ";
                stack_pos1[i]=0;
                break;
            }
        }
        board[1][position] = p2+to_string(input); // update board
        p1_onboard--;
    }

}
void goHome(int input,int dice,string player) // working
{

    if (player==p1)
    {
        int spaces= pos[input]+dice;
        if(spaces==63)
        {
            cout<<"Congrats you reached home. :)\n";
            stackGoti(dice,player,input);
            p1_home++;
            
        }
        else if(spaces<63)
        {
            stackGoti(dice,player,input);
        }
        else
        {
            cout<<"Better luck Next time :(\n";
        }
    
    }
    else
    {
        int spaces= pos2[input]+dice;
        if(spaces==31)
        {
            cout<<"Congrats you reached home. :)\n";
            stackGoti(dice,player,input);
            p2_home++;

        }
        else if(spaces<31)
        {
            stackGoti(dice,player,input);
        }
        else
        {
            cout<<"Better luck Next time :(\n";
        }
    }
    if(p1_home==4)
    {
        cout<<"Player 1 has won!!!!!!! woohooo";
        system("pause");
        exit(0);
    }
    else if(p2_home==4)
    {
        cout<<"Player 2 has won!!!!!!! woohooo";
        system("pause");
        exit(0);
    }
    


}
bool checkstack(int spaces,int input,string player)
{
    if (player==p1)
    {
        bool check=false;

            int j=0;
            for (int i=1;i<5;i++)
            {
                string box=board[i][spaces];
                if (box[0]==p2[0])
                {
                    j++;
                }
            }   
            if (j>1) // if enemy stack ahead
            {
                return true;
            }
            else
            {
                return false;
            }
        
    }
    else
    {
        int j=0;
        for (int i=1;i<5;i++)
        {
            string box=board[i][spaces];
            if (box[0]==p1[0])
            {
                j++;
            }
        }
        if (j>1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}
void checkCorrect(int& input,string player)
{
    if (player==p1)
    {
        bool correct=false;
        while(correct==false)
        {
            if (pos[input]==0 || pos[input]==63) // if goti is at home or not out yet
            {
                cout<<"Please enter a Goti that is playable: ";
                cin>>input;  
            }
            else // if goti entered is playable
            {
                correct=true;
            }
        }
    }
    else
    {
        bool correct=false;
        while(correct==false)
        {
            if (pos2[input]==32 || pos2[input]==31) // if goti is at home or not out yet
            {
                cout<<"Please enter a Goti that is playable: ";
                cin>>input;  
            }
            else // if goti entered is playable
            {
                correct=true;
            }
        }

    }
}
bool checkSafe(int spaces)
{
    for(int i=1;i<5;i++)
    {
        if (board[i][spaces]=="  ")
        {
            return true;
        }
    }
    return false;

}
string boxCheck(string player,int spaces)
{
    for(int i=1;i<5;i++) // checks all 4 elements of the box
    {
        string box = board[i][spaces];
        if(box[0]==player[0]) //checks for friendly
        { 
            return "friendly";
        }
        if(player==p1)
        {
            if(box[0]==p2[0])// checks for enemy
            {
                return "enemy";
            } 
        }
        else if(player==p2)
        {
            if(box[0]==p1[0])//checks for enemy
            {
                return "enemy";
            } 
        }
    }
    return "none";
}
void cornerCase(string player,int input,int& dice,int& spaces)
{
    if (player==p1)
    {
        if (pos[input]==25)//working
        {
            if((dice-1)!=1)// if not landing on spawn then do all of this.
            {
                board[stack_pos1[input]][pos[input]]="  ";//problem
                pos[input]=32;//problem
                dice--;
                spaces=pos[input]+dice;
            }
            else
            {
                spaces=32+(dice-1);
            }
        }
        if(spaces > 25 && spaces < 32) //not working
        {
            int diff=25-pos[input];
            if((dice-diff-1)!=1)// if not landing on spawn
            {
                board[stack_pos1[input]][pos[input]]="  ";//problem
                pos[input]=32;//problem
                dice=dice-diff-1;
                spaces=pos[input]+dice;
            }
            else
            {
                spaces=32+(dice-diff-1);
            }
        }

    }
    else if(player==p2)
    {
        if (pos2[input]==57)
        {
            if((dice-1)!=1)// if not landing on spawn then do all of this.
            {
            board[stack_pos2[input]][pos2[input]]="  ";
            pos2[input]=0;
            dice--;
            spaces=pos2[input]+dice;
            }
            else
            {
               spaces=0+dice-1; 
            }

        }
        if(spaces > 57 && spaces < 64) 
        {
            int diff= 57-pos2[input];
            if((dice-diff-1)!=1)// if not landing on spawn
            {
            board[stack_pos2[input]][pos2[input]]="  ";
            pos2[input]=0;
            dice=dice-diff-1;
            spaces=pos2[input]+dice;
            }
            else
            {
                spaces=0+dice-diff-1;
            }
        }

    }

}
void movement(int dice,int input,string player)// corners handled
{
    if(player==p1)
    {
        checkCorrect(input,player); // checks if correct goti number is chosen or not
        
        int spaces=pos[input]+dice;

        cornerCase(player,input,dice,spaces);// navigate corner // working
        
        while (spaces==54 || spaces==22)//safe spaces
        {
            bool check = checkSafe(spaces);
            if (check==true)
            {
                stackGoti(dice,player,input);
                dispBoard();
                return;
            }
            else
            {
                cout<<"This safe space is full :( Enter another Goti to move or Enter 0 to waste dice: ";
                cin>>input;
                if (input==0)
                {
                    return;
                }
                else
                {
                    checkCorrect(input,player);
                    spaces=pos[input]+dice;
                }
            }  
        }
        while(spaces==33) // spawn point
        {
            cout<<"Enter another Goti to move or Enter 0 to waste dice: ";
            cin>>input;
            if (input==0)
            {
                return;
            }
            else
            {
                checkCorrect(input,player);
                spaces=pos[input]+dice;
                cornerCase(player,input,dice,spaces);
            }
        }
        bool stack=checkstack(spaces,input,player);
        while(stack==true) // if enemy stack is present
        {
            cout<<"You cannot land on an enemy stack\n";
            cout<<"Please enter any other Goti to move OR enter 0 to waste dice: ";
            cin>>input;
            if (input==0)
            {
                return;
            }
            else
            {
                checkCorrect(input,player);
                spaces=pos[input]+dice;
                stack=checkstack(spaces,input,player);
            }
        }
        
        string check=boxCheck(player,spaces);
        if (spaces >58) // checking if chosen piece is near home
        {
            goHome(input,dice,player); // if near home than this function moves goti accordignly
        }
        else if(check=="enemy")
        {
            killGoti(input,dice,player); 
        }
        else if (check=="friendly") //checks if forward position has friendly
        {
            stackGoti(dice,player,input); //updates board
        }
        else
        {
            moveGoti(input,dice,player);
        }
    }
    if(player==p2) // check corner case function
    {
        checkCorrect(input,player); // checks if correct goti number is chosen or not
        
        int spaces=pos2[input]+dice;

        cornerCase(player,input,dice,spaces); //navigate the corners

        while (spaces==54 || spaces==22)//safe spaces
        {
            bool check = checkSafe(spaces);
            if (check==true)
            {
                stackGoti(dice,player,input);
                dispBoard();
                return;
            }
            else
            {
                cout<<"This safe space is full :( Enter another Goti to move or Enter 0 to waste dice: ";
                cin>>input;
                if (input==0)
                {
                    return;
                }
                else
                {
                    checkCorrect(input,player);
                    spaces=pos2[input]+dice;
                }
            }  
        }
        while(spaces==1) // spawn point
        {
            cout<<"Enter another Goti to move or Enter 0 to waste dice: ";
            cin>>input;
            if (input==0)
            {
                return;
            }
            else
            {
                checkCorrect(input,player);
                spaces=pos2[input]+dice;
                cornerCase(player,input,dice,spaces);
            }
        }
        bool stack=checkstack(spaces,input,player);
        while(stack==true) // if enemy stack is present
        {
            cout<<"You cannot land on an enemy stack\n";
            cout<<"Please enter any other Goti to move OR enter 0 to waste dice: ";
            cin>>input;
            if (input==0)
            {
                return;
            }
            else
            {
                checkCorrect(input,player);
                spaces=pos2[input]+dice;
                stack=checkstack(spaces,input,player);
            }
        }
        
        string check=boxCheck(player,spaces);
        if (spaces < 33 && spaces > 26) // checking if chosen piece is near home
        {
            goHome(input,dice,player); // if near home than this function moves goti accordignly
        }
        else if(check=="enemy")
        {
            killGoti(input,dice,player);  
        }
        else if (check=="friendly") //checks if forward position has friendly
        {
            stackGoti(dice,player,input); //updates board
        }
        else
        {
            moveGoti(input,dice,player);
        }
    }
    dispBoard();
}
void newArrays()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<100;j++)
        {
            board[i][j]="  ";
        }   
    }
    for(int m=1;m<5;m++)
    {
        pos[m]=0;
        pos2[m]=32;
        stack_pos1[m]=0;
        stack_pos2[m]=0;
    }

}
int main()
{
    int dice;int dice2;int dice3;
    int input;char choice;
    int spaces;
    srand(time(NULL));

    newArrays();
    /*Test scenarios
    board[1][50]=p1+to_string(1);pos[1]=50;stack_pos1[1]=1; //on board
    board[1][1]=p1+to_string(2);pos[2]=1;stack_pos1[2]=1; //at home
    board[1][45]=p1+to_string(3);pos[3]=45;stack_pos1[3]=1; //to be killed

    board[1][43]=p2+to_string(1);pos2[1]=43;stack_pos2[1]=1;// killer

    p1_onboard=3;p2_onboard=1;
    */

    dispBoard();
    
    while(p1_win==false&&p2_win==false)
    {
        cout<<"Player 1's Turn.\n";
        //////////////////////////P1 ki turn///////////////////
        dice = rand() % 6 + 1; // roll no.1
        cout << "You rolled a " << dice << " !!!\n";
        if (dice == 6)
        {
            dice2 = rand() % 6 + 1; // roll no.2
            cout << "You get another turn :) \n";
            cout << "You rolled a " << dice2 << " !!!\n";

            if (dice2 == 6)
            {
                dice3 = rand() % 6 + 1; // roll no.3
                cout << "You get another turn :) \n";
                cout << "You rolled a " << dice3 << " !!!\n";

                if (dice3 == 6) // all 3 dice are 6
                {
                    cout << "LOL you lost ur turn better luck next time.\n"; // bari skipped
                }
                else // dice 1 and dice 2 = 6   but dice 3 is not 6
                {
                    if(p1_onboard==p1_home)
                    {
                        newGoti(p1);
                        if(p1_onboard==4)
                        {
                            cout<<"Enter Which Goti to move: ";
                            cin>>input;
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p1);
                            if (spaces == dice2)
                            {
                                cout << "Choose Next Goti to move : ";
                                cin >> input;
                                movement(dice3, input,p1);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move : ";
                                cin >> input;
                                movement(dice2, input,p1);
                            }
                        }
                        else
                        {

                            cout << "Press N for new Goti OR Press M to move existing Goti: ";
                            cin >> choice;
                            if (choice == 'N')
                            {
                                newGoti(p1);
                                cout << "Enter which Goti to move: ";
                                cin >> input;
                                movement(dice3, input, p1);
                            }
                            if (choice == 'M')
                            {
                                cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                cin >> spaces;
                                movement(spaces, 1, p1);
                                if (spaces == dice2) //second 6 was used up
                                {
                                    movement(dice3, 1, p1);
                                }
                                else //dice 3 was used
                                {
                                    cout << "Press N for new Goti OR Press M to move existing Goti: ";
                                    cin >> choice;
                                    if (choice == 'N')
                                    {
                                        newGoti(p1); // dice 2 = 6 was used up
                                    }
                                    else
                                    {
                                        movement(dice2, 1, p1);
                                    }
                                }
                            }
                        }

                    }
                    else if (p1_onboard == 0) //checked  :)
                    {
                        newGoti(p1);
                        cout << "Press N for new Goti OR Press M to move existing Goti: ";
                        cin >> choice;
                        if (choice == 'N')
                        {
                            newGoti(p1);
                            cout << "Enter which Goti to move (1-2): ";
                            cin >> input;
                            movement(dice3, input,p1);
                        }
                        if (choice == 'M')
                        {
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, 1,p1);
                            if (spaces == dice2) //second 6 was used up
                            {
                                movement(dice3, 1,p1);
                            }
                            else //dice 3 was used
                            {
                                cout << "Press N for new Goti OR Press M to move existing Goti: ";
                                cin >> choice;
                                if (choice == 'N')
                                {
                                    newGoti(p1); // dice 2 = 6 was used up
                                }
                                else
                                {
                                    movement(dice2, 1,p1);
                                }
                            }
                        }
                    }
                    else if (p1_onboard == 4) //checked :)
                    {
                        cout << "Which goti do you want to move(1-4)?: ";
                        cin >> input;
                        cout << "How many spaces to move (" << dice << " or " << dice2 << " or " << dice3 << ")?: ";
                        cin >> spaces;
                        movement(spaces, input,p1);
                        if (spaces == dice)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p1);
                            if (spaces == dice2)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice3, input,p1);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice2, input,p1);
                            }
                        }

                        else if (spaces == dice2)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p1);
                            if (spaces == dice)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice3, input,p1);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice, input,p1);
                            }
                        }

                        else if (spaces == dice3)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p1);
                            if (spaces == dice)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice2, input,p1);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice, input,p1);
                            }
                        }
                    }
                    else if (p1_onboard < 4) // checked :)
                    {
                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                        cin >> choice;
                        if (choice == 'N') // 1 six used
                        {
                            newGoti(p1);
                            if (p1_onboard == 4) //Now if all goti are on board then just move
                            {
                                cout << "Enter Goti number to move(1-4): ";
                                cin >> input;
                                cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                cin >> spaces;
                                movement(spaces, input,p1);
                                if (spaces == dice2)
                                {
                                    cout << "Enter Goti number to move(1-4): ";
                                    cin >> input;
                                    movement(dice3, input,p1);
                                }
                                else
                                {
                                    cout << "Enter Goti number to move(1-4): ";
                                    cin >> input;
                                    movement(dice2, input,p1);
                                }
                            }
                            else
                            {

                                cout << "Press N for new goti or M if you just want to move your gotis: ";
                                cin >> choice;
                                if (choice == 'N') // 2 six used
                                {
                                    newGoti(p1);

                                    cout << "Enter Goti number to move : "; // ask which goti to move
                                    cin >> input;

                                    movement(dice3, input,p1); // last dice is just movement
                                }
                                else // use remaining dice to move
                                {
                                    cout << "Enter Goti number to move: ";
                                    cin >> input;
                                    cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p1);

                                    if (spaces == dice2)
                                    {
                                        cout << "Enter Goti number to move : ";
                                        cin >> input;
                                        movement(dice3, input,p1);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p1);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move : ";
                                            cin >> input;
                                            movement(dice2, input,p1);
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Enter Goti number to move : "; // ask which goti to move
                            cin >> input;

                            cout << "How many spaces to move (" << dice << " or " << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;

                            movement(spaces, input,p1);
                            if (spaces == dice)
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;
                                if (choice == 'N') // Dice2 = 6 is used here
                                {
                                    newGoti(p1);

                                    cout << "Enter Goti number to move : "; // ask which goti to move
                                    cin >> input;
                                    movement(dice3, input,p1);
                                }
                                else
                                {
                                    cout << "Enter Goti number to move : "; // ask which goti to move
                                    cin >> input;
                                    cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                    cin >> spaces;

                                    movement(spaces, input,p1);
                                    if (spaces == dice2)
                                    {
                                        cout << "Choose Next Goti to move : ";
                                        cin >> input;
                                        movement(dice3, input,p1);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p1);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move : ";
                                            cin >> input;
                                            movement(dice2, input,p1);
                                        }
                                    }
                                }
                            }
                            else if (spaces == dice2)
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;

                                if (choice == 'N') // Dice1=6 is used here
                                {
                                    newGoti(p1);
                                    cout << "Enter Goti number to move : "; // ask which goti to move
                                    cin >> input;
                                    movement(dice3, input,p1);
                                }
                                else
                                {
                                    cout << "How many spaces to move (" << dice << " or " << dice3 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p1);
                                    if (spaces == dice)
                                    {
                                        cout << "Choose Next Goti to move (1-4): ";
                                        cin >> input;
                                        movement(dice3, input,p1);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p1);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move : ";
                                            cin >> input;
                                            movement(dice, input,p1);
                                        }
                                    }
                                }
                            }
                            else if (spaces == dice3) // dice 2 and dice 1 are used here
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;

                                if (choice == 'N') // Dice1 is used here for new goti
                                {
                                    newGoti(p1);
                                    if (p1_onboard == 4) //dice 2 can only be used for movement
                                    {
                                        cout << "Enter Goti number to move (1-4): ";
                                        cin >> input;
                                        movement(dice2, input,p1);
                                    }
                                    else
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p1); //dice2=6 is used here for new goit
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move : "; // ask which goti to move
                                            cin >> input;
                                            movement(dice2, input,p1); //dice 2 used for movement
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "Enter Goti number to move : "; // ask which goti to move
                                    cin >> input;

                                    cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p1);
                                    if (spaces == dice) //dice1 is used here
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'M')
                                        {
                                            cout << "Enter Goti number to move : "; // ask which goti to move
                                            cin >> input;
                                            movement(dice2, input,p1);
                                        }
                                        else
                                        {
                                            newGoti(p1); //dice2=6 is used here
                                        }
                                    }
                                    else //dice 2 is used here
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'M')
                                        {
                                            cout << "Enter Goti number to move : "; // ask which goti to move
                                            cin >> input;
                                            movement(dice, input,p1);
                                        }
                                        else
                                        {
                                            newGoti(p1); //dice1 =6 is used here
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else //dice 1 =6 but dice 2 is not 6
            {
                if(p1_onboard==p1_home)
                {
                    newGoti(p1);
                    cout << "Enter goti to move?: ";
                    cin >> input;
                    movement(dice2, input,p1);
                }
                else if (p1_onboard == 0) //checked
                {
                    newGoti(p1);
                    movement(dice2, 1,p1);
                }
                else if (p1_onboard == 4) //checked
                {
                    cout << "Which goti do you want to move(1-4)?: ";
                    cin >> input;
                    cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                    cin >> spaces;
                    movement(spaces, input,p1);
                    if (spaces == dice)
                    {
                        cout << "Choose Next Goti to move(1-4): ";
                        cin >> input;
                        movement(dice2, input,p1);
                    }
                    else
                    {
                        cout << "Choose Next Goti to move(1-4): ";
                        cin >> input;
                        movement(dice, input,p1);
                    }
                }
                else if (p1_onboard < 4) // checked
                {
                    cout << "Press N for new goti or M if you just want to move your gotis: ";
                    cin >> choice;
                    if (choice == 'N') // if new goti then we initialize
                    {
                        newGoti(p1);

                        cout << "Enter Goti number : "; // now we ask what goti to move
                        cin >> input;
                        movement(dice2, input,p1); // using dice 2 since dice 1 was used to take out goti
                    }
                    else if (choice == 'M') // if they want to move gotis only
                    {
                        cout << "Enter Goti number : "; // ask which goti to move
                        cin >> input;
                        cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: "; // ask which dice to use
                        cin >> spaces;
                        movement(spaces, input,p1); // move goti acording to above choice
                        if (spaces == dice)      // if first choice was dice 1 then automatically move goti using dice 2
                        {
                            cout << "Choose Next Goti to move : ";
                            cin >> input;
                            movement(dice2, input,p1);
                        }
                        else // if first choice was dice2
                        {
                            cout << "Press N or new Goti OR Press M to move goti: ";
                            cin >> choice;
                            if (choice == 'N')
                            {
                                newGoti(p1);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move : ";
                                cin >> input;
                                movement(dice, input,p1);
                            }
                        }
                    }
                }
            }
        }
        else if(p1_onboard==p1_home) // all pieces on board are not usable
        {
            cout<<"Better luck next time.\n";
        }
        else if (dice < 6 && p1_onboard > 0)
        {
            cout << "Which Goti do you want to move?: ";
            cin >> input;

            movement(dice, input,p1);
        }
        else if (dice < 6 && p1_onboard == 0)
        {
            cout << "Better luck Next time\n";
        }
        ////////////////////////p1 ka end//////////////////////
        //break;// testing purpose
        
        system("pause");
        cout<<"Player 2's Turn.\n";
    
        /////////////////////////p2 ki turn///////////////////
        
        dice = rand() % 6 + 1; // roll no.1
        cout << "You rolled a " << dice << " !!!\n";
        if (dice == 6)
        {
            dice2 = rand() % 6 + 1; // roll no.2
            cout << "You get another turn :) \n";
            cout << "You rolled a " << dice2 << " !!!\n";

            if (dice2 == 6)
            {
                dice3 = rand() % 6 + 1; // roll no.3
                cout << "You get another turn :) \n";
                cout << "You rolled a " << dice3 << " !!!\n";

                if (dice3 == 6) // all 3 dice are 6
                {
                    cout << "LOL you lost ur turn better luck next time.\n"; // bari skipped
                }
                else // dice 1 and dice 2 = 6   but dice 3 is not 6
                {
                    if(p2_onboard==p2_home)
                    {
                        newGoti(p2);
                        if(p2_onboard==4)
                        {
                            cout<<"Enter Which Goti to move: ";
                            cin>>input;
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p2);
                            if (spaces == dice2)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice3, input,p2);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice2, input,p2);
                            }
                        }
                        else
                        {
                            cout << "Press N for new Goti OR Press M to move existing Goti: ";
                            cin >> choice;
                            if (choice == 'N')
                            {
                                newGoti(p2);
                                cout << "Enter which Goti to move (1-2): ";
                                cin >> input;
                                movement(dice3, input, p2);
                            }
                            if (choice == 'M')
                            {
                                cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                cin >> spaces;
                                movement(spaces, 1, p2);
                                if (spaces == dice2) //second 6 was used up
                                {
                                    movement(dice3, 1, p2);
                                }
                                else //dice 3 was used
                                {
                                    cout << "Press N for new Goti OR Press M to move existing Goti: ";
                                    cin >> choice;
                                    if (choice == 'N')
                                    {
                                        newGoti(p2); // dice 2 = 6 was used up
                                    }
                                    else
                                    {
                                        movement(dice2, 1, p2);
                                    }
                                }
                            }
                        }

                    }
                    else if (p2_onboard == 0) //checked  :)
                    {
                        newGoti(p2);
                        cout << "Press N for new Goti OR Press M to move existing Goti: ";
                        cin >> choice;
                        if (choice == 'N')
                        {
                            newGoti(p2);
                            cout << "Enter which Goti to move (1-2): ";
                            cin >> input;
                            movement(dice3, input,p2);
                        }
                        if (choice == 'M')
                        {
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, 1,p2);
                            if (spaces == dice2) //second 6 was used up
                            {
                                movement(dice3, 1,p2);
                            }
                            else //dice 3 was used
                            {
                                cout << "Press N for new Goti OR Press M to move existing Goti: ";
                                cin >> choice;
                                if (choice == 'N')
                                {
                                    newGoti(p2); // dice 2 = 6 was used up
                                }
                                else
                                {
                                    movement(dice2, 1,p2);
                                }
                            }
                        }
                    }
                    else if (p2_onboard == 4) //checked :)
                    {
                        cout << "Which goti do you want to move(1-4)?: ";
                        cin >> input;
                        cout << "How many spaces to move (" << dice << " or " << dice2 << " or " << dice3 << ")?: ";
                        cin >> spaces;
                        movement(spaces, input,p2);
                        if (spaces == dice)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p2);
                            if (spaces == dice2)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice3, input,p2);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice2, input,p2);
                            }
                        }

                        else if (spaces == dice2)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice << " or " << dice3 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p2);
                            if (spaces == dice)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice3, input,p2);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice, input,p2);
                            }
                        }

                        else if (spaces == dice3)
                        {
                            cout << "Choose Next Goti to move (1-4): ";
                            cin >> input;
                            cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                            cin >> spaces;
                            movement(spaces, input,p2);
                            if (spaces == dice)
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice2, input,p2);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-4): ";
                                cin >> input;
                                movement(dice, input,p2);
                            }
                        }
                    }
                    else if (p2_onboard < 4) // checked :)
                    {
                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                        cin >> choice;
                        if (choice == 'N') // 1 six used
                        {
                            newGoti(p2);
                            if (p2_onboard == 4) //Now if all goti are on board then just move
                            {
                                cout << "Enter Goti number to move(1-4): ";
                                cin >> input;
                                cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                cin >> spaces;
                                movement(spaces, input,p2);
                                if (spaces == dice2)
                                {
                                    cout << "Enter Goti number to move(1-4): ";
                                    cin >> input;
                                    movement(dice3, input,p2);
                                }
                                else
                                {
                                    cout << "Enter Goti number to move(1-4): ";
                                    cin >> input;
                                    movement(dice2, input,p2);
                                }
                            }
                            else
                            {

                                cout << "Press N for new goti or M if you just want to move your gotis: ";
                                cin >> choice;
                                if (choice == 'N') // 2 six used
                                {
                                    newGoti(p2);

                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                    cin >> input;

                                    movement(dice3, input,p2); // last dice is just movement
                                }
                                else // use remaining dice to move
                                {
                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): ";
                                    cin >> input;
                                    cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p2);

                                    if (spaces == dice2)
                                    {
                                        cout << "Enter Goti number to move (1-" << p2_onboard << "): ";
                                        cin >> input;
                                        movement(dice3, input,p2);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p2);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): ";
                                            cin >> input;
                                            movement(dice2, input,p2);
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                            cin >> input;

                            cout << "How many spaces to move (" << dice << " or " << dice2 << " or " << dice3 << ")?: ";
                            cin >> spaces;

                            movement(spaces, input,p2);
                            if (spaces == dice)
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;
                                if (choice == 'N') // Dice2 = 6 is used here
                                {
                                    newGoti(p2);

                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                    cin >> input;
                                    movement(dice3, input,p2);
                                }
                                else
                                {
                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                    cin >> input;
                                    cout << "How many spaces to move (" << dice2 << " or " << dice3 << ")?: ";
                                    cin >> spaces;

                                    movement(spaces, input,p2);
                                    if (spaces == dice2)
                                    {
                                        cout << "Choose Next Goti to move (1" << p2_onboard << "): ";
                                        cin >> input;
                                        movement(dice3, input,p2);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p2);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): ";
                                            cin >> input;
                                            movement(dice2, input,p2);
                                        }
                                    }
                                }
                            }
                            else if (spaces == dice2)
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;

                                if (choice == 'N') // Dice1=6 is used here
                                {
                                    newGoti(p2);
                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                    cin >> input;
                                    movement(dice3, input,p2);
                                }
                                else
                                {
                                    cout << "How many spaces to move (" << dice << " or " << dice3 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p2);
                                    if (spaces == dice)
                                    {
                                        cout << "Choose Next Goti to move (1-4): ";
                                        cin >> input;
                                        movement(dice3, input,p2);
                                    }
                                    else
                                    {
                                        cout << "Press N for new goti or M if you just want to move your gotis: ";
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p2);
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): ";
                                            cin >> input;
                                            movement(dice, input,p2);
                                        }
                                    }
                                }
                            }
                            else if (spaces == dice3) // dice 2 and dice 1 are used here
                            {
                                cout << "Press M to move a Goti OR Press N for new Goti: ";
                                cin >> choice;

                                if (choice == 'N') // Dice1 is used here for new goti
                                {
                                    newGoti(p2);
                                    if (p2_onboard == 4) //dice 2 can only be used for movement
                                    {
                                        cout << "Enter Goti number to move (1-4): ";
                                        cin >> input;
                                        movement(dice2, input,p2);
                                    }
                                    else
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'N')
                                        {
                                            newGoti(p2); //dice2=6 is used here for new goit
                                        }
                                        else
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                            cin >> input;
                                            movement(dice2, input,p2); //dice 2 used for movement
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                    cin >> input;

                                    cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                                    cin >> spaces;
                                    movement(spaces, input,p2);
                                    if (spaces == dice) //dice1 is used here
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'M')
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                            cin >> input;
                                            movement(dice2, input,p2);
                                        }
                                        else
                                        {
                                            newGoti(p2); //dice2=6 is used here
                                        }
                                    }
                                    else //dice 2 is used here
                                    {
                                        cout << "Press M to move a Goti OR Press N for new Goti: "; // ask which goti to move
                                        cin >> choice;
                                        if (choice == 'M')
                                        {
                                            cout << "Enter Goti number to move (1-" << p2_onboard << "): "; // ask which goti to move
                                            cin >> input;
                                            movement(dice, input,p2);
                                        }
                                        else
                                        {
                                            newGoti(p2); //dice1 =6 is used here
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else //dice 1 =6 but dice 2 is not 6
            {
                if(p2_onboard==p2_home)
                {
                    newGoti(p2);
                    movement(dice2, 1,p2);
                }
                else if (p2_onboard == 0) //checked
                {
                    newGoti(p2);
                    movement(dice2, 1,p2);
                }
                else if (p2_onboard == 4) //checked
                {
                    cout << "Which goti do you want to move(1-4)?: ";
                    cin >> input;
                    cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: ";
                    cin >> spaces;
                    movement(spaces, input,p2);
                    if (spaces == dice)
                    {
                        cout << "Choose Next Goti to move(1-4): ";
                        cin >> input;
                        movement(dice2, input,p2);
                    }
                    else
                    {
                        cout << "Choose Next Goti to move(1-4): ";
                        cin >> input;
                        movement(dice, input,p2);
                    }
                }
                else if (p2_onboard < 4) // checked
                {
                    cout << "Press N for new goti or M if you just want to move your gotis: ";
                    cin >> choice;
                    if (choice == 'N') // if new goti then we initialize
                    {
                        newGoti(p2);

                        cout << "Enter Goti number (1-" << p2_onboard << "): "; // now we ask what goti to move
                        cin >> input;
                        movement(dice2, input,p2); // using dice 2 since dice 1 was used to take out goti
                    }
                    else if (choice == 'M') // if they want to move gotis only
                    {
                        cout << "Enter Goti number (1-" << p2_onboard << "): "; // ask which goti to move
                        cin >> input;
                        cout << "How many spaces to move (" << dice << " or " << dice2 << ")?: "; // ask which dice to use
                        cin >> spaces;
                        movement(spaces, input,p2); // move goti acording to above choice
                        if (spaces == dice)      // if first choice was dice 1 then automatically move goti using dice 2
                        {
                            cout << "Choose Next Goti to move (1-" << p2_onboard << "): ";
                            cin >> input;
                            movement(dice2, input,p2);
                        }
                        else // if first choice was dice2
                        {
                            cout << "Press N or new Goti OR Press M to move goti: ";
                            cin >> choice;
                            if (choice == 'N')
                            {
                                newGoti(p2);
                            }
                            else
                            {
                                cout << "Choose Next Goti to move (1-" << p2_onboard << "): ";
                                cin >> input;
                                movement(dice, input,p2);
                            }
                        }
                    }
                }
            }
        }
        else if(p2_onboard==p2_home)
        {
            cout<<"Better luck next time\n";
        }
        else if (dice < 6 && p2_onboard > 0)
        {
            cout << "Which Goti do you want to move?(1-" << p2_onboard << ")?";
            cin >> input;

            movement(dice, input,p2);
        }
        else if (dice < 6 && p2_onboard == 0)
        {
            cout << "Better luck Next time\n";
        }
        ///////////////////////p2 ka end//////////////////////
        system("pause");

     //while loop end
    }

}