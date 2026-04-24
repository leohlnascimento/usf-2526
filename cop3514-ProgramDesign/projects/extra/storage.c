/*
    Implementation of the storage data structure and its associated 
    functions defined in storage.h.
    See header file for documentation on each of the following functions.
*/

#include "storage.h"

// TODO implement this function based on its documentation in storage.h
Storage* storage_create(void){
    // TODO insert your code here
}


// TODO implement this function based on its documentation in storage.h
void storage_destroy(Storage *storage){
    // TODO insert your code here
}


// TODO implement this function based on its documentation in storage.h
int storage_add_function(Storage *storage, function_pointer_t function){
    // TODO insert your code here
}


char *(*storage_get_function(Storage *storage, size_t index))(const char *){
    if (!storage || index >= storage->functions_array_size) {
        return NULL;
    }
    return storage->functions_array[index];
}


size_t storage_get_size(Storage *storage){
    if (!storage) {
        return 0;
    }
    return storage->functions_array_size;
}


// TODO implement this function based on its documentation in storage.h
char **storage_execute_all(Storage *storage, const char *input){
    // TODO insert your code here
}
