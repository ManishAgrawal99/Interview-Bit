/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3]

Output:[3, 4]

A = 3, B = 4


*/

int* repeatedNumber(const int* A, int n1, int *length_of_array) {

        *length_of_array = 2; // length of result array
        int *result = (int *) malloc(*length_of_array * sizeof(int));
        long long int diff = 0;
        long long int sq_sum = 0;
        int i;
        for(i = 0; i < n1; i++){
            diff += (long long int)A[i] - (long long int)i-1;
            sq_sum += (long long int)A[i]*(long long int)A[i] - ((long long int)i+1)*((long long int)i+1);
        }
        long long int sum = (long long int)(sq_sum/diff);
        result[0] = (int)((sum + diff)/2);
        result[1] = (int)((sum - diff)/2);
        return result;

}
