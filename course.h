#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Student;

class Course {
  friend class Student;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Course &course);

private:
  // values
  set<int> students;
  string title;
  string ID;

  // Change the title of the course
  // Returns true if successful
  bool setTitle(string title);

  // returns title
  string getTitle();

  // returns the list of students,
  // organized alphabetically by last name
  // seperated by commas
  string getClassListByLastName() const;

  // returns the list of students,
  // organized numerically by studentID
  // seperated by commas
  string getClassListByID() const;

  // adds studentID to the set of students
  // does not add courseID to the student object
  // returns true if successful
  bool addStudent(int studentID);

  // removes studentID from the set of students
  // does not remove courseID from the student object
  // returns true if successful
  bool dropStudent(int studentID);

  // returns true if studentID is in the set of students
  bool isInCourse(int studentID);

public:
  explicit Course(string courseID, string title);
  // No copy constructor needed
  ~Course();
};

#endif