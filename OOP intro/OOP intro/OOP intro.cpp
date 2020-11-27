#include <iostream>
#include <string>
#include <cstring>
#include<iomanip>
using namespace std;

class Student
{
public:
	class DateOfBirth
	{
		static const size_t CURR_YEAR = 2020;
		bool isLeap(size_t year)
		{
			return year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // 1700 not leap, 1600 - leap, 1992
		}
	public:
		void setMonth(const size_t& month_)
		{
			if (month_ >= 1 && month_ <= 12)
			{
				month = month_;
			}
		}
		void setYear(const size_t year_)
		{
			if (year_ < CURR_YEAR - 14)
			{
				year = year_;
			}
		}
		void setDay(size_t day_)
		{
			size_t dayInMonth[]{ 31,28,31,30,31,30,30,31,30,31,30,31 };
			if (day >= 1 && day <= dayInMonth[month - 1])
			{
				day = day_;
			}
			else if (month == 2 && day_ == 29 && isLeap(year))
			{
				day = day_;
			}

		}
		void print(int length)
		{
			cout << "Birthday: " << setw(length) << day << "/" << month << "/" << year << endl;
		}
		void input()
		{
			cout << "Enter date of your birth. Year : ";
			cin >> year;
			cout << "Enter month : ";
			cin >> month;
			cout << "Enter day : ";
			cin >> day;
		}

	private:
		size_t day = 1, month = 1, year = 2000;
	};
	static const size_t maxAge = 120;
	void print() {
		cout << "Thats the information that you have entered :" << endl;
		cout << "Name: " << setw(maxLengthOfAllStrings + 15) << name << endl;
		cout << "Surname: " << setw(maxLengthOfAllStrings + 12) << surname << endl;
		birth.print((int)maxLengthOfAllStrings + 4);
		cout << "Phone: " << setw(maxLengthOfAllStrings + 14) << phone << endl;
		cout << "City: " << setw(maxLengthOfAllStrings + 15) << city << endl;
		cout << "Country: " << setw(maxLengthOfAllStrings + 12) << country << endl;
		cout << "Univercity: " << setw(maxLengthOfAllStrings + 9) << university << endl;
		cout << "Univercity city: " << setw(maxLengthOfAllStrings + 4) << cityUniversity << endl;
		cout << "Univercity country: " << setw(maxLengthOfAllStrings + 1) << countryUniversity << endl;
		cout << "Group number: " << setw(maxLengthOfAllStrings + 7) << groupNumber << endl;
	}
	void setName(const string& newName)
	{
		if (!newName.empty()) {
			name = newName;
		}
	}
	const string& getName() const
	{
		return name;
	}
	void setSurname(const string& newSurname)
	{
		if (!newSurname.empty()) {
			surname = newSurname;
		}
	}
	const string& getSurname() const
	{
		return surname;
	}
	void setPhone(const string& newPhone)
	{
		if (!newPhone.empty()) {
			const char* stringToChar = newPhone.c_str(); // < - I googled this.
			int digitsInString = 0;
			for (size_t i = 0; i < newPhone.length(); i++)
			{
				if (isdigit(stringToChar[i]))
					digitsInString++;
			}
			if (digitsInString == newPhone.length())
			{
				if (stod(newPhone) > 100000000 && stod(newPhone) < 1000000000000)
				{
					phone = newPhone;
					maxLengthOfAllStrings = (maxLengthOfAllStrings < phone.length()) ? phone.length() : maxLengthOfAllStrings;
				}
				else
					cout << "Not correct phone format (from 9 to 12 digits only)" << endl;
			}
			else
				cout << "Not correct phone format (from 9 to 12 digits only)" << endl;
			//	delete [] stringToChar; <-cant delete .c_str(), string will control livelong of itself
		}
	}
	const string& getPhone() const
	{
		return phone;
	}
	void setCity(const string& newCity)
	{
		if (!newCity.empty()) {
			city = newCity;
		}
	}
	const string& getCity() const
	{
		return city;
	}
	void setCountry(const string& newCountry)
	{
		if (!newCountry.empty()) {
			country = newCountry;
		}
	}
	const string& getCountry() const
	{
		return country;
	}
	void setUniversity(const string& newUniversity)
	{
		if (!newUniversity.empty()) {
			university = newUniversity;
		}
	}
	const string& getUnivercity() const
	{
		return university;
	}
	void setCityUniversity(const string& newCityUniversity)
	{
		if (!newCityUniversity.empty()) {
			cityUniversity = newCityUniversity;
		}
	}
	const string& getCityUniversity() const
	{
		return cityUniversity;
	}
	void setCountryUniversity(const string& newCountryUniversity)
	{
		if (!newCountryUniversity.empty()) {
			countryUniversity = newCountryUniversity;
		}
	}
	const string& getCountryUniversity() const
	{
		return countryUniversity;
	}
	void setGroupNumber(const string& newGroupNumber)
	{
		if (!newGroupNumber.empty()) {
			groupNumber = newGroupNumber;
		}
	}
	const string& getGroupNumber() const
	{
		return groupNumber;
	}
	void setBirth(const DateOfBirth& birth) {
		this->birth = birth;
	}
	void checkPhone(const string& newPhone) {

	}
	void input() {
		cout << "Please enter your information carefully :" << endl;
		cout << "Enter your name: ";
		cin >> name;
		maxLengthOfAllStrings = name.length();
		cout << "Enter your surname: ";
		cin >> surname;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < surname.length()) ? surname.length() : maxLengthOfAllStrings;
		birth.input();
		string newPhone;
		cout << "Enter your phone: ";
		cin >> newPhone;
		setPhone(newPhone);
		cout << "Enter your city: ";
		cin >> city;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < city.length()) ? city.length() : maxLengthOfAllStrings;
		cout << "Enter your country: ";
		cin >> country;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < country.length()) ? country.length() : maxLengthOfAllStrings;
		cout << "Enter your university name: ";
		cin >> university;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < university.length()) ? university.length() : maxLengthOfAllStrings;
		cout << "Enter your university city: ";
		cin >> cityUniversity;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < cityUniversity.length()) ? cityUniversity.length() : maxLengthOfAllStrings;
		cout << "Enter your university country: ";
		cin >> countryUniversity;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < countryUniversity.length()) ? countryUniversity.length() : maxLengthOfAllStrings;
		cout << "Enter your group number: ";
		cin >> groupNumber;
		maxLengthOfAllStrings = (maxLengthOfAllStrings < groupNumber.length()) ? groupNumber.length() : maxLengthOfAllStrings;
	}
	long long maxLengthOfAllStrings = 0;
private: //incapsulation
	string name = "NoName";
	string surname = "NoSurname";
	DateOfBirth birth;
	string phone = "0000000000";
	string city = "NoNameCity";
	string country = "NoNameCountry";
	string university = "NoNameUnivercity";
	string cityUniversity = "NoNameCity";
	string countryUniversity = "NoNameCountry";
	string groupNumber = "NoGroup";
};



int main() {
	Student student;
	student.input();
	student.print();
	return 0;
}