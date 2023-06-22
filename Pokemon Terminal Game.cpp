#include <iostream>

using namespace std;

class PokeType
{
    public:
        PokeType(char);
        char getType();
        double getSpeed();
        double getAttack();
        double getHP();

    private:
        char type;
        double base_speed;
        double base_attack;
        double base_hp;
};

class Trainer;

class Pokemon
{
    public:
        Pokemon();
        Pokemon(const Pokemon&);
        Pokemon(string,char,int);
        Pokemon operator++(int);

        void LevelUp();

        //get functions
        string getName();
        void setName(string);

        int getLevel();
        void setLevel(int);

        double getHP();
        void setHP(double);

        double getAttack();
        void setAttack(double);

        double getSpeed();
        void setSpeed(double);

        double getXP();
        void setXP(double);
        void addXp(double);

        PokeType* getType();
        void setType(PokeType*);

        double getTotalHp();
        void setTotalHp(double);

        ~Pokemon();



        //variables 
    private:
        string name;
        int level;
        PokeType* type;
        double current_hp;
        double current_speed;
        double current_attack;
        double xp; 
        double total_hp;
        Trainer* trainer; 
};
void Pokemon ::LevelUp()
{
    level++;
    total_hp=total_hp*1.1;
    current_hp=current_hp*1.1;
    current_attack=current_attack*1.05;
    xp=0;
}

Pokemon :: ~Pokemon()
{
    delete type;
}



class Trainer
{
    public:
        Trainer(string);
        Trainer();
        void AddPokemon(Pokemon);
        void DisplayPokemon();
        void DisplayParty();
        void operator + (Pokemon);
        friend ostream & operator<<(ostream&,Trainer&);
        void battle(Trainer&,int,int);
        void attack(Trainer&,int,int);
        bool lost();
        bool fainted(int);

        void LevelUp();

        //set get funcs
        void RemoveFromParty(int);
        void AddToParty(int);
        void RemoveFromCollection(int);
        string getName();
        void setName(string);
        int getInParty();
        int getOwned();
        void addXp();

        string getPokemonName(int);

        void restoreHp();

        ~Trainer();
        
    private:
        string name;
        int owned;
        int in_party;
        Pokemon* pokemon_owned;
        Pokemon* current_party[6];
};

void Trainer :: LevelUp()
{
    for (int i = 0; i < 6; i++)
    {
        if(current_party[i] != nullptr)
        {
            if(current_party[i]->getXP()>1)
            {
                current_party[i]->LevelUp();
            }
            
        }
    }
    
}

void DisplayPikachu()
{
    cout<<"@@@@@@#                                                                                         "<<endl;
    cout<<" @@@@@@***/@                                                                #@@@@@@.            "<<endl;
    cout<<"  *@@@@%******/&                                                      &(***&@@@@@@              "<<endl;
    cout<<"    &@@@**********@.                                             *%********@@@@@&               "<<endl;
    cout<<"      @@%***********(&                                        &***********#@@@@                 "<<endl;
    cout<<"        @#*************@                                   &**************@@@                   "<<endl;
    cout<<"          #/*************&                              ,(***************@(               *%&   "<<endl;
    cout<<"             &************/*   .&(***************(&,  (***************#(         .%@(*******(   "<<endl;
    cout<<"               .&**************************************************@.      (@(*************(,   "<<endl;
    cout<<"                   #/****/*************************************&     *@(*******************&    "<<endl;
    cout<<"                       /************************************#   #&*************************(    "<<endl;
    cout<<"                     /***************************************&****************************#     "<<endl;
    cout<<"                     &****************************************#***************************%     "<<endl;
    cout<<"                     &*****(@@@/********************@@@&******&**************************%      "<<endl;
    cout<<"                     &***(@@@   @*****************&.  &@@&****%*************************/,      "<<endl;
    cout<<"                     #***/&&@@@@@*****************#@@@@&&%****%********************/&&*         "<<endl;
    cout<<"                    &*******/(*********************************#**********/&%.                  "<<endl;
    cout<<"                   /&((((&*********************************&%%&&*****(.                         "<<endl;
    cout<<"                   %(((((((&*******(&#&@/***&%*(%*******&((((((#(******//                       "<<endl;
    cout<<"                    &((((((((**************************&(((((((@**********%                     "<<endl;
    cout<<"                     &((((#%***************************##(((((@%************&                   "<<endl;
    cout<<"                       ##***********************************&.    ((**********@                 "<<endl;
    cout<<"                       &**/&*****************************%/*(   %/*********/@*                  "<<endl;
    cout<<"                       /*******%*********************%/******%********%(                        "<<endl;
    cout<<"                      #**************//////////***************(**(*#                            "<<endl;
    cout<<"                    ******************************************/######&                          "<<endl;
    cout<<"                   &*****************(*********/****************&#&,                            "<<endl;
    cout<<"                 %********************%*******%******************&                              "<<endl;
    cout<<"                &*********************#******%***************/****(.                            "<<endl;
    cout<<"               %*****/*****************/*****%***************(*****(,                           "<<endl;
    cout<<"         &*(**%&******#****************%*****(**************&*******%  %&(                      "<<endl;
    cout<<"         %#*#****%*****/***************&****(**************@*******&***%*(/                     "<<endl;
    cout<<"          ,(/////******/#**************&////#*************&*****%**///(/&                       "<<endl;
    cout<<"            ,(//////*****@*************#////(***********/#******//////@                         "<<endl;
    cout<<"              ,%//////////(%**********/(/////#*********&////**/////(%                           "<<endl;
    cout<<"                 @//////#////#********%     *********((///%//////@                              "<<endl;
    cout<<"                    #&&.      &/%#/(          ,./&*/%   *(///&(                                 "<<endl;
}

void Player2Wins()
{
    cout<<"\n\n";
    cout<<"   ________  ___       ________      ___    ___ _______   ________           _______          ___       __   ___  ________   ________      "<<endl;
    cout<<"  |\\   __  \\|\\  \\     |\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\   __  \\         /  ___  \\        |\\  \\     |\\  \\|\\  \\|\\   ___  \\|\\   ____\\     "<<endl;
    cout<<"  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\|\\  \\   \\ \\  \\/  / | \\   __/|\\ \\  \\|\\  \\       /__/|_/  /|       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\___|_    "<<endl;
    cout<<"   \\ \\   ____\\ \\  \\    \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\   _  _\\      |__|//  / /        \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\_____  \\   "<<endl;
    cout<<"    \\ \\  \\___|\\ \\  \\____\\ \\  \\ \\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\  \\\\  \\|         /  /_/__        \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\|____|\\  \\  "<<endl;
    cout<<"     \\ \\__\\    \\ \\_______\\ \\__\\ \\__\\__/  / /      \\ \\_______\\ \\__\\\\ _\\        |\\________\\       \\ \\____________\\ \\__\\ \\__\\\\ \\__\\____\\_\\  \\ "<<endl;
    cout<<"      \\|__|     \\|_______|\\|__|\\|__|\\___/ /        \\|_______|\\|__|\\|__|        \\|_______|        \\|____________|\\|__|\\|__| \\|__|\\_________\\"<<endl;
    cout<<"                                   \\|___|/                                                                                     \\|_________|"<<endl;

}

void Player1Wins()
{
    cout<<"\n\n";
    cout<<"   ________  ___       ________      ___    ___ _______   ________           _____          ___       __   ___  ________   ________      "<<endl;
    cout<<"  |\\   __  \\|\\  \\     |\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\   __  \\         / __  \\        |\\  \\     |\\  \\|\\  \\|\\   ___  \\|\\   ____\\     "<<endl;
    cout<<"  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\|\\  \\   \\ \\  \\/  / | \\   __/|\\ \\  \\|\\  \\       |\\/_|\\  \\       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\___|_    "<<endl;
    cout<<"   \\ \\   ____\\ \\  \\    \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\   _  _\\      \\|/ \\ \\  \\       \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\_____  \\   "<<endl;
    cout<<"    \\ \\  \\___|\\ \\  \\____\\ \\  \\ \\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\  \\\\  \\|          \\ \\  \\       \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\|____|\\  \\  "<<endl;
    cout<<"     \\ \\__\\    \\ \\_______\\ \\__\\ \\__\\__/  / /      \\ \\_______\\ \\__\\\\ _\\           \\ \\__\\       \\ \\____________\\ \\__\\ \\__\\\\ \\__\\____\\_\\  \\ "<<endl;
    cout<<"      \\|__|     \\|_______|\\|__|\\|__|\\___/ /        \\|_______|\\|__|\\|__|           \\|__|        \\|____________|\\|__|\\|__| \\|__|\\_________\\"<<endl;
    cout<<"                                   \\|___|/                                                                                   \\|_________|"<<endl; 
}

string Trainer :: getPokemonName(int Pokemon)
{
    return current_party[Pokemon-1]->getName();
}
void Trainer :: addXp()
{
    for (int i = 0; i < 6; i++)
    {
        if(current_party[i]!= nullptr)
        {
            current_party[i]->addXp(10);
        }
    }
    

}
bool Trainer :: fainted(int pokemon)
{
    if(current_party[pokemon-1]->getHP()==0)
    {
        return true;
    }
    return false;
}

void Trainer :: attack(Trainer& other, int pokemon1,int pokemon2)
{
    int hp1=current_party[pokemon1-1]->getHP();
    int hp2 = other.current_party[pokemon2-1]->getHP();
    
    int attack1=current_party[pokemon1-1]->getAttack();

    if ( ( hp2 - attack1 ) < 0)
    {
        other.current_party[pokemon2-1]->setHP(0);
    }
    else
    {
        other.current_party[pokemon2-1]->setHP( (hp2 - attack1) );
    }
}

void Trainer :: battle(Trainer& other, int pokemon1, int pokemon2)
{
    int speed1 = current_party[pokemon1-1]->getSpeed();
    int speed2 = other.current_party[pokemon2-1]->getSpeed();

    int hp1=current_party[pokemon1-1]->getHP();
    int hp2 = other.current_party[pokemon2-1]->getHP();

    int attack1=current_party[pokemon1-1]->getAttack();
    int attack2=other.current_party[pokemon2-1]->getAttack();

    if(speed1 > speed2) // if p1 attacks first
    {
        if( ( hp2 - attack1 ) <  0 )
        {
            other.current_party[pokemon2-1]->setHP(0);
            return;
        }
        else
        {
            other.current_party[pokemon2-1]->setHP( (hp2 - attack1) );
        }

        if( ( hp1  -  attack2 ) < 0 )
        {
            current_party[pokemon1-1]->setHP(0);
        }
        else
        {
            current_party[pokemon1-1]->setHP( (hp1 - attack2) );
        }
    }
    else // p2 attacks first
    {
        if( ( hp1 - attack2 ) < 0 )
        {
            current_party[pokemon1-1]->setHP(0);
            return;
        }
        else
        {
            current_party[pokemon1-1]->setHP(hp1 - attack2);
        }

        if( ( hp2 - attack1 ) < 0 )
        {
           other.current_party[pokemon2-1]->setHP(0);
        }
        else
        {
           other.current_party[pokemon2-1]->setHP(hp2 - attack1);
        }


    }

}
bool Trainer:: lost()
{
    for (int i = 0; i < in_party; i++)
    {
        if(current_party[i]->getHP()!= 0)
        {
            return false;
        }
    }

    return true;

}
void Trainer :: restoreHp()
{
    for (int i = 0; i < in_party; i++)
    {
        current_party[i]->setHP(current_party[i]->getTotalHp());
    }
}

int Trainer :: getOwned()
{
    return owned;
}
void Trainer :: RemoveFromCollection(int n)
{
    Pokemon* temp;

    if ((owned - 1) != 0)
    {
        temp = new Pokemon[owned - 1];
        int j = 0;
        for (int i = 0; i < owned; i++)
        {
            if (i != (n - 1))
            {
                temp[j] = pokemon_owned[i];
                j++;
            }
        }
    }

    owned--;
    delete[] pokemon_owned;

    if (owned != 0)
    {
        pokemon_owned = new Pokemon[owned];

        for (int i = 0; i < owned; i++)
        {
            pokemon_owned[i] = temp[i];
        }
        delete[] temp;
    }
}

void Trainer::AddToParty(int n)
{
    if(in_party==0)
    {

        in_party++;

        current_party[0]= new Pokemon;

        *(current_party[0])=pokemon_owned[n-1];

        //delete from pokemon owned

        RemoveFromCollection(n);
        
        
    }
    else
    {
        in_party++;
        for (int i = 0; i < 6; i++)
        {
            if(current_party[i] == nullptr)
            {
                current_party[i] = new Pokemon;
                *(current_party[i])=pokemon_owned[n-1];
                break;
            }
        }

        RemoveFromCollection(n);
    }
}

void Trainer::RemoveFromParty(int n)
{
    (*this)+(*(current_party[n-1])); // add to collection

    delete current_party[n-1];

    current_party[n-1]=nullptr; // remove from current party

    Pokemon* temp_party[6]={nullptr};

    // cout<<"\nLine 314\n";
    int j=0;

    for (int i = 0; i < 6; i++)
    {
        if( current_party[i] != nullptr )
        {
            temp_party[j]=current_party[i];
            j++;
        }
    }
    // cout<<"\nLine 324\n";
    // for (int i = 0; i < 6; i++)
    // {
    //     if(current_party[i]!=nullptr)
    //     {
    //       delete current_party[i];  
    //     }
    // } why can we not delete all pokemon
    // cout<<"\nLine 331\n";

    for (int i = 0; i < 6; i++)
    {
        current_party[i]=nullptr;
    }
    
    for (int i = 0; i < 6; i++)
    {
        current_party[i]=temp_party[i];
    }
    
    in_party--;
 
}

int Trainer::getInParty()
{
    return in_party;
}

void Trainer::DisplayParty()
{
    cout<<name<<"'s Pokemon in Current Party: \n";
    for (int i = 0; i < 6; i++)
    {
        if(current_party[i] != nullptr)
        {
            cout<<i+1<<". "<<current_party[i]->getName()<<" -- Level "<<current_party[i]->getLevel()<<" -- Current Hp "<<current_party[i]->getHP()<<endl;
            cout<<"Attack: "<<current_party[i]->getAttack()<<endl;
        }
    }
    cout<<endl;
    
}



Pokemon AddPokemonHelper();
int getTrainerIndex(Trainer* &trainers,int num_trainers,string name)
{
    for (int i = 0; i < num_trainers; i++)
    {
        if(name == trainers[i].getName())
        {
           return i; 
        }
    }
    cout<<"Trainer not found\n";
    return -1;
    

}
void Battle(Trainer* &trainers,int num_trainers,int tr1,int tr2)
{

    int pokemon1,pokemon2;
    cout<<"\nPlayer 1's Turn\n";

    trainers[tr1].DisplayParty();
    cout<<"Choose your Pokemon: ";
    cin>>pokemon1;

    cout<<"\n\nPlayer 2's Turn\n";

    trainers[tr2].DisplayParty();
    cout<<"Choose your Pokemon: ";
    cin>>pokemon2;

    int choice1,choice2;

    cout<<"Player 1's Pokemon:"<<trainers[tr1].getPokemonName(pokemon1)<<endl;
    cout<<"Player 2's Pokemon:"<<trainers[tr2].getPokemonName(pokemon2)<<endl;

    while( (choice1 != 3) || (choice2 != 3) )
    {
        cout << "\nPlayer 1's Turn\n";

        cout << "Press 1 to Attack\n";
        cout << "Press 2 to Switch\n";
        cout << "Press 3 to forfiet :(\n";
        cout << "What will you do?: ";
        cin >> choice1;

        cout << "\n\nPlayer 2's Turn\n";

        cout << "Press 1 to Attack\n";
        cout << "Press 2 to Switch\n";
        cout << "Press 3 to forfiet :(\n";
        cout << "What will you do?: ";
        cin >> choice2;

        if(choice1==3) // p1 forfiet
        {
            Player2Wins();
            trainers[tr2].addXp();
            trainers[tr1].restoreHp();
            trainers[tr2].restoreHp();
            return;
        }
        if(choice2==3) // p2 forfiet
        {
            Player1Wins();
            trainers[tr1].addXp();
            trainers[tr1].restoreHp();
            trainers[tr2].restoreHp();
            return;
        }

        if(choice1 == 1 && choice2 == 1) // both attack
        {
            //attack attack
            trainers[tr1].battle(trainers[tr2],pokemon1,pokemon2);

            if(trainers[tr1].lost()==true)
            {
                Player2Wins();
                trainers[tr2].addXp();
                trainers[tr1].restoreHp();
                trainers[tr2].restoreHp();
                return;
            }
            if(trainers[tr2].lost()==true)
            {
                Player1Wins();
                trainers[tr1].addXp();
                trainers[tr1].restoreHp();
                trainers[tr2].restoreHp();
                return;
            }

            if(trainers[tr1].fainted(pokemon1)==true)
            {
                cout<<"Player 1's Pokemon Fainted :(\n";
                trainers[tr1].DisplayParty();
                cout<<"Choose your pokemon:";
                cin>>pokemon1;
            }
            if(trainers[tr2].fainted(pokemon2)==true)
            {
                cout<<"Player 2's Pokemon Fainted :(\n";
                trainers[tr2].DisplayParty();
                cout<<"Choose your pokemon:";
                cin>>pokemon2;

            }


        }
        if(choice1 == 1 && choice2 == 2) // p1 attack p2 switch
        {
            // p1 attack
            trainers[tr1].attack(trainers[tr2],pokemon1,pokemon2);

            if(trainers[tr2].lost()==true)
            {
                Player1Wins();
                trainers[tr1].addXp();
                trainers[tr1].restoreHp();
                trainers[tr2].restoreHp();
            }
            if(trainers[tr2].fainted(pokemon2)==true)
            {
                cout<<"Player 2's Pokemon Fainted :(\n";
                trainers[tr2].DisplayParty();
                cout<<"Choose your pokemon:";
                cin>>pokemon2;

            }
            else
            {
                cout<<"Player 2 Switch Pokemon\n";
                trainers[tr2].DisplayParty();
                cout<<"Choose your Pokemon: ";
                cin>>pokemon2;
            }

        }
        if(choice1 == 2 && choice2 == 1) // P2 attack p1 switch
        {
            // p2 attack
            trainers[tr2].attack(trainers[tr1],pokemon2,pokemon1);

            if(trainers[tr1].lost()==true)
            {
                Player2Wins();
                trainers[tr2].addXp();
                trainers[tr1].restoreHp();
                trainers[tr2].restoreHp();
                return;
            }
            if(trainers[tr1].fainted(pokemon1)==true)
            {
                cout<<"Player 1's Pokemon Fainted :(\n";
                trainers[tr1].DisplayParty();
                cout<<"Choose you pokemon:";
                cin>>pokemon1;
            }
            else
            {
                cout<<"Player 1 Switch Pokemon\n";
                trainers[tr1].DisplayParty();
                cout<<"Choose your Pokemon: ";
                cin>>pokemon1;

            }
            
        }
        if(choice1 == 2 && choice2 == 2) // both switch
        {
            cout<<"Player 1 Switch Pokemon\n";
            trainers[tr1].DisplayParty();
            cout<<"Choose your Pokemon: ";
            cin>>pokemon1;

            cout<<"Player 2 Switch Pokemon\n";
            trainers[tr2].DisplayParty();
            cout<<"Choose your Pokemon: ";
            cin>>pokemon2;
            
        }

        cout<<"\nPlayer 1's Current Pokemon:"<<trainers[tr1].getPokemonName(pokemon1)<<endl;
        trainers[tr1].DisplayParty();

        cout<<"Player 2's Current Pokemon:"<<trainers[tr2].getPokemonName(pokemon2)<<endl;
        trainers[tr2].DisplayParty();
    }





}
void BattleMenu(Trainer* &trainers,int num_trainers)
{
    for (int i = 0; i < num_trainers; i++)
    {
        cout << i + 1 << ".  " << trainers[i].getName() << endl;
    }

    string t1,t2;
    int tr1=-1;int tr2=-1;
    while (tr1 == -1 || tr2 == -1) // until correct name not entered
    {
        cout<<"Enter name of Trainer 1: ";
        cin>>t1;
        cout<<"Enter name of Trainer 2: ";
        cin>>t2;
        tr1=getTrainerIndex(trainers,num_trainers,t1);
        tr2=getTrainerIndex(trainers,num_trainers,t2);
    }

    if( (trainers[tr1].getInParty()==0) || (trainers[tr2].getInParty()==0) )
    {
        cout<<"Both Trainers must have Pokemon to start a Battle\n";
        return;
    }

    cout<<"\nStadium: LUMS(no boost only stress)\n";


    cout<<"\n\n\n\n";

    Battle(trainers,num_trainers,tr1,tr2);

    trainers[tr1].LevelUp();
    trainers[tr2].LevelUp();




    
}
void CreateTrainerHelper(Trainer* &trainers,int num)
{
    Trainer *temp;
    if (num != 1)
    {
        temp = new Trainer[num - 1];

        for (int i = 0; i < num - 1; i++)
        {
            temp[i] = trainers[i];
        }
    }
    trainers = new Trainer[num];

    if(num!=1)
    {
        for (int i = 0; i < num-1; i++)
        {
            trainers[i]=temp[i];
        }
    }

    string n;

    cout<<"Enter name of trainer: ";
    cin>>n;

    trainers[num-1].setName(n);


}
void AddToPartyHelper(int choice,int n,Trainer* &trainers)
{
    if(trainers[n-1].getInParty()==6)
    {
        int num;
        trainers[n-1].DisplayParty();
        cout<<"Party is Full\n";
        cout<<"Enter Number of Pokemon to remove:";
        cin>>num;

        trainers[n-1].RemoveFromParty(num);

        cout<<trainers[n-1];
        cout<<"Enter Number of Pokemon to add to party:";
        cin>>num;

        trainers[n-1].AddToParty(num);
    }
    else
    {

        // cout<<trainers[n-1];
        // cout<<"Enter Number of Pokemon to add to party:";
        // cin>>num;

        trainers[n-1].AddToParty(choice);
    }


}
void CurrentPartyMenu(int n,Trainer* &trainers)
{
    int choice=0;
    while (choice != 4)
    {
        cout<<"Current Party Management:\n";
        cout<<"  1.View Current Party\n";
        cout<<"  2.Add Pokemon to the Current Party\n";
        cout<<"  3.Remove Pokemon from the Current Party\n";
        cout<<"  4.Return to Trainer Menu\n";
        cin>>choice;

        if (choice == 1)
        {
            if(trainers[n-1].getInParty()==0)
            {
                cout<<"Current Party has no pokemon\n";
            }
            else
            {
                trainers[n-1].DisplayParty();
            }
            
        }
        else if(choice ==2)
        {
            int choice=0;
            cout<<trainers[n-1]; // display collection

            cout<<"Enter Number of Pokemon to add to party:";
            cin>>choice;

            AddToPartyHelper(choice,n,trainers);

        }
        else if(choice == 3)
        {
            trainers[n-1].DisplayParty();

            cout<<"Enter Number of Pokemon to remove from party:";
            cin>>choice;
            
            trainers[n-1].RemoveFromParty(choice);

        }
        
        
    }


}

void TrainerMenu(int n,Trainer* &trainers)
{
    int choice=0;

    while(choice != 4)
    {
        cout<<trainers[n-1].getName()<<"'s Menu:\n";
        cout<<"   1. Add Pokemon?\n";
        cout<<"   2. Display Pokemon?\n";
        cout<<"   3. Manage Current Party\n";
        cout<<"   4. Return to Main Menu?\n";
        cin>>choice;

        if (choice == 1)
        {
            (trainers[n-1])+(AddPokemonHelper());
        }
        if(choice ==2)
        {
            if(trainers[n-1].getOwned()==0)
            {
                cout<<"No Pokemon in collection. Go Catch some more\n";
            }
            else
            {
                cout<<trainers[n-1];
            }

        }
        if(choice == 3)
        {
            CurrentPartyMenu(n,trainers);
        }
    }

}

void Menu(Trainer* &trainers,int &num)
{
    int choice = 0;
    while (choice != 3)
    {

        cout << "What would you like to do:\n";
        cout << "\t1. Create a Trainer\n";
        cout << "\t2. Access a Trainer\n";
        cout << "\t3. Exit to Main Menu\n";
        cin >> choice;

        if (choice == 1) // New Trainer
        {
            num++;
            CreateTrainerHelper(trainers, num);
        }
        else if (choice == 2) // Display Trainer
        {
            if (num == 0)
            {
                int c;
                cout << "No Trainers Exist :( \n";
                cout << "Do you want to make a Trainer ? (Enter 1 for YES OR 2 for NO)";
                cin >> c;

                if (c == 1)
                {
                    num++;
                    CreateTrainerHelper(trainers, num);
                }
            }
            else
            {
                int c;
                for (int i = 0; i < num; i++)
                {
                    cout << i + 1 << ".  " << trainers[i].getName() << endl;
                }

                cout << "Choose your Trainer: ";
                cin >> c;

                TrainerMenu(c, trainers);
            }
        }
        else
        {
            return;
        }
    }
    // while (num == 0) // if no trainers exist
    // {
    //     char c;
    //     cout<<"Do you want to create a Trainer?(y/n)";
    //     cin>>c;
    //     if (c == 'n')
    //     {
    //         return;
    //     }
    //     else
    //     {
    //         num++;
    //         CreateTrainerHelper(trainers,num);
    //     }

    // }
    // char c='y';
    // while(c=='y') // ask to make new trainer if if previous exist
    // {
    //     cout<<"\n\nDo you want to create a Trainer?(y/n)";
    //     cin>>c;

    //     if(c =='y')
    //     {
    //         num++;
    //         CreateTrainerHelper(trainers,num);
    //     }

    // }
    // int n=0;
    // cout<<"\nEnter Trainer number: ";
    // cin>>n;

    // if (n>num)
    // {
    //     cout<<"\nTrainer does not exist :(\n";
    //     return; // return to main menu
    // }

    

    // int choice;

    // while(choice != 3)
    // {
    //     cout<<trainers[n-1].getName()<<"'s Menu:\n";
    //     cout<<"   1. Add Pokemon?\n";
    //     cout<<"   2. Display Pokemon?\n";
    //     cout<<"   3. Return to Main Menu?\n";
    //     cin>>choice;

    //     if (choice == 1)
    //     {
    //         (trainers[n-1])+(AddPokemonHelper());
    //     }
    //     if(choice ==2)
    //     {
    //         cout<<trainers[n-1];

    //     }
    // }
}
void Game()
{
    Trainer* trainers;
    int num_trainers=0;

    int choice=0;

    while (choice != 3)
    {

        cout << "Enter one of the options to proceed\n";
        cout << "   1. Trainer Menu?\n";
        cout << "   2. Battle Menu?\n";
        cout << "   3. Exit?\n";
        cin >> choice;

        if (choice == 1)
        {
            Menu(trainers, num_trainers);
        }
        if(choice ==2)
        {
            if(num_trainers<2)
            {
                cout<<"There must be atleast 2 Trainers in game to Battle\n";
            }
            else
            {
                BattleMenu(trainers,num_trainers);
            }
        }
        if (choice == 3)
        {
            return;
        }
    }

    delete[] trainers;
}


Pokemon AddPokemonHelper()
{
    string n;
    int l;
    char ty;

    cout<<"Enter name of Pokemon: ";
    cin>>n;
    cout<<"Enter level of Pokemon: ";
    cin>>l;
    cout<<"Enter type of Pokemon: ";
    cin>>ty;

    cout<<"\n\n";
    Pokemon temp(n,ty,l);

    return temp;

}


int main()
{
    DisplayPikachu();
    cout<<"\nWelcome to Pokemon LUMSU edition\n";
    Game();
    
}

//Trainer functions
Trainer :: ~Trainer()
{
    delete[] pokemon_owned;
    for (int i = 0; i < in_party; i++)
    {
        if(current_party[i]!= nullptr)
        {
            delete current_party[i];
        }
    }
    
}

string Trainer:: getName()
{
    return name;
}
void Trainer :: setName(string n)
{
    name=n;
}

Trainer :: Trainer()
{
    name="";
    pokemon_owned=NULL;
    for (int i = 0; i < 6; i++)
    {
        current_party[i]=nullptr;
    }
    

    owned=0;
    in_party=0;

}

ostream & operator<<(ostream &out,Trainer &bro)
{
    bro.DisplayPokemon();
    return out;
}

void Trainer :: operator+(Pokemon catched)
{
    AddPokemon(catched);
    cout<<"Gotta catch em all\n";

}

Trainer :: Trainer(string n)
{
    name=n;
    pokemon_owned = NULL;

    for (int i = 0; i < 6; i++)
    {
        current_party[i]=nullptr;
    }
    

    owned=0;
    in_party=0;
}

void Trainer ::AddPokemon(Pokemon catched)
{
    Pokemon* prev_owned;
    if (owned > 0) // storing all previous pokemon
    {
        prev_owned = new Pokemon[owned];

        for (int i = 0; i < owned; i++)
        {
            prev_owned[i]=pokemon_owned[i];
        }

    }

    owned++;

    pokemon_owned= new Pokemon[owned];

    if((owned-1) >0)
    {
        for (int i = 0; i < (owned-1); i++)
        {
            pokemon_owned[i]=prev_owned[i];
        }
    }

    pokemon_owned[owned-1]=catched;



}

void Trainer :: DisplayPokemon()
{
    cout<<name<<"'s Pokemon: \n";
    for (int i = 0; i < owned; i++)
    {
        cout<<i+1<<". "<<pokemon_owned[i].getName()<<" -- Level "<<pokemon_owned[i].getLevel()<<endl;
        // cout<<"Current hp: "<<pokemon_owned[i].getHP()<<endl;
        // cout<<"Current attack: "<<pokemon_owned[i].getAttack()<<endl;
        // cout<<"Current speed: "<<pokemon_owned[i].getSpeed()<<"\n\n";
    }
    cout<<endl;
    
}


//Poketype functions
char PokeType :: getType()
{
    return type;
}
double PokeType :: getAttack()
{
    return base_attack;
}
double PokeType :: getSpeed()
{
    return base_speed;
}
double PokeType :: getHP()
{
    return base_hp;
}

PokeType :: PokeType(char t)
{
    type=t;
    if(t=='f')
    {
        base_speed=10;
        base_attack=15;
        base_hp=65;
    }
    else if(t=='w')
    {
        base_speed=5;
        base_attack=20;
        base_hp=100;
    }
    else
    {
        base_speed=2;
        base_attack=25;
        base_hp=50; 
    }
}


//Pokemon functions
void Pokemon :: setTotalHp(double hp)
{
    total_hp=hp;
}

Pokemon :: Pokemon()
{
    name="";
    type=NULL;
    level=1;
    current_hp=0;
    current_speed=0;
    current_attack=0;
    total_hp=0;
    xp=0;
    trainer=nullptr;
}

Pokemon Pokemon :: operator++(int i)
{
    Pokemon temp(*this);
    level++;
    total_hp=total_hp*1.1;
    current_hp=current_hp*1.1;
    current_attack=current_attack*1.05;
    xp=0;

    return temp;
}
Pokemon :: Pokemon(const Pokemon &OG) //copy constructor
{

        name = OG.name;
        char what_type = OG.type->getType();
        type = new PokeType(what_type);
        current_attack = OG.current_attack;
        current_speed = OG.current_speed; 
        level = OG.level;         
        trainer = OG.trainer;
        current_hp = OG.current_hp;
        total_hp=OG.total_hp;
        xp = OG.xp;
}

Pokemon :: Pokemon(string n,char t,int l)
{
    
    name=n;
    trainer=nullptr;
    level=l;
    type = new PokeType(t);
    current_hp = type->getHP();
    total_hp=current_hp;
    current_attack= type->getAttack();
    if(level>1)
    {
        for (int i = 1; i < level; i++)
        {
            total_hp=total_hp*1.1;
            current_hp=current_hp*1.1;
            current_attack=current_attack*1.05;
        }
    }
    current_speed= type->getSpeed();
    xp=0;

}


// type get set
void Pokemon :: addXp(double add)
{
    xp+=add;
}
void Pokemon::setType(PokeType* t)
{
    type=t;
}

PokeType* Pokemon :: getType()
{
    return type;
}

// xp get set
double Pokemon :: getXP()
{
    return xp;
}
void Pokemon :: setXP(double x)
{
    xp= x;
}
// speed get set

double Pokemon :: getSpeed()
{
    return current_speed;
}
void Pokemon :: setSpeed(double s)
{
    current_speed= s;
}

// attack get set
double Pokemon :: getAttack()
{
    return current_attack;
}
void Pokemon :: setAttack(double a)
{
    current_attack= a;
}
// level get set

int Pokemon :: getLevel()
{
    return level;
}
void Pokemon :: setLevel(int l)
{
    level=l;
}

// HP get set
double Pokemon :: getTotalHp()
{
    return total_hp;
}
double Pokemon :: getHP()
{
    return current_hp;
}
void Pokemon :: setHP(double h)
{
    current_hp= h;
}

//name set get
string Pokemon :: getName()
{
    return name;
}
void Pokemon :: setName(string n)
{
    name=n;
}