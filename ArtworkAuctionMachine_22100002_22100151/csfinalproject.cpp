#include<iostream>
#include<iomanip>      //For text layout
#include<stdlib.h>
#include<fstream>    //For file handline
#include <cstdlib>  //library for random
#include <windows.h> //Library for sleep and color
#include <ctime>    //library for random
#include<limits> // for catching error(cin.ignore)

using namespace std;

void signup(void);
int randomfunction1(void);
void timer(void);
int randomfunction2(void);
string lineseparator(ifstream &receive)  //used to separate each line taken from the text file (if we don't use this, everything in one line)
{
    string lines="";                    //lines stores the whole content AFTER separating each line
    while (!receive.eof())
    {
        string temp;                   //Each individual line goes in temp using get line
        getline(receive,temp);
        temp+="\n";                    //character for line separation added
        lines+=temp;
    }
    return lines;
}
//name of structure skeleton is user
//name of the one and only structure is cust
//name of the created txt file is custinfo.txt
//pseudo name is also custinfo
struct user
{
    string usern;
    string pass;
    string fname;
    string lname;
    string phone;
    int bal;
    string add;


} cust;
int main()
{
    string check1="null";//
    string check2="null";//  all three to store availability of 3 paintings
    string check3="null";//
    int bid1;//
    int bid2;//  all three to store the bid you made for either of 3 paintings
    int bid3;//
    string temp;
    string log;// to store login option
    system("Color 0E");// yellow color of text
top:// setting level
    do // to control whole of first page
    {
        system("cls");//clear screen
/////// PRINTING THE FIRST LOGIN PAGE///////
        {
            for (int i = 0; i < 80; i++)
            {
                cout << "_";
            }
            cout<<endl;
            cout << "" << setw(55) << "Welcome to the Sotheby's Art Auction "  << setw(25) <<""<<endl;
            for (int i = 0; i < 80; i++)
            {
                cout << "_";
            }
            cout << endl;
            cout << endl;
            cout << "Do you already have an account or would you like to sign up first?\n"<<endl;
            cout << "[1] Sign in\n"<<endl;
            cout << "[2] Sign up\n"<<endl;
        }
//////////////////////////////////////////////
        cin >> log;
        cin.ignore();
///////////////////////SIGN IN//////////////////////
        if (log == "1")
        {
            string password;
            string username;
            bool found = false;//to control outer do loop
            do
            {
                ifstream custinfo;
                custinfo.open("custinfo.txt");// opening file
                system("cls");
                cout<<"Please enter username\t";
                cin>> username;
                cout<<"Please enter password\t";
                cin>> password;
                while(custinfo.good())//controls the reading and matching of entered username and password with
                {
                    getline(custinfo,cust.usern);
                    getline(custinfo,cust.pass);
                    if (username == cust.usern && password == cust.pass)
                    {
                        found=true;// change bool to true to break outer loop
                        system("cls");
                        cout<<"    *You have successfully logged in*"<<endl;
                        cout<<endl;
                        cout<<endl;

                        cout<<"How much money would you like to reserve for the event (in USD)?"<<endl;
                        cin>>cust.bal;

                        while(1)// to catch any non integer entered
                        {
                            if(cin.fail())
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                cout<<"Please enter a valid amount"<<endl;
                                cin>>cust.bal;
                            }
                            if(!cin.fail())
                                break;
                        }
                        break;
                    }
                }
                custinfo.close();
                if(found==false)
                {
                    cout<<"Username or Password you entered is not correct\nenter z to go back or enter any other key to try again";
                    string a;
                    cin>> a;
                    if(a=="z")
                    {
                        goto top;
                    }
                }
            }
            while(found==false);//outer do loop
        }
///////////////////////SIGN UP//////////////////////
        else if(log == "2")
        {
            signup();
        }
///////////////for entry of improper data/////////////////
        else
        {
            system("cls");
            cout<<"please enter a valid option(enter any key to go back)";
            cin;
            cin.ignore();
        }
        //////////////////////////////////
    }
    while(log!="1"&&log!="2");// condition for the loop that controls whole of the login screen
    system("cls");
    cout<<"       Welcome to the auction! press any key to continue to the main menu";// prompt for a successful login
    cout<<endl;
    string a;
    cin>>a;
    cin.ignore();

///////////MAIN MENU FOR AUCTION////////////////
top2:
    system("cls");
    for (int i = 0; i < 80; i++)
        cout << "_";
    cout<<endl;
    cout << "" << setw(55) << "The Sotheby's Art Auction Main Menu"  << setw(24) <<""<<endl;
    for (int i = 0; i < 80; i++)
        cout << "_";
    cout << endl;
    cout << endl;
    cout << "Please enter the number of your selected option to continue.\n"<<endl;
    cout << "[1] Enter auction room"<<endl;
    cout << "[2] Checkout"<<endl;
    cout << "[3] Check balance"<<endl;
    cout << "[4] Play the slot machine"<<endl;
    int b;
    cin>>b;
////////////////////CHECKOUT////////////////////
    if(b==2)
    {
        system("cls");
        for (int i = 0; i < 80; i++)
            cout << "_";
        cout<<endl;
        cout << "" << setw(55) << "Auction Checkout"  << setw(25) <<""<<endl;
        for (int i = 0; i < 80; i++)
            cout << "_";
        cout<<endl;
        cout<<endl;
        if(check1!="win"&&check2!="win"&&check3!="win")// in case person did not bid or did not win anything
        {
            cout<<"You have no winning auction to display."<<endl;
            cout<<endl;
            cout<<"Enter z to exit the auction or enter any other key to go back ";
            string a;
            cin>> a;
            if(a=="z")
            {
                exit(0) ;
            }
            goto top2;
        }
        cout<<"The following are your winning bids of the day: "<<endl;
        cout<<endl;
        if(check1 == "win")
        {
            cout<<"Monalisa " <<"bought for $"<<bid1<<endl;
        }
        if(check2 == "win")
        {
            cout<<"The Scream " <<"bought for $"<<bid2<<endl;
        }

        if(check3 == "win")
        {
            cout<<"Girl with pearl earrings " <<"bought for $"<<bid3<<endl;
        }
        cout<<endl;
        cout<<"Enter z to exit the auction or enter any other key to go back ";
        string a;
        cin>> a;
        if(a=="z")
        {
            exit(0) ;
        }
        goto top2;
    }
//////////BALANCE CHECK/////////
    else if(b==3)
    {
        system("cls");
        cout<<"Your current balance is:  $"<<cust.bal<<endl;
        string d;
        cout<<"Please enter any key to go back to auction main menu"<<endl;
        cin>>d;
        goto top2;
    }
//////////////SLOT MACHINE///////////////
    else if(b==4)
    {
        system("cls");
        int bid;
        bool check=true;
        int in;
        string won="YOU WON";
        string lost="YOU LOST";
        for (int i = 0; i < 80; i++)
        {
            cout << "_";
        }
        cout<<endl;
        cout << "" << setw(55) << "Welcome to the Sothebys Casino room "  << setw(25) <<""<<endl;
        for (int i = 0; i < 80; i++)
        {
            cout << "_";
        }
        cout << endl;
        cout << endl; //Slot machine title
        cout<< "Your initial balance $"<<cust.bal<<endl;
        while(check)
        {
            cout<<"1) Spin it"<<endl;
            cout<<"2) Exit room"<<endl;
            cin>>in;
            if (cin.fail()) //cin fail
            {
                cout<<"Invalid input"<<endl;
                cin.clear();
                getline(cin,temp);
            }
            if (in==2)
            {
                cout<<"See you soon"<<endl;
                goto top2; //FARAZ: Refer back to main menu here
            }
            else if (in==1)
            {
                cout<<"Enter your bet $ ";
                cin>>bid;
                if (cin.fail()) //cin fail
                {
                    cout<<"Invalid input"<<endl;
                    cin.clear();
                    getline(cin,temp);
                }
                if(bid<=0 || bid>=cust.bal  )
                {
                    cout<<"You did not enter a valid bet"<<endl;
                }
                else
                {
                    srand(time(0));
                    int s1=randomfunction1();
                    int s2=randomfunction1();
                    int s3=randomfunction1();
                    Sleep(1000);   //To display each digit one by one
                    cout<<s1<<" ";
                    Sleep(1000);
                    cout<<s2<<" ";
                    Sleep(1000);
                    cout<<s3<<endl;
                    Sleep(500);
                    if (s1==s2 && s2==s3) // condition to win
                    {
                        system("color 2"); //color changing
                        cout<<won<<endl;
                        Sleep(1000);
                        system("color 0E");
                        cust.bal=cust.bal + bid;
                    }
                    else //lose condition(default)
                    {
                        system("color 4");
                        cout<<lost<<endl;
                        Sleep(1000);
                        system("color 0E");
                        cust.bal=cust.bal-bid;

                    }
                    cout<<"Your balance $"<<cust.bal<<endl;
                }
            }
            else
            {
                cout<<"You did not enter a valid number"<<endl;
            }
        }
    }
/////////AUCTION ROOM/////////

    else if(b==1)
    {
top5:
        system("cls");
        for (int i = 0; i < 80; i++)
            cout << "_";
        cout<<endl;
        cout << "" << setw(55) << "The Sothebys art auction"  << setw(25) <<""<<endl;
        for (int i = 0; i < 80; i++)
            cout << "_";
        cout << endl;
        cout << endl;
        cout << "Please enter the number for the painting you want to bid on.\n"<<endl;
        cout << "[1] The Monalisa"<<endl;
        cout << "[2] The Scream"<<endl;
        cout << "[3] The girl with pearl earrings"<<endl;
        cout << "[4] Return to main menu"<<endl;
        int paint;
        cin>>paint;
        if(paint==4)//Return to Main Menu
        {
            goto top2;
        }
        else if(paint==1)// Monalisa
        {
            if(check1!="null")
            {
                system("cls");
                cout<<"Sorry but this painting has already been auctioned off\nPlease choose another option(enter any key to go back)";
                string a;
                cin>>a;
                goto top5;
            }
            system("cls");
            string content;
            ifstream receive;  //assigning object to class
            srand(time(0));
            int m1=randomfunction2();
            int m2=randomfunction2();
            int m3=randomfunction2();
            cout<<setw(19)<<"THE MONA LISA"<<endl;
            receive.open("monalisa.txt"); //opening file
            if(receive.fail())    //Error handling
            {
                cerr<<"Error in loading file"<<endl;
            }
            content=lineseparator(receive); //content stored after separation
            cout<<content;
            cout<<"Mona Lisa by Leonardo da Vinci (1503) "<<setw(10)<<"77cm x 53cm"<<endl;
            while(1)
            {
                cout<<"Enter your bid $";
                cin>>bid1;
                if(cin.fail() || bid1==0|| bid1>cust.bal)
                {
                    cout<<"You did not enter a Valid bid"<<endl;
                    cin.clear();
                    getline(cin,temp);
                }
                else
                {
                    break;
                }
            }
            cout<<"Timer: "<<endl;
            timer();
            cout<<"Bid by Customer 1 $"<<m1<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 2 $"<<m2<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 3 $"<<m3<<endl;
            Sleep(1000);
            if (bid1>m1 && bid1>m2 && bid1>m3)
            {
                system("color 2");
                cout<<"| You WON the bidding |"<<endl;
                Sleep(1000);
                system("color 0E");
                cust.bal=cust.bal -bid1;
                check1 ="win";
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;                   //FARAZ: add MONA LISA TO CHECK OUT
            }
            else if (bid1==m1 || bid1==m2 || bid1==m3)
            {
                cout<<"Its a draw: Join us next time to bid again(enter any key to go back)"<<endl;
                string f;
                cin>>f;
                goto top2;
            }
            else
            {
                system("color 4");
                cout<<"| You lost the bid |\nenter any key to proceed to main menu"<<endl;
                Sleep(1000);
                system("color 0E");
                check1 ="lose";
                string f;
                cin>>f;
                goto top2;
            }
        }
        else if (paint == 2)//The Scream
        {
            if(check2!="null")
            {
                system("cls");
                cout<<"Sorry but this painting has already been auctioned off\nPlease choose another option(enter any key to go back)";
                string a;
                cin>>a;
                goto top5;
            }
            system("cls");
            string content1;
            ifstream receive1;  //assigning object to class
            srand(time(0));
            int sc1=randomfunction2();
            int sc2=randomfunction2();
            int sc3=randomfunction2();
            cout<<setw(19)<<"THE SCREAM"<<endl;
            receive1.open("scream.txt"); //opening file
            if(receive1.fail())    //Error handling
            {
                cerr<<"Error in loading file"<<endl;
            }
            content1=lineseparator(receive1); //content stored after separation
            cout<<content1;
            cout<<"The Scream by Norwegian Expressionist artist Edvard Munch (1893)"<<setw(10)<<"91cm x 73.5cm"<<endl;
            while(1)
            {
                cout<<"Enter your bid $";
                cin>>bid2;
                if(cin.fail() || bid2==0||bid2>cust.bal )
                {
                    cout<<"You did not enter a Valid bid"<<endl;
                    cin.clear();
                    getline(cin,temp);
                }
                else
                {
                    break;
                }
            }
            cout<<"Timer: "<<endl;
            timer();
            cout<<"Bid by Customer 1 $"<<sc1<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 2 $"<<sc2<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 3 $"<<sc3<<endl;
            Sleep(1000);
            if (bid2>sc1 && bid2>sc2 && bid2>sc3)
            {
                system("color 2");
                cout<<"| You WON the bidding |"<<endl;
                Sleep(1000);
                system("color 0E");
                cust.bal=cust.bal -bid2; //FARAZ: connect this to balance
                check2 ="win";
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;                    //FARAZ: add MONA LISA TO CHECK OUT
            }
            else if ((bid2==sc1 && sc1>sc2 && sc1>sc3)|| (bid2==sc2 && sc2>sc1 && sc2>sc3) || (bid2==sc3 && sc3>sc2 && sc3>sc1))
            {
                cout<<"Its a draw: Join us next time to bid again"<<endl;
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;     //FARAZ: return to main menu here
            }
            else
            {
                system("color 4");
                cout<<"| You lost the bid |"<<endl;
                Sleep(1000);
                system("color 0E");
                check2 ="lose";
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2; //FARAZ: return to main menu here
            }
        }
        else if (paint == 3)//Girl with pearl earrings
        {
            if(check3!="null")
            {
                system("cls");
                cout<<"Sorry but this painting has already been auctioned off\nPlease choose another option(enter any key to go back)";
                string a;
                cin>>a;
                goto top5;
            }
            system("cls");
            string content2;
            ifstream receive2;  //assigning object to class
            srand(time(0));
            int tg1=randomfunction2();
            int tg2=randomfunction2();
            int tg3=randomfunction2();
            cout<<setw(19)<<"THE GIRL WITH PEARL EARINGS"<<endl;
            receive2.open("thegirl.txt"); //opening file
            if(receive2.fail())    //Error handling
            {
                cerr<<"Error in loading file"<<endl;
            }
            content2=lineseparator(receive2); //content stored after separation
            cout<<content2;
            cout<<"The Girl With Pearl Earings Johannes Vermeer (1665)"<<setw(10)<<"44cm x 39cm"<<endl;
            while(1)
            {
                cout<<"Enter your bid $";
                cin>>bid3;
                if(cin.fail() || bid3==0||bid3>cust.bal )
                {
                    cout<<"You did not enter a Valid bid"<<endl;
                    cin.clear();
                    getline(cin,temp);
                }
                else
                {
                    break;
                }
            }
            cout<<"Timer: "<<endl;
            timer();
            cout<<"Bid by Customer 1 $"<<tg1<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 2 $"<<tg2<<endl;
            Sleep(1000);
            cout<<"Bid by Customer 3 $"<<tg3<<endl;
            Sleep(1000);
            if (bid3>tg1 && bid3>tg2 && bid3>tg3)
            {
                system("color 2");
                cout<<"| You WON the bidding |"<<endl;
                Sleep(1000);
                system("color 0E");
                cust.bal=cust.bal -bid3;
                check3 ="win";
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;
            }
            else if ((bid3==tg1 && tg1>tg2 && tg1>tg3)|| (bid3==tg2 && tg2>tg1 && tg2>tg3) || (bid3==tg3 && tg3>tg2 && tg3>tg1))
            {
                cout<<"Its a draw: Join us next time to bid again"<<endl;
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;             //FARAZ: return to main menu here
            }
            else
            {
                system("color 4");
                cout<<"| You lost the bid |"<<endl;
                Sleep(1000);
                system("color 0E");
                check3 ="lose";
                cout<<"enter any key to return to main menu";
                string f;
                cin>>f;
                goto top2;
            }
        }
        else //Error Handling in Auction
        {
            system("cls");
            cout<<"please enter a valid option(enter any key to go back)";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //To ignore all characters in stream after error
            string a;
            cin>>a;
            goto top5;
        }
    }
    else //Error Handling in Main Menu
    {
        system("cls");
        cout<<"please enter a valid option(enter any key to go back)";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        string a;
        cin>>a;
        goto top2;
    }

    return 0;
}
void signup(void)
{
    cout<< " please enter your first name"<<endl;
    getline(cin,cust.fname );

    cout<< " please enter your last name"<<endl;
    getline(cin,cust.lname );

top6:
    cin.clear();
    cin.ignore();

    cout<< " please enter a username"<<endl;
    getline(cin,cust.usern );

    ifstream custinfo;
    custinfo.open("custinfo.txt");// opening file

    while(custinfo.good())// to check if entered username is alreadycstored
    {
        string storuser;
        getline(custinfo,storuser);
        if (cust.usern == storuser)
        {
            cout<<"This username already exists, Please select a different username\n    enter any key to try again.  "<<endl;
            string a;
            cin>>a;
            goto top6;
        }
    }
    custinfo.close();
    cout<< " please enter a password"<<endl;
    getline(cin,cust.pass );

    cout<< " please enter your phone number"<<endl;
    getline(cin,cust.phone );

    cout<< " please enter your your home address"<<endl;
    getline(cin,cust.add );

    cout<< " please enter the amount of money you want to reserve for the event (in USD)"<<endl;
    cin>>cust.bal;
    while(1)
    {
        if(cin.fail())// to catch any entry of non integers
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter a valid amount"<<endl;
            cin>>cust.bal;
        }
        if(!cin.fail())
            break;
    }
    {
        ofstream custinfo;
        custinfo.open("custinfo.txt",ios::out|ios::app);

        custinfo<<cust.usern<<endl<<cust.pass<<endl<<cust.add<<endl<<cust.fname<<endl<<cust.lname<<endl<<cust.phone<<endl;

        custinfo.close();
    }
}

int randomfunction1()
{
    int s1=rand()%3+1;
}
//Random function created for generating values 1,2,3 randomly
int randomfunction2()    //Random function with max limit $1000
{
    int s1=rand()%1000+1;
}
void timer()            //Timer for 5secs count down
{
    for(int i=5; i>=0; i--)
    {
        cout<<"\r"<<i;   //"\r" carriage return, an escape sequence to return to start of line
        Sleep(1000);
    }
    cout<<"\n | Bidding Closed |"<<endl;
}
