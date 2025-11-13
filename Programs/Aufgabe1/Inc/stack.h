
#ifndef STACK_H
#define STACK_H

#include "errors.h"
#include <stdbool.h>

typedef struct Stack Stack;
struct Stack{
    //Variablen
    int size;
    int top;
    int *arr;
    //Funktions-pointer

    /*
    * @Brief 
    * Fügt einen Wert auf den Stack hinzu, wenn der Stack nicht voll ist.
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * val: Der Wert der auf den Stack gelegt wird
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * NO_Value wird Ausgegeben, wenn ein NULL Pointer für den Wert übergeben wurde
    * STACK_OVERFLOW wird Ausgegeben, wenn der Wert nicht hinzugefügt werden kann, weil der Stack voll ist
    */
    int (*push)(Stack *self, int val);

    /*
    * @Brief 
    * Gibt den obersten Wert auf den Stack aus und löscht diesen, wenn der Stack nicht leer ist.
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * val: Pointer auf die Variable auf dem der Rückgabewert übergeben wird
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * NO_Value wird Ausgegeben, wenn ein NULL Pointer für den Wert übergeben wurde
    * STACK_UNDERFLOW wird Ausgegeben, wenn der Wert nicht ausgegeben werden kann, weil der Stack leer ist
    */
    int (*pop)(Stack *self, int* val);

    /*
    * @Brief 
    * Gibt den Wert an der Position des Index aus, wenn der Stack nicht leer ist.
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * index: Der Index Gibt an welcher Wert aus dem Stack gelesen werden soll
    * val: Pointer auf die Variable auf dem der Rückgabewert übergeben wird
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * NO_Value wird Ausgegeben, wenn ein NULL Pointer für den Wert übergeben wurde
    * STACK_UNDERFLOW wird Ausgegeben, wenn der Wert nicht ausgegeben werden kann, weil der Stack leer ist
    * INDEX_OUT_OF_BOUND wird Ausgegeben, wenn der Indexwert größer als die Anzahl im Stack liegender Werte ist oder wenn der Index kleiner 0 ist
    */
    int (*peak)(Stack *self, int index, int *val);
    
    /*
    * @Brief 
    * Leert den Stack, alte Werte werden aber nicht überschrieben
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    */
    int (*clear)(Stack *self);

    /*
    * @Brief 
    * Dupliziert den obersten Wert im Stack
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * NO_Value wird Ausgegeben, wenn ein NULL Pointer für den Wert übergeben wurde
    * STACK_UNDERFLOW wird Ausgegeben, wenn der Wert nicht ausgegeben werden kann, weil der Stack leer ist
    * STACK_OVERFLOW wird Ausgegeben, wenn der Wert nicht hinzugefügt werden kann, weil der Stack voll ist
    * INDEX_OUT_OF_BOUND wird Ausgegeben, wenn der Indexwert größer als die Anzahl im Stack liegender Werte ist oder wenn der Index kleiner 0 ist
    */
    int (*duplicate)(Stack *self);

    /*
    * @Brief 
    * Tauscht die beiden obersten Werte im Stack.
    * @Param 
    * self: Pointer auf den Stack der die Funktion aufruft
    * @Return 
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * STACK_NO_ARRAY wird Ausgegeben, wenn ein NULL Pointer für das Array existiert
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * NO_Value wird Ausgegeben, wenn ein NULL Pointer für den Wert übergeben wurde
    * STACK_UNDERFLOW wird Ausgegeben, wenn der Wert nicht ausgegeben werden kann, weil der Stack leer ist. Wenn STACK_UNDERFLOW beim zweiten stack.pop() Aufruf stattfindet, wird der erste Wert vorher wieder auf den Stack gepusht.
    * STACK_OVERFLOW wird Ausgegeben, wenn der Wert nicht hinzugefügt werden kann, weil der Stack voll ist
    */
    int (*swap)(Stack *self);

    /*
    * @Brief
    * Löscht alle Referenzen die der Stack besitzt und gibt Speicher wieder frei.
    * @Param
    * self: Pointer auf den Stack der die Funktion aufruft
    * @Return
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    */
    int (*delete)(Stack *self);
}typedef Stack;

    /*
    * @Brief
    * Initialisiert den Stack mit allen Pointern und allokiert speicher für das Array
    * @Param
    * stack_ptr: Pointer auf den Stack der die Funktion aufruft
    * size: Maximal größe des Stacks
    * @Return
    * EOK wird Ausgegeben, wenn keine Fehler aufgetreten sind
    * NO_STACK wird Ausgegeben, wenn ein NULL Pointer für den Stack übergeben wurde
    * STACK_SIZE_INVALID wird Ausgegeben, wenn die maximal Größe des Stacks <= 0 ist
    */
int newStack(Stack* stack_ptr, int size);
#endif
//eof