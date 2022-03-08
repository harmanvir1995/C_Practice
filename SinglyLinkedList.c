#include<stdio.h>
#include<stdlib.h>
typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;

typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode *l;
    };
} element;

typedef struct _listnode {
    element el;
    struct _listnode *next;
} *list;

const element NIL = { .type=LIST, .l=NULL };

/**
atom as element, that returns an element whose content is
set to atom a.
*/
element aasel(atom a) {
    element newElement;
    newElement.type = ATOM;
    newElement.a = a;
    return newElement;
}

/**
list as element, that returns an element whose content is set
to the list, pointed by l.
*/
element lasel(list l){
    element newElement;
    newElement.type = LIST;
    newElement.l = l;
    return newElement;
}

/**
This function returns the head of the list, represented by e; returns
NIL, if e is not a list.
*/
element car(element e) {
    if (e.type != LIST) {
        return NIL;
    }
    return e.l->el;
}

/**
This function returns tail of the list, represented by e. The tail of a list
with one or zero element is NIL. The tail of an element that is not a list is also NIL.
*/
list cdr(element e) {
    if (e.type != LIST || e.l == NULL || e.l->next == NULL) {
        return NULL;
    }
    return e.l->next;
}

/**
that returns the cdr of the cdr of the list, represented by e.
*/
list cddr(element e){
     return cdr(lasel(cdr(e)));
}






/**
This creates a new list whose car and cdr are the
element e and the list l. The memory for the newly created list is to be allocated
dynamicallY.
*/
list cons(element e, list l) {
    list newElement = (list)malloc(sizeof(struct _listnode));
    newElement->el = e;
    newElement->next = l;
    return newElement;
}

/**
This creates a new list whose elements are shallow
copies of elements in l1 and l2, appended.
*/
list append(list l1,list l2) {
    list newlist=l1;
    struct _listnode *last = newlist;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next=l2;
    return newlist;
}


/**
This frees all the memory previously allocated by the whole list
(including all its elements and its inner lists)
*/
void lfreer(list l) {
    list newList = l;
    while (newList != NULL) {
        if (newList->el.type == LIST) {
            lfreer(newList->el.l);
        }
        list temp = newList->next;
        free((void*)newList);
        newList = temp;
    }
}

/**
that prints the content of the element e. If e is an atom, it
prints the char symbol embraced in spaces, and if e it is a list, it (recursively) prints the
elements of the list enclosed in parentheses (`(` and `)'). If e is NIL, the word NIL is
printed
*/
void print(element e) {
    if (e.type == LIST && e.l == NULL) {
        printf(" NIL ");
        return;
    }
    if (e.type == ATOM) {
        printf(" %c ", e.a);
    } else {
        list ptr = e.l;
        printf(" (");
        while (ptr != NULL) {
            print(ptr->el);
            ptr = ptr->next;
        }
        printf(") ");
    }
}

int main(){
     element a=aasel('a');
    element b=aasel('b');
    element c=aasel('c');
    element d=aasel('d');
    element e=aasel('e');
    list bc= cons(lasel(cons(b, cons(c, NULL))),NULL);;
    list de = cons(d, cons(e,NULL));
    list abc = cons(a,bc);
    list abcd = append(abc,cons(d, NULL));
    list abcde = append(abcd,cons(e, NULL));

    print(lasel(abcde));
    printf("\n");
    print(car(lasel(abcde)));
    printf("\n");
    print(lasel(cdr(lasel(abcde))));
    printf("\n");
    print(car(car(lasel(abcde))));
    printf("\n");
    lfreer(abcde);
    return 0;
}
