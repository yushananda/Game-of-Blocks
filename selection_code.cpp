/*	
Project Title	: Hospital Database Management System
Developed By	: Ayush Anand	
Class	: XII-C	
School	: The Mother’s International School	
*/		

#include<conio.h>
#include<fstream.h>

#include<stdio.h>

#include<string.h>

struct BLOODGROUP

{

char A;

char B;

};

struct DATE

{

int day;

int month;

int year;

};

struct APPOINTMENT

{

int patientid;

char Name[40];

char Doctor[40];

DATE appdate;

int adminforward;

};

class PATIENTRECORD

{

int age;

DATE dob;

int PatientID;

char Name[40];

char gender;




 
BLOODGROUP blood;

int Numberofvisits;

DATE nextvisit;

char disorder[40];

char medicine[200];

char doctor[40];

public:

PATIENTRECORD()

{

strcpy(medicine,"Not Yet Prescribed");

strcpy(disorder,"Not Yet Diagnosed");

nextvisit.day=0;

nextvisit.month=0;

nextvisit.year=0;

}

void Input()

{

cout<<"Patient ID: ";

cout<<PatientID<<endl;

cout<<"Name: ";

gets(Name);

cout<<"Age: ";

cin>>age;

cout<<"Date Of Birth(DD MM YYYY Format): ";

cin>>dob.day>>dob.month>>dob.year;

cout<<"Gender: ";

cin>>gender;

cout<<"Blood Group: ";

cin>>blood.A>>blood.B;

cout<<"Enter Number Of Previous Visits: "; cin>>Numberofvisits;
cout<<"Doctor Assigned(No Need to Prefix Dr. ): "; gets(doctor);
}

void Output()

{

cout<<"\nPatient ID: "<<PatientID<<endl;

cout<<"Name: ";

puts(Name);

cout << "Age: " << age <<endl <<"Date of Birth: " << dob.day << "/"

<<	dob.month << "/"<<dob.year << endl; cout<<"Gender: "; cout<<gender<<endl;
cout<<"Blood Group: ";





 
cout<<blood.A<<blood.B<<endl;

cout<<"Number Of Visits: ";

cout<<Numberofvisits<<endl;

cout<<"Doctor Assigned: ";

puts(doctor);

cout<<"Identified Disorder: ";

puts(disorder);

cout<<"Medication: ";

puts(medicine);

cout<<"Date Of Next Visit: ";

if(nextvisit.day!=0)

cout<<nextvisit.day<<"/"<<nextvisit.month<<"/"<<nextvisit.year<<endl; else cout<<"Not Available"<<endl;

getch();

}

void Generatepatientid(int &prev)

{

PatientID=prev+1;

}

int RPatientID()

{

return PatientID;

}

char* RName()

{

return Name;

}

char* RDoctor()

{

return doctor;

}

int RDay()

{

return nextvisit.day;

}

int RMonth()

{

return nextvisit.month;

}

int RYear()

{

return nextvisit.year;

}

int RYob()

{





 
return dob.year;

}

void EditDoctor(char newdoc[])

{

strcpy(doctor,newdoc);

}

void EditNxtVisit()

{

cout<<"Enter new date of next visit: "; cin>>nextvisit.day>>nextvisit.month>>nextvisit.year;

}

void InputD()

{

cout<<"Identified Disorder: ";

gets(disorder);

cout<<"Medicines to be taken: ";

gets(medicine);

cout<<"Date Of Next Visit (Enter 0 0 0 to leave this column blank):

";

cin>>nextvisit.day>>nextvisit.month>>nextvisit.year;

}

void Appointment(DATE app)

{

nextvisit.day=app.day;

nextvisit.month=app.month;

nextvisit.year=app.year;

}

};

void Line(char, int);

void PatientHeader();

void DoctorHeader();

void AdminHeader();

void GeneratePatientPass(int, int);

void GenerateDoctorPass(char []);

void GenerateAdminPass(char pass[]="a");

void CheckPatientPass(int, int &, APPOINTMENT []);

void CheckPass(int, int &, int &, APPOINTMENT [], char dname[]="\0"); void PatientMenu(int, int &, APPOINTMENT []);
void DoctorMenu(char [], int &, APPOINTMENT []); void AdminMenu(int &, int &, APPOINTMENT []); void DoctorNotif(char [], int &, APPOINTMENT []); void AdminNotif(int &, APPOINTMENT []);
void ShiftNotif(int, int &, APPOINTMENT []); void DoctorEdit();




 
void SearchDoctorDate(char []);

void CalculateCollection(char []);

void SearchPatientID();

void ADD(int &);

void EDIT();

void VIEW();

void REMOVE();

void ChangePassword(char []);

void main()

{

GenerateAdminPass();

APPOINTMENT A[100];

char dname[50];

int opt, patientid, notif=0, prev=0;

do

{

{

clrscr();

Line('*',80);

cout<<endl;

Line(' ',27);

cout<<"\n"; Line(' ',12);
cout<<"Computer Science Project For CBSE Examinations 2019-2020\n"; Line(' ',8);
cout<<"By Ayush Anand of Class XII-C\n";

cout<<endl;

Line('*',80);

}

cout<<"\nPlease select the user: \n1. Patient \n2. Doctor \n3. Admin \n4. Exit"<<endl;
cin>>opt;

if(opt==1)

{

PatientHeader();

cout<<"Enter Patient ID: ";

cin>>patientid;

fstream fil1;

fil1.open("Hospital.dat", ios::binary|ios::in);

PATIENTRECORD P;

int found=0;

while(!found && fil1.read((char*)&P,sizeof(P)))

if (P.RPatientID()==patientid)

found++;





 
if(!found)

cout<<"PATIENT ID DOES NOT EXIST! "<<endl; else CheckPatientPass(patientid, notif, A); fil1.close();
}

else if(opt==2)

{

DoctorHeader();

cout<<"Enter Name: ";

gets(dname);

fstream fil1;

fil1.open("Hospital.dat", ios::binary|ios::in);

PATIENTRECORD P;

int found=0;

while(!found && fil1.read((char*)&P,sizeof(P)))

if (strcmpi(P.RDoctor(),dname)==0)

found++;

if(!found)

{

cout<<"DOCTOR NAME DOESN'T EXIST IN THE RECORDS!"<<endl; getch();
}

else

CheckPass(2, notif, prev, A, dname); fil1.close();
}

else if(opt==3)

{

AdminHeader();

CheckPass(3, notif ,prev, A);

}

} while(opt!=4); getch();

}

void Line(char ch,int n)

{

for(int i=1; i<=n; i++)

cout<<ch;

}

void PatientHeader()

{

clrscr();

Line('#',80);





 
cout<<endl;

Line(' ',32);

cout<<"PATIENT PROFILE\n";

cout<<endl;

Line('#',80);

}

void DoctorHeader()

{

clrscr();

Line('#',80);

cout<<endl;

Line(' ',33);

cout<<"DOCTOR PROFILE\n";

cout<<endl;

Line('#',80);

}

void AdminHeader()

{

clrscr();

Line('#',80);

cout<<endl;

Line(' ',33);

cout<<"ADMIN PROFILE\n";

cout<<endl;

Line('#',80);

}

void GeneratePatientPass(int patientid, int yob)

{

{

fstream fil;

fil.open("temp1.txt", ios::out);

fil<<patientid;

fil.close();

}

char patientidnum[10];

{

fstream fil1;

fil1.open("temp1.txt", ios::in);

while(!fil1.eof())

fil1>>patientidnum;

fil1.close();

}





 
{

char filename[100]="p";

char suf[10]=".txt";

strcat(filename,patientidnum);

strcat(filename,suf);

fstream fil;

fil.open(filename, ios::out);

fil<<"pat"<<patientid<<yob;

fil.close();

}

}

void GenerateDoctorPass(char dname[])

{

char filename[100]="d";

char subname[10];

char suf[10]=".txt";

for(int i=0; i<=4; i++)

{

if(dname[i]!=' ')

subname[i]=dname[i];

else subname[i]='_';

}

subname[5]='\0';

strcat(filename,subname);

strcat(filename,suf);

fstream fil;

fil.open(filename, ios::out);

strlwr(dname);

fil<<"doc";

for(int p=0; p<strlen(dname);p++)

if(dname[p]!=' ')

fil<<dname[p];

fil.close();

}


void GenerateAdminPass(char pass[])

{

fstream fil;

fil.open("AdminPass.txt", ios::out);

fil<<pass;

fil.close();

}






 
void CheckPatientPass(int patientid, int &notif, APPOINTMENT A[]) {

char ch, pass[40];

int i=0;

cout<<"Password: ";

do

{

ch=getch();

cout<<"*";

pass[i++]=ch;

} while(ch!=13); cout<<endl; pass[i-1]='\0';

{

fstream fil; fil.open("temp1.txt", ios::out); fil<<patientid;
fil.close();

}

char patientidnum[10];

{

fstream fil1; fil1.open("temp1.txt", ios::in); while(!fil1.eof()) fil1>>patientidnum; fil1.close();
}

char filename[100]="p"; char suf[10]=".txt"; strcat(filename,patientidnum); strcat(filename,suf); fstream fil; fil.open(filename, ios::in); char pass1[40];

fil>>pass1;

if(strcmp(pass,pass1)==0)

PatientMenu(patientid,notif,A); else
cout<<"WRONG PASSWORD!"<<endl; fil.close();
getch();

}

void CheckPass(int opt, int &notif, int &prev, APPOINTMENT A[], char dname[])





 
{

char ch, pass[40];

int i=0;

cout<<"Password: ";

do

{

ch=getch();

cout<<"*";

pass[i++]=ch;

} while(ch!=13); pass[i-1]='\0'; if(opt==2)

{

char filename[100]="d"; char subname[10]; char suf[10]=".txt"; for(int i=0; i<=4; i++)
{

if(dname[i]!=' ') subname[i]=dname[i]; else subname[i]='_';

}

subname[5]='\0';

strcat(filename,subname);

strcat(filename,suf); fstream fil; fil.open(filename, ios::in); char pass1[40]; fil.getline(pass1,40); if(strcmp(pass,pass1)==0) DoctorMenu(dname, notif, A); else
{

cout<<"\nWRONG PASSWORD!"<<endl; fil.close();
}

}

else if(opt==3)

{

fstream fil ("AdminPass.txt", ios::in); char pass1[40];
fil>>pass1;

if(strcmp(pass,pass1)==0) AdminMenu(notif, prev, A); else



 
cout<<"\nWRONG PASSWORD!"<<endl;

fil.close();

}

getch();

}

void PatientMenu(int patientid, int &notif, APPOINTMENT A[]) {

PatientHeader();

int opt=0, found=0;

PATIENTRECORD P;

fstream fil;

fil.open("Hospital.dat", ios::binary|ios::in); while(found==0 && fil.read((char*)&P, sizeof(P))) {
if(P.RPatientID()==patientid)

found++;

}

if(found==0)

opt=4;

if(opt!=4)

{

do

{

PatientHeader();

cout<<"\nPlease  select  the  option:  \n1.  Alert  Section  \n2.  View

Your  Profile  \n3.  Request  New  Appointment  \n4.  Change  Password  \n5.

Exit"<<endl;

cin>>opt;

if(opt==1)

{

PatientHeader();

{

if(P.RDay()!=0)

cout<<"You have an upcoming appointment on "<<P.RDay()<<"/"<<P.RMonth()<<"/"<<P.RYear()<<endl;
else

cout<<"NO UPCOMING APPONINMENTS"<<endl; getch();
}

}

if(opt==2)

{

PatientHeader();

P.Output();





 
}

else if(opt==3)

{

PatientHeader();

cout<<"Please Enter The Date For Which You Want The Appointment:

";

cin>>A[notif].appdate.day>>A[notif].appdate.month>>A[notif].appdate.ye ar;

A[notif].adminforward=0;

A[notif].patientid=patientid;

strcpy(A[notif].Name,P.RName());

strcpy(A[notif].Doctor,P.RDoctor());

notif++;

{

cout<<"\nThank You For Sending The Request, Please Check The Alert Section For Updates."<<endl;
getch();

}

}

else if(opt==4)

{

PatientHeader();

{

fstream fil;

fil.open("temp1.txt", ios::out);

fil<<patientid;

fil.close();

}

char patientidnum[10];

{

fstream fil1;

fil1.open("temp1.txt", ios::in);

while(!fil1.eof())

fil1>>patientidnum;

fil1.close();

}

{

char filename[100]="p";

char suf[10]=".txt";

strcat(filename,patientidnum);

strcat(filename,suf);

ChangePassword(filename);

}

}




 
} while(opt!=5);

}

}

void DoctorMenu(char dname[], int &notif, APPOINTMENT A[]) {

DoctorHeader();

int opt;

do

{

DoctorHeader();

cout<<"\nPlease select the option: \n1. Check Appointment Requests \n2. Show Patients For A Particular Date \n3. Show Collection For A Particular Date\n4. Edit Patient Record \n5. Change Password \n6. Exit"<<endl;
cin>>opt;

if(opt==1)

{

DoctorHeader();

DoctorNotif(dname, notif, A);

}

if(opt==2)

{

DoctorHeader();

SearchDoctorDate(dname);

}

else if(opt==3)

{

DoctorHeader();

CalculateCollection(dname);

}

else if(opt==4)

{

DoctorHeader();

DoctorEdit();

}

else if(opt==5)

{

DoctorHeader();

{

char filename[100]="d";

char subname[10];

char suf[10]=".txt";

for(int i=0; i<=4; i++)

{






 
if(dname[i]!=' ')

subname[i]=dname[i];

else subname[i]='_';

}

subname[5]='\0';

strcat(filename,subname);

strcat(filename,suf);

ChangePassword(filename);

}

}

} while(opt!=6);

}

void AdminMenu(int &notif, int &prev, APPOINTMENT A[])

{

int opt;

do

{

AdminHeader();

cout<<"\nPlease select the option: \n1. Check Appointment Requests \n2. View All Patient Records \n3. Add New Patient Record \n4. Edit Patient Record"<<endl;
cout<<"5. Remove Patient Record \n6. Search & View Patient Record \n7. Change Password \n8. Exit"<<endl;
cin>>opt;

if(opt==1)

{

AdminHeader();

AdminNotif(notif, A);

}

else if(opt==2)

{

AdminHeader();

VIEW();

}

else if(opt==3)

{

AdminHeader();

ADD(prev);

}

else if(opt==4)

{

AdminHeader();

EDIT();

}




 
else if(opt==5)

{

AdminHeader();

REMOVE();

}

else if(opt==6)

{

AdminHeader();

char dname[40];

int opt1;

cout<<"\n1. By Patient ID \n2. By Doctor & Date"<<endl;

cin>>opt1;

if(opt1==1)

SearchPatientID();

else if(opt1==2)

{

cout<<"Enter Doctor's Name: ";

gets(dname);

SearchDoctorDate(dname);

}

}

else if(opt==7)

{

AdminHeader();

ChangePassword("AdminPass.txt");

}

} while(opt!=8);

}

void DoctorNotif(char dname[40], int &notif, APPOINTMENT A[]) {

int flag=0;

if(notif==0)

cout<<"NO NEW APPOINTMENT REQUESTS"<<endl;

else

{

for(int j=1, i=notif-1; i>=0; i--, j++)

{

if (A[notif-1].adminforward==1 && (strcmpi(A[notif-1].Doctor,dname)==0))
{

flag++;

int opt;








 
cout<<j<<". "<<A[i].Name<<" would like an appoinment with you on "<<A[i].appdate.day<<"/"<<A[i].appdate.month<<"/"<<A[i].appdate.year<< endl;

cout<<"\nPlease select the option: "<<endl;

cout<<"1. Confirm Request \n2. Reject Request"<<endl;

cin>>opt;

if(opt==1)

{

cout<<"REQUEST CONFIRMED!"<<endl;

fstream fil;

fil.open("Hospital.dat",ios::binary|ios::in|ios::out);

PATIENTRECORD P;

while(fil.read((char*)&P, sizeof(P)))

{

if(P.RPatientID()==A[i].patientid)

P.Appointment(A[i].appdate);

fil.seekg(fil.tellg()-sizeof(P));

fil.write((char*)&P,sizeof(P));

}

fil.close();

}

else if(opt==2)

cout<<"REQUEST REJECTED!"<<endl;

ShiftNotif(i,notif,A);

notif--;

}

}

if(flag==0)

cout<<"NO NEW APPOINTMENT REQUESTS\n"; else
cout<<"END OF APPOINTMENT REQUESTS\n";

}

getch();

}

void AdminNotif(int &notif, APPOINTMENT A[])

{

if(notif==0)

cout<<"NO NEW APPOINTMENT REQUESTS"<<endl;

else

{

for(int j=1, i=notif-1; i>=0; i--, j++)

{

if(A[i].adminforward!=1)

{






 
int opt;

cout<<j<<".	"<<A[i].Name<<"	would	like	an	appoinment	with

"<<A[i].Doctor<<" on "<<A[i].appdate.day<<"/"<<A[i].appdate.month<<"/"<<A[i].appdate.year<< endl;
cout<<"\nPlease select the option: "<<endl;

cout<<"1. Confirm Request \n2. Forward to Doctor \n3. Reject Request"<<endl;
cin>>opt;

if(opt==1)

{

cout<<"REQUEST ACCEPTED!"<<endl;

fstream fil;

fil.open("Hospital.dat",ios::binary|ios::in|ios::out);

PATIENTRECORD P;

while(fil.read((char*)&P, sizeof(P)))

{

if(P.RPatientID()==A[i].patientid)

P.Appointment(A[i].appdate);

fil.seekg(fil.tellg()-sizeof(P));

fil.write((char*)&P,sizeof(P));

}

ShiftNotif(i, notif,A);

notif--;

fil.close();

}

else if(opt==2)

{

cout<<"REQUEST FORWARDED FOR APPROVAL!"<<endl; A[notif-1].adminforward=1;
}

else if(opt==3)

{

cout<<"REQUEST REJECTED!"<<endl;

ShiftNotif(i,notif,A);

notif--;

}

}

else cout<<"NO NEW APPOINTMENT REQUESTS!";

}

}

getch();

}

void ShiftNotif(int i, int &notif, APPOINTMENT A[])






 
{

for(int j=i+1; j<notif; j++)

A[j-1]=A[j];

}

void DoctorEdit()

{

fstream fil1;

fil1.open("Hospital.dat",ios::binary|ios::in|ios::out);

PATIENTRECORD P;

int found=0, Pno;

cout<<"Enter Patient ID whose details are to be edited : "; cin>>Pno;
while(!found && fil1.read((char*)&P,sizeof(P)))

{

if(P.RPatientID()==Pno)

{

found++;

P.InputD();

fil1.seekg(fil1.tellg()-sizeof(P));

fil1.write((char*)&P,sizeof(P));

cout<<"PATIENT RECORD UPDATED!";

}

}

if(!found)

cout<<"PATIENT ID DOES NOT EXIST!"<<endl;

fil1.close();

getch();

}

void SearchDoctorDate(char dname[])

{

fstream fil1;

fil1.open("Hospital.dat",ios::binary|ios::in);

PATIENTRECORD P;

int found=0;

char doctor1[40];

int day1,month1,year1;

cout<<"Date : ";

cin>>day1>>month1>>year1;

cout<<"\nTHE FOLLWING ARE THE APPOINTMENTS: "<<endl; while(fil1.read((char*)&P,sizeof(P))) {

if (strcmpi(P.RDoctor(),dname)==0 && P.RDay()==day1 && P.RMonth()==month1 && P.RYear()==year1)





 
{

P.Output();

cout<<endl;

found++;

}

}

if(!found)

cout<<"NO APPOINTMENTS FOR THE GIVEN DATE!"<<endl;

fil1.close();

getch();

}

void CalculateCollection(char dname[])

{

fstream fil1;

fil1.open("Hospital.dat",ios::binary|ios::in);

PATIENTRECORD P;

int found=0;

int day1,month1,year1;

cout<<"Date : ";

cin>>day1>>month1>>year1;

while(fil1.read((char*)&P,sizeof(P)))

{

if (strcmpi(P.RDoctor(),dname)==0 && P.RDay()==day1 && P.RMonth()==month1 && P.RYear()==year1)
found++;

}

cout<<"Estimated collection for the day: Rs. "<<found*750<<endl;

fil1.close();

getch();

}

void SearchPatientID()

{

fstream fil1;

fil1.open("Hospital.dat",ios::binary|ios::in);

PATIENTRECORD P;

int found=0, Pno;

cout<<"Enter Patient ID : ";

cin>>Pno;

while(!found && fil1.read((char*)&P,sizeof(P)))

{

if(P.RPatientID()==Pno)

{

P.Output();






 
found++;

}

}

if(!found)

cout<<"PATIENT ID DOES NOT EXIST!"<<endl;

fil1.close();

getch();

}

void ADD(int &prev)

{

fstream fil1,fil2;

fil1.open("Hospital.dat",ios::binary|ios::in);

fil2.open("Temp.dat",ios::binary|ios::out);

PATIENTRECORD P,Pnew;

cout<<"Enter the details of the new patient: "<<endl; Pnew.Generatepatientid(prev); prev++;

Pnew.Input();

int insert=0;

while(fil1.read((char*)&P,sizeof(P)))

{

if(!insert && P.RPatientID()>Pnew.RPatientID())

{

fil2.write((char*)&Pnew,sizeof(P));

insert++;

}

fil2.write((char*)&P,sizeof(P));

}

if(!insert)

fil2.write((char*)&Pnew,sizeof(P));

cout<<"RECORD SUCCESSFULLY ADDED!"<<endl;

GeneratePatientPass(Pnew.RPatientID(), Pnew.RYob());

int found=0;

PATIENTRECORD A;

while(found==0 && fil1.read((char*)&A, sizeof(A)))

{

if(strcmpi(A.RDoctor(),Pnew.RDoctor())==0)

found++;

}

if(found==0)

GenerateDoctorPass(Pnew.RDoctor());

fil1.close();

fil2.close();

remove("Hospital.dat");






 
rename("Temp.dat","Hospital.dat");

getch();

}

void EDIT()

{

int opt,patientid, found=0;

fstream fil;

fil.open("Hospital.dat", ios::in|ios::binary|ios::out);

cout<<"Enter the Patient's ID whose details are to be edited: ";

cin>>patientid;

PATIENTRECORD P,Q;

while(!found && fil.read((char*)&P,sizeof(P)))

{

if (P.RPatientID()==patientid)

found++;

}

if(!found)

cout<<"PATIENT ID DOES NOT EXIST!"<<endl;

else

{

char newdoc[40];

cout<<"Please select what you want to edit: "<<endl;

cout<<"\n1. Change Assigned Doctor \n2. Change Date of Next Visit"<<endl;
cin>>opt;

if(opt==1)

{

cout<<"Please enter the new doctor's name: ";

gets(newdoc);

P.EditDoctor(newdoc);

}

else if(opt==2)

P.EditNxtVisit();

cout<<"RECORD SUCCESSFULLY EDITED!"<<endl;

fil.seekg(fil.tellg()-sizeof(P));

fil.write((char*)&P,sizeof(P));

if(opt==1)

{

int fnd=0;

fil.seekg(0);

while(fnd==0 && fil.read((char*)&Q, sizeof(Q)))

{

if(strcmpi(Q.RDoctor(),newdoc)==0 && P.RPatientID()!=Q.RPatientID())




 
fnd++;

}

if(fnd==0)

GenerateDoctorPass(newdoc);

}

}

fil.close();

getch();

}

void VIEW()

{

fstream fil;

fil.open("Hospital.dat",ios::binary|ios::in);

PATIENTRECORD P;

while(fil.read((char*)&P,sizeof(P)))

P.Output();

fil.close();

getch();

}

void REMOVE()

{

fstream fil1,fil2;

PATIENTRECORD P;

fil1.open("Hospital.dat",ios::binary|ios::in);

fil2.open("Temp.dat",ios::binary|ios::out);

int del=0;

int Num;

cout<<"Enter the patient ID be deleted: ";

cin>>Num;

while(fil1.read((char*)&P,sizeof(P)))

if(P.RPatientID()!=Num)

fil2.write((char*)&P,sizeof(P));

else

del++;

fil1.close();

fil2.close();

if(del)

{

cout<<"RECORD DELETION SUCCESSFUL!"<<endl; remove("Hospital.dat"); rename("Temp.dat","Hospital.dat");

}

else






 
cout<<"Record not found\n";

getch();

}

void ChangePassword(char filename[])

{

cout<<"ENTER OLD PASSWORD:";

int ch2;

char pass2[40];

int j=0;

do

{

ch2=getch();

cout<<'*';

pass2[j++]=ch2;

} while(ch2!=13); pass2[j-1]='\0'; fstream file; file.open(filename, ios::in); char pass1[40]; file>>pass1; if(strcmp(pass2,pass1)==0)

{

cout<<"\n"<<"Enter New password:"; int ch;
char pass[40]; int i=0;
do

{

ch=getch();

cout<<'*';

pass[i++]=ch;

}while(ch!=13); pass[i-1]='\0'; file.close(); fstream file; file.open(filename, ios::out); file<<pass<<endl;

cout<<"\nPASSWORD SUCCESSFULLY CHANGED!\n";

}

else cout<<"\n"<<"WRONG PASSWORD!\n"; file.close();
getch();

}
