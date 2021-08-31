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
  char number[50];
  char gmail[40];
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
  void deletecontact(char n[20]);
  void searchbyname(char p[20]);
  void searchbynumber(char no[30]);
  void searchbygmail(char g[20]);
  void newnode();
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

void utility::newnode()
{
  char number[50];
  char gmail[40];
  char name[30];
  char ans;
  do
  {
    cout << "\nENTER NAME      :";
    cin >> name;
    cout << "ENTER NUMBER    :";
    cin >> number;
    while (strlen(number) != 10)
    {
      cout << "ENTER VALID NUMBER  :";
      cin >> number;
    }
    cout << "ENTER MAIL ID    :";
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
    cout << "DO YOU WANT TO CONTINUE?????????";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
}
void utility::display()
{
  ptr = head;         
  while (ptr != NULL) 
  {
    cout << "\n\nNAME  :\t" << ptr->name;
    cout << "\nNUMBER:\t+91-" << ptr->number;
    cout << "\nMAIL ID:\t" << ptr->gmail;
    ptr = ptr->next;
  }
}

void utility::insert()
{
  newnode();
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
    cout << "DELETED!\n\n";
  }
  if (ptr == head)
  {
    head = head->next;
    head->prev = NULL;
    delete (ptr);
    cout << "DELETED!\n\n";
  }
  if (ptr->next == NULL)
  {
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    delete (ptr);
    cout << "DELETED!\n\n";
  }
  if (c == 2)
  {
    cout << "NOT FOUND!!";
  }
}
void utility::searchbyname(char na[10])
{
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(na, ptr->name) == 0)
    {
      cout << "NAME FOUND" << endl;
      cout << "DETAILS.\n"
           << endl;
      cout << "\n\nNAME  :\t" << ptr->name;
      cout << "\nNUMBER:\t+91-" << ptr->number;
      cout << "\nMAIL ID:\t" << ptr->gmail;
    }
    ptr = ptr->next;
  }
}
void utility::searchbynumber(char num[20])
{
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(num, ptr->number) == 0)
    {
      cout << "NUMBER FOUND!\n"
           << endl;
      cout << "DETAILS\n"
           << endl;
      cout << "\n\nNAME  :\t" << ptr->name;
      cout << "\nNUMBER:\t+91-" << ptr->number;
      cout << "\nMAIL ID:\t" << ptr->gmail;
    }
    ptr = ptr->next;
  }
}
void utility::searchbygmail(char gm[20])
{
  ptr = head;
  while (ptr != NULL)
  {
    if (strcmp(gm, ptr->gmail) == 0)
    {
      cout << "G-MAIL FOUND\n"
           << endl;
      cout << "DETAILS!\n"
           << endl;
      cout << "\n\nNAME  :\t" << ptr->name;
      cout << "\nNUMBER:\t+91-" << ptr->number;
      cout << "\nMAIL ID:\t" << ptr->gmail;
    }
    ptr = ptr->next;
  }
}
void utility::update(char n[20])
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
        cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
        cin >> c;
        switch (c)
        {
        case 1:
          cout << "ENTER NEW-NAME=";
          cin >> ptr->name;
          break;
        case 2:
          cout << "ENTER NEW PHONE-NUMBER?";
          cin >> ptr->number;
          while (strlen(ptr->number) != 10)
          {
            cout << "ENTER VALID NUMBER  :";
            cin >> ptr->number;
          }
          break;
        case 3:
          cout << "ENTER NEW MAIL ID";
          cin >> ptr->gmail;
          break;
        }
        cout << "DO YOU WANT TO CONTINUE UPDATING?";
        cin >> ans;
      } while (ans == 'y');
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
  cout << "\n\n\n\n**************                               Divyatej Mishra's Phonebook Project                     ********************";
  cout << "\n\nWHAT IS YOUR NAME?\n";
  cin.getline(name, 20);
  cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << name << "   !!!!!!!!!!!!!!!!!!!!!";
  d1.newnode();
  do
  {
    cout << "\n\n\n\n1) DISPLAY YOUR PHONEBOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) SEARCH\n";
    cin >> ch;
    switch (ch)
    {
    case 2:
      d1.insert();
      break;

    case 1:
      d1.display();
      break;
    case 3:

      cout << "\n\nENTER THE NAME OF PERSON WHOSE DETAILS HAS TO BE UPDATED\n";
      cin >> n;
      d1.update(n);

      break;
    case 4:
      cout << "\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
      cin >> name;
      d1.deletecontact(name);
      break;
    case 5:
      do
      {
        cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n";
        cin >> a;
        switch (a)
        {
        case 1:
          cout << "ENTER THE NAME TO BE SEARCHED\n";
          cin >> name;
          d1.searchbyname(name);
          break;
        case 2:
          cout << "ENTER THE NAME TO BE SEARCHED\n";
          cin >> number;
          d1.searchbynumber(number);
          break;
        case 3:
          cout << "ENTER THE NAME TO BE SEARCHED\n";
          cin >> gmail;
          d1.searchbygmail(gmail);
          break;
        default:
          cout << "\nINVALID INPUT!\n";
        }
        cout << "DO YOU WANT TO CONTINUE SEARCHING?";
        cin >> ans;
      } while (ans == 'y' || ans == 'Y');

      break;
;
    default:
      cout << "\nINVALID INPUT!\n";
    }
    cout << "\n\nMENU?";
    cin >> ans;
  } while (ans == 'y' || ans == 'Y');
}
