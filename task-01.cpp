#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int totalCourses;

    cout << "==========================================" << endl;
    cout << "         ADVANCED CGPA CALCULATOR         " << endl;
    cout << "==========================================" << endl;

    cout << "Enter total number of courses: ";
    cin >> totalCourses;

    cin.ignore();

    string courseName[100];
    string letterGrade[100];

    float gradePoint[100];
    float coursePoints[100];

    int creditHours[100];

    float totalCredits = 0;
    float totalGradePoints = 0;


    // ---------- Taking Input ----------
    for(int i = 0; i < totalCourses; i++)
    {
        cout << endl;
        cout << "------------- Course " << i + 1 << " -------------" << endl;

        cout << "Enter Course Name: ";
        getline(cin, courseName[i]);

        cout << "Enter Letter Grade (A, B+, B, C, D, F): ";
        cin >> letterGrade[i];

        // Converting Letter Grade to Grade Point
        if(letterGrade[i] == "A")
        {
            gradePoint[i] = 4.0;
        }
        else if(letterGrade[i] == "B+")
        {
            gradePoint[i] = 3.5;
        }
        else if(letterGrade[i] == "B")
        {
            gradePoint[i] = 3.0;
        }
        else if(letterGrade[i] == "C")
        {
            gradePoint[i] = 2.0;
        }
        else if(letterGrade[i] == "D")
        {
            gradePoint[i] = 1.0;
        }
        else
        {
            gradePoint[i] = 0.0;
        }

        cout << "Enter Credit Hours: ";
        cin >> creditHours[i];

        while(creditHours[i] <= 0)
        {
            cout << "Invalid Credit Hours. Enter Again: ";
            cin >> creditHours[i];
        }

        coursePoints[i] = gradePoint[i] * creditHours[i];

        totalCredits += creditHours[i];
        totalGradePoints += coursePoints[i];

        cin.ignore();
    }


    // ---------- CGPA Calculation ----------
    float finalCGPA = totalGradePoints / totalCredits;


    // ---------- Report ----------
    cout << endl;
    cout << "==========================================" << endl;
    cout << "             SEMESTER REPORT              " << endl;
    cout << "==========================================" << endl;

    cout << left
         << setw(25) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits"
         << setw(15) << "Points"
         << endl;


    for(int i = 0; i < totalCourses; i++)
    {
        cout << left
             << setw(25) << courseName[i]
             << setw(15) << letterGrade[i]
             << setw(15) << creditHours[i]
             << setw(15) << coursePoints[i]
             << endl;
    }


    cout << fixed << setprecision(2);

    cout << endl;
    cout << "Total Credit Hours : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << "Final CGPA         : " << finalCGPA << endl;


    // ---------- Performance ----------
    cout << endl;

    if(finalCGPA >= 3.7)
    {
        cout << "Performance        : Excellent" << endl;
        cout << "Remarks            : Outstanding Work!" << endl;
    }
    else if(finalCGPA >= 3.0)
    {
        cout << "Performance        : Good" << endl;
        cout << "Remarks            : Keep Improving!" << endl;
    }
    else if(finalCGPA >= 2.0)
    {
        cout << "Performance        : Average" << endl;
        cout << "Remarks            : Need More Practice." << endl;
    }
    else
    {
        cout << "Performance        : Poor" << endl;
        cout << "Remarks            : Work Hard Next Time." << endl;
    }


    // ---------- Pass or Fail ----------
    if(finalCGPA >= 2.0)
    {
        cout << "Status             : PASS" << endl;
    }
    else
    {
        cout << "Status             : FAIL" << endl;
    }


    // ---------- Highest Grade Course ----------
    float highestGrade = gradePoint[0];
    string bestCourse = courseName[0];

    for(int i = 1; i < totalCourses; i++)
    {
        if(gradePoint[i] > highestGrade)
        {
            highestGrade = gradePoint[i];
            bestCourse = courseName[i];
        }
    }


    // ---------- Lowest Grade Course ----------
    float lowestGrade = gradePoint[0];
    string weakCourse = courseName[0];

    for(int i = 1; i < totalCourses; i++)
    {
        if(gradePoint[i] < lowestGrade)
        {
            lowestGrade = gradePoint[i];
            weakCourse = courseName[i];
        }
    }


    cout << endl;
    cout << "Best Course        : " << bestCourse << endl;
    cout << "Highest GPA        : " << highestGrade << endl;

    cout << "Weakest Course     : " << weakCourse << endl;
    cout << "Lowest GPA         : " << lowestGrade << endl;


    // ---------- Search Course ----------
    string searchCourse;

    cout << endl;
    cout << "Enter Course Name to Search: ";

    getline(cin, searchCourse);

    bool found = false;

    for(int i = 0; i < totalCourses; i++)
    {
        if(courseName[i] == searchCourse)
        {
            cout << endl;
            cout << "Course Found!" << endl;

            cout << "Course Name   : " << courseName[i] << endl;
            cout << "Letter Grade  : " << letterGrade[i] << endl;
            cout << "Grade Point   : " << gradePoint[i] << endl;
            cout << "Credit Hours  : " << creditHours[i] << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "Course Not Found." << endl;
    }


    cout << endl;
    cout << "==========================================" << endl;
    cout << " Thank You For Using CGPA Calculator :) " << endl;
    cout << "==========================================" << endl;

    return 0;
}