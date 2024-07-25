//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->setProximo(this->cauda);
    this->cabeca->setAnterior(nullptr);

    this->cauda->setProximo(nullptr);
    this->cauda->setAnterior(this->cabeca);

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
    auto aux = this->cabeca;

	while(aux != nullptr)
	{
		auto outro = aux;
		aux = aux->getProximo();
		delete outro;
	}
}

bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s)
{	
//	throw "\n!!! MÉTODO 'inserirOrdenado' AINDA NÃO FOI IMPLEMENTADO !!! \n";
  /*
	No<std::string> * atual = this->cabeca->getProximo();

	while(atual != this->cauda && atual->getValor() > s)
	{
		atual = atual->getProximo();
	}

	if( atual != this->cauda && atual->getValor() == s )
	{
		return false;
	}

	No<std::string>* novo = new No<std::string>(s);
	novo -> setProximo(atual);
	novo -> setAnterior(atual->getAnterior());
	atual -> getAnterior() -> setProximo(novo);
	atual -> setAnterior(novo);

	this->quantidade++;
	return true;

  */

  auto aux = this->getCabeca()->getProximo();

  while(aux != this->getCauda() && aux -> getValor() > s){
	aux = aux -> getProximo();
  }

  if(aux != this->cauda && aux->getValor() == s){return false;}

  auto novo = new No<std::string>(s);

  novo -> setProximo(aux);
  novo -> setAnterior(aux->getAnterior());

  aux -> getAnterior() -> setProximo(novo);
  aux -> setAnterior(novo);

  this -> quantidade++;
  return true;


}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void)
{
    return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
    return this->tamanho() == 0;
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(No<std::string>* n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

bool ListaDuplamenteEncadeada::checarOrdenacao()
{
	if(this->tamanho() == 0 || this->tamanho() == 1)
	{
		return true;
	}

	for(auto no = this->getCabeca()->getProximo(); no->getProximo() != this->getCauda(); no = no->getProximo())
	{
		No<std::string>* noProx = no->getProximo();
		if(no->getValor() < noProx->getValor())
		{
			return false;
		}
	}

	return true;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->getProximo() == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->getProximo()->getAnterior() != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->getAnterior() != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->getAnterior() == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->getAnterior()->getProximo() != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->getProximo() != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->getProximo() != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->getAnterior() )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->getProximo(); i != this->cauda; i=i->getProximo())
		{
			if( i->getProximo()->getAnterior() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->getAnterior()->getProximo() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
