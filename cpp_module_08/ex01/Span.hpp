#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>

template <typename Tp>
class Span
{
    private:
        Tp container_;
        unsigned int size_;
        unsigned int capacity_;
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

        class ExceptionFullContainer: public std::exception
        {
            public:
                const char *what(void) const throw();
        };

};

#include "Span.tpp"

#endif //SPAN_HPP

