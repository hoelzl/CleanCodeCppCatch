// ReSharper disable IdentifierTypo
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppClangTidyModernizeUseNodiscard
// ReSharper disable CppClangTidyClangDiagnosticUnusedPrivateField
#include <iostream>
#include <string>
#include <vector>

// Bad names and inappropriate data types
// See the end of the file for an improved version.
class BadNames1
{
    std::vector<std::pair<int, int>> the_list;

    std::vector<std::pair<int, int>> get_them() const
    {
        std::vector<std::pair<int, int>> list1{};
        for (std::pair<int, int> x : the_list) {
            if (x.first == 4) {
                list1.push_back(x);
            }
        }
        return list1;
    }
};

class BdNms3
{
    int ts_yymmdd{};
};

// BdNms3 improved:
class BadNames3
{
    int unix_timestamp{};
};

// Not intention revealing, problem not implementation
constexpr int INCLUDE_NONE = 0;
constexpr int INCLUDE_FIRST = 1;
constexpr int INCLUDE_SECOND = 2;
constexpr int INCLUDE_BOTH = 3;

// Closer to problem
constexpr int INCLUDE_NO_DATE = 0;
constexpr int INCLUDE_START_DATE = 1;
constexpr int INCLUDE_END_DATE = 2;
constexpr int INCLUDE_BOTH_DATES = 3;

// Compute the yearly salary
// double salary{add_array_elements(monthly_salaries)};

// Disinformation: name doesn't mean what is says
struct Pair
{
    int first{};
    int second{};
    int third{};
};

struct Triple
{
    int first{};
    int second{};
    int third{};
};

// Disinformation: names differ only slightly
constexpr int MY_CONTROLLER_FOR_EFFICIENT_HANDLING_OF_STRINGS = 1;
constexpr int MY_CONTROLLER_FOR_EFFICIENT_STORING_OF_STRINGS = 2;

// Hungarian notation
const int* pi_target;
const int* target;

// Prefixes
class IActor
{};
class Actor : public IActor
{};

class Actor2
{};
class ActorImpl : public Actor2
{};

// Wrong parts of speech
class GoToTheServer
{
    void connection() {}
    bool server_availability() { return false; }
};

class ServerConnection
{
    void connect() {}
    bool is_server_available() { return false; }
};


// Inconsistent names, noisy
class ObjectManager;
class ObjectController;
class DataController;
class ObjCtrlr;

// Not intention revealing
class SerialDate
{
    virtual int to_serial() = 0;
    // ...
};

// Implementation, not problem
class UnixDate : public SerialDate
{
    int unix_timestamp{0};
    int to_serial() override
    {
        return unix_timestamp; // Unix timestamp
    }
};

class CalenderDate;
class SerializableDate;


// Wrong part of speech: this is supposed to be a file, not a function that wraps a file
// handle
class WrapFileHandle
{
    // Wrong part of speech, could be expressed in code
    // Does not change the state of the file.
    bool open() { return true; }
};

class File
{
    bool is_open() const { return true; }
};


// Functions

// Not intention revealing, could be expressed in code
void copy(char a1[], char a2[])
{
    while ((*(a2++) = *(a1++))) {}
}

void copy_2(char from[], char to[])
{
    while ((*(to++) = *(from++))) {}
}

void copy_3(const char from[], char to[])
{
    while ((*(to++) = *(from++))) {}
}

// Refactoring into classes
int my_fun(int a, int b)
{
    // Do something complex
    int c{a + b};
    // Work some more
    int d{0};
    // Do something else
    return 0;
}

class MyFun
{
    int a;
    int b;
    int c{a + b};
    int d{0};

public:
    MyFun(int a, int b) : a{a}, b{b} {}

    void do_something_complex() {}
    void work_some_more() {}
    void do_something_else() {}

    int compute()
    {
        do_something_complex();
        work_some_more();
        do_something_else();
        return 0;
    }
};

void f()
{
    int i{my_fun(1, 2)};

    MyFun my_new_fun{1, 2};
    int j{my_new_fun.compute()};
}

// Long argument lists
void my_long_arglist_function(int a, int b, int c) {}
void my_long_arglist_function_2(float x, int a, int b, int c) {}

struct GridPosition
{
    int a;
    int b;
    int c;
};

void my_long_arglist_function(GridPosition g) {}
void my_long_arglist_function_2(float x, GridPosition g) {}

// Boolean parameters
int print_text(std::string text, bool should_print_header = false)
{
    if (should_print_header) {
        std::cout << "Header" << std::endl;
    }
    std::cout << text << std::endl;
    return 0;
}

enum class TextDecoration
{
    no_decoration,
    header_only,
    footer_only,
    header_and_footer,
};

struct PrinterConfig
{
    bool include_header{false};
    bool include_footer{false};
    int indent{4};
};

int print_text(
    std::string text, TextDecoration decoration = TextDecoration::no_decoration);


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


struct Employee  // NOLINT(cppcoreguidelines-special-member-functions)
{
    virtual ~Employee() = default;
    virtual int calculate_pay(const std::string& name) = 0;
};

struct CommissionedEmployee : public Employee
{
    int calculate_pay(const std::string& name) override { return 4500; }
};

struct HourlyEmployee : public Employee
{
    int calculate_pay(const std::string& name) override { return 1500; }
};

Employee* makeEmployee(int id)
{
    if (id < 100) {
        return new CommissionedEmployee();
    }
    else {
        return new HourlyEmployee();
    }
}


// BadNames1 improved...
class MineSweeper
{
    enum class Status
    {
        Flagged,
        Unflagged
    };
    struct Cell
    {
        Status status{Status::Flagged};
        int bomb_count{0};
    };
    using board_type = std::vector<Cell>;
    using flagged_cells_type = std::vector<Cell>;

    board_type game_board;

    flagged_cells_type get_flagged_cells()
    {
        flagged_cells_type flagged_cells{};
        for (Cell cell : game_board) {
            if (cell.status == Status::Flagged) {
                flagged_cells.push_back(cell);
            }
        }
        return flagged_cells;
    }
};
