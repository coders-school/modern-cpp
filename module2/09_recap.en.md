<!-- .slide: data-background="#111111" -->
# Recap

___

## What do you remember from today's session?

___

## C++ quirks

* Lambda - you need to add `mutable` in case you have `[=]` on capture list and you want to modify captured elements
* Lambda - `unique_ptr` on capture list `a=std::move(a)`
* Try marking as many functions as `constexpr` as possible
