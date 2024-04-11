#include "dictionary.hpp"
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data> :: InsertAll(const TraversableContainer<Data> & container){
    
    bool allInserted = true;

    // Funzione lambda per l'inserimento di ciascun elemento
    auto insertFunction = [this, &allInserted](const Data & element){

        // Prova ad inserire l'elemento e aggiorna allInserted in base al successo dell'inserimento
        allInserted &= Insert(element);
    };

    // Attraversa il container e prova ad inserire ogni elemento
    container.Traverse(insertFunction);

    //ritorna true se tutti gli elementi sono stati inseriti
    return allInserted;
}

template<typename Data>
bool DictionaryContainer<Data> :: InsertAll(MappableContainer<Data> && container){
    
    bool allInserted = true;
    
    // Funzione lambda per l'inserimento di ciascun elemento
    auto insertFunction = [this, &allInserted](const Data & element){

        // Prova ad inserire l'elemento e aggiorna allInserted in base al successo dell'inserimento
        allInserted &= Insert(element);
    };

    // Attraversa il container e prova ad inserire ogni elemento
    container.Map(insertFunction);

    //ritorna true se tutti gli elementi sono stati inseriti
    return allInserted;
}

template<typename Data>
bool DictionaryContainer<Data> :: RemoveAll(const TraversableContainer<Data> & container){

    bool allRemoved = true;

    auto removeFunction = [this, &allRemoved](const Data & element){

        allRemoved &= Remove(element);
    };

    container.Traverse(removeFunction);

    //ritorna true se tutti gli elementi sono stati rimossi
    return allRemoved;
}


template<typename Data>
bool DictionaryContainer<Data> :: InsertSome(const TraversableContainer<Data> & container){

    bool someInserted = false;

    auto insertSomeFunction = [this, &someInserted](const Data & element){

            someInserted |= Insert(element);
    };

    container.Traverse(insertSomeFunction);

    //ritorna true se almeno un elemento è stato inserito 
    return someInserted;
}

template<typename Data>
bool DictionaryContainer<Data> :: InsertSome(MappableContainer<Data> && container){

    bool someInserted = false;

    auto insertSomeFunction = [this, &someInserted](const Data & element){

            someInserted |= Insert(element);
    };

    container.Map(insertSomeFunction);

    //ritorna true se almeno un elemento è stato inserito 
    return someInserted;
}


template<typename Data>
bool DictionaryContainer<Data> :: RemoveSome(const TraversableContainer<Data> & container){

    bool someRemoved = false;

    auto removeSomeFunction = [this, &someRemoved](const Data & element){

        someRemoved |= Remove(element);
    };

    container.Traverse(removeSomeFunction);

    //ritorna true se tutti gli elementi sono stati rimossi
    return someRemoved;
}
/* ************************************************************************** */

}
