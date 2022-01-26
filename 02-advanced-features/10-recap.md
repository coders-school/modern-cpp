<!-- .slide: data-background="#111111" -->
# Podsumowanie

___

## Co pamiętasz z dzisiejszej sesji?

___

## Nietypowe rzeczy warte zapamiętania

* W lambdzie trzeba dodać słówko `mutable`, gdy chcemy modyfokować rzeczy przechwycone przez kopię `[=]` na liście przechwytywania
* Aby przekazać `unique_ptr` na liście przechwytywania w lambdzie, trzeba posłużyć się konstrukcją `[a = std::move(a)]`
* Zawsze warto oznaczać wszystko co się da jako `constexpr`
