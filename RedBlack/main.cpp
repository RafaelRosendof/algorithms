#include "RedBlack.hpp"
#include <iostream>
#include <random>
#include <memory>
#include <string>
#include <vector>

Tree::Tree();
Tree::~Tree();

//Criar arrays de nodes para inserir um por um 

int main(){

    Tree::arv_CriarArv();

    auto raiz = std::make_shared<Node>(1, 1, "raiz", Color::BLACK);
    auto no1 = std::make_shared<Node>(2, 2, "no1", Color::RED);
    auto no2 = std::make_shared<Node>(3, 3, "no2", Color::RED);
    auto no3 = std::make_shared<Node>(4, 4, "no3", Color::RED);
    auto no4 = std::make_shared<Node>(5, 5, "no4", Color::RED);
    auto no5 = std::make_shared<Node>(6, 6, "no5", Color::RED);
    auto no6 = std::make_shared<Node>(7, 7, "no6", Color::RED);
    auto no7 = std::make_shared<Node>(8, 8, "no7", Color::RED);
    auto no8 = std::make_shared<Node>(9, 9, "no8", Color::RED);
    auto no9 = std::make_shared<Node>(10, 10, "no9", Color::RED);
    auto no10 = std::make_shared<Node>(11, 11, "no10", Color::RED);
    auto no11 = std::make_shared<Node>(12, 12, "no11", Color::RED); 
    auto no12 = std::make_shared<Node>(13, 13, "no12", Color::RED);
    auto no13 = std::make_shared<Node>(14, 14, "no13", Color::RED);
    auto no14 = std::make_shared<Node>(15, 15, "no14", Color::RED);
    auto no15 = std::make_shared<Node>(16, 16, "no15", Color::RED);
    auto no16 = std::make_shared<Node>(17, 17, "no16", Color::RED);
    auto no17 = std::make_shared<Node>(18, 18, "no17", Color::RED);
    auto no18 = std::make_shared<Node>(19, 19, "no18", Color::RED);
    auto no19 = std::make_shared<Node>(20, 20, "no19", Color::RED);

    

    Tree::arv_InsereRB(raiz , no1);
    Tree::arv_InsereRB(raiz , no2);
    Tree::arv_InsereRB(raiz , no3);
    Tree::arv_InsereRB(raiz , no4);
    Tree::arv_InsereRB(raiz , no5);
    Tree::arv_InsereRB(raiz , no6);
    Tree::arv_InsereRB(raiz , no7);
    Tree::arv_InsereRB(raiz , no8);
    Tree::arv_Remove(raiz , no3);
    Tree::arv_InsereRB(raiz , no9);
    Tree::arv_InsereRB(raiz , no10);
    Tree::arv_InsereRB(raiz , no11);
    Tree::arv_InsereRB(raiz , no12);
    Tree::arv_InsereRB(raiz , no13);
    Tree::arv_InsereRB(raiz , no14);
    Tree::arv_ImprimeOrdem(raiz);
    Tree::arv_InsereRB(raiz , no15);
    Tree::arv_InsereRB(raiz , no16);
    Tree::arv_InsereRB(raiz , no17);
    Tree::arv_InsereRB(raiz , no18);
    Tree::arv_InsereRB(raiz , no19);
    Tree::arv_ImprimeOrdem(raiz);
    Tree::arv_ImprimePreOrdem(raiz);
    Tree::arv_Remove(raiz , no1);
    Tree::arv_ImprimeOrdem(raiz);
}