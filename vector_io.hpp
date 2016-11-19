/* @file vector_io std::vector I/O．iostreamに対応
 */

#ifndef VECTOR_IO_HPP_
#define VECTOR_IO_HPP_

#include <vector>
#include <iostream>

#ifndef VECTOR_IO_DELIM
#define VECTOR_IO_DELIM ','
#endif

namespace vector_io {
    /* @function std::vectorの抽出関数．抽出子オーバーロードがうまくいかない時，直接コールする
     * @param os 出力ストリーム
     * @param seq std::vector
     * @param delim デリミタ
     */
    template <typename Elem>
    std::ostream &out(std::ostream &os, const std::vector <Elem> &seq, const char delim=VECTOR_IO_DELIM)
    {
        if (seq.empty()) { return os; } // 空列の時何も出力しない

        os << *(seq.begin());
        for (auto it=seq.begin()+1; it!=seq.end(); it++) {
            os << delim << *it;
        }
        return os;
    }

    /* @function std::vectorの挿入関数．挿入子オーバーロードがうまくいかない時，直接コールする
     * @param is 入力ストリーム
     * @param seq std::vector
     * @param delim デリミタ
     */
    template <typename Elem>
    std::istream &in(std::istream &is, std::vector <Elem> &seq, const char delim=VECTOR_IO_DELIM)
    {
        if (seq.empty()) { return is; } // 空列の時何も入力しない
        
        is >> *(seq.begin());
        for (auto it=seq.begin()+1; it!=seq.end(); it++) {
            is.ignore(1, delim);
            is >> *it;
        }
        return is;
    }
}

/* @operator std::vectorの抽出子
 */
template <typename Elem>
std::ostream &operator<<(std::ostream &os, const std::vector <Elem> &seq)
{
    return vector_io::out(os, seq);
}

/* @operator std::vectorの挿入子
 */
template <typename Elem>
std::istream &operator>>(std::istream &is, std::vector <Elem> &seq)
{
    return vector_io::in(is, seq);
}

#endif
