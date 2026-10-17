// fruit vendor shopping cart
// apples and pineapples

using namespace std;

class Article {
protected:
    int articleNumber;
public:
    // constructor
    Article (int an): articleNumber(an) {}
    virtual double getPrice() const { return 0.0; }
    virtual info() const { return }
};

class Apple: public Article {
private:
    string kind; // probably wrong
    double pricePerKilo;
    double weight;
public:
    Apple (int an, string k, double ppk, double w): Article(an), kind(k), pricePerKilo(ppk), weight(w) {}
    virtual double getPrice() const override { return weight * PricePerKilo; }
    virtual void info() const 
    {  
        cout << "Apples of kind " << k  << ", article no.: " << an << ", price per kg: " 
            << ppk << "€, weight: " << w << "kg" << endl;
    }

};

class Pineapple {
private:
    string countryOfOrigin;
    double piecePrice;
    int quantity;
public:
    Pineapple (int an, sting coo, double pp, int q): Article(an), countryOfOrigin(coo), piecePrice(pp), quality(q) {}
    virtual double getPrice() const override 
    { 
        if (countryOfOrigin == "Brazil")
        {
            return ceil(piecePrice * quantity / 2); // round up here
        } 
        else
        {
            return piecePrice * quantity;
        }
    }

    virtual void info() const 
    {  
        // Pineapples from Brazil, article no.: 276543, piece price: 3.29€, quantity: 3 * buy one, get one free *
        cout << "Pineapples from " << countryOfOrigin  << ", article no.: " << an << ", piece price: " 
            << pieceprice << "€, quantity: " << quantity;
        if (countryOfOrigin == "Brazil")
        {
            cout << " * buy one, get one free *"
        }

        cout << endl;
    }
        

};

class ShoppingCart {
private:
    // array of pointers to articles and number of articles
    Article& articles[];
    int length;

public:
    ShoppingCart(Article& arr[] = {}): articles(arr[]),length(0) {}
    void info()
    ShoppingCart()
    add(const Article& a)
};