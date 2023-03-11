#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void menu();
bool signup(string name, string password, string role);
string signin(string name, string password);
void menu();
int menuOption();
void clearScreen();
void adminInterface();
void employeInterface();
void customerInterface();
void addMedicine();
void chkfeedback();
void viewInventory();
void addStaff();
void viewStaff();
void removeMedicine();
void requestMedicine();
void aboutPharmacy();
void enterMedicine();
void billForCustomer();
void chkbill();
void dailyReport();

bool check;
int userCount = 0;
int index = 0;
int index1 = 0;
int index2 = 0;
int index3 = 0;
int total = 0;
// arrays
int arrsize = 10;
string username[10];
string passwards[10];
string roles[10];
string medicine[500];
int quantity[500];
string staffName[50];
int staffPass[50];
string feedback[500];
string buy[500];
int buyQuantity[500];
int buyPrice[500];
int cost[50];

main()
{
  int loginOption = 0;
  while (loginOption != 3)
  {
    menu();
    loginOption = menuOption();
    if (loginOption == 2)
    {
      system("cls");
      string password;
      string name;
      string role;
      menu();
      cout << "Enter the username : ";
      cin >> name;
      cout << "Enter the password : ";
      cin >> password;
      role = signin(name, password);
      if (role == "Admin")
      {
        clearScreen();
        adminInterface();
        check == true;
      }
      else if (role == "Employe")
      {
        clearScreen();
        employeInterface();
      }
      else if (role == "Customer")
      {
        clearScreen();
        customerInterface();
      }
      else if (role == "Undefined")
      {
        cout << "You have Entered Wrong id and password ! " << endl;
      }
    }
    else if (loginOption == 1)
    {
      system("cls");
      string password;
      string name;
      string role;
      menu();
      cout << "Enter the username : ";
      cin >> name;
      cout << "Enter the password : ";
      cin >> password;
      cout << "Enter your role (Admin or Employe or Customer) : ";
      cin >> role;
      bool isValid = signup(name, password, role);
      if (isValid)
      {
        cout << "Sign up Successfully" << endl;
      }
      if (!(isValid))
      {
        cout << "No more space : " << endl;
      }
    }
    clearScreen();
  }
}
void menu()
{
  cout << "**************************************************************************************" << endl;
  cout << endl;
  cout << "                       PHARMACY     MANAGEMENT      SYSTEM" << endl;
  cout << endl;
  cout << "**************************************************************************************" << endl;
}
int menuOption()
{
  cout << "1. Signup " << endl;
  cout << "2. Signin " << endl;
  cout << "3. Exit " << endl;
  cout << endl;
  int option;
  cout << "Enter the option : ";
  cin >> option;
  return option;
}
int adminMenu()
{
  int option;
  cout << "1. Budget Management " << endl;
  cout << "2. Bills Management " << endl;
  cout << "3. Add medicine stock " << endl;
  cout << "4. Remove medicine " << endl;
  cout << "5. View stock " << endl;
  cout << "6. Add staff " << endl;
  cout << "7. view staff " << endl;
  cout << "8. Check Feedback " << endl;
  cout << "9. Exit " << endl;
  cout << "Enter option : ";
  cin >> option;
  return option;
}
void clearScreen()
{
  cout << "Press any key to continue... : " << endl;
  getch();
  system("cls");
}
bool signup(string name, string password, string role)
{
  bool isPresent = false;

  for (int index = 0; index < userCount; index++)
  {
    if (username[index] == name && passwards[index] == password)
    {
      isPresent = true;
      break;
    }
  }
  if (isPresent == true)
  {
    return 0;
    cout << "User Already exit! please Enter a new one.... " << endl;
  }
  else if (userCount < arrsize)
  {
    username[userCount] = name;
    passwards[userCount] = password;
    roles[userCount] = role;
    userCount++;
    return true;
  }
  else
  {
    return false;
  }
}
string signin(string name, string password)
{
  for (int index = 0; index < userCount; index++)
  {
    if (username[index] == name && passwards[index] == password)
    {
      return roles[index];
    }
  }
  return "Undefined";
}
int employMenu()
{
  int option;

  cout << "1. Bill for customer " << endl;
  cout << "2. View medicine stock " << endl;
  cout << "3. Change Password " << endl;
  cout << "4. Request medicine " << endl;
  cout << "5. Daily report " << endl;
  cout << "6. Exit " << endl;
  cout << "Enter the option : ";
  cin >> option;
  return option;
}
int customerMenu()
{
  int option;
  cout << "1. Enter the medicine " << endl;
  cout << "2. Claim his bill " << endl;
  cout << "3. Give Feedback " << endl;
  cout << "4. Exit " << endl;
  cout << "Enter your option :" << endl;

  cin >> option;
  return option;
}
void adminInterface()
{

  bool exit = false;
  while (exit == false)
  {
    system("cls");
    int option = adminMenu();
    if (option == 3)
    {
      addMedicine();
    }
     if (option == 2)
    {
      dailyReport();
    }
    if (option == 5)
    {
      viewInventory();
    }
    if (option == 6)
    {
      addStaff();
    }
      if (option == 1)
    {
      cout<<"This function is not implemented yet!";
      getch();
      continue;
    }
    if (option == 7)
    {
      viewStaff();
    }
    if (option == 4)
    {
      removeMedicine();
    }
    if (option == 9)
    {
      system("cls");
      break;
    }
    if (option > 9)
    {
      cout << "Please enter the valid option......."<<endl;
      getch();
      system("cls");
      continue;
    }
    if (option == 8)
    {
      chkfeedback();
    }
    cout << "Press any key to continue...";
    getch();
  }
}
void employeInterface()
{
  bool exit = false;
  while (exit == false)
  {
    system("cls");
    int option = employMenu();
    if (option == 2)
    {
      viewInventory();
    }
    if (option == 4)
    {
      requestMedicine();
    }
    if (option == 5)
    {
      dailyReport();
    }
    if (option == 1)
    {
      billForCustomer();
    }
     if (option == 3)
    {
      cout<<"This function is not implemented yet!";
      getch();
      continue;
    }
    if (option > 6)
    {
      cout << "Please enter the valid option.......";
    }
    if (option == 6)
    {
      system("cls");
      break;
    }
    cout << "Press any key to continue...";
    getch();
  }
}

void customerInterface()
{
  bool loop = false;
  while (loop == false)
  {
    system("cls");
    int option = customerMenu();
    if (option == 3)
    {
      aboutPharmacy();
    }
    if (option == 1)
    {
      enterMedicine();
    }
    if (option == 2)
    {
      chkbill();
    }
    if (option == 4)
    {
      system("cls");
      break;
    }
    if (option > 4)
    {
      cout << "Please enter the valid option.......";
    }
    cout << "Press any key to continue...";
    getch();
  }
}

// Admin functionalities..................
void addMedicine()
{
  cout << "Enter the medicine you want to add : ";
  cin >> medicine[index];
  cout << "Enter the quantity of adding medicine : ";
  cin >> quantity[index];
  index++;
}
void viewInventory()
{
  for (int i = 0; i < index; i++)
  {
    cout << i + 1 << "."
         << "\t" << medicine[i] << "\t"
         << "    " << quantity[i] << "\t" << endl;
  }
  cout << "Press any key to continue..." << endl;
  getch();
}
void addStaff()
{
  cout << "Enter the name of employer : ";
  cin >> staffName[index1];
  cout << "Enter the password of employer : ";
  cin >> staffPass[index1];
  index1++;
  cout << "Press any key to continue....";
  getch();
}
void chkfeedback()
{
  for (int i = 0; i < index2 + 1; i++)
  {
    cout << i + 1 << "."
         << " " << feedback[i] << endl;
  }
  // index2++;
}
void viewStaff()
{
  for (int i = 0; i < index1; i++)
  {
    cout << i + 1 << "."
         << "\t"
         << "    " << staffName[i] << "\t"
         << "   " << staffPass[i] << "\t" << endl;
  }
  cout << "Press any key to continue...";
  getch();
}
void removeMedicine()
{
  string remove;
  cout << "...............Available Medicines...................... " << endl;
  for (int i = 0; i < index; i++)
  {
    cout << i + 1 << "."
         << "\t" << medicine[i] << "\t"
         << "    " << quantity[i] << "\t" << endl;
  }
  cout << "Enter the medicine you want to remove : ";
  cin >> remove;
  for (int i = 0; i < index; i++)
  {
    if (remove == medicine[i])
    {
      medicine[i] = medicine[i + 1];
      quantity[i] = quantity[i + 1];
      index--;
      break;
    }
    else
    {
      continue;
    }
  }
}
// admin functionalties..................................

// Employe funtionaities..........................
void requestMedicine()
{
  string name;
  // bool check = true;
  cout << "Enter the name of medicine : ";
  cin >> name;

  for (int i = 0; i < index; i++)
  {
    bool check = true;
    if (name == medicine[i])
    {
        check = true;
      cout << "....This medicine is available..... " << endl;
      cout << i + 1 << "."
           << "\t" << medicine[i] << "\t\t" << quantity[i] << endl;
      break;
    }

    else
    {
      check = false;
    }
  }
  if (check == false)
  {
    cout << "....This meidicine is not available in your Pharmacy....... " << endl;
    cout << "....Please ask the Admin to order this medicine...." << endl;
  }
}

void billForCustomer()
{
    
   for (int i = 0; i < index3-1 + 1; i++)
  {
     cout << "Enter the price of  which customer want to bought :  ";
  cin >> cost[i];

  }
  for (int i = 0; i < index3; i++)
  {

    buyPrice[i] = buyQuantity[i] * cost[i];
    // cout<<"your bill is "<< buyPrice[i]<<endl;
    total = total + buyPrice[i];
  }
  cout << "Your total bill is = " << total << endl;
  // index3++;
}
void dailyReport()
{
  for (int i = 0; i < index3; i++)
  {
    cout << buy[i] << "\t"
         << "\t" << buyQuantity[i] << "\t" << buyPrice[i] << "\t"
         << "Employe" << endl;
  }
  cout << endl;
  cout << "The total amount you earn today is :  " << total << endl;
}

// employe functionalties..........................

// customer functionalities..........
void aboutPharmacy()
{
  cout << "Enter the feedback about our pharmacy : ";
  getline(cin >> ws, feedback[index2]);
  index2++;
  cout << endl;
  cout << ".............Thank you for your feedback  (Jazakallah)!................" << endl;
}
void enterMedicine()
{

  cout << "Enter the medicine you want to buy : ";
  cin >> buy[index3];
  cout << "Enter the quantity : ";
  cin >> buyQuantity[index3];
  index3++;
}
void chkbill()
{
  cout << "your total bill is " << total << endl;
  cout << endl;
  cout << "................ThankYou for coming here............. " << endl;
  cout << endl;
}