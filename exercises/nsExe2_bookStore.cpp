#include <iostream>

class bookInfo {
private:
    int code_;
    float price_;
    int inventory_;
    int enrollment_;
    int orderAmount_;
    bool reqd_;
    bool new_;
public:
    void init();
    void display();
    float output();
};

void bookInfo::init() {
    std::cout << "Please enter the book code: ";
    std::cin >> code_;
    std::cout << " single copy price: ";
    std::cin >> price_;
    std::cout << " number on hand: ";
    std::cin >> inventory_;
    std::cout << " prospective enrollment: ";
    std::cin >> enrollment_;
    std::cout << " 1 for reqd/0 for optional: ";
    std::cin >> reqd_;
    std::cout << " 1 for new/0 for used: ";
    std::cin >> new_;
    std::cout << "***************************************************" << std::endl;
}

void bookInfo::display() {
    std::cout << "Book: " << code_ << std::endl;
    std::cout << "Price: $" << price_ << std::endl;
    std::cout << "Inventory: " << inventory_ << std::endl;
    std::cout << "Enrollment: " << enrollment_ << std::endl << std::endl;
    std::cout << "This book is " << (reqd_ ? "required" : "optional") << " and " << (new_ ? "new." : "used.") << std::endl;
    std::cout << "***************************************************" << std::endl;
}

float bookInfo::output() {
    float percent = 0;

    if (new_ && reqd_)
        percent = 0.9;
    else if (!new_ && reqd_)
        percent = 0.65;
    else if (new_ && !reqd_)
        percent = 0.4;
    else if (!new_ && !reqd_)
        percent = 0.2;

    orderAmount_ = enrollment_ * percent - inventory_;

    std::cout << "Need to order: " << orderAmount_ << std::endl;
    std::cout << "Total Cost: $" << orderAmount_ * price_ << std::endl;
    std::cout << "***************************************************" << std::endl << std::endl;

    return orderAmount_ * price_;
}

int main(void) {
    float cost = 0;
    float totalCost = 0;
    float profit = 0;
    bool addMore = false;
    bookInfo aBook;

    do {
        aBook.init();
        aBook.display();
        cost = aBook.output();

        std::cout << "Enter 1 to do another book, 0 to stop.";
        std::cin >> addMore;
        std::cout << "***************************************************" << std::endl;

        totalCost += cost;
    } while(addMore);

    std::cout << "Total for all orders: $" << totalCost << std::endl;
    std::cout << "Profit: $" << totalCost * 0.2 << std::endl;
    std::cout << "***************************************************" << std::endl;

    return 0;
}