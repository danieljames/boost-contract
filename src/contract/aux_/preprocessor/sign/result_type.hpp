// Copyright (C) 2009-2010 Lorenzo Caminiti.
// Use, modification, and distribution is subject to the
// Contract++ Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt.)

#ifndef CONTRACT_AUX_PP_SIGN_RESULT_TYPE_HPP_
#define CONTRACT_AUX_PP_SIGN_RESULT_TYPE_HPP_

#include "seq_.hpp"
#include "../keyword/is_void.hpp"
#include <boost/preprocessor.hpp>

#define CONTRACT_AUX_PP_SIGN_RESULT_TYPE(sign) \
    BOOST_PP_SEQ_ELEM(CONTRACT_AUX_PP_SIGN_SEQ_RESULT_TYPE_INDEX, \
            sign)

#define CONTRACT_AUX_PP_SIGN_IS_VOID_RESULT(sign) \
    CONTRACT_AUX_PP_KEYWORD_IS_VOID( \
            CONTRACT_AUX_PP_SIGN_RESULT_TYPE(sign))

#endif // #include guard

