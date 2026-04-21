#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"


template <typename Tp>
MutantStack<Tp>::MutantStack()
{}


template <typename Tp>
MutantStack<Tp>::MutantStack(const MutantStack& other)
{
    this->c = other.c;
}

template <typename Tp>
MutantStack<Tp>& MutantStack<Tp>::operator=(const MutantStack& other)
{
    if (this != &other)
        container_type::operator=(other.c);
    return *this;
}

template <typename Tp>
MutantStack<Tp>::~MutantStack()
{}



template <typename Tp>
typename MutantStack<Tp>::iterator MutantStack<Tp>::begin(void)
{
    return this->c.begin();
}

template <typename Tp>
typename MutantStack<Tp>::const_iterator MutantStack<Tp>::begin(void) const
{
    return this->c.begin();
}

template <typename Tp>
typename MutantStack<Tp>::iterator MutantStack<Tp>::end(void)
{
    return this->c.end();
}

template <typename Tp>
typename MutantStack<Tp>::const_iterator MutantStack<Tp>::end(void) const
{
    return this->c.end();
}

# endif // MUTANTSTACK_TPP

