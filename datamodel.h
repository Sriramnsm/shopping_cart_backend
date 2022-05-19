#include<string>
#include <unordered_map>
using namespace std;
// Product, Item, Cart

// Forward Declaration because we have declared these to classes as friend classes in Product class
class Item;
class Cart;

class Product {
	int id;
	string name;
	int price;
public:
	Product() {

	}
	// Constructor
	Product(int u_id, string name, int price) {
		// Assignment of values
		id = u_id;
		this->name = name;
		this->price = price;
	}
	// Display Items
	string getDisplayName() {
		return to_string(id) + " " + name + " : Rs " + to_string(price) + '\n';
	}

	string getShortName() {
		// return name.substr(0, 1);
		return to_string(id);
	}
	friend class Item;
	friend class Cart;

};

class Item {
	Product product;
	int quantity;
public:
	Item() {}
	// Constuctor Initialization list
	Item(Product p, int q): product(p), quantity(q) {};
	int getItemPrice() {
		return quantity * product.price;
	}

	string getItemInfo() {
		return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + '\n';
	}
	friend class Cart;
};

class Cart {
	unordered_map<int, Item> items;
public:
	// Adds available products to the cart
	void addProduct(Product product) {
		if (items.count(product.id) == 0) {
			Item newItem(product, 1);
			items[product.id] = newItem;
		}
		else {
			items[product.id].quantity += 1;
		}
	}

	// Calculates the total cost of items in the cart
	int getTotal() {
		int total = 0;
		for (auto itemPair : items) {
			auto item = itemPair.second;
			total += item.getItemPrice();
		}
		return total;
	}
	// To view the items in the cart
	string viewCart() {
		if (items.empty()) {
			return "Cart is empty";
		}
		string itemizedList;
		int cart_total = getTotal();

		for (auto itemPair : items) {
			auto item = itemPair.second;
			itemizedList.append(item.getItemInfo());
		}
		return itemizedList + '\n' + "Total Amount : Rs. " + to_string(cart_total) + '\n';
	}

	// Checks if the cart is empty or not
	bool isEmpty() {
		return items.empty();
	}
};