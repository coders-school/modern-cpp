<!-- .slide: data-background="#111111" -->
# Standardy C++

___

## Historia standaryzacji C++

### Kiedy utworzono C++?
<!-- .element: class="fragment fade-in" -->

#### 1979
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in-then-semi-out"--> 1998 - pierwszy standard ISO C++ - C++98
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2003 - TC1 (Technical Corrigendum 1) opublikowane jako C++03. Poprawki błędów dla C++98
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2005 - Publikacja raportu technicznego (Technical Report 1) - przestrzeń nazw <code>std::tr1</code>
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2011 - opublikowano C++0x jako C++11
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2013 - pełna wersja robocza C++1y
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2014 - C++1y opublikowany jako C++14
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2017 - C++1z opublikowany jako C++17
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2020 - C++2a opublikowane jako C++20
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2023 - C++2b powinno zostać opublikowane jako C++23

___

## Wsparcie kompilatorów

### [GCC](https://gcc.gnu.org/projects/cxx-status.html) - [Clang](https://clang.llvm.org/cxx_status.html)

<div class="box" style="width: 45%; left: 0; top: 200px">
    <h3>C++23</h3>
    <ul>
        <li>Pełne wsparcie: jeszcze nie zaimplementowane</li>
        <li>Flagi kompilatora: <code>-std=c++2b</code></li>
    </ul>
</div>

<div class="box" style="width: 45%; left: 0; top: 360px">
    <h3>C++20</h3>
    <ul>
        <li>(prawie) pełne wsparcie: gcc11, clang14</li>
        <li>Flagi kompilatora: <code>-std=c++20</code>, <code>-std=c++2a</code></li>
    </ul>
</div>
<div class="box" style="width: 45%; right: 0; top: 360px">
    <h3>C++17</h3>
    <ul>
        <li>Pełne wsparcie: gcc7, clang5</li>
        <li>Flagi kompilatora: <code>-std=c++17</code>, <code>-std=c++1z</code></li>
    </ul>
</div>
<div class="box" style="width: 45%; left: 0; top: 520px">
    <h3>C++14</h3>
    <ul>
        <li>Pełne wsparcie: gcc5, clang3.4</li>
        <li>Flagi kompilatora: <code>-std=c++14</code>, <code>-std=c++1y</code></li>
        <li><u>Domyślnie włączone od gcc6.1</u></li>
    </ul>
</div>
<div class="box" style="width: 45%; right: 0; top: 520px">
    <h3>C++11</h3>
    <ul>
        <li>Pełne wsparcie: gcc4.8.1, clang3.3</li>
        <li>Flagi kompilatora: <code>-std=c++11</code>, <code>-std=c++0x</code></li>
    </ul>
</div>
