#pragma once

// This is supposed to be provided by a third party. You cannot change this!

#ifndef EMPLOYEE_AUGURDB_H
#define EMPLOYEE_AUGURDB_H

#include <stdexcept>
#include <string>
#include <vector>

namespace employee_workshop_simplified {

struct DatabaseRecord
{
    explicit DatabaseRecord(std::vector<std::string> saved_fields)
        : saved_fields{std::move(saved_fields)}
    {}

    std::vector<std::string> saved_fields{};
};

inline bool operator==(const DatabaseRecord& lhs, const DatabaseRecord& rhs)
{
    return lhs.saved_fields == rhs.saved_fields;
}

class AugurDb
{
private:
    std::vector<DatabaseRecord> records{};
    std::vector<std::string> current_record_entries{};
    bool is_transaction_active{false};

public:
    [[nodiscard]] const std::vector<DatabaseRecord>& get_records() const
    {
        if (is_transaction_active) {
            throw std::logic_error("Cannot get records while inside a transaction.");
        }
        return records;
    }

    void start_transaction()
    {
        if (is_transaction_active) {
            throw std::logic_error("Cannot start nested transaction.");
        }
        current_record_entries.clear();
        is_transaction_active = true;
    }

    void commit_transaction()
    {
        if (!is_transaction_active) {
            throw std::logic_error("Cannot commit outside of a transaction.");
        }
        is_transaction_active = false;
        records.emplace_back(std::move(current_record_entries));
    }

    template <typename T>
    void store_field(const std::string& name, const T& value)
    {
        if (!is_transaction_active) {
            throw std::logic_error{"Storing field outside of a transaction."};
        }
        current_record_entries.push_back(name);
    }
};

} // namespace employee_workshop_simplified
#endif // EMPLOYEE_AUGURDB_H
