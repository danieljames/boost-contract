/**
 * @file
 * @author Copyright (C) 2009 Lorenzo Caminiti.
 *  Distributed under DBC++ Software License (see file LICENSE_1_0.txt).
 */
/* $Id$ */

#ifndef NAMES_HPP_
#define NAMES_HPP_

#include <dbc.hpp>
#include <string>
#include <list>

/** List of names. */
class NameList DBC_INHERIT_OBJECT(NameList) {
public:
    // Creation //

    NameList(void)
    DBC_CONSTRUCTOR( (public) (NameList)( (void) ), {
    }, {
    }, {})

    virtual ~NameList(void)
    DBC_DESTRUCTOR( (public) (virtual) (NameList)( (void) ), {})

    // Queries //

    /** If specified name is in list. */
    bool has(const std::string& name) const
    DBC_MEM_FUN( (public) (bool) (NameList) 
            (has)( (const std::string&)(name) ) (const), {
    }, {
    }, ;)

    /** Return number of names in list. */
    unsigned int count(void) const
    DBC_MEM_FUN( (public) (unsigned int) (NameList)
            (count)( (void) ) (const), {
    }, {
    }, ;)

    // Commands //

    /** Add specified name to list. */
    virtual void put(const std::string& name)
    DBC_MEM_FUN( (public) (virtual) (void) DBC_COPYABLE(NameList) 
            (put)( DBC_COPYABLE(const std::string&)(name) ), {
        DBC_ASSERT_STREAM(!self.has(name), "not in list",
                err << "name '" << name << "' already in list");
    }, {
        // required() is provided to facilitate writing post-condition guards
        // for more flexible contracts of virtual functions.
        if (required()) // Or "if (!self.old.has(name.old))".
            DBC_ASSERT_STREAM(self.now.has(name.now), 
                    "if require passed, in list",
                    err << "name '" << name.now << "' not in list");
        // Because name's type is const, name.now could be used here instead of
        // name.old (saving to declare name's type as DBC_COPYABLE() and to 
        // have to copy its value). However, technically "seld.old.has(
        // name.old)" is the expression equivalent to required().
        if (!self.old.has(name.old))
            DBC_ASSERT(self.now.count() == (self.old.count() + 1),
                    "if was not in list, count increased");
    }, ;)

private:
    std::list<std::string> names_;
    
    DBC_INVARIANT(NameList, {})
};

/** List of names that allows for duplicates. */
class RelaxedNameList: public NameList
        DBC_MULTI_INHERIT_OBJECT(RelaxedNameList) {
public:
    // Creation //

    RelaxedNameList(void)
    DBC_CONSTRUCTOR( (public) (RelaxedNameList)( (void) ), {
    }, {
    }, {})

    virtual ~RelaxedNameList(void)
    DBC_DESTRUCTOR( (public) (virtual) (RelaxedNameList)( (void) ), {})

    // Commands //

    void put(const std::string& name)
    DBC_MEM_FUN( (public) (void) 
            DBC_COPYABLE(RelaxedNameList)DBC_BASE(NameList)
            (put)( DBC_COPYABLE(const std::string&)(name) ), {
        DBC_ASSERT_STREAM(self.has(name), "in list",
                err << "name '" << name << "' not in list");
    }, {
        if (self.old.has(name.old))
            DBC_ASSERT(self.now.count() == self.old.count(),
                    "if in list, count unchanged");
    }, ;)
    
private:
    DBC_INVARIANT(RelaxedNameList, {})
};

#endif // NAMES_HPP_

