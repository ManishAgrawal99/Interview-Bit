/**


You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only.
Each string goes through a number of operations, where:

1.	At time 1, you circularly rotate each string by 1 letter.
2.	At time 2, you circularly rotate the new rotated strings by 2 letters.
3.	At time 3, you circularly rotate the new rotated strings by 3 letters.
4.	At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is "abaa"

1.	At time 1, string is "baaa", as 1 letter is circularly rotated to the back
2.	At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
3.	At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
4.	At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
5.	At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back

After some units of time, a string becomes equal to it’s original self.
Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be it’s original self at 2t time.
You have to find the minimum time, where maximum number of strings are equal to their original self.
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Input:

A: Array of strings.

Output:

Minimum time, where maximum number of strings are equal to their original self.

Constraints:

1 <= size(A) <= 10^5
1 <= size of each string in A <= 10^5
Each string consists of only characters 'a' and 'b'
Summation of length of all strings <= 10^7

Example:

Input

A: [a,ababa,aba]

Output

4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.


**/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findlcm(int* arr, int n)
{
    // Initialize result
    long long int ans = arr[0];
    int i;

    for (i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)))%1000000007;

    return ans%1000000007;
}

int solve(char** A, int n1) {
    int i,j;
    int same[n1];

    for(i=0;i<n1;i++){
        j=1;
        while((j*(j+1)/2)%strlen(A[i])!=0){
            j++;
        }
        same[i] = j;
    }

    int res = findlcm(&same, n1);
    return res;
}

void main(){
    int i;
    char** arr = (char**)malloc(sizeof(char*)*3);
    for(i=0;i<3;i++)
        *(arr+i) = (char*)malloc(sizeof(char)*20);

    arr[0] = "a";
    arr[1] = "ababa";
    arr[2] = "aba";

    int res = solve(arr, 3);
    printf("%d", res);
}



///Python Solution
/**

class Solution:

    def gcd(self, A, B):
        if (B > A):
            A, B = B, A
        if (B == 0):
            return A
        return self.gcd(B, A % B)

    def solve(self, A):
        ans = 1
        for k in A:
            for i in range(1, 1000000000):
                if (((i * (i + 1)) // 2) % len(k) == 0):
                    ans = ((ans * i) // self.gcd(ans, i))
                    break
        return (ans % 1000000007)
**/
