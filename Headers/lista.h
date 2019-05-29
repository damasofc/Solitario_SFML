#ifndef LISTA_H
#define LISTA_H
#include <iostream>

template <typename T>
class nodo
{
public:
    T valor;
    nodo *siguiente;
    nodo(T val)
    :valor(val),siguiente(NULL)
    {
        siguiente = 0;
    }
};

template <typename T>
class lista
{
private:
    nodo<T>* inicio;
    nodo<T>* fin;
    int cantElementos;
    
    
public:
    lista()
    {
        inicio = NULL;
        fin = NULL;
        cantElementos = 0;
    }
    int size()
    {
        return cantElementos;
    }
    lista<T> subLista(int ini, int fin)
    {
        lista<T> miLista;
        if(ini < 0 || fin > (this->cantElementos-1))
            return miLista;
        nodo<T>* it = this->inicio;
        int cont = 0;
        for(int i = ini; i <= fin; i++)
        {
            miLista.insertar(this->get(i),cont);
            it = it->siguiente;
            cont++;
        }
        return miLista;
    }
    lista<T> clonar()
    {
        lista<T> miLista;
        nodo<T>* it = this->inicio;
        for(int i = 0; i < this->cantElementos; i++)
        {
            miLista.insertar(it->valor,i);
            it = it->siguiente;
        }
        return miLista;
    }
    lista<T> interseccion(lista<T> lis)
    {
        lista<T> miLista = lis.unir(*this);
        nodo<T>* it = miLista.inicio;
        for(int i = 0; i < miLista.size(); i++)
        {
            if(this->buscar(it->valor) != -1 && lis.buscar(it->valor) != -1)
            {
                it = it->siguiente;
                continue;
            }
            miLista.eliminar(i);
        }
        return miLista;
        
    }
    lista<T> unir(lista<T> lis)
    {
        lista<T> miLista;
        nodo<T>* it = lis.inicio;
        nodo<T>* it1 = this->inicio;
        for(int i = 0; i < lis.size(); i++)
        {
            miLista.insertar(it->valor,miLista.size());
            it = it->siguiente;
        }
        for(int m = 0; m < this->cantElementos; m++)
        {
            miLista.insertar(this->obtener(m),miLista.size());
            it1 = it1->siguiente;
        }
        it = miLista.inicio;
        for(int i = 0; i < miLista.size(); i++)
        {
            int reps = 0;
            for(int t = 0; t < miLista.size(); t++)
            {
                if(miLista.get(i) == miLista.get(t))
                {
                    reps++;
                }
                if(reps > 1)
                {
                    miLista.eliminar(t);
                    reps--;
                }
            }
            
        }
        
        return miLista;
    }
    int insertar(T val,int pos)
    {
        if(pos > cantElementos || pos < 0)
        {
            return -1;
        }
        nodo<T>* nuevo = new nodo<T>(val);
        if(pos == 0)
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
            if(cantElementos == 0)
                fin = nuevo;
        }
        else if(pos == cantElementos)
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        else
        {
            nodo<T>* temp = inicio;
            for(int i = 0; i < (pos-1); i++)
            {
                temp = temp->siguiente;
            }
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
            return 0;
        }
        this->cantElementos++;
    }
    T get(int pos)
    {
        nodo<T>* temp = this->inicio->siguiente;
        if(pos < 0 || pos > (this->cantElementos-1))
        {
            return T();
        } 
        else if(pos == 0)
        {
            return this->inicio->valor;
        }
        else if(pos == (this->cantElementos-1))
        {
            return this->fin->valor;
        }

        for(int i = 1; i < this->cantElementos; i++)
        {
            if(pos == i)
                return temp->valor;
            temp = temp->siguiente;
            
        }
        return T();
    }
    int buscar(T val)
    {
        nodo<T>* temp = inicio;
        for(int i = 0; i < this->cantElementos; i++)
        {
            if(temp->valor == val)
                return i;
            temp = temp->siguiente;
            
        }
        return -1;
    }
    T eliminar(int pos)
    {
        if(pos < 0 || pos >= this->cantElementos)
        {
            return T();
        }
        nodo<T>* eliminar;
        if(pos ==0)
        {
            eliminar = inicio;
            inicio = inicio->siguiente;
        }
        else
        {
            nodo<T>* tmp =  inicio;
            for(int i = 0; i < pos-1; i++)
            {
                tmp = tmp->siguiente;
            }
            eliminar = tmp->siguiente;
            tmp->siguiente = tmp->siguiente->siguiente;
            if(tmp->siguiente != NULL)
            {
                 
            }
            else
            {
                fin = tmp;
            }
        }
        if(this->cantElementos == 1)
        {
            fin == NULL;
        }
        this->cantElementos--;
        T eliminado = eliminar->valor;
        delete eliminar;
        return eliminado;
    }
    void push_back(T val)
    {
        insertar(val,cantElementos);
    }
    void pop_front()
    {
        eliminar(0);
    }
    void push_front(T val)
    {
        insertar(val,0);
    }
    void remove(T val)
    {
        int pos = buscar(val);
        if(pos!=-1)
        {
            eliminar(pos);
        }
    }
    T front()
    {
        return inicio->valor;
    }
    T back()
    {
        return fin->valor;
    }
};
#endif
