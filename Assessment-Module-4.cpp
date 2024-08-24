// Assessment Module-4 : ATM Banking Application

#include <iostream>
#include <ctime>

using namespace std;

class Show_dateAndTime
{
public:
    void Display_Date_Time()
    {
        time_t now = time(0); // get current dat/time with respect to system...

        char *dt = ctime(&now); // convert it into string...

        cout << "================================== Welcome to ATM ===================================" << endl;

        cout << "Current Date : " << dt << endl; // print local date and time...

        cout << "=====================================================================================" << endl;
    }
};

class Initial_Info
{
public:
    string acc_holder_name = "Bhoomi Vadhvana";
    string acc_holder_address = "Gujarat";
    string branch_location = "Surendranagar";
    int initial_balace = 60000;
    int acc_no = 98765;

    // It Define Initial information of Bank Account Holder...
    int Display_Ini_Info()
    {
        cout << "The Name Of The Account Holder : " << acc_holder_name << endl;
        cout << "The Account Holder Address : " << acc_holder_address << endl;
        cout << "The Branch Location : " << branch_location << endl;
        cout << "Account Number :" << acc_no << endl;

        return initial_balace;
    }
};

class select_Menu
{
public:
    int menu_ch;

    // It select Choice Which Operation Perform...
    int choice_Menu()
    {
        cout << " Enter [1] To Deposite Cash " << endl;
        cout << " Enter [2] To Withdraw Cash " << endl;
        cout << " Enter [3] To Balance Inquiry " << endl;
        cout << " Enter [4] To Exit ATM " << endl;

        cout << "PLEASE ENTER A SELECTION : " << endl;
        cin >> menu_ch;

        return menu_ch;
    }
};

class Deposit : public Initial_Info
{
public:
    int deposit_amount;

    // It Increases the amount of entered deposited Balance and Display Updated Balance...
    int Deposit_Process()
    {
        cout << "Enter The Amount To Be Deposited Rs. : ";
        cin >> deposit_amount;
        initial_balace += deposit_amount;
        cout << "Your New Avilable Balance Amount Is Rs. : " << initial_balace << endl;
        cout << "Thank You !" << endl;
        // cout << "Press any key to return main menu " << endl;
    }
};

class Withdrawl : public Initial_Info
{
public:
    int withdrawl_amount;

    // It Decreases the amount of entered Withdraed Balance and Display Updated Balance...

    int Withdrawl_Process()
    {
        cout << "Enter The Amount To Be Withdraw Rs. : ";
        cin >> withdrawl_amount;
        initial_balace -= withdrawl_amount;

        if (withdrawl_amount > initial_balace)
        {
            // It Display sorry message if Enterd withdraw balance is less than initial balance...
            cout << "Insufficient Avilable Balance in Your Account." << endl;
            cout << " Sorry..... " << endl;
            // cout << "Press any key to continue... " << endl;
        }
        else
        {
            cout << "Your New Avilable Balance Amount Is Rs. : " << initial_balace << endl;
            cout << "Thank You !" << endl;
            // cout << "Press any key to continue... " << endl;
        }
    }
};

int main()
{
    Show_dateAndTime dt;
    dt.Display_Date_Time();
    select_Menu sm;
    Initial_Info ii;
    Deposit d;
    Withdrawl w;

    int wlcm_ch;

    // It Get choice, User Get Help Or Enter Pin Number for Process...

    cout << "press 1 And Then Press Enter To Access Your Account Via Pin Number" << endl;
    cout << "Press 0 And Press Enter To Get Help";
    cin >> wlcm_ch;

    int acc_pinNo = 12345;

    switch (wlcm_ch)
    {
    case 1:

        // ATM Access Section for enter ATM pin number...
        cout << "============================= ATM Account Access ====================================" << endl
             << endl;

        cout << "Enter Your Account Pin Access Number ...!! [ Only One Attempt Is Allowed ]" << endl
             << endl;

        cout << "=====================================================================================" << endl;
        cin >> acc_pinNo;

        if (acc_pinNo == 12345)
        {
            sm.choice_Menu();
            switch (sm.menu_ch)
            {
                // case 1 do process regarding deposit balance...
            case 1:
                ii.Display_Ini_Info();
                cout << " Present Avilable Balance : " << ii.initial_balace << endl;
                d.Deposit_Process();
                break;

                // case 2 do process regarding withdraw balance...
            case 2:
                ii.Display_Ini_Info();
                w.Withdrawl_Process();
                break;

                // case 3 display avilable balance...
            case 3:
                cout << "Your Available Balance : " << ii.initial_balace;
                break;

                // case 4 exit ATM...
            case 4:
                cout << "Thanks For Visit ATM!" << endl;
                break;

            default:
                cout << "Please Enter Number Between 1 To 4 : ";
                break;
            }
        }
        else
        {
            // Display message if atm attempt is failed...
            cout << "============================= Thank You ====================================" << endl;
            cout << "You Had Made YOut attempt Which Failed !! No More Attempts Allowed !! Sorry !! " << endl;
            cout << "============================= ATM Account Access ====================================" << endl;
            // cout << "Press Any Key to continue" << endl;
        }
        break;

    case 0:
        // It is help part -- in which use can saw how perform operations...
        cout << "============================= ATM Account Status ====================================" << endl;
        cout << "You Must Have Correct Pin Number To Access This Account." << endl;
        cout << "See Your Bank Representative For Assistance During Bank Operating Hours. " << endl;
        cout << "Thanks For, Your Choice Today...!!" << endl;
        cout << "=====================================================================================" << endl;
        // cout<<" press any key to continue"<<endl;
        break;

    default:
        cout << "Please Enter Number 1 Or 0 ";
        break;
    }

    return 0;
}
