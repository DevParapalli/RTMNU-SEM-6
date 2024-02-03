#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

struct Rule {
    char lhs;
    char * rhs[];
} rule_t;


size_t getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp) {
	char *ptr, *eptr;


	if (*buf == NULL || *bufsiz == 0) {
		*bufsiz = BUFSIZ;
		if ((*buf = malloc(*bufsiz)) == NULL)
			return -1;
	}

	for (ptr = *buf, eptr = *buf + *bufsiz;;) {
		int c = fgetc(fp);
		if (c == -1) {
			if (feof(fp)) {
				size_t diff = (size_t)(ptr - *buf);
				if (diff != 0) {
					*ptr = '\0';
					return diff;
				}
			}
			return -1;
		}
		*ptr++ = c;
		if (c == delimiter) {
			*ptr = '\0';
			return ptr - *buf;
		}
		if (ptr + 2 >= eptr) {
			char *nbuf;
			size_t nbufsiz = *bufsiz * 2;
			size_t d = ptr - *buf;
			if ((nbuf = realloc(*buf, nbufsiz)) == NULL)
				return -1;
			*buf = nbuf;
			*bufsiz = nbufsiz;
			eptr = nbuf + nbufsiz;
			ptr = nbuf + d;
		}
	}
}

size_t getline(char **buf, size_t *bufsiz, FILE *fp)
{
	return getdelim(buf, bufsiz, '\n', fp);
}


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE * file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char * line = NULL;
    size_t len = 0;
    size_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        struct Rule rule;   

        char *lhs = getdelim(&line, &len, ':', file);
    }

    return 0;
}