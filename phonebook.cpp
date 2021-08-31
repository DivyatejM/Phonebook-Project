// Divyatej Mishra
// Github : https://github.com/DivyatejM
// Linkedin : https://www.linkedin.com/in/divyatej-mishra/
// Instagram : https://www.instagram.com/divyatej.mishra/

//      Phonebook Project using Linked Lists in C++
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
  char number[30];
  char gmail[30];
  char name[30];
  node *prev, *next;
  node(char n[], char r[], char g[])
  {
    strcpy(name, n);
    strcpy(number, r);
    strcpy(gmail, g);
    next = NULL;
    prev = NULL;
  }
  friend class utility;
};
class utility
{
  node *head, *temp, *ptr;

  node *ptr1, *ptr2, *dup;

public:
  node *prevn;
  void insert();
  void sort();
  void deletecontact(char n[30]);
  void deletesamenumber();
  void deletesamename();
  void deletesamegmail();
  void searchbyname(char p[30]);
  void searchbynumber(char no[30]);
  void searchbygmail(char g[30]);
  void accept();
  void display();
  void update(char ch[10]);
  utility()
  {
    head = NULL;
    temp = NULL;
    ptr = NULL;
    ptr1 = NULL;
    ptr2 = NULL;
    dup = NULL;
  }
};

void utility::accept()
{
  char number[30];
  char gmail[30];
  char name[30];
  char ans;
  do
  {
    cout << "ENTER NAME:";
    cin >> name;
    cout << "Enter Number\t";
    cin >> number;
    while (strlen(number) != 10)
    {
      cout << "Invalid Number!!\nEnter Again\t";
      cin >> number;
    }
    cout << "Enter Mail Address:\t";
    cin >> gmail;
    temp = new node(name, number, gmail);
    if (head == NULL)
    {
      head = temp;
    }
    else
    {
      ptr = head;
      while (ptr->next != NULL)
      {
        ptr = ptr->next;
      }
      ptr->next = temp;
      temp->prev = ptr;
    }
    cout << "Do you want to continue?(Y/N)\t";
    cin >> ans;
  } while (ans == 'y');
}

void utility::display()
{
  ptr = head;
  while (ptr != NULL)
  { 
    cout << "\n\nName:\t" << ptr->name;
    cout << "\nNumber:\t+91-" << ptr->number;
    cout << "\nMail Address:\t" << ptr->gmail;
    ptr = ptr->next;
  }
}

void utility::insert()
{
  accept();
}
void utility::sort()
{
  node *i, *j;
  int temp;
  char n[10];
  for (i = head; i->next != NULL; i = i->next)
  {
    for (j = i->next; j != NULL; j = j->next)
    {
      temp = strcmp(i->name, j->name);
      if (temp > 0)
      {
        strcpy(n, i->name);
        strcpy(i->name, j->name);
        strcpy(j->name, n);
      }
    }
  }
}
void utility::deletecontact(char s[20])
{
  int c = 0;
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(s, ptr->name) == 0)
    {
      c = 1;
      break;
    }
    else
    {
      c = 2;
    }
    ptr = ptr->next;
  }
  if (c == 1 && ptr != head && ptr->next != NULL)
  {
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete (ptr);
    cout << "Deleted!\n\n";
  }
  if (ptr == head)
  {
    head = head->next;
    head->prev = NULL;
    delete (ptr);
    cout << "Deleted!\n\n";
  }
  if (ptr->next == NULL)
  {
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    delete (ptr);
    cout << "Deleted!\n\n";
  }
  if (c == 2)
  {
    cout << "Not Found!";
  }
}

void utility::searchbyname(char na[30])
{
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(na, ptr->name) == 0)
    {
      cout << "Name Found!" << endl;
      cout << "Details:\n"<< endl;
      cout << "\n\nName:\t" << ptr->name;
      cout << "\nNumber:\t+91-" << ptr->number;
      cout << "\nMail Address:\t" << ptr->gmail;
    }
    ptr = ptr->next;
  }
}
void utility::searchbynumber(char num[30])
{
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(num, ptr->number) == 0)
    {
      cout << "Number Found!\n"<< endl;
      cout << "Details:\n"<< endl;
      cout << "\n\nName:\t" << ptr->name;
      cout << "\nNumber:\t+91-" << ptr->number;
      cout << "\nMail Address:\t" << ptr->gmail;
    }
    ptr = ptr->next;
  }
}
void utility::update(char n[30])
{
  char ans;
  int c;
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(n, ptr->name) == 0)
    {

      do
      {
        cout << "\nWhat do you want to update?\n1.Name\n2.Contact Number\n3.Mail Address\n";
        cin >> c;
        switch (c)
        {
        case 1:
          cout << "Enter New Name=";
          cin >> ptr->name;
          break;
        case 2:
          cout << "Enter New Contact Number=";
          cin >> ptr->number;
          while (strlen(ptr->number) != 10)
          {
            cout << "Invalid Number!!\nEnter Again:\t";
            cin >> ptr->number;
          }
          break;
        case 3:
          cout << "Enter New Mail Address";
          cin >> ptr->gmail;
          break;
        }
        cout << "Do you want to keep updating?(Y/N)";
        cin >> ans;
      } while (ans == 'y' || ans == 'Y');
    }
    ptr = ptr->next;
  }
}
int main()
{
  char n[20];
  char nam[20];
  char name[10];
  char number[10];
  char gmail[20];
  utility d1;
  char ans;
  int ch, a;
  cout << "**************                                PHONE BOOK                          ********************";
  cout << "\n\nWhat is your Name?\n";
  cin.getline(name, 20);
  cout << "\n\n!!!!!!!!!!!!   Welcome " << name << "   !!!!!!!!!!!!!!!!!!!!!";
  d1.accept();
  d1.sort();
  do
  {
    cout << "\n\n\nMenu\n\n1) Display Phonebook\n2) Insert New Contact\n3) Update Existing\n4) DELETE CONTACT\n5) SEARCH\n";
    cin >> ch;
    switch (ch)
    {
    case 2:
      d1.insert();
      d1.sort();
      break;

    case 1:
      d1.sort();
      d1.display();
      break;
    case 3:

      cout << "\n\nEnter Name\n";
      cin >> n;
      d1.update(n);
      d1.sort();
      break;
    case 4:
      cout << "\nEnte the name that has to be deleted\n";
      cin >> name;
      d1.deletecontact(name);
      break;
    case 5:
      do
      {
        cout << "1.Search by Namee\n2.Search by Number\n";
        cin >> a;
        switch (a)
        {
        case 1:
          cout << "Enter the Name to be searched\n";
          cin >> name;
          d1.searchbyname(name);
          break;
        case 2:
          cout << "Enter the Number to be searched\n";
          cin >> number;
          d1.searchbynumber(number);
          break;
        default:
          cout << "\nInvalid Input\n";
        }
        cout << "Do you want to continue searching?(Y/N)";
        cin >> ans;
      } while (ans == 'y' || ans == 'Y');

      break;
    case 8:
      d1.deletesamegmail();
      d1.display();
      break;
    default:
      cout << "\nNO PROPER INPUT GIVEN..\n";
    }
    cout << "\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
}