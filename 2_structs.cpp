#include <iostream>
#include <string>

struct movie{
    std::string title;
    std::string director;
    int year;
    float rating;
    bool watched;
};

int main() {

    movie madmax;
    madmax.title = "Mad Max: Fury Road";
    madmax.director = "George Miller";
    madmax.year = 2015;
    madmax.rating = 4.5;
    madmax.watched = 1;

    std::cout << "The movie is " << madmax.title << ", directed by " << madmax.director << " in " << madmax.year << ". It's rating is " << madmax.rating << "." << std::endl;

    std::cout << "Did I watch it? ";
    if (madmax.watched) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }

    return(0);
}
