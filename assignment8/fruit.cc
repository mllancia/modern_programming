// fruit and shopping cart
// author:  Holger Arndt
// version: 02.12.2025
// framework for sheet 8, exercise 25

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// fruit vendor shopping cart
// apples and pineapples

class Article {
protected:
  int articleNumber;
public:
  // constructor
  Article (int an): articleNumber(an) {}

  // Virtual destructor
  virtual ~Article() {}
  virtual double getPrice() const = 0;
  virtual void info() const = 0;
};

class Apple: public Article {
private:
  string kind;
  double pricePerKilo;
  double weight;
public:
  Apple (int an, string k, double ppk, double w)
    : Article(an), kind(k), pricePerKilo(ppk), weight(w) {}

  virtual double getPrice() const override { 
    return weight * pricePerKilo; 
  }

  virtual void info() const override
  {  
    cout << "Apples of kind " << kind  << ", article no.: " << articleNumber << ", price per kg: " 
        << pricePerKilo << "€, weight: " << weight << "kg";
  }
};

class Pineapple: public Article {
private:
  string countryOfOrigin;
  double piecePrice;
  int quantity;
public:
  Pineapple (int an, string coo, double pp, int q)
    : Article(an), countryOfOrigin(coo), piecePrice(pp), quantity(q) {}
  virtual double getPrice() const override 
  { 
    if (countryOfOrigin == "Brazil")
    {
      return piecePrice * ceil(quantity / 2); // round up here
    } 
    else
    {
      return piecePrice * quantity;
    }
  }

  virtual void info() const override
  {  
    // Pineapples from Brazil, article no.: 276543, piece price: 3.29€, quantity: 3 * buy one, get one free *
    cout << "Pineapples from " << countryOfOrigin  << ", article no.: " << articleNumber << ", piece price: " 
        << piecePrice << "€, quantity: " << quantity;
    if (countryOfOrigin == "Brazil")
    {
      cout << " * buy one, get one free *";
    }
  }
};

class ShoppingCart {
private:
  // array of pointers to articles and number of articles
  Article** articles;
  int length;

public:
  ShoppingCart(): articles(nullptr),length(0) {}

  // Destructor to clean up  
  ~ShoppingCart() {
    for (int i = 0; i < length; i++) {
      delete articles[i];
    }
    delete[] articles;
  }

    void add(const Article& a) {
      // Create new array with one more position
      Article** newArticles = new Article*[length + 1];
      
      // Copy old elements
      for (int i = 0; i < length; i++) {
        newArticles[i] = articles[i];
      }
      
      // Add new article (need to create a copy)
      // Determine type and create appropriate copy
      if (const Apple* apple = dynamic_cast<const Apple*>(&a)) {
        newArticles[length] = new Apple(*apple);
      } else if (const Pineapple* pineapple = dynamic_cast<const Pineapple*>(&a)) {
        newArticles[length] = new Pineapple(*pineapple);
      }
      
      // Deallocate old array
      delete[] articles;
      
      // Update to new array
      articles = newArticles;
      length++;
    }
  double getPrice() const {
    double total = 0.0;
    for (int i = 0; i < length; i++) {
      total += articles[i]->getPrice();
    }
    return total;
  }

  void info() const {
    if (length == 0) {
      cout << "The shopping cart is empty!" << endl;
    } else {
      cout << "Content of the shopping cart:" << endl;
      
      for (int i = 0; i < length; i++) {
        articles[i]->info();
      }
    }
  }
};

int main()
{
  Apple a1{123456, "Braeburn", 2.99, 0.85};
  Apple a2{123462, "Red Delicious", 2.69, 1.1};
  Pineapple p1{276543, "Brazil", 3.29, 3};
  Pineapple p2{276540, "Costa Rica", 4.15, 1};

  cout << "Creating new shopping cart." << endl;
  ShoppingCart sc;
  sc.info();

  cout << "\nFilling shopping cart …" << endl;
  sc.add(a1);
  sc.add(a2);
  sc.add(p1);
  sc.add(p2);
  sc.info();

  cout << "\nTotal price: "
       << fixed << setprecision(2) << sc.getPrice() << "€" << endl;
}
