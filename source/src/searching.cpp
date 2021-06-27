/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date June 17th, 2021.
 */

#include "searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        // The loop will cycle through the entire array,
        // stopping when it finds the element fetched or when it reaches the end of the array.
        while (first != last) {
            // Checks if the value in the first position is equal to the fetched value
            if(*first == value) {
                return first; 
            }
            first += 1; // Walk a position
        }
        return last;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        int * lastAssistant = last; // Auxiliary variable
        while (first != lastAssistant) 
        {
            // Receives the address of the middle element of the array or of the subset of the array
            int * middle = (first + (int) (lastAssistant - first - 1) / 2);
            if (* middle == value) 
            { // Checks if the element inside the middle address is equal to the fetched value
                return middle;
            }
            if (* middle > value) 
            { 
                lastAssistant = middle; // Update the value of the last
            } else 
            {
                first = middle + 1; // Update the value of the first
            }
        }
        return last; 
    }

    /*!
     * Performs a ** recursive binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param lastAssistant Pointer auxiliary just past the last element of the data range.
     * \param middle Central element of the range [first; last).
     * \param value The value we are looking for.
     * \param last Pointer to the original address of the first last
     */
    value_type * search( value_type * first, value_type * lastAssistant, value_type * middle, value_type value, value_type * last ) {
        if (first == lastAssistant) 
        {  
            return last; // Recursion Stop Condition
        }
        if (* middle == value) // If the central element is equal to the fetched value, we get what we wanted.
        {
            return middle;
        }
        if (* middle > value) // If the central element is greater than the searched value, we need to change our search space.
        {
            return search(first, middle, (first + (int) (middle - first - 1) / 2), value, last);
        } else // If the central element is smaller than the searched value, last possible case, we need to change our search space.
        {
            return search(middle + 1, lastAssistant, ((middle + 1) + (int) (lastAssistant - (middle + 1) - 1) / 2), value, last);
        }
    }

    /*!
     * Performs a ** recursive binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */

    value_type * brsearch( value_type * first, value_type * last, value_type value )
    {
        int * lastAssistant = last; // Auxiliary variable
        // Receives the address of the middle element of the array or of the subset of the array
        int * middle = (first + (int) (lastAssistant - first - 1) / 2);
        return search(first, lastAssistant, middle, value, last);
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        while( first != last) {
            if (* first >= value ) {
                return first;
            }
            first += 1;
        }
        return last; // STUB
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        while( first != last) {
            if (* first > value ) {
                return first;
            }
            first += 1;
        }
        return last; // STUB
    }
}

