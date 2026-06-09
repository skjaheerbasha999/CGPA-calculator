#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string Name;
    string year;
    int semester;
    vector<string> Subject;
    vector<double> Marks;
    int eachsubmarks;
    vector<int> credits;
};

// Calculate percentage dynamically based on full marks
double Eachsubjectpercentage(double mark, double total){
    if (total == 0) return 0.0;
    return (mark * 100.0) / total;
}

// Calculate CGPA dynamically (out of 10)
double EachsubjectCGPA(double mark, double total){
    if (total == 0) return 0.0;
    return (mark * 10.0) / total;
}

// Determine grade (returns 'F' if marks are below passing threshold of 35%)
char EachsubjectGrade(double cgpa, double mark, double total){
    if (total == 0 || (mark / total) < 0.35) return 'F';
    
    if (cgpa >= 9.5) return 'O'; 
    else if (cgpa >= 8.5) return 'A';
    else if (cgpa >= 7.5) return 'B';
    else if (cgpa >= 6.5) return 'C';
    else if (cgpa >= 5.0) return 'D';
    else return 'E';
}

char PassorFail(double mark, double total){
    if (total == 0 || (mark / total) < 0.35) return 'F';
    return 'P';
}

int GetEarnedCredits(double mark, double total, int creditValue){
    if (total == 0 || (mark / total) < 0.35) return 0;
    return creditValue;
}

char result(int earned, int totalcredits) {
    if (earned == totalcredits && totalcredits > 0) return 'P';
    return 'F';
}

int main(){
    Student call;
    int numSubjects;
    
    cout << "Enter Name: ";
    getline(cin >> ws, call.Name);
    
    cout << "Enter Year: ";
    getline(cin >> ws, call.year);
    
    cout << "Enter Semester: ";
    cin >> call.semester;
    
    cout << "Enter total subjects number: ";
    cin >> numSubjects;
    
    call.Subject.resize(numSubjects);
    call.Marks.resize(numSubjects);
    call.credits.resize(numSubjects);
    
    cout << "Enter full marks for each subject: ";
    cin >> call.eachsubmarks;
    
    for(int i = 0; i < numSubjects; i++){
        cout << "Enter Subject " << i + 1 << " Name: ";
        getline(cin >> ws, call.Subject[i]);
        
        cout << "Enter Marks for " << call.Subject[i] << ": ";
        cin >> call.Marks[i];
        
        cout << "Enter Credits for " << call.Subject[i] << ": ";
        cin >> call.credits[i];
    }
    
    int totalcredits = 0;
    for(int i = 0; i < numSubjects; i++){
        totalcredits += call.credits[i];
    }
    
    cout << "\n=================== Marks Memo =======================" << endl;
    double totalcgpa = 0;
    int earnedcredits = 0;
    
    cout << "Name     : " << call.Name <<  endl;
    cout << "Year     : " << call.year << endl;
    cout << "Semester : " << call.semester << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(8) << "Sl. No."
         << setw(20) << "Subject"
         << right << setw(7) << "Marks"
         << setw(9) << "Credits"
         << setw(8) << "CGPA" 
         << setw(8) << "Grade" 
         << setw(11) << "Pass/Fail" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for(int i = 0; i < numSubjects; i++){ 
        double cgpa = EachsubjectCGPA(call.Marks[i], call.eachsubmarks);
        int Credits = GetEarnedCredits(call.Marks[i], call.eachsubmarks, call.credits[i]);
        totalcgpa += cgpa * call.credits[i];
        earnedcredits += Credits;
        
        cout << left << setw(8) << i + 1 
             << setw(20) << call.Subject[i] 
             << right << setw(7) << call.Marks[i] 
             << setw(9) << call.credits[i] 
             << setw(8) << fixed << setprecision(2) << cgpa 
             << setw(8) << EachsubjectGrade(cgpa, call.Marks[i], call.eachsubmarks) 
             << setw(11) << PassorFail(call.Marks[i], call.eachsubmarks) << endl;
    }
    
    cout << "--------------------------------------------------------" << endl;
    double finalCGPA = (totalcredits > 0) ? (totalcgpa / totalcredits) : 0.0;
    cout << "Total CGPA    : " << fixed << setprecision(2) << finalCGPA << "/10"  << endl;
    cout << "Total Credits : " << earnedcredits << "/" << totalcredits << endl;
    cout << "Result        : " << result(earnedcredits, totalcredits) << endl;
    
    return 0;
}

/*
Enter Name: John Doe
Enter Year: 2nd Year
Enter Semester: 4
Enter total subjects number: 3
Enter full marks for each subject: 100
Enter Subject 1 Name: Mathematics
Enter Marks for Mathematics: 95
Enter Credits for Mathematics: 4
Enter Subject 2 Name: Physics
Enter Marks for Physics: 82
Enter Credits for Physics: 3
Enter Subject 3 Name: Chemistry
Enter Marks for Chemistry: 34
Enter Credits for Chemistry: 3

=================== Marks Memo =======================
Name     : John Doe
Year     : 2nd Year
Semester : 4
--------------------------------------------------------
Sl. No. Subject               Marks  Credits    CGPA   Grade  Pass/Fail
--------------------------------------------------------
1       Mathematics              95        4    9.50       O          P
2       Physics               82.00        3    8.20       B          P
3       Chemistry             34.00        3    3.40       F          F
--------------------------------------------------------
Total CGPA    : 7.28/10
Total Credits : 7/10
Result        : F
*/
