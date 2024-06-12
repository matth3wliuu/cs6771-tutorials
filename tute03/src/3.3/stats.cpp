#include "stats.h"
#include <istream>
#include <algorithm>

auto read_marks(const std::string& path) -> std::vector<int>
{
    auto fp = std::ifstream{path};
    if (not fp.is_open()) {
        throw std::runtime_error("file couldn't be opened");
    }

    return std::vector<int>(
        std::istream_iterator<int>(fp), // iterator points to start of file
        std::istream_iterator<int>{} // iterator points to the "end" of file
    );
}

auto calculate_stats(const std::vector<int>& marks) -> stats
{
    auto sorted_mks = marks;
    std::sort(sorted_mks.begin(), sorted_mks.end());

    return {
        .avg = std::accumulate(sorted_mks.begin(), sorted_mks.end(), 0) / static_cast<int>(sorted_mks.size()),
        .median = sorted_mks[sorted_mks.size() / 2],
        .lowest = sorted_mks.front(),
        .highest = sorted_mks.back()
    };
}