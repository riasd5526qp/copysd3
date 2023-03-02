#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Course;

class Student {
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;
  friend ostream &operator<<(ostream &out, const Student &student);

private:
  set<string> courses;
  string lastName;
  string firstName;
  int ID;

  // Only removes the string from the set of courses,
  // does not remove the studentID from the course object
  bool dropCourse(const string &courseNumber);

  // Only add the string to the set of courses,
  // does not add the studentID to the course object
  bool addCourse(const string &courseNumber);

  // Only checks if the string is in the set of courses
  // Does not check if the studentID is present in the course object
  bool isInCourse(const string &courseNumber) const;

  // Returns every element in the student's courses set
  // seperated by a comma ", "
  string getEnrolledCourses() const;

  // Returns name of the student, first last
  string getStudentName();

public:
  explicit Student(int studentID, string firstName, string lastName);
  // No need for copy constructor
  ~Student();
};

#endif