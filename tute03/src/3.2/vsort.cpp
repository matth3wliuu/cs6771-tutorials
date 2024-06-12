#include "vsort.h"

auto vsort(std::vector<std::string>& vs) -> void {
    std::sort(vs.begin(), vs.end(), [] (const auto& lhs, const auto& rhs) {
        auto is_vowel = [] (char ch) -> bool {
            const auto lower = std::tolower(ch);
            return lower == 'a' or lower == 'e' or lower == 'i' or lower == 'o' or lower == 'u';
        };

        const auto lhs_vowels = std::count_if(lhs.begin(), lhs.end(), is_vowel);
        const auto rhs_vowels = std::count_if(rhs.begin(), rhs.end(), is_vowel);

        if (lhs_vowels == rhs_vowels) {
            return lhs < rhs;
        }

        return lhs_vowels < rhs_vowels;
    });
}