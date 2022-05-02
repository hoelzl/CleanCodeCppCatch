// Copyright (c) 2022 Dr. Matthias Hölzl.

// ReSharper disable IdentifierTypo
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppClangTidyModernizeUseNodiscard
// ReSharper disable CppClangTidyClangDiagnosticUnusedPrivateField

// ReSharper disable All
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

// Disinformation: name doesn't mean what is says
struct Pair
{
    int first{};
    int second{};
    int third{};
};

// Renamed:
struct Triple
{
    int first{};
    int second{};
    int third{};
};

// Disinformation(?): names differ only slightly
constexpr int MY_CONTROLLER_FOR_EFFICIENT_HANDLING_OF_STRINGS = 1;
constexpr int MY_CONTROLLER_FOR_EFFICIENT_STORING_OF_STRINGS = 2;

// Hungarian notation
const int* pi_target;
// Better:
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

class AbstractActor
{};
class Actor3 : public AbstractActor
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
    // OsConnection& get_connection();
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
public:
    virtual ~SerialDate() = default;
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

// Probably Better:
class CalenderDate
{
public:
    virtual ~CalenderDate() = default;
    virtual int to_timestamp() = 0;
};


// Wrong part of speech: this is supposed to be a file, not a function that wraps a file
// handle
class WrapFileHandle
{
public:
    // Wrong part of speech, could be expressed in code
    // Does not change the state of the file.
    bool open() { return true; }

private:
    // Problematic: is handle a verb or a noun?
    int handle{};
};

class File
{
public:
    bool is_open() const { return true; }

private:
    // Probably better, makes it clear that handle is a noun.
    int file_handle{};
};


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
