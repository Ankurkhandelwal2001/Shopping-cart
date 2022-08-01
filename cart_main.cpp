#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;

vector<product> allproducts = {
    product{1,"apple",26},
    product{3,"mango",16},
    product{2,"guava",36},
    product{5,"banana",56},
    product{4,"strawberry",29},
    product{6,"pinnapple",20},
    
};
product chooseproduct(){
    //Display the list of products 
    string productList;
    cout<<"Available Products"<<endl;
    for(auto product: allProducts){
        productList.append(product.getDisplayName());
    }
    cout <<productList<<endl;
    cout<<"------------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allproducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allproducts[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;


}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in cash";
    int paid;
    cin>>paid;
    if(paid >= total ){
        cout<<"Change "<<paid -total <<endl;
        cout<<" Thank you for shopping! ";
        return true;
    }
    else {
        cout<<"Not enough cash!";
        return false;
    }
}


int main(){
    char action;
    Cart cart;
    while (true){
        cout<<"select an action - (a)dd item ,(v)iew cart, (c)heckout"<<endl;
    
    if(action=='a'){
        //TODO: Add to cart
        // View All Products + Choose Product + Add to the cart
        Product * product = chooseproduct();
        if(product!=NULL){
            cout<<"Added to the Cart"<<product->getDisplayName()<<endl;
            cart.addproduct(*product);
        }


    }
    else if(action=='v'){
        //view the cart
        cout<<"----------------"<<endl;
        cout<< cart.viewCart();
        cout<<"-----------------"<<endl;


    }
    else {
        //checkout
        cart.viewCart();
        if(checkout(cart)){
            break;
        }

    }
  
    }
    return 0;
}

