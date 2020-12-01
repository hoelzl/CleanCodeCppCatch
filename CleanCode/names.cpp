#include <iostream>
#include <string>
#include <vector>

class BadNames1 {
    std::vector<std::pair<int, int>> theList;

    std::vector<std::pair<int, int>> getThem()
    {
        std::vector<std::pair<int, int>> list1 {};
        for (std::pair<int, int> x : theList) {
            if (x.first == 4) {
                list1.push_back(x);
            }
        }
    }
};

class MineSweeper {
    enum class Status { Flagged,
        Unflagged };
    struct Cell {
        Status status { Status::Flagged };
        int bomb_count { 0 };
    };

    std::vector<Cell> game_board;

    std::vector<Cell> getFlaggedCells()
    {
        std::vector<Cell> flagged_cells {};
        for (Cell cell : game_board) {
            if (cell.status == Status::Flagged) {
                flagged_cells.push_back(cell);
            }
        }
        return flagged_cells;
    }
};

class BdNms3 {
    int ts_yymmdd;
};

class BadNames4 {
    int unix_timestamp;
};

const int INCLUDE_NONE = 0;
const int INCLUDE_FIRST = 1;
const int INCLUDE_SECOND = 2;
const int INCLUDE_BOTH = 3;

const int INCLUDE_NO_DATE = 0;
const int INCLUDE_START_DATE = 1;
const int INCLUDE_END_DATE = 2;
const int INCLUDE_BOTH_DATES = 3;

int MY_CONTROLLER_FOR_EFFICIENT_HANDLING_OF_STRINGS = 1;
int MY_CONTROLLER_FOR_EFFICIENT_STORING_OF_STRINGS = 2;

// Consistent

class ObjectManager;
class ObjectController;

// Disinformation

class Pair {
    int first;
    int second;
    int third;
};

class Triple {
    int first;
    int second;
    int third;
};

class CalenderDate;
class SerializableDate;

class SerialDate {
    virtual int toSerial() = 0;
    // ...
};

class UnixDate : public SerialDate {
    int unix_timestamp { 0 };
    int toSerial() override
    {
        return unix_timestamp; // Unix timestamp
    }
};

void copy(char a1[], char a2[])
{
    while (*(a2++) = *(a1++))
        ;
}

void copy_2(char from[], char to[])
{
    while (*(to++) = *(from++))
        ;
}

int* pi_target;
int* target;

class IActor {
};
class Actor : public IActor {
};

class Actor2 {
};
class ActorImpl : public Actor2 {
};

class File {
    bool is_open() const { return true; }
};

// Wrong part of speech
class GoToTheServer {
    void connection() { }
    bool server_availability() { return false; }
};

class ServerConnection {
    void connect() { }
    bool is_server_available() { return false; }
};

// Functions

int my_fun(int a, int b)
{
    int c { 0 };
    int d { 0 };
    // Do something complex
    // Do something else
    return 0;
}

class MyFun {
    int a;
    int b;
    int c { 0 };
    int d { 0 };

public:
    MyFun(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void do_something_complex() { }
    void do_something_else() { }

    int compute()
    {
        do_something_complex();
        do_something_else();
        return 0;
    }
};

void f()
{
    int i { my_fun(1, 2) };

    MyFun my_new_fun { 1, 2 };
    int j { my_new_fun.compute() };
}

class Employee {
    virtual int calculate_pay(const std::string& name) = 0;
};

class CommissionedEmployee : public Employee {
    int calculate_pay(const std::string& name) override
    {
        return 4500;
    }
};

class HourlyEmployee : public Employee {
    int calculate_pay(const std::string& name) override
    {
        return 1500;
    }
};

Employee* makeEmployee(int id)
{
    if (id < 100) {
        return new CommissionedEmployee();
    } else {
        return new HourlyEmployee();
    }
}

int my_long_arglist_function(int a, int b, int c);
int my_long_arglist_function_2(float x, int a, int b, int c);

struct GridPosition {
    int a;
    int b;
    int c;
};

int my_long_arglist_function(GridPosition g);
int my_long_arglist_function_2(float x, GridPosition g);

int print_text(std::string text, bool should_print_header = false)
{
    if (should_print_header) {
        std::cout << "Header" << std::endl;
    }
    std::cout << text << std::endl;
    return 0;
}

int print_text_without_header(std::string text)
{
    std::cout << text << std::endl;
    return 0;
}

int print_text_with_header(std::string text)
{
    std::cout << "Header" << std::endl;
    std::cout << text << std::endl;

    return 0;
}
