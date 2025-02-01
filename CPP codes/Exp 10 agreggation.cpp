#include <iostream>
#include <string>
#include <vector>

class shop;
class shoppingmall;

class shop 
{
private:
    std::string name;
public:
    shop(const std::string& shopname) : name(shopname) {}

    std::string getname() const 
	{
        return name;
    }
};

class shoppingmall {
private:
    std::string name;
    std::vector<shop*> shops;

public:
    shoppingmall(const std::string& mallname) : name(mallname) {}

    void addshop(shop* shop) 
	{
        shops.push_back(shop);
    }

    void displayshops() 
	{
    	std::cout << "shops in " << name << ":\n";
        for (const auto& shop : shops)
		{
            std::cout << "- " << shop->getname() << "\n";
        }
    }
};

int main()
 {
    shop shop1("clothing store");
    shop shop2("bookstore");
    shop shop3("electronics store");

    shoppingmall mall("supermall");

    mall.addshop(&shop1);
    mall.addshop(&shop2);
    mall.addshop(&shop3);

    mall.displayshops();

    return 0;
}
