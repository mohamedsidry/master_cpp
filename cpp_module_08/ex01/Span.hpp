#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <initializer_list>

class Span
{
    private:
        std::vector<int> data_;
        unsigned int maxSize_;
    public:
        Span();
        Span(unsigned int);
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span();


        void addNumber(int);
        unsigned int longestSpan(void) const;
        unsigned int shortestSpan(void) const;
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) +  data_.size() > maxSize_ )
                throw Span::ExceptionFullContainer();
            data_.insert(data_.end(), begin, end);
        }

        class ExceptionFullContainer: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        class ExceptionNotEnoughNumbers: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

};

#endif //SPAN_HPP

