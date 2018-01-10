#include <iostream>

class Time {
 public:
  Time();
  Time(int hours, int minutes);

  int get_hours() const;
  int get_minutes() const;
  void add_minute();
  void add_minutes(int n);

  Time &operator++();           // Prefix
  Time operator++(int unused);  // Postfix

 private:
  int hours;
  int minutes;
};

Time::Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

int Time::get_hours() const { return hours; }

int Time::get_minutes() const { return minutes; }

bool operator==(const Time &left, const Time &right);

void Time::add_minute() {
  minutes++;

  if (minutes == 60) {
    minutes = 0;
    hours++;
  }

  if (hours == 13) {
    hours = 1;
  }
}

void Time::add_minutes(int n) {
  for (int i = 0; i < n; i++) {
    this->add_minute();
  }
}

bool operator==(const Time &left, const Time &right) {
  if (left.get_hours() != right.get_hours()) {
    return false;
  }

  if (left.get_minutes() != right.get_minutes()) {
    return false;
  }

  return true;
}

Time &Time::operator++() {
  this->add_minute();
  return *this;
}

Time Time::operator++(int unused) {
  Time clone(hours, minutes);
  clone.add_minute(); 
  return clone;
}

int main() {
  // Time clock = Time(12, 0);
  // clock.add_minutes(75);

  Time start = Time(12, 0);
  Time end = Time(1, 15);
  start.add_minutes(75);

  std::cout << start.get_hours() << ":" << start.get_minutes() << '\n';

  if (start == end) {
    std::cout << "Class dismissed." << '\n';
  }
  ++start;

  std::cout << start.get_hours() << ":" << start.get_minutes() << '\n';

  start++;

  std::cout << start.get_hours() << ":" << start.get_minutes() << '\n';

  return 0;
}