#include<fstream>

#include<conio.h>

#include<process.h>

#include<string.h>

#include<graphics.h>

#include<stdlib.h>

#include<dos.h>

#include<string.h>

using namespace std;

void boun();
class employee {
  public: int empno;
  char n[50],
  add[20],
  des[20],
  c,
  mob[20],
  dob[20],
  gen[10];
  float s,
  da,
  hra,
  tax,
  gr,
  np;

  void calculate11();
  void pslip(int);
  void accept() {
    boun();
    textcolor(2);
    cout << endl;
    gotoxy(10, 5);
    cprintf("Enter Name ");
    cin >> n;
    cout << endl;
    gotoxy(10, 7);
    cprintf("Enter Employee Number ");
    cin >> empno;
    cout << endl;
    gotoxy(10, 9);
    cprintf("Enter Designation (Clerk/Manager/Substaff) ");
    cin >> des;
    cout << endl;
    gotoxy(10, 11);
    cprintf("Enter The Address ");
    cin >> add;
    gotoxy(10, 13);
    cprintf("Enter the Mobile Number - ");
    cin >> mob;
    gotoxy(10, 15);
    cprintf("Gender - ");
    cin >> gen;
    gotoxy(10, 17);
    cprintf("Date Of Birth (DD-MM-YY) - ");
    cin >> dob;
    gotoxy(10, 19);
    cout << endl;
    calculate11();
  }
  void display() {
    boun();
    textcolor(3);
    cout << endl;
    gotoxy(10, 5);
    cprintf("Employee Number ");
    cout << empno;
    gotoxy(10, 7);
    cprintf("Name ");
    cout << n;
    gotoxy(10, 9);
    cprintf("Designation ");
    cout << des;
    gotoxy(10, 11);
    cprintf("Address ");
    cout << add;
    gotoxy(10, 13);
    cprintf("Mobile Number - ");
    cout << mob;
    gotoxy(10, 15);
    cprintf("Gender - ");
    cout << gen;
    gotoxy(10, 17);
    cprintf("Date Of Birth - ");
    cout << dob;
    gotoxy(10, 19);
    cprintf("Salary ");
    cout << np;
    gotoxy(10, 21);
    cprintf("Press Any Key");
    getch();
  }
  int searchno(char name[]) {
    if (strcmpi(n, name) == 0)
      return 1;
    else
      return 0;
  }
  int searchd(char desig[]) {
    if (strcmpi(desig, des) == 0)
      return 1;
    else
      return 0;
  }
  int searchn(int no) {
    if (no == empno)
      return 1;
    else
      return 0;
  }
  int returnempno() {
    return empno;
  }
};
void employee::pslip(int sam) {
  boun();
  int k = 7 + sam;
  gotoxy(3, k);
  cout << empno;

  gotoxy(10, k);
  cout << n;
  gotoxy(20, k);
  cout << des;
  gotoxy(30, k);
  cout << s;
  gotoxy(42, k);
  cout << gr;
  gotoxy(52, k);
  cout << tax;

  gotoxy(67, k);
  cout << np;
  k = k + 1;
}
void employee::calculate11() {
  if (strcmpi(des, "Clerk") == 0) {
    s = 20000;
    da = 1000;
    hra = 2000;
    tax = 10 * (s) / 100.0;
  } else {
    if (strcmpi(des, "Manager") == 0) {
      s = 40000;
      hra = 5000;
      da = 1500;
      tax = 20 * (s) / 100.0;
    } else
    if (strcmpi(des, "Substaff") == 0) {
      s = 10000;
      hra = 1000;
      da = s * 1.10;
      tax = 5 * (s) / 100.0;
    }
  }
  gr = s + hra + da;
  np = gr - tax;
}
void main() {
  void boundary();
  void employmanagement();
  void about();
  int main1();
  int main3();
  void salarymanagement();
  boundary();
  clrscr();
  int i;
  fstream obj, obj1;
  employee e;
  char n[20], desig[20], password[] = "tiger", pass[20];
  int no, t, empn;
  int ch1, choice;
  textcolor(GREEN);
  boun();
  gotoxy(20, 8);
  textcolor(9);
  cprintf("PASSWORD--  ");
  for (i = 0; pass[i - 1] != 13; i++) {
    pass[i] = getch();
    textcolor(4);
    cprintf("\b* ");
  }
  pass[i - 1] = NULL;
  if (strcmpi(pass, password) == 0) {
    do {
      clrscr();
      ch1 = main1();
      switch (ch1) {
      case 1:
        clrscr();
        obj.open("employee.dat", ios::binary | ios::app);
        e.accept();
        obj.write((char * ) & e, sizeof(e));
        obj.close();
        break;
      case 2:
        employmanagement();
        break;
      case 3:
        salarymanagement();
        break;
      case 4:
        clrscr();
        obj.open("employee.dat", ios::binary | ios::in);
        while (obj) {
          obj.read((char * ) & e, sizeof(e));
          if (obj.eof())
            break;
          e.display();
          clrscr();
        }
        clrscr();
        obj.close();
        break;
      case 5:
        clrscr();
        obj.open("employee.dat", ios::binary | ios::in);
        obj1.open("copy.dat", ios::binary | ios::out);
        cprintf("Enter Employee Number To Be Removed ");
        cin >> empn;
        while (!obj.eof()) {
          obj.read((char * ) & e, sizeof(e));
          if (obj.eof())
            break;
          if (e.returnempno() != empn) {
            obj1.write((char * ) & e, sizeof(e));
            i = 1;
          }
        }
        obj.close();
        obj1.close();
        obj.open("employee.dat", ios::binary | ios::out);
        obj1.open("copy.dat", ios::binary | ios::in);
        while (obj1) {
          obj1.read((char * ) & e, sizeof(e));
          if (obj1.eof())
            break;
          obj.write((char * ) & e, sizeof(e));
        }
        obj.close();
        obj1.close();
        break;
      case 6:
        about();
        break;
      case 7:
        exit(0);
      default:
        gotoxy(30, 20);
        cout << "Wrong Choice ";
        getch();
      }
    } while (1);
  } else
    cout << "Wrong Password " << endl;

}
void boundary() {
  int userpat;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  setbkcolor(WHITE);
  setlinestyle(4, userpat, 2);
  setcolor(RED);
  rectangle(10, 20, 625, 465);
  delay(200);
  rectangle(20, 30, 615, 455);
  delay(200);
  rectangle(30, 40, 605, 445);
  delay(200);
  setbkcolor(WHITE);
  rectangle(40, 50, 595, 280);
  rectangle(40, 290, 595, 435);
  setfillstyle(10, GREEN);
  bar(40, 50, 595, 280);
  setfillstyle(10, GREEN);
  bar(40, 290, 595, 435);
  setcolor(RED);
  settextstyle(4, 0, 5);
  outtextxy(120, 50, "Kaustubh & Samaksh");
  settextstyle(1, 0, 4);
  outtextxy(160, 110, "COMPUTER PROJECT");
  settextstyle(8, 0, 4);
  outtextxy(270, 150, "ON");
  settextstyle(10, 0, 3);
  outtextxy(90, 200, "EMPLOYEE MANAGEMENT");
  line(95, 260, 540, 260);
  line(95, 265, 540, 265);
  settextstyle(1, 0, 2);
  outtextxy(55, 300, "MADE BY :");
  line(50, 325, 160, 325);
  line(60, 330, 150, 330);
  settextstyle(3, 0, 1);
  outtextxy(60, 340, "KAUSTUBH PATHAK");
  outtextxy(60, 370, "SAMAKSH SINGH");
  settextstyle(1, 0, 2);
  outtextxy(370, 300, "SPECIAL THANKS TO :");
  line(365, 325, 580, 325);
  line(375, 330, 575, 330);
  settextstyle(3, 0, 1);
  outtextxy(465, 340, "MR ANIL");

  getch();
  closegraph();
}
int main1() {
  char x;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  setbkcolor(5);
  rectangle(10, 20, 625, 465);
  delay(200);
  rectangle(20, 30, 615, 455);
  delay(200);
  rectangle(30, 40, 605, 445);
  delay(200);
  setbkcolor(5);
  settextstyle(10, 0, 2);
  outtextxy(230, 60, "MAIN MENU");
  line(210, 110, 420, 110);
  line(210, 115, 420, 115);
  setcolor(3);
  settextstyle(7, 0, 1);
  outtextxy(160, 130, "1 -->  Add New Employee ");
  outtextxy(160, 160, "2 -->  Employee Management");
  outtextxy(160, 190, "3 -->  Salary Management");
  outtextxy(160, 220, "4 -->  Display All Employee Details ");
  outtextxy(160, 250, "5 -->  Delete An Employee Record ");
  outtextxy(160, 280, "6 -->  About The Project");
  outtextxy(160, 310, "7 -->  Press To EXIT Program");
  settextstyle(7, 0, 1);
  setcolor(4);
  outtextxy(160, 350, "Enter Ur Choice");
  x = getch();
  closegraph();
  int y;
  if (x == '1') y = 1;
  else if (x == '2') y = 2;
  else if (x == '3') y = 3;
  else if (x == '4') y = 4;
  else if (x == '5') y = 5;
  else if (x == '6') y = 6;
  else if (x == '7') y = 7;
  else y = 8;
  return y;
}
void employmanagement() {
  void sename();
  int main2();
  void seno();
  void sedes();
  char choice;
  choice = main2();
  switch (choice) {
  case 1:
    sename();
    break;
  case 2:
    seno();
    break;
  case 3:
    sedes();
    break;
  case 4:
    break;
  default:
    cout << "wrong choice";
  }

}
int main2() {
  char x;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  setbkcolor(BROWN);
  rectangle(10, 20, 625, 465);
  delay(200);
  rectangle(20, 30, 615, 455);
  delay(200);
  rectangle(30, 40, 605, 445);
  delay(200);
  setbkcolor(5);
  settextstyle(7, 0, 1);
  outtextxy(230, 60, "Employee Management");
  line(210, 110, 420, 110);
  line(210, 115, 420, 115);
  setcolor(2);
  settextstyle(7, 0, 1);
  outtextxy(160, 130, "1 --> Search Employee by name");
  outtextxy(160, 160, "2 --> Search by Employee Number");
  outtextxy(160, 190, "3 --> Search by Designation");
  outtextxy(160, 220, "4 --> EXIT");
  settextstyle(7, 0, 1);
  setcolor(4);
  outtextxy(160, 280, "Enter your Choice");
  x = getch();
  closegraph();
  int y;
  if (x == '1') y = 1;
  else if (x == '2') y = 2;
  else if (x == '3') y = 3;
  else if (x == '4') y = 4;
  else y = 5;
  return y;
}
void sename() {
  clrscr();
  employee e;
  fstream obj;
  char n[20];
  obj.open("employee.dat", ios::binary | ios::in);
  textcolor(9);
  cprintf("Enter The Name To Be Searched ");
  cin >> n;
  int t;
  while (obj) {
    obj.read((char * ) & e, sizeof(e));
    t = e.searchno(n);
    if (t == 1) {
      e.display();
      clrscr();
      break;
    }
  }
  if (t == 0) {
    cout << "Given Name Not Found " << endl;
    getch();
    clrscr();
  }
  obj.close();
}
void seno() {
  clrscr();
  fstream obj;
  employee e;
  int no;
  int t;
  textcolor(9);
  obj.open("employee.dat", ios::binary | ios::in);
  cprintf("Enter The Employee Number To Be Searched ");
  cin >> no;
  while (obj) {
    obj.read((char * ) & e, sizeof(e));
    t = e.searchn(no);
    if (t == 1) {
      e.display();
      clrscr();
      break;
    }
  }
  if (t == 0) {
    cout << "Given Employee Number Not Found " << endl;
    getch();
    clrscr();
  }
  obj.close();

}
void about() {
  int c = 1, ch;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  setbkcolor(LIGHTBLUE);
  rectangle(10, 20, 625, 465);
  delay(20);
  rectangle(20, 30, 615, 455);
  delay(20);
  rectangle(30, 40, 605, 445);
  delay(20);
  setcolor(15);
  settextstyle(3, 0, 2);
  outtextxy(50, 50, "This Project is on EMPLOYEE MANAGEMENT which ");
  outtextxy(50, 70, "deals with proper management of employees in ");
  outtextxy(50, 90, "a company. Employee management is the basic  ");
  outtextxy(50, 110, "need in every business today.  ");
  outtextxy(50, 130, "               With proper basic and excellent");
  outtextxy(50, 150, "employee management system you are able to  ");
  outtextxy(50, 170, "success your business in a systematic way.");
  outtextxy(50, 190, "Advantages & benefits of a computerised payroll-- ");
  outtextxy(80, 210, "1. Computerised payroll helps achieve best practice.");
  outtextxy(80, 230, "2. Computerised payroll take less time than manual.  ");
  outtextxy(80, 250, "3. Leave calculations done for you.                 ");
  outtextxy(80, 270, "4. Improved management reporting.                 ");
  outtextxy(80, 290, "5. Back-ups are easy.                            ");
  outtextxy(80, 310, "6. Security and confidentiality                     ");
  setcolor(4);
  settextstyle(7, 0, 1);
  outtextxy(80, 390, "PRESS [Esc] TO EXIT WINDOW");
  do {
    ch = getch();
    if (ch == 27)
      c = 0;
  } while (c);
  closegraph();
}
void sedes() {
  employee e;
  int t;
  fstream obj;
  char n[20], desig[20];
  obj.open("employee.dat", ios::binary | ios::in);
  textcolor(13);
  cprintf("Enter The Designation To Be Searched ");
  cin >> desig;
  while (obj) {
    obj.read((char * ) & e, sizeof(e));
    t = e.searchd(desig);
    if (t == 1) {
      e.display();
      clrscr();
      break;
    }
  }
  if (t == 0) {
    cout << "Enter Valid Designation " << endl;
    getch();
    clrscr();
  }
  obj.close();
}
int main3() {
  char x;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  setbkcolor(BROWN);
  rectangle(10, 20, 625, 465);
  delay(200);
  rectangle(20, 30, 615, 455);
  delay(200);
  rectangle(30, 40, 605, 445);
  delay(200);
  setbkcolor(5);
  settextstyle(8, 0, 1);
  outtextxy(230, 60, "Salary Management");
  line(210, 110, 420, 110);
  line(210, 115, 420, 115);
  setcolor(2);
  settextstyle(8, 0, 1);
  outtextxy(160, 130, "1 --> Whole Report");
  outtextxy(160, 160, "2 --> Pay Slip");
  outtextxy(160, 190, "3 --> Exit");
  settextstyle(7, 0, 1);
  setcolor(4);
  outtextxy(160, 300, "Enter Ur Choice");
  x = getch();
  closegraph();
  int y;
  if (x == '1') y = 1;
  else if (x == '2') y = 2;
  else y = 3;
  return y;
}
void payslip() {
  clrscr();
  fstream obj;
  employee e;
  int eno, flag = 0;
  cout << '\n' << " Enter Employee Number To Be Searched :";
  cin >> eno;
  obj.open("employee.dat", ios::in);

  while (!obj.eof()) {
    obj.read((char * ) & e, sizeof(e));

    if (e.empno == eno) {
      clrscr();
      boun();
      textcolor(1);
      gotoxy(10, 5);
      cout << '\t';
      cprintf("*********************************************");
      gotoxy(10, 6);
      textcolor(13);
      cout << '\t';
      cprintf("         Pay Slip                  ");
      gotoxy(10, 7);
      textcolor(1);
      cout << '\t';
      cprintf("*********************************************");
      gotoxy(10, 8);
      cout << '\t' << "EMPLOYEE CODE                :" << eno;
      gotoxy(10, 9);
      cout << '\t' << "NAME OF EMPLOYEE             :" << e.n;
      gotoxy(10, 10);
      cout << '\t' << "EMPLOYEE DESIGNATION         :" << e.des;
      gotoxy(10, 11);
      cout << '\t' << "BASIC SALARY                 :" << e.s;
      gotoxy(10, 12);
      cout << '\t' << "DEARNESS ALLOWANCE           :" << e.da;
      gotoxy(10, 13);
      cout << '\t' << "HOUSE RENT ALLOWANCE         :" << e.hra;
      gotoxy(10, 14);
      cout << '\t' << "GROSS PAY                    :" << e.gr;
      gotoxy(10, 15);
      cout << '\t' << "TAX                          :" << e.tax;
      gotoxy(10, 16);
      cout << '\t' << "NET PAY                      :" << e.np;
      gotoxy(10, 17);
      cout << '\t' << "*********************************************";
      flag = 1;
      cout << endl;
      gotoxy(15, 20);
      cout << "Press any Key ";
      getch();
    }
  }
  if (flag == 0) {
    clrscr();
    cout << "\n\n\n\n\n\n\t\t\tNo such employee";
    getch();
  }

  obj.close();
}
void report() {
  clrscr();
  fstream obj;
  employee e;
  int gdriver = DETECT, gmode;
  initgraph( & gdriver, & gmode, "../bgi");
  rectangle(0, 0, 600, 450);
  line(0, 50, 600, 50);
  line(0, 90, 600, 90);
  line(50, 90, 50, 450);
  line(140, 90, 140, 450);
  line(220, 90, 220, 450);
  line(290, 90, 290, 450);
  line(390, 90, 390, 450);
  line(490, 90, 490, 450);
  int sam = 0;
  gotoxy(30, 3);
  cout << " EMPLOYEE DETAILS ";
  gotoxy(3, 5);
  cout << "E.NO.";
  gotoxy(10, 5);
  cout << "NAME";
  gotoxy(20, 5);
  cout << "POST";
  gotoxy(30, 5);
  cout << "BASIC";
  gotoxy(40, 5);
  cout << "GROSS PAY";
  gotoxy(52, 5);
  cout << "DEDUCTION";
  gotoxy(67, 5);
  cout << "NETPAY";
  obj.open("employee.dat", ios::in);
  while (!obj.eof()) {
    obj.read((char * ) & e, sizeof(e));
    if (!obj.eof()) {
      e.pslip(sam);
      sam++;
    }
  }
  cout << endl;
  getch();
  obj.close();
}
void salarymanagement() {
  void report();
  void payslip();
  int main3();
  char choice;
  choice = main3();
  switch (choice) {
  case 1:
    report();
    break;
  case 2:
    payslip();
    break;
  default:
    cout << "Wrong Choice";
  }
}

void boun() {
  int y = 2;
  textcolor(14);
  for (int i = 0; i < 39; i++) {
    cprintf("||");
    delay(20);
  }
  cprintf("|");
  textcolor(4);
  for (i = 0; i < 23; i++, y++) {
    gotoxy(78, y);
    cprintf("||");
    delay(30);
  }
  y = 78;
  textcolor(9);
  for (i = 0; i < 79; i++, y--) {
    gotoxy(y, 25);
    cprintf("||");
    delay(20);
  }
  cprintf("|");
  y = 24;
  textcolor(10);
  for (i = 0; i < 23; i++, y--) {
    gotoxy(1, y);
    cprintf("||");
    delay(30);
  }
}
