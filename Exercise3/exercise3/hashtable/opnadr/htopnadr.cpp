
namespace lasd {

/* ************************************************************************** */

//Default constructor
template <typename Data>
HashTableOpnAdr<Data>:: HashTableOpnAdr(){
    tableSize = MIN_SIZE;
    size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    table.Resize(tableSize);
    flags.Resize(tableSize);

    for(unsigned long i=0; i<tableSize; i++){
        flags[i] = 'E';
    }
}

/* ************************************************************************** */

}
