#include <iostream>
#include <memory>
#include <list>

using namespace std::string_literals;

struct SuperThingie {
    virtual void print_shizzle() const = 0;
    virtual ~SuperThingie() {};
};

struct AThingie : SuperThingie {
    int x, y;

    AThingie(int x, int y) :
        x{x},
        y{y}
    {}

    virtual ~AThingie() {
        std::cout << "AThingie() " << to_string() << std::endl;
    }

    [[nodiscard]]
    std::string to_string() const {
        return ""s + std::to_string(x) + ", " + std::to_string(y);
    }

    void print_shizzle() const override {
        std::cout << "AThingie: " << to_string() << std::endl;
    }
};

struct AnotherThingie : SuperThingie {
    std::string some_text;

    explicit AnotherThingie(std::string && some_text) :
        some_text(some_text)
    {}

    virtual ~AnotherThingie() {
        std::cout << "~AnotherThingie() " << some_text << std::endl;
    }

    void print_shizzle() const override {
        std::cout << "AnotherThingie: " << some_text << std::endl;
    }
};

void visit_thingie(const SuperThingie * item) {
    std::cout << "visit_thingie: ";
    item->print_shizzle();
}

void visit_thingie_by_reference(const SuperThingie & item) {
    std::cout << "visit_thingie_by_reference: ";
    item.print_shizzle();
}

// I assume this one is a really bad idea...
void visit_the_unique_ptr(const std::unique_ptr<SuperThingie> &item_ptr) {
    std::cout << "visit_the_unique_ptr: ";
    item_ptr->print_shizzle();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unique_ptr<AThingie> thingie = std::make_unique<AThingie>(1, 2);

    std::cout << thingie->to_string() << std::endl;
    thingie->print_shizzle();

    std::list<std::unique_ptr<SuperThingie>> thingies{};

    thingies.push_back(std::make_unique<AThingie>(3, 4));
    thingies.push_back(std::make_unique<AThingie>(5, 6));
    thingies.push_back(std::make_unique<AnotherThingie>("seven, eight"s));

    std::cout << "List coming up:" << std::endl;
    for (const auto &item: thingies) {
        visit_thingie(item.get());
        visit_thingie_by_reference(*item);
        visit_the_unique_ptr(item);
    }

//    thingies.pop_back();
//    thingies.pop_back();
//    thingies.pop_back();

    std::cout << "the end" << std::endl;

    return 0;
}
