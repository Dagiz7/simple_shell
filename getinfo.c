#include "shell.h"

// Clear the information stored in the 'info' structure
void clear_info(info_t *info) {
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = 0;
}

// Set the information in the 'info' structure based on command-line arguments
void set_info(info_t *info, char **av) {
    int i = 0;

    // Set the first argument as the 'fname' member of 'info'
    info->fname = av[0];

    // If 'arg' is not NULL, split it into an array of strings ('argv')
    if (info->arg) {
        info->argv = strtow(info->arg, " \t");

        // If 'strtow' returns NULL, allocate memory for a two-element 'argv' array
        if (!info->argv) {
            info->argv = malloc(sizeof(char *) * 2);
            if (info->argv) {
                info->argv[0] = _strdup(info->arg);
                info->argv[1] = NULL;
            }
        }

        // Count the number of elements in 'argv' and assign it to 'argc'
        for (i = 0; info->argv && info->argv[i]; i++);
        info->argc = i;

        // Perform alias and variable substitution on 'info'
        replace_alias(info);
        replace_vars(info);
    }
}

// Free the memory allocated for the 'info' structure and its members
void free_info(info_t *info, int all) {
    ffree(info->argv);
    info->argv = NULL;
    info->path = NULL;

    // If 'all' is non-zero, free additional memory and perform cleanup
    if (all) {
        if (!info->cmd_buf)
            free(info->arg);
        if (info->env)
            free_list(&(info->env));
        if (info->history)
            free_list(&(info->history));
        if (info->alias)
            free_list(&(info->alias));
        ffree(info->environ);
        info->environ = NULL;
        bfree((void **)info->cmd_buf);
        if (info->readfd > 2)
            close(info->readfd);
        _putchar(BUF_FLUSH);
    }
}