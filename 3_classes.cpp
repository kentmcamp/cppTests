#include <iostream>
#include <string>

class movie {
public:

    // Constructors

    // Default constructor
    movie() {
        title = "No title";
        director = "No director";
        year = 0;
        rating = 0.0;
        watched = false;
    }

    // Parameterized constructor
    movie(std::string title_i, std::string director_, int year_i, float rating_i, bool watched_i) {
        title = title_i;
        director = director_;
        year = year_i;
        rating = rating_i;
        watched = watched_i;
    }

    // Getters
    std::string get_name() const{
        return title;
    };
    std::string get_director() const{
        return director;
    };
    int get_year() const{
        return year;
    };
    float get_rating() const{
        return rating;
    };
    bool get_watched() const{
        return watched;
    };

    // Setters
    void set_name(std::string new_title){
        title = new_title;
    };
    void set_director(std::string director_i){
        director = director_i;
    };
    void set_year(int year_i){
        year = year_i;
    };
    void set_rating(float rating_i){
        rating = rating_i;
    };
    void set_watched(bool watched_i){
        watched = watched_i;
    };

private:
    std::string title;
    std::string director;
    int year;
    float rating;
    bool watched;
};

int main() {

    movie madmax("Mad Max: Fury Road", "George Miller", 2015, 4.5, true);

    std::cout << "The movie is " << madmax.get_name() << ", directed by " << madmax.get_director() << " in " << madmax.get_year() << ". It's rating is " << madmax.get_rating() << "." << std::endl;

    std::cout << "Did I watch it? ";
    if (madmax.get_watched() == true)
    {
        std::cout << "Yes" << std::endl;;
    }
    else
    {
        std::cout << "No" << std::endl;;
    }

    madmax.set_rating(5.0);
    std::cout << "Actually, I changed my rating to a " << madmax.get_rating() << std::endl;

    return (0);
}
