#include <cstddef>
#include <future>
#include <iostream>
#include <algorithm>
#include "header.hpp"
#include <memory>
#include <string>


Tree::Tree(const Node &no): no(no) , num_filhos(0), esq(nullptr), dir(nullptr){}


Tree::~Tree(){}

Tree * Tree::arvore_criaArv(){
    return nullptr;
}


Node * Tree::arv_CriaNo(Node no){
    return new Node(no.code , no.score , no.cpf , no.nome);
}


void  Tree::arv_insere(Tree *raiz , Node no){
    if(raiz == nullptr){
        raiz = new Tree(no);
        std::cout<<"\n\n Nó criado com sucesso! \n\n";
        return;
    }

    if(no.score < raiz -> no.score){
        if(!raiz -> esq){
            raiz -> esq = std::make_unique<Tree>(no);
            std::cout<<"\n\n Nó criado com sucesso! \n\n";

        }
        else{
            arv_insere(raiz -> esq.get() , no);
        }
    }
    else if(no.score > raiz -> no.score){
        if(!raiz -> dir){
            raiz -> dir = std::make_unique<Tree>(no);
            std::cout<<"\n\n Nó criado com sucesso! \n\n";
        } else{
            arv_insere(raiz -> dir.get() , no);
        }
    }

    else{
        std::cout<<"\n\n Nó já existe! \n\n";
    }
}

Tree *Tree::arv_buscaNodeT(Tree * raiz , int codigo){
    if(raiz == nullptr || raiz -> no.code == codigo){
        std::cout << "Arvore vaiza meu caro \n\n "<< std::endl;
        return raiz;
    }

    if(raiz -> esq && raiz -> dir){
        std::future<Tree*> esqFreak = std::async(std::launch::async , &Tree::arv_buscaNodeT, this, raiz->esq.get() , codigo );

        Tree * dirFreak = arv_buscaNodeT(raiz -> dir.get() , codigo);

        Tree * esqRes = esqFreak.get();

        return esqRes ? esqRes : dirFreak;
    }

    if( codigo < raiz -> no.code && raiz -> esq){ return arv_buscaNodeT(raiz->esq.get() , codigo);}

    else if(raiz -> dir){ return arv_buscaNodeT(raiz-> dir.get() , codigo);}

    return nullptr;
}

Tree * Tree::arv_buscaNode(Tree * raiz , int codigo){

    if(raiz == nullptr || raiz -> no.code == codigo){
        std::cout<< "Arvore vazia meu caro \n\n";
        return raiz;
    }

    if(codigo < raiz -> no.code){
        return arv_buscaNode(raiz -> esq.get() , codigo);
    }
    else{
        return arv_buscaNode(raiz -> dir.get(),  codigo);
    }
}


bool  Tree::arv_vazia(Tree * raiz){
   return (raiz == nullptr) ? true : false ;
}

bool Tree::arv_removeNode(std::unique_ptr<Tree> &raiz , int code){

    if( !raiz ){
        std::cout<< "arvore vazia, nada a remover ";
        return false;
    }

    if( code < raiz -> no.code ){
        return arv_removeNode( raiz -> esq ,  code);
    }
    else if(code > raiz ->no.code){
        return arv_removeNode(raiz -> dir ,  code);
    }

    //entrou no nó específico
       //sem filhos
      if( !raiz -> esq  && !raiz -> dir ){

          raiz.reset();
          return true;
      }

      //tem pelo menos um filho
      if(!raiz -> esq){
        raiz =  std::move(raiz -> dir);
        return true;
      }

      if(!raiz -> dir){
          raiz = std::move(raiz -> esq);
          return true;
      }


      Tree * aux = raiz -> dir.get();

      while(aux -> esq){
          aux = aux -> esq.get();
      }

    raiz -> no = aux -> no;
    return arv_removeNode(raiz ->dir ,  code);
}

void Tree::arv_imprimeOrdem(Tree *raiz){
    if(!raiz){ return; }

    arv_imprimeOrdem(raiz -> esq.get());
    std::cout << "Code: " << raiz->no.code
                  << " , Score: " << raiz->no.score
                  << " , CPF: " << raiz->no.cpf
                  << " , Nome: " << raiz->no.nome << std::endl;


    arv_imprimeOrdem(raiz -> dir.get());
}

void Tree::arv_imprimePosOrdem(Tree *raiz){
    if (!raiz) {return; }

    arv_imprimePreOrdem(raiz -> esq.get());
    arv_imprimePreOrdem(raiz -> dir.get());

    std::cout << "Code: " << raiz->no.code
                  << " , Score: " << raiz->no.score
                  << " , CPF: " << raiz->no.cpf
                  << " , Nome: " << raiz->no.nome << std::endl;

}

void Tree::arv_imprimePreOrdem(Tree *raiz){
    if (!raiz) {return ;}



    std::cout << "Code: " << raiz->no.code
                  << " , Score: " << raiz->no.score
                  << " , CPF: " << raiz->no.cpf
                  << " , Nome: " << raiz->no.nome << std::endl;


    arv_imprimePreOrdem(raiz -> esq.get());
    arv_imprimePreOrdem(raiz -> dir.get());
}


int Tree::arv_altura(Tree *raiz){
    if(!raiz){
        return 0;
    }

    return 1 + std::max(arv_altura(raiz -> esq.get()) , arv_altura(raiz -> dir.get()));
}
