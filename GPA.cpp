#include<iostream>
#include<fstream>
#include <windows.h>
#include<conio.h>

using namespace std;

int check_100(int x,int y,int z);// to check 0-100 values
int grade_name_f(int y); //A+,A,B,B+ ++++ Adding a grade name
string reg_number; // store registration number
string reg_name;   //store student name
int attempts=0;     //control both user name attempt and password attempts
char next_student;

//string subject_name[32];
int subject_score[32];    //store subject marks
int assignment_score[32]; //store assignment marks
int credits[32];          //store credit values for each subject
float all_score[32];      //total score  [(exam marks/2)+(assignment marks/2)]  ....  100%
string grade_name[32];     //GPA grade name  Ex --> A+,B+.....
float several_gpa[32];      //store GPA points(values)
float semester_GPA[5];      //store Average semester GPA after calculation
char password[15];  //PASSWORD

string subject_name[]={"MTH 311 Advanced Algebra","SDV 210 Business Entrepreneurship","MEC 311 Engineer in Society","EEC 315 Electrical Material Science","EEI 311 Electrical Measurement and Control III","EEC 313 Electric Circuit Theory III","ICT 302 Computer Packages","EEE 314 Analogue Electronics III","MTH 312 Advanced Calculus","GNS 413 Industrial Management","EEC 324 Testing Method and Reliability","EEC 325 Electrical Circuit Theory IV","EEP 328 Electrical Design and Drawing I","EEE 325 Digital Communication I","EEP 326 Electric Power Systems III","EEP 327 Electric Machines III","ICT 321 Data Communication and Networking","EEI 435 Instrumentation Design and Drafting","EEI 437 Pneumatic Instrumentation","EEC 431 Electromagnetic Field Theory","MTH 321 Numerical Methods","EEE 435 Digital Communication II","EEE 434 Analogue Electronics IV","EEC 433 Control Engineering","EEI 431 Electrical Measurement and Control IV","EEC 437 Project","EEI 442 Electronic Instrumentation","EEI 444 Process Measurement","EEI 446 Instruments Maintenance and Repairs","MTH 313 Statistical Methods","ICT 301 Introduction to Computer Programming (C++)" ,"EEC 447 Project"};

string select_Type;

int main(){
   string user_name; //TO CONTROL THE LOOP
  // string password;   //TO CONTROL THE LOOP
   string Semster_number; //semester number input
   int ss;


    cout<<"---------------------- W E L C O M E ---------------------------"<<endl<<endl;
    cout<<"                    ****  ****     *      "<<endl;
    cout<<"                   *      *   *   * *     "<<endl;
    cout<<"                   * ***  ****   *****    "<<endl;
    cout<<"                    ** *  *     *     *   "<<endl;
   // cout<<"----------------------------------------------------------------"<<endl;

   // cout<<"   ***     *    *     *** *   * *       *    *****  ***  ****      \n";
    //cout<<"  *       * *   *    *    *   * *      * *     *   *   * *   *     \n";
    //cout<<"  *      *****  *    *    *   * *     *****    *   *   * ****      \n";
    //cout<<"   ***  *     * ****  ***  ***  **** *     *   *    ***  *  **     \n";

    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"--- C A L C U L A T E    Y O U R   S E M E S T E R    G P A ----"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl<<endl;



do{
        next_student=0;
    do{

        cout<<"Login as (admin / student)  "<<"\t\t"<<":  ";
        cin>>user_name;
        cout<<endl;

    if(user_name=="admin"){
        attempts=0;



    do{
            //char password[10]={};
        cout<<"Enter admin pasword                  \t:  ";





            for(int i=0; i<10;i++){
        password[i]=getch();
        cout<<"*";

        if(password[i]=='\r') //check if enter key is pressed
            break;

        else if(password[i]=='\b'){   //check if escape key is pressed

            if(i==0)
                cout<<"\b"<<" "<<"\b";
            else if(i>=1){
                password[i-1]='\0';//make the previous byte null if backspase is pressed
                i=i-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
            }

         }
    }



    if(password[0]=='1' && password[1]=='2' && password[2]=='3'){
            do{----------------------------------------------------------------
                next_student=0;

        system("CLS");
        cout<<"Logged In User : Admin"<<endl;
        cout<<"----------------------------------------------------------------"<<endl<<endl;
        cout<<"\nEnter Student Registration Number  [ EXAMPLE: kur-it-2017-f-0097 ] : ";
        cin>>reg_number;
        cout<<"\n\nEnter Student Name with Initials  [ EXAMPLE: O.S.P.Silva ]        : ";
        cin>>reg_name;
do{
        system("CLS");

        cout<<"\n1 : 1ST SEMESTER GPA"<<endl;
        cout<<"2 : 2ND SEMESTER GPA"<<endl;
        cout<<"3 : 3RD SEMESTER GPA"<<endl;
        cout<<"4 : 4TH SEMESTER GPA"<<endl<<endl;

        cout<<"Enter your option : ";



        cin>>Semster_number;

    if(Semster_number=="1"){

            system("CLS");
            cout<<"\n-------------------------> ! IMPORTANT ! <----------------------------"<<endl;

            cout<<"\n* IF ABSENT WITHOUT VALID REASON FOR EXAM -------------- ENTER (-1) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITHOUT VALID REASON --- ENTER (-1) * "<<endl;
            cout<<"* IF ABSENT WITH VALID REASON FOR EXAM ----------------- ENTER (-2) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITH VALID REASON ------ ENTER (-2) * \n"<<endl;

            cout<<"------------------------- ENTER YOUR MARKS ---------------------------"<<endl;
            cout<<"----------------------------------------------------------------------"<<endl<<endl;

    for(int x=0;x<8;x++){
        do{
            cout<<"Enter Exam Marks for "<<subject_name[x]<<"  : ";
            cin>>subject_score[x];

            cout<<"Enter Assignment Marks  : ";
            cin>>assignment_score[x];
            cout<<endl;

            ss =check_100(subject_score[x],assignment_score[x],x);   //ss variable for do while

            if(ss==1){
                all_score[x]=(subject_score[x]/2)+(assignment_score[x]/2);


                grade_name_f(x);

            }else{
                ss==0;
                cout<<"Invalid input.! "<<endl<<endl;

            }
        }while(ss==0);

    }
    cout<<"EXAM\t"<<"ASSIGNMENT"<<endl<<endl;
    cout<<"------------------"<<endl<<endl;
for(int x=0;x<8;x++){

    cout<<" "<<subject_score[x]<<"\t   "<<assignment_score[x]<<endl<<endl;

     if(assignment_score[x]==-1 && subject_score[x]>=30){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="INC";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-2){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]>=30){
        grade_name[x]="DFR)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
         grade_name[x]="I(SE)";
        several_gpa[x]=0;

   }else if(subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }

}
        semester_GPA[0]=0;

        for(int x=0;x<8;x++){

            semester_GPA[0] = (several_gpa[x]*3)+semester_GPA[0];
            semester_GPA[0]+several_gpa[x];
        }
            semester_GPA[0]=semester_GPA[0]/24;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            cout<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            reg_number+= ".txt";
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"                        SEMESTER 01 - EXAM RESULTS  "<<endl<<endl;

            cout<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<subject_name[0]<<"\t\t\t\t"<<several_gpa[0]<<"\t-- "<<grade_name[0]<<endl<<endl;
            cout<<subject_name[1]<<"\t\t\t"<<several_gpa[1]<<"\t-- "<<grade_name[1]<<endl<<endl;
            cout<<subject_name[2]<<"\t\t\t\t"<<several_gpa[2]<<"\t-- "<<grade_name[2]<<endl<<endl;
            cout<<subject_name[3]<<"\t\t\t"<<several_gpa[3]<<"\t-- "<<grade_name[3]<<endl<<endl;
            cout<<subject_name[4]<<"\t\t"<<several_gpa[4]<<"\t-- "<<grade_name[4]<<endl<<endl;
            cout<<subject_name[5]<<"\t\t\t"<<several_gpa[5]<<"\t-- "<<grade_name[5]<<endl<<endl;
            cout<<subject_name[6]<<"\t\t\t\t"<<several_gpa[6]<<"\t-- "<<grade_name[6]<<endl<<endl;
            cout<<subject_name[7]<<"\t\t\t"<<several_gpa[7]<<"\t-- "<<grade_name[7]<<endl<<endl;

            cout<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[0]<<endl<<endl;
























        ofstream myfile;


            myfile.open(reg_number.c_str(), ios::app);
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            myfile<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;

            myfile<<"                        SEMESTER 01 - EXAM RESULTS  "<<endl<<endl;

            myfile<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<subject_name[0]<<"\t\t\t\t"<<several_gpa[0]<<"\t-- "<<grade_name[0]<<endl<<endl;
            myfile<<subject_name[1]<<"\t\t\t"<<several_gpa[1]<<"\t-- "<<grade_name[1]<<endl<<endl;
            myfile<<subject_name[3]<<"\t\t\t"<<several_gpa[3]<<"\t-- "<<grade_name[3]<<endl<<endl;
            myfile<<subject_name[4]<<"\t\t"<<several_gpa[4]<<"\t-- "<<grade_name[4]<<endl<<endl;
            myfile<<subject_name[5]<<"\t\t\t"<<several_gpa[5]<<"\t-- "<<grade_name[5]<<endl<<endl;
            myfile<<subject_name[6]<<"\t\t\t\t"<<several_gpa[6]<<"\t-- "<<grade_name[6]<<endl<<endl;
            myfile<<subject_name[7]<<"\t\t\t"<<several_gpa[7]<<"\t-- "<<grade_name[7]<<endl<<endl;

            myfile<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[0]<<endl<<endl;



    }else if(Semster_number=="2"){

            system("CLS");
            cout<<"\n---------------------> ! IMPORTANT ! <------------------------"<<endl;

            cout<<"\n* IF ABSENT WITHOUT VALID REASON FOR EXAM ------------- (-1) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITHOUT VALID REASON -- (-1) * "<<endl;
            cout<<"* IF ABSENT WITH VALID REASON FOR EXAM ---------------- (-2) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITH VALID REASON ----- (-2) * \n"<<endl;

            cout<<"--------------------- ENTER YOUR MARKS ------------------------"<<endl;
            cout<<"---------------------------------------------------------------"<<endl<<endl;

    for(int x=8;x<17;x++){
         do{
            cout<<"Enter Exam Marks for "<<subject_name[x]<<"  : ";
            cin>>subject_score[x];

            cout<<"Enter Assignment Marks  : ";
            cin>>assignment_score[x];
            cout<<endl;

            ss =check_100(subject_score[x],assignment_score[x],x);   //ss variable for do while

            if(ss==1){
                all_score[x]=(subject_score[x]/2)+(assignment_score[x]/2);


                grade_name_f(x);

            }else{
                ss==0;
                cout<<"Invalid input.! "<<endl<<endl;

            }
        }while(ss==0);
    }
        cout<<"EXAM\t"<<"ASSIGNMENT"<<endl<<endl;
        cout<<"------------------"<<endl<<endl;

for(int x=8;x<17;x++){

        cout<<" "<<subject_score[x]<<"\t   "<<assignment_score[x]<<endl<<endl;

     if(assignment_score[x]==-1 && subject_score[x]>=30){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="INC";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-2){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]>=30){
        grade_name[x]="DFR)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
         grade_name[x]="I(SE)";
        several_gpa[x]=0;

   }else if(subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }
    }
         semester_GPA[1]=0;
        for(int x=8;x<17;x++){

            semester_GPA[1] = (several_gpa[x]*3)+semester_GPA[1];
            semester_GPA[1]+several_gpa[x];
        }
            semester_GPA[1]=semester_GPA[1]/27;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            cout<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            reg_number+= ".txt";
            cout<<"-----------------------------------------------------------------------------"<<endl;

            cout<<"                        SEMESTER 02 - EXAM RESULTS  "<<endl<<endl;

            cout<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<subject_name[8] <<"\t\t\t\t"<<several_gpa[8] <<"    -- "<<grade_name[8]<<endl<<endl;
            cout<<subject_name[9] <<"\t\t\t\t"<<several_gpa[9] <<"    -- "<<grade_name[9]<<endl<<endl;
            cout<<subject_name[10]<<"\t\t\t"<<several_gpa[10]<<"    -- "<<grade_name[10]<<endl<<endl;
            cout<<subject_name[11]<<"\t\t\t"<<several_gpa[11]<<"    -- "<<grade_name[11]<<endl<<endl;
            cout<<subject_name[12]<<"\t\t\t"<<several_gpa[12]<<"    -- "<<grade_name[12]<<endl<<endl;
            cout<<subject_name[13]<<"\t\t\t\t"<<several_gpa[13]<<"    -- "<<grade_name[13]<<endl<<endl;
            cout<<subject_name[14]<<"\t\t\t"<<several_gpa[14]<<"    -- "<<grade_name[14]<<endl<<endl;
            cout<<subject_name[15]<<"\t\t\t\t"<<several_gpa[15]<<"    -- "<<grade_name[15]<<endl<<endl;
            cout<<subject_name[16]<<"\t\t"<<several_gpa[16]<<"    -- "<<grade_name[16]<<endl<<endl;

            cout<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[1]<<endl<<endl;

            ofstream myfile;

            myfile.open(reg_number.c_str(), ios::app);
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            myfile<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;

            myfile<<"                        SEMESTER 02 - EXAM RESULTS  "<<endl<<endl;


            myfile<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<subject_name[8] <<"\t\t\t\t"<<several_gpa[8] <<"    -- "<<grade_name[8]<<endl<<endl;
            myfile<<subject_name[9] <<"\t\t\t\t"<<several_gpa[9] <<"    -- "<<grade_name[9]<<endl<<endl;
            myfile<<subject_name[10]<<"\t\t\t"<<several_gpa[10]<<"    -- "<<grade_name[10]<<endl<<endl;
            myfile<<subject_name[11]<<"\t\t\t"<<several_gpa[11]<<"    -- "<<grade_name[11]<<endl<<endl;
            myfile<<subject_name[12]<<"\t\t\t"<<several_gpa[12]<<"    -- "<<grade_name[12]<<endl<<endl;
            myfile<<subject_name[13]<<"\t\t\t\t"<<several_gpa[13]<<"    -- "<<grade_name[13]<<endl<<endl;
            myfile<<subject_name[14]<<"\t\t\t"<<several_gpa[14]<<"    -- "<<grade_name[14]<<endl<<endl;
            myfile<<subject_name[15]<<"\t\t\t\t"<<several_gpa[15]<<"    -- "<<grade_name[15]<<endl<<endl;
            myfile<<subject_name[16]<<"\t\t"<<several_gpa[16]<<"    -- "<<grade_name[16]<<endl<<endl;

            myfile<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[1]<<endl<<endl;

    }else if(Semster_number=="3"){

            system("CLS");
            cout<<"\n---------------------> ! IMPORTANT ! <------------------------"<<endl;

            cout<<"\n* IF ABSENT WITHOUT VALID REASON FOR EXAM ------------- (-1) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITHOUT VALID REASON -- (-1) * "<<endl;
            cout<<"* IF ABSENT WITH VALID REASON FOR EXAM ---------------- (-2) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITH VALID REASON ----- (-2) * \n"<<endl;

            cout<<"--------------------- ENTER YOUR MARKS ------------------------"<<endl;
            cout<<"---------------------------------------------------------------"<<endl<<endl;

    for(int x=17;x<26;x++){
         do{
            cout<<"Enter Exam Marks for "<<subject_name[x]<<"  : ";
            cin>>subject_score[x];

            cout<<"Enter Assignment Marks  : ";
            cin>>assignment_score[x];
            cout<<endl;

            ss =check_100(subject_score[x],assignment_score[x],x);   //ss variable for do while

            if(ss==1){
                all_score[x]=(subject_score[x]/2)+(assignment_score[x]/2);


                grade_name_f(x);

            }else{
                ss==0;
                cout<<"Invalid input.! "<<endl<<endl;

            }
        }while(ss==0);
    }
        cout<<"EXAM\t"<<"ASSIGNMENT"<<endl<<endl;
        cout<<"------------------"<<endl<<endl;
for(int x=17;x<26;x++){

        cout<<" "<<subject_score[x]<<"\t   "<<assignment_score[x]<<endl<<endl;

     if(assignment_score[x]==-1 && subject_score[x]>=30){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="INC";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-2){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]>=30){
        grade_name[x]="DFR)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
         grade_name[x]="I(SE)";
        several_gpa[x]=0;

   }else if(subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }
}

            semester_GPA[2]=0;
        for(int x=17;x<26;x++){

            semester_GPA[2] = (several_gpa[x]*3)+semester_GPA[2];
            semester_GPA[2]+several_gpa[x];
        }
            semester_GPA[2]=semester_GPA[2]/27;

            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            cout<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            reg_number+= ".txt";
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<"                        SEMESTER 03 - EXAM RESULTS                     "<<endl<<endl;


            cout<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            cout<<"-----------------------------------------------------------------------------"<<endl;
            cout<<subject_name[17]<<"\t\t"<<several_gpa[17]<<"\t-- "<<grade_name[17]<<endl<<endl;
            cout<<subject_name[18]<<"\t\t\t"<<several_gpa[18]<<"\t-- "<<grade_name[18]<<endl<<endl;
            cout<<subject_name[19]<<"\t\t\t"<<several_gpa[19]<<"\t-- "<<grade_name[19]<<endl<<endl;
            cout<<subject_name[20]<<"\t\t\t\t"<<several_gpa[20]<<"\t-- "<<grade_name[20]<<endl<<endl;
            cout<<subject_name[21]<<"\t\t\t"<<several_gpa[21]<<"\t-- "<<grade_name[21]<<endl<<endl;
            cout<<subject_name[22]<<"\t\t\t\t"<<several_gpa[22]<<"\t-- "<<grade_name[22]<<endl<<endl;
            cout<<subject_name[23]<<"\t\t\t\t"<<several_gpa[23]<<"\t-- "<<grade_name[23]<<endl<<endl;
            cout<<subject_name[24]<<"\t\t"<<several_gpa[24]<<"\t-- "<<grade_name[24]<<endl<<endl;
            cout<<subject_name[25]<<"\t\t\t\t\t\t"<<several_gpa[25]<<"\t-- "<<grade_name[25]<<endl<<endl;

            cout<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[2]<<endl<<endl;

            ofstream myfile;

            myfile.open(reg_number.c_str(), ios::app);
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<"REGISTRATION NUMBER : "<<reg_number<<endl;
            myfile<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;

            myfile<<"                        SEMESTER 03 - EXAM RESULTS  "<<endl<<endl;


            myfile<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
            myfile<<"-----------------------------------------------------------------------------"<<endl;
            myfile<<subject_name[17]<<"\t\t"<<several_gpa[17]<<"\t-- "<<grade_name[17]<<endl<<endl;
            myfile<<subject_name[18]<<"\t\t\t"<<several_gpa[18]<<"\t-- "<<grade_name[18]<<endl<<endl;
            myfile<<subject_name[19]<<"\t\t\t"<<several_gpa[19]<<"\t-- "<<grade_name[19]<<endl<<endl;
            myfile<<subject_name[20]<<"\t\t\t\t"<<several_gpa[20]<<"\t-- "<<grade_name[20]<<endl<<endl;
            myfile<<subject_name[21]<<"\t\t\t"<<several_gpa[21]<<"\t-- "<<grade_name[21]<<endl<<endl;
            myfile<<subject_name[22]<<"\t\t\t\t"<<several_gpa[22]<<"\t-- "<<grade_name[22]<<endl<<endl;
            myfile<<subject_name[23]<<"\t\t\t\t"<<several_gpa[23]<<"\t-- "<<grade_name[23]<<endl<<endl;
            myfile<<subject_name[24]<<"\t\t"<<several_gpa[24]<<"\t-- "<<grade_name[24]<<endl<<endl;
            myfile<<subject_name[25]<<"\t\t\t\t\t\t"<<several_gpa[25]<<"\t-- "<<grade_name[25]<<endl<<endl;

            myfile<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<semester_GPA[2]<<endl<<endl;

    }else if(Semster_number=="4"){

            system("CLS");
            cout<<"\n---------------------> ! IMPORTANT ! <------------------------"<<endl;

            cout<<"\n* IF ABSENT WITHOUT VALID REASON FOR EXAM ------------- (-1) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITHOUT VALID REASON -- (-1) * "<<endl;
            cout<<"* IF ABSENT WITH VALID REASON FOR EXAM ---------------- (-2) * "<<endl;
            cout<<"* IF DID NOT SUBMIT ASSIGNMENTS WITH VALID REASON ----- (-2) * \n"<<endl;

            cout<<"--------------------- ENTER YOUR MARKS ------------------------"<<endl;
            cout<<"---------------------------------------------------------------"<<endl<<endl;

        for(int x=26;x<32;x++){
             do{
            cout<<"Enter Exam Marks for "<<subject_name[x]<<"  : ";
            cin>>subject_score[x];

            cout<<"Enter Assignment Marks  : ";
            cin>>assignment_score[x];
            cout<<endl;

            ss =check_100(subject_score[x],assignment_score[x],x);   //ss variable for do while

            if(ss==1){
                all_score[x]=(subject_score[x]/2)+(assignment_score[x]/2);


                grade_name_f(x);

            }else{
                ss==0;
                cout<<"Invalid input.! "<<endl<<endl;

            }
        }while(ss==0);
            }

        cout<<"EXAM\t"<<"ASSIGNMENT"<<endl<<endl;
        cout<<"------------------"<<endl<<endl;
for(int x=26;x<32;x++){

        cout<<" "<<subject_score[x]<<"\t   "<<assignment_score[x]<<endl<<endl;

     if(assignment_score[x]==-1 && subject_score[x]>=30){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="INC";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-2){
        grade_name[x]="I(CA)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-1 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]>=30){
        grade_name[x]="DFR)";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(assignment_score[x]==-2 && subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }else if(subject_score[x]<30 && !(subject_score[x]==-2 || subject_score[x]==-1)){
         grade_name[x]="I(SE)";
        several_gpa[x]=0;

   }else if(subject_score[x]==-2){
        grade_name[x]="DFR";
        several_gpa[x]=0;

   }else if(subject_score[x]==-1){
        grade_name[x]="AB";
        several_gpa[x]=0;

   }
}
            semester_GPA[3]=0;
        for(int x=26;x<32;x++){

            semester_GPA[3] = (several_gpa[x]*3)+semester_GPA[3];
            semester_GPA[3]+several_gpa[x];
        }
            semester_GPA[3]=semester_GPA[3]/24;

                cout<<"-----------------------------------------------------------------------------"<<endl;
                cout<<"REGISTRATION NUMBER : "<<reg_number<<endl;
                cout<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
                reg_number+= ".txt";
                cout<<"-----------------------------------------------------------------------------"<<endl;

                cout<<"                        SEMESTER 04 - EXAM RESULTS  "<<endl<<endl;

                cout<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
                cout<<"-----------------------------------------------------------------------------"<<endl;
                cout<<subject_name[26]<<"\t"<<"\t"<<"\t"<<several_gpa[26]<<"\t-- "<<grade_name[26]<<endl<<endl;
                cout<<subject_name[27]<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[27]<<"\t-- "<<grade_name[27]<<endl<<endl;
                cout<<subject_name[28]<<"\t"<<"\t"<<several_gpa[28]<<"\t-- "<<grade_name[28]<<endl<<endl;
                cout<<subject_name[29]<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[29]<<"\t-- "<<grade_name[29]<<endl<<endl;
                cout<<subject_name[30]<<"\t"<<several_gpa[30]<<"\t-- "<<grade_name[30]<<endl<<endl;
                cout<<subject_name[31]<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[31]<<"\t-- "<<grade_name[31]<<endl<<endl;

                cout<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<several_gpa[24]<<endl<<endl;

                ofstream myfile;

                myfile.open(reg_number.c_str(), ios::app);
                myfile<<"-----------------------------------------------------------------------------"<<endl;
                myfile<<"REGISTRATION NUMBER : "<<reg_number<<endl;
                myfile<<"STUDENT NAME        : "<<reg_name<<endl<<endl;
                myfile<<"-----------------------------------------------------------------------------"<<endl;

                myfile<<"                        SEMESTER 04 - EXAM RESULTS  "<<endl<<endl;


                myfile<<"  SUBJECT"<<"\t\t\t\t\t\t"<<"GPA    GRADE/STATUS   "<<endl;
                myfile<<"-----------------------------------------------------------------------------"<<endl;
                myfile<<subject_name[26]<<"\t"<<"\t"<<"\t"<<several_gpa[26]<<"\t-- "<<grade_name[26]<<endl<<endl;
                myfile<<subject_name[27]<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[27]<<"\t-- "<<grade_name[27]<<endl<<endl;
                myfile<<subject_name[28]<<"\t"<<"\t"<<several_gpa[28]<<"\t-- "<<grade_name[28]<<endl<<endl;
                myfile<<subject_name[29]<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[29]<<"\t-- "<<grade_name[29]<<endl<<endl;
                myfile<<subject_name[30]<<"\t"<<several_gpa[30]<<"\t-- "<<grade_name[30]<<endl<<endl;
                myfile<<subject_name[31]<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<several_gpa[31]<<"\t-- "<<grade_name[31]<<endl<<endl;

                myfile<<"SEMESTER GRADE POINT AVERAGE -------------- :  "<<several_gpa[24]<<endl<<endl;


    }else if(Semster_number==""){

    }else{
        cout<<"Invalid input.!"<<endl;
    }
}while(!(Semster_number=="1"||Semster_number=="2"||Semster_number=="3"||Semster_number=="4"));


            do{
            cout<<"\n\n1 : Calculate another Student GPA"<<endl;
            cout<<"2 : Main menu"<<endl;
            cout<<"3 : Exit"<<endl<<endl;


                cout<<"Enter your option : ";

                cin>>next_student;
            if(next_student=='1'){
                system("CLS");
            }else if(next_student=='2'){
                system("CLS");
                password[0]='1';
                password[1]='2';
                password[2]='3';

            }else if(next_student=='3'){
                char zz=0;
                cout<<"\n\nAre you sure.? [y/n]: ";
                cin>>zz;
                if(zz=='y'){
                    system("CLS");
                    cout<<"\n\nSuccessfully Exited. ";
                    cout<<"THANK YOU !"<<endl<<endl;
                }else{
                next_student=0;
                system("CLS");
                }
            }else{
                system("CLS");
                cout<<"Invalid Input.!";
            }

        }while(!(next_student=='1' || next_student=='2' || next_student=='3'));

    }while(next_student=='1');   //loop to  Next Student




    }else{
        attempts++;
        system("CLS");

        cout<<"Password is incorrect.!"<<endl<<endl;;
        cout<<"Password hint -->   **3"<<endl<<endl;

    if(attempts==2){
        system("CLS");
        cout<<"W A R N I N G ! --> This is the Final Attempt.!"<<endl<<endl;

    }else if(attempts>2){

        int i;
    for(i=5; i>-1; i--){
        system("CLS");
        cout<<"Exceeded Attempts .!"<<endl<<endl;
        cout<<"Program will Exit in "<<i<<" seconds"<<endl<<endl;
        Sleep(1000);
    }
        exit(0);

    }
    }

}while(!(password[0]=='1' && password[1]=='2' && password[2]=='3'));

    }else if(user_name=="student"){   //****************************** log in USER **************************************
        boolean bl =true;
           system("CLS");


                cout<<"Logged In User : Student"<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"***********   V I E W   Y O U R   R E S U L T S   **************"<<endl;
                cout<<"----------------------------------------------------------------"<<endl<<endl;
do{
                cout<<"Please enter your register number    : ";
                cin>>reg_number;
                cout<<endl<<endl;
                reg_number+= ".txt";

                string line;

                ifstream myfile (reg_number.c_str(), ios::app);
                    if (getline (myfile,line)){
                    bl=true;


                while ( getline (myfile,line) ){
                    cout << line << '\n';
                    }
                myfile.close();

                    }else{
                        system("CLS");
                        cout<<"Logged In User : Student"<<endl;
                cout<<"----------------------------------------------------------------"<<endl;
                cout<<"***********   V I E W   Y O U R   R E S U L T S   **************"<<endl;
                cout<<"----------------------------------------------------------------"<<endl<<endl;

                cout << "This Student Record is Not Available.!"<<endl<<endl;
                    bl=false;

                    }
                }while(bl==false);
    }else{

        cout<<"Your user name is incorrect.!"<<endl<<endl;
        attempts++;
            if(attempts==3){
                int i;
                    for(i=10; i>-1; i--){
                        system("CLS");
                        cout<<"Program is Bloked.!"<<endl<<endl;
                        cout <<"Program will Unblock in "<< i <<" Seconds"<< endl;
                        Sleep(1000);
                    }
                system("CLS");
            }else if(attempts==4){

                system("CLS");

                int i;
                    for(i=5; i>-1; i--){
                        system("CLS");
                        cout<<"Exceeded Attempts .!"<<endl<<endl;
                        cout<<"Program will Exit in "<<i<<" seconds"<<endl<<endl;
                        Sleep(1000);
                    }
                exit(0);

            }
    }
    }while(!(user_name=="admin"||user_name=="student"));
}while(next_student=='2'); //----------------------------------------------------- // To loop to main menu

}    //************************************************************  end of the main class



int check_100(int x,int y,int z){ //function for validate scores
    cout<<endl;
        if((x<=100&&x>=0)&&(y<=100&&y>=0)){x=1;

        }else if(x==-1 || y==-1 || x==-2 || y==-2){  //return x for confirm the eligible,  to continue.
            x=1;
        }else
             x=0;
            return x;
}



int grade_name_f(int x){  //Insert grade names (A+,B+,...) and  insert GPA values


    if(all_score[x]<=100&&all_score[x]>=85){
        grade_name[x]="A+";
        several_gpa[x]=4.0;

    }else if(all_score[x]>=70&&all_score[x]<=84){
        grade_name[x]="A";
        several_gpa[x]=4.0;

    }else if(all_score[x]>=65&&all_score[x]<=69){
        grade_name[x]="A-";
        several_gpa[x]=3.7;

    }else if(all_score[x]>=60&&all_score[x]<=64){
        grade_name[x]="B+";
        several_gpa[x]=3.3;

    }else if(all_score[x]>=55&&all_score[x]<=59){
        grade_name[x]="B";
        several_gpa[x]=3.0;

    }else if(all_score[x]>=50&&all_score[x]<=54){
        grade_name[x]="B-";
        several_gpa[x]=2.7;

    }else if(all_score[x]>=45&&all_score[x]<=49){
        grade_name[x]="C+";
        several_gpa[x]=2.3;

    }else if(all_score[x]>=40&&all_score[x]<=44){
        grade_name[x]="C";
        several_gpa[x]=2.0;

    }else if(all_score[x]>=35&&all_score[x]<=39){
        grade_name[x]="C-";
        several_gpa[x]=1.7;

    }else if(all_score[x]>=30&&all_score[x]<=34){
        grade_name[x]="D+";
        several_gpa[x]=1.3;

    }else if(all_score[x]>=25&&all_score[x]<=29){
        grade_name[x]="D";
        several_gpa[x]=1.0;

    }else if(all_score[x]>=0&&all_score[x]<=24){
        grade_name[x]="E";
        several_gpa[x]=0.0;
    }

}






