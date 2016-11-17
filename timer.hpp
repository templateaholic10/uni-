/* @file timer タイマークラスを提供
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

/* @class Timer 定義またはrestartメソッドで計測を開始し，elapsedメソッドで経過時間を取得する
 * @tparam Unit 時間の単位
 */
template <typename Unit=std::chrono::milliseconds>
class Timer
{
public:
    using duration = Unit;
    using type = Timer <duration>;
    using time_point = std::chrono::system_clock::time_point;
private:
    time_point start;
public:
    Timer() { restart(); }
    void restart() { start = std::chrono::system_clock::now(); }
    int elapsed() const { return std::chrono::duration_cast <duration>(std::chrono::system_clock::now()-start).count(); }
};

#endif
