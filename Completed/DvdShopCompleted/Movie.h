#ifndef DVDSHOP_MOVIE_H
#define DVDSHOP_MOVIE_H

#include <string>

class Movie
{
private:
    std::string title;

public:
    explicit Movie(std::string title);
    Movie(const Movie& other) = delete;
    Movie(Movie&& other) noexcept = delete;
    Movie& operator=(const Movie& other) = delete;
    Movie& operator=(Movie&& other) noexcept = delete;
    virtual ~Movie() = default;

    [[nodiscard]] const std::string& get_title() const;

    [[nodiscard]] virtual double determine_amount(int days_rented) const = 0;
    [[nodiscard]] virtual int determine_points(int days_rented) const = 0;
};


#endif // DVDSHOP_MOVIE_H
