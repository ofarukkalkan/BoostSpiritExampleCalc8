/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
///////////////////////////////////////////////////////////////////////////////
//
//  Now we'll introduce boolean expressions and control structures.
//  Is it obvious now what we are up to? ;-)
//
//  [ JDG April 9, 2007 ]       spirit2
//  [ JDG February 18, 2011 ]   Pure attributes. No semantic actions.
//
///////////////////////////////////////////////////////////////////////////////

#include "expression.hpp"
///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////
int
main()
{
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "Expression parser...\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "Type some statements... ";
    std::cout << "-------------------------\n";

    std::wstring str;
    std::wstring source;
    std::wstring parsed;
    while (std::getline(std::wcin, str))
    {
        if (str.empty())
            break;
        source += str + L'\n';
    }

    typedef std::wstring::const_iterator iterator_type;
    iterator_type iter = source.begin();
    iterator_type end = source.end();


    client::error_handler<iterator_type>
        error_handler(iter, end);               // Our error handler
    client::parser::expression<iterator_type>
        parser(error_handler);                  // Our parser


    boost::spirit::standard_wide::space_type space;
    bool success = phrase_parse(iter, end, parser, space, parsed);

    std::cout << "-------------------------\n";

    if (success && iter == end)
    {
        std::wcout << parsed << std::endl;
    }
    else
    {
        std::cout << "Parse failure\n";
    }

    std::cout << "-------------------------\n\n";
    return 0;
}


