#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "webarchive.h"

const char *validate(const char *data)
{
    int i;

    // name
    if (strncmp(data,"name=",5) != 0)
        return "invalid query string: must start with 'name='";
    i = 5;
    while (isalnum(data[i]))
        i++;
    if (i == 5)
        return "invalid query string: no name";
    if (i > 35)
        return "invalid query string: max name size is 32";

    // filedata
    if (strncmp(data+i, "&data=", 6) != 0)
        return "invalid query string: invalid name / no data";

    return NULL;
}

int main()
{
    const char *query_string = getenv("QUERY_STRING");
    if (query_string == NULL) {
        generatepage("Internal error: invalid request");
    } else if (NULL != validate(query_string)) {
        generatepage(validate(query_string));
    } else {
        char *data[MAX_RECORDS] = {0};
        if (!readdata(data, MAX_RECORDS)) {
            generatepage("Failed to read file data");
            return EXIT_SUCCESS;
        }

        char name[32] = {0};
        strcpy(name, getname(query_string));
        int index = -1;
        for (int i = 0; i < MAX_RECORDS && data[i]; i++) {
            if (strcmp(name, getname(data[i])) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            generatepage("File not found");
            return EXIT_SUCCESS;
        }

        // cleanup data...
        char str[1000] = {0};
        char *dst = str;
        for (const char *src = query_string; *src; src++) {
            *dst = *src;
            dst++;
            if (strncmp(src, "%25", 3) == 0 && isxdigit(src[3]) && isxdigit(src[4]))
                src += 2;
        }

        data[index] = str;
        sortdata(data, MAX_RECORDS);

        FILE *f = fopen("data.txt", "wt");
        if (f == NULL) {
            generatepage("Failed to add file (access denied). Try again.");
            return EXIT_SUCCESS;
        }
        for (int i = 0; i < MAX_RECORDS && data[i]; i++)
            fprintf(f, "%s\n", data[i]);
        fclose(f);
        generatepage("saved.");
    }

    return EXIT_SUCCESS;
}

