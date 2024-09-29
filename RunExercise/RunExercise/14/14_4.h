 // The swap() function for swap values of aeguments
// with help template
#pragma once
#ifndef _SWAP_TEMPLATE_H_
#define _SWAP_TEMPLATE_H_


#include <iostream>

namespace Template_14_4 {
    template <class S>
    void swap(S &argument1, S &argument2)
    {
        S temp = argument1;
        argument1 = argument2;
        argument2 = temp;
    }
}

#endif // !_SWAP_TEMPLATE_H_