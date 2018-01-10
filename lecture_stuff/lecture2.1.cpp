#include <iostream>
#include <thread>
#include <chrono>

class Time {
 public:
  Time();
  Time(int hours, int minutes);

  int get_hours() const;
  int get_minutes() const;
  void add_minute();
  void add_minutes(int n);
  
  void operator++(); // Prefix ++Time
  void operator++(int unused); // Postfix Time++
  bool operator==(Time t);

 private:
  int hours;
  int minutes;
};

Time::Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

int Time::get_hours() const { return hours; }

int Time::get_minutes() const { return minutes; }

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

void Time::operator++() {
    this->add_minute();
}

void Time::operator++(int unused) {
    this->add_minute();
}

bool Time::operator==(Time t) {
    if (this->minutes != t.get_minutes()) {
        return false;
    }

    if (this->hours != t.get_hours()) {
        return false;
    }

    return true;
}

int main() {
    Time clock = Time(12, 0);
    Time clock2 = clock;
    
    for (int i = 1; i <= 75; i++) {
        std::this_thread::sleep_for (std::chrono::seconds(1000));
        clock2++;
    }

    if (clock2 == Time(1, 15)) {
        std::cout << "Class dismissed." << '\n';
    }
    
  return 0;
}