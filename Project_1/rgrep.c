#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
  // Implement if desire 

  return 0;
}

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {
    int slashCount = 0;  
    int startPatternIndex = 0;
    for(int count = -1; pattern[count] != 0; count--) {
        startPatternIndex++;
    }

    //if not wildcard char
    if(pattern[0] != '+' && pattern[0] != '.' && pattern[0] != '?' && pattern[0] != '\\') {
        if(pattern[1] == '?') {  //if ? is after
            if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                if(pattern[2] == '\0') {
                    return 1;
                }
                else if(rgrep_matches(line, pattern + 2) == 0) {
                    if(line[1] == '\0') {
                        return 0;
                    }
                    return rgrep_matches(line + 1, pattern - startPatternIndex);
                }
                return rgrep_matches(line, pattern + 2);
            }
            else {  //if it matches, move to next line char and pattern char after ?
                if(pattern[2] == '\0') {
                    return 1;
                }
                else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                    return rgrep_matches(line, pattern + 2);
                }
                return rgrep_matches(line + 1, pattern + 2);
            } 
        }
        else { //else if no ? after
            if(line[0] != pattern[0]) { //if no match then move to next line char and reset pattern char to beginning
                if(line[1] == '\0') {
                    return 0;
                }
                return rgrep_matches(line + 1, pattern - startPatternIndex);
            }
            else { //if match then move to next line char and pattern char
                if(pattern[1] == '\0') {
                    return 1;
                }
                else if(line[1] == '\0') {
                    return 0;
                }
                return rgrep_matches(line + 1, pattern + 1);
            } 
        }
    }
    
    //if + wildcard
    else if(pattern[0] == '+') {
        if(pattern[-1] == '\\') { //if there is \ before it check how many slashes
            slashCount++;
            while(pattern[0 - slashCount] == pattern[-1 - slashCount]) {
                slashCount++;
            }
            if(slashCount % 2 == 1) { //if odd number of slashes then special meaning removed
                if(pattern[1] == '?') {  //if ? is after
                    if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line, pattern + 2) == 0) {
                            if(line[1] == '\0') {
                                return 0;
                            }
                            return rgrep_matches(line + 1, pattern - startPatternIndex);
                        }
                        return rgrep_matches(line, pattern + 2);
                    }
                    else {  //if it matches, move to next line char and pattern char after ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                            return rgrep_matches(line, pattern + 2);
                        }
                        return rgrep_matches(line + 1, pattern + 2);
                    } 
                }
                else { //else if no ? after
                    if(line[0] != pattern[0]) { //if no match then move to next line char and reset pattern char to beginning
                        if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern - startPatternIndex);
                    } 
                    else { //if match then move to next line char and pattern char
                        if(pattern[1] == '\0') {
                            return 1;
                        }
                        else if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern + 1);
                    }
                }
            }
            else {} //else if even number of slashes then special meaning remains, move on
        }
        // if there is no \ before
        else if(line[0] != line[-1]) { //if current line char doesnt match previous line char, move to next line char and pattern char
            if(line[1] == '\0' || pattern[1] == '\0') {
                return 1;
            }
            return rgrep_matches(line + 1, pattern + 1);
        }
        else { //if current line char does match previous line char, check if there are more multiples
            if(pattern[1] == '\0') {
                return 1;
            }
            int multipleCount = 0;
            while(line[multipleCount] == line[multipleCount - 1]) { //count how many repeating
                if(line[multipleCount] == '\0') {
                    return 0;
                }
                multipleCount++;
            }
            int patternCount = 1;
            while(pattern[patternCount] != '\0') {
                if(line[multipleCount - 1] == pattern[patternCount]) { //if last repeating line char is same as pattern char after +, subtract 1 from multipleCount
                    multipleCount--;
                }
                patternCount++;
            }
            return rgrep_matches(line + multipleCount, pattern + 1); //move onto next line until the repeating char doesnt appear, move to next pattern char 
        }
    }        
    
    //if .
    else if(pattern[0] == '.') {
        if(pattern[-1] == '\\') { //if there is \ before it check how many slashes
            slashCount++;
            while(pattern[0 - slashCount] == pattern[-1 - slashCount]) {
                slashCount++;
            }
            if(slashCount % 2 == 1) { //if odd number of slashes then special meaning removed
                if(pattern[1] == '?') {  //if ? is after
                    if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line, pattern + 2) == 0) {
                            if(line[1] == '\0') {
                                return 0;
                            }
                            return rgrep_matches(line + 1, pattern - startPatternIndex);
                        }
                        return rgrep_matches(line, pattern + 2);
                    }
                    else {  //if it matches, move to next line char and pattern char after ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                            return rgrep_matches(line, pattern + 2);
                        }
                        return rgrep_matches(line + 1, pattern + 2);
                    } 
                }
                else { //else if no ? after
                    if(line[0] != pattern[0]) { //if no match then move to next line char and reset pattern char to beginning
                        if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern - startPatternIndex);
                    } 
                    else { //if match then move to next line char and pattern char
                        if(pattern[1] == '\0') {
                            return 1;
                        }
                        else if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern + 1);
                    }
                }
            }
            else {} //else if even number of slashes then special meaning remains, move on
        }
        else if(pattern[1] == '?') {  //if ? is after
            if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                if(pattern[2] == '\0') {
                    return 1;
                }
                else if(rgrep_matches(line, pattern + 2) == 0) {
                    if(line[1] == '\0') {
                        return 0;
                    }
                    return rgrep_matches(line + 1, pattern - startPatternIndex);
                }
                return rgrep_matches(line, pattern + 2);
            }
            else {  //if it matches, move to next line char and pattern char after ?
                if(pattern[2] == '\0') {
                    return 1;
                }
                else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                    return rgrep_matches(line, pattern + 2);
                }
                return rgrep_matches(line + 1, pattern + 2);
            } 
        }
        else { // if no ?, move to next line char and pattern char
            if(pattern[1] == '\0') {
                return 1;
            }
            else if(line[1] == '\0') {
                return 0;
            }
            return rgrep_matches(line + 1, pattern + 1);
        }
    }

    //if on \ then
    else if(pattern[0] == '\\') {
        if(pattern[-1] == '\\') { //if there is \ before it check how many slashes
            slashCount++;
            while(pattern[0 - slashCount] == pattern[-1 - slashCount]) {
                slashCount++;
            }
            if(slashCount % 2 == 1) { //if odd number of slashes then special meaning removed
                if(pattern[1] == '?') {  //if ? is after
                    if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line, pattern + 2) == 0) {
                            if(line[1] == '\0') {
                                return 0;
                            }
                            return rgrep_matches(line + 1, pattern - startPatternIndex);
                        }
                        return rgrep_matches(line, pattern + 2);
                    }
                    else {  //if it matches, move to next line char and pattern char after ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                            return rgrep_matches(line, pattern + 2);
                        }
                        return rgrep_matches(line + 1, pattern + 2);
                    } 
                }
                else { //else if no ? after
                    if(line[0] != pattern[0]) { //if no match then move to next line char and reset pattern char to beginning
                        if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern - startPatternIndex);
                    } 
                    else { //if match then move to next line char and pattern char
                        if(pattern[1] == '\0') {
                            return 1;
                        }
                        else if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern + 1);
                    }
                }
            }
            else {} //else if even number of slashes then special meaning remains, move on
        }
        return rgrep_matches(line, pattern + 1); //go to next pattern char
    }

    //if ?
    else if(pattern[0] == '?') {
        if(pattern[-1] == '\\') { //if \ is before it
            slashCount++;
            while(pattern[0 - slashCount] == pattern[-1 - slashCount]) { //count slashes
                slashCount++;
            }
            if(slashCount % 2 == 1) { //if odd, special meaning is removed
                if(pattern[1] == '?') {  //if ? is after
                    if(line[0] != pattern[0]) { //if it doesnt match, stay at same line char and skip pattern char to after the ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line, pattern + 2) == 0) {
                            if(line[1] == '\0') {
                                return 0;
                            }
                            return rgrep_matches(line + 1, pattern - startPatternIndex);
                        }
                        return rgrep_matches(line, pattern + 2);
                    }
                    else {  //if it matches, move to next line char and pattern char after ?
                        if(pattern[2] == '\0') {
                            return 1;
                        }
                        else if(rgrep_matches(line + 1, pattern + 2) == 0) {
                            return rgrep_matches(line, pattern + 2);
                        }
                        return rgrep_matches(line + 1, pattern + 2);
                    } 
                }
                else { //else if no ? after
                    if(line[0] != pattern[0]) { //if no match, go to next line char and reset to beginning pattern char
                        if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern - startPatternIndex);
                    } 
                    else { //if match, move on to next line char and pattern char
                        if(pattern[1] == '\0') {
                            return 1;
                        }
                        else if(line[1] == '\0') {
                            return 0;
                        }
                        return rgrep_matches(line + 1, pattern + 1);
                    }
                }
            }
        }
        return 1;     
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
