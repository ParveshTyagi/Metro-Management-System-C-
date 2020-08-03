#include<iostream>
#include<fstream>
using namespace std;

fstream file, fl;
void MainMenu();
void Admin();
void User();
void Passenger();
void EmployeeMenu();
void MetroMenu();
void AlterTrain();
template<typename T>
T sum(T a, T b)
{
    return (a+b);
}

class Employee{
private:
    char name[20], id[20];
    string password;
    int age, employee_no;
    unsigned int salary;
public:
	void CreateEmployee()
	{
		int choice;
		system("cls");
		cout<<"***********************************************"<<endl;
		cout<<"\t\tWelcome to Delhi Metro"<<endl;
		cout<<"***********************************************"<<endl;
		cout<<"Please, Enter the following details:"<<endl;
		cout<<"Name\t:";
		cin.getline(name,20);
		cout<<"Age\t:";
		cin>>age;
		cout<<"salary\t:";
		cin>>salary;
		cin.ignore();
		cout<<"Email ID\t:";
		cin.getline(id,20);
		//cin.ignore();
		cout<<"Password\t:";
		cin>>password;
		cout<<"Enter Employee Number\t:";
		cin>>employee_no;
		cin.ignore();
	}

	void DisplayEmployee()
	{

		cout<<"The details of Employee Number: "<<employee_no<<endl;
		cout<<"Name\t: "<<name<<endl;
		cout<<"Age\t: "<<age<<endl;
		cout<<"Salary\t: "<<salary<<endl;
		cout<<"Email ID : "<<id<<endl;
		cout<<"Password : "<<password<<endl;
	}

	void AlterEmployee()
	{
		cout<<"Select the field to be changed: \n";
		int choice;
		cout<<"1: Name\n2: Age:\n3: Salary\n4: ID\n5:Password\n6:Return to Previous Menu\n";
		cin>>choice;
		cin.ignore();
		switch (choice)
		{
			case 1:
				cout<<"Enter new Name: ";
				cin.getline(name,20);
				cout<<"Update Successful\n";
				system("pause");
				system("cls");
				DisplayEmployee();
				AlterEmployee();
				break;
			case 2:
				cout<<"Enter new Age: ";
				cin>>age;
				cout<<"Update Successful\n";
				system("pause");
				system("cls");
				DisplayEmployee();
				AlterEmployee();
				break;
			case 3:
				cout<<"Enter new Salary: ";
				cin>>salary;
				cout<<"Update Successful\n";
				system("pause");
				system("cls");
				DisplayEmployee();
				AlterEmployee();
				break;
			case 4:
				cout<<"Enter new ID: ";
				cin.getline(id,20);
				cout<<"Update Successful\n";
				system("pause");
				system("cls");
				DisplayEmployee();
				AlterEmployee();
				break;
			case 5:
				cout<<"Enter new Password: ";
				cin>>password;
				cout<<"Update Successful\n";
				system("pause");
				system("cls");
				DisplayEmployee();
				AlterEmployee();
				break;
			case 6:
				EmployeeMenu();
				break;
			default:
				system("cls");
				cout<<"Please, Enter a valid input\n";
				AlterEmployee();
		}
	}

	int Employee_Num()
	{
		return employee_no;
	}

	string Employee_Pwd()
	{
	    return password;
	}

};

class MetroRoute
{
    char source[20], destination[20];
    float fare;

public:
    void GetRoute()
    {

        cout<<"Please, Enter the following details about Train Route: \n";
        cout<<"Starting point: ";
        cin.getline(source, 20);
        cout<<"Destination: ";
        cin.getline(destination, 20);
        cout<<"Fare: ";
        cin>>fare;

    }

    void DisplayRoute()
    {
        cout<<"The Route's details are:\n";
        cout<<"Starting point: "<<source<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Fare: "<<fare<<endl;
        cout<<"----------------------------------------------------------\n";

    }

    float Fare()
    {
        return fare;
    }

    friend class MetroCard;

    void AlterRoute()
    {
        int choice;
        system("cls");
        cout<<"To update route, Select from the following options:\n";
        cout<<"1: Stating point\n2: Destination\n3: Fare\n4: Return to Previous Menu\n";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout<<"Enter new Starting Point: ";
            cin.getline(source, 20);
            cout<<"Updated successfully, new Starting Point is: "<<source<<endl;
            system("pause");
            AlterRoute();
            break;
        case 2:
            cout<<"Enter new Destination: ";
            cin.getline(destination, 20);
            cout<<"Updated successfully, new Destination is: "<<destination<<endl;
            system("pause");
            AlterRoute();
            break;
        case 3:
            cout<<"New Fare: ";
            cin>>fare;
            cout<<"Updated successfully, new Fare is: "<<fare<<endl;
            system("pause");
            AlterRoute();
            break;
        case 4:
            AlterTrain();
            break;
        default:
            system("cls");
            cout<<"Please, Enter a valid input"<<endl;
            AlterRoute();
        }
    }
};

class MetroTrain: public MetroRoute
{
    int train_no, no_coaches;
public:
    void GetTrain()
    {
        system("cls");
        cout<<"**********************************************************\n";
        cout<<"\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
        cout<<"Please, Enter the following details about Metro Train:\n";
        cout<<"Train Number: ";
        cin>>train_no;
        cout<<"Number of Coaches: ";
        cin>>no_coaches;
        cin.ignore();
        GetRoute();

    }

    void DisplayTrain()
    {
        cout<<"The following are the details of the Metro Train:\n";
        cout<<"Train Number: "<<train_no<<endl;
        cout<<"Number of Coaches: "<<no_coaches<<endl;
        DisplayRoute();

    }

    void AlterTrains()
    {
        system("cls");
        cout<<"**********************************************************\n";
        cout<<"\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
        int choice;
        cout<<"To update, Select from the following options:\n";
        cout<<"1: Train Number\n2: Number of Coaches \n3: Update Route and Fare\n4 :Return to Previous Menu\n";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout<<"Enter new Train Number: ";
            cin>>train_no;
            cout<<"Updated successfully, new Train Number is: "<<train_no<<endl;
            system("pause");
            AlterTrains();
            break;
        case 2:
            cout<<"Enter new Number of Coaches: ";
            cin>>no_coaches;
            cout<<"Updated successfully, new Number of Coaches is: "<<no_coaches<<endl;
            system("pause");
            AlterTrains();
            break;
        case 3:
            AlterRoute();
            break;
        case 4:
            MetroMenu();
            break;
        default:
            system("cls");
            cout<<"Enter a Valid Input\n";
            AlterTrains();
        }

    }

    int Train_Num()
    {
        return train_no;
    }
};

class MetroCard
{
    int card_no;
    float balance;
public:
    void CreateCard()
    {
        system("cls");
		cout<<"**********************************************************\n";
        cout<<"\t\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
        cout<<"Please enter the following details:\n";
        cout<<"Card No.: ";
        cin>>card_no;
        cout<<"Balance: ";
        cin>>balance;
        cout<<"-----------------------------------------------------------\n";
        cout<<"Card created successfully\n";
        cout<<"-----------------------------------------------------------\n";
        system("pause");
    }

    void DisplayCard()
    {
        cout<<"The Cards details are:\n";
        cout<<"Card Number: "<<card_no<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"-----------------------------------------------------------\n";
    }

    float Balance()
    {
        return balance;
    }

    int Card_No()
    {
        return card_no;
    }

    void operator += (float amount)
    {
        //balance += amount;
        balance = sum(balance, amount);
    }

    void operator -= (float amount)
    {
        balance -= amount;
    }


};

Employee employee;
MetroTrain train;
MetroCard card;

void SelectTrain()
{
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    fl.open("card.dat", ios::in| ios::out);
    int card_num;
    cout<<"Enter the Card No.: ";
    cin>>card_num;
    while(fl.read((char *)& card, sizeof(MetroCard)))
    {
        if(card_num==card.Card_No())
        {
            break;
        }
    }
    file.open("metro.dat", ios::in);
    int num;
    cout<<"Enter the Metro train no.: ";
    cin>>num;
    while(file.read((char *)& train, sizeof(MetroTrain)))
    {
        if(num==train.Train_Num())
        {
            train.DisplayRoute();
            float bal = card.Balance();
            float amount = train.Fare();
            if(bal>=amount)
            {
                card -= amount;
                cout<<"Token created successfully\n";
            }
            else
                cout<<"Not Sufficient Balance";


            break;
        }

    }
    fl.write((char *)& card, sizeof(MetroCard));
    file.close();
    fl.close();

}

void ShowTrains()
{
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    file.open("metro.dat", ios::in);
    //file.seekg(-1, ios::cur);
    while(file.read((char*)& train, sizeof(MetroTrain)))
    {
        train.DisplayTrain();
    }
    file.close();
}

void CreateToken()
{
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    file.open("metro.dat", ios::in);
    int num, flag=0;
    cout<<"Enter the Metro train no.: ";
    cin>>num;
    while(file.read((char *)& train, sizeof(MetroTrain)))
    {
        if(num==train.Train_Num()& flag==0)
        {
            train.DisplayRoute();
            cout<<"Token created successfully\n";
            break;
        }
    }
    if(flag==0)
        cout<<"Train not found\n";
    file.close();
}

void CheckBalance()
{
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    int num, flag=0;
    file.open("card.dat", ios::in);
    cout<<"Please, Enter the Card number: ";
    cin>>num;
    while(file.read((char *)& card, sizeof(MetroCard)))
    {
        if(num==card.Card_No() & flag==0)
        {
            card.DisplayCard();
            flag=1;
        }
    }
    if(flag==0)
        cout<<"Card not found, Please try another card\n";
    file.close();


}

void UpdateBalance()
{
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    int num;
    file.open("card.dat", ios::in|ios::out);
    cout<<"Please, Enter the Card number: ";
    cin>>num;
    while(file.read((char *)& card, sizeof(MetroCard)))
    {
        if(num==card.Card_No())
        {
            card.DisplayCard();
            cout<<"Enter the amount to add: ";
            float amount;
            cin>>amount;
            card += amount;
            file.write((char *)& card, sizeof(MetroCard));
        }
    }

    file.close();
    cout<<card.Balance()<<"Balance Update successful\n";

}
void EmployeeDetails()
{
    int num;
    file.open("employee.dat", ios::in | ios::out);
			int flag=0;
			cout<<"Enter Employee Number: ";
			cin>>num;
			while(file.read((char * ) & employee, sizeof(Employee)))
			{
				if(employee.Employee_Num()==num && flag==0)
				{

					employee.DisplayEmployee();
					flag=1;
					break;

				}
			}
			if(flag==0)
				{
				    cout<<"Employee not found";
				}
			file.close();
			cout<<endl;
}

void UpdateEmployee()
{
    int flag=0, num;
			file.open("employee.dat", ios::in | ios::out);
			cout<<"Enter Employee Number: ";
			cin>>num;
			while(file.read((char * ) & employee, sizeof(Employee)))
			{
				if(employee.Employee_Num()==num && flag==0)
				{
				    system("cls");
					int pos = -1 * sizeof(employee);
					employee.DisplayEmployee();
					employee.AlterEmployee();
					file.seekp(pos, ios::cur);
					file.write((char * ) & employee, sizeof(Employee));
					flag=1;
					break;

				}

			}
			if(flag==0)
            {
                cout<<"Match not found";
            }
			file.close();
			cout<<endl;
}

void UpdateTrain()
{
        int flag=0, train_num;
        cout<<"Enter Train Number: ";
        cin>>train_num;
        file.open("metro.dat", ios::in | ios::out);
        //file.seekg(ios::beg);
        while(file.read((char *)& train, sizeof(MetroTrain)))
        {
            if(train.Train_Num()==train_num && flag==0)
            {
                int pos = -1*sizeof(MetroTrain);
                train.AlterTrains();
                file.seekp(pos, ios::cur);
                file.write((char *) & train, sizeof(MetroTrain));
                flag =1;
            }

        }
        if(flag==0)
        {
                cout<<"Match not found\n";
        }
        file.close();
}

void AlterTrain()
{
    train.AlterTrains();
}


void MetroMenu()
{
    int choice;
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    cout<<"Please, select from the following options:\n"<<"1: Add Metro Train\n"<<"2: Alter Metro Train\n";
    cout<<"3: Display Metro Train List\n"<<"4: Return to Previous Menu\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        file.open("metro.dat", ios::out | ios::app);
        train.GetTrain();
        file.write((char *)& train, sizeof(MetroTrain));
        file.close();
        cout<<"Metro Train added successfully\n";
        system("pause");
        MetroMenu();
        break;
    case 2:
        UpdateTrain();
        system("pause");
        MetroMenu();
        break;
    case 3:
        ShowTrains();
        system("pause");
        MetroMenu();
        break;
    case 4:
        Admin();
        break;
    default:
        system("cls");
        cout<<"Please, Enter a Valid Input\n";
        MetroMenu();
    }

}

void EmployeeMenu()
	{
		int choice, num;
		system("cls");
		cout<<"**********************************************************\n";
        cout<<"\t\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
		cout<<"Please, select from the following options:\n"<<"1: Add new employee\n"<<"2: Show the list of all Employee\n";
		cout<<"3: Show details of particular Employee\n"<<"4: Alter the Employee details\n"<<"5: Admin Menu\n";
		cin>>choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			file.open("employee.dat",ios::out | ios::app);
			employee.CreateEmployee();
			file.write((char * ) & employee, sizeof(Employee));
			file.close();
			cout<<endl;
			system("pause");
			EmployeeMenu();
			break;
		case 2:
			file.open("employee.dat", ios::in);
			while(file.read((char * ) & employee, sizeof(Employee)))
			{
				employee.DisplayEmployee();
			}
			file.close();
			cout<<endl;
			system("pause");
			EmployeeMenu();
			break;
		case 3:
		    EmployeeDetails();
			system("pause");
			EmployeeMenu();
			break;
		case 4:
		    UpdateEmployee();
			system("pause");
			EmployeeMenu();
			break;
		case 5:
			Admin();
			break;
		default:
			system("cls");
			cout<<"Please, Enter a valid input\n";
			cout<<endl;
			system("pause");
			EmployeeMenu();
		}
		//system("pause");
	}


void AdminCheck()
{
    string admin_id, pwd;
    cout<<"Enter the Login Details:\n";
    cout<<"Admin ID: ";
    cin>>admin_id;
    if(admin_id=="Admin")
    {
        cout<<"Password: ";
        cin>>pwd;
        if(pwd=="12345678")
        {
            cout<<"Login successful\n";
            system("pause");
            Admin();
        }
        else
            cout<<"Wrong Password\n";
    }
    else
        cout<<"Wrong Admin ID\n";
    system("pause");
    MainMenu();

}

void Usercheck()
{
    file.open("employee.dat", ios::in);
    int id, flag=0;
    cout<<"Please enter the following details \nEmployee No.: ";
    cin>>id;
    //cin.ignore();
    string pwd;
    while(file.read((char *) & employee, sizeof(Employee)))
    {
        if(id==employee.Employee_Num() & flag==0)
        {
            cout<<"Password: ";
            cin>>pwd;
            if(pwd==employee.Employee_Pwd())
            {
                cout<<"Login successful\n";
                system("pause");
                User();
            }
            else
            {
                cout<<"Password not matched, Please try again\n";
                system("pause");
            }
        }
        else
        {
            cout<<"Employee Number not found, Please try again\n";
            system("pause");
        }
    }
    file.close();

}

	void Admin()
	{
		int choice;
		system("cls");
		cout<<"**********************************************************\n";
        cout<<"\t\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
		cout<<"Please, select from the following options:\n"<<"1: Metro Train Menu\n"<<"2: Employee Menu\n3: Return to Main Menu\n";
		cin>>choice;
		switch (choice)
		{
        case 1:
            MetroMenu();
            break;
       /* case 2:
            RouteMenu();
            break; */
		case 2:
			EmployeeMenu();
			break;
        case 3:
            MainMenu();
            break;
        default:
            system("cls");
            cout<<"Please, Enter a Valid Input\n";
            Admin();
		}
	}

	void User()
	{
	    system("cls");
		cout<<"**********************************************************\n";
        cout<<"\t\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
        cout<<"Select from the following options:\n1: Create Metro Token\n2: Create Metro Card\n";
        cout<<"3: Update Balance in Metro Card\n4: Display all Metro Trains\n5: Return to Previous Menu\n";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            CreateToken();
            system("pause");
            User();
            break;
        case 2:
            file.open("card.dat", ios::out | ios::app);
            card.CreateCard();
            file.write((char *)& card, sizeof(MetroCard));
            file.close();
            cout<<endl;
            system("pause");
            User();
            break;
        case 3:
            UpdateBalance();
            system("pause");
            User();
            break;
        case 4:
            ShowTrains();
            system("pause");
            User();
            break;
        case 5:
            MainMenu();\
            break;
        default:
            cout<<"Please Enter a Valid Input\n";
            system("pause");
            User();
        }
	}

	void Passenger()
	{
	    system("cls");
		cout<<"**********************************************************\n";
        cout<<"\t\t\t Delhi Metro\n";
        cout<<"**********************************************************\n";
        int choice;
        cout<<"Please, choose from the following options:\n1: Select the Metro Train\n2: Check Balance\n";
        cout<<"3: Display All Metro Trains\n4: Return to Previous Menu";
        cin>>choice;
        switch (choice)
        {
        case 1:
            SelectTrain();
            system("pause");
            cout<<endl;
            Passenger();
            break;
        case 2:
            CheckBalance();
            system("pause");
            cout<<endl;
            Passenger();
            break;
        case 3:
            file.open("metro.dat", ios::in);
            while(file.read((char *)& train, sizeof(MetroTrain)))
            {
               train.DisplayTrain();
            }
            file.close();
            system("pause");
            cout<<endl;
            Passenger();
            break;
        case 4:
            MainMenu();
            break;
        default:
            cout<<"Please Enter a Valid Input\n";
            system("pause");
            Passenger();

        }
	}

void MainMenu()
	{
	    int choice;
    system("cls");
    cout<<"**********************************************************\n";
    cout<<"\t\t\t Delhi Metro\n";
    cout<<"**********************************************************\n";
    cout<<"Select from the following:\n1: Admin\n2: User\n3: Passenger\n4: Exit\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        Admin();
        break;
    case 2:
        Usercheck();
        break;
    case 3:
        Passenger();
        break;
    case 4:
        cout<<"Thank you for using Delhi Metro Service\n";
        system("pause");
        break;
    default:
        cout<<"Please Enter a Valid Input\n";
        system("pause");
        MainMenu();
    }
	}

int main()
{
    MainMenu();
    return 0;
}

