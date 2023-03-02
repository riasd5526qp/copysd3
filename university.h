#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <string>
#include <unordered_map>

using namespace std;

class University {
  friend class EnrollmentSystem;
  friend class Course;
  friend class Student;

private:
  string name;
  unordered_map<int, Student *> students;
  unordered_map<string, Course *> courses;

  // Creates the course object, then
  // adds the course to the university catalog,
  // returns true if successful
  bool addToCatalog(string courseID, string description);

  // returns true if the course is already in the university catalog
  bool isInCatalog(string courseID);

  // Creates the student object, then
  // adds student to the university list,
  // returns true if successful
  bool addToStudentlist(int studentID, string name);

  // returns true if the student is already in the university list
  bool isInStudentList(int studentID);

  // Drop student from given course, return true if successful
  // Must remove the course from the student's list
  // AND remove the student from the course's list
  // returns true if successful
  bool dropCourse(int studentID, const string &courseNumber);

  // Add student to the given course, return true if successful
  // Must add the course to the student's list
  // AND add the student to the course's list
  // returns true if successful
  bool addCourse(int studentID, const string &courseNumber);

  // Return true if student is in the given course
  // Must check that the student is in the course list
  // AND check that the course is in the student list
  bool isInCourse(int studentID, const string &courseNumber) const;

  // Return the courses student is enrolled in
  // The returned courses are separated by commas and sorted by course name
  string getEnrolledCourses(int studentID) const;

  // Return the title for the course
  string getCourseTitle(const string &courseNumber);

  // Return class list sorted by last name of students
  string getClassListByLastName(const string &courseNumber) const;

  // Return class list sorted by id of students
  string getClassListByID(const string &courseNumber) const;

public:
  explicit University(string name);
  // No need for copy constructor
  ~University();
};

#endif