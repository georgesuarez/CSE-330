#include <unistd.h>
#include <iostream>

class Time
{
public:
  Time(int h, int m);
  int get_hours() const;
  int get_minutes() const;
  void add_minute();
  void minus_minute();
  bool operator==(Time t);
  void operator++();    // prefix
  void operator++(int); // postfix
  void operator--();    // prefix
  void operator--(int); // postfix
private:
  int hours;
  int minutes;
};

Time::Time(int hours, int minutes) : hours(hours), minutes(minutes) {}

int Time::get_hours() const { return hours; }

int Time::get_minutes() const { return minutes; }

bool Time::operator==(Time t)
{
  if (this->get_hours() != t.get_hours())
    return false;
  if (this->get_minutes() != t.get_minutes())
    return false;
  return true;
}

void Time::operator++() { this->add_minute(); }

void Time::operator++(int) { this->add_minute(); }

void Time::operator--() { this->minus_minute(); }

void Time::operator--(int) { this->minus_minute(); }

void Time::add_minute()
{
  minutes++;
  if (minutes == 60)
  {
    minutes = 0;
    hours++;
  }
  if (hours == 13)
    hours = 1;
}

void Time::minus_minute()
{
  minutes--;
  if (minutes == -1)
  {
    minutes = 59;
    hours--;
  }

  if (hours == 0)
    hours = 12;
}

int main()
{
  Time start = Time(12, 0);
  Time end = Time(1, 15);

  for (int i = 0; i < 75; i++)
  {
    sleep(60);
    end--;
  }

  if (start == end)
  {
    std::cout << "Class dismissed." << '\n';
  }
}