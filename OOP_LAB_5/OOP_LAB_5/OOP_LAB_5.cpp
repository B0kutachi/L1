#include "Book.h"
#include "Route.h"
#include "Time_Flight.h"
#include "Music.h"
#include "GeometricProgram.h"
#include "Teacher.h"
#include "Users.h"
#include "Product.h"
#include "Stuff.h"

GeometricProgram GProgram;

// Метод принимает массив всех зарегистрированных бесплатных пользователей,
// ищет пользователя с введенным именем и паролем.
// Если такого пользователя нет, возвращается nullptr.
// Если пользователь есть, но пароль не подошел, то генерируется исключение.
User* Login(User** users, int usersCount, string enteredLogin, string enteredPassword) {
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->GetLogin() == enteredLogin) {
			if (users[i]->IsCorrectPassword(enteredPassword))
			{
				return users[i];
			}
			else
			{
				throw exception("Uncorrect password");
			}
		}
	}
	return nullptr;
}

static void Breakpoints1()
{
	DemoBook();
}

static void Breakpoints2()
{
	DemoRoute();
}

static void Breakpoints3()
{
	GProgram.DemoRectangleWithPoint();
}

static void Breakpoints4()
{
	DemoFlightWithTime();

	cout << endl << endl;
	Flight flight;
	FlightBuild(flight);
}

static void Breakpoints5()
{
	DemoBand();
}

static void Breakpoints6()
{
	GProgram.DemoRing();
}

static void Breakpoints7()
{
	GProgram.DemoCollision();
}

static void Breakpoints8()
{
	Person* person1 = new Person("Egorov", "Egor", "Egorovich");
	cout << "\nPerson: ";
	person1->ShowName(person1);

	Student* student1 = new Student("Dmitriev", "Dima", "Dmitrievich", 10000, 2020);
	cout << "\nStudent: ";
	student1->ShowName(student1);

	Teacher* teacher1 = new Teacher("Antonov", "Anton", "Antonovich", "director");
	cout << "\nTeacher: ";
	teacher1->ShowName(teacher1);

	delete person1; person1 = nullptr;
	delete student1; student1 = nullptr;
	delete teacher1; teacher1 = nullptr;
}

static void Breakpoints9()
{
	User** users = new User * [8]
		{
			new User(100000, "morkovka1995", "1995morkovka"),
				new User(100001, "ilon_mask", "X æ A-12"),
				new User(100002, "megazver", "password"),
				new User(100003, "yogurt", "ksTPQzSu"),
				new PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
				new PaidUser(200001, "system_exe", "UgfkDGmU"),
				new PaidUser(200002, "RazorQ", "TBgRnbCP"),
				new PaidUser(200003, "schdub", "CetyQVID")
		};
	string login = "megazver";
	string password = "password";
	User* loginedUser = Login(users, 8, login, password);
	cout << "Signed in as: " << loginedUser->GetLogin() << endl;

	login = "system_exe";
	password = "UgfkDGmU";
	User* loginedPaidUser = Login(users, 8, login, password);
	cout << "Signed in as: " << loginedPaidUser->GetLogin() << endl;

	for (int i = 0; i < 8; i++)
	{
		delete users[i];
	}
	delete[] users;
}

void Breakpoints10()
{
	Product* products = new Product[4];
	products[0] = Product("TV LG49N000", TV, 40000);
	products[1] = Product("Micromax Q1", Micromax, 2000);
	products[2] = Product("Pantum M650", Pantum, 8000);
	products[3] = Product("HP LasetJet", HP, 11000);

	PercentDiscount pd1(TV, 25);
	CertificateDiscount cd1(Micromax, 500);
	PercentDiscount pd2(HP, 10);
	CertificateDiscount cd2(Pantum, 2000);

	ShowCheckWithDiscount(&pd1, &products[0], 1);
	cout << endl;
	ShowCheckWithDiscount(&cd1, &products[1], 1);
	cout << endl;
	ShowCheckWithDiscount(&pd2, &products[2], 1);
	cout << endl;
	ShowCheckWithDiscount(&cd2, &products[3], 1);

	//DiscountBase disbase;		// проверка того, что нельзя создавать объект абстрактного класса

	delete[] products;
}

void Breakpoints11()
{
	cout << "\nSalary of the teacher: ";
	Teacher1 teacher;
	teacher.setSalary(180);
	teacher.CalculateSalary(168);

	cout << endl << "\nSalary of the master teacher: ";
	MasterTeacher1 mteacher;
	mteacher.setSalary(180);
	mteacher.CalculateSalary(168);
}


int main()
{
	int x = 0;
	cout << "\nEnter the case: ";
	cin >> x;
	switch (x) {
	case 1:
		Breakpoints1();
		break;
	case 2:
		Breakpoints2();
		break;
	case 3:
		Breakpoints3();
		break;
	case 4:
		Breakpoints4();
		break;
	case 5:
		Breakpoints5(); 
		break;
	case 6:
		Breakpoints6(); 
		break;
	case 7:
		Breakpoints7(); // Tasks 4.5.1 - 4.5.7
		break;
	case 8:
		Breakpoints8(); 
		break;
	case 9:
		Breakpoints9();
		break;
	case 10:
		Breakpoints10();
		break;
	case 11:
		Breakpoints11();
		break;
	default:
		cout << "Invalid value. Try again.";
	}
	cout << endl << endl;
	return 0;
}

