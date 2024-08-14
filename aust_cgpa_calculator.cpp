//This code can be used to calculate your CGPA if it follows below Grading system
//Number			          Grade	Point
//80% 	and above		      A+	4.00
//75% 	to less than 80%	A	  3.75
//70% 	to less than 75%	A-	3.50
//65% 	to less than 70%	B+	3.25
//60% 	to less than 65%	B	  3.00
//55% 	to less than 60%	B-	2.75
//50% 	to less than 55%	C+	2.50
//45%	  to less than 50%	C	2.25
//40% 	to less than 45%	D	2.00
//<40% 	Less than 	40%	F	0.00



#include <iostream>
#include <vector>
using namespace std;

double getGrade(int marks) {
    if (marks <= 100 && marks >= 80) {
        return 4.0;
    } else if (marks <= 79 && marks >= 75) {
        return 3.75;
    } else if (marks <= 74 && marks >= 70) {
        return 3.50;
    } else if (marks <= 69 && marks >= 65) {
        return 3.25;
    } else if (marks <= 64 && marks >= 60) {
        return 3.00;
    } else if (marks <= 59 && marks >= 55) {
        return 2.75;
    } else if (marks <= 54 && marks >= 50) {
        return 2.5;
    } else if (marks <= 49 && marks >= 45) {
        return 2.25;
    } else if (marks <= 44 && marks >= 40) {
        return 2.00;
    } else {
        return 0.0;
    }
}

double calculateCGPA(const vector<int>& marks, const vector<double>& credits) {
    double totalGradePoints = 0.0;
    double totalCredits = 0.0;

    for (size_t i = 0; i < marks.size(); ++i) {
        totalGradePoints += getGrade(marks[i]) * credits[i];
        totalCredits += credits[i];
    }

    return totalCredits ? totalGradePoints / totalCredits : 0.0;
}

int main() {
    int numberOfCourses;
    cout << "Enter the number of courses: ";
    cin >> numberOfCourses;

    vector<int> marks(numberOfCourses);
    vector<double> credits(numberOfCourses);

    for (int i = 0; i < numberOfCourses; ++i) {
        cout << "Enter marks for course " << i + 1 << ": ";
        cin >> marks[i];
        cout << "Enter credits for course " << i + 1 << " (max 3 credits): ";
        cin >> credits[i];

        // Validate the credits input
        if (credits[i] > 3) {
            cout << "Credits cannot exceed 3. Setting to 3." << endl;
            credits[i] = 3;
        }
    }

    double cgpa = calculateCGPA(marks, credits);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}
