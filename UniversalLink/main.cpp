#include <iostream>
#include <vector>

class Widget
{
    
};

template <typename T>
void foo(T && param)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void bar(Widget && param)
{
    foo(param);
}

Widget & makeWidgetAndReturnLvalueLink()
{
    Widget * w1 = new Widget();
    Widget * w2 = new Widget();
    
    return rand() ? *w1 : *w2;
}

Widget && makeWidgetAndReturnRvalueLink()
{
    Widget w1 = Widget();
    Widget w2 = Widget();
    
    return rand() ? std::move(w1) : std::move(w2);
}

Widget simpleMakeWidget()
{
    return Widget();
}

void f(Widget && param); // rvalue-ссылка
Widget && var1 = Widget(); // rvalue-ссылка
template <typename T>
void f(std::vector<T> && param); // rvalue-ссылка

auto && var2 = var1; // не rvalue-ссылка
template <typename T>
void f(T && param); // не rvalue-ссылка

int main(int argc, const char * argv[]) {
    
    Widget lvo;
    foo(lvo);
    Widget & lvo_lvl = lvo;
    foo(lvo_lvl);
    bar(simpleMakeWidget());
    foo(simpleMakeWidget());
    foo(makeWidgetAndReturnLvalueLink());
    foo(makeWidgetAndReturnRvalueLink());
    

    return 0;
}
