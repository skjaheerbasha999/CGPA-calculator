#include <bits/stdc++.h>
using namespace std;
struct Main{
    int totalsubject;
    string Name;
    string year;
    int semister;
    vector<string> Subject;
    vector<double> Marks;
    int eachsubmarks;
    int totalmarks;
    vector<char> Grade;
    vector<int> credits;
};
double Eachsubjectpercentage(int mark, int total){
    double ans = ((double)mark*100) / total;
    return double(ans);
}
double EachsubjectCGPA(int mark, int total){
    double ans = ( (double)mark *100)/ total ;
    return double(ans/10);
}
char EachsubjectGrade(double cgpa){
    if(cgpa == 10) return 'O'; 
    else if(cgpa >= 9 && cgpa < 10) return 'A';
    else if(cgpa >= 8 && cgpa < 9) return 'B';
    else if(cgpa >= 7 && cgpa < 8) return 'C';
    else if(cgpa >= 6 && cgpa < 7) return 'D';
    else return 'E';
}
char PassorFail(int marks){
    if(marks < 35) return 'F';
    else return 'P';
}
int credits(int marks, int c){
    if(marks < 35) return 0;
    else return c;
}
char result(int earned , int totalcredits) {
    if(earned == totalcredits) return 'P';
    else return 'F';
}
int main(){
    struct Main call;
    int a ;
    cout << "enter Name : ";
    cin >> call.Name ;
    cout << "Enter Year : ";
    cin >> call.year ;
    cout << "Enter Semister : ";
    cin >> call.semister ;
    cout << "Enter total subjets number : ";
    cin >> a;
    call.Subject.resize(a);
    call.Marks.resize(a);
    call.credits.resize(a);
    call.Grade.resize(a);
    cout << "Enter Total Subjets Names: " ;
    for(int i = 0; i < a; i++){
        cin >> call.Subject[i];
    }
    cout << "Enter Marks : " ;
    for(int i = 0; i < a; i++){
        cin >> call.Marks[i];
    }
    cout << "Enter full marks for subject:";
    cin >> call.eachsubmarks;
    cout << "Enter Credits : " ;
    for(int i = 0; i < a; i++){
        cin >> call.credits[i];
    }
    int studenttotalmarks = 0;
    for(int i = 0; i < a; i++){
        studenttotalmarks += call.Marks[i];
    }
    int totalcredits = 0;
    for(int i = 0; i < a; i++){
        totalcredits +=  call.credits[i];
    }
    cout << "=================== Marks Memo =======================" << endl;
    double totalcgpa = 0;
    int earnedcredits = 0;
    cout << "Name : " << call.Name <<  endl;
    cout << "Year : " << call.year << endl;
    cout << "Semister : " << call.semister << endl;
    cout << "------------------------------------------------------" << endl;
    cout << setw(4) << "SI.No "
         << setw(9) << "Subject"
         << setw(7) << "Marks"
         << setw(8) << "credits"
         << setw(8) << "CGPA" 
         << setw(7) << "Grade" 
         << setw(10) << "Pass/Fail"<< endl;
    cout << "-------------------------------------------------------" << endl;
   for(int i = 0; i < a; i++){ 
    double per = Eachsubjectpercentage(call.Marks[i], call.eachsubmarks);
    double cgpa = EachsubjectCGPA(call.Marks[i], call.eachsubmarks);
    int Credits = credits(call.Marks[i], call.credits[i]);
    totalcgpa += cgpa * call.credits[i];
    earnedcredits += Credits;
    cout << setw(4) << i+1 
         << setw(9) << call.Subject[i] 
         << setw(7) << call.Marks[i] 
         <<  setw(8) << credits(call.Marks[i], call.credits[i]) 
         <<  setw(8) << cgpa 
         << setw(7) << EachsubjectGrade(cgpa) 
         << setw(10) << PassorFail(call.Marks[i]) <<  endl;
}
    cout << "------------------------------------------------------" << endl;
    cout << "Total CGPA : " << double(totalcgpa / totalcredits) << setprecision(2)<< "/10"  << endl;
    cout << "Total Credits : " << earnedcredits << "/" << totalcredits << endl;
    cout << "Result : " << result(earnedcredits, totalcredits) << endl;
}
