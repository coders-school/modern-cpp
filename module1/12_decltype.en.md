## `decltype`

**Rationale**: Deduction provided in contexts where auto is not allowed.

`decltype` allows a compiler to deduce the type of the variable or expression, eg. the returned type can be deduced from function parameters.

```cpp
std::map<std::string, float> collection;

decltype(collection) other;              // other has type of collection
decltype(collection)::mapped_type value; // value is float

template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b)  // from C++14 decltype not necessary
{
    return a + b;
}
```

___

## `decltype(auto)`

`decltype(auto)` deduction mechanism preserves type modifiers (references, const, volatile).

`auto` deduction mechanism does not preserve type modifiers.

```cpp
template<class FunctionType, class... Args>
decltype(auto) Example(FunctionType fun, Args&&... args)
{
    return fun(std::forward<Args>(args)...);
}
```
