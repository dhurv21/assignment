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
    return t;

}

void read_taxon_info(const char *label, char *name_out, int *lifespan_out) {
    printf("\n Enter details: %s \n", label);
    printf("Name: ");
    scanf(" %s", name_out); 
    printf("avg lifespan: ");
    scanf("%d", lifespan_out);

}

void link_parent(Taxon *child, Taxon *parent) {
    child -> parent_group = parent;
}

void print_taxonomy(Taxon *species_list, int species_count) {
    printf(" SPECIES HEIRARCHY");
    for (int i = 0; i < species_count; i++) {
        Taxon *s = species_list[i];
        printf("Species %d %s \n", i + 1,s->name);
        printf("Average Lifespan: %d ", s-> lifespan);
        printf("belongs to genus: %s (lifespan: %d yrs)", s->parent_group->name, s->parent_group->lifespan);
        printf(" belongs to Family: %s (lifespan: %d yrs)", s->parent_group->parent_group->name, s->parent_group->parent_group->lifespan);
    }
}
// milestone 1 
int main() {
    char temp_name[50];
    int temp_life;
    Taxon *all_taxa[7];

    const char *labels[7] = {
        "Family", "Genus 1", "Genus 2", "Species 1", "Species 2", "Species 3", "Species 4"};
    
    for (int i = 0; i < 7; i++) {
        read_taxon_info(labels[i], temp_name, &temp_life);
        all_taxa[i] = create_taxon(temp_name, temp_life);
    }

   link_parent(all_taxa[1], all_taxa[0]);
    link_parent(all_taxa[2], all_taxa[0]);
    
    link_parent(all_taxa[3], all_taxa[1]);
    link_parent(all_taxa[4], all_taxa[1]);
    link_parent(all_taxa[5], all_taxa[2]);
    link_parent(all_taxa[6], all_taxa[2]);


    Taxon *species_arr[4];
    species_arr[0] = all_taxa[3];
    species_arr[1] = all_taxa[4];
    species_arr[2] = all_taxa[5];
    species_arr[3] = all_taxa[6];


}