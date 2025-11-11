#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_MAX 100
#define DELIM "," // CSV delimiter

char *ifile, *ofile;
unsigned filter_age_max;
FILE *istream, *ostream;

#define USAGE                                                                  \
  R"(Filters CSV rows, keeping only those with provided maximum age
%1$s max-age [input-file] [output-file]

Example: 
%1$s max-age input.csv output.csv
%1$s max-age input.csv (output to stdout)
%1$s max-age           (input from stdin, output to stdout)
)"

void filter_stream(FILE *istream, FILE *ostream) {
  char line[LINE_MAX];
  char *fgets_return;
  char *name, *age_str;
  size_t line_no = 0;

  while (getc(istream) != EOF) {
    ++line_no;

    // Read a line from `istream` and assign the return value to `fgets_return`
    // YOUR CODE HERE
    char c;
    int i = 0;
    while((c = getc(istream)) != '\n')
	line[i++] = c;
    line[i] = '\0';
    fgets_return = line;

    if (fgets_return && *fgets_return != '\n') {
      if (strlen(line) > 1) {
        // Assign `name` and `age_str` using `strtok`
        // YOUR CODE HERE
	  char templine[LINE_MAX];
	  strcpy(templine, line);
	char* pch;
	name = (pch = strtok(templine, ","));
	age_str = (pch = strtok(NULL, ","));
	

        // Alternative to strtok:
        // sscanf(line, "%*[^,],%d", &age);

        if (!age_str) {
          // Error message
          // YOUR CODE HERE
	  printf("WARNING: line %ld had no age, skipping...\n", line_no);
          continue;
        }
      }
    } else {
      // Error message
      // YOUR CODE HERE
      printf("WARNING: line %ld is empty, skipping...\n", line_no);
      continue;
    }

    // Age processing
    unsigned age;
    auto recognized_count = sscanf(age_str, "%d", &age);
    if (recognized_count == 1) {
      if (age <= filter_age_max) {
        // Forward input line to `ostream`
        // YOUR CODE HERE
	  while (*fgets_return != '\0') {
	      putc(*fgets_return, ostream);
	      fgets_return++;
	  }
	  putc('\n', ostream);
      }
    } else {
      // Error message
	printf("WARNING: on line %ld; age is NAN, skipping...\n", line_no);
    }
  }
}

int main(int argc, char *argv[]) {
  switch (argc) {
  case 4:
    // max-age ifile ofile
    ofile = argv[3];
  case 3:
    // max-age ifile
    ifile = argv[2];
  case 2:
    // max-age
    if (!sscanf(argv[1], "%d", &filter_age_max)) {
      puts("First argument is not an age.");
      exit(EXIT_FAILURE);
    }
    break;
  default:
    printf(USAGE, argv[0]);
    return EXIT_SUCCESS;
  }

  if (ifile) {
    // Open `ifile` and assign it to `istream`
    // YOUR CODE HERE
    istream = fopen(ifile, "r");

    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
    if(istream == NULL) {
	printf("ERROR: input file, %s, couldn't open input file, exiting...\n", ifile);
	return EXIT_FAILURE;
    }
  } else {
    // Set `ostream` if no file provided
    // istream?
    // YOUR CODE HERE
    printf("ERROR: missing input file, exiting...\n");
    return EXIT_FAILURE;
  }

  if (ofile) {
    // Open `ofile` and assign it to `ostream`
    // YOUR CODE HERE

    // Exit program with an error message if file cannot be opened
    // YOUR CODE HERE
  } else {
    // Set `ostream` if no file provided
    // YOUR CODE HERE
      ostream = fopen("out.csv", "w");
  }

  filter_stream(istream, ostream);
  return EXIT_SUCCESS;
}
