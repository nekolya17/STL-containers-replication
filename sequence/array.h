#pragma once 
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

template <typename T, std::size_t N>
class Array{
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = value_type*;
    using const_iterator = value_type*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    value_type elems[N];

    // Iterators 

    constexpr iterator begin() noexcept{
        return iterator(elems);
    }
    constexpr const_iterator cbegin() const noexcept{
        return const_iterator(elems);
    }
    constexpr iterator end() noexcept{
        return iterator(elems + N);
    }
    constexpr const_iterator cend() const noexcept{
        return const_iterator(elems + N);
    }
    constexpr reverse_iterator rbegin() noexcept{
        return reverse_iterator(end());
    }
    constexpr const_reverse_iterator rcbegin() const noexcept{
        return const_reverse_iterator(cend());
    }
    constexpr reverse_iterator rend() noexcept{
        return reverse_iterator(begin());
    }
    constexpr const_reverse_iterator rcend() const noexcept{
        return const_reverse_iterator(cbegin());
    }
    
    // Element access
    constexpr reference operator[](size_type pos) noexcept{
        return elems[pos];
    } 
    constexpr const_reference operator[](size_type pos) const noexcept{
        return elems[pos];
    } 
    constexpr reference at(size_type pos) {
        if(pos > N){
            throw std::out_of_range("at() argument is either greater than size of array, or is negative");
        }
        return elems[pos];
    }
    constexpr const_reference at(size_type pos) const  {
        if(pos > N){
            throw std::out_of_range("at() argument is either greater than size of array, or is negative");
        }
        return elems[pos];
    }
    constexpr reference front() noexcept {
        return elems[0];
    }
    constexpr const_reference front() const noexcept {
        return elems[0];
    }
    constexpr reference back() noexcept {
        return elems[N - 1];
    }
    constexpr const_reference back() const noexcept {
        return elems[N - 1];
    }
    constexpr pointer data() noexcept {
        return static_cast<pointer>(elems);
    }
    constexpr const_pointer data() const noexcept {
        return static_cast<const_pointer>(elems);
    }

    //Capacity 
    constexpr size_type size() const noexcept {
        return N;
    }
    constexpr bool empty() const noexcept {
        return (size() == 0);
    }
    constexpr size_type max_size() const noexcept {
        return N;
    }

    //Operations

    constexpr void fill(const value_type& value ){
        for(value_type& x : elems){
            x = value;
        }
    }

};

#endif