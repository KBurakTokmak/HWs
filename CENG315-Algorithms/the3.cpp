#include "the3.h"
#include <iostream>
// do not add extra libraries, but you can define helper functions below.


/*
F(i,j) = max(F(i-1, j-1) + c(i,j),
             F(i-1, j) - gap,
             F(i, j-1) - gap)
*/

/* 
PART 1
you are expected to call recursive_alignment (as the name suggests) recursively to find an alignment. 
initial call_count value given to you will be 0.
you should check if call_count >= 1000000, if so, set possible_alignment string to "STACK LIMIT REACHED", return INT_MIN (or anything - it will not be checked).
*/


int max_of_three(int a, int b, int c){
    if (a >= b && a >= c){
        return a;
    }
    else if (b >= a && b >= c){
        return b;
    }
    else{
        return c;
    }
}


int matching_check(char a, char b, int mismatch, int match){
    if (a == b){
        return match;
    }
    else{
        return -mismatch ;
    }
}


int recursive_alignment_helper(std::string &sequence_A, std::string &sequence_B, int gap, int mismatch, int match, std::string &possible_alignment, int i, int j, int &call_count) {
    if (call_count >= 1000000) {;
        return INT_MIN;
    }

    call_count++;

    if (i == 0 && j == 0) return 0;
    if (i == 0) {
        possible_alignment = std::string(j, '_') + possible_alignment;
        return j * -gap;
    }
    if (j == 0) {
        possible_alignment = std::string(i, '.') + possible_alignment;
        return i * -gap;
    }

    int matching_score = INT_MIN, gapA_score = INT_MIN, gapB_score = INT_MIN;
    std::string matching_string, gapA_string, gapB_string; // strings to hold the possible alignment strings

    if (i > 0 && j > 0) {
        matching_score = recursive_alignment_helper(sequence_A, sequence_B, gap, mismatch, match, matching_string, i - 1, j - 1, call_count) + matching_check(sequence_A[i - 1], sequence_B[j - 1], mismatch, match);
    }
    if (i > 0) {
        gapA_score = recursive_alignment_helper(sequence_A, sequence_B, gap, mismatch, match, gapA_string, i - 1, j, call_count) - gap;
    }
    if (j > 0) {
        gapB_score = recursive_alignment_helper(sequence_A, sequence_B, gap, mismatch, match, gapB_string, i, j - 1, call_count) - gap;
    }


    int max_score = max_of_three(matching_score, gapA_score, gapB_score);

    // update possible allignment with highest
    if (max_score == matching_score) {
        if (sequence_A[i - 1] == sequence_B[j - 1]) {
            possible_alignment = matching_string + sequence_A[i - 1];
        } else {
            possible_alignment = matching_string + '!';
        }
    } else if (max_score == gapA_score) {
        possible_alignment = gapA_string + '.';
    } else {
        possible_alignment = gapB_string + '_';
    }

    return max_score;
}


int recursive_alignment(std::string sequence_A, std::string sequence_B, int gap, int mismatch, int match, std::string &possible_alignment, int call_count){
    int highest_alignment_score = recursive_alignment_helper(sequence_A, sequence_B, gap, mismatch, match, possible_alignment, sequence_A.length(), sequence_B.length(), call_count);
    if(possible_alignment.length()<=1){
        possible_alignment="STACK_LIMIT_REACHED";
    }
    return highest_alignment_score;
}

/* 
PART 2
you are expected to create a dynamic programming table to find the highest alignment score. 
then you will need to reconstruct a possible alignment string from the table.
*/
int dp_table_alignment(std::string sequence_A, std::string sequence_B, int gap, int mismatch, int match, std::string &possible_alignment){
    int n = sequence_A.length()+1;//+1 for gaps and 0 starter
    int m = sequence_B.length()+1;
    
    int **dp_table = new int*[n];  
    for (int i = 0; i < n; i++){   
        dp_table[i] = new int[m];  
    }

    // initialize for gaps
    for (int i = 0; i < n; i++){
        dp_table[i][0] = i * -gap;
    }
    for (int j = 0; j < m; j++){
        dp_table[0][j] = j * -gap;
    }

    // fill the DP table
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            int matching_score = dp_table[i - 1][j - 1] + matching_check(sequence_A[i - 1], sequence_B[j - 1], mismatch, match);
            int gapA_score = dp_table[i - 1][j] - gap;
            int gapB_score = dp_table[i][j - 1] - gap;
            dp_table[i][j] = max_of_three(matching_score, gapA_score, gapB_score);
        }
    }

    int highest_alignment_score = dp_table[n - 1][m - 1];
   
    // traceback allignment 
    int i = n - 1, j = m - 1;
    while (i > 0 || j > 0){
        if (i > 0 && j > 0 && dp_table[i][j] == dp_table[i - 1][j - 1] + matching_check(sequence_A[i - 1], sequence_B[j - 1], mismatch, match)){
            if (sequence_A[i - 1] == sequence_B[j - 1]){
                possible_alignment = sequence_A[i - 1] + possible_alignment;
            }
            else{
                possible_alignment = '!' + possible_alignment;
            }
            i--; j--;
        }
        else if (i > 0 && dp_table[i][j] == dp_table[i - 1][j] - gap){
            possible_alignment = '.' + possible_alignment;
            i--;
        }
        else if (j > 0 && dp_table[i][j] == dp_table[i][j - 1] - gap){
            possible_alignment = '_' + possible_alignment;
            j--;
        }
    }

    // free memory
    for (int i = 0; i < n; i++){
        delete[] dp_table[i];
    }
    delete[] dp_table;
    
    return highest_alignment_score;    
}
