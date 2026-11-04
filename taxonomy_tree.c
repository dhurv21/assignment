#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;               // Average lifespan in years
    struct Taxon *parent_group; // Pointer to the broader group it belongs to
} Taxon;

Taxon* create_taxon(const char *name, int lifespan) {
    Taxon *t = (Taxon*) malloc(sizeof(Taxon));
    strcpy(t->name, name);
    t->lifespan = lifespan;
    t-> parent_group = NULL;
    
}

void read_taxon_info(const char *label, char *name_out, int *lifespan_out)
// milestone 1 
int main() {



}