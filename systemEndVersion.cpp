#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
void menu();
bool signup(string name, string password, string role);
string signin(string name, string password);
void menu();
void logo();
void pharmacyPrint();
void menuAdmin();
void menuEmploye();
void menuCustomer();
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
void chkAttendence();
void markAttendence();
void billsManage();
void requestMedicine();
void aboutPharmacy();
void enterMedicine();
void billForCustomer();
void chkbill();
void dailyReport();
void changePassword();
int navigation(int navig);
string getField(string record, int field);
void storeData();
void loadData();
void storeMedicine();
void loadMedicine();
void storeFeedback();
void loadFeedback();
void storeDailyReport();
void loadDailyReport();
void storeTotal();
void loadTotal();
void markAttendence();
void storeAttendence();
void loadAttendence();
bool validation(string temp);
bool stringValidation(string temp1);
void gotoxy(int, int);

bool check;
int userCount = 1;
int index = 0;
// int index1 = 0;
int index2 = 0;
int index3 = 0;
int index4 = 0;
int total = 0;
int totalCount = 0;
fstream myFile;
// arrays
int arrsize = 10;
string username[10];
string passwards[10];
string roles[10];
string attendence[10];
string medicine[500];
int quantity[500];
string feedback[500];
string buy[500];
int buyQuantity[500];
int buyPrice[500];
int cost[50];
int totals[500];

string getField(string record, int field);

main()
{
  pharmacyPrint();
  username[0] = "hamza123";
  passwards[0] = "abcd";
  roles[0] = "Admin";
  loadData();
  loadMedicine();
  loadFeedback();
  loadDailyReport();
  loadTotal();
  loadAttendence();
  // loadEnterMedicine();
  int loginOption = 0;
  while (loginOption != 3)
  {
    logo();
    loginOption = menuOption();
    if (loginOption == 2)
    {
      system("cls");
      string password;
      string name;
      string role;
      menu();
      cout << "Enter the username : ";
      getline(cin >> ws, name);
      cout << "Enter the password : ";
      cin >> password;
      role = signin(name, password);
      // storeData();
      if (role == "Admin")
      {
        clearScreen();
        // menu();
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
      string role = "Admin";
      menu();
      cout << "Enter the username : ";
      cin >> name;
      cout << "Enter the password : ";
      cin >> password;
      while (role == "Admin")
      {
        cout << "Enter your role (Employe or Customer) : ";
        cin >> role;
        if (role == "Admin")
        {
          cout << "......You cannot signup as an Admin...." << endl;
          cout << "......Please Try Again................." << endl;
        }
      }
      bool isValid = signup(name, password, role);
      if (isValid)
      {
        cout << "Sign up Successfully" << endl;
      }
      if (!(isValid))
      {
        cout << " ................User Already Present............ " << endl;
      }
    }
    clearScreen();
  }
}
void menu()
{
  int k = 5;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << endl
       << endl
       << endl;
  cout << "**************************************************************************************" << endl;
  cout << endl;
  cout << "                       PHARMACY     MANAGEMENT      SYSTEM" << endl;
  cout << endl;
  cout << "**************************************************************************************" << endl;
}
void pharmacyPrint()
{
  system("cls");
  cout << "                         ___________  " << endl;
  cout << "                        [___________]     " << endl;
  cout << "                         {=========}     " << endl;
  cout << "                       .-'         '-.     " << endl;
  cout << "                      /               \\\\     " << endl;
  cout << "                     /_________________\\     " << endl;
  cout << "                     |   _  _   _      |     " << endl;
  cout << "                     ||\\(_ |_)||_)||\\ ||     " << endl;
  cout << "    ,.--.   ,.--.    ||~\\_)|  || \\|| \\||     " << endl;
  cout << "   /  \\  \\ /  \\  \\   |_________________|     " << endl;
  cout << "   \\\\  \\ / \\\\  \\ /   |                 |     " << endl;
  cout << "    `'--'   `'--'    '-----------------'     " << endl;
  cout << endl;
  cout << "                                                             I--------------I   " << endl;
  cout << "                                                             I--------------I    " << endl;
  cout << "                                                            .-'             '-.   " << endl;
  cout << "                                                           / --.-.--,---,.--.\\  " << endl;
  cout << "                                                          /--.-.--,---,.--.,--\\ " << endl;
  cout << "                                                          |--------------------| " << endl;
  cout << "                                                          |       ANTI         | " << endl;
  cout << "                                                          |                    | " << endl;
  cout << "                                                          |  VERBAL-DIARRHOEA  | " << endl;
  cout << "                                                          |                    | " << endl;
  cout << "                                                          |     MEDICINE       | " << endl;
  cout << "                                                          |                    | " << endl;
  cout << "                                                          | [ Pharmacy Only ]  | " << endl;
  cout << "                                                          |____________________| " << endl;
  cout << "                                                          |.,--.-.--,---,.--.-.| " << endl;
  cout << "                                                          |--.-.--,---,.--.,--.| " << endl;
  cout << "                                                          '--------------------' " << endl;
  cout << endl
       << endl;

  cout << "                                  ..................WELCOME TO OUR PHARMACY................" << endl;
  getch();
}
void logo()
{
  int k = 1;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  system("cls");
  cout << "            /$$                                                                                                             /$$                            " << endl;
  cout << "           | $$                                                                                                            | $$                             " << endl;
  cout << "   /$$$$$$ | $$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$   /$$$$$$$ /$$   /$$        /$$$$$$$ /$$   /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$/$$$$  " << endl;
  cout << "  /$$__  $$| $$__  $$ |____  $$ /$$__  $$| $$_  $$_  $$ |____  $$ /$$_____/| $$  | $$       /$$_____/| $$  | $$ /$$_____/|_  $$_/   /$$__  $$| $$_  $$_  $$ " << endl;
  cout << " | $$  \\ $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$ \\ $$ \\ $$  /$$$$$$$| $$      | $$  | $$      |  $$$$$$ | $$  | $$|  $$$$$$   | $$    | $$$$$$$$| $$ \\ $$ \\ $$ " << endl;
  cout << " | $$  | $$| $$  | $$ /$$__  $$| $$      | $$ | $$ | $$ /$$__  $$| $$      | $$  | $$       \\____  $$| $$  | $$ \\____  $$  | $$ /$$| $$_____/| $$ | $$ | $$ " << endl;
  cout << " | $$$$$$$/| $$  | $$|  $$$$$$$| $$      | $$ | $$ | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$       /$$$$$$$/|  $$$$$$$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$ | $$ | $$ " << endl;
  cout << " | $$____/ |__/  |__/ \\_______/|__/      |__/ |__/ |__/ \\_______/ \\_______/ \\____  $$      |_______/  \\____  $$|_______/    \\___/   \\_______/|__/ |__/ |__/ " << endl;
  cout << " | $$                                                                       /$$  | $$                 /$$  | $$                                             " << endl;
  cout << " | $$                                                                      |  $$$$$$/                |  $$$$$$/                                             " << endl;
  cout << " |__/                                                                       \\\\______/                  \\______/    " << endl;
  cout << endl;
  cout << endl
       << endl
       << endl
       << endl;
}
void menuAdmin()
{
  cout << "                             $$$$$$\\        $$\\               $$\\                 $$\\      $$\\                                       " << endl;
  cout << "                            $$  __$$\\       $$ |              \\__|                $$$\\    $$$ |                                      " << endl;
  cout << "                            $$ /  $$ | $$$$$$$ |$$$$$$\\$$$$\\  $$\\ $$$$$$$\\        $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  $$\\   $$\\         " << endl;
  cout << "                            $$$$$$$$ |$$  __$$ |$$  _$$  _$$\\ $$ |$$  __$$\\       $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ $$ |  $$ |        " << endl;
  cout << "                            $$  __$$ |$$ /  $$ |$$ / $$ / $$ |$$ |$$ |  $$ |      $$ \\$$$  $$ |$$$$$$$$ |$$ |  $$ |$$ |  $$ |        " << endl;
  cout << "                            $$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$ |$$ |  $$ |      $$ |\\$  /$$ |$$   ____|$$ |  $$ |$$ |  $$ |        " << endl;
  cout << "                            $$ |  $$ |\\$$$$$$$ |$$ | $$ | $$ |$$ |$$ |  $$ |      $$ | \\_/ $$ |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$  |        " << endl;
  cout << "                            \\__|  \\__| \\_______|\\__| \\__| \\__|\\__|\\__|  \\__|      \\__|     \\__| \\_______|\\__|  \\__| \\______/         " << endl;
  cout << endl;
  cout << "************************************************************************************************************************************************************************       " << endl;
}
void menuEmploye()
{
  cout << "              $$$$$$$$\\                         $$\\                                     $$\\      $$\\                                 " << endl;
  cout << "             $$  _____|                        $$ |                                    $$$\\    $$$ |                                 " << endl;
  cout << "             $$ |      $$$$$$\\$$$$\\   $$$$$$\\  $$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\        $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  $$\\   $$\\    " << endl;
  cout << "             $$$$$\\    $$  _$$  _$$\\ $$  __$$\\ $$ |$$  __$$\\ $$ |  $$ |$$  __$$\\       $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ $$ |  $$ |   " << endl;
  cout << "             $$  __|   $$ / $$ / $$ |$$ /  $$ |$$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |      $$ \\$$$  $$ |$$$$$$$$ |$$ |  $$ |$$ |  $$ |   " << endl;
  cout << "             $$ |      $$ | $$ | $$ |$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |$$   ____|      $$ |\\$  /$$ |$$   ____|$$ |  $$ |$$ |  $$ |   " << endl;
  cout << "             $$$$$$$$\\ $$ | $$ | $$ |$$$$$$$  |$$ |\\$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\       $$ | \\_/ $$ |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$  |   " << endl;
  cout << "             \\________|\\__| \\__| \\__|$$  ____/ \\__| \\______/  \\____$$ | \\_______|      \\__|     \\__| \\_______|\\__|  \\__| \\______/    " << endl;
  cout << "                                     $$ |                    $$\\   $$ |                                                              " << endl;
  cout << "                                     $$ |                    \\$$$$$$  |                                                              " << endl;
  cout << "                                     \\__|                     \\______/                                                               " << endl;
  cout << endl;
  cout << "************************************************************************************************************************************************************************       " << endl;
}
void menuCustomer()
{
  cout << "   $$$$$$\\                        $$\\                                                       $$\\      $$\\                                " << endl;
  cout << "  $$  __$$\\                       $$ |                                                      $$$\\    $$$ |                               " << endl;
  cout << "  $$ /  \\__|$$\\   $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\   $$$$$$\\        $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  $$\\   $$\\  " << endl;
  cout << "  $$ |      $$ |  $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  _$$  _$$\\ $$  __$$\\ $$  __$$\\       $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ $$ |  $$ | " << endl;
  cout << "  $$ |      $$ |  $$ |\\$$$$$$\\    $$ |    $$ /  $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  \\__|      $$ \\$$$  $$ |$$$$$$$$ |$$ |  $$ |$$ |  $$ | " << endl;
  cout << "  $$ |  $$\\ $$ |  $$ | \\____$$\\   $$ |$$\\ $$ |  $$ |$$ | $$ | $$ |$$   ____|$$ |            $$ |\\$  /$$ |$$   ____|$$ |  $$ |$$ |  $$ | " << endl;
  cout << "  \\$$$$$$  |\\$$$$$$  |$$$$$$$  |  \\$$$$  |\\$$$$$$  |$$ | $$ | $$ |\\$$$$$$$\\ $$ |            $$ | \\_/ $$ |\\$$$$$$$\\ $$ |  $$ |\\$$$$$$  | " << endl;
  cout << "   \\______/  \\______/ \\_______/    \\____/  \\______/ \\__| \\__| \\__| \\_______|\\__|            \\__|     \\__| \\_______|\\__|  \\__|  \\______/  " << endl;
  cout << endl;
  cout << "************************************************************************************************************************************************************************       " << endl;
}

int menuOption()
{
  cout << "\t\t\t Signup " << endl;
  cout << "\t\t\t Signin " << endl;
  cout << "\t\t\t Exit " << endl;
  cout << endl;
  int option = navigation(3);
  return option;
}
int adminMenu()
{
  system("cls");
  menuAdmin();
  int k = 6;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << endl
       << endl
       << endl
       << endl
       << endl;
  cout << "\t\t\t Mark Attendence " << endl;
  cout << "\t\t\t Bills Management " << endl;
  cout << "\t\t\t Add medicine stock " << endl;
  cout << "\t\t\t Remove medicine " << endl;
  cout << "\t\t\t View stock " << endl;
  cout << "\t\t\t Add Employe and Admin " << endl;
  cout << "\t\t\t view staffs " << endl;
  cout << "\t\t\t Check Feedback " << endl;
  cout << "\t\t\t Check Attendence " << endl;
  cout << "\t\t\t Exit " << endl;
  int option = navigation(10);
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
    cout << " User Already exit! please Enter a new one.... " << endl;
  }
  else if (userCount < arrsize)
  {
    username[userCount] = name;
    passwards[userCount] = password;
    roles[userCount] = role;
    storeData();
    userCount++;
    return true;
  }
  else
  {
    return false;
  }
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
string signin(string name, string password)
{
  for (int index = 0; index < userCount; index++)
  {
    storeData();
    if (username[index] == name && passwards[index] == password)
    {
      return roles[index];
    }
  }

  return "Undefined";
}
int employMenu()
{
  menuEmploye();
  int k = 6;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << endl
       << endl;
  cout << "\t\t\t Bill for customer " << endl;
  cout << "\t\t\t View medicine stock " << endl;
  cout << "\t\t\t Change Password " << endl;
  cout << "\t\t\t Request medicine " << endl;
  cout << "\t\t\t Daily report " << endl;
  cout << "\t\t\t Exit " << endl;
  int option = navigation(6);
  return option;
}
int customerMenu()
{
  menuCustomer();
  int k = 6;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << endl
       << endl
       << endl
       << endl
       << endl;
  cout << "\t\t\t Enter the medicine " << endl;
  cout << "\t\t\t Claim his bill " << endl;
  cout << "\t\t\t Give Feedback " << endl;
  cout << "\t\t\t Exit " << endl;
  int option = navigation(4);
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
      menu();
      addMedicine();
    }
    if (option == 2)
    {
      menu();
      billsManage();
      getch();
    }
    if (option == 5)
    {
      menu();
      viewInventory();
      getch();
    }
    if (option == 6)
    {
      menu();
      addStaff();
    }
    if (option == 9)
    {
      menu();
      chkAttendence();
      getch();
    }
    if (option == 1)
    {
      menu();
      markAttendence();
      getch();
    }
    if (option == 7)
    {
      menu();
      viewStaff();
    }
    if (option == 4)
    {
      menu();
      removeMedicine();
    }
    if (option == 10)
    {
      system("cls");
      break;
    }
    if (option > 10)
    {
      cout << "Please enter the valid option......." << endl;
      getch();
      system("cls");
      continue;
    }
    if (option == 8)
    {
      chkfeedback();
    }
    // cout << "Press any key to continue...";
    // getch();
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
      menu();
      viewInventory();
    }
    if (option == 4)
    {
      menu();
      requestMedicine();
    }
    if (option == 5)
    {
      menu();
      dailyReport();
    }
    if (option == 1)
    {
      menu();
      billForCustomer();
    }
    if (option == 3)
    {
      menu();
      changePassword();
      // getch();
      // continue;
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
  index4 = 0;
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
  string temp, temp1;
  int values;
  cout << "Enter the medicine you want to add : ";
  cin >> temp1;
  while (!(stringValidation(temp1)))
  {
    cout << "Invalid,try Again." << endl;
    cin >> temp1;
  }
  cout << "Enter the quantity of adding medicine : ";
  cin >> temp;
  while (!(validation(temp)))
  {
    cout << "Invalid,try Again." << endl;
    cin >> temp;
  }

  values = stoi(temp);
  medicine[index] = temp1;
  quantity[index] = values;
  index++;
  storeMedicine();
}
void viewInventory()
{
  system("cls");
  menu();
  gotoxy(6, 12);
  cout << "No";
  gotoxy(36, 12);
  cout << "Medicine";
  gotoxy(66, 12);
  cout << "Quantity";
  for (int i = 0; i < index; i++)
  {

    gotoxy(6, 13 + i);
    cout << i + 1 << ".";
    gotoxy(36, 13 + i);
    cout << medicine[i];
    gotoxy(66, 13 + i);
    cout << quantity[i];
  }
  cout << endl;
  cout << "Press any key to continue..." << endl;
  getch();
}
void addStaff()
{
  string temp1;
  cout << "Enter the name : ";
  cin >> temp1;
   while (!(stringValidation(temp1)))
  {
    cout << "Invalid,try Again." << endl;
    cin >> temp1;
  }
  username[userCount] = temp1;
  cout << "Enter the password : ";
  cin >> passwards[userCount];
  cout << "Enter the role : ";
  cin >> roles[userCount];
  userCount++;
  storeData();
  //   cout << "Press any key to continue....";
  //   getch();
}
void chkfeedback()
{
  for (int i = 0; i < index2; i++)
  {
    cout << "\t"
         << ".........." << feedback[i] << endl;
  }
  cout << "Press any key to continue......... ";
  getch();
  // index2++;
}
void viewStaff()
{
  system("cls");
  menu();
  gotoxy(6, 12);
  cout << "UserName";
  gotoxy(36, 12);
  cout << "Passwords";
  gotoxy(66, 12);
  cout << "Role";
  for (int i = 0; i < userCount; i++)
  {
    gotoxy(6, 13 + i);
    cout << username[i];
    gotoxy(36, 13 + i);
    cout << passwards[i];
    gotoxy(66, 13 + i);
    cout << roles[i];
  }
  cout << endl;
  cout << "Press any key to continue...";
  getch();
}
void removeMedicine()
{
  string temp1;
  string remove;
  cout << "...............Available Medicines...................... " << endl;
  for (int i = 0; i < index; i++)
  {
    cout << i + 1 << "."
         << "\t" << medicine[i] << "\t"
         << quantity[i] << "\t" << endl;
  }
  cout << "Enter the medicine you want to remove : ";
  cin >> temp1;
   while (!(stringValidation(temp1)))
  {
    cout << "Invalid,try Again." << endl;
    cin >> temp1;
  }
  remove = temp1;
  int i = 0;
  while (i < index)
  {
    if (remove == medicine[i])
    {
      for (int j = i; j < index - 1; j++)
      {
        medicine[j] = medicine[j + 1];
        quantity[j] = quantity[j + 1];
        // break;
      }
      index--;
    }
    else
    {
      i++;
      // continue;
    }
  }
  storeMedicine();
}
void billsManage()
{
  for (int i = 0; i < index3; i++)
  {
    cout << buy[i] << "\t"
         << "\t" << buyQuantity[i] << "\t" << buyPrice[i] << "\t"
         << "Employe" << endl;

    // for (int i = 0; i < totalCount; i++)
    // {
    //   cout << "Day " << i + 1 << "\t\t"
    //        << "Total\t" << totals[i] << " Rs" << endl;
    // }
  }
  cout << endl
       << endl
       << endl;
  for (int i = 0; i < totalCount; i++)
  {
    cout << "Day " << i + 1 << "\t\t"
         << "Total\t" << totals[i] << " Rs" << endl;
  }
}
void chkAttendence()
{
  for (int i = 0; i < userCount; i++)
  {
    if (roles[i] == "Employe")
    {
      gotoxy(15, 18 + i);
      cout << username[i] << "\t\t " << attendence[i] << endl;
      // storeAttendence();
    }
    else if (roles[i] == "Customer")
    {
      continue;
    }
    else if (roles[i] == "Admin")
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
  bool check = true;
  cout << "Enter the name of medicine : ";
  cin >> name;

  for (int i = 0; i < index; i++)
  {
    // bool check = true;
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
  string temp;
  int values;
  total = 0;
  for (int i = 0; i < index4; i++)
  {
    cout << "Enter the price of  which customer want to bought :  ";
    cin >> temp;
    while (!(validation(temp)))
    {
      cout << "Invalid,try Again." << endl;
      cin >> temp;
    }
    values = stoi(temp);
    cost[i] = values;
  }
  for (int i = 0; i < index4; i++)
  {
    buyPrice[i] = buyQuantity[i] * cost[i];
    total = total + buyPrice[i];
  }
  cout << "Your total bill is = " << total << endl;
  totals[totalCount] = total;
  totalCount++;
  storeTotal();
  storeDailyReport();
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

  // storeTotal();
  storeDailyReport();
}

// employe functionalties..........................

// customer functionalities..........
void aboutPharmacy()
{
  getline(cin >> ws, feedback[index2]);
  storeFeedback();
  index2++;
  cout << endl;
  cout << ".............Thank you for your feedback  (Jazakallah)!................" << endl;
}
void enterMedicine()
{

  string temp;
  int values;
  cout << "Enter the medicine you want to buy : ";
  cin >> buy[index3];
  cout << "Enter the quantity : ";
  cin >> temp;
  while (!(validation(temp)))
  {
    cout << "Invalid,try Again." << endl;
    cin >> temp;
  }
  values = stoi(temp);
  buyQuantity[index3] = values;
  index3++;
  index4++;
  // storeEnterMedicine();
}
void chkbill()
{
  cout << "your total bill is " << total << endl;
  cout << endl;
  cout << "................ThankYou for coming here............. " << endl;
  cout << endl;
}
void changePassword()
{
  string pass;
  string name;
  string newPass;
  int flag;
  cout << "Enter the username :";
  cin >> name;
  cout << "Enter the prevous password : ";
  cin >> pass;
  cout << "Enter the new password : ";
  cin >> newPass;

  for (int i = 0; i < userCount; i++)
  {
    if (name == username[i] && pass == passwards[i])
    {
      flag = 1;

      passwards[i] = newPass;
      cout << "Password Changed Successfully." << endl;
      storeData();
      break;
    }
    else
    {
      flag = 0;
      continue;
    }
    // else
  }

  if (flag == 0)
  {
    cout << "Please Enter the correct previous password." << endl;
  }
}
void storeData()
{

  myFile.open("Data.txt", ios::out);
  for (int i = 0; i < userCount; i++)
  {
    myFile << username[i] << ",";
    myFile << passwards[i] << ",";
    myFile << roles[i] << endl;
  }
  myFile.close();
}
void loadData()
{
  string record;
  myFile.open("Data.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      getline(myFile >> ws, record);
      username[i] = getField(record, 1);
      passwards[i] = getField(record, 2);
      roles[i] = getField(record, 3);
      i++;
    }
    userCount = i - 1;
    myFile.close();
  }
}
void storeMedicine()
{
  myFile.open("medicine.txt", ios::out);
  for (int i = 0; i < index; i++)
  {
    myFile << medicine[i] << ",";
    myFile << quantity[i] << endl;
  }
  myFile.close();
}
void loadMedicine()
{
  string record;
  myFile.open("medicine.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      getline(myFile >> ws, record);
      medicine[i] = getField(record, 1);
      quantity[i] = stoi(getField(record, 2));
      i++;
    }
    index = i - 1;
    myFile.close();
  }
}
void storeFeedback()
{
  myFile.open("feedback.txt", ios::out);
  for (int i = 0; i <= index2; i++)
  {
    myFile << feedback[i] << endl;
  }
  myFile.close();
}
void loadFeedback()
{
  myFile.open("feedback.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      getline(myFile >> ws, feedback[i]);
      i++;
    }
    index2 = i - 1;
    myFile.close();
  }
}
void storeDailyReport()
{
  myFile.open("dailyReport.txt", ios::out);
  for (int i = 0; i < index3; i++)
  {
    myFile << buy[i] << ",";
    myFile << buyQuantity[i] << ",";
    myFile << buyPrice[i] << endl;
  }
  myFile.close();
}
void loadDailyReport()
{
  string record;
  myFile.open("dailyReport.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      getline(myFile >> ws, record);
      buy[i] = getField(record, 1);
      buyQuantity[i] = stoi(getField(record, 2));
      buyPrice[i] = stoi(getField(record, 3));
      i++;
    }
    index3 = i - 1;
    index4 = i - 1;
    myFile.close();
  }
}
void storeTotal()
{
  myFile.open("total.txt", ios::out);
  for (int i = 0; i < totalCount; i++)
  {
    myFile << totals[i] << endl;
  }
  myFile.close();
}
void loadTotal()
{
  myFile.open("total.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      myFile >> totals[i];
      i++;
    }
    totalCount = i - 1;
    myFile.close();
  }
}
int navigation(int navig)
{
  int navX = 20;
  int navY = 16;
  int x = 1;
  while (true)
  {
    gotoxy(navX, navY);
    cout << "=>";
    gotoxy(20, 20);
    if (GetAsyncKeyState(VK_DOWN))
    {
      if (x < navig)
      {
        x = x + 1;
        gotoxy(navX, navY);
        cout << "  ";
        navY = navY + 1;
        gotoxy(navX, navY);
        cout << "=>";
      }
    }
    if (GetAsyncKeyState(VK_UP))
    {
      if (x > 1)
      {
        x = x - 1;
        gotoxy(navX, navY);
        cout << "  ";
        navY = navY - 1;
        gotoxy(navX, navY);
        cout << "=>";
      }
    }
    if (getch() == 13)
    {
      system("cls");
      return x;
    }
    Sleep(100);
  }
}
string getField(string record, int field)
{
  int commaCount = 1;
  string item;
  for (int x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
    {
      commaCount = commaCount + 1;
    }
    else if (commaCount == field)
    {
      item = item + record[x];
    }
  }
  return item;
}

void markAttendence()
{
  for (int i = 0; i < userCount; i++)
  {
    if (roles[i] == "Employe")
    {
      cout << "Is user " << username[i] << " present : ";
      cin >> attendence[i];
      storeAttendence();
    }
    else if (roles[i] == "Customer")
    {
      continue;
    }
    else if (roles[i] == "Admin")
    {
      continue;
    }
  }
  gotoxy(15, 17);
  cout << "......Here is the Attendence of Employe......." << endl;
  for (int i = 0; i < userCount; i++)
  {
    if (roles[i] == "Employe")
    {
      gotoxy(15, 18 + i);
      cout << username[i] << "\t\t " << attendence[i] << endl;
      // storeAttendence();
    }
    else if (roles[i] == "Customer")
    {
      continue;
    }
    else if (roles[i] == "Admin")
    {
      continue;
    }
  }
}
void storeAttendence()
{
  myFile.open("attendence.txt", ios::out);
  for (int i = 0; i < userCount; i++)
  {
    myFile << username[i] << ",";
    myFile << attendence[i] << endl;
  }
  myFile.close();
}
void loadAttendence()
{
  string record;
  myFile.open("attendence.txt", ios::in);
  if (myFile.is_open())
  {
    int i = 0;
    while (!myFile.eof())
    {
      getline(myFile >> ws, record);
      username[i] = getField(record, 1);
      attendence[i] = getField(record, 2);
      i++;
    }
    userCount = i - 1;
    myFile.close();
  }
}
bool validation(string temp)
{
  for (int z = 0; z < temp.length(); z++)
  {
    if (temp[z] != '0' && temp[z] != '1' && temp[z] != '2' && temp[z] != '3' && temp[z] != '4' && temp[z] != '5' && temp[z] != '6' && temp[z] != '7' && temp[z] != '8' && temp[z] != '9')
    {
      return false;
    }
  }
  return true;
}
bool stringValidation(string temp1)
{
  for (int z = 0; z < temp1.length(); z++)
  {
    if (temp1[z] == '0' || temp1[z] == '1' || temp1[z] == '2' || temp1[z] == '3' || temp1[z] == '4' || temp1[z] == '5'|| temp1[z] == '6' || temp1[z] == '7' ||temp1[z] == '8' ||temp1[z] == '9')
    {
      return false;
    }
  }
  return true;
}
