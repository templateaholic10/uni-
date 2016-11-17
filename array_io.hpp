/* @file array_io std::arrai I/O
 */

#ifndef ARRAY_IO_HPP_
#define ARRAY_IO_HPP_

#include <array>
#include <iostream>

#ifndef ARRAY_IO_DELIM
#define ARRAY_IO_DELIM ','
#endif

namespace array_io {
    /* @function std::arrayの抽出関数．抽出子オーバーロードがうまくいかない時，直接コールする
     * @param os 出力ストリーム
     * @param seq std::array
     * @param delim デリミタ
     */
    template <typename Elem, size_t N>
    std::ostream &out(std::ostream &os, const std::array <Elem, N> &seq, const char delim=ARRAY_IO_DELIM)
    {
        if (N==0) { return os; } // 空列の時何も出力しない

        os << *(seq.begin());
        for (auto it=seq.begin()+1; it!=seq.end(); it++) {
            os << delim << *it;
        }
        return os;
    }

    /* @function std::arrayの挿入関数．挿入子オーバーロードがうまくいかない時，直接コールする
     * @param is 入力ストリーム
     * @param seq std::array
     * @param delim デリミタ
     */
    template <typename Elem, size_t N>
    std::istream &in(std::istream &is, std::array <Elem, N> &seq, const char delim=ARRAY_IO_DELIM)
    {
        if (N==0) { return is; } // 空列の時何も入力しない
        
        is >> *(seq.begin());
        for (auto it=seq.begin()+1; it!=seq.end(); it++) {
            is.ignore(1, delim);
            is >> *it;
        }
        return is;
    }
}

/* @operator std::arrayの抽出子
 */
template <typename Elem, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array <Elem, N> &seq)
{
    return array_io::out(os, seq);
}

/* @operator std::arrayの挿入子
 */
template <typename Elem, size_t N>
std::istream &operator>>(std::istream &is, std::array <Elem, N> &seq)
{
    return array_io::in(is, seq);
}

#endif
