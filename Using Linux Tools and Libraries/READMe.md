# Code discussed in this video:

#include <stdio.h>

double square(double);

int main(void) {
    double a = 2.5;
    double aSquared = square(a);
    printf("%.2lf squared = %.2lf\n", a, aSquared);
    return 0;
}

double square(double x) {
    return x*x;
}


# Code discussed in this video:

#include <stdio.h>
#include <math.h>

int main(){
    double a = 2.5;
    double asquared = pow(a,2);
    printf("%.2lf squared = %.2lf\n",a,asquared);
    return 0;
}

# Commands and changes discussed in this video:

x is raised to the power of y
a is raised to the power of 2  (squared)
look at the documentation when you click on pow

find / -name "math.h" 2>/dev/null
ls /usr/include | less
ls /usr/include > includes.txt  (open with editor)

# Code discussed in this video:

#include <stdio.h>
#include <curses.h>
#include <menu.h>
#include <stdlib.h>

int main(void) {
	ITEM **my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;
	char *choices[] = {
	    "Menu 1",
	    "Menu 2",
	    "Menu 3",
	    "Menu 4"
	};
	char *descriptions[] = {
		"do this",
		"do that",
		"do ....",
		"do ????"
	};
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	n_choices = sizeof(choices) / sizeof(choices[0]);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
	
	for (i=0; i<n_choices; i++) {
	    my_items[i] = new_item(choices[i], descriptions[i]);
	}
	my_items[n_choices] = (ITEM *)NULL;
	
	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "q to quit");
	post_menu(my_menu);
	refresh();
	
	while ((c = getch()) != 'q') {
	    if (c==KEY_DOWN) {
	        menu_driver(my_menu, REQ_DOWN_ITEM);
	    } else if (c==KEY_UP) {
	        menu_driver(my_menu, REQ_UP_ITEM);
	    }
	}
	
	for (i=0; i<=n_choices; i++) {
		free_item(my_items[i]);
	}
	free_menu(my_menu);
	endwin();
	return 0;

# Code discussed in this video:

#include <stdio.h>
#include "weather.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 5.3, 9.8, 1.8, 0.3};
	printAverageTemp(temperatures, 7);
	return 0;
}

# Commands discussed in this video:

compile weatherstats.c to weatherstats.o using
gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o
either make program.o object file similarly and then link using
gcc -std=c11 -Wall -fmax-errors=10 -Wextra weatherstats.o program.o -o program
or do both at once using
gcc -std=c11 -Wall -fmax-errors=10 -Wextra weatherstats.o program.c -o program
____________________________________________________________________________________________________________________________________

Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
Source file weatherstats.c:

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

# Code discussed in this video:

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Makefile commands discussed in this video:

program: program.o weatherstats.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o weatherstats.o -o program
	
program.o: program.c weatherstats.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o
	
weatherstats.o: weatherstats.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o
________________________________________________________________________________________
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

# Makefile code discussed in this video:

# define the C compiler to use
CC       = gcc
# define comipler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra
# define library paths in addition to /usr/lib
LFLAGS   = 
# define libraries to use
LIBS     = 
# define the object files that this project needs
OBJFILES = program.o weatherstats.o
# define the name of the executable file
MAIN     = program

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) 
    
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)
_______________________________________________________________________________________________________________________

program.c

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

Makefile code discussed in this video:

program: program.o weatherstats.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o weatherstats.o -o program
	
program.o: program.c weatherstats.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o
	
weatherstats.o: weatherstats.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o

launch: program
	./program
_______________________________________________________________________________________________________________________

program.c

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

Commands discussed in this video:
Create library: Use the ar (archive) utility:

ar rcs libweather.a weatherstats.o
r - replace (if already in)
c - create if doesn't exist yet
s - create index for fast access
(there are the most popular options)
link program: The linker is able to read ar files and extract object file(s) from it.

gcc -std=c11 -Wall -fmax-errors=10 -Wextra -o program program.o libweather.a
Still doesn't look quite like the first example of a library use with the -l flag. Here goes:

gcc -std=c11 -Wall -fmax-errors=10 -Wextra -o program program.o -L. -lweather
_______________________________________________________________________________________________________________________

program.c

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

Commands discussed in this video:

Update library:

ar rcs libweather.a weatherio.o weatherstats.o
link program:

gcc -std=c11 -Wall -fmax-errors=10 -Wextra -o program program.o -L. -lweather
_______________________________________________________________________________________________________________________

Code discussed in this video:

program.c

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
        printTemps(temperatures, 7);
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

header file weather.h

#include "weatherio.h"
#include "weatherstats.h"
header file weatherio.h

void printTemps(double *temps, int numOfTemps);
source file weatherio.c:

#include 

void printTemps(double *temps, int numOfTemps) {
	int i;
	printf("Over the past %d days, the temperatures were: \n", numOfTemps);
	for (i=0; i<numOfTemps; i++) {
		printf("%d: %.2lf\n", i+1, temps[i]);
	}
}

# Commands discussed in this video:

Makefile:

# define the C compiler to use
CC       = gcc
# define comipler flags
CFLAGS   = -std=c11 -Wall -fmax-errors=10 -Wextra
# define library paths in addition to /usr/lib
LFLAGS   = -L. 
# define libraries to use
LIBS     = -lweather
# define the object files that this project needs
OBJFILES = program.o
# define the name of the executable file
MAIN     = program

# all of the below is generic - one typically only adjusts the above

all: $(MAIN)

$(MAIN): $(OBJFILES)
    $(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) $(LFLAGS) $(LIBS) 
    
%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

launch: program
	./program

clean:
    rm -f $(OBJFILES) $(MAIN)
Intermediate step:

program: program.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o -L. -lweather -o program
	
program.o: program.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

launch: program
	./program
_______________________________________________________________________________________________________________________

program.c

#include <stdio.h>
#include "weatherstats.h"

int main(void) {
	double temperatures[7] = {6.9, 12.3, 9.0, 15.3, 9.8, 1.8, 0.3};
	double average = averageTemp(temperatures, 7);
	double max = maxTemp(temperatures, 7); 
        printTemps(temperatures, 7);
	printf("Average 7-day temp: %.2lf\n", average);
	printf("Highest temp: %.2lf\n", max);
	printf("Lowest temperature: %.2lf\n", minTemp(temperatures,7));
	return 0;
}
Header file weatherstats.h:

double averageTemp(double *temps, int numOfTemps);
double maxTemp(double *temps, int numOfTemps);
double minTemp(double *temps, int numOfTemps);
Source file weatherstats.c

double averageTemp(double *temps, int numOfTemps) {
	double result = 0.0;
	int i;
	for (i=0; i<numOfTemps; i++) {
		result = result + temps[i];
	}
	result = result / (double) numOfTemps;
	return result;
}

double maxTemp(double *temps, int numOfTemps) {
	double max = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (max < temps[i]) {
			max = temps[i];
		}
	}
	return max;
}
double minTemp(double *temps, int numOfTemps) {
	double min = temps[0];
	int i;
	for (i=0; i<numOfTemps; i++) {
		if (min > temps[i]) {
			min = temps[i];
		}
	}
	return min;
}

header file weather.h

#include "weatherio.h"
#include "weatherstats.h"
header file weatherio.h

void printTemps(double *temps, int numOfTemps);
source file weatherio.c:

#include 

void printTemps(double *temps, int numOfTemps) {
	int i;
	printf("Over the past %d days, the temperatures were: \n", numOfTemps);
	for (i=0; i<numOfTemps; i++) {
		printf("%d: %.2lf\n", i+1, temps[i]);
	}
}

Code discussed in this video:

#include <stdio.h>
#include <stdlib.h> // for atoi and atof
#include <string.h> // for strcmp

int main(int argc, char *argv[]) {
    int i, compare, wholeNumber;
    double decimalNumber;
    
    printf("I have %d arguments from the command line: \n", argc);
    for (i = 0; i<argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    
    if (argc == 4) {
        compare = strcmp(argv[1], "-e");
        if (compare ==0) {
            printf("argv[1] equals -e \n");
        } else {
            printf("argv[1] does not equal -e \n");
        }
        wholeNumber = atoi(argv[2]);
        printf("%s as an integer is %d.\n", argv[2], wholeNumber);
        decimalNumber = atof(argv[3]);
        printf("%s as a double is %lf.\n", argv[3], decimalNumber);
    }
    return 0;
}

Code discussed in this video:

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;
    printf("I have %d arguments from the command line: \n", argc);
    for (i = 0; i<argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    
    return 0;
}

#include <stdio.h>

int main(void) {
    FILE *ifile;  /* ifile is a variable name - you could use any other name here. 
                     However, the '*' is important - we are working with a pointer. 
                     We call this a file pointer. */
    int i, num, N;
    
    ifile = fopen("my_first_file.txt", "r"); /* open file for reading. 
                                                     The "r" stands for reading. */
    
    fscanf(ifile, "%d", &N); /* Read first number from the file.
                                Just like scanf(), the only difference is the 
                                file pointer that gets passed in as well. */
                                
    printf("There are %d numbers in the file.\n", N);
    
    for (i = 0; i<N; i++) {
        fscanf(ifile, "%d", &num);
        printf("I read %d from the file. \n", num);
    }
    
    fclose(ifile); /* closes the file */
    
    return 0;
}

Code discussed in this video:

#include <stdio.h>

int main(void) {
    FILE *ifile;  /* ifile is a variable name - you could use any other name here. 
                     However, the '*' is important - we are working with a pointer. 
                     We call this a file pointer. */
    int i, num, N;
    
    ifile = fopen("my_first_file.txt", "r"); /* open file for reading. 
                                                     The "r" stands for reading. */
    
    fscanf(ifile, "%d", &N); /* Read first number from the file.
                                Just like scanf(), the only difference is the 
                                file pointer that gets passed in as well. */
                                
    printf("There are %d numbers in the file.\n", N);
    
    for (i = 0; i<N; i++) {
        fscanf(ifile, "%d", &num);
        printf("I read %d from the file. \n", num);
    }
    
    fclose(ifile); /* closes the file */
    
    return 0;
}
______________________________________________________________________________________________________________________

This requires a file by the name of "my_first_file.txt" to exist in the same directory as the code.Here is a sample file:

9
56  3  8  -11  0  -45  55  2  78
Then change the code slightly to read from "my_second_file.txt" which contains doubles rather than integers. Sample:

6
13.5 22.7 8.0 -4.3 2.99 6.66

#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int i, num, sum;
    int N, done, message;
    
    ifile = fopen("my_third_file.txt", "r"); 
                                
    N=0;
    sum = 0;
    done = 0; 
    
    while (!done) {
        message = fscanf(ifile, "%d", &num);
        if (message == EOF) done = 1;
        else {
            printf("I read %d from the file. \n", num);
            sum += num;
            N++;
        }
    }
    
    fclose(ifile);
    
    printf("There are %d numbers in the file.\n", N);
    printf("The sum of the numbers read is %d.\n", sum); 
    printf("The average is %.2f.", (float) sum / N);
    
    return 0;
}
______________________________________________________________________________________

Need a file "my_third_file.txt" here. For example

56  3  8  -11  0  -45  55  2  78

______________________________________________________________________________________

More elegant version:

#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int i, num, sum;
    int N;
    
    ifile = fopen("files/my_third_file.txt", "r"); 
                                
    N=0;
    sum = 0;
    
    while (fscanf(ifile, "%d", &num) != EOF) {
        printf("I read %d from the file. \n", num);
        sum += num;
        N++;
    }
    
    fclose(ifile);
    
    printf("There are %d numbers in the file.\n", N);
    printf("The sum of the numbers read is %d.\n", sum); 
    printf("The average is %.2f.", (float) sum / N);
    
    return(0);
}

Code discussed in this video:

#include <stdio.h>

int main(void) {
    FILE *ofile;  /* You can use any variable name here, just make sure you 
                     include the '*'. */
    char filename[] = "my_first_output_file.txt";
    int num;
    
    ofile = fopen(filename, "w"); 
     
    do {
        printf("Please enter a grade. Enter -1 to quit: \n");
        scanf("%d", &num);
        if (num != -1)
            fprintf(ofile, "%d ", num);        
    } while (num != -1);
    fclose(ofile);
    
    return 0;
}