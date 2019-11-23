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
    void showReadyTrain();
    void userLogin();
    void userMenu();
    void buyTicket();
};

RailWayManagement::RailWayManagement()
{
    //ifstream user_data("signUpInfo.txt");
    //login_user_id_ptr = nullptr;

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

    bool check_credentials = false;

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
        {
            ofstream store_user_id_temply("tempUser.txt");
            store_user_id_temply << login_user_id;
            store_user_id_temply.close();
            cout << "Login successful\n";
            RailWayManagement obj;
            obj.userMenu();
        }
    else
    {
        cout << "Credentials not matched" << endl;
        main();
    }

}

void RailWayManagement::showReadyTrain()
{
    //ifstream ready_train("schedualTraininfo.txt");
    //cout << "Yet to Implement" << endl;
    ifstream read_ready_schedule("schedulaTraininfo.txt");
    string train_name, from, to, arrival_time, depature_time, off_day;

    if(read_ready_schedule.is_open())
    {
        int train_index = 0;
        cout << "                          Schedule List\t" << endl;
        cout << "Train No" << "  Train Name\t\t" << "From\t" << "To\t" << "Arrival Time\t" << "Departure Time\t" << "Off Day" << endl;
        cout << endl;
        while(read_ready_schedule >> train_name >> from >> to >> arrival_time >> depature_time >> off_day)
        {
            cout << train_index << "  "<< train_name << "\t\t" << from << "\t" << to << "\t" << arrival_time << "\t" << depature_time << "\t" << off_day << endl;
            cout << endl;
            train_index++;
        }
    }
    read_ready_schedule.close();
}

void seat_formation(int total_seat_in_a_compartment)
{
    int print_seat = 1;
    for(int i = 1;i<=total_seat_in_a_compartment/4;i++)
    {
        for(int j=1;j<=2;j++)
        {
            for(int k=1;k<=2;k++)
            {
                cout << print_seat <<"  ";
                print_seat++;
            }
            cout <<"        ";

        }

        cout << endl;
    }
    cout << endl;
}
bool checkDateFormat(string date)
{
    char ch = '/';
    bool check_format = false;

    if(date.size()!=10)
        return check_format;

    for(int i=0;i<date.size();i++)
    {
        if(date[2]==ch)
            if(date[5]==ch)
                if(date[(date.size())]=='\0')
                    check_format = true;


    }
    if(check_format==false)
        return false;
    else
        return true;

}

int checkDateCorrectness(char ch, string date)
{
    int ch0,ch1,ch2,ch3,day,month,year;
    if(ch =='d')
    {
        ch1 = date[0]-48;
        ch2 = date[1]-48;
        day = (ch1*10)+ch2;
        return day;
    }
    if(ch == 'm')
    {
        ch1 = date[3]-48;
        ch2 = date[4]-48;
        month = (ch1*10)+ch2;;
        return month;
    }
    if(ch == 'y')
    {
        ch0 = date[6]-48;
        ch1 = date[7]-48;
        ch2 = date[8]-48;
        ch3 = date[9]-48;
        year = (ch0*1000)+(ch1*100)+(ch2*10)+ch3;
        return year;
    }
    return 0;
}
void showUpcomingDate()
{
    ofstream write_upcoming_date("upcomingDateInfo.txt");
	time_t t = time(NULL);
	tm* now = localtime(&t);

    int day = now->tm_mday;
    int temp_month = now->tm_mon;
    int month = temp_month + 1;
    int year =  now->tm_year+1900;
    bool change_Month = true;

    int i = day + 1;
    for(int j = 1;j <= 7;j++)
    {
        if(month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12)
        {
            if(change_Month == true and i == 32)
                {
                    if(month == 12)
                    {
                        month = 1;
                        i = 1;
                        year = year + 1;
                    }
                    else
                    {
                        month = month + 1;
                        change_Month = false;
                        i = 1;
                    }
                }

        }
        else if(month == 2)
        {
            if((year % 4) == 0 or (year % 100) == 0 or (year % 400) == 0)
                {
                    if(change_Month == true and i == 30)
                    {
                        month = month + 1;
                        change_Month = false;
                        i = 1;
                    }
                }
                else
                {
                    if(change_Month == true and i == 29)
                    {
                        month = month + 1;
                        change_Month = false;
                        i = 1;
                    }
                }
        }
        else
        {
            if(change_Month == true and i == 31)
                    {
                        month = month + 1;
                        change_Month = false;
                        i = 1;
                    }
        }

        cout << i <<'/' << month <<'/' << year;
        cout << endl;
        write_upcoming_date << i << "  " << month << "  " << year;
        write_upcoming_date << "\n";
        i++;
  }
  write_upcoming_date.close();

}

void RailWayManagement::buyTicket()
{
    ifstream fetch_train_data("trainInfo.txt");
    ifstream fetch_train_schedule("schedulaTraininfo.txt");
    ifstream temp_user_file("tempUser.txt");
    ofstream reserved_ticket_info("reservedTicket",ios_base::app);
    RailWayManagement obj;
    obj.showReadyTrain();
    string train_name, from, to, arrival_time, depature_time, off_day;
    string fetch_train_name; int fetch_compartment_number, fetch_seat_number;
    string selected_train_name, selected_from, selected_to, selected_depature_time, selected_arrival_time;

    int select_train;
    printf("Select Train: "); cin >> select_train;

    if(fetch_train_schedule.is_open())
    {
        int train_index = 0;
        while(fetch_train_schedule >> train_name >> from >> to >> arrival_time >> depature_time >> off_day)
        {
            if(train_index == select_train)
            {
                //cout << train_name << endl;
                selected_train_name = train_name;
                selected_from = from;
                selected_to = to;
                selected_depature_time = depature_time;
                selected_arrival_time = arrival_time;
                //cout << selected_train_name << endl;
                break;
            }
            train_index++;
        }
    }

    int number_of_compartments,number_of_seats;

    if(fetch_train_data.is_open())
    {
        while(fetch_train_data >> fetch_train_name >> fetch_compartment_number >> fetch_seat_number)
        {
            //cout << fetch_train_name << compartment_number << fetch_seat_number << endl;
            if(selected_train_name == fetch_train_name)
            {
                //cout << fetch_compartment_number << endl << fetch_seat_number << endl;
                cout << "Your train is: " << fetch_train_name << endl << endl;
                number_of_compartments = fetch_compartment_number;
                number_of_seats = fetch_seat_number;
                break;
            }

        }
    }

    cout << "Select compartment no(" << 1 << "-" << number_of_compartments << "): ";
    int select_compartment_no; cin >> select_compartment_no;
    cout << endl;

    seat_formation(number_of_seats);
    string travel_date;

    cout << "Pick Date From Bellow"<<endl<<endl;;
    showUpcomingDate();
    cout<<"(example: --/--/----): ";
    ifstream read_upcoming_dates("upcomingDateInfo.txt");
        int read_day, read_month,read_year;

    while (1)
    {
        cin >> travel_date;
        if(checkDateFormat(travel_date)== true)
        {
            break;
        }
        else
        {
            cout << endl;
            cout << "Date format does not match" << endl;
            cout << "Pick Date From Bellow"<<endl<<endl;
            showUpcomingDate();
            cout<<"(example: --/--/----): ";
        }


    }
    bool terminate_loop = true;
    if(read_upcoming_dates.is_open());
        {
            while (read_upcoming_dates >> read_day >> read_month >> read_year)
            {
                if(read_day == checkDateCorrectness('d',travel_date) and read_month == checkDateCorrectness('m',travel_date) and read_year == checkDateCorrectness('y',travel_date))
                {
                    terminate_loop = false;
                    break;
                }
            }
            if(terminate_loop == true)
                {
                    cout << endl << "Ticket is not available" << endl;
                    obj.buyTicket();
                }
        }


    cout << "How many seat/seats (Maximun 4 seats)" << endl;
    int seat[4], how_many_seats,taken_seat = 1;

    string temp_user_id;

    while(1)
    {
        cin >> how_many_seats;
        if(how_many_seats <= 4 and how_many_seats > 0)
        {
            for(int i = 0; i < how_many_seats; i++)
            {
                cout << "Select seat no: "; cin >> seat[i];
                taken_seat ++;
            }
            break;
        }
        else
        {
            cout << "You can not take more than 4 seats" << endl;
        }
    }
    string pass_user_id;
    while (temp_user_file >> temp_user_id)
    {
        pass_user_id = temp_user_id;
    }

    reserved_ticket_info << pass_user_id << "  " << selected_train_name << "  " << select_compartment_no << "  " << travel_date
    << "  " << selected_from << " " << selected_to << " " << " " << selected_depature_time << "  " << selected_arrival_time << "  ";

    for(int i = 0; i < how_many_seats; i++)
    {
        reserved_ticket_info << seat[i] << "  ";
    }
    reserved_ticket_info << "\n";


    reserved_ticket_info.close();
    temp_user_file.close();
    fetch_train_data.close();
    fetch_train_schedule.close();

}

void RailWayManagement::userMenu()
{
    RailWayManagement obj;
    cout << "1.Train List" << endl;
    cout << "2.Buy Ticket" << endl;
    cout << "3.Cancel Ticket" << endl;
    cout << "4.Show Ticket" << endl;
    cout << "5.Main Menu" << endl;
    int option; cin >> option;
    if(option==1)
    {
        obj.showReadyTrain();
        cin.ignore();
        obj.userMenu();
    }
    else if(option == 2)
    {
        obj.buyTicket();
        cin.ignore();
        obj.userMenu();
    }
    else if(option == 5)
    {
        main();
    }
}

class RailwayManagementAdmin:public RailWayManagement{
    private:
        string train_name, from, to, arrival_time, depature_time, off_day;

    public:
        void showUserInfo();
        void adminMenu();
        void addTrain();
        void scheduleTrain();
        void showReadyTrain();
};

void RailwayManagementAdmin::showUserInfo()
{
    ifstream user_data("signUpInfo.txt");
    if(user_data.is_open())
        cout << user_data.rdbuf();

    user_data.close();
}

void RailwayManagementAdmin::adminMenu()
{
    RailwayManagementAdmin obj;

    int option;
    printf("1.Show User Information\n");
    printf("2.Add Train\n");
    printf("3.Schedule Train\n");
    printf("4.Show Train Information\n");
    printf("5.Main Menu\n");
    cin >> option;

    if(option == 1)
    {
        obj.showUserInfo();
        cin.ignore();
        obj.adminMenu();
    }
    else if(option == 2)
    {
        obj.addTrain();
    }
    else if(option == 3)
    {
        obj.scheduleTrain();
    }
    else if(option == 4)
    {
        obj.showReadyTrain();
    }
    else if(option == 5)
    {
        main();
    }
    else
    {
        main();
    }


}

void RailwayManagementAdmin::addTrain()
{
    getchar();
    ofstream add_train;
    add_train.open("trainInfo.txt",ios_base::app);
    string train_name;
    int total_compartment;
    int seat;
    printf("Train name: "); cin >> train_name;
    printf("Total compartment: "); cin >> total_compartment;
    printf("Seat in per compartment: "); cin >> seat;

    add_train << train_name << "  " << total_compartment << "  " << seat << endl;

    add_train.close();
    RailwayManagementAdmin obj;
    obj.adminMenu();
}

void showTrainList()
{
    ifstream read_train("trainInfo.txt");
    string train_name;
    int compartment, seat, train_index = 0;
    if(read_train.is_open())
        while(read_train >> train_name >> compartment >> seat)
        {
            cout << train_index << "  " << train_name << "  " << compartment << "  " << seat;
            cout << endl;
            train_index++;
        }
    read_train.close();
}

void RailwayManagementAdmin::scheduleTrain()
{
    ofstream schedule_train("schedulaTraininfo.txt",ios_base :: app);
    ifstream read_train("trainInfo.txt");
    string train_name;
    int train_no,compartment, seat;
    //string to, from, arrival_time, depature_time, off_day, date;

    /*for(int i = read_train.beg; i <= read_train.tellg(); i++)
    {
        read_train >> train_name >> compartment >> seat;
        cout << i <<"  " << train_name << "  " << compartment << "  " << seat;
        cout << endl;
    }*/

    showTrainList();

    printf("Select Train: "); cin >> train_no;
    int loop_counter_in_read_train = 0;
    if(read_train.is_open())
    {
        while (read_train >> train_name >> compartment >> seat)
        {
            if(loop_counter_in_read_train == train_no)
            {
                printf("From: "); cin >> from;
                printf("To: "); cin >> to;
                printf("Depature Time: "); cin >> depature_time;
                printf("Arrival Time: "); cin >> arrival_time;
                //printf("Date: "); cin >> date;
                printf("Off Day: "); cin >> off_day;
                //read_train >> train_name;// >> compartment >> seat;
                schedule_train << train_name << "  " << from << "  " << to << "  " << arrival_time << "  " <<
                depature_time << "  " << off_day << endl;
                cin.ignore();
                break;
            }
            loop_counter_in_read_train = loop_counter_in_read_train + 1;
            cout << train_name << endl;
        }

    }

    read_train.close();
    schedule_train.close();
}

void RailwayManagementAdmin::showReadyTrain()
{
    ifstream read_ready_schedule("schedulaTraininfo.txt");
    //ifstream read_ready_train("trainInfo.txt");
    cout << "Train List" << endl;
    showTrainList();
    cout << endl;

    if(read_ready_schedule.is_open())
    {
        cout << "Schedule List\t" << endl;
        cout << "Train Name\t\t" << "From\t" << "To\t" << "Arrival Time\t" << "Departure Time\t" << "Off Day" << endl;
        cout << endl;
        while(read_ready_schedule >> train_name >> from >> to >> arrival_time >> depature_time >> off_day)
        {
            cout << train_name << "\t\t" << from << "\t" << to << "\t" << arrival_time << "\t" << depature_time << "\t" << off_day << endl;
            cout << endl;
        }
    }
    read_ready_schedule.close();

}


int main()
{
    RailWayManagement obj;
    RailwayManagementAdmin admin_obj;
    int option;
    printf("1.Login\n");
    printf("2.Sign up\n");
    printf("3.Admin\n");
    printf("4.Exit\n");
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
        admin_obj.adminMenu();
        break;
    case 4:
        exit(1);

    default:
        printf("Unknown response\n");
        main();
        break;
    }
    //obj.signUp();
    //obj.showUserInfo();

}
