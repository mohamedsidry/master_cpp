#ifndef SPAN_HPP
# define SPAN_HPP

#include <array>
#include <stdexcept>

template <typename Tp>
class Span
{
    private:
        Tp container_;
        unsigned int size_;
        unsigned int offset_;
    public:
        Span();
        Span(unsigned int);
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span(){};


        unsigned int size(void) const {return size_;};
        unsigned int offset(void) const {return offset_;};
        const Tp& container(void) {return container_;};
};

#include "Span.tpp"

#endif //SPAN_HPP

