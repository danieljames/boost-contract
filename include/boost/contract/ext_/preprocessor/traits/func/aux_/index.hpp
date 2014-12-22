
#ifndef BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_INDEX_HPP_
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_INDEX_HPP_

// You can set this internal macro to stop and test at a func-trait index.
// #define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_INDEX_TEST <an-index-below>

// WARNING: These indexes must match order traits are parsed (see func.hpp).

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_ACCESS_INDEX      0

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_VERBATIM_INDEX    1

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_EXPORT_INDEX      2

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_TEMPLATE_INDEX    3
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_TPARAMS_INDEX     4

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_INLINE_INDEX      5
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_STATIC_INDEX      6
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_EXTERN_INDEX      7
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_EXPLICIT_INDEX    8
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_VIRTUAL_INDEX     9
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_FRIEND_INDEX      10
// This must be defined to the largest index of the above.
#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_CLASSIFIERS_INDEX \
    BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_FRIEND_INDEX

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_RETURN_INDEX      11

#define BOOST_CONTRACT_EXT_PP_FUNC_TRAITS_AUX_DONE_INDEX        12

#endif // #include guard

