<!-- .slide: data-background="#111111" -->
# C++ standards

___

## The history of C++ standardization

### When C++ was created?
<!-- .element: class="fragment fade-in" -->

#### 1979
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in-then-semi-out"--> 1998 - first ISO C++ standard - C++98
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2003 - TC1 (Technical Corrigendum 1) published as C++03. Bug fixes for C++98
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2005 - Technical Report 1 published (<code>std::tr1</code> namespace)
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2011 - ratified C++0x as C++11
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2013 - full version of C++1y draft
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2014 - C++1y published as C++14
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2017 - C++1z published as C++17
* <!-- .element: class="fragment fade-in-then-semi-out"--> 2020 - C++2a should be published as C++20

___

## Compilers support

### [GCC](https://gcc.gnu.org/projects/cxx-status.html) - [Clang](https://clang.llvm.org/cxx_status.html)

<div class="box" style="width: 45%; left: 0;">
    <h3>C++20</h3>
    <ul>
        <li>Full support: not implemented yet</li>
        <li>Compiler flags: -std=c++2a</li>
    </ul>
</div>
<div class="box" style="width: 45%; right: 0;">
    <h3>C++17</h3>
    <ul>
        <li>Full support: gcc7, clang5</li>
        <li>Compiler flags: -std=c++17, -std=c++1z</li>
    </ul>
</div>
<div class="box" style="width: 45%; left: 0; top: 450px">
    <h3>C++14</h3>
    <ul>
        <li>Full support: gcc5, clang3.4</li>
        <li>Compiler flags: -std=c++14, -std=c++1y</li>
        <li><u>Enabled by default since gcc6.1</u></li>
    </ul>
</div>
<div class="box" style="width: 45%; right: 0; top: 450px">
    <h3>C++11</h3>
    <ul>
        <li>Full support: gcc4.8.1, clang3.3</li>
        <li>Compiler flags: -std=c++11, -std=c++0x</li>
    </ul>
</div>
