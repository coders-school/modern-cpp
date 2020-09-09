## `decltype`

**Uzasadnienie**: Dedukcja w kontekstach, w których auto jest niedozwolone.

`decltype` pozwala kompilatorowi wydedukować typ zmiennej lub wyrażenia, np. zwracany typ można wywnioskować z parametrów funkcji.

```cpp
std::map<std::string, float> collection;

decltype(collection) other;              // other jest typu collection
decltype(collection)::mapped_type value; // value jest typu float

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)  // od C++14 decltype niepotrzebne
{
    return a + b;
}
```

___

## `decltype(auto)`

Mechanizm dedukcji `decltype(auto)` zachowuje modyfikatory typu (referencje, const, volatile).

Mechanizm dedukcji `auto` nie zachowuje modyfikatorów typu.

```cpp
template<class FunctionType, class... Args>
decltype(auto) Example(FunctionType fun, Args&&... args)
{
    return fun(std::forward<Args>(args)...);
}
```
