#!/bin/bash

failed=0
total=0

# 1: file, 2: pattern, 3: task
function check_regex() {
    (( total++ ))

    egrep -z "$2" "$1" > /dev/null

    if [[ $? != 0 ]]; then
        (( failed++ ))
        echo "❌ $3"
        return 1
    fi

    echo "✅ $3"
    return 0
}

function check_static_assert() {
    check_regex "../../shapes/Circle.cpp" "static_assert\(\s*((M_PI\s*!=\s*3\.14)|(3\.14\s*!=\s*M_PI))" "static_assert"
}

function check_using_alias() {
    check_regex "../../shapes/main.cpp" "using\s*Collection\s*=\s*vector\s*<\s*shared_ptr\s*<\s*Shape\s*>\s*>" "using alias"
}

function check_enum() {
    check_regex "../../shapes/Shape.hpp" "enum\s*class\s*Color\s*:\s*unsigned\s*char\s*{" "enum class"
    check_regex "../../shapes/Shape.hpp" "Color\s*color" "enum class member"
}

function check_for_loop() {
    (( total++ ))

    num_for_loops=$( grep -P "for\s*\(\w*\s*auto&?\s*\w+\s*:\s*collection\)" "../../shapes/main.cpp" | wc -l )

    if [[ $num_for_loops < 2 ]]; then
        (( failed++ ))
        echo "❌ range-based for loops"
        return 1
    fi

    echo "✅ range-based for loops"
    return 0
}

function check_auto() {
    check_regex "../../shapes/main.cpp" "auto\s*\w+\s*=\s*std::find_if\(" "auto"
}

function check_default() {
    check_regex "../../shapes/Circle.hpp" "Circle\(const\s*Circle\s*&\s*other\)\s*=\s*default;" "default copy ctor - Circle"
    check_regex "../../shapes/Rectangle.hpp" "Rectangle\(const\s*Rectangle\s*&\s*other\)\s*=\s*default;" "default copy ctor - Rectangle"
    check_regex "../../shapes/Square.hpp" "Square\(const\s*Square\s*&\s*other\)\s*=\s*default;" "default copy ctor - Square"
}

function check_delete() {
    check_regex "../../shapes/Circle.hpp" "Circle\(\)\s*=\s*delete;" "delete ctor - Circle"
    check_regex "../../shapes/Square.hpp" "Square\(\)\s*=\s*delete;" "delete ctor - Square"
    check_regex "../../shapes/Rectangle.hpp" "Rectangle\(\)\s*=\s*delete;" "delete ctor - Rectangle"
    check_regex "../../shapes/Square.hpp" "double\s*getY\(\)\s*=\s*delete;" "delete getY - Square"
}

function check_final() {
    check_regex "../../shapes/Circle.hpp" "Circle\s*final" "final - Circle"
    check_regex "../../shapes/Rectangle.hpp" "virtual\s*double\s*getX\(\)\s*const\s*final;" "final - Rectangle"
}

function check_override() {
    check_regex "../../shapes/Circle.hpp" "double\s*getArea\(\)\s*const\s*override;" "override Circle - getArea"
    check_regex "../../shapes/Circle.hpp" "double\s*getPerimeter\(\)\s*const\s*override;" "override Circle - getPerimeter"
    check_regex "../../shapes/Circle.hpp" "void\s*print\(\)\s*const\s*override;" "override Circle - print"
}

function check_initializer_list() {
    check_regex "../../shapes/main.cpp" "Collection\s+shapes\s*{(\s*.*)*};" "initializer_list - collection"
}

function check_color_ctor() {
    check_regex "../../shapes/Shape.hpp" "Shape\s*\(Color\s*\w+\)" "Shape color ctor"
    check_regex "../../shapes/Shape.hpp" "Shape\s*\(\s*\)\s*=\s*default;" "Shape default ctor"
    check_regex "../../shapes/Circle.hpp" "double\s*r_\s*{\s*};" "Circle default initalization"
    check_regex "../../shapes/Rectangle.hpp" "double\s*x_\s*{\s*};" "Rectangle default initalization - x_"
    check_regex "../../shapes/Rectangle.hpp" "double\s*y_\s*{\s*};" "Rectangle default initalization - y_"
}

function check_attributes() {
    check_regex "../../shapes/Circle.hpp" "\[\[deprecated.*\]\]\s*double\s+getPi\s*\(\s*\)" "Circle deprecated attribute"
}

function check_alignment() {
    check_regex "../../shapes/Circle.hpp" "class\s*alignas\([0-9]*\)\s*Circle" "Circle alignas"
    check_regex "../../shapes/main.cpp" "alignof\(Circle\)" "Circle alignof"
}

function check_lambda() {
    check_regex "../../shapes/main.cpp" "auto\s+sortByArea\s*=\s*\[\]\(.*\)\s*{" "Lambda - sortByArea"
    check_regex "../../shapes/main.cpp" "auto\s+perimeterBiggerThan20\s*=\s*\[\]\(.*\)\s*{" "Lambda - perimeterBiggerThan20"
    check_regex "../../shapes/main.cpp" "auto\s+areaLessThanX\s*=\s*\[x\s*=\s*10\]\(.*\)\s*{" "Lambda - areaLessThanX"
    check_regex "../../shapes/main.cpp" "void\s+findFirstShapeMatchingPredicate\s*\(.*,\s*(std::)?function<bool\(shared_ptr<Shape>\)>\s*predicate,\s*.*\)\s*{" "Lambda - std::function"
}

function check_structured_binding() {
    check_regex "../../shapes/main.cpp" "(std::)?map<shared_ptr<Shape>,\s*double>\s*\w*" "Structured binding - map of shapes"
    check_regex "../../shapes/main.cpp" "for\s*\((const\s*)?auto\s*&?\s*\[\w+,\s*\w+\]\s*:\s*\w+\)\s*{" "Structured binding - for loop"
}

function check_fibonacci() {
    check_regex "../../shapes/fibonacci.hpp" "\w+\s+fibonacci\(\w+\s+\w+\)\s*{" "Fibonacci existance"
    check_regex "../../shapes/main.cpp" "fibonacci\(45\)" "Fibonacci usage in main"
}

function check_noexcept() {
    getArea_pattern="double\s+getArea\s*\(\)\s*\w*\s*noexcept"
    getPerimeter_pattern="double\s+getPerimeter\s*\(\)\s*\w*\s*noexcept"

    check_regex "../../shapes/Circle.hpp" "$getArea_pattern" "Circle - getArea noexcept"
    check_regex "../../shapes/Circle.hpp" "$getPerimeter_pattern" "Circle - getPerimeter noexcept"

    check_regex "../../shapes/Rectangle.hpp" "$getArea_pattern" "Rectangle - getArea noexcept"
    check_regex "../../shapes/Rectangle.hpp" "$getPerimeter_pattern" "Rectangle - getPerimeter noexcept"

    check_regex "../../shapes/Square.hpp" "$getArea_pattern" "Square - getArea noexcept"
    check_regex "../../shapes/Square.hpp" "$getPerimeter_pattern" "Square - getPerimeter noexcept"

    check_regex "../../shapes/Shape.hpp" "$getArea_pattern" "Shape - getArea noexcept"
    check_regex "../../shapes/Shape.hpp" "$getPerimeter_pattern" "Shape - getPerimeter noexcept"
}

function check_variadic() {
    check_regex "../../shapes/make_shape.hpp" "template\s*<class\s*DerivedType,\s*class\.\.\.\s*Arguments>\s*std::shared_ptr<Shape>\s*make_shape\(Arguments&&\.\.\.\s*args\)\s*{" "Variadic template"
    check_regex "../../shapes/make_shape.hpp" "std::forward<Arguments>\(args\)\.\.\." "Variadic template - perfect forwarding"
}

function check_delegating_ctors() {
    check_regex "../../shapes/Circle.hpp" "Circle\(double\s+\w+,\s*Color\s+\w+\)" "Delegating ctors - Circle new ctor"
    check_regex "../../shapes/Circle.cpp" "Circle::Circle\(double\s+\w+\)\s*:\s*Circle\(\w+,\s*Color::\w+\)" "Delegating ctors - Circle delegating ctor"

    check_regex "../../shapes/Rectangle.hpp" "Rectangle\(double\s+\w+,\s*double\s+\w+,\s*Color\s+\w+\)" "Delegating ctors - Rectangle new ctor"
    check_regex "../../shapes/Rectangle.cpp" "Rectangle::Rectangle\(double\s+\w+,\s*double\s+\w+\)\s*:\s*Rectangle\(\w+,\s*\w+,\s*Color::\w+\)" "Delegating ctors - Rectangle delegating ctor"

    check_regex "../../shapes/Square.hpp" "Square\(double\s+\w+,\s*Color\s+\w+\)" "Delegating ctors - Square new ctor"
    check_regex "../../shapes/Square.cpp" "Square::Square\(double\s+\w+\)\s*:\s*Square\(\w+,\s*Color::\w+\)" "Delegating ctors - Square delegating ctor"
}

function summary() {
    if [[ $failed -eq 0 ]]; then
        echo "🍾 All checks have passed"
    else
        echo "❌ ${failed}/${total} failed"
        echo
        echo "If you think this is a bug in the checking script please raise an Issue in this repo and describe the problem. Don't forget to attach a link to this PR via #PR_Number"
    fi

    return $failed
}
