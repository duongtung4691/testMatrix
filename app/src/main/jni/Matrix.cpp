//
// Created by duong.thanh.tung on 11/5/2015.
//

#include "Matrix.hpp"
#include "ItemMatrix.hpp"
#include <stdlib.h>

typedef struct node {
    ItemMatrix itemMatrix;
    struct node *next;
} *NODEPTR;

class Matrix {
    void Innit(NODEPTR *plist) {
        *plist = NULL;
    }

    NODEPTR Getnode(void) {
        NODEPTR p;
        p = (NODEPTR) malloc(sizeof(struct node));
        return (p);
    }

    void Freenode(NODEPTR p) {
        free(p);
    }

    bool Emptynode(NODEPTR *plist) {
        if (*plist == NULL)
            return true;
        return false;
    }

    NODEPTR Inserttop(NODEPTR *plist, ItemMatrix x) {
        NODEPTR p;
        p = Getnode();
        p->itemMatrix = x;
        if (Emptynode(plist)) {
            p->next = NULL;
            *plist = p;
            return (p);
        }
        p->next = *plist;
        *plist = p;
        return p;
    }

    int Bottomnode(NODEPTR *plist) {
        int i;
        NODEPTR p;
        if (Emptynode(plist))
            return (-1);
        p = *plist;
        i = 0;
        while (p != NULL) {
            i = i + 1;
            p = p->next;
        }
        return (i);
    }

    NODEPTR Insertbottom(NODEPTR *plist, ItemMatrix x) {
        NODEPTR p, q;
        int n, i;
        n = Bottomnode(plist);
        if (n == -1) {
            Inserttop(plist, x);
            return (*plist);
        }
        p = *plist;
        i = 0;
        q = Getnode();
        q->itemMatrix = x;
        while (i < n - 1) {
            p = p->next;
            i = i + 1;
        }
        p->next = q;
        q->next = NULL;
        return (q);
    }

    NODEPTR Insertafter(NODEPTR *plist, ItemMatrix x, int n) {
        NODEPTR p, q;
        int i;
        if (n < 0) {
            return (NULL);
        }
        p = *plist;
        i = 0;
        while (p != NULL && i < n) {
            i = i + 1;
            p = p->next;
        }
        if (p == NULL) {
            return (NULL);
        }
        q = Getnode();
        q->itemMatrix = x;
        q->next = p->next;
        p->next = q;
        return (q);
    }

    void Deltop(NODEPTR *plist) {
        NODEPTR p, q;
        p = *plist;
        if (Emptynode(plist)) {
            return;
        }
        q = p;
        p = p->next;
        *plist = p;
        Freenode(q);
    }

    void Delbottom(NODEPTR *plist) {
        NODEPTR p, q;
        int i, n;
        n = Bottomnode(plist);
        if (n == -1) {
            return;
        }
        if (n == 1) {
            Deltop(plist);
            return;
        }
        p = *plist;
        i = 0;
        while (i < n - 2) {
            p = p->next;
            i = i + 1;
        }
        q = p->next;
        p->next = NULL;
        Freenode(q);
    }

    void Delcurrent(NODEPTR *plist, int n) {
        NODEPTR p, q;
        int i;
        if (Emptynode(plist)) {
            return;
        }
        if (n == 0) {
            Deltop(plist);
            return;
        }
        p = *plist;
        i = 0;
        while (p != NULL && i < n - 1) {
            i = i + 1;
            p = p->next;
        }
        if (p->next == NULL) {
            return;
        }
        q = p->next;
        p->next = q->next;
        Freenode(q);
    }

    void Travenode(NODEPTR *plist) {
        NODEPTR p;
        if (Emptynode(plist)) {
            return;
        }
        p = *plist;
        while (p != NULL) {
            p = p->next;
        }
    }

    ItemMatrix Searchnode(NODEPTR *plist, uint64_t col, uint64_t row) {
        NODEPTR p;
        p = *plist;
        while (p != NULL && (p->itemMatrix.getCollum() != col&& p->itemMatrix.getRow()!=row))
            p = p->next;
        if (p == NULL)
            return NULL;
        else {
            return p->itemMatrix;
        }

    }
};


