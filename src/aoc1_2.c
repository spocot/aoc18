#include <stdio.h>
#include <stdlib.h>

struct freq_change {
    int amnt;
    struct freq_change *next;
};

struct frequency_node {
    int val;
    struct frequency_node *next;
};

/**
 * Search for the given frequency value in the chain of nodes.
 * return NULL if not found, otherwise pointer to the node containing that val.
 */
struct frequency_node *search(struct frequency_node *n, int val)
{
    struct frequency_node *curr = n;
    while (curr != NULL && curr->val != val) {
        curr = curr->next;
    }
    return curr;
}

/**
 * Create a new frequency_node and place it at the head since order doesnt matter.
 */
struct frequency_node *add_frequency(struct frequency_node *node_list, int val)
{
    struct frequency_node *new_node = malloc(sizeof(struct frequency_node));
    new_node->val = val;
    new_node->next = node_list;
    return new_node;
}

/**
 * Create a new freq_change and add it to the list of frequency changes.
 * returns pointer to new tail of list
 */
struct freq_change *add_change(struct freq_change *tail, int amnt)
{
    struct freq_change *new_change = malloc(sizeof(struct freq_change));
    new_change->amnt = amnt;
    new_change->next = NULL;

    if (tail != NULL){
        tail->next = new_change;
    }
    return new_change;
}

int main(int argc, char **argv)
{
    int freq = 0;
    char *line = NULL;
    size_t size = 0;

    struct frequency_node *node_list = malloc(sizeof(struct frequency_node));
    node_list->val = 0;
    node_list->next = NULL;
    struct freq_change *change_list_head = NULL;
    struct freq_change *curr_change = NULL;
    struct frequency_node *curr_freq = NULL;

    while (getline(&line, &size, stdin) != -1) {
        int val = atoi(line);

        free(line);
        line = NULL;

        freq += val;

        curr_change = add_change(curr_change, val);

        if (change_list_head == NULL) {
            change_list_head = curr_change;
        }

        if ((curr_freq = search(node_list, freq)) == NULL) {
            node_list = add_frequency(node_list, freq);
        } else {
            // If search returns something other than NULL, then the freq
            // already exists!
            printf("Freq Repeat found: %d\n", curr_freq->val);
            exit(0);
        }
    }

    // If we reach here then there were no repeats in the first iteration though
    // the calibration loop so we will keep looping through until we repeat a freq.
    while (1) {
        for (
                curr_change = change_list_head;
                curr_change != NULL;
                curr_change = curr_change->next
            ){
            freq += curr_change->amnt;
            if ((curr_freq = search(node_list, freq)) == NULL) {
                node_list = add_frequency(node_list, freq);
            } else {
                // If search returns something other than NULL, then the freq
                // already exists!
                printf("Freq Repeat found: %d\n", curr_freq->val);
                exit(0);
            }
        }
    }
}
