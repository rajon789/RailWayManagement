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
    ofstream user_data;
    user_data.open("signUpInfo.txt",ios_base :: app);
    string name,email,check_match_pass;

    getchar();
    while(user_data)
    {
        printf("Name: ");
        getline(cin,name);

        printf("Email: ");
        getline(cin,email);

        printf("User name: ");
        getline(cin,user_name);

        printf("Password: ");
        getline(cin,user_pass);
        printf("Re enter password: ");
        getline(cin,check_match_pass);
        if(user_pass.compare(check_match_pass) == 0)
        {
            cout << "Congratulation! Mr." << name << " your account is created";
            printf("\nNow you can login to researve seat\n");
            user_data << name << endl;
            user_data << email << endl;
            user_data << user_name << endl;
            user_data << user_pass << endl;
            cin.ignore();
            main();
        }
        else
        {
            printf("Password did not match\n");
            RailWayManagement obj;
            obj.signUp();
        }

        if(cin)
            exit(1);
    }
    user_data.close();
}

void RailWayManagement::userLogin()
{
    ifstream user_data("signUpInfo.txt");
    //string *login_user_name = new string;
    //string *login_user_pass = new string;
    string login_user_id, login_user_pass,valid_user_info;
    //bool check_id = false;
    //bool check_pass = false;
    bool check_creddentials = false;

    printf("User ID: ");  cin >> login_user_id;
    printf("Password: "); cin >> login_user_pass;

    
    while(getline(user_data, valid_user_info))
    {
        if(login_user_id.compare(valid_user_info) == 0)
            if(login_user_pass.compare(valid_user_info) == 0)
            {
                check_creddentials = true;
            }
    }

    user_data.close();
    if(check_creddentials == true)
        cout << "Login successful\n";
    
    
    /*while(getline(user_data, valid_user_id))
    {
        if(valid_user_id.compare(login_user_id) == 0)
            {
                cout << valid_user_id;
                check_id = true;
                //return;
            }
    }
    while (getline(user_data,valid_user_pass))
    {
        if(valid_user_pass.compare(login_user_pass) == 0)
        {
            cout << valid_user_pass;
            check_pass = true;
        }
    }*/
    user_data.close();

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
