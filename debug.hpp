/* @file debug $B%G%P%C%0$N$?$a$N%f!<%F%#%j%F%#%^%/%m72!%(B
 *  #define DEBUG$B$^$?$O(B#define ISDEBUG 1$B$N;~$N$_F0:n$9$k(B
 */

#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <iostream>
#include <boost/preprocessor/control/expr_iif.hpp>

#ifndef ISDEBUG
#ifdef DEBUG
#define ISDEBUG 1
#else
#define ISDEBUG 0
#endif
#endif

/* @macro HERE $B<+$i$N=j:_CO$r=PNO$9$kDj?t%^%/%m(B
 */
#ifdef HERE
#undef HERE
#endif
#define HERE BOOST_PP_EXPR_IIF(ISDEBUG, { std::cerr << "DEBUG: here is line " << __LINE__ << " in " << __FILE__ << std::endl; })

/* @macro PRINT(var) $BJQ?t$NCf?H$r=PNO$9$k4X?t%^%/%m(B
 */
#ifdef PRINT
#undef PRINT
#endif
#define PRINT(var) BOOST_PP_EXPR_IIF(ISDEBUG, { std::cerr << "DEBUG: $" #var " is " << (var) << std::endl; })

#endif
