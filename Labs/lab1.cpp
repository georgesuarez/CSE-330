#include <unistd.h>
#include <iostream>

class Time {
 public:
  Time(int h, int m);
  int gethours() const;
  int getminutes() const;
  void addminute();
  void subtractminute();
  bool operator==(Time t);
  void operator++();     // prefix
  void operator++(int);  // postfix
  void operator--();     // prefix
  void operator--(int);  // postfix
 private:
  int hours;
  int minutes;
};

Time::Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

int Time::gethours() const { return hours; }

int Time::getminutes() const { return minutes; }

bool Time::operator==(Time t) {
  if (this->gethours() != t.gethours()) return false;
  if (this->getminutes() != t.getminutes()) return false;
  return true;
}

void Time::operator++() { this->addminute(); }

void Time::operator++(int) { this->addminute(); }

void Time::operator--() { this->subtractminute(); }

void Time::operator--(int) { this->subtractminute(); }

void Time::addminute() {
  minutes++;
  if (minutes == 60) {
    minutes = 0;
    hours++;
  }
  if (hours == 13) hours = 1;
}

void Time::subtractminute() {
  minutes--;
  if (minutes == 0) {
    minutes = 59;
    hours--;
  }

  if (hours == 0) hours = 1;
}

int main() {
  Time start = Time(12, 0);
  Time end = Time(1, 15);

  for (int i = 0; i < 75; i++) {
    sleep(60); // sleep for 60 seconds
    end--;  
  }

  if (start == end) {
    std::cout << "Class dismissed." << '\n';
  }
}