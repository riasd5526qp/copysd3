Overview
The design for a University enrollment system. The system allows students to enroll in courses, drop courses, and view their enrolled courses. The system also allows different university to manage courses and student, view class lists, and perform other administrative functions.

Descriptions
The system includes four main classes: EnrollmentSystem, University, Course, and Student

EnrollmentSystem:
The EnrollmentSystem class is responsible for managing the overall system. It contains functions to create University, set current University where you are working on. It also contains functions to create courses and students, add and remove students from courses, and view course and student information. It also contains functions to read enrollment, course, or student files that are given.

University:
The University class represents the entire university. It contains a name and maps of students and courses for this University. Functions in this class allow the university to create, add and remove students from courses. Also view course and student information. It also contains functions to generate class lists.

Student:
The Student class represents a single student. It contains a name, student ID, and a set of courses this student is enrolled in. Functions in this class allow a student to drop or add courses and view their enrolled courses.

Course:
The Course class represents a single course. It contains a course ID, title about this Course, and a set of students enrolled in the course. Functions in this class allow a course to be updated with a new title, view the list of enrolled students. 

Header Files
The following header files should be included in the system:

EnrollmentSystem.h: This file should contain the EnrollmentSystem class definition.
University.h: This file should contain the University class definition.
Student.h: This file should contain the Student class definition.
Course.h: This file should contain the Course class definition.
Explanation of Functions
readCourseList: 
For each line in the given file, will call currentUniversity->addToCatalog, which itself will call the Course constructor with each course being placed on the heap immediately after construction, the course object’s pointer will be placed into the “courses” map, with the string “courseID” being the string used for mapping.

readEnrollmentInfo: 
For each line in the given file, will call currentUniversity->addCourse(studentID, courseID), which will itself return ( Student::addCourse(courseID) and Course::addStudent(studentID) ). Each of these will add their respective variables to the set of the object they are called in. All functions mentioned to this point are booleans that return true if successful. At the end of each addition, the sets will be sorted: Student::courses by courseID, and Course::students by studentID.

addCourse:
Will return currentUniversity->addCourse(studentID, courseID), which will work as described above and return true if successful.

getEnrolledCourses: 
Will return currentUniversity->getEnrolledCourses(studentID), which will return Student::getEnrolledCourses(), which will return a string containing all of the elements of the set Student::courses separated by a comma. The set will already be sorted by courseID, so there is no need to sort in this string of function calls.


getClassListByName:
Will return currentUniversity->getClassListByName(studentID), which will return Course::getClassListByName(), which will call the sort function on Course::students to sort it by Student::LastName. It will then store the ordered strings, separated by commas into one string for returning later. Finally, it will sort Course::students by studentID (how it should be default sorted), and then return the stored string that was created while it was sorted by last name.
