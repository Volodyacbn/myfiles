
#include <iostream>
using namespace std;

struct Course {
    char name[100];
    int lvl;
    int dur;
    double price;
};

void printOutCourse(Course Courses[], int index) {
    cout << "Курс " << index + 1 << " {\n";

    cout << "Назва курсу: " << Courses[index].name << "\n";
    cout << "Рiвень курсу: " << Courses[index].lvl << "\n";
    cout << "Тривалiсть курсу: " << Courses[index].dur << "\n";
    cout << "Цiна курсу: " << Courses[index].price << "}\n\n";

    cout << "\n";
}

void printOutCourses(Course Courses[], int amount) {
    cout << "Вивiд ->\n\n";

    for (int i = 0; i < amount; i++) {
        printOutCourse(Courses, i);
    }

    cout << "<-";


    cout << "\n";
}

void initiateCourses(Course Courses[], int amount) {
    cout << "\n";

    for (int i = 0; i < amount; i++) {
        cout << "Курс " << i+1 <<"\n \n";

        cout << "Введiть назву курсу: ";
        cin >> Courses[i].name;

        cout << "Введiть уровень курсу: ";
        cin >> Courses[i].lvl;

        cout << "Введiть тривалiсть курсу: ";
        cin >> Courses[i].dur;

        cout << "Введiть цiну курсу: ";
        cin >> Courses[i].price;

        cout << "\n";
;    }

    cout << "\n";

    printOutCourses(Courses, amount);
}

void searchByLVL(Course Courses[], int amount, int lvl) {
    bool found = false;

    for (int i = 0; i < amount; i++) {
        if (Courses[i].lvl == lvl) {
            printOutCourse(Courses, i);
            found = true;
        }
    }

    if (!found) {
        cout << "\nне знайдено\n";
    }
}

double getAvgPrice(Course Courses[], int amount) {
    int summary = 0;

    for (int i = 0; i < amount; i++) {
        summary += Courses[i].price;
    }

    return summary / amount;
}

void sortByPrice(Course Courses[], int amount, bool descending) {
    for (int i = 0; i < amount - 1; i++) {
        if (Courses[i + 1].price < Courses[i].price and descending) {
            Course s = Courses[i];

            Courses[i] = Courses[i+1];
            Courses[i + 1] = s;

            sortByPrice(Courses, amount, descending);

            break;
        }
        
        if (Courses[i + 1].price > Courses[i].price and !descending) {
            Course s = Courses[i];

            Courses[i] = Courses[i + 1];
            Courses[i + 1] = s;

            sortByPrice(Courses, amount, descending);

            break;
        }
    }
}

void longestCourses(Course Courses[], int amount) {
    int maxDur = Courses[0].dur;
    int maxI = 0;

    for (int i = 1; i < amount; i++) {
        if (Courses[i].dur > maxDur) {
            maxDur = Courses[i].dur;
            maxI = i;
        }
    }

    cout << "Найдовшi курси: \n\n";

    printOutCourse(Courses, maxI);

    cout << "\n\n";
}

void startOptions(Course Courses[], int amount) {
    cout << "Виберiть що ви хочете зробити з курсами\n\n" << "1: Знайти курс за допомогую рiвня |\n 2: Обчислити середню вартiсть курсiв |\n 3: Вивести найдовший курси |\n 4: Сортирування по цiнi |\n 0: Закiнчити\n\n";

    cout << "Введiть цифру: ";

    int choose;
    cin >> choose;

    if (choose == 0) {
        return;
    }

    cout << "\n\nВивiд ->\n\n";

    cout << "\n";

    if (choose == 1) {
        int targetLVL;

        cout << "Введiть рiвень курсу який хочете знайти: ";
        cin >> targetLVL;

        cout << "\n";

        searchByLVL(Courses, amount, targetLVL);
    }

    if (choose == 2) {
        double avgPrice = getAvgPrice(Courses, amount);

        cout << "\n\nСередня вартiсть курсiв: " << avgPrice << "\n\n";
    }

    if (choose == 3) {
        longestCourses(Courses, amount);
    }

    if (choose == 4) {
        bool descending = false;
        
        cout << "\n\nСпадаюча? 1 - так , 0 - нi";
        
        cout << "\n\nВиберiть цифру: ";
        
        cin >> descending;
        cout << "\n\n";
        
        sortByPrice(Courses, amount, descending);

        printOutCourses(Courses, amount);
    }

    cout << "\n\n<- \n\n\n\n";

    startOptions(Courses, amount);
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    Course Courses[100];

    int courses_Amount;

    cout << "Введiть кiлькiсть курсiв: ";
    cin >> courses_Amount;

    initiateCourses(Courses, courses_Amount);

    startOptions(Courses, courses_Amount);
}
