#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename Tp>
class MutantStack : public std::stack<Tp>
{        

    public:
    typedef typename std::stack<Tp>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;

    MutantStack();
    MutantStack(const MutantStack&);
    MutantStack& operator=(const MutantStack&);
    ~MutantStack();

    iterator begin(void);
    const_iterator cbegin(void) const;
    iterator end(void);
    const_iterator cend(void) const;
    const_iterator begin(void) const;
    const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP

