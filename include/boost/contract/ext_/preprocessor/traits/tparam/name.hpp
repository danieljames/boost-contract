
#ifndef BOOST_CONTRACT_EXT_PP_TPARAM_TRAITS_NAME_HPP_
#define BOOST_CONTRACT_EXT_PP_TPARAM_TRAITS_NAME_HPP_

#include <boost/contract/ext_/preprocessor/traits/tparam/aux_/index.hpp>
#include <boost/contract/ext_/preprocessor/traits/aux_/adt.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

// PUBLIC //

// Precondition: name must always be the last remaining token in signature.
// Implementation: NIL used as tuples cannot have EMTPY() elems (on MSVC).
#define BOOST_CONTRACT_EXT_PP_TPARAM_TRAITS_NAME_PARSE(sign_traits) \
    ( \
        BOOST_PP_NIL, \
        BOOST_CONTRACT_EXT_PP_TRAITS_AUX_PUSH_BACK( \
            BOOST_PP_TUPLE_ELEM(2, 1, sign_traits), \
            BOOST_PP_TUPLE_ELEM(2, 0, sign_traits) \
            BOOST_PP_EMPTY \
        ) \
    )

// Expand to `[...] name | EMPTY()` (ellipses `...` for variadic templates).
#define BOOST_CONTRACT_EXT_PP_TPARAM_TRAITS_NAME(traits) \
    BOOST_CONTRACT_EXT_PP_TRAITS_AUX_ELEM( \
        BOOST_CONTRACT_EXT_PP_TPARAM_TRAITS_AUX_NAME_INDEX, \
        traits \
    )()

#endif // #include guard

