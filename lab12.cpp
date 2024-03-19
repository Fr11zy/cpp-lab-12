#include <iostream>
#include <vector>
#include <deque>

template <typename T>
class ReverseIterator {
public:
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    ReverseIterator(pointer ptr) : ptr(ptr) {}

    ReverseIterator& operator++() 
    {
        --ptr;
        return *this;
    }

    ReverseIterator& operator--() 
    {
        ++ptr;
        return *this;
    }

    reference operator*() 
    {
        return *ptr;
    }

    bool operator==(const ReverseIterator& other) const 
    {
        return ptr == other.ptr;
    }

    bool operator!=(const ReverseIterator& other) const 
    {
        return ptr != other.ptr;
    }

private:
    pointer ptr;
};

template <typename T>
class IterVec
{
    private:
        std::vector<T> &vec;
    public:
        IterVec(std::vector<T> &vec): vec(vec) {}

        ReverseIterator<T> beg()
        {
            return ReverseIterator<T>(&(vec.back()));
        }

        ReverseIterator<T> end()
        {
            return ReverseIterator<T>(&(vec.front())-1);
        }
};

template <typename T>
class IterDeq
{
    private:
        std::deque<T> &deq;
    public:
        IterDeq(std::deque<T> &deq): deq(deq) {}

        ReverseIterator<T> beg()
        {
            return ReverseIterator<T>(&(deq.back()));
        }

        ReverseIterator<T> end()
        {
            return ReverseIterator<T>(&(deq.front())-1);
        }
};


int main() 
{
    std::vector<int> vec1={1,2,3,4,5};
    IterVec vIter(vec1);
    auto Vecbegin=vIter.beg();
    auto Vecend=vIter.end();
    for (auto it=Vecbegin;it!=Vecend; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::deque<double> deq1={1.1,1.2,1.3,1.44,1.55555};
    IterDeq dIter(deq1);
    auto Deqbegin=dIter.beg();
    auto Deqend=dIter.end();
    for (auto it=Deqbegin;it!=Deqend; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
