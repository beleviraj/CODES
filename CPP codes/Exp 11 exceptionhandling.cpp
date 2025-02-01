#include <iostream>
#include <stdexcept>
#include <string>

class date 
{
public:
	int day;
    int month;
    int year;
    
    date(int day, int month, int year) : day(day), month(month), year(year) {}

    void validatedate() 
	{
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
            throw std::invalid_argument("invalid date!");
        }
    }
};

class person 
{
private:
    std::string name;
    date birthdate;

public:
    person(const std::string& name, const date& birthdate) : name(name), birthdate(birthdate) {}

    void printinfo() const 
	{
        std::cout << "name: " << name << std::endl;
        std::cout << "birth date: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << std::endl;
    }
};

int main() 
{
    try
	{
        date birthdate(30, 2, 2000);
        birthdate.validatedate();

        person person("Avani", birthdate);
        person.printinfo();
    } catch (const std::exception& ex) 
	{
        std::cout << "exception: " << ex.what() << std::endl;
    }

    return 0;
}
