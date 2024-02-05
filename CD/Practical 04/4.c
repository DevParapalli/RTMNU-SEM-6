#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define RHS_DELIM '|'	
#define RHS_DELIM_STR "|"
#define LHS_DELIM ":"

typedef struct Rule {
    char * lhs;
	size_t rhs_count;
    char ** rhs;
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

void print_rule(rule_t * rule) {
	printf("%s -> ", rule->lhs);
	for (size_t i = 0; i < rule->rhs_count; i++) {
		printf("%s", rule->rhs[i]);
		if (i < rule->rhs_count - 1) {
			printf(" | ");
		}
	}
	printf("\n");
}


int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE * file = fopen(argv[1], "r");
    // FILE * file = fopen("inp2.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char * line = NULL;
    size_t len = 0;
    size_t read;

	rule_t * rules[100];
	size_t rule_count = 0;

    while ((read = getline(&line, &len, file)) != -1) {
        struct Rule * rule = (rule_t *)malloc(sizeof(struct Rule));   	
		rule->rhs_count = 1;
		for (char *ptr = line; *ptr != '\0'; ptr++) {
			if (*ptr == RHS_DELIM) 
				rule->rhs_count++; 
		}
		
		rule->rhs = malloc(rule->rhs_count * sizeof(char *));
		if (rule->rhs == NULL) {
			fprintf(stderr, "Error: Unable to allocate memory @ line %d\n", __LINE__);
			exit(EXIT_FAILURE);
		}
		
		rule->lhs = strdup(strtok(line, LHS_DELIM));
		for (size_t i = 0; i < rule->rhs_count; i++) {
			rule->rhs[i] = strdup(strtok(NULL, RHS_DELIM_STR));
		}
		// remove trailing newline for last rhs using strcspn
		rule->rhs[rule->rhs_count - 1][strcspn(rule->rhs[rule->rhs_count - 1], "\n")] = 0;
		rules[rule_count++] = rule;
    }

	fclose(file);
	if (line) {
		free(line);
	}

	fprintf(stdout, "Original Rules:\n");
	for (size_t i = 0; i < rule_count; i++) {
		print_rule(rules[i]);
	}


	
    return 0;
}