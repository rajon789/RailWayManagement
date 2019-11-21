#include<bits/stdc++.h>
using namespace std;
int main();
class RailWayManagement{
    private:
    string user_pass;
    string user_name;

    public:
    RailWayManagement();
    void signUp();
    void showUserInfo();
    void userLogin();
};

RailWayManagement::RailWayManagement()
{
    //ifstream user_data("signUpInfo.txt");

}

void RailWayManagement::signUp()
{
    ofstream user_data,login_info;
    user_data.open("signUpInfo.txt",ios_base :: app);
    login_info.open("loginInfo.txt",ios_base::app);
    string name,email,check_match_pass;

    getchar();
    if(user_data.is_open() and login_info.is_open())
    {
        printf("Name: ");
        getline(cin,name);

        printf("Email: ");
        getline(cin,email);

        printf("User name: ");
        cin >> user_name;

        printf("Password: ");
        cin >> user_pass;
        printf("Re enter password: ");
        cin >> check_match_pass;
        if(user_pass == check_match_pass)
        {
            cout << "Congratulation! Mr." << name << " your account is created";
            printf("\nNow you can login to researve seat\n");

            user_data <<"User Name: " << name << endl;
            user_data << "Email: "    << email << endl;
            user_data << "User ID: "  << user_name << endl;
            user_data << "Password: " << user_pass << endl;
            user_data << endl;
            login_info << user_name << " " << user_pass << endl;
            user_data.close();
            login_info.close();
            cin.ignore();
            main();
        }
        else
        {
            int check_pass_correct_frequency = 0;
            printf("Password did not match\n");
            RailWayManagement obj;
            check_pass_correct_frequency = check_pass_correct_frequency + 1;
            if(check_pass_correct_frequency == 3)
            {
                check_pass_correct_frequency = 0;
                main();
            }
            obj.signUp();
        }

        if(cin)
            exit(1);
    }
    user_data.close();
    login_info.close();
}

void RailWayManagement::userLogin()
{
    ifstream login_info("loginInfo.txt");
    //string *login_user_name = new string;
    //string *login_user_pass = new string;
    string login_user_id, login_user_pass;
    string valid_user_id, valid_user_pass;
    //bool check_id = false;
    //bool check_pass = false;
    bool check_credentials = false;
    string str;

    printf("User ID: ");  cin >> login_user_id;
    printf("Password: "); cin >> login_user_pass;


    for(int i = login_info.beg; i <= login_info.tellg(); i++)
    {
        login_info >> valid_user_id >> valid_user_pass;
        if(login_user_id == valid_user_id and login_user_pass == valid_user_pass)
        {
            //cout << "User ID: " << valid_user_id << "     Pass: " << valid_user_pass;
            check_credentials = true;
        }
    }


    login_info.close();

    if(check_credentials == true)
        cout << "Login successful\n";
    else
    {
        cout << "Credentials not matched" << endl;
        main();
    }

}

void RailWayManagement::showUserInfo()
{
    ifstream user_data("signUpInfo.txt");
    if(user_data.is_open())
        cout << user_data.rdbuf();

    user_data.close();
}

int main()
{
    RailWayManagement obj;
    int option;
    printf("1.Login\n");
    printf("2.Sign up\n");
    printf("3.Exit\n");
    cin >> option;

    switch (option)
    {
    case 1:
         obj.userLogin();
        break;
    case 2:
        obj.signUp();
        break;
    case 3:
        exit(1);

    default:
        printf("Unknown response\n");
        main();
        break;
    }
    //obj.signUp();
    //obj.showUserInfo();

}
