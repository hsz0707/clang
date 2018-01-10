// RUN: %clang_cc1 -std=c++17 -verify %s
// expected-no-diagnostics
template<bool> struct DominatorTreeBase {
  static constexpr bool IsPostDominator = true;
};
extern template class DominatorTreeBase<false>;
constexpr bool k = DominatorTreeBase<false>::IsPostDominator;

template <typename T> struct A {
  static const int n;
  static const int m;
  constexpr int f() { return n; }
  constexpr int g() { return n; }
};
template <typename T> constexpr int A<T>::n = sizeof(A) + sizeof(T);
template <typename T> inline constexpr int A<T>::m = sizeof(A) + sizeof(T);
static_assert(A<int>().f() == 5);
static_assert(A<int>().g() == 5);
