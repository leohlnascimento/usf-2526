/*
    Implementation of the storage data structure and its associated 
    functions defined in storage.h.
    See header file for documentation on each of the following functions.
*/

#include "storage.h"

// TODO implement this function based on its documentation in storage.h
Storage* storage_create(void){
    Storage* storage = (Storage*)malloc(sizeof(Storage));
    if (!storage) {
        return NULL;
    }
    storage->functions_array = NULL;
    storage->functions_array_size = 0;
    return storage;
}


// TODO implement this function based on its documentation in storage.h
void storage_destroy(Storage *storage){
    if (!storage) {
        return;
    }
    if (storage->functions_array) {
        free(storage->functions_array);
    }
    free(storage);
}


// TODO implement this function based on its documentation in storage.h
int storage_add_function(Storage *storage, function_pointer_t function){
    if (!storage || !function) {
        return -1;
    }
    
    function_pointer_t* new_array;
    if (storage->functions_array == NULL) {
        // First function being added
        new_array = (function_pointer_t*)malloc(sizeof(function_pointer_t));
    } else {
        // Reallocate to add one more function
        new_array = (function_pointer_t*)realloc(storage->functions_array, 
                                                  (storage->functions_array_size + 1) * sizeof(function_pointer_t));
    }
    
    if (!new_array) {
        return -1;
    }
    
    storage->functions_array = new_array;
    storage->functions_array[storage->functions_array_size] = function;
    storage->functions_array_size++;
    
    return 0;
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
    if (!storage || !input) {
        return NULL;
    }
    
    size_t size = storage->functions_array_size;
    char** results = (char**)malloc(size * sizeof(char*));
    if (!results) {
        return NULL;
    }
    
    char* current_input = (char*)input;
    
    for (size_t i = 0; i < size; i++) {
        function_pointer_t func = storage->functions_array[i];
        char* result = func(current_input);
        
        if (!result) {
            // If a function returns NULL, free all previous results and clean up
            for (size_t j = 0; j < i; j++) {
                free(results[j]);
            }
            free(results);
            return NULL;
        }
        
        // Store the result
        results[i] = result;
        
        // Next iteration will use this result as input
        current_input = result;
    }
    
    return results;
}
