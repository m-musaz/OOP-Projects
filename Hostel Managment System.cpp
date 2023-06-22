#include <iostream>
#include <queue>

using namespace std;

class Booking_info
{
    public:
        Booking_info()
        {
            available=1;
            date_of_booking="/01/2022";
            int start =0;
            int end =0;
            int days_booked=0;
            type='m';
            room_type=1;

            name="";
            cnic=0;
            phone=0;
            
        };
        int getAvail()
        {
            return available;
        }
        int getType()
        {
            return room_type;
        };
        void setAvail(int a)
        {
            available=a;
        };
        void setRoomType(int a)
        {
            room_type=a;
        }
        void reserve(char hostel,int room_num)
        {
            cout<<"Enter Date of Booking in Format(DD/MM/YYYY): ";
            cin>>date_of_booking;

            cout<<"Enter Start of Occupancy (1-8)(1st Jan to 8th Jan): ";
            cin>>start;

            cout<<"Enter End of Occupancy: ";
            cin>>end;

            days_booked = end-start;
            days_booked++;

            type=hostel;

            if(hostel == 'm')
            {
                room_type=2;
            }
            else //female hostel
            {
                if(room_num > 15)
                {
                    room_type=1;
                }
                else
                {
                    room_type=2;
                }
            }

            cout<<"Enter your Name: ";
            cin>>name;
            cout<<"Enter your CNIC: ";
            cin>>cnic;
            cout<<"Enter your Phone Number: ";
            cin>>phone;




        }
        bool empty_waitlist()
        {
            if(start==0)
            {
                return true;
            }
            return false;
        }
        string getName()
        {
            return name;
        }
        string getBD()
        {
            return date_of_booking;
        }
        int getDaysBooked()
        {
            return days_booked;
        }
        int getStartDay()
        {
            return start;
        }
        int getEndDay()
        {
            return end;
        }
        int getCNIC()
        {
            return cnic;
        }
        int getPhone()
        {
            return phone;
        }
        void checkout(char hostel,int room_num)
        {
            cout<<"////////////Checkout Reciept////////////\n";
            cout<<"Delegate Name      : "<<name<<endl;
            cout<<"Delegate CNIC      : "<<cnic<<endl;
            cout<<"Delegate Phone     : "<<phone<<endl;
            if(hostel == 'm')
            {
                cout<<"Hostel             : Male\n";
            }
            else
            {
                cout<<"Hostel             : Female\n";
            }
            cout<<"Occupancy Type     : "<<room_type<<endl;
            cout<<"Room Number        : "<<room_num<<endl;
            cout<<"Booking Date       : "<<date_of_booking<<endl;
            cout<<"Start of Occupancy : 0"<<start<<"/01/2022"<<endl;
            cout<<"End of Occupancy   : 0"<<end<<"/01/2022"<<endl;
            cout<<"Stay Duration      : "<<days_booked<<" Days"<<endl;
            if (room_type ==1)
            {
                cout<<"Charge per Day     : "<<2000<<endl;
                cout<<"Total Bill         : "<<(2000*days_booked)<<endl;
            }
            else if(room_type == 2)
            {
                
                cout<<"Charge per Day     : "<<1000<<endl;
                cout<<"Total Bill         : "<<(1000*days_booked)<<endl;
            }
            cout<<"Thank you and Welcome to LUMS\n";
            cout<<"////////////////////////////////////////"<<endl;
        }
        void cancel()
        {
            available=1;
            date_of_booking="/01/2022";
            int start =0;
            int end =0;
            int days_booked=0;
            type='m';
            room_type=1;

            name="";
            cnic=0;
            phone=0;
        }
        void test()
        {
            available=0;
            date_of_booking="01/01/2022";
            int start =1;
            int end =8;
            int days_booked=start-end;
            type='m';
            room_type=2;

            name="FayzanCrack";
            cnic=2511;
            phone=111;

        }
    private:
        // booking info
        string date_of_booking;
        int start; // 1st to 8th
        int end; // 1st to 8th
        int days_booked; // always less than 9

        // room info
        char type; // male or female
        // int room_num;
        int room_type; //(1 or 2)
        int available;
        
        // personal info
        //first mate
        string name;
        int cnic;
        int phone;


};

class Accommodation
{
    public:
        Accommodation()
        {
            location = 'm';
            rooms_occupied=0;
            rooms= nullptr;
            reserved_list=nullptr;
            room_rent = 0;
            num_waitlist=0;
        };

        virtual void display_empty_rooms()=0;
        virtual void reserve_room()=0;
        virtual void checkout(string name)=0;
        virtual void cancellation(string name)=0;

    protected:
        char location; //Male or female
        int rooms_occupied; // used as number of students so 80 rooms for Male and 45 rooms for Female

        Booking_info** rooms;
        int* reserved_list;

        queue <Booking_info> waitlist;

        int num_waitlist;

        int room_rent;
};

class Male_hostel : public Accommodation
{
    public:
        Male_hostel()
        {
            rooms_occupied = 0;
            rooms = new Booking_info *[41];

            for (int i = 1; i < 41; i++)
            {
                rooms[i] = new Booking_info[2];
            }

            reserved_list = new int[41];

            for (int i = 1; i < 41; i++)
            {
                reserved_list[i] = 0;
            }

            location = 'm';
            room_rent = 1000;
            num_waitlist = 0;
        }
        // Male_hostel(int); Parameterised Constructor
        //copy constructor
        void display_empty_rooms()
        {
            cout<<"List of rooms available(Double Occupancy):-\n";
            for (int i = 1; i < 41; i++)
            {
                if(reserved_list[i] < 2)
                {
                    cout<<"Room Number: "<<i<<endl;
                }
            }
            
        };
        void reserve_room()
        {
            for (int i = 1; i < 41; i++)
            {
                if(reserved_list[i]<2)
                {
                    reserved_list[i]+=1;

                    if(rooms[i][0].empty_waitlist()==true)
                    {
                        rooms[i][0].reserve('m',i);
                    }
                    else
                    {
                        rooms[i][1].reserve('m',i);
                    }
                    rooms_occupied++;

                    return;

                }
            }


            if (num_waitlist < 6)
            {
                cout<<"You are being Added to Waitlist Queue\n";
                Booking_info delegate;
                delegate.reserve('m',1);

                waitlist.push(delegate);

                num_waitlist++;
                return;
            }

            cout<<"Wait list is full and hostel is not empty. Try again next year\n";
            
            
            
        }
        void checkout(string name)
        {
            for (int i = 1; i < 41; i++)
            {
                if(rooms[i][0].getName()==name)
                {
                    rooms[i][0].checkout('m',i);
                    return;

                }
                else if(rooms[i][1].getName()==name)
                {
                    rooms[i][1].checkout('m',i);
                    return;
                }
            }
            cout<<"\nRoom Not Found. Try Rentering Delegate Name\n";
        }
        void cancellation(string name)
        {
            for (int i = 1; i < 41; i++)
            {
                if (rooms[i][0].getName()==name)
                {
                    rooms[i][0].cancel();
                    cout<<"Reservation for "<<name<<" has been cancelled\n";
                    reserved_list[i]-=1;

                    rooms_occupied--;

                    if (rooms_occupied == 79)
                    {
                        if (num_waitlist != 0)
                        {
                            Booking_info delegate;

                            delegate = waitlist.front();

                            waitlist.pop();

                            rooms[i][0] = delegate;

                            rooms[i][0].setRoomType(2);

                            cout << "Waitlist Delegate has been alloted Room\n";
                            rooms_occupied++;

                            reserved_list[i]+=1;
                        }
                    }

                    return;
                    


                    
                   
                }
                else if(rooms[i][1].getName()==name)
                {
                    rooms[i][1].cancel();
                    cout<<"Reservation for "<<name<<" has been cancelled\n";
                    reserved_list[i]-=1;

                    rooms_occupied--;

                    if (rooms_occupied == 79)
                    {
                        if (num_waitlist != 0)
                        {
                            Booking_info delegate;

                            delegate = waitlist.front();

                            waitlist.pop();

                            rooms[i][1] = delegate;
                            rooms[i][1].setRoomType(2);

                            cout << "Waitlist Delegate has been alloted Room\n";
                            rooms_occupied++;

                            reserved_list[i]+=1;
                        }
                        
                    }

                    return;
                    
                }
                
            }
            
            cout<<"No Reservation Found.\n";
            

        }
        void blah()
        {
            for (int i = 1; i < 41; i++)
            {
                while (reserved_list[i] < 2)
                {
                    if (reserved_list[i] < 2)
                    {
                        reserved_list[i] += 1;

                        if (rooms[i][0].empty_waitlist() == true)
                        {
                            rooms[i][0].test();
                        }
                        else
                        {
                            rooms[i][1].test();
                        }
                        rooms_occupied++;
                    }
                }
            }
            
        }
        ~Male_hostel()
        {
            delete[] reserved_list;

            for (int i = 1; i < 41; i++)
            {
                delete[] rooms[i];
            }
            delete[] rooms;
        };
    private:


        


};

class Female_hostel : public Accommodation
{
public:
    Female_hostel()
    {
        rooms_occupied = 0;
        rooms = new Booking_info *[31];

        for (int i = 1; i < 16; i++)
        {
            rooms[i] = new Booking_info[2];
        }
        for (int i = 16; i < 31; i++)
        {
            rooms[i] = new Booking_info[1];
        }

        reserved_list = new int[31];

        for (int i = 1; i < 31; i++)
        {
            reserved_list[i] = 0;
        }

        location = 'f';
        room_rent = 2000;
        num_waitlist = 0;
    };

    void display_empty_rooms()
    {
        cout << "List of rooms available(Double Occupancy):-\n";
        for (int i = 1; i < 16; i++)
        {
            if (reserved_list[i] < 2)
            {
                cout << "Room Number: " << i << endl;
            }
        }
    };
    void display_single_oc_rooms()
    {
        cout << "List of rooms (Single Occupancy):-\n";
        for (int i = 15; i < 31; i++)
        {
            if (reserved_list[i] == 0)
            {
                cout << "Room Number: " << i << endl;
            }
        }
    };
    void reserve_room()
    {
        for (int i = 1; i < 31; i++)
        {
            if (i < 16) // double oc
            {
                if (reserved_list[i] < 2)
                {
                    reserved_list[i] += 1;

                    if (rooms[i][0].empty_waitlist() == true)
                    {
                        rooms[i][0].reserve('f', i);
                    }
                    else
                    {
                        rooms[i][1].reserve('f', i);
                    }
                    rooms_occupied++;
                    return;
                }
            }
            else // single oc
            {
                if (reserved_list[i] == 0)
                {
                    reserved_list[i] += 1;

                    rooms[i][0].reserve('f', i);
                    rooms_occupied++;

                    return;
                }
            }
        }

        // for (int i = 1; i < 6; i++)
        // {
        //     if(wait_list[i].empty_waitlist()==true)
        //     {
        //         cout<<"You are being Added to Waitlist\n";
        //         wait_list[i].reserve('f',i);
        //         break;
        //     }
        // }

        if (num_waitlist < 6)
        {
            cout << "You are being Added to Waitlist Queue\n";
            Booking_info delegate;
            delegate.reserve('f', 1);

            waitlist.push(delegate);

            num_waitlist++;
            return;
        }

        cout << "Wait list is full and hostel is not empty. Try again next year\n";
    }
    void checkout(string name)
    {
        for (int i = 1; i < 31; i++)
        {
            if (i < 16)
            {
                if (rooms[i][0].getName() == name)
                {
                    rooms[i][0].checkout('f', i);
                    return;
                }
                else if (rooms[i][1].getName() == name)
                {
                    rooms[i][1].checkout('f', i);
                    return;
                }
            }
            else
            {
                if (rooms[i][0].getName() == name)
                {
                    rooms[i][0].checkout('f', i);
                    return;
                }
            }
        }

        cout << "\nRoom Not Found. Try Rentering Delegate Name\n";
    }
    void cancellation(string name)
    {
        for (int i = 1; i < 16; i++)
        {
            if (rooms[i][0].getName() == name)
            {
                rooms[i][0].cancel();
                cout << "Reservation for " << name << " has been cancelled\n";
                reserved_list[i] -= 1;

                rooms_occupied--;

                if (rooms_occupied == 44)
                {
                    Booking_info delegate;

                    delegate = waitlist.front();

                    waitlist.pop();

                    rooms[i][0] = delegate;
                    rooms[i][0].setRoomType(2);

                    cout << "Waitlist Delegate has been alloted Room\n";
                    rooms_occupied++;

                    reserved_list[i] += 1;
                }

                return;
            }
            else if (rooms[i][1].getName() == name)
            {
                rooms[i][1].cancel();
                cout << "Reservation for " << name << " has been cancelled\n";
                reserved_list[i] -= 1;

                rooms_occupied--;

                if (rooms_occupied == 44)
                {
                    Booking_info delegate;

                    delegate = waitlist.front();

                    waitlist.pop();

                    rooms[i][1] = delegate;
                    rooms[i][1].setRoomType(2);

                    cout << "Waitlist Delegate has been alloted Room\n";
                    rooms_occupied++;

                    reserved_list[i] += 1;
                }

                return;
            }
        }

        for (int i = 16; i < 31; i++)
        {
            if (rooms[i][0].getName() == name)
            {
                rooms[i][0].cancel();
                cout << "Reservation for " << name << " has been cancelled\n";
                reserved_list[i] -= 1;

                rooms_occupied--;

                if (rooms_occupied == 44)
                {
                    Booking_info delegate;

                    delegate = waitlist.front();

                    waitlist.pop();

                    rooms[i][0] = delegate;
                    rooms[i][0].setRoomType(1);

                    cout << "Waitlist Delegate has been alloted Room\n";
                    rooms_occupied++;

                    reserved_list[i] += 1;
                }

                return;
            }
        }

        cout << "No Reservation Found.\n";
    };
    void blah()
        {
            for (int i = 1; i < 16; i++)
            {
                while (reserved_list[i] < 2)
                {
                    if (reserved_list[i] < 2)
                    {
                        reserved_list[i] += 1;

                        if (rooms[i][0].empty_waitlist() == true)
                        {
                            rooms[i][0].test();
                        }
                        else
                        {
                            rooms[i][1].test();
                        }
                        rooms_occupied++;
                    }
                }
            }
            
        }
    ~Female_hostel()
    {
        delete[] reserved_list;

        for (int i = 1; i < 31; i++)
        {
            delete[] rooms[i];
        }
        delete[] rooms;
    };

private:
};

void queryMenu(Male_hostel &m1,Female_hostel&f1)
{
    int choice;
    cout<<"Search by:\n";
    cout<<"1. Hostel (male / female)\n";
    cout<<"2. Accomodation type (single / double)\n";
    cin>>choice;

    if(choice == 1)
    {
        cout<<"Enter 1 for Male Hostels\n";
        cout<<"Enter 2 for Female Hostels\n";
        cin>>choice;

        if(choice == 1)
        {
            m1.display_empty_rooms();
        }
        else
        {
           f1.display_empty_rooms();
           f1.display_single_oc_rooms();
        }
    }
    else
    {
        cout<<"Enter 1 for Single Occupancy\n";
        cout<<"Enter 2 for Double Occupancy\n";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Female Hostel:\n";
            f1.display_single_oc_rooms();
        }
        else
        {
            cout<<"Male Hostel:\n";
            m1.display_empty_rooms();

            cout<<"Female Hostel:\n";
            f1.display_empty_rooms();
        }
    }

}
void ReserveMenu(Male_hostel &m1,Female_hostel&f1)
{
    int choice;
    cout<<"Which Hostel do you want to reserve room in ?\n";
    cout<<"Enter 1 for Male Hostel\n";
    cout<<"Enter 2 for Female Hostel\n";
    cin>>choice;

    if (choice == 1)
    {
        m1.reserve_room();   
    }
    else
    {
        f1.reserve_room();
    }
    


}
void CheckoutMenu(Male_hostel &m1,Female_hostel&f1)
{
    string name;
    int choice;

    cout<<"Enter Delegate Name for Checkout:";
    cin>>name;

    cout<<"Enter 1 for Male Hostel\n";
    cout<<"Enter 2 for Female Hostel\n";
    cin>>choice;

    if(choice ==1)
    {
        m1.checkout(name);
    }
    else
    {
        f1.checkout(name);
    }
}
void CancelMenu(Male_hostel &m1,Female_hostel&f1)
{
    string name;
    int hostel;
    cout<<"Please Enter Name of Delegate for Cancellation: ";
    cin>>name;

    cout<<"Enter 1 for Male Hostel\n";
    cout<<"Enter 2 for Female Hostel\n";
    cin>>hostel;

    if (hostel == 1)
    {
        m1.cancellation(name);
        
    }
    else
    {
        f1.cancellation(name);
    }
    
    
    


}
void Level_2(Male_hostel &m1,Female_hostel&f1)
{
    int choice;
    cout<<"1. Query\n";
    cout<<"2. Reserve a room\n";
    cout<<"3. Checkout\n";
    cout<<"4. Cancel reservation\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice==1)
    {
        queryMenu(m1,f1);
    }
    if(choice == 2)
    {
        ReserveMenu(m1,f1);
    }
    if(choice == 3)
    {
        CheckoutMenu(m1,f1);

    }
    if(choice == 4)
    {
        CancelMenu(m1,f1);

    }
}

int main()
{
    Male_hostel m1;
    Female_hostel f1;

    // m1.blah();
    // f1.blah();

    int choice=0;

    while (choice != 3)
    {
        cout<<"1. Room Reservation (Delegates Operations)\n";
        cout<<"2. Administrative Operations\n";
        cout<<"3. Quit\n";
        cin>>choice;

        if(choice == 1)
        {
            Level_2(m1,f1);
        }
    }    

}