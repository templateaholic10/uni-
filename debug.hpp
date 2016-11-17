/* @file debug デバッグのためのユーティリティマクロ群．
 *  #define DEBUGまたは#define ISDEBUG 1の時のみ動作する
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

/* @macro HERE 自らの所在地を出力する定数マクロ
 */
#ifdef HERE
#undef HERE
#endif
#define HERE BOOST_PP_EXPR_IIF(ISDEBUG, { std::cerr << "DEBUG: here is line " << __LINE__ << " in " << __FILE__ << std::endl; })

/* @macro PRINT(var) 変数の中身を出力する関数マクロ
 */
#ifdef PRINT
#undef PRINT
#endif
#define PRINT(var) BOOST_PP_EXPR_IIF(ISDEBUG, { std::cerr << "DEBUG: $" #var " is " << (var) << std::endl; })

#endif
