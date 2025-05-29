#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>// random password generation
#include <ctime>//rand time stop

using namespace std;

int studentLoginIndex;
int teacherLoginIndex;

// Structures
struct personal_studentInfo {
    string studentName;
    int age;
    string contactNumber;
    string city;
};

struct educational_studentInfo {
    string subject;
    int semester;
    string program;
    int fscResult;
    int extraCharges;
    int tuitionFees;
    int courses;  // Add this line to store the number of courses

};


struct studentLogin {
    string username;
    string password;
};

struct teacherInfo {
    string teacherName;
    int teacherAge;
    string teacherCity;
    string course[2];
};

struct teacherLogin {
    string username;
    string password;


};

struct courseInfo {
    string courseName;
    string courseTeacher;
    int courseCreditHour;
    string lectureNotes;
};

// Globals
const int MAX_STUDENTS = 20;
const int MAX_TEACHERS = 20;
int indexStudent = 0;
int indexTeacher = 0;

//preassigned teachers

courseInfo courseNum[MAX_STUDENTS];
personal_studentInfo personalInfo[MAX_STUDENTS];
educational_studentInfo educationalInfo[MAX_STUDENTS];
studentLogin studentLog[MAX_STUDENTS];
teacherInfo Teacher[MAX_TEACHERS];
teacherLogin teacherLog[MAX_TEACHERS];
// Function to generate random password

string generateRandomPassword(int length) {
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string password = "";
    for (int i = 0; i < length; i++) {
        password += characters[rand() % characters.length()];
    }
    return password;
}


void Pre_defined_variable() {

    courseNum[2].courseTeacher = "Adnan Khalid";
    courseNum[3].courseTeacher = "Adnan Khalid";
    courseNum[4].courseTeacher = "M.Suood ";
    courseNum[5].courseTeacher = "M.Suood";
    courseNum[6].courseTeacher = "Humaid Atif";
    courseNum[7].courseTeacher = "Humaid Atif";



    //course outline:
    courseNum[0].courseName = "Computer Programing";
    courseNum[1].courseName = "Object Oriented Programing";
    courseNum[2].courseName = "ICT";
    courseNum[3].courseName = "Computer Networks";
    courseNum[4].courseName = "Descrete Math";
    courseNum[5].courseName = "Calculus";
    courseNum[6].courseName = "Islamiyat";
    courseNum[7].courseName = "Pak Studies";

    courseNum[0].courseCreditHour = 3;
    courseNum[1].courseCreditHour = 3;
    courseNum[2].courseCreditHour = 2;
    courseNum[3].courseCreditHour = 2;
    courseNum[4].courseCreditHour = 3;
    courseNum[5].courseCreditHour = 3;
    courseNum[6].courseCreditHour = 1;
    courseNum[7].courseCreditHour = 1;


}


void loadStudentIndex() {
    ifstream indexFile("studentIndex.txt", ios::in);
    if (indexFile) {
        indexFile >> indexStudent;
        indexFile.close();
    }
    else {
        indexStudent = 0; // Default to 0 if the file doesn't exist
    }
}


void saveStudentIndex() {
    ofstream indexFile("studentIndex.txt", ios::trunc);
    indexFile << indexStudent;
    indexFile.close();
}


void logo() {
    cout << "#     #                                                              ######                                   #     #" << endl;
    cout << "#  #  # ###### #       ####   ####  #    # ######    #####  ####     #     #   ##   #    # #####  #   ##      #     # #    # # #    # ###### #####   ####  # ##### #   #" << endl;
    cout << "#  #  # #      #      #    # #    # ##  ## #           #   #    #    #     #  #  #  #    # #    # #  #  #     #     # ##   # # #    # #      #    # #      #   #    # # " << endl;
    cout << "#  #  # #####  #      #      #    # # ## # #####       #   #    #    ######  #    # ###### #    # # #    #    #     # # #  # # #    # #####  #    #  ####  #   #     #  " << endl;
    cout << "#  #  # #      #      #      #    # #    # #           #   #    #    #     # ###### #    # #####  # ######    #     # #  # # # #    # #      #####       # #   #     #  " << endl;
    cout << "#  #  # #      #      #    # #    # #    # #           #   #    #    #     # #    # #    # #   #  # #    #    #     # #   ## #  #  #  #      #   #  #    # #   #     #  " << endl;
    cout << " ## ##  ###### ######  ####   ####  #    # ######      #    ####     ######  #    # #    # #    # # #    #     #####  #    # #   ##   ###### #    #  ####  #   #     #  " << endl;
    cout << endl;
    cout << "Press Enter to continue ";
    string pause;
    getline(cin, pause);
    system("cls");
}


void studentProgram() {
    int programChoice;
    cout << "Program:" << endl;
    cout << "1.BS CS" << endl;
    cout << "2.BS IT" << endl;
    cout << "Pick a course from above: ";
    cin >> programChoice;
    switch (programChoice) {
    case 1:
        educationalInfo[indexStudent].program = "BSCS";
        educationalInfo[indexStudent].courses = 4;
        break;
    case 2:
        educationalInfo[indexStudent].program = "BSIT";
        educationalInfo[indexStudent].courses = 4;
        break;
    }
}



// Function to add a new student
void addNewStudent() {
    system("cls");

    if (indexStudent >= MAX_STUDENTS) {
        cout << "Maximum number of students reached!" << endl;
        return;
    }

    // File streams for storing data
    ofstream studentDetailsFile("studentDetails.txt", ios::app); // Append mode for student details
    ofstream loginDetailsFile("loginDetails.txt", ios::app);     // Append mode for login details

    // Personal Information
    cout << "Enter Student's Information:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, personalInfo[indexStudent].studentName);
    cout << "Age: ";
    cin >> personalInfo[indexStudent].age;
    cin.ignore();
    cout << "Contact Number: ";
    getline(cin, personalInfo[indexStudent].contactNumber);
    cout << "City: ";
    getline(cin, personalInfo[indexStudent].city);

    // Education Information
    cout << "FSC %: ";
    cin >> educationalInfo[indexStudent].fscResult;
    studentProgram();
    cout << "Semester: ";
    cin >> educationalInfo[indexStudent].semester;
    cout << "Tuition Fees: ";
    cin >> educationalInfo[indexStudent].tuitionFees;


    // Generate username (remove spaces from name)
    for (char ch : personalInfo[indexStudent].studentName) {
        if (ch != ' ') {
            studentLog[indexStudent].username += ch;
        }
    }
    // Generate password
    studentLog[indexStudent].password = generateRandomPassword(8);

    //write  info to file
    studentDetailsFile << indexStudent << "\n"
        << personalInfo[indexStudent].studentName << "\n"
        << personalInfo[indexStudent].age << "\n"
        << personalInfo[indexStudent].contactNumber << "\n"
        << personalInfo[indexStudent].city << "\n"
        << educationalInfo[indexStudent].fscResult << "\n"
        << educationalInfo[indexStudent].program << "\n"
        << educationalInfo[indexStudent].semester << "\n"
        << educationalInfo[indexStudent].tuitionFees << "\n\n";

    //write login info to file
    loginDetailsFile << indexStudent << "\n"
        << studentLog[indexStudent].username << "\n"
        << studentLog[indexStudent].password << "\n\n";

    // Display generated credentials
    cout << "Roll Number: " << indexStudent << endl;
    cout << "Generated Username: " << studentLog[indexStudent].username << endl;
    cout << "Generated Password: " << studentLog[indexStudent].password << endl;

    indexStudent++;

    saveStudentIndex(); // Save the updated index
    cout << "Press Enter to continue ";
    string pause;
    getline(cin, pause);
    cout << endl;

    studentDetailsFile.close();
    loginDetailsFile.close();

    system("pause");
    system("cls");

}






void assignCourse() {
    int courseChoice;
    cout << "--------------------------------------------------" << endl;
    cout << "| 0 | Computer Programing |" << endl;
    cout << "| 1 | Object Oriented Programing |" << endl;
    cout << "| 2 | ICT |" << endl;
    cout << "| 3 | Computer Networks |" << endl;
    cout << "| 4 | Discrete Math |" << endl;
    cout << "| 5 | Calculus |" << endl;
    cout << "| 6 | Islamiyat |" << endl;
    cout << "| 7 | Pak Studies |" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0;i < 2;i++) {

        cout << "Course Number " << i + 1 << endl;
        cin >> courseChoice;
        switch (courseChoice) {
        case 0:
            courseNum[0].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[0].courseName;
            break;
        case 1:
            courseNum[1].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[1].courseName;
            break;
        case 2:
            courseNum[2].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[2].courseName;

            break;
        case 3:
            courseNum[3].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[3].courseName;
            break;
        case 4:
            courseNum[4].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[4].courseName;
            break;
        case 5:
            courseNum[5].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[5].courseName;

            break;
        case 6:
            courseNum[6].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[6].courseName;
            break;
        case 7:
            courseNum[7].courseTeacher = Teacher[indexTeacher].teacherName;
            Teacher[indexTeacher].course[i] = courseNum[7].courseName;

            break;
        }

    }

}

// Function to add a new teacher
void addNewTeacher() {
    system("cls");
    if (indexTeacher >= MAX_TEACHERS) {
        cout << "Maximum number of teachers reached!" << endl;
        return;
    }
    cout << "Enter Teacher's Personal Information:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, Teacher[indexTeacher].teacherName);
    cout << "Age: ";
    cin >> Teacher[indexTeacher].teacherAge;
    cin.ignore();
    cout << "City: ";
    getline(cin, Teacher[indexTeacher].teacherCity);

    //Course Information.
    cout << "Enter Teacher's Educational Information:\n";
    cout << "Assign Course:" << endl;
    assignCourse();
    // Assign login credentials
    teacherLog[indexTeacher].username = Teacher[indexTeacher].teacherName;
    teacherLog[indexTeacher].password = generateRandomPassword(8);
    cout << "Generated Username: " << teacherLog[indexTeacher].username << endl;
    cout << "Generated Password: " << teacherLog[indexTeacher].password << endl;

    indexTeacher++;

    cout << "Press Enter to continue ";
    string pause;
    getline(cin, pause);
    cout << endl;
    system("pause");
    system("cls");
}

void teacherDetails() {

    system("cls");

    cout << left << setw(20) << "Name" // Header
        << setw(10) << "Age"
        << setw(15) << "City"
        << setw(28) << "Course 1"
        << setw(22) << "Course 2"
        << setw(15) << "Username:"
        << setw(15) << "Password:" << endl;
    cout << setfill('-') << setw(135) << " -" << endl;
    cout << setfill(' ');

    // Data Rows
    cout << left << setw(20) << Teacher[teacherLoginIndex].teacherName
        << setw(10) << Teacher[teacherLoginIndex].teacherAge
        << setw(8) << Teacher[teacherLoginIndex].teacherCity
        << setw(26) << Teacher[teacherLoginIndex].course[0]
        << setw(32) << Teacher[teacherLoginIndex].course[1]
        << setw(15) << teacherLog[teacherLoginIndex].username
        << setw(15) << teacherLog[teacherLoginIndex].password << endl;

}


void studentInfo() {

    system("cls");


    // Open the student details file
    ifstream studentDetailsFile("studentDetails.txt", ios::in);
    if (!studentDetailsFile) {
        cout << "Error: Unable to open studentDetails.txt. No data to display!" << endl;
        return;
    }

    string tempName, tempContact, tempCity, tempProgram;
    int tempAge, tempFscResult, tempSemester, tempTuitionFees, tempIndex;
    bool studentFound = false;

    // Read data until the end of the file
    while (!studentDetailsFile.eof()) {
        studentDetailsFile >> tempIndex;
        studentDetailsFile.ignore();                 // Ignore any leftover newline characters
        getline(studentDetailsFile, tempName);
        studentDetailsFile >> tempAge;
        studentDetailsFile.ignore();
        getline(studentDetailsFile, tempContact);
        getline(studentDetailsFile, tempCity);
        studentDetailsFile >> tempFscResult;
        studentDetailsFile.ignore();
        getline(studentDetailsFile, tempProgram);
        studentDetailsFile >> tempSemester;
        studentDetailsFile >> tempTuitionFees;
        studentDetailsFile.ignore();

        if (tempIndex == studentLoginIndex) {
            cout << left << setw(20) << "Name"
                << setw(10) << "Age"
                << setw(15) << "City"
                << setw(20) << "Contact Number:"
                << setw(20) << "Program"
                << setw(15) << "Semester"
                << setw(15) << "Tuition Fees" << endl;
            cout << setfill('-') << setw(115) << "-" << endl;
            cout << setfill(' ');

            cout << left << setw(20) << tempName
                << setw(10) << tempAge
                << setw(15) << tempCity
                << setw(20) << tempContact
                << setw(20) << tempProgram
                << setw(15) << tempSemester
                << setw(15) << tempTuitionFees << endl;

            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Error: No student found with index " << studentLoginIndex << "!" << endl;
    }

    studentDetailsFile.close();
}


// Function to search for a student by roll number or name
void searchStudent() {

    system("cls");

    int studentIndex;
    bool found = false;
    char confirm;

    cout << "Enter Student Index: ";
    cin >> studentIndex;

    if (studentIndex < 0 || studentIndex >= indexStudent) {
        cout << "Error: Invalid student index!" << endl;
        return;
    }

    // Display student details
    cout << "Student Details:" << endl;
    cout << "Name: " << personalInfo[studentIndex].studentName << endl;
    cout << "Age: " << personalInfo[studentIndex].age << endl;
    cout << "Contact: " << personalInfo[studentIndex].contactNumber << endl;
    cout << "City: " << personalInfo[studentIndex].city << endl;
    cout << "Program: " << educationalInfo[studentIndex].program << endl;
    cout << "Semester: " << educationalInfo[studentIndex].semester << endl;
    cout << "Roll Number: 13-4242-" << studentIndex << endl;

    cout << "Press Enter to continue ";
    string pause;
    getline(cin, pause);
    cout << endl;
    system("pause");
    system("cls");

}

void educationDetails() {
    system("cls");


    cout << endl;
    // Headers
    cout << left << setw(20) << "Program"
        << setw(20) << "Semester"
        << setw(20) << "Courses"
        << setw(20) << "FSC %"
        << setw(20) << "Tuition Fees" << endl;
    cout << setfill('-') << setw(90) << " -" << endl;
    cout << setfill(' ');

    // Data Rows
    cout << setw(20) << educationalInfo[studentLoginIndex].program
        << setw(20) << educationalInfo[studentLoginIndex].semester
        << setw(20) << educationalInfo[studentLoginIndex].courses
        << setw(20) << educationalInfo[studentLoginIndex].fscResult
        << setw(20) << educationalInfo[studentLoginIndex].tuitionFees << endl;
}

void courseDetail() {

    system("cls");

    cout << left << setw(26) << "Course"
        << setw(22) << "Instructor"
        << setw(20) << "Credit Hours" << endl;
    cout << setfill('-') << setw(70) << " -" << endl;
    cout << setfill(' ');
    // Data Rows
    if (educationalInfo[studentLoginIndex].program == "BSCS" && educationalInfo[studentLoginIndex].semester == 1)
    {
        cout << left << setw(27) << courseNum[0].courseName << setw(26) << courseNum[0].courseTeacher << setw(70) << courseNum[0].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[2].courseName << setw(26) << courseNum[2].courseTeacher << setw(70) << courseNum[2].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[4].courseName << setw(26) << courseNum[4].courseTeacher << setw(70) << courseNum[4].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[6].courseName << setw(26) << courseNum[6].courseTeacher << setw(70) << courseNum[6].courseCreditHour << endl;
    }
    if (educationalInfo[studentLoginIndex].program == "BSCS" && educationalInfo[studentLoginIndex].semester == 2)
    {
        cout << left << setw(27) << courseNum[1].courseName << setw(26) << courseNum[1].courseTeacher << setw(70) << courseNum[1].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[3].courseName << setw(26) << courseNum[3].courseTeacher << setw(70) << courseNum[3].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[5].courseName << setw(26) << courseNum[5].courseTeacher << setw(70) << courseNum[5].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[7].courseName << setw(26) << courseNum[7].courseTeacher << setw(70) << courseNum[7].courseCreditHour << endl;
    }
    if (educationalInfo[studentLoginIndex].program == "BSIT" && educationalInfo[studentLoginIndex].semester == 1)
    {
        cout << left << setw(27) << courseNum[0].courseName << setw(26) << courseNum[0].courseTeacher << setw(70) << courseNum[0].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[2].courseName << setw(26) << courseNum[2].courseTeacher << setw(70) << courseNum[2].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[4].courseName << setw(26) << courseNum[4].courseTeacher << setw(70) << courseNum[4].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[6].courseName << setw(26) << courseNum[6].courseTeacher << setw(70) << courseNum[6].courseCreditHour << endl;
    }
    if (educationalInfo[studentLoginIndex].program == "BSIT" && educationalInfo[studentLoginIndex].semester == 2)
    {
        cout << left << setw(27) << courseNum[1].courseName << setw(26) << courseNum[1].courseTeacher << setw(70) << courseNum[1].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[3].courseName << setw(26) << courseNum[3].courseTeacher << setw(70) << courseNum[3].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[5].courseName << setw(26) << courseNum[5].courseTeacher << setw(70) << courseNum[5].courseCreditHour << endl;
        cout << left << setw(27) << courseNum[7].courseName << setw(26) << courseNum[7].courseTeacher << setw(70) << courseNum[7].courseCreditHour << endl;
    }

}

void addLectureNotes() {

    int choice;

    cout << " 0." << Teacher[teacherLoginIndex].course[0] << endl;
    cout << " 1." << Teacher[teacherLoginIndex].course[1] << endl;

    cout << "Select Course:" << endl;
    cin >> choice;

    cout << "Enter Lecture Notes" << endl;

    if (choice == 0) {
        cin.ignore();
        getline(cin, courseNum[0].lectureNotes);
    }
    else if (choice == 1) {
        cin.ignore();
        getline(cin, courseNum[1].lectureNotes);
    }

    cout << "Press Enter to continue ";
    string pause;
    getline(cin, pause);
    cout << endl;
    system("pause");
    system("cls");



}

void showLectureNotes() {
    system("cls");


    int choice;
    if ((educationalInfo[studentLoginIndex].program == "BSCS" || educationalInfo[studentLoginIndex].program == "BSIT") && educationalInfo[studentLoginIndex].semester == 1) {
        cout << "--------------------------------------------------" << endl;
        cout << "| 0 | Computer Programing |" << endl;
        cout << "| 2 | ICT |" << endl;
        cout << "| 4 |  Descrete Math |" << endl;
        cout << "| 6 | Islamiyat |" << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "Choose Course:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << courseNum[0].lectureNotes;
            break;
        case 2:
            cout << courseNum[2].lectureNotes;
            break;
        case 4:
            cout << courseNum[4].lectureNotes;
            break;
        case 6:
            cout << courseNum[6].lectureNotes;
            break;
        default:
            break;
        }
    }
    else if ((educationalInfo[studentLoginIndex].program == "BSCS" || educationalInfo[studentLoginIndex].program == "BSIT") && educationalInfo[studentLoginIndex].semester == 2) {
        cout << "--------------------------------------------------" << endl;
        cout << "| 1 | Object Oriented Programing |" << endl;
        cout << "| 3 | Computer Networks |" << endl;
        cout << "| 5 |  Discrete Math |" << endl;
        cout << "| 7 | Pak Studies |" << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "Choose Course:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << courseNum[0].lectureNotes;
            break;
        case 2:
            cout << courseNum[2].lectureNotes;
            break;
        case 4:
            cout << courseNum[4].lectureNotes;
            break;
        case 6:
            cout << courseNum[6].lectureNotes;
            break;
        default:
            break;
        }
    }

    cout << "\nPress Enter to continue ";
    string pause;
    getline(cin, pause);
    cout << endl;
    system("pause");
    system("cls");

}


int studentChoice = 0;


void student_menu() {
    while (studentChoice != 5) {

        cout << " #####                                             #     #                      " << endl;
        cout << "#     # ##### #    # #####  ###### #    # #####    ##   ## ###### #    # #    # " << endl;
        cout << "#         #   #    # #    # #      ##   #   #      # # # # #      ##   # #    # " << endl;
        cout << " #####    #   #    # #    # #####  # #  #   #      #  #  # #####  # #  # #    # " << endl;
        cout << "      #   #   #    # #    # #      #  # #   #      #     # #      #  # # #    #  " << endl;
        cout << "#     #   #   #    # #    # #      #   ##   #      #     # #      #   ## #    # " << endl;
        cout << " #####    #    ####  #####  ###### #    #   #      #     # ###### #    #  ####  " << endl;
        cout << endl;
        cout << "1. Student Info : " << endl;
        cout << "2. Educational Details : " << endl;
        cout << "3. Course Details : " << endl;
        cout << "4. Lecture Material : " << endl;
        cout << "5. Exit : " << endl;
        cout << "Enter your choice:" << endl;
        cin >> studentChoice;
        switch (studentChoice)
        {
        case 1:
            studentInfo();
            system("pause");
            system("cls");
            break;

        case 2:
            educationDetails();
            system("pause");
            system("cls");
            break;

        case 3:
            courseDetail();
            system("pause");
            system("cls");
            break;

        case 4:
            showLectureNotes();
            break;

        case 5:
            //exit
            break;


        }
        system("pause");
    }
}


int teacherChoice;


void teacher_menu() {
    system("cls");


    while (teacherChoice != 3) {

        cout << "####### #######    #     #####  #     # ####### ######     #     # ####### #     # #     #" << endl;
        cout << "   #    #         # #   #     # #     # #       #     #    ##   ## #       ##    # #     #" << endl;
        cout << "   #    #        #   #  #       #     # #       #     #    # # # # #       # #   # #     # " << endl;
        cout << "   #    #####   #     # #       ####### #####   ######     #  #  # #####   #  #  # #     # " << endl;
        cout << "   #    #       ####### #       #     # #       #   #      #     # #       #   # # #     # " << endl;
        cout << "   #    #       #     # #     # #     # #       #    #     #     # #       #    ## #     # " << endl;
        cout << "   #    ####### #     #  #####  #     # ####### #     #    #     # ####### #     #  ##### " << endl;
        cout << endl;
        cout << "1. Teacher Info : " << endl;
        cout << "2. Lecture Material : " << endl;
        cout << "3. Exit : " << endl;

        cout << "Choose your Option:";
        cin >> teacherChoice;
        switch (teacherChoice)
        {
        case 1:
            teacherDetails();
            system("pause");
            system("cls");
            break;

        case 2:
            addLectureNotes();
            break;

        case 3:
            //exit
            break;


        }
        system("pause");

    }

}



void generateChallanHTML() {
    system("cls");


    cout << "\nGenerate Challan" << endl;
    cout << setfill('=') << setw(45) << "=" << endl;

    int studentIndex;
    bool found = false;
    char confirm;

    cout << "Enter Student Index: ";
    cin >> studentIndex;

    if (studentIndex < 0 || studentIndex >= indexStudent) {
        cout << "Error: Invalid student index!" << endl;
        return;
    }

    // Display student details
    cout << "Student Details:" << endl;
    cout << "Name: " << personalInfo[studentIndex].studentName << endl;
    cout << "Age: " << personalInfo[studentIndex].age << endl;
    cout << "Contact: " << personalInfo[studentIndex].contactNumber << endl;
    cout << "City: " << personalInfo[studentIndex].city << endl;
    cout << "Program: " << educationalInfo[studentIndex].program << endl;
    cout << "Semester: " << educationalInfo[studentIndex].semester << endl;
    cout << "Roll Number: 13-4242-" << studentIndex << endl;

    // Get extra charges
    cout << "Extra Charges (if any): ";
    cin >> educationalInfo[studentIndex].extraCharges;

    // Confirm challan generation
    cout << "\nGenerate Challan? (Y): ";
    cin >> confirm;

    if (confirm != 'Y' && confirm != 'y') {
        cout << "Challan generation canceled." << endl;
        return;
    }

    // Generate the challan HTML file
    ofstream challanFile("Challan.html");

    if (!challanFile) {
        cerr << "Error: Unable to open 'Challan.html' for writing." << endl;
        return;
    }

    challanFile << "<!DOCTYPE html>\n<html lang='en'>\n<head>\n";
    challanFile << "<meta charset='UTF-8'>\n<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
    challanFile << "<title>University Student Challan</title>\n";
    challanFile << "<style>\n";
    challanFile << "body { font-family: Arial, sans-serif; margin: 20px; padding: 0; background-color: #f5f5f5; }\n";
    challanFile << ".challan-container { max-width: 600px; margin: 0 auto; padding: 20px; background: #fff; "
        << "border: 1px solid #ddd; border-radius: 8px; box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1); }\n";
    challanFile << ".logo { text-align: center; margin-bottom: 20px; }\n";
    challanFile << ".logo img { width: 150px; }\n";
    challanFile << ".header { text-align: center; margin-bottom: 20px; }\n";
    challanFile << ".header h2 { margin: 0; color: #333; }\n";
    challanFile << ".details { margin-bottom: 20px; }\n";
    challanFile << ".details p { margin: 5px 0; line-height: 1.6; }\n";
    challanFile << ".fees-section { border-top: 1px solid #ddd; padding-top: 10px; }\n";
    challanFile << ".fees-section p { margin: 5px 0; font-weight: bold; }\n";
    challanFile << ".due-date { color: red; font-weight: bold; }\n";
    challanFile << ".footer { text-align: center; margin-top: 20px; font-size: 12px; color: #555; }\n";
    challanFile << "</style>\n</head>\n<body>\n";
    challanFile << "<div class='challan-container'>\n";
    challanFile << "<div class='logo'><img src='https://nica.team/wp-content/uploads/2021/01/logo5.png' alt='University Logo'></div>\n";
    challanFile << "<div class='header'><h2>University Student Challan</h2></div>\n";
    challanFile << "<div class='details'>\n";
    challanFile << "<p><strong>Name:</strong> " << personalInfo[studentIndex].studentName << "</p>\n";
    challanFile << "<p><strong>Program:</strong> " << educationalInfo[studentIndex].program << "</p>\n";
    challanFile << "<p><strong>Semester:</strong> " << educationalInfo[studentIndex].semester << "</p>\n";
    challanFile << "<p><strong>Roll Number:</strong> " << studentIndex << "</p>\n";
    challanFile << "</div>\n";
    challanFile << "<div class='fees-section'>\n";
    challanFile << "<p><strong>Tuition Fees:</strong> Rs " << educationalInfo[studentIndex].tuitionFees << "</p>\n";
    challanFile << "<p><strong>Extra Charges:</strong> Rs " << educationalInfo[studentIndex].extraCharges << "</p>\n";
    challanFile << "<p><strong>Total Fees:</strong> Rs " << (educationalInfo[studentIndex].tuitionFees + educationalInfo[studentIndex].extraCharges) << "</p>\n";
    challanFile << "<p class='due-date'>Due Date: 25th December 2024</p>\n";
    challanFile << "</div>\n";
    challanFile << "<div class='footer'>\n";
    challanFile << "<p>Please pay the fees before the due date to avoid late charges.</p>\n";
    challanFile << "<p>&copy; 2024 Bahria University. All Rights Reserved.</p>\n";
    challanFile << "</div>\n";
    challanFile << "</div>\n";
    challanFile << "</body>\n</html>\n";

    challanFile.close();
    cout << "HTML file 'Challan.html' created successfully." << endl;


}



void adminPanel() {
    system("cls");

    int choiceAdmin;

    do {
        cout << "   #    ######  #     # ### #     #    #     # ####### #     # #     # " << endl;
        cout << "  # #   #     # ##   ##  #  ##    #    ##   ## #       ##    # #     # " << endl;
        cout << " #   #  #     # # # # #  #  # #   #    # # # # #       # #   # #     # " << endl;
        cout << "#     # #     # #  #  #  #  #  #  #    #  #  # #####   #  #  # #     # " << endl;
        cout << "####### #     # #     #  #  #   # #    #     # #       #   # # #     # " << endl;
        cout << "#     # #     # #     #  #  #    ##    #     # #       #    ## #     # " << endl;
        cout << "#     # ######  #     # ### #     #    #     # ####### #     #  #####  " << endl;
        cout << endl;
        cout << "1. Add New Student\n";
        cout << "2. Add New Teacher\n";
        cout << "3. Search Student\n";
        cout << "4. Generate Challan\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choiceAdmin;

        if (choiceAdmin == 1) {
            addNewStudent();
        }
        else if (choiceAdmin == 2) {
            addNewTeacher();
        }
        else if (choiceAdmin == 3) {
            searchStudent();
        }
        else if (choiceAdmin == 4) {
            generateChallanHTML();
        }
        else if (choiceAdmin == 5) {
            cout << "Returning to Main Menu..." << endl;
            return;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}




void login() {



    string username1, password1;
    char role;
    Pre_defined_variable();

    while (true) {  // Loop to allow multiple login attempts or exit

        system("cls");
        cout << "Are you a student, Teacher, or Admin (S, T, or A)?\n";
        cout << "Press 0 to Exit.\n";
        cout << "Enter your choice: ";
        cin >> role;

        if (role == '0') {  // Exit condition
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);  // Exit the program
        }

        system("cls");

        cout << "#       #######  #####  ### #     # " << endl;
        cout << "#       #     # #     #  #  ##    #" << endl;
        cout << "#       #     # #        #  # #   # " << endl;
        cout << "#       #     # #  ####  #  #  #  #" << endl;
        cout << "#       #     # #     #  #  #   # #" << endl;
        cout << "#       #     # #     #  #  #    ##" << endl;
        cout << "####### #######  #####  ### #     # " << endl;

        bool loginSuccessful = false;

        for (int i = 0; i < 3; i++) { // Allow three login attempts
            cout << "Username: ";
            cin >> username1;
            cout << "Password: ";
            cin >> password1;
            cout << endl;

            if (role == 'S' || role == 's') { // Student Login
                ifstream loginDetailsFile("loginDetails.txt", ios::in);
                if (loginDetailsFile) {  // Ensure the file exists
                    string fileUsername, filePassword;
                    int fileIndex = 0;

                    while (!loginDetailsFile.eof()) {  // Read file until the end
                        loginDetailsFile >> fileIndex;
                        loginDetailsFile >> fileUsername;
                        loginDetailsFile >> filePassword;

                        if (username1 == fileUsername && password1 == filePassword) {
                            studentLoginIndex = fileIndex;

                            student_menu();

                            loginSuccessful = true;
                            break;
                        }
                    }
                    loginDetailsFile.close();
                }
                else {
                    cout << "Login file not found. Unable to process login!" << endl;
                }
            }
            else if (role == 'T' || role == 't') { // Teacher Login
                for (int teacherLoginIndex = 0; teacherLoginIndex < indexTeacher; teacherLoginIndex++) {
                    if (username1 == teacherLog[teacherLoginIndex].username && password1 == teacherLog[teacherLoginIndex].password) {
                        cout << setfill('-') << setw(69) << "| WELCOME |" << setw(63) << '-' << endl << endl;
                        cout << setfill(' ');
                        loginSuccessful = true;
                        teacher_menu();
                        break;
                    }
                }
            }
            else if (role == 'A' || role == 'a') { // Admin Login
                if (username1 == "admin" && password1 == "admin") {
                    cout << setfill('-') << setw(69) << "| ADMIN WELCOME |" << setw(63) << '-' << endl << endl;
                    cout << setfill(' ');
                    loginSuccessful = true;
                    adminPanel();  // Call adminPanel function after successful login
                    break;
                }
                else {
                    cout << "Incorrect Admin credentials!" << endl;
                }
            }
            else {
                cout << "Invalid role selected!" << endl;
                return;
            }

            if (loginSuccessful) {
                break;
            }
            else {
                cout << setw(17) << "Try again" << endl << endl;
            }
        }

        if (!loginSuccessful) {
            cout << "Failed to log in after 3 attempts. Returning to main menu." << endl;
        }
        system("cls");
    }
}



// Main function
int main() {
    srand(time(0)); // Initialize random seed

    logo();

    loadStudentIndex(); // Load the current student index from the file
    login();

    system("pause");
    return 0;
}







