## Q3.8. Algorithms Galore

Answer the following quetsions:

1. Consider the code below:
```cpp
auto first(const std::vector<int> &v, const int needle) {
  for (auto i = v.begin(); i != v.end(); ++i) {
    if (*i == needle) {
      return i;
    }
  }
  return v.end();
}
```
What standard algorithm can this code be replaced by?
- a) std::get
- b) std::find_if
- c) std::search
**- d) std::find**

2. Consider the code below:
```cpp
auto second(std::vector<int> &v, std::vector<int>::iterator new_first) {
  auto copy = std::vector<int>(v.begin(), new_first);
  v.erase(v.begin(), new_first);
  return v.insert(v.end(), copy.begin(), copy.end());
}
```
What standard algorithm can this be replaced by?
- a) std::erase
- b) std::shift_left
**- c) std::rotate**
- d) std::shift_right

3. Consider the code below
```cpp
auto third(std::span<float> floats) {
  auto v = std::vector<float>{};
  for (auto f : floats) {
    v.push_back(f);
  }

  auto m = std::numeric_limits<float>::max();
  for (auto f : v) {
    if (f < m) {
      m = f;
    }
  }

  auto M = std::numeric_limits<float>::min();
  for (auto f : v) {
    if (M < f) M = f;
  }

  return std::make_pair(m, M);
}
```
What sequence of standard algorithms can this reasonably be replaced by?
- a) std::copy -> std::min_element -> std::max_element
**- b) std::copy -> std::minmax_element**
- c) std::vector iterator constructor -> std::min_element -> std::max_element
- d) std::memcpy -> std::max_element -> std::min_element
