#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>

#define ABS(x) ((x) > 0 ? (x) : -(x))

template <typename Tp>
class Span
{
    private:
        Tp container_;
        unsigned int size_;
        unsigned int capacity_;

        int min(void) const;
        int max(void) const;
    public:
        Span();
        Span(unsigned int);
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span(){};


        unsigned int size(void) const {return size_;};
        unsigned int capacity(void) const {return capacity_;};
        const Tp& container(void) const {return container_;};
        Tp& container(void) {return container_;};
        void addNumber(int);
        unsigned int longestSpan(void) const;
        //unsigned int shortestSpan(void) const;
        class ExceptionFullContainer: public std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };
        class ExceptionEmptyContainer: public std::exception
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

#include "Span.tpp"

#endif //SPAN_HPP

